/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PotentiometerSensorandFiltering23_private.h
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

#ifndef RTW_HEADER_PotentiometerSensorandFiltering23_private_h_
#define RTW_HEADER_PotentiometerSensorandFiltering23_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "PotentiometerSensorandFiltering23_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_roundd_snf(real_T u);

/* private model entry point functions */
extern void PotentiometerSensorandFiltering23_derivatives(void);

#endif             /* RTW_HEADER_PotentiometerSensorandFiltering23_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
