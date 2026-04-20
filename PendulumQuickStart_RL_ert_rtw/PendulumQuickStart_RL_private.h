/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PendulumQuickStart_RL_private.h
 *
 * Code generated for Simulink model 'PendulumQuickStart_RL'.
 *
 * Model version                  : 14.20
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Fri Apr 17 17:18:53 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef PendulumQuickStart_RL_private_h_
#define PendulumQuickStart_RL_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "PendulumQuickStart_RL_types.h"
#include "PendulumQuickStart_RL.h"
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

/* Used by FromWorkspace Block: '<S13>/From Workspace' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

extern real_T rt_roundd_snf(real_T u);
extern void microKernel12080111301191785960(int32_T K, const real32_T *A,
  int32_T LDA, const real32_T *B, real32_T *C);
extern void microKernel10342937760430656108(int32_T K, const real32_T *A,
  int32_T LDA, const real32_T *B, real32_T *C);
extern void macroKernel13917226898109328511(int32_T M, int32_T K, int32_T N,
  const real32_T *A, int32_T LDA, const real32_T *B, int32_T LDB, real32_T *C,
  int32_T LDC);
extern void matrixMultiply13917226898109328511(int32_T M, int32_T K, int32_T N,
  int32_T blockSizeM, int32_T blockSizeK, int32_T blockSizeN, const real32_T *A,
  const real32_T *B, real32_T *C);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);
extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);

/* private model entry point functions */
extern void PendulumQuickStart_RL_derivatives(void);

#endif                                 /* PendulumQuickStart_RL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
