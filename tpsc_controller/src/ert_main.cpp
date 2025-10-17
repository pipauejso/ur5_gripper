#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "TPSC_01.h"
#include <cmath>

// 定义 ROS 话题发布器
ros::Publisher cmd_vel_pub;

void rt_OneStep()
{
    static double t = 0.0;
    double dt = 0.01;

    // 设置模型输入（与 Windows 版逻辑相同）
    ht = 1.0 + GAMMA * cos(t);
    htdot = 1.0 - GAMMA * sin(t);
    wr = e;
    vr = e * R;

    // 执行控制器
    TPSC_01_step();

    // 获取控制器输出
    double controller_output_w = w;
    double controller_output_v = v;

    // 创建并发布 Twist 消息
    geometry_msgs::Twist cmd_msg;
    cmd_msg.linear.x = controller_output_v;  // 线速度
    cmd_msg.angular.z = controller_output_w; // 角速度
    cmd_vel_pub.publish(cmd_msg);

    // 打印输出（与 Windows 版相同）
    ROS_INFO("t = %f, ht = %f, htdot = %f, vr = %f, wr = %f, w = %f, v = %f",
             t, ht, htdot, vr, wr, controller_output_w, controller_output_v);

    // 更新时间
    t += dt;
}

int main(int argc, char *argv[])
{
    // 初始化 ROS 节点
    ros::init(argc, argv, "tpsc_controller");
    ros::NodeHandle nh;

    // 话题发布器，发布到 /cmd_vel
    cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 10);

    // **初始化模型**
    TPSC_01_initialize();

    // 设置仿真时间
    double simulation_time = 0.0;
    double dt = 0.01;

    ROS_INFO("Simulation started. Press Ctrl+C to stop.");

    // 主循环，模拟运行 20s
    ros::Rate loop_rate(100);  // 100Hz = 10ms

    while (ros::ok())
    {
        // 运行一次控制器
        rt_OneStep();
        simulation_time += dt;

        // 停止仿真
        if (simulation_time > 60.0)
        {
            ROS_INFO("Simulation ended!");
            break;
        }

        // 处理ROS消息并维持 10ms 循环
        ros::spinOnce();
        loop_rate.sleep();
    }

    ROS_INFO("Simulation ended normally.");
    return 0;
}
