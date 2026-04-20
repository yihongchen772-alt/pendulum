/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Potentiometer_Calibration23.c
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

#include "Potentiometer_Calibration23.h"
#include "rtwtypes.h"
#include "Potentiometer_Calibration23_types.h"
#include <string.h>
#include "Potentiometer_Calibration23_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stddef.h>

/* Block signals (default storage) */
B_Potentiometer_Calibration23_T Potentiometer_Calibration23_B;

/* Block states (default storage) */
DW_Potentiometer_Calibration2_T Potentiometer_Calibration23_DW;

/* Real-time model */
static RT_MODEL_Potentiometer_Calibr_T Potentiometer_Calibration23_M_;
RT_MODEL_Potentiometer_Calibr_T *const Potentiometer_Calibration23_M =
  &Potentiometer_Calibration23_M_;

/* Forward declaration for local functions */
static void Potentiometer_Calibrat_eml_find(const boolean_T x_data[], const
  int32_T *x_size, int32_T i_data[], int32_T *i_size);
static void Potentiometer__SystemCore_setup(codertarget_raspi_internal_SC_T *obj);
static void Potentiomete_SystemCore_setup_m(codertarget_raspi_internal__m_T *obj);
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/MATLAB Function1' */
static void Potentiometer_Calibrat_eml_find(const boolean_T x_data[], const
  int32_T *x_size, int32_T i_data[], int32_T *i_size)
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  idx = 0;
  *i_size = *x_size;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= *x_size - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= *x_size) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (*x_size == 1) {
    if (idx == 0) {
      *i_size = 0;
    }
  } else if (idx < 1) {
    *i_size = 0;
  } else {
    *i_size = idx;
  }
}

static void Potentiometer__SystemCore_setup(codertarget_raspi_internal_SC_T *obj)
{
  void* SCIModuleVoidPtr;
  int32_T i;
  char_T b_SCIModuleLoc[13];
  static const char_T b_SCIModuleLoc_0[13] = "/dev/serial0";

  /* Start for MATLABSystem: '<S2>/Serial Read' */
  obj->isInitialized = 1;
  for (i = 0; i < 13; i++) {
    /* Start for MATLABSystem: '<S2>/Serial Read' */
    b_SCIModuleLoc[i] = b_SCIModuleLoc_0[i];
  }

  SCIModuleVoidPtr = (void*)(&b_SCIModuleLoc[0]);

  /* Start for MATLABSystem: '<S2>/Serial Read' */
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleVoidPtr, true, MW_UNDEFINED_VALUE,
    MW_UNDEFINED_VALUE);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, MW_SCI_PARITY_NONE,
                        MW_SCI_STOPBITS_1);
  obj->isSetupComplete = true;
}

static void Potentiomete_SystemCore_setup_m(codertarget_raspi_internal__m_T *obj)
{
  void* SCIModuleVoidPtr;
  int32_T i;
  char_T b_SCIModuleLoc[13];
  static const char_T b_SCIModuleLoc_0[13] = "/dev/serial0";

  /* Start for MATLABSystem: '<S3>/Serial Write' */
  obj->isInitialized = 1;
  for (i = 0; i < 13; i++) {
    /* Start for MATLABSystem: '<S3>/Serial Write' */
    b_SCIModuleLoc[i] = b_SCIModuleLoc_0[i];
  }

  SCIModuleVoidPtr = (void*)(&b_SCIModuleLoc[0]);

  /* Start for MATLABSystem: '<S3>/Serial Write' */
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleVoidPtr, true, MW_UNDEFINED_VALUE,
    MW_UNDEFINED_VALUE);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, MW_SCI_PARITY_NONE,
                        MW_SCI_STOPBITS_1);
  obj->isSetupComplete = true;
}

