/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Potentiometer_Calibration23_types.h
 *
 * Code generated for Simulink model 'Potentiometer_Calibration23'.
 *
 * Model version                  : 13.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jul 23 12:06:42 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Potentiometer_Calibration23_types_h_
#define RTW_HEADER_Potentiometer_Calibration23_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<S3>/Serial Write' */
#include "MW_SVD.h"
#ifndef struct_tag_vB8gURpcbTUBlHcczw228B
#define struct_tag_vB8gURpcbTUBlHcczw228B

struct tag_vB8gURpcbTUBlHcczw228B
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_vB8gURpcbTUBlHcczw228B */

#ifndef typedef_e_codertarget_raspi_internal__T
#define typedef_e_codertarget_raspi_internal__T

typedef struct tag_vB8gURpcbTUBlHcczw228B e_codertarget_raspi_internal__T;

#endif                             /* typedef_e_codertarget_raspi_internal__T */

#ifndef struct_tag_VOf4ufvAb7nufAMTC2gUxC
#define struct_tag_VOf4ufvAb7nufAMTC2gUxC

struct tag_VOf4ufvAb7nufAMTC2gUxC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  e_codertarget_raspi_internal__T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_VOf4ufvAb7nufAMTC2gUxC */

#ifndef typedef_codertarget_raspi_internal_SC_T
#define typedef_codertarget_raspi_internal_SC_T

typedef struct tag_VOf4ufvAb7nufAMTC2gUxC codertarget_raspi_internal_SC_T;

#endif                             /* typedef_codertarget_raspi_internal_SC_T */

#ifndef struct_tag_QY5kIkagyBWqman9TieI9D
#define struct_tag_QY5kIkagyBWqman9TieI9D

struct tag_QY5kIkagyBWqman9TieI9D
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  e_codertarget_raspi_internal__T Hw;
  MW_Handle_Type MW_SCIHANDLE;
};

#endif                                 /* struct_tag_QY5kIkagyBWqman9TieI9D */

#ifndef typedef_codertarget_raspi_internal__m_T
#define typedef_codertarget_raspi_internal__m_T

typedef struct tag_QY5kIkagyBWqman9TieI9D codertarget_raspi_internal__m_T;

#endif                             /* typedef_codertarget_raspi_internal__m_T */

#ifndef struct_emxArray_real_T_255
#define struct_emxArray_real_T_255

struct emxArray_real_T_255
{
  real_T data[255];
  int32_T size;
};

#endif                                 /* struct_emxArray_real_T_255 */

#ifndef typedef_emxArray_real_T_255_Potentiom_T
#define typedef_emxArray_real_T_255_Potentiom_T

typedef struct emxArray_real_T_255 emxArray_real_T_255_Potentiom_T;

#endif                             /* typedef_emxArray_real_T_255_Potentiom_T */

/* Parameters (default storage) */
typedef struct P_Potentiometer_Calibration23_T_ P_Potentiometer_Calibration23_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Potentiometer_Calibra_T RT_MODEL_Potentiometer_Calibr_T;

#endif                     /* RTW_HEADER_Potentiometer_Calibration23_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
