/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PotentiometerSensorandFiltering23_data.c
 *
 * Code generated for Simulink model 'PotentiometerSensorandFiltering23'.
 *
 * Model version                  : 13.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Apr 22 15:23:21 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PotentiometerSensorandFiltering23.h"

/* Block parameters (default storage) */
P_PotentiometerSensorandFilte_T PotentiometerSensorandFilteri_P = {
  /* Expression: SampleTime
   * Referenced by: '<S2>/Serial Read'
   */
  0.004,

  /* Expression: 85
   * Referenced by: '<S1>/Constant1'
   */
  85.0,

  /* Expression: 191
   * Referenced by: '<S1>/Constant2'
   */
  191.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Saturation1'
   */
  1000.0,

  /* Expression: -1000
   * Referenced by: '<S1>/Saturation1'
   */
  -1000.0,

  /* Computed Parameter: DerivativeFilter_A
   * Referenced by: '<Root>/Derivative Filter'
   */
  -20.0,

  /* Computed Parameter: DerivativeFilter_C
   * Referenced by: '<Root>/Derivative Filter'
   */
  20.0,

  /* Computed Parameter: Filter_A
   * Referenced by: '<Root>/Filter'
   */
  -15.0,

  /* Computed Parameter: Filter_C
   * Referenced by: '<Root>/Filter'
   */
  15.0,

  /* Computed Parameter: BufferSize_Value
   * Referenced by: '<S2>/Buffer Size'
   */
  10U,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S2>/Constant4'
   */
  85U,

  /* Computed Parameter: Constant1_Value_g
   * Referenced by: '<S2>/Constant1'
   */
  191U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