/* Model step function */
void Potentiometer_Calibration23_step(void)
{
  int32_T i;
  int32_T i_0;
  int32_T inc;
  int32_T loop_ub;
  int32_T tmp_size;
  uint32_T qY;
  int16_T rod;
  uint8_T rtb_TmpSignalConversionAtSFunct[5];
  uint8_T t_0[4];
  uint8_T t[2];
  uint8_T d_x;
  uint8_T e_x;
  uint8_T f_x;
  uint8_T g_x;
  uint8_T h_x;
  uint8_T i_x;
  uint8_T j_x;
  uint8_T rtb_DataTypeConversion4;
  uint8_T status;
  uint8_T xi;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   *  Constant: '<Root>/Constant1'
   */
  Potentiometer_Calibration23_B.VectorConcatenate[0] =
    Potentiometer_Calibration23_P.Constant1_Value;

  /* MATLABSystem: '<S2>/Serial Read' */
  if (Potentiometer_Calibration23_DW.obj.SampleTime !=
      Potentiometer_Calibration23_P.SerialRead_SampleTime) {
    Potentiometer_Calibration23_DW.obj.SampleTime =
      Potentiometer_Calibration23_P.SerialRead_SampleTime;
  }

  status = MW_SCI_Receive(Potentiometer_Calibration23_DW.obj.MW_SCIHANDLE,
    &Potentiometer_Calibration23_B.RxDataLocChar[0], 10U);
  memcpy((void *)&Potentiometer_Calibration23_B.RxData[0], (void *)
         &Potentiometer_Calibration23_B.RxDataLocChar[0], (size_t)10 * sizeof
         (uint8_T));

  /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
   *  Constant: '<S2>/Buffer Size'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant4'
   *  MATLABSystem: '<S2>/Serial Read'
   * */
  if (!Potentiometer_Calibration23_DW.bff_not_empty) {
    for (i = 0; i < 10; i++) {
      Potentiometer_Calibration23_DW.packetindex[i] = 0U;
    }
  }

  if (!Potentiometer_Calibration23_DW.val_not_empty) {
    Potentiometer_Calibration23_DW.val_not_empty = true;
    Potentiometer_Calibration23_DW.bff.size =
      Potentiometer_Calibration23_P.BufferSize_Value;
    loop_ub = Potentiometer_Calibration23_P.BufferSize_Value;
    if (loop_ub - 1 >= 0) {
      memset(&Potentiometer_Calibration23_DW.bff.data[0], 0, (uint32_T)loop_ub *
             sizeof(real_T));
    }

    Potentiometer_Calibration23_DW.bff_not_empty =
      (Potentiometer_Calibration23_DW.bff.size != 0);
    inc = 0;
  } else {
    inc = 1;
  }

  Potentiometer_Calibration23_B.b_r = rt_roundd_snf
    (Potentiometer_Calibration23_DW.val - 1.0);
  if (Potentiometer_Calibration23_B.b_r < 256.0) {
    if (Potentiometer_Calibration23_B.b_r >= 0.0) {
      xi = (uint8_T)Potentiometer_Calibration23_B.b_r;
    } else {
      xi = 0U;
    }
  } else {
    xi = MAX_uint8_T;
  }

  if (Potentiometer_Calibration23_DW.val - 1.0 == xi) {
    if (Potentiometer_Calibration23_P.BufferSize_Value != 0) {
      if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
        j_x = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        j_x = (uint8_T)((uint32_T)xi /
                        Potentiometer_Calibration23_P.BufferSize_Value);
      }

      xi = (uint8_T)((uint32_T)xi - (uint8_T)((uint32_T)j_x *
        Potentiometer_Calibration23_P.BufferSize_Value));
    }
  } else {
    Potentiometer_Calibration23_B.b_r = Potentiometer_Calibration23_DW.val - 1.0;
    if (Potentiometer_Calibration23_P.BufferSize_Value == 0) {
      if (Potentiometer_Calibration23_DW.val - 1.0 == 0.0) {
        Potentiometer_Calibration23_B.b_r = 0.0;
      }
    } else if (rtIsInf(Potentiometer_Calibration23_DW.val - 1.0)) {
      Potentiometer_Calibration23_B.b_r = (rtNaN);
    } else if (Potentiometer_Calibration23_DW.val - 1.0 == 0.0) {
      Potentiometer_Calibration23_B.b_r = 0.0;
    } else {
      Potentiometer_Calibration23_B.b_r = fmod
        (Potentiometer_Calibration23_DW.val - 1.0,
         Potentiometer_Calibration23_P.BufferSize_Value);
      if (Potentiometer_Calibration23_B.b_r == 0.0) {
        Potentiometer_Calibration23_B.b_r = 0.0;
      } else if (Potentiometer_Calibration23_DW.val - 1.0 < 0.0) {
        Potentiometer_Calibration23_B.b_r += (real_T)
          Potentiometer_Calibration23_P.BufferSize_Value;
      }
    }

    Potentiometer_Calibration23_B.b_r = rt_roundd_snf
      (Potentiometer_Calibration23_B.b_r);
    if (Potentiometer_Calibration23_B.b_r < 256.0) {
      if (Potentiometer_Calibration23_B.b_r >= 0.0) {
        xi = (uint8_T)Potentiometer_Calibration23_B.b_r;
      } else {
        xi = 0U;
      }
    } else {
      xi = MAX_uint8_T;
    }
  }

  i_0 = (int32_T)(xi + 1U);
  if (xi + 1U > 255U) {
    i_0 = 255;
  }

  if (!Potentiometer_Calibration23_DW.bff_not_empty) {
    Potentiometer_Calibration23_DW.bff.size =
      Potentiometer_Calibration23_P.BufferSize_Value;
    loop_ub = Potentiometer_Calibration23_P.BufferSize_Value;
    if (loop_ub - 1 >= 0) {
      memset(&Potentiometer_Calibration23_DW.bff.data[0], 0, (uint32_T)loop_ub *
             sizeof(real_T));
    }

    Potentiometer_Calibration23_DW.bff_not_empty =
      (Potentiometer_Calibration23_DW.bff.size != 0);
  }

  if (status == 0) {
    for (i = 0; i < 10; i++) {
      tmp_size = (uint8_T)i_0 + i;
      if (tmp_size > 255) {
        tmp_size = 255;
      }

      status = (uint8_T)(tmp_size - 1);
      if (Potentiometer_Calibration23_P.BufferSize_Value != 0) {
        if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
          j_x = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          j_x = (uint8_T)((uint32_T)(uint8_T)(tmp_size - 1) /
                          Potentiometer_Calibration23_P.BufferSize_Value);
        }

        status = (uint8_T)((uint32_T)(uint8_T)(tmp_size - 1) - (uint8_T)
                           ((uint32_T)j_x *
                            Potentiometer_Calibration23_P.BufferSize_Value));
      }

      tmp_size = (int32_T)(status + 1U);
      if (status + 1U > 255U) {
        tmp_size = 255;
      }

      Potentiometer_Calibration23_DW.bff.data[tmp_size - 1] =
        Potentiometer_Calibration23_B.RxData[i];
    }

    if (inc == 1) {
      Potentiometer_Calibration23_DW.val += 10.0;
    }
  }

  tmp_size = (int32_T)((uint8_T)i_0 + 1U);
  if ((uint8_T)i_0 + 1U > 255U) {
    tmp_size = 255;
  }

  if ((uint8_T)tmp_size > Potentiometer_Calibration23_DW.bff.size) {
    i = 0;
    inc = 0;
  } else {
    i = (uint8_T)tmp_size - 1;
    inc = Potentiometer_Calibration23_DW.bff.size;
  }

  loop_ub = inc - i;
  for (tmp_size = 0; tmp_size < loop_ub; tmp_size++) {
    Potentiometer_Calibration23_B.tmp_data_m[tmp_size] =
      (Potentiometer_Calibration23_DW.bff.data[i + tmp_size] ==
       Potentiometer_Calibration23_P.Constant4_Value);
  }

  Potentiometer_Calibrat_eml_find(Potentiometer_Calibration23_B.tmp_data_m,
    &loop_ub, Potentiometer_Calibration23_B.tmp_data, &i);
  for (tmp_size = 0; tmp_size < i; tmp_size++) {
    Potentiometer_Calibration23_B.b_r = (real_T)
      Potentiometer_Calibration23_B.tmp_data[tmp_size] + (real_T)(uint8_T)i_0;
    if (Potentiometer_Calibration23_B.b_r < 256.0) {
      if (Potentiometer_Calibration23_B.b_r >= 0.0) {
        Potentiometer_Calibration23_B.head_data[tmp_size] = (uint8_T)
          Potentiometer_Calibration23_B.b_r;
      } else {
        Potentiometer_Calibration23_B.head_data[tmp_size] = 0U;
      }
    } else {
      Potentiometer_Calibration23_B.head_data[tmp_size] = MAX_uint8_T;
    }
  }

  if (i == 0) {
    if (Potentiometer_Calibration23_DW.bff.size < 1) {
      loop_ub = -1;
    } else {
      loop_ub = Potentiometer_Calibration23_DW.bff.size - 1;
    }

    tmp_size = loop_ub + 1;
    for (i_0 = 0; i_0 <= loop_ub; i_0++) {
      Potentiometer_Calibration23_B.tmp_data_m[i_0] =
        (Potentiometer_Calibration23_DW.bff.data[i_0] ==
         Potentiometer_Calibration23_P.Constant4_Value);
    }

    Potentiometer_Calibrat_eml_find(Potentiometer_Calibration23_B.tmp_data_m,
      &tmp_size, Potentiometer_Calibration23_B.tmp_data, &i);
    for (i_0 = 0; i_0 < i; i_0++) {
      tmp_size = Potentiometer_Calibration23_B.tmp_data[i_0];
      if (tmp_size < 0) {
        tmp_size = 0;
      } else if (tmp_size > 255) {
        tmp_size = 255;
      }

      Potentiometer_Calibration23_B.head_data[i_0] = (uint8_T)tmp_size;
    }
  }

  if (Potentiometer_Calibration23_P.BufferSize_Value == 0) {
    xi = Potentiometer_Calibration23_B.head_data[0];
  } else {
    if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
      j_x = MAX_uint8_T;

      /* Divide by zero handler */
    } else {
      j_x = (uint8_T)((uint32_T)Potentiometer_Calibration23_B.head_data[0] /
                      Potentiometer_Calibration23_P.BufferSize_Value);
    }

    xi = (uint8_T)((uint32_T)Potentiometer_Calibration23_B.head_data[0] -
                   (uint8_T)((uint32_T)j_x *
      Potentiometer_Calibration23_P.BufferSize_Value));
  }

  i_0 = (int32_T)(xi + 1U);
  if (xi + 1U > 255U) {
    i_0 = 255;
  }

  if (Potentiometer_Calibration23_DW.bff.data[i_0 - 1] ==
      Potentiometer_Calibration23_P.Constant1_Value_k) {
    qY = Potentiometer_Calibration23_B.head_data[0] - 1U;
    if (Potentiometer_Calibration23_B.head_data[0] - 1U >
        Potentiometer_Calibration23_B.head_data[0]) {
      qY = 0U;
    }

    xi = (uint8_T)qY;
    if (Potentiometer_Calibration23_P.BufferSize_Value == 0) {
      status = Potentiometer_Calibration23_B.head_data[0];
    } else {
      if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
        j_x = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        j_x = (uint8_T)((uint32_T)(uint8_T)qY /
                        Potentiometer_Calibration23_P.BufferSize_Value);
      }

      xi = (uint8_T)((uint32_T)(uint8_T)qY - (uint8_T)((uint32_T)j_x *
        Potentiometer_Calibration23_P.BufferSize_Value));
      if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
        j_x = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        j_x = (uint8_T)((uint32_T)Potentiometer_Calibration23_B.head_data[0] /
                        Potentiometer_Calibration23_P.BufferSize_Value);
      }

      status = (uint8_T)((uint32_T)Potentiometer_Calibration23_B.head_data[0] -
                         (uint8_T)((uint32_T)j_x *
        Potentiometer_Calibration23_P.BufferSize_Value));
    }

    i_0 = (int32_T)(Potentiometer_Calibration23_B.head_data[0] + 1U);
    if (Potentiometer_Calibration23_B.head_data[0] + 1U > 255U) {
      i_0 = 255;
    }

    rtb_DataTypeConversion4 = (uint8_T)i_0;
    if (Potentiometer_Calibration23_P.BufferSize_Value != 0) {
      if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
        j_x = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                        Potentiometer_Calibration23_P.BufferSize_Value);
      }

      rtb_DataTypeConversion4 = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)
        ((uint32_T)j_x * Potentiometer_Calibration23_P.BufferSize_Value));
    }

    i_0 = (int32_T)(Potentiometer_Calibration23_B.head_data[0] + 2U);
    if (Potentiometer_Calibration23_B.head_data[0] + 2U > 255U) {
      i_0 = 255;
    }

    d_x = (uint8_T)i_0;
    if (Potentiometer_Calibration23_P.BufferSize_Value != 0) {
      if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
        j_x = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                        Potentiometer_Calibration23_P.BufferSize_Value);
      }

      d_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
        Potentiometer_Calibration23_P.BufferSize_Value));
    }

    i_0 = (int32_T)(Potentiometer_Calibration23_B.head_data[0] + 3U);
    if (Potentiometer_Calibration23_B.head_data[0] + 3U > 255U) {
      i_0 = 255;
    }

    e_x = (uint8_T)i_0;
    if (Potentiometer_Calibration23_P.BufferSize_Value != 0) {
      if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
        j_x = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                        Potentiometer_Calibration23_P.BufferSize_Value);
      }

      e_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
        Potentiometer_Calibration23_P.BufferSize_Value));
    }

    i_0 = (int32_T)(Potentiometer_Calibration23_B.head_data[0] + 4U);
    if (Potentiometer_Calibration23_B.head_data[0] + 4U > 255U) {
      i_0 = 255;
    }

    f_x = (uint8_T)i_0;
    if (Potentiometer_Calibration23_P.BufferSize_Value != 0) {
      if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
        j_x = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                        Potentiometer_Calibration23_P.BufferSize_Value);
      }

      f_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
        Potentiometer_Calibration23_P.BufferSize_Value));
    }

    i_0 = (int32_T)(Potentiometer_Calibration23_B.head_data[0] + 5U);
    if (Potentiometer_Calibration23_B.head_data[0] + 5U > 255U) {
      i_0 = 255;
    }

    g_x = (uint8_T)i_0;
    if (Potentiometer_Calibration23_P.BufferSize_Value != 0) {
      if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
        j_x = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                        Potentiometer_Calibration23_P.BufferSize_Value);
      }

      g_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
        Potentiometer_Calibration23_P.BufferSize_Value));
    }

    i_0 = (int32_T)(Potentiometer_Calibration23_B.head_data[0] + 6U);
    if (Potentiometer_Calibration23_B.head_data[0] + 6U > 255U) {
      i_0 = 255;
    }

    h_x = (uint8_T)i_0;
    if (Potentiometer_Calibration23_P.BufferSize_Value != 0) {
      if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
        j_x = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                        Potentiometer_Calibration23_P.BufferSize_Value);
      }

      h_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
        Potentiometer_Calibration23_P.BufferSize_Value));
    }

    i_0 = (int32_T)(Potentiometer_Calibration23_B.head_data[0] + 7U);
    if (Potentiometer_Calibration23_B.head_data[0] + 7U > 255U) {
      i_0 = 255;
    }

    i_x = (uint8_T)i_0;
    if (Potentiometer_Calibration23_P.BufferSize_Value != 0) {
      if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
        j_x = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                        Potentiometer_Calibration23_P.BufferSize_Value);
      }

      i_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
        Potentiometer_Calibration23_P.BufferSize_Value));
    }

    i_0 = (int32_T)(Potentiometer_Calibration23_B.head_data[0] + 8U);
    if (Potentiometer_Calibration23_B.head_data[0] + 8U > 255U) {
      i_0 = 255;
    }

    j_x = (uint8_T)i_0;
    if (Potentiometer_Calibration23_P.BufferSize_Value != 0) {
      if (Potentiometer_Calibration23_P.BufferSize_Value == 0U) {
        j_x = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                        Potentiometer_Calibration23_P.BufferSize_Value);
      }

      j_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
        Potentiometer_Calibration23_P.BufferSize_Value));
    }

    i_0 = (int32_T)(xi + 1U);
    if (xi + 1U > 255U) {
      i_0 = 255;
    }

    Potentiometer_Calibration23_DW.packetindex[0] = (uint8_T)i_0;
    i_0 = (int32_T)(status + 1U);
    if (status + 1U > 255U) {
      i_0 = 255;
    }

    Potentiometer_Calibration23_DW.packetindex[1] = (uint8_T)i_0;
    i_0 = (int32_T)(rtb_DataTypeConversion4 + 1U);
    if (rtb_DataTypeConversion4 + 1U > 255U) {
      i_0 = 255;
    }

    Potentiometer_Calibration23_DW.packetindex[2] = (uint8_T)i_0;
    i_0 = (int32_T)(d_x + 1U);
    if (d_x + 1U > 255U) {
      i_0 = 255;
    }

    Potentiometer_Calibration23_DW.packetindex[3] = (uint8_T)i_0;
    i_0 = (int32_T)(e_x + 1U);
    if (e_x + 1U > 255U) {
      i_0 = 255;
    }

    Potentiometer_Calibration23_DW.packetindex[4] = (uint8_T)i_0;
    i_0 = (int32_T)(f_x + 1U);
    if (f_x + 1U > 255U) {
      i_0 = 255;
    }

    Potentiometer_Calibration23_DW.packetindex[5] = (uint8_T)i_0;
    i_0 = (int32_T)(g_x + 1U);
    if (g_x + 1U > 255U) {
      i_0 = 255;
    }

    Potentiometer_Calibration23_DW.packetindex[6] = (uint8_T)i_0;
    i_0 = (int32_T)(h_x + 1U);
    if (h_x + 1U > 255U) {
      i_0 = 255;
    }

    Potentiometer_Calibration23_DW.packetindex[7] = (uint8_T)i_0;
    i_0 = (int32_T)(i_x + 1U);
    if (i_x + 1U > 255U) {
      i_0 = 255;
    }

    Potentiometer_Calibration23_DW.packetindex[8] = (uint8_T)i_0;
    i_0 = (int32_T)(j_x + 1U);
    if (j_x + 1U > 255U) {
      i_0 = 255;
    }

    Potentiometer_Calibration23_DW.packetindex[9] = (uint8_T)i_0;
  }

  for (i_0 = 0; i_0 < 10; i_0++) {
    Potentiometer_Calibration23_B.packet[i_0] =
      Potentiometer_Calibration23_DW.bff.data[Potentiometer_Calibration23_DW.packetindex
      [i_0] - 1];
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function1' */

  /* MATLAB Function: '<S2>/MATLAB Function2' */
  qY = MAX_uint32_T;
  for (i = 0; i < 6; i++) {
    Potentiometer_Calibration23_B.b_r = rt_roundd_snf
      (Potentiometer_Calibration23_B.packet[i]);
    if (Potentiometer_Calibration23_B.b_r < 256.0) {
      if (Potentiometer_Calibration23_B.b_r >= 0.0) {
        j_x = (uint8_T)Potentiometer_Calibration23_B.b_r;
      } else {
        j_x = 0U;
      }
    } else {
      j_x = MAX_uint8_T;
    }

    qY ^= (uint32_T)j_x << 24;
    for (inc = 0; inc < 8; inc++) {
      loop_ub = (int32_T)(qY >> 31);
      qY <<= 1;
      if (loop_ub == 1) {
        qY ^= 79764919U;
      }
    }
  }

  Potentiometer_Calibration23_B.crc_c = qY;

  /* End of MATLAB Function: '<S2>/MATLAB Function2' */

  /* MATLAB Function: '<S2>/uint32_in2' */
  Potentiometer_Calibration23_B.b_r = rt_roundd_snf
    (Potentiometer_Calibration23_B.packet[6]);
  if (Potentiometer_Calibration23_B.b_r < 256.0) {
    if (Potentiometer_Calibration23_B.b_r >= 0.0) {
      t_0[0] = (uint8_T)Potentiometer_Calibration23_B.b_r;
    } else {
      t_0[0] = 0U;
    }
  } else {
    t_0[0] = MAX_uint8_T;
  }

  Potentiometer_Calibration23_B.b_r = rt_roundd_snf
    (Potentiometer_Calibration23_B.packet[7]);
  if (Potentiometer_Calibration23_B.b_r < 256.0) {
    if (Potentiometer_Calibration23_B.b_r >= 0.0) {
      t_0[1] = (uint8_T)Potentiometer_Calibration23_B.b_r;
    } else {
      t_0[1] = 0U;
    }
  } else {
    t_0[1] = MAX_uint8_T;
  }

  Potentiometer_Calibration23_B.b_r = rt_roundd_snf
    (Potentiometer_Calibration23_B.packet[8]);
  if (Potentiometer_Calibration23_B.b_r < 256.0) {
    if (Potentiometer_Calibration23_B.b_r >= 0.0) {
      t_0[2] = (uint8_T)Potentiometer_Calibration23_B.b_r;
    } else {
      t_0[2] = 0U;
    }
  } else {
    t_0[2] = MAX_uint8_T;
  }

  Potentiometer_Calibration23_B.b_r = rt_roundd_snf
    (Potentiometer_Calibration23_B.packet[9]);
  if (Potentiometer_Calibration23_B.b_r < 256.0) {
    if (Potentiometer_Calibration23_B.b_r >= 0.0) {
      t_0[3] = (uint8_T)Potentiometer_Calibration23_B.b_r;
    } else {
      t_0[3] = 0U;
    }
  } else {
    t_0[3] = MAX_uint8_T;
  }

  memcpy((void *)&Potentiometer_Calibration23_B.y, (void *)&t_0[0], (size_t)1 *
         sizeof(uint32_T));

  /* End of MATLAB Function: '<S2>/uint32_in2' */

  /* MATLAB Function: '<S2>/MATLAB Function3' */
  if (!Potentiometer_Calibration23_DW.validpack_not_empty) {
    Potentiometer_Calibration23_B.b_r = rt_roundd_snf
      (Potentiometer_Calibration23_B.packet[2]);
    if (Potentiometer_Calibration23_B.b_r < 256.0) {
      if (Potentiometer_Calibration23_B.b_r >= 0.0) {
        t[0] = (uint8_T)Potentiometer_Calibration23_B.b_r;
      } else {
        t[0] = 0U;
      }
    } else {
      t[0] = MAX_uint8_T;
    }

    Potentiometer_Calibration23_B.b_r = rt_roundd_snf
      (Potentiometer_Calibration23_B.packet[3]);
    if (Potentiometer_Calibration23_B.b_r < 256.0) {
      if (Potentiometer_Calibration23_B.b_r >= 0.0) {
        t[1] = (uint8_T)Potentiometer_Calibration23_B.b_r;
      } else {
        t[1] = 0U;
      }
    } else {
      t[1] = MAX_uint8_T;
    }

    memcpy((void *)&Potentiometer_Calibration23_DW.validpack, (void *)&t[0],
           (size_t)1 * sizeof(int16_T));
    Potentiometer_Calibration23_DW.validpack_not_empty = true;
  }

  if (!Potentiometer_Calibration23_DW.validpack2_not_empty) {
    Potentiometer_Calibration23_B.b_r = rt_roundd_snf
      (Potentiometer_Calibration23_B.packet[4]);
    if (Potentiometer_Calibration23_B.b_r < 256.0) {
      if (Potentiometer_Calibration23_B.b_r >= 0.0) {
        t[0] = (uint8_T)Potentiometer_Calibration23_B.b_r;
      } else {
        t[0] = 0U;
      }
    } else {
      t[0] = MAX_uint8_T;
    }

    Potentiometer_Calibration23_B.b_r = rt_roundd_snf
      (Potentiometer_Calibration23_B.packet[5]);
    if (Potentiometer_Calibration23_B.b_r < 256.0) {
      if (Potentiometer_Calibration23_B.b_r >= 0.0) {
        t[1] = (uint8_T)Potentiometer_Calibration23_B.b_r;
      } else {
        t[1] = 0U;
      }
    } else {
      t[1] = MAX_uint8_T;
    }

    memcpy((void *)&Potentiometer_Calibration23_DW.validpack2, (void *)&t[0],
           (size_t)1 * sizeof(int16_T));
    Potentiometer_Calibration23_DW.validpack2_not_empty = true;
  }

  if (Potentiometer_Calibration23_B.crc_c == Potentiometer_Calibration23_B.y) {
    Potentiometer_Calibration23_B.b_r = rt_roundd_snf
      (Potentiometer_Calibration23_B.packet[2]);
    if (Potentiometer_Calibration23_B.b_r < 256.0) {
      if (Potentiometer_Calibration23_B.b_r >= 0.0) {
        t[0] = (uint8_T)Potentiometer_Calibration23_B.b_r;
      } else {
        t[0] = 0U;
      }
    } else {
      t[0] = MAX_uint8_T;
    }

    Potentiometer_Calibration23_B.b_r = rt_roundd_snf
      (Potentiometer_Calibration23_B.packet[3]);
    if (Potentiometer_Calibration23_B.b_r < 256.0) {
      if (Potentiometer_Calibration23_B.b_r >= 0.0) {
        t[1] = (uint8_T)Potentiometer_Calibration23_B.b_r;
      } else {
        t[1] = 0U;
      }
    } else {
      t[1] = MAX_uint8_T;
    }

    memcpy((void *)&Potentiometer_Calibration23_DW.validpack, (void *)&t[0],
           (size_t)1 * sizeof(int16_T));
    Potentiometer_Calibration23_B.b_r = rt_roundd_snf
      (Potentiometer_Calibration23_B.packet[4]);
    if (Potentiometer_Calibration23_B.b_r < 256.0) {
      if (Potentiometer_Calibration23_B.b_r >= 0.0) {
        t[0] = (uint8_T)Potentiometer_Calibration23_B.b_r;
      } else {
        t[0] = 0U;
      }
    } else {
      t[0] = MAX_uint8_T;
    }

    Potentiometer_Calibration23_B.b_r = rt_roundd_snf
      (Potentiometer_Calibration23_B.packet[5]);
    if (Potentiometer_Calibration23_B.b_r < 256.0) {
      if (Potentiometer_Calibration23_B.b_r >= 0.0) {
        t[1] = (uint8_T)Potentiometer_Calibration23_B.b_r;
      } else {
        t[1] = 0U;
      }
    } else {
      t[1] = MAX_uint8_T;
    }

    memcpy((void *)&Potentiometer_Calibration23_DW.validpack2, (void *)&t[0],
           (size_t)1 * sizeof(int16_T));
    rod = Potentiometer_Calibration23_DW.validpack;
  } else {
    rod = Potentiometer_Calibration23_DW.validpack;
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function3' */

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   *  Constant: '<Root>/Save'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  if (rod > Potentiometer_Calibration23_DW.maxAnalog) {
    Potentiometer_Calibration23_DW.maxAnalog = rod;
  }

  if ((Potentiometer_Calibration23_DW.minAnalog > rod) && (rod != 0)) {
    Potentiometer_Calibration23_DW.minAnalog = rod;
  }

  if (Potentiometer_Calibration23_P.Save_Value == 1.0) {
    Potentiometer_Calibration23_B.VectorConcatenate[1] =
      Potentiometer_Calibration23_DW.maxAnalog;
    Potentiometer_Calibration23_B.VectorConcatenate[2] =
      Potentiometer_Calibration23_DW.minAnalog;
    Potentiometer_Calibration23_B.VectorConcatenate[3] = rod;
  } else {
    Potentiometer_Calibration23_B.VectorConcatenate[1] = 500.0;
    Potentiometer_Calibration23_B.VectorConcatenate[2] = 500.0;
    Potentiometer_Calibration23_B.VectorConcatenate[3] = rod;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */
  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  Potentiometer_Calibration23_B.b_r = floor
    (Potentiometer_Calibration23_P.Constant1_Value_h);
  if (rtIsNaN(Potentiometer_Calibration23_B.b_r) || rtIsInf
      (Potentiometer_Calibration23_B.b_r)) {
    Potentiometer_Calibration23_B.b_r = 0.0;
  } else {
    Potentiometer_Calibration23_B.b_r = fmod(Potentiometer_Calibration23_B.b_r,
      256.0);
  }

  xi = (uint8_T)(Potentiometer_Calibration23_B.b_r < 0.0 ? (int32_T)(uint8_T)
                 -(int8_T)(uint8_T)-Potentiometer_Calibration23_B.b_r : (int32_T)
                 (uint8_T)Potentiometer_Calibration23_B.b_r);

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  Potentiometer_Calibration23_B.b_r = floor
    (Potentiometer_Calibration23_P.Constant2_Value);
  if (rtIsNaN(Potentiometer_Calibration23_B.b_r) || rtIsInf
      (Potentiometer_Calibration23_B.b_r)) {
    Potentiometer_Calibration23_B.b_r = 0.0;
  } else {
    Potentiometer_Calibration23_B.b_r = fmod(Potentiometer_Calibration23_B.b_r,
      256.0);
  }

  status = (uint8_T)(Potentiometer_Calibration23_B.b_r < 0.0 ? (int32_T)(uint8_T)
                     -(int8_T)(uint8_T)-Potentiometer_Calibration23_B.b_r :
                     (int32_T)(uint8_T)Potentiometer_Calibration23_B.b_r);

  /* End of DataTypeConversion: '<S3>/Data Type Conversion1' */

  /* DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  Potentiometer_Calibration23_B.b_r = floor
    (Potentiometer_Calibration23_P.Constant1_Value);
  if (rtIsNaN(Potentiometer_Calibration23_B.b_r) || rtIsInf
      (Potentiometer_Calibration23_B.b_r)) {
    Potentiometer_Calibration23_B.d = 0.0;
    Potentiometer_Calibration23_B.b_r = 0.0;
  } else {
    Potentiometer_Calibration23_B.d = fmod(Potentiometer_Calibration23_B.b_r,
      256.0);
    Potentiometer_Calibration23_B.b_r = fmod(Potentiometer_Calibration23_B.b_r,
      65536.0);
  }

  rtb_DataTypeConversion4 = (uint8_T)(Potentiometer_Calibration23_B.d < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-Potentiometer_Calibration23_B.d :
    (int32_T)(uint8_T)Potentiometer_Calibration23_B.d);

  /* End of DataTypeConversion: '<S3>/Data Type Conversion4' */

  /* DataTypeConversion: '<S3>/Data Type Conversion7' */
  rod = (int16_T)(Potentiometer_Calibration23_B.b_r < 0.0 ? (int32_T)(int16_T)
                  -(int16_T)(uint16_T)-Potentiometer_Calibration23_B.b_r :
                  (int32_T)(int16_T)(uint16_T)Potentiometer_Calibration23_B.b_r);

  /* MATLAB Function: '<S3>/uint16_in1' */
  memcpy((void *)&t[0], (void *)&rod, (size_t)2 * sizeof(uint8_T));

  /* SignalConversion generated from: '<S9>/ SFunction ' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  MATLAB Function: '<S3>/uint16_in1'
   */
  rtb_TmpSignalConversionAtSFunct[0] = xi;
  rtb_TmpSignalConversionAtSFunct[1] = status;
  rtb_TmpSignalConversionAtSFunct[2] = rtb_DataTypeConversion4;
  rtb_TmpSignalConversionAtSFunct[3] = t[0];
  rtb_TmpSignalConversionAtSFunct[4] = t[1];

  /* MATLAB Function: '<S3>/MATLAB Function' */
  qY = MAX_uint32_T;
  for (i = 0; i < 5; i++) {
    qY ^= (uint32_T)rtb_TmpSignalConversionAtSFunct[i] << 24;
    for (inc = 0; inc < 8; inc++) {
      loop_ub = (int32_T)(qY >> 31);
      qY <<= 1;
      if (loop_ub == 1) {
        qY ^= 79764919U;
      }
    }
  }

  /* MATLAB Function: '<S3>/uint32_in' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  memcpy((void *)&t_0[0], (void *)&qY, (size_t)4 * sizeof(uint8_T));

  /* SignalConversion generated from: '<S3>/Serial Write' incorporates:
   *  MATLAB Function: '<S3>/uint16_in1'
   *  MATLAB Function: '<S3>/uint32_in'
   */
  Potentiometer_Calibration23_B.TmpSignalConversionAtSerial[0] = xi;
  Potentiometer_Calibration23_B.TmpSignalConversionAtSerial[1] = status;
  Potentiometer_Calibration23_B.TmpSignalConversionAtSerial[2] =
    rtb_DataTypeConversion4;
  Potentiometer_Calibration23_B.TmpSignalConversionAtSerial[3] = t[0];
  Potentiometer_Calibration23_B.TmpSignalConversionAtSerial[4] = t[1];
  Potentiometer_Calibration23_B.TmpSignalConversionAtSerial[5] = t_0[0];
  Potentiometer_Calibration23_B.TmpSignalConversionAtSerial[6] = t_0[1];
  Potentiometer_Calibration23_B.TmpSignalConversionAtSerial[7] = t_0[2];
  Potentiometer_Calibration23_B.TmpSignalConversionAtSerial[8] = t_0[3];

  /* MATLABSystem: '<S3>/Serial Write' */
  memcpy((void *)&Potentiometer_Calibration23_B.TxDataLocChar[0], (void *)
         &Potentiometer_Calibration23_B.TmpSignalConversionAtSerial[0], (size_t)
         9 * sizeof(uint8_T));
  MW_SCI_Transmit(Potentiometer_Calibration23_DW.obj_o.MW_SCIHANDLE,
                  &Potentiometer_Calibration23_B.TxDataLocChar[0], 9U);

  {                                    /* Sample time: [0.004s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Potentiometer_Calibration23_M->Timing.taskTime0 =
    ((time_T)(++Potentiometer_Calibration23_M->Timing.clockTick0)) *
    Potentiometer_Calibration23_M->Timing.stepSize0;
}

/* Model initialize function */
void Potentiometer_Calibration23_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Potentiometer_Calibration23_M, 0,
                sizeof(RT_MODEL_Potentiometer_Calibr_T));
  rtmSetTFinal(Potentiometer_Calibration23_M, -1);
  Potentiometer_Calibration23_M->Timing.stepSize0 = 0.004;

  /* External mode info */
  Potentiometer_Calibration23_M->Sizes.checksums[0] = (1988005262U);
  Potentiometer_Calibration23_M->Sizes.checksums[1] = (1428336447U);
  Potentiometer_Calibration23_M->Sizes.checksums[2] = (3910148069U);
  Potentiometer_Calibration23_M->Sizes.checksums[3] = (433317464U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    Potentiometer_Calibration23_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Potentiometer_Calibration23_M->extModeInfo,
      &Potentiometer_Calibration23_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Potentiometer_Calibration23_M->extModeInfo,
                        Potentiometer_Calibration23_M->Sizes.checksums);
    rteiSetTPtr(Potentiometer_Calibration23_M->extModeInfo, rtmGetTPtr
                (Potentiometer_Calibration23_M));
  }

  /* block I/O */
  (void) memset(((void *) &Potentiometer_Calibration23_B), 0,
                sizeof(B_Potentiometer_Calibration23_T));

  /* states (dwork) */
  (void) memset((void *)&Potentiometer_Calibration23_DW, 0,
                sizeof(DW_Potentiometer_Calibration2_T));
  Potentiometer_Calibration23_DW.bff.size = 0;

  /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function1' */
  Potentiometer_Calibration23_DW.val_not_empty = false;
  Potentiometer_Calibration23_DW.bff_not_empty = false;
  Potentiometer_Calibration23_DW.val = 0.0;

  /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function3' */
  Potentiometer_Calibration23_DW.validpack_not_empty = false;
  Potentiometer_Calibration23_DW.validpack2_not_empty = false;

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
  Potentiometer_Calibration23_DW.maxAnalog = 500.0;
  Potentiometer_Calibration23_DW.minAnalog = 500.0;

  /* Start for MATLABSystem: '<S2>/Serial Read' */
  Potentiometer_Calibration23_DW.obj.isInitialized = 0;
  Potentiometer_Calibration23_DW.obj.matlabCodegenIsDeleted = false;
  Potentiometer_Calibration23_DW.obj.SampleTime =
    Potentiometer_Calibration23_P.SerialRead_SampleTime;
  Potentiometer__SystemCore_setup(&Potentiometer_Calibration23_DW.obj);

  /* Start for MATLABSystem: '<S3>/Serial Write' */
  Potentiometer_Calibration23_DW.obj_o.isInitialized = 0;
  Potentiometer_Calibration23_DW.obj_o.matlabCodegenIsDeleted = false;
  Potentiomete_SystemCore_setup_m(&Potentiometer_Calibration23_DW.obj_o);
}

/* Model terminate function */
void Potentiometer_Calibration23_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Serial Read' */
  if (!Potentiometer_Calibration23_DW.obj.matlabCodegenIsDeleted) {
    Potentiometer_Calibration23_DW.obj.matlabCodegenIsDeleted = true;
    if ((Potentiometer_Calibration23_DW.obj.isInitialized == 1) &&
        Potentiometer_Calibration23_DW.obj.isSetupComplete) {
      MW_SCI_Close(Potentiometer_Calibration23_DW.obj.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Read' */
  /* Terminate for MATLABSystem: '<S3>/Serial Write' */
  if (!Potentiometer_Calibration23_DW.obj_o.matlabCodegenIsDeleted) {
    Potentiometer_Calibration23_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Potentiometer_Calibration23_DW.obj_o.isInitialized == 1) &&
        Potentiometer_Calibration23_DW.obj_o.isSetupComplete) {
      MW_SCI_Close(Potentiometer_Calibration23_DW.obj_o.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Serial Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
