/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CartControl.c
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
#include "CartControl_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "CartControl_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stddef.h>

/* Block signals (default storage) */
B_CartControl_T CartControl_B;

/* Continuous states */
X_CartControl_T CartControl_X;

/* Disabled State Vector */
XDis_CartControl_T CartControl_XDis;

/* Block states (default storage) */
DW_CartControl_T CartControl_DW;

/* Real-time model */
static RT_MODEL_CartControl_T CartControl_M_;
RT_MODEL_CartControl_T *const CartControl_M = &CartControl_M_;

/* Forward declaration for local functions */
static void CartControl_eml_find(const boolean_T x_data[], const int32_T *x_size,
  int32_T i_data[], int32_T *i_size);
static void CartControl_SystemCore_setup_a(codertarget_raspi_internal__a_T *obj);
static void CartControl_SystemCore_setup(codertarget_raspi_internal_SC_T *obj);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  CartControl_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  CartControl_step();
  CartControl_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  CartControl_step();
  CartControl_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

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

/* Function for MATLAB Function: '<S6>/MATLAB Function1' */
static void CartControl_eml_find(const boolean_T x_data[], const int32_T *x_size,
  int32_T i_data[], int32_T *i_size)
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

static void CartControl_SystemCore_setup_a(codertarget_raspi_internal__a_T *obj)
{
  void* SCIModuleVoidPtr;
  int32_T i;
  char_T b_SCIModuleLoc[13];
  static const char_T b_SCIModuleLoc_0[13] = "/dev/serial0";

  /* Start for MATLABSystem: '<S6>/Serial Read' */
  obj->isInitialized = 1;
  for (i = 0; i < 13; i++) {
    /* Start for MATLABSystem: '<S6>/Serial Read' */
    b_SCIModuleLoc[i] = b_SCIModuleLoc_0[i];
  }

  SCIModuleVoidPtr = (void*)(&b_SCIModuleLoc[0]);

  /* Start for MATLABSystem: '<S6>/Serial Read' */
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleVoidPtr, true, MW_UNDEFINED_VALUE,
    MW_UNDEFINED_VALUE);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, MW_SCI_PARITY_NONE,
                        MW_SCI_STOPBITS_1);
  obj->isSetupComplete = true;
}

static void CartControl_SystemCore_setup(codertarget_raspi_internal_SC_T *obj)
{
  void* SCIModuleVoidPtr;
  int32_T i;
  char_T b_SCIModuleLoc[13];
  static const char_T b_SCIModuleLoc_0[13] = "/dev/serial0";

  /* Start for MATLABSystem: '<S2>/Serial Write' */
  obj->isInitialized = 1;
  for (i = 0; i < 13; i++) {
    /* Start for MATLABSystem: '<S2>/Serial Write' */
    b_SCIModuleLoc[i] = b_SCIModuleLoc_0[i];
  }

  SCIModuleVoidPtr = (void*)(&b_SCIModuleLoc[0]);

  /* Start for MATLABSystem: '<S2>/Serial Write' */
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleVoidPtr, true, MW_UNDEFINED_VALUE,
    MW_UNDEFINED_VALUE);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, MW_SCI_PARITY_NONE,
                        MW_SCI_STOPBITS_1);
  obj->isSetupComplete = true;
}

