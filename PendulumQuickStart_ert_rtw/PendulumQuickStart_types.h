/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PendulumQuickStart_types.h
 *
 * Code generated for Simulink model 'PendulumQuickStart'.
 *
 * Model version                  : 14.2
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Tue Mar 31 17:19:17 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef PendulumQuickStart_types_h_
#define PendulumQuickStart_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<S9>/Serial Read' */
#include "MW_SVD.h"
#ifndef struct_tag_Wz2d2HkqjZj9uqbwniGuLD
#define struct_tag_Wz2d2HkqjZj9uqbwniGuLD

struct tag_Wz2d2HkqjZj9uqbwniGuLD
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_Wz2d2HkqjZj9uqbwniGuLD */

#ifndef typedef_d_codertarget_raspi_internal__T
#define typedef_d_codertarget_raspi_internal__T

typedef struct tag_Wz2d2HkqjZj9uqbwniGuLD d_codertarget_raspi_internal__T;

#endif                             /* typedef_d_codertarget_raspi_internal__T */

#ifndef struct_tag_1I6z4LLcwVt9s4l5Pkk6FF
#define struct_tag_1I6z4LLcwVt9s4l5Pkk6FF

struct tag_1I6z4LLcwVt9s4l5Pkk6FF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_codertarget_raspi_internal__T Hw;
  MW_Handle_Type MW_SCIHANDLE;
};

#endif                                 /* struct_tag_1I6z4LLcwVt9s4l5Pkk6FF */

#ifndef typedef_codertarget_raspi_internal_SC_T
#define typedef_codertarget_raspi_internal_SC_T

typedef struct tag_1I6z4LLcwVt9s4l5Pkk6FF codertarget_raspi_internal_SC_T;

#endif                             /* typedef_codertarget_raspi_internal_SC_T */

#ifndef struct_tag_A8Uxk735fUdEmEkL68Qi1
#define struct_tag_A8Uxk735fUdEmEkL68Qi1

struct tag_A8Uxk735fUdEmEkL68Qi1
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_codertarget_raspi_internal__T Hw;
  MW_Handle_Type MW_SCIHANDLE;
};

#endif                                 /* struct_tag_A8Uxk735fUdEmEkL68Qi1 */

#ifndef typedef_codertarget_raspi_internal__a_T
#define typedef_codertarget_raspi_internal__a_T

typedef struct tag_A8Uxk735fUdEmEkL68Qi1 codertarget_raspi_internal__a_T;

#endif                             /* typedef_codertarget_raspi_internal__a_T */

#ifndef struct_emxArray_real_T_255
#define struct_emxArray_real_T_255

struct emxArray_real_T_255
{
  real_T data[255];
  int32_T size;
};

#endif                                 /* struct_emxArray_real_T_255 */

#ifndef typedef_emxArray_real_T_255_PendulumQ_T
#define typedef_emxArray_real_T_255_PendulumQ_T

typedef struct emxArray_real_T_255 emxArray_real_T_255_PendulumQ_T;

#endif                             /* typedef_emxArray_real_T_255_PendulumQ_T */

/* Parameters (default storage) */
typedef struct P_PendulumQuickStart_T_ P_PendulumQuickStart_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_PendulumQuickStart_T RT_MODEL_PendulumQuickStart_T;

#endif                                 /* PendulumQuickStart_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
