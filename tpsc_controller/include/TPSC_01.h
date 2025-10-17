/*
 * File: TPSC_01.h
 *
 * Code generated for Simulink model 'TPSC_01'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Mar 13 14:44:30 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TPSC_01_h_
#define RTW_HEADER_TPSC_01_h_

#ifdef __cplusplus
extern "C" {  // 让 C++ 代码正确解析 C 函数
#endif

#ifndef TPSC_01_COMMON_INCLUDES_
#define TPSC_01_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TPSC_01_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define GAMMA 0.5  // gamma = 0.5
#define e     0.5  // e = 0.5
#define R     0.8  // R = 0.8

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_DSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_DSTATE;           /* '<Root>/Integrator2' */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void TPSC_01_initialize(void);
extern void TPSC_01_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/* Exported data declaration */

/* Declaration for custom storage class: Global */
extern real_T a;                       /* Referenced by: '<Root>/a' */
extern real_T b;                       /* Referenced by: '<Root>/b' */
extern real_T episilon;                /* Referenced by: '<Root>/episilon' */
extern real_T k0;                      /* Referenced by: '<Root>/k0' */
extern real_T k1;                      /* Referenced by: '<Root>/k1' */

/* Declaration for custom storage class: Global */
extern real_T ht;                      /* '<Root>/ht' */
extern real_T htdot;                   /* '<Root>/htdot' */
extern real_T v;                       /* '<Root>/MATLAB Function3' */
extern real_T vr;                      /* '<Root>/vr' */
extern real_T w;                       /* '<Root>/MATLAB Function3' */
extern real_T wr;                      /* '<Root>/wr' */

#ifdef __cplusplus
}
#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TPSC_01'
 * '<S1>'   : 'TPSC_01/MATLAB Function'
 * '<S2>'   : 'TPSC_01/MATLAB Function1'
 * '<S3>'   : 'TPSC_01/MATLAB Function2'
 * '<S4>'   : 'TPSC_01/MATLAB Function3'
 */
#endif                                 /* RTW_HEADER_TPSC_01_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */;