/* Model step function */
void CartControl_step(void)
{
  int32_T i;
  int32_T inc;
  int32_T j;
  int32_T xfi;
  uint32_T qY;
  int16_T rtb_DataTypeConversion7;
  uint8_T rtb_TmpSignalConversionAtSFunct[5];
  uint8_T t_0[4];
  uint8_T t[2];
  uint8_T c_r;
  uint8_T h_r;
  uint8_T i_r;
  uint8_T j_r;
  uint8_T k_r;
  uint8_T l_r;
  uint8_T m_r;
  uint8_T rtb_DataTypeConversion1;
  uint8_T rtb_DataTypeConversion4;
  uint8_T status;
  boolean_T exitg1;
  boolean_T y;
  if (rtmIsMajorTimeStep(CartControl_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&CartControl_M->solverInfo,
                          ((CartControl_M->Timing.clockTick0+1)*
      CartControl_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(CartControl_M)) {
    CartControl_M->Timing.t[0] = rtsiGetT(&CartControl_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(CartControl_M)) {
    /* MATLABSystem: '<S6>/Serial Read' */
    if (CartControl_DW.obj.SampleTime != CartControl_P.SerialRead_SampleTime) {
      CartControl_DW.obj.SampleTime = CartControl_P.SerialRead_SampleTime;
    }

    status = MW_SCI_Receive(CartControl_DW.obj.MW_SCIHANDLE,
      &CartControl_B.RxDataLocChar[0], 10U);
    memcpy((void *)&CartControl_B.RxData[0], (void *)
           &CartControl_B.RxDataLocChar[0], (size_t)10 * sizeof(uint8_T));

    /* MATLAB Function: '<S6>/MATLAB Function1' incorporates:
     *  Constant: '<S6>/Buffer Size'
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/Constant4'
     *  MATLABSystem: '<S6>/Serial Read'
     * */
    if (!CartControl_DW.bff_not_empty) {
      for (i = 0; i < 10; i++) {
        CartControl_DW.packetindex[i] = 0U;
      }
    }

    if (!CartControl_DW.val_not_empty) {
      CartControl_DW.val_not_empty = true;
      CartControl_DW.bff.size = CartControl_P.BufferSize_Value;
      i = CartControl_P.BufferSize_Value;
      if (i - 1 >= 0) {
        memset(&CartControl_DW.bff.data[0], 0, (uint32_T)i * sizeof(real_T));
      }

      CartControl_DW.bff_not_empty = (CartControl_DW.bff.size != 0);
      inc = 0;
    } else {
      inc = 1;
    }

    CartControl_B.u0 = rt_roundd_snf(CartControl_DW.val - 1.0);
    if (CartControl_B.u0 < 256.0) {
      if (CartControl_B.u0 >= 0.0) {
        rtb_DataTypeConversion1 = (uint8_T)CartControl_B.u0;
      } else {
        rtb_DataTypeConversion1 = 0U;
      }
    } else {
      rtb_DataTypeConversion1 = MAX_uint8_T;
    }

    if (CartControl_DW.val - 1.0 == rtb_DataTypeConversion1) {
      if (CartControl_P.BufferSize_Value != 0) {
        if (CartControl_P.BufferSize_Value == 0U) {
          c_r = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          c_r = (uint8_T)((uint32_T)rtb_DataTypeConversion1 /
                          CartControl_P.BufferSize_Value);
        }

        rtb_DataTypeConversion1 = (uint8_T)((uint32_T)rtb_DataTypeConversion1 -
          (uint8_T)((uint32_T)c_r * CartControl_P.BufferSize_Value));
      }
    } else {
      CartControl_B.DeadZone = CartControl_DW.val - 1.0;
      if (CartControl_P.BufferSize_Value == 0) {
        if (CartControl_DW.val - 1.0 == 0.0) {
          CartControl_B.DeadZone = 0.0;
        }
      } else if (rtIsInf(CartControl_DW.val - 1.0)) {
        CartControl_B.DeadZone = (rtNaN);
      } else if (CartControl_DW.val - 1.0 == 0.0) {
        CartControl_B.DeadZone = 0.0;
      } else {
        CartControl_B.DeadZone = fmod(CartControl_DW.val - 1.0,
          CartControl_P.BufferSize_Value);
        if (CartControl_B.DeadZone == 0.0) {
          CartControl_B.DeadZone = 0.0;
        } else if (CartControl_DW.val - 1.0 < 0.0) {
          CartControl_B.DeadZone += (real_T)CartControl_P.BufferSize_Value;
        }
      }

      CartControl_B.u0 = rt_roundd_snf(CartControl_B.DeadZone);
      if (CartControl_B.u0 < 256.0) {
        if (CartControl_B.u0 >= 0.0) {
          rtb_DataTypeConversion1 = (uint8_T)CartControl_B.u0;
        } else {
          rtb_DataTypeConversion1 = 0U;
        }
      } else {
        rtb_DataTypeConversion1 = MAX_uint8_T;
      }
    }

    j = (int32_T)(rtb_DataTypeConversion1 + 1U);
    if (rtb_DataTypeConversion1 + 1U > 255U) {
      j = 255;
    }

    if (!CartControl_DW.bff_not_empty) {
      CartControl_DW.bff.size = CartControl_P.BufferSize_Value;
      i = CartControl_P.BufferSize_Value;
      if (i - 1 >= 0) {
        memset(&CartControl_DW.bff.data[0], 0, (uint32_T)i * sizeof(real_T));
      }

      CartControl_DW.bff_not_empty = (CartControl_DW.bff.size != 0);
    }

    if (status == 0) {
      for (i = 0; i < 10; i++) {
        xfi = (uint8_T)j + i;
        if (xfi > 255) {
          xfi = 255;
        }

        if (CartControl_P.BufferSize_Value == 0) {
          c_r = (uint8_T)(xfi - 1);
        } else {
          if (CartControl_P.BufferSize_Value == 0U) {
            c_r = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            c_r = (uint8_T)((uint32_T)(uint8_T)(xfi - 1) /
                            CartControl_P.BufferSize_Value);
          }

          c_r = (uint8_T)((uint32_T)(uint8_T)(xfi - 1) - (uint8_T)((uint32_T)c_r
            * CartControl_P.BufferSize_Value));
        }

        xfi = (int32_T)(c_r + 1U);
        if (c_r + 1U > 255U) {
          xfi = 255;
        }

        CartControl_DW.bff.data[xfi - 1] = CartControl_B.RxData[i];
      }

      if (inc == 1) {
        CartControl_DW.val += 10.0;
      }
    }

    xfi = (int32_T)((uint8_T)j + 1U);
    if ((uint8_T)j + 1U > 255U) {
      xfi = 255;
    }

    if ((uint8_T)xfi > CartControl_DW.bff.size) {
      inc = 0;
      i = 0;
    } else {
      inc = (uint8_T)xfi - 1;
      i = CartControl_DW.bff.size;
    }

    i -= inc;
    for (xfi = 0; xfi < i; xfi++) {
      CartControl_B.tmp_data_m[xfi] = (CartControl_DW.bff.data[inc + xfi] ==
        CartControl_P.Constant4_Value);
    }

    CartControl_eml_find(CartControl_B.tmp_data_m, &i, CartControl_B.tmp_data,
                         &inc);
    for (xfi = 0; xfi < inc; xfi++) {
      CartControl_B.u0 = (real_T)CartControl_B.tmp_data[xfi] + (real_T)(uint8_T)
        j;
      if (CartControl_B.u0 < 256.0) {
        if (CartControl_B.u0 >= 0.0) {
          CartControl_B.head_data[xfi] = (uint8_T)CartControl_B.u0;
        } else {
          CartControl_B.head_data[xfi] = 0U;
        }
      } else {
        CartControl_B.head_data[xfi] = MAX_uint8_T;
      }
    }

    if (inc == 0) {
      if (CartControl_DW.bff.size < 1) {
        i = -1;
      } else {
        i = CartControl_DW.bff.size - 1;
      }

      xfi = i + 1;
      for (j = 0; j <= i; j++) {
        CartControl_B.tmp_data_m[j] = (CartControl_DW.bff.data[j] ==
          CartControl_P.Constant4_Value);
      }

      CartControl_eml_find(CartControl_B.tmp_data_m, &xfi,
                           CartControl_B.tmp_data, &inc);
      for (j = 0; j < inc; j++) {
        xfi = CartControl_B.tmp_data[j];
        if (xfi < 0) {
          xfi = 0;
        } else if (xfi > 255) {
          xfi = 255;
        }

        CartControl_B.head_data[j] = (uint8_T)xfi;
      }
    }

    if (CartControl_P.BufferSize_Value == 0) {
      c_r = CartControl_B.head_data[0];
    } else {
      if (CartControl_P.BufferSize_Value == 0U) {
        c_r = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        c_r = (uint8_T)((uint32_T)CartControl_B.head_data[0] /
                        CartControl_P.BufferSize_Value);
      }

      c_r = (uint8_T)((uint32_T)CartControl_B.head_data[0] - (uint8_T)((uint32_T)
        c_r * CartControl_P.BufferSize_Value));
    }

    j = (int32_T)(c_r + 1U);
    if (c_r + 1U > 255U) {
      j = 255;
    }

    if (CartControl_DW.bff.data[j - 1] == CartControl_P.Constant1_Value_e) {
      qY = CartControl_B.head_data[0] - 1U;
      if (CartControl_B.head_data[0] - 1U > CartControl_B.head_data[0]) {
        qY = 0U;
      }

      if (CartControl_P.BufferSize_Value == 0) {
        status = (uint8_T)qY;
        rtb_DataTypeConversion1 = CartControl_B.head_data[0];
      } else {
        if (CartControl_P.BufferSize_Value == 0U) {
          c_r = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          c_r = (uint8_T)((uint32_T)(uint8_T)qY / CartControl_P.BufferSize_Value);
        }

        status = (uint8_T)((uint32_T)(uint8_T)qY - (uint8_T)((uint32_T)c_r *
          CartControl_P.BufferSize_Value));
        if (CartControl_P.BufferSize_Value == 0U) {
          c_r = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          c_r = (uint8_T)((uint32_T)CartControl_B.head_data[0] /
                          CartControl_P.BufferSize_Value);
        }

        rtb_DataTypeConversion1 = (uint8_T)((uint32_T)CartControl_B.head_data[0]
          - (uint8_T)((uint32_T)c_r * CartControl_P.BufferSize_Value));
      }

      j = (int32_T)(CartControl_B.head_data[0] + 1U);
      if (CartControl_B.head_data[0] + 1U > 255U) {
        j = 255;
      }

      if (CartControl_P.BufferSize_Value == 0) {
        rtb_DataTypeConversion4 = (uint8_T)j;
      } else {
        if (CartControl_P.BufferSize_Value == 0U) {
          c_r = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          c_r = (uint8_T)((uint32_T)(uint8_T)j / CartControl_P.BufferSize_Value);
        }

        rtb_DataTypeConversion4 = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)
          ((uint32_T)c_r * CartControl_P.BufferSize_Value));
      }

      j = (int32_T)(CartControl_B.head_data[0] + 2U);
      if (CartControl_B.head_data[0] + 2U > 255U) {
        j = 255;
      }

      if (CartControl_P.BufferSize_Value == 0) {
        h_r = (uint8_T)j;
      } else {
        if (CartControl_P.BufferSize_Value == 0U) {
          c_r = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          c_r = (uint8_T)((uint32_T)(uint8_T)j / CartControl_P.BufferSize_Value);
        }

        h_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)c_r *
          CartControl_P.BufferSize_Value));
      }

      j = (int32_T)(CartControl_B.head_data[0] + 3U);
      if (CartControl_B.head_data[0] + 3U > 255U) {
        j = 255;
      }

      if (CartControl_P.BufferSize_Value == 0) {
        i_r = (uint8_T)j;
      } else {
        if (CartControl_P.BufferSize_Value == 0U) {
          c_r = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          c_r = (uint8_T)((uint32_T)(uint8_T)j / CartControl_P.BufferSize_Value);
        }

        i_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)c_r *
          CartControl_P.BufferSize_Value));
      }

      j = (int32_T)(CartControl_B.head_data[0] + 4U);
      if (CartControl_B.head_data[0] + 4U > 255U) {
        j = 255;
      }

      if (CartControl_P.BufferSize_Value == 0) {
        j_r = (uint8_T)j;
      } else {
        if (CartControl_P.BufferSize_Value == 0U) {
          c_r = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          c_r = (uint8_T)((uint32_T)(uint8_T)j / CartControl_P.BufferSize_Value);
        }

        j_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)c_r *
          CartControl_P.BufferSize_Value));
      }

      j = (int32_T)(CartControl_B.head_data[0] + 5U);
      if (CartControl_B.head_data[0] + 5U > 255U) {
        j = 255;
      }

      if (CartControl_P.BufferSize_Value == 0) {
        k_r = (uint8_T)j;
      } else {
        if (CartControl_P.BufferSize_Value == 0U) {
          c_r = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          c_r = (uint8_T)((uint32_T)(uint8_T)j / CartControl_P.BufferSize_Value);
        }

        k_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)c_r *
          CartControl_P.BufferSize_Value));
      }

      j = (int32_T)(CartControl_B.head_data[0] + 6U);
      if (CartControl_B.head_data[0] + 6U > 255U) {
        j = 255;
      }

      if (CartControl_P.BufferSize_Value == 0) {
        l_r = (uint8_T)j;
      } else {
        if (CartControl_P.BufferSize_Value == 0U) {
          c_r = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          c_r = (uint8_T)((uint32_T)(uint8_T)j / CartControl_P.BufferSize_Value);
        }

        l_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)c_r *
          CartControl_P.BufferSize_Value));
      }

      j = (int32_T)(CartControl_B.head_data[0] + 7U);
      if (CartControl_B.head_data[0] + 7U > 255U) {
        j = 255;
      }

      if (CartControl_P.BufferSize_Value == 0) {
        m_r = (uint8_T)j;
      } else {
        if (CartControl_P.BufferSize_Value == 0U) {
          c_r = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          c_r = (uint8_T)((uint32_T)(uint8_T)j / CartControl_P.BufferSize_Value);
        }

        m_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)c_r *
          CartControl_P.BufferSize_Value));
      }

      j = (int32_T)(CartControl_B.head_data[0] + 8U);
      if (CartControl_B.head_data[0] + 8U > 255U) {
        j = 255;
      }

      if (CartControl_P.BufferSize_Value == 0) {
        c_r = (uint8_T)j;
      } else {
        if (CartControl_P.BufferSize_Value == 0U) {
          c_r = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          c_r = (uint8_T)((uint32_T)(uint8_T)j / CartControl_P.BufferSize_Value);
        }

        c_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)c_r *
          CartControl_P.BufferSize_Value));
      }

      j = (int32_T)(status + 1U);
      if (status + 1U > 255U) {
        j = 255;
      }

      CartControl_DW.packetindex[0] = (uint8_T)j;
      j = (int32_T)(rtb_DataTypeConversion1 + 1U);
      if (rtb_DataTypeConversion1 + 1U > 255U) {
        j = 255;
      }

      CartControl_DW.packetindex[1] = (uint8_T)j;
      j = (int32_T)(rtb_DataTypeConversion4 + 1U);
      if (rtb_DataTypeConversion4 + 1U > 255U) {
        j = 255;
      }

      CartControl_DW.packetindex[2] = (uint8_T)j;
      j = (int32_T)(h_r + 1U);
      if (h_r + 1U > 255U) {
        j = 255;
      }

      CartControl_DW.packetindex[3] = (uint8_T)j;
      j = (int32_T)(i_r + 1U);
      if (i_r + 1U > 255U) {
        j = 255;
      }

      CartControl_DW.packetindex[4] = (uint8_T)j;
      j = (int32_T)(j_r + 1U);
      if (j_r + 1U > 255U) {
        j = 255;
      }

      CartControl_DW.packetindex[5] = (uint8_T)j;
      j = (int32_T)(k_r + 1U);
      if (k_r + 1U > 255U) {
        j = 255;
      }

      CartControl_DW.packetindex[6] = (uint8_T)j;
      j = (int32_T)(l_r + 1U);
      if (l_r + 1U > 255U) {
        j = 255;
      }

      CartControl_DW.packetindex[7] = (uint8_T)j;
      j = (int32_T)(m_r + 1U);
      if (m_r + 1U > 255U) {
        j = 255;
      }

      CartControl_DW.packetindex[8] = (uint8_T)j;
      j = (int32_T)(c_r + 1U);
      if (c_r + 1U > 255U) {
        j = 255;
      }

      CartControl_DW.packetindex[9] = (uint8_T)j;
    }

    for (j = 0; j < 10; j++) {
      CartControl_B.packet[j] =
        CartControl_DW.bff.data[CartControl_DW.packetindex[j] - 1];
    }

    /* End of MATLAB Function: '<S6>/MATLAB Function1' */
    /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    CartControl_B.u0 = floor(CartControl_P.Constant1_Value);
    if (rtIsNaN(CartControl_B.u0) || rtIsInf(CartControl_B.u0)) {
      CartControl_B.u0 = 0.0;
    } else {
      CartControl_B.u0 = fmod(CartControl_B.u0, 256.0);
    }

    status = (uint8_T)(CartControl_B.u0 < 0.0 ? (int32_T)(uint8_T)-(int8_T)
                       (uint8_T)-CartControl_B.u0 : (int32_T)(uint8_T)
                       CartControl_B.u0);

    /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

    /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
     *  Constant: '<S2>/Constant2'
     */
    CartControl_B.u0 = floor(CartControl_P.Constant2_Value);
    if (rtIsNaN(CartControl_B.u0) || rtIsInf(CartControl_B.u0)) {
      CartControl_B.u0 = 0.0;
    } else {
      CartControl_B.u0 = fmod(CartControl_B.u0, 256.0);
    }

    rtb_DataTypeConversion1 = (uint8_T)(CartControl_B.u0 < 0.0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-CartControl_B.u0 : (int32_T)(uint8_T)
      CartControl_B.u0);

    /* End of DataTypeConversion: '<S2>/Data Type Conversion1' */

    /* DataTypeConversion: '<S2>/Data Type Conversion4' incorporates:
     *  Constant: '<S1>/Enable '
     *  DataTypeConversion: '<S1>/Data Type Conversion3'
     */
    rtb_DataTypeConversion4 = (uint8_T)(CartControl_P.Enable_Value != 0.0);

    /* MATLAB Function: '<S6>/MATLAB Function2' */
    CartControl_B.crc = MAX_uint32_T;
    for (i = 0; i < 6; i++) {
      CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[i]);
      if (CartControl_B.u0 < 256.0) {
        if (CartControl_B.u0 >= 0.0) {
          c_r = (uint8_T)CartControl_B.u0;
        } else {
          c_r = 0U;
        }
      } else {
        c_r = MAX_uint8_T;
      }

      CartControl_B.crc ^= (uint32_T)c_r << 24;
      for (j = 0; j < 8; j++) {
        xfi = (int32_T)(CartControl_B.crc >> 31);
        CartControl_B.crc <<= 1;
        if (xfi == 1) {
          CartControl_B.crc ^= 79764919U;
        }
      }
    }

    /* End of MATLAB Function: '<S6>/MATLAB Function2' */

    /* MATLAB Function: '<S6>/uint32_in2' */
    CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[6]);
    if (CartControl_B.u0 < 256.0) {
      if (CartControl_B.u0 >= 0.0) {
        t_0[0] = (uint8_T)CartControl_B.u0;
      } else {
        t_0[0] = 0U;
      }
    } else {
      t_0[0] = MAX_uint8_T;
    }

    CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[7]);
    if (CartControl_B.u0 < 256.0) {
      if (CartControl_B.u0 >= 0.0) {
        t_0[1] = (uint8_T)CartControl_B.u0;
      } else {
        t_0[1] = 0U;
      }
    } else {
      t_0[1] = MAX_uint8_T;
    }

    CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[8]);
    if (CartControl_B.u0 < 256.0) {
      if (CartControl_B.u0 >= 0.0) {
        t_0[2] = (uint8_T)CartControl_B.u0;
      } else {
        t_0[2] = 0U;
      }
    } else {
      t_0[2] = MAX_uint8_T;
    }

    CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[9]);
    if (CartControl_B.u0 < 256.0) {
      if (CartControl_B.u0 >= 0.0) {
        t_0[3] = (uint8_T)CartControl_B.u0;
      } else {
        t_0[3] = 0U;
      }
    } else {
      t_0[3] = MAX_uint8_T;
    }

    memcpy((void *)&CartControl_B.y, (void *)&t_0[0], (size_t)1 * sizeof
           (uint32_T));

    /* End of MATLAB Function: '<S6>/uint32_in2' */

    /* MATLAB Function: '<S6>/MATLAB Function3' */
    if (!CartControl_DW.validpack_not_empty) {
      CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[2]);
      if (CartControl_B.u0 < 256.0) {
        if (CartControl_B.u0 >= 0.0) {
          t[0] = (uint8_T)CartControl_B.u0;
        } else {
          t[0] = 0U;
        }
      } else {
        t[0] = MAX_uint8_T;
      }

      CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[3]);
      if (CartControl_B.u0 < 256.0) {
        if (CartControl_B.u0 >= 0.0) {
          t[1] = (uint8_T)CartControl_B.u0;
        } else {
          t[1] = 0U;
        }
      } else {
        t[1] = MAX_uint8_T;
      }

      memcpy((void *)&CartControl_DW.validpack, (void *)&t[0], (size_t)1 *
             sizeof(int16_T));
      CartControl_DW.validpack_not_empty = true;
    }

    if (!CartControl_DW.validpack2_not_empty) {
      CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[4]);
      if (CartControl_B.u0 < 256.0) {
        if (CartControl_B.u0 >= 0.0) {
          t[0] = (uint8_T)CartControl_B.u0;
        } else {
          t[0] = 0U;
        }
      } else {
        t[0] = MAX_uint8_T;
      }

      CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[5]);
      if (CartControl_B.u0 < 256.0) {
        if (CartControl_B.u0 >= 0.0) {
          t[1] = (uint8_T)CartControl_B.u0;
        } else {
          t[1] = 0U;
        }
      } else {
        t[1] = MAX_uint8_T;
      }

      memcpy((void *)&CartControl_DW.validpack2, (void *)&t[0], (size_t)1 *
             sizeof(int16_T));
      CartControl_DW.validpack2_not_empty = true;
    }

    if (CartControl_B.crc == CartControl_B.y) {
      CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[2]);
      if (CartControl_B.u0 < 256.0) {
        if (CartControl_B.u0 >= 0.0) {
          t[0] = (uint8_T)CartControl_B.u0;
        } else {
          t[0] = 0U;
        }
      } else {
        t[0] = MAX_uint8_T;
      }

      CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[3]);
      if (CartControl_B.u0 < 256.0) {
        if (CartControl_B.u0 >= 0.0) {
          t[1] = (uint8_T)CartControl_B.u0;
        } else {
          t[1] = 0U;
        }
      } else {
        t[1] = MAX_uint8_T;
      }

      memcpy((void *)&CartControl_DW.validpack, (void *)&t[0], (size_t)1 *
             sizeof(int16_T));
      CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[4]);
      if (CartControl_B.u0 < 256.0) {
        if (CartControl_B.u0 >= 0.0) {
          t[0] = (uint8_T)CartControl_B.u0;
        } else {
          t[0] = 0U;
        }
      } else {
        t[0] = MAX_uint8_T;
      }

      CartControl_B.u0 = rt_roundd_snf(CartControl_B.packet[5]);
      if (CartControl_B.u0 < 256.0) {
        if (CartControl_B.u0 >= 0.0) {
          t[1] = (uint8_T)CartControl_B.u0;
        } else {
          t[1] = 0U;
        }
      } else {
        t[1] = MAX_uint8_T;
      }

      memcpy((void *)&CartControl_DW.validpack2, (void *)&t[0], (size_t)1 *
             sizeof(int16_T));
      CartControl_B.rod = CartControl_DW.validpack;
    } else {
      CartControl_B.rod = CartControl_DW.validpack;
    }

    /* End of MATLAB Function: '<S6>/MATLAB Function3' */

    /* DataTypeConversion: '<S14>/Data Type Conversion2' */
    CartControl_B.DataTypeConversion2 = CartControl_DW.validpack2;

    /* Product: '<S7>/Product' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     *  Product: '<S7>/Divide'
     */
    CartControl_B.Product = CartControl_B.DataTypeConversion2 /
      CartControl_P.Constant_Value * CartControl_P.Constant1_Value_m;

    /* MATLAB Function: '<S1>/Homing Block' incorporates:
     *  Constant: '<S1>/Home'
     *  Constant: '<S1>/Mode'
     */
    if (CartControl_P.Mode_Value == 0.0) {
      if (CartControl_DW.homeval == 0.0) {
        if (CartControl_P.Home_Value == 0.0) {
          CartControl_DW.state = 0.0;
          CartControl_DW.homeval = 0.0;
          CartControl_DW.counter = 0.0;
          CartControl_DW.precart = 0.0;
          CartControl_DW.prepos = 0.0;
          memset(&CartControl_DW.precartArray[0], 0, 10U * sizeof(real_T));
        }

        if (CartControl_DW.state == 0.0) {
          CartControl_DW.torqueval_p = 0.0;
          if (CartControl_P.Home_Value == 1.0) {
            CartControl_DW.state = 1.0;
          }
        } else if (CartControl_DW.state == 1.0) {
          CartControl_DW.torqueval_p = 500.0;
          CartControl_DW.state = 2.0;
        } else if (CartControl_DW.counter == 100.0) {
          y = true;
          j = 0;
          exitg1 = false;
          while ((!exitg1) && (j < 10)) {
            if (!(CartControl_DW.precartArray[j] == CartControl_B.Product)) {
              y = false;
              exitg1 = true;
            } else {
              j++;
            }
          }

          if (y) {
            CartControl_DW.torqueval_p = 0.0;
            CartControl_DW.homeval = 1.0;
            CartControl_DW.prepos = CartControl_B.Product;
          } else {
            CartControl_DW.i++;
            CartControl_DW.precartArray[(int32_T)CartControl_DW.i - 1] =
              CartControl_DW.precart;
            if (CartControl_DW.i == 10.0) {
              CartControl_DW.i = 0.0;
            }

            CartControl_DW.precart = CartControl_B.Product;
          }
        } else {
          CartControl_DW.counter++;
        }
      } else if (CartControl_P.Home_Value == 0.0) {
        CartControl_DW.state = 0.0;
        CartControl_DW.homeval = 0.0;
        CartControl_DW.counter = 0.0;
        CartControl_DW.prepos = 0.0;
      }
    }

    CartControl_B.homed = CartControl_DW.homeval;
    CartControl_B.torque = CartControl_DW.torqueval_p;
    if (CartControl_DW.homeval == 1.0) {
      CartControl_B.cartPos = (-329.0 - CartControl_DW.prepos) +
        CartControl_B.Product;
    } else {
      CartControl_B.cartPos = CartControl_B.Product;
    }

    /* End of MATLAB Function: '<S1>/Homing Block' */

    /* Constant: '<S1>/Setpoint(mm)' */
    CartControl_B.Setpointmm = CartControl_P.Setpointmm_Value;

    /* Sum: '<S4>/Sum' */
    CartControl_B.DeadZone = CartControl_B.Setpointmm - CartControl_B.cartPos;

    /* DeadZone: '<S4>/Dead Zone' */
    if (CartControl_B.DeadZone > CartControl_P.DeadZone_End) {
      CartControl_B.DeadZone -= CartControl_P.DeadZone_End;
    } else if (CartControl_B.DeadZone >= CartControl_P.DeadZone_Start) {
      CartControl_B.DeadZone = 0.0;
    } else {
      CartControl_B.DeadZone -= CartControl_P.DeadZone_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone' */

    /* Gain: '<S4>/Proportion Gain' */
    CartControl_B.ProportionGain = CartControl_P.ProportionGain_Gain *
      CartControl_B.DeadZone;
  }

  /* Integrator: '<S4>/Integrator' */
  /* Limited  Integrator  */
  if (CartControl_X.Integrator_CSTATE >= CartControl_P.Integrator_UpperSat) {
    CartControl_X.Integrator_CSTATE = CartControl_P.Integrator_UpperSat;
  } else if (CartControl_X.Integrator_CSTATE <=
             CartControl_P.Integrator_LowerSat) {
    CartControl_X.Integrator_CSTATE = CartControl_P.Integrator_LowerSat;
  }

  if (rtmIsMajorTimeStep(CartControl_M)) {
    /* Gain: '<S4>/Derivative Gain' */
    CartControl_B.DerivativeGain = CartControl_P.DerivativeGain_Gain *
      CartControl_B.DeadZone;

    /* MATLAB Function: '<S1>/Selection' incorporates:
     *  Constant: '<S1>/Mode'
     *  Gain: '<S4>/Gain'
     *  Saturate: '<S4>/Saturation1'
     */
    if (CartControl_P.Mode_Value == 0.0) {
      CartControl_DW.torqueval = -CartControl_B.torque;
    }

    if (CartControl_P.Mode_Value == 1.0) {
      if (CartControl_B.homed == 1.0) {
        /* Sum: '<S4>/Sum1' incorporates:
         *  Integrator: '<S4>/Integrator'
         *  TransferFcn: '<S4>/Transfer Fcn'
         */
        CartControl_B.u0 = (CartControl_P.TransferFcn_C *
                            CartControl_X.TransferFcn_CSTATE +
                            CartControl_P.TransferFcn_D *
                            CartControl_B.DerivativeGain) +
          (CartControl_B.ProportionGain + CartControl_X.Integrator_CSTATE);

        /* Saturate: '<S4>/Saturation1' */
        if (CartControl_B.u0 > CartControl_P.Saturation1_UpperSat) {
          CartControl_B.u0 = CartControl_P.Saturation1_UpperSat;
        } else if (CartControl_B.u0 < CartControl_P.Saturation1_LowerSat) {
          CartControl_B.u0 = CartControl_P.Saturation1_LowerSat;
        }

        CartControl_DW.torqueval = -(CartControl_P.Gain_Gain * CartControl_B.u0);
      } else {
        CartControl_DW.torqueval = 0.0;
      }
    }

    /* Saturate: '<S2>/Saturation1' incorporates:
     *  MATLAB Function: '<S1>/Selection'
     */
    if (CartControl_DW.torqueval > CartControl_P.Saturation1_UpperSat_a) {
      CartControl_B.u0 = CartControl_P.Saturation1_UpperSat_a;
    } else if (CartControl_DW.torqueval < CartControl_P.Saturation1_LowerSat_h)
    {
      CartControl_B.u0 = CartControl_P.Saturation1_LowerSat_h;
    } else {
      CartControl_B.u0 = CartControl_DW.torqueval;
    }

    /* DataTypeConversion: '<S2>/Data Type Conversion7' incorporates:
     *  Saturate: '<S2>/Saturation1'
     */
    CartControl_B.u0 = floor(CartControl_B.u0);
    if (rtIsNaN(CartControl_B.u0) || rtIsInf(CartControl_B.u0)) {
      CartControl_B.u0 = 0.0;
    } else {
      CartControl_B.u0 = fmod(CartControl_B.u0, 65536.0);
    }

    rtb_DataTypeConversion7 = (int16_T)(CartControl_B.u0 < 0.0 ? (int32_T)
      (int16_T)-(int16_T)(uint16_T)-CartControl_B.u0 : (int32_T)(int16_T)
      (uint16_T)CartControl_B.u0);

    /* End of DataTypeConversion: '<S2>/Data Type Conversion7' */

    /* MATLAB Function: '<S2>/uint16_in1' */
    memcpy((void *)&t[0], (void *)&rtb_DataTypeConversion7, (size_t)2 * sizeof
           (uint8_T));

    /* SignalConversion generated from: '<S8>/ SFunction ' incorporates:
     *  MATLAB Function: '<S2>/MATLAB Function'
     *  MATLAB Function: '<S2>/uint16_in1'
     */
    rtb_TmpSignalConversionAtSFunct[0] = status;
    rtb_TmpSignalConversionAtSFunct[1] = rtb_DataTypeConversion1;
    rtb_TmpSignalConversionAtSFunct[2] = rtb_DataTypeConversion4;
    rtb_TmpSignalConversionAtSFunct[3] = t[0];
    rtb_TmpSignalConversionAtSFunct[4] = t[1];

    /* MATLAB Function: '<S2>/MATLAB Function' */
    qY = MAX_uint32_T;
    for (i = 0; i < 5; i++) {
      qY ^= (uint32_T)rtb_TmpSignalConversionAtSFunct[i] << 24;
      for (j = 0; j < 8; j++) {
        xfi = (int32_T)(qY >> 31);
        qY <<= 1;
        if (xfi == 1) {
          qY ^= 79764919U;
        }
      }
    }

    /* MATLAB Function: '<S2>/uint32_in' incorporates:
     *  MATLAB Function: '<S2>/MATLAB Function'
     */
    memcpy((void *)&t_0[0], (void *)&qY, (size_t)4 * sizeof(uint8_T));

    /* SignalConversion generated from: '<S2>/Serial Write' incorporates:
     *  MATLAB Function: '<S2>/uint16_in1'
     *  MATLAB Function: '<S2>/uint32_in'
     */
    CartControl_B.TmpSignalConversionAtSerial[0] = status;
    CartControl_B.TmpSignalConversionAtSerial[1] = rtb_DataTypeConversion1;
    CartControl_B.TmpSignalConversionAtSerial[2] = rtb_DataTypeConversion4;
    CartControl_B.TmpSignalConversionAtSerial[3] = t[0];
    CartControl_B.TmpSignalConversionAtSerial[4] = t[1];
    CartControl_B.TmpSignalConversionAtSerial[5] = t_0[0];
    CartControl_B.TmpSignalConversionAtSerial[6] = t_0[1];
    CartControl_B.TmpSignalConversionAtSerial[7] = t_0[2];
    CartControl_B.TmpSignalConversionAtSerial[8] = t_0[3];

    /* MATLABSystem: '<S2>/Serial Write' */
    memcpy((void *)&CartControl_B.TxDataLocChar[0], (void *)
           &CartControl_B.TmpSignalConversionAtSerial[0], (size_t)9 * sizeof
           (uint8_T));
    MW_SCI_Transmit(CartControl_DW.obj_m.MW_SCIHANDLE,
                    &CartControl_B.TxDataLocChar[0], 9U);

    /* Gain: '<S4>/Gain1' */
    CartControl_B.Gain1 = CartControl_P.Gain1_Gain * CartControl_B.DeadZone;

    /* DataTypeConversion: '<S14>/Data Type Conversion' */
    CartControl_B.DataTypeConversion = CartControl_B.rod;
  }

  if (rtmIsMajorTimeStep(CartControl_M)) {
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        CartControl_M->Timing.t[0];

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(CartControl_M)) {/* Sample time: [0.004s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((CartControl_M->Timing.clockTick1) * 0.004);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(CartControl_M)) {
    rt_ertODEUpdateContinuousStates(&CartControl_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++CartControl_M->Timing.clockTick0;
    CartControl_M->Timing.t[0] = rtsiGetSolverStopTime
      (&CartControl_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.004s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.004, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      CartControl_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void CartControl_derivatives(void)
{
  XDot_CartControl_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_CartControl_T *) CartControl_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator' */
  lsat = (CartControl_X.Integrator_CSTATE <= CartControl_P.Integrator_LowerSat);
  usat = (CartControl_X.Integrator_CSTATE >= CartControl_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (CartControl_B.Gain1 > 0.0)) || (usat &&
       (CartControl_B.Gain1 < 0.0))) {
    _rtXdot->Integrator_CSTATE = CartControl_B.Gain1;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S4>/Integrator' */

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = CartControl_P.TransferFcn_A *
    CartControl_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += CartControl_B.DerivativeGain;
}

