/*
 * File: TPSC_01.c
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


#include "TPSC_01.h"
#include <math.h>
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Exported data definition */

/* Definition for custom storage class: Global */
real_T a = 0.4;                        /* Referenced by: '<Root>/a' */
real_T b = 0.4;                        /* Referenced by: '<Root>/b' */
real_T episilon = 0.5;                 /* Referenced by: '<Root>/episilon' */
real_T k0 = 1.0;                       /* Referenced by: '<Root>/k0' */
real_T k1 = 1.0;                       /* Referenced by: '<Root>/k1' */

/* Definition for custom storage class: Global */
real_T ht;                             /* '<Root>/ht' */
real_T htdot;                          /* '<Root>/htdot' */
real_T v;                              /* '<Root>/MATLAB Function3' */
real_T vr;                             /* '<Root>/vr' */
real_T w;                              /* '<Root>/MATLAB Function3' */
real_T wr;                             /* '<Root>/wr' */

/* Model step function */
void TPSC_01_step(void)
{
  real_T V1;
  real_T V1_tmp;
  real_T c_tmp;
  real_T rtb_x2dot;
  real_T u0_tmp;

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  Constant: '<Root>/a'
   *  Constant: '<Root>/b'
   *  Constant: '<Root>/episilon'
   *  Constant: '<Root>/k0'
   *  Constant: '<Root>/k1'
   *  DiscreteIntegrator: '<Root>/Integrator'
   *  DiscreteIntegrator: '<Root>/Integrator1'
   *  DiscreteIntegrator: '<Root>/Integrator2'
   *  Inport: '<Root>/ht'
   *  Inport: '<Root>/htdot'
   *  Inport: '<Root>/vr'
   *  Inport: '<Root>/wr'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   *  MATLAB Function: '<Root>/MATLAB Function2'
   */
  V1 = rtDW.Integrator1_DSTATE * rtDW.Integrator1_DSTATE +
    rtDW.Integrator2_DSTATE * rtDW.Integrator2_DSTATE;
  c_tmp = sqrt(V1);
  u0_tmp = sin(rtDW.Integrator_DSTATE);
  rtb_x2dot = fmin(fmax(k0 * rtDW.Integrator2_DSTATE, -a), a);
  V1_tmp = episilon * ht;
  V1 = -((((ht * wr * rtDW.Integrator2_DSTATE + htdot * rtDW.Integrator1_DSTATE)
           + ht * vr * u0_tmp) / (c_tmp + 1.0) - ht * rtDW.Integrator1_DSTATE /
          ((c_tmp + 1.0) * (c_tmp + 1.0)) / c_tmp * (rtDW.Integrator1_DSTATE *
           vr * u0_tmp + -rtb_x2dot * rtDW.Integrator2_DSTATE)) * episilon) /
    (1.0 - V1_tmp * rtDW.Integrator2_DSTATE / (sqrt(V1) + 1.0)) - fmin(fmax
    ((V1_tmp * rtDW.Integrator1_DSTATE / (sqrt(V1) + 1.0) +
      rtDW.Integrator_DSTATE) * k1, -b), b);
  v = -fmin(fmax(k0 * rtDW.Integrator2_DSTATE, -a), a) + vr * cos
    (rtDW.Integrator_DSTATE);
  c_tmp = wr - V1;
  w = c_tmp;

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  DiscreteIntegrator: '<Root>/Integrator1'
   */
  rtb_x2dot = -c_tmp * rtDW.Integrator1_DSTATE - rtb_x2dot;

  /* Update for DiscreteIntegrator: '<Root>/Integrator' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function3'
   */
  rtDW.Integrator_DSTATE += 0.01 * V1;

  /* Update for DiscreteIntegrator: '<Root>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<Root>/Integrator2'
   *  Inport: '<Root>/vr'
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  rtDW.Integrator1_DSTATE += (c_tmp * rtDW.Integrator2_DSTATE + u0_tmp * vr) *
    0.01;

  /* Update for DiscreteIntegrator: '<Root>/Integrator2' */
  rtDW.Integrator2_DSTATE += 0.01 * rtb_x2dot;
}

/* Model initialize function */
void TPSC_01_initialize(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<Root>/Integrator' */
  rtDW.Integrator_DSTATE = 0.5;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Integrator1' */
  rtDW.Integrator1_DSTATE = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Integrator2' */
  rtDW.Integrator2_DSTATE = -1.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
