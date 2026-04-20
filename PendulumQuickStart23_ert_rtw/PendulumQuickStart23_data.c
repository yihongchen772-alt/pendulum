/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PendulumQuickStart23_data.c
 *
 * Code generated for Simulink model 'PendulumQuickStart23'.
 *
 * Model version                  : 11.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jul 23 14:42:12 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (32-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PendulumQuickStart23.h"

/* Block parameters (default storage) */
P_PendulumQuickStart23_T PendulumQuickStart23_P = {
  /* Variable: K
   * Referenced by: '<S11>/Constant1'
   */
  { -38.729833462076911, 164.21096922856907, -76.341661170485068,
    41.057040642974329 },

  /* Variable: Nbar
   * Referenced by: '<S11>/Constant2'
   */
  -38.729833462076911,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S15>/Constant'
   */
  100.0,

  /* Expression: SampleTime
   * Referenced by: '<S9>/Serial Read'
   */
  0.004,

  /* Expression: 0
   * Referenced by: '<S1>/Mode'
   */
  0.0,

  /* Expression: 5268
   * Referenced by: '<S8>/Constant'
   */
  5268.0,

  /* Expression: 658
   * Referenced by: '<S8>/Constant1'
   */
  658.0,

  /* Expression: 1
   * Referenced by: '<S1>/Home'
   */
  1.0,

  /* Expression: 360
   * Referenced by: '<S12>/Constant'
   */
  360.0,

  /* Expression: -800
   * Referenced by: '<S12>/RodOffset'
   */
  -800.0,

  /* Expression: 2048
   * Referenced by: '<S12>/Constant1'
   */
  2048.0,

  /* Expression: 85
   * Referenced by: '<S7>/Constant1'
   */
  85.0,

  /* Expression: 191
   * Referenced by: '<S7>/Constant2'
   */
  191.0,

  /* Expression: 1
   * Referenced by: '<S1>/Enable'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Move Center'
   */
  1.0,

  /* Expression: -1e-3
   * Referenced by: '<S5>/Gain'
   */
  -0.001,

  /* Expression: -0.05
   * Referenced by: '<S11>/Dead Zone'
   */
  -0.05,

  /* Expression: +0.05
   * Referenced by: '<S11>/Dead Zone'
   */
  0.05,

  /* Expression: pi/180
   * Referenced by: '<S11>/Gain2'
   */
  0.017453292519943295,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S11>/Transfer Fcn'
   */
  { -11.309733552923255, -39.478417604357432 },

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S11>/Transfer Fcn'
   */
  { 39.478417604357432, 0.0 },

  /* Expression: 1
   * Referenced by: '<S11>/Gain3'
   */
  1.0,

  /* Computed Parameter: undOrder_A
   * Referenced by: '<S11>/2nd Order'
   */
  { -5.6548667764616276, -9.869604401089358 },

  /* Computed Parameter: undOrder_C
   * Referenced by: '<S11>/2nd Order'
   */
  { 9.869604401089358, 0.0 },

  /* Expression: 1*pi/180
   * Referenced by: '<S11>/Gain6'
   */
  0.017453292519943295,

  /* Expression: -3.397053617623811
   * Referenced by: '<S11>/Cart-Pos'
   */
  -3.3970536176238109,

  /* Expression: -1
   * Referenced by: '<S11>/Gain4'
   */
  -1.0,

  /* Expression: 35
   * Referenced by: '<S11>/Saturation'
   */
  35.0,

  /* Expression: -35
   * Referenced by: '<S11>/Saturation'
   */
  -35.0,

  /* Computed Parameter: FVolt_A
   * Referenced by: '<S11>/F//Volt'
   */
  -46.889653016567678,

  /* Computed Parameter: FVolt_C
   * Referenced by: '<S11>/F//Volt'
   */
  13.296488728573443,

  /* Computed Parameter: FVolt_D
   * Referenced by: '<S11>/F//Volt'
   */
  0.34261493239271018,

  /* Expression: 1000
   * Referenced by: '<S11>/Saturation1'
   */
  1000.0,

  /* Expression: -1000
   * Referenced by: '<S11>/Saturation1'
   */
  -1000.0,

  /* Expression: 1000/12
   * Referenced by: '<S11>/Gain'
   */
  83.333333333333329,

  /* Expression: 1
   * Referenced by: '<S11>/Gain7'
   */
  1.0,

  /* Expression: 1.2
   * Referenced by: '<S17>/Constant3'
   */
  1.2,

  /* Expression: 1000
   * Referenced by: '<S5>/Saturation1'
   */
  1000.0,

  /* Expression: -1000
   * Referenced by: '<S5>/Saturation1'
   */
  -1000.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Enable Control'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S7>/Saturation1'
   */
  1000.0,

  /* Expression: -1000
   * Referenced by: '<S7>/Saturation1'
   */
  -1000.0,

  /* Computed Parameter: BufferSize_Value
   * Referenced by: '<S9>/Buffer Size'
   */
  10U,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S9>/Constant4'
   */
  85U,

  /* Computed Parameter: Constant1_Value_h5
   * Referenced by: '<S9>/Constant1'
   */
  191U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