/* Model initialize function */
void CartControl_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&CartControl_M->solverInfo,
                          &CartControl_M->Timing.simTimeStep);
    rtsiSetTPtr(&CartControl_M->solverInfo, &rtmGetTPtr(CartControl_M));
    rtsiSetStepSizePtr(&CartControl_M->solverInfo,
                       &CartControl_M->Timing.stepSize0);
    rtsiSetdXPtr(&CartControl_M->solverInfo, &CartControl_M->derivs);
    rtsiSetContStatesPtr(&CartControl_M->solverInfo, (real_T **)
                         &CartControl_M->contStates);
    rtsiSetNumContStatesPtr(&CartControl_M->solverInfo,
      &CartControl_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&CartControl_M->solverInfo,
      &CartControl_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&CartControl_M->solverInfo,
      &CartControl_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&CartControl_M->solverInfo,
      &CartControl_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&CartControl_M->solverInfo, (boolean_T**)
      &CartControl_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&CartControl_M->solverInfo, (&rtmGetErrorStatus
      (CartControl_M)));
    rtsiSetRTModelPtr(&CartControl_M->solverInfo, CartControl_M);
  }

  rtsiSetSimTimeStep(&CartControl_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&CartControl_M->solverInfo, false);
  CartControl_M->intgData.y = CartControl_M->odeY;
  CartControl_M->intgData.f[0] = CartControl_M->odeF[0];
  CartControl_M->intgData.f[1] = CartControl_M->odeF[1];
  CartControl_M->intgData.f[2] = CartControl_M->odeF[2];
  CartControl_M->contStates = ((X_CartControl_T *) &CartControl_X);
  CartControl_M->contStateDisabled = ((XDis_CartControl_T *) &CartControl_XDis);
  CartControl_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&CartControl_M->solverInfo, (void *)&CartControl_M->intgData);
  rtsiSetSolverName(&CartControl_M->solverInfo,"ode3");
  rtmSetTPtr(CartControl_M, &CartControl_M->Timing.tArray[0]);
  rtmSetTFinal(CartControl_M, -1);
  CartControl_M->Timing.stepSize0 = 0.004;

  /* External mode info */
  CartControl_M->Sizes.checksums[0] = (3358034468U);
  CartControl_M->Sizes.checksums[1] = (2876662314U);
  CartControl_M->Sizes.checksums[2] = (180721208U);
  CartControl_M->Sizes.checksums[3] = (473329090U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    CartControl_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(CartControl_M->extModeInfo,
      &CartControl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(CartControl_M->extModeInfo,
                        CartControl_M->Sizes.checksums);
    rteiSetTPtr(CartControl_M->extModeInfo, rtmGetTPtr(CartControl_M));
  }

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  CartControl_X.Integrator_CSTATE = CartControl_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn' */
  CartControl_X.TransferFcn_CSTATE = 0.0;
  CartControl_DW.bff.size = 0;

  /* Start for MATLABSystem: '<S6>/Serial Read' */
  CartControl_DW.obj.isInitialized = 0;
  CartControl_DW.obj.matlabCodegenIsDeleted = false;
  CartControl_DW.obj.SampleTime = CartControl_P.SerialRead_SampleTime;
  CartControl_SystemCore_setup_a(&CartControl_DW.obj);

  /* Start for MATLABSystem: '<S2>/Serial Write' */
  CartControl_DW.obj_m.isInitialized = 0;
  CartControl_DW.obj_m.matlabCodegenIsDeleted = false;
  CartControl_SystemCore_setup(&CartControl_DW.obj_m);
}

/* Model terminate function */
void CartControl_terminate(void)
{
  /* Terminate for MATLABSystem: '<S6>/Serial Read' */
  if (!CartControl_DW.obj.matlabCodegenIsDeleted) {
    CartControl_DW.obj.matlabCodegenIsDeleted = true;
    if ((CartControl_DW.obj.isInitialized == 1) &&
        CartControl_DW.obj.isSetupComplete) {
      MW_SCI_Close(CartControl_DW.obj.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Serial Read' */
  /* Terminate for MATLABSystem: '<S2>/Serial Write' */
  if (!CartControl_DW.obj_m.matlabCodegenIsDeleted) {
    CartControl_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((CartControl_DW.obj_m.isInitialized == 1) &&
        CartControl_DW.obj_m.isSetupComplete) {
      MW_SCI_Close(CartControl_DW.obj_m.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
