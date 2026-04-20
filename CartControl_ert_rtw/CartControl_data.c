/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CartControl_data.c
 *
 * Code generated for Simulink model 'CartControl'.
 *
 * Model version                  : 6.8
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jul 23 14:48:27 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CartControl.h"

/* Block parameters (default storage) */
P_CartControl_T CartControl_P = {
  /* Expression: SampleTime
   * Referenced by: '<S6>/Serial Read'
   */
  0.004,

  /* Expression: 85
   * Referenced by: '<S2>/Constant1'
   */
  85.0,

  /* Expression: 191
   * Referenced by: '<S2>/Constant2'
   */
  191.0,

  /* Expression: 0
   * Referenced by: '<S1>/Enable '
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Mode'
   */
  1.0,

  /* Expression: -5279
   * Referenced by: '<S7>/Constant'
   */
  -5279.0,

  /* Expression: 658
   * Referenced by: '<S7>/Constant1'
   */
  658.0,

  /* Expression: 0
   * Referenced by: '<S1>/Home'
   */
  0.0,

  /* Expression: 91.31957559317379
   * Referenced by: '<S1>/Setpoint(mm)'
   */
  91.3195755931738,

  /* Expression: -1
   * Referenced by: '<S4>/Dead Zone'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Dead Zone'
   */
  1.0,

  /* Expression: 117
   * Referenced by: '<S4>/Proportion Gain'
   */
  117.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator'
   */
  0.0,

  /* Expression: 350
   * Referenced by: '<S4>/Integrator'
   */
  350.0,

  /* Expression: -350
   * Referenced by: '<S4>/Integrator'
   */
  -350.0,

  /* Expression: 1
   * Referenced by: '<S4>/Derivative Gain'
   */
  1.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S4>/Transfer Fcn'
   */
  -100.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S4>/Transfer Fcn'
   */
  -10000.0,

  /* Computed Parameter: TransferFcn_D
   * Referenced by: '<S4>/Transfer Fcn'
   */
  100.0,

  /* Expression: 1500
   * Referenced by: '<S4>/Saturation1'
   */
  1500.0,

  /* Expression: -1500
   * Referenced by: '<S4>/Saturation1'
   */
  -1500.0,

  /* Expression: -1
   * Referenced by: '<S4>/Gain'
   */
  -1.0,

  /* Expression: 1000
   * Referenced by: '<S2>/Saturation1'
   */
  1000.0,

  /* Expression: -1000
   * Referenced by: '<S2>/Saturation1'
   */
  -1000.0,

  /* Expression: 20
   * Referenced by: '<S4>/Gain1'
   */
  20.0,

  /* Computed Parameter: BufferSize_Value
   * Referenced by: '<S6>/Buffer Size'
   */
  10U,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S6>/Constant4'
   */
  85U,

  /* Computed Parameter: Constant1_Value_e
   * Referenced by: '<S6>/Constant1'
   */
  191U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
