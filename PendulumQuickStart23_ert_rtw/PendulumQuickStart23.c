/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PendulumQuickStart23.c
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
#include "PendulumQuickStart23_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "PendulumQuickStart23_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stddef.h>

/* Block signals (default storage) */
B_PendulumQuickStart23_T PendulumQuickStart23_B;

/* Continuous states */
X_PendulumQuickStart23_T PendulumQuickStart23_X;

/* Disabled State Vector */
XDis_PendulumQuickStart23_T PendulumQuickStart23_XDis;

/* Block states (default storage) */
DW_PendulumQuickStart23_T PendulumQuickStart23_DW;

/* Real-time model */
static RT_MODEL_PendulumQuickStart23_T PendulumQuickStart23_M_;
RT_MODEL_PendulumQuickStart23_T *const PendulumQuickStart23_M =
  &PendulumQuickStart23_M_;

/* Forward declaration for local functions */
static void PendulumQuickStart23_eml_find(const boolean_T x_data[], const
  int32_T *x_size, int32_T i_data[], int32_T *i_size);
static void PendulumQuic_SystemCore_setup_a(codertarget_raspi_internal__a_T *obj);
static void PendulumQuickS_SystemCore_setup(codertarget_raspi_internal_SC_T *obj);

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PendulumQuickStart23_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  PendulumQuickStart23_step();
  PendulumQuickStart23_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  PendulumQuickStart23_step();
  PendulumQuickStart23_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  PendulumQuickStart23_step();
  PendulumQuickStart23_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

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

/* Function for MATLAB Function: '<S9>/MATLAB Function1' */
static void PendulumQuickStart23_eml_find(const boolean_T x_data[], const
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

static void PendulumQuic_SystemCore_setup_a(codertarget_raspi_internal__a_T *obj)
{
  void* SCIModuleVoidPtr;
  int32_T i;
  char_T b_SCIModuleLoc[13];
  static const char_T b_SCIModuleLoc_0[13] = "/dev/serial0";

  /* Start for MATLABSystem: '<S9>/Serial Read' */
  obj->isInitialized = 1;
  for (i = 0; i < 13; i++) {
    /* Start for MATLABSystem: '<S9>/Serial Read' */
    b_SCIModuleLoc[i] = b_SCIModuleLoc_0[i];
  }

  SCIModuleVoidPtr = (void*)(&b_SCIModuleLoc[0]);

  /* Start for MATLABSystem: '<S9>/Serial Read' */
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleVoidPtr, true, MW_UNDEFINED_VALUE,
    MW_UNDEFINED_VALUE);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, MW_SCI_PARITY_NONE,
                        MW_SCI_STOPBITS_1);
  obj->isSetupComplete = true;
}

static void PendulumQuickS_SystemCore_setup(codertarget_raspi_internal_SC_T *obj)
{
  void* SCIModuleVoidPtr;
  int32_T i;
  char_T b_SCIModuleLoc[13];
  static const char_T b_SCIModuleLoc_0[13] = "/dev/serial0";

  /* Start for MATLABSystem: '<S7>/Serial Write' */
  obj->isInitialized = 1;
  for (i = 0; i < 13; i++) {
    /* Start for MATLABSystem: '<S7>/Serial Write' */
    b_SCIModuleLoc[i] = b_SCIModuleLoc_0[i];
  }

  SCIModuleVoidPtr = (void*)(&b_SCIModuleLoc[0]);

  /* Start for MATLABSystem: '<S7>/Serial Write' */
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleVoidPtr, true, MW_UNDEFINED_VALUE,
    MW_UNDEFINED_VALUE);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, MW_SCI_PARITY_NONE,
                        MW_SCI_STOPBITS_1);
  obj->isSetupComplete = true;
}

/* Model step function */
void PendulumQuickStart23_step(void)
{
  real_T rtb_Product;
  int32_T tmp_data_0[255];
  int32_T i;
  int32_T i_0;
  int32_T inc;
  int32_T loop_ub;
  int32_T tmp_size;
  uint32_T qY;
  int16_T cart;
  int16_T rod;
  int8_T rtAction;
  uint8_T head_data[255];
  uint8_T RxData[10];
  uint8_T RxDataLocChar[10];
  uint8_T TxDataLocChar[9];
  uint8_T rtb_TmpSignalConversionAtSerial[9];
  uint8_T rtb_TmpSignalConversionAtSFun_k[5];
  uint8_T t_0[4];
  uint8_T t[2];
  uint8_T c_x;
  uint8_T d_x;
  uint8_T e_x;
  uint8_T f_x;
  uint8_T g_x;
  uint8_T h_x;
  uint8_T i_x;
  uint8_T j_x;
  uint8_T status;
  uint8_T xi;
  boolean_T tmp_data[255];
  boolean_T Compare;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(PendulumQuickStart23_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&PendulumQuickStart23_M->solverInfo,
                          ((PendulumQuickStart23_M->Timing.clockTick0+1)*
      PendulumQuickStart23_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PendulumQuickStart23_M)) {
    PendulumQuickStart23_M->Timing.t[0] = rtsiGetT
      (&PendulumQuickStart23_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(PendulumQuickStart23_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PendulumQuickStart23_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PendulumQuickStart23_DW.EnabledSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PendulumQuickStart23_DW.EnabledSubsystem1_SubsysRanBC);
  if (rtmIsMajorTimeStep(PendulumQuickStart23_M)) {
    /* MATLABSystem: '<S9>/Serial Read' */
    if (PendulumQuickStart23_DW.obj.SampleTime !=
        PendulumQuickStart23_P.SerialRead_SampleTime) {
      PendulumQuickStart23_DW.obj.SampleTime =
        PendulumQuickStart23_P.SerialRead_SampleTime;
    }

    status = MW_SCI_Receive(PendulumQuickStart23_DW.obj.MW_SCIHANDLE,
      &RxDataLocChar[0], 10U);
    memcpy((void *)&RxData[0], (void *)&RxDataLocChar[0], (size_t)10 * sizeof
           (uint8_T));

    /* MATLAB Function: '<S9>/MATLAB Function1' incorporates:
     *  Constant: '<S9>/Buffer Size'
     *  Constant: '<S9>/Constant1'
     *  Constant: '<S9>/Constant4'
     *  MATLABSystem: '<S9>/Serial Read'
     * */
    if (!PendulumQuickStart23_DW.bff_not_empty) {
      for (i = 0; i < 10; i++) {
        PendulumQuickStart23_DW.packetindex[i] = 0U;
      }
    }

    if (!PendulumQuickStart23_DW.val_not_empty) {
      PendulumQuickStart23_DW.val_not_empty = true;
      PendulumQuickStart23_DW.bff.size = PendulumQuickStart23_P.BufferSize_Value;
      loop_ub = PendulumQuickStart23_P.BufferSize_Value;
      if (loop_ub - 1 >= 0) {
        memset(&PendulumQuickStart23_DW.bff.data[0], 0, (uint32_T)loop_ub *
               sizeof(real_T));
      }

      PendulumQuickStart23_DW.bff_not_empty = (PendulumQuickStart23_DW.bff.size
        != 0);
      inc = 0;
    } else {
      inc = 1;
    }

    rtb_Product = rt_roundd_snf(PendulumQuickStart23_DW.val - 1.0);
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        xi = (uint8_T)rtb_Product;
      } else {
        xi = 0U;
      }
    } else {
      xi = MAX_uint8_T;
    }

    if (PendulumQuickStart23_DW.val - 1.0 == xi) {
      if (PendulumQuickStart23_P.BufferSize_Value != 0) {
        if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
          j_x = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          j_x = (uint8_T)((uint32_T)xi / PendulumQuickStart23_P.BufferSize_Value);
        }

        xi = (uint8_T)((uint32_T)xi - (uint8_T)((uint32_T)j_x *
          PendulumQuickStart23_P.BufferSize_Value));
      }
    } else {
      rtb_Product = PendulumQuickStart23_DW.val - 1.0;
      if (PendulumQuickStart23_P.BufferSize_Value == 0) {
        if (PendulumQuickStart23_DW.val - 1.0 == 0.0) {
          rtb_Product = 0.0;
        }
      } else if (rtIsInf(PendulumQuickStart23_DW.val - 1.0)) {
        rtb_Product = (rtNaN);
      } else if (PendulumQuickStart23_DW.val - 1.0 == 0.0) {
        rtb_Product = 0.0;
      } else {
        rtb_Product = fmod(PendulumQuickStart23_DW.val - 1.0,
                           PendulumQuickStart23_P.BufferSize_Value);
        if (rtb_Product == 0.0) {
          rtb_Product = 0.0;
        } else if (PendulumQuickStart23_DW.val - 1.0 < 0.0) {
          rtb_Product += (real_T)PendulumQuickStart23_P.BufferSize_Value;
        }
      }

      rtb_Product = rt_roundd_snf(rtb_Product);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          xi = (uint8_T)rtb_Product;
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

    if (!PendulumQuickStart23_DW.bff_not_empty) {
      PendulumQuickStart23_DW.bff.size = PendulumQuickStart23_P.BufferSize_Value;
      loop_ub = PendulumQuickStart23_P.BufferSize_Value;
      if (loop_ub - 1 >= 0) {
        memset(&PendulumQuickStart23_DW.bff.data[0], 0, (uint32_T)loop_ub *
               sizeof(real_T));
      }

      PendulumQuickStart23_DW.bff_not_empty = (PendulumQuickStart23_DW.bff.size
        != 0);
    }

    if (status == 0) {
      for (i = 0; i < 10; i++) {
        tmp_size = (uint8_T)i_0 + i;
        if (tmp_size > 255) {
          tmp_size = 255;
        }

        status = (uint8_T)(tmp_size - 1);
        if (PendulumQuickStart23_P.BufferSize_Value != 0) {
          if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
            j_x = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            j_x = (uint8_T)((uint32_T)(uint8_T)(tmp_size - 1) /
                            PendulumQuickStart23_P.BufferSize_Value);
          }

          status = (uint8_T)((uint32_T)(uint8_T)(tmp_size - 1) - (uint8_T)
                             ((uint32_T)j_x *
                              PendulumQuickStart23_P.BufferSize_Value));
        }

        tmp_size = (int32_T)(status + 1U);
        if (status + 1U > 255U) {
          tmp_size = 255;
        }

        PendulumQuickStart23_DW.bff.data[tmp_size - 1] = RxData[i];
      }

      if (inc == 1) {
        PendulumQuickStart23_DW.val += 10.0;
      }
    }

    tmp_size = (int32_T)((uint8_T)i_0 + 1U);
    if ((uint8_T)i_0 + 1U > 255U) {
      tmp_size = 255;
    }

    if ((uint8_T)tmp_size > PendulumQuickStart23_DW.bff.size) {
      i = 0;
      inc = 0;
    } else {
      i = (uint8_T)tmp_size - 1;
      inc = PendulumQuickStart23_DW.bff.size;
    }

    loop_ub = inc - i;
    for (tmp_size = 0; tmp_size < loop_ub; tmp_size++) {
      tmp_data[tmp_size] = (PendulumQuickStart23_DW.bff.data[i + tmp_size] ==
                            PendulumQuickStart23_P.Constant4_Value);
    }

    PendulumQuickStart23_eml_find(tmp_data, &loop_ub, tmp_data_0, &i);
    for (tmp_size = 0; tmp_size < i; tmp_size++) {
      rtb_Product = (real_T)tmp_data_0[tmp_size] + (real_T)(uint8_T)i_0;
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          head_data[tmp_size] = (uint8_T)rtb_Product;
        } else {
          head_data[tmp_size] = 0U;
        }
      } else {
        head_data[tmp_size] = MAX_uint8_T;
      }
    }

    if (i == 0) {
      if (PendulumQuickStart23_DW.bff.size < 1) {
        loop_ub = -1;
      } else {
        loop_ub = PendulumQuickStart23_DW.bff.size - 1;
      }

      tmp_size = loop_ub + 1;
      for (i_0 = 0; i_0 <= loop_ub; i_0++) {
        tmp_data[i_0] = (PendulumQuickStart23_DW.bff.data[i_0] ==
                         PendulumQuickStart23_P.Constant4_Value);
      }

      PendulumQuickStart23_eml_find(tmp_data, &tmp_size, tmp_data_0, &i);
      for (i_0 = 0; i_0 < i; i_0++) {
        tmp_size = tmp_data_0[i_0];
        if (tmp_size < 0) {
          tmp_size = 0;
        } else if (tmp_size > 255) {
          tmp_size = 255;
        }

        head_data[i_0] = (uint8_T)tmp_size;
      }
    }

    if (PendulumQuickStart23_P.BufferSize_Value == 0) {
      xi = head_data[0];
    } else {
      if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
        j_x = MAX_uint8_T;

        /* Divide by zero handler */
      } else {
        j_x = (uint8_T)((uint32_T)head_data[0] /
                        PendulumQuickStart23_P.BufferSize_Value);
      }

      xi = (uint8_T)((uint32_T)head_data[0] - (uint8_T)((uint32_T)j_x *
        PendulumQuickStart23_P.BufferSize_Value));
    }

    i_0 = (int32_T)(xi + 1U);
    if (xi + 1U > 255U) {
      i_0 = 255;
    }

    if (PendulumQuickStart23_DW.bff.data[i_0 - 1] ==
        PendulumQuickStart23_P.Constant1_Value_h5) {
      qY = head_data[0] - 1U;
      if (head_data[0] - 1U > head_data[0]) {
        qY = 0U;
      }

      xi = (uint8_T)qY;
      if (PendulumQuickStart23_P.BufferSize_Value == 0) {
        status = head_data[0];
      } else {
        if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
          j_x = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          j_x = (uint8_T)((uint32_T)(uint8_T)qY /
                          PendulumQuickStart23_P.BufferSize_Value);
        }

        xi = (uint8_T)((uint32_T)(uint8_T)qY - (uint8_T)((uint32_T)j_x *
          PendulumQuickStart23_P.BufferSize_Value));
        if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
          j_x = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          j_x = (uint8_T)((uint32_T)head_data[0] /
                          PendulumQuickStart23_P.BufferSize_Value);
        }

        status = (uint8_T)((uint32_T)head_data[0] - (uint8_T)((uint32_T)j_x *
          PendulumQuickStart23_P.BufferSize_Value));
      }

      i_0 = (int32_T)(head_data[0] + 1U);
      if (head_data[0] + 1U > 255U) {
        i_0 = 255;
      }

      c_x = (uint8_T)i_0;
      if (PendulumQuickStart23_P.BufferSize_Value != 0) {
        if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
          j_x = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                          PendulumQuickStart23_P.BufferSize_Value);
        }

        c_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
          PendulumQuickStart23_P.BufferSize_Value));
      }

      i_0 = (int32_T)(head_data[0] + 2U);
      if (head_data[0] + 2U > 255U) {
        i_0 = 255;
      }

      d_x = (uint8_T)i_0;
      if (PendulumQuickStart23_P.BufferSize_Value != 0) {
        if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
          j_x = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                          PendulumQuickStart23_P.BufferSize_Value);
        }

        d_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
          PendulumQuickStart23_P.BufferSize_Value));
      }

      i_0 = (int32_T)(head_data[0] + 3U);
      if (head_data[0] + 3U > 255U) {
        i_0 = 255;
      }

      e_x = (uint8_T)i_0;
      if (PendulumQuickStart23_P.BufferSize_Value != 0) {
        if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
          j_x = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                          PendulumQuickStart23_P.BufferSize_Value);
        }

        e_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
          PendulumQuickStart23_P.BufferSize_Value));
      }

      i_0 = (int32_T)(head_data[0] + 4U);
      if (head_data[0] + 4U > 255U) {
        i_0 = 255;
      }

      f_x = (uint8_T)i_0;
      if (PendulumQuickStart23_P.BufferSize_Value != 0) {
        if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
          j_x = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                          PendulumQuickStart23_P.BufferSize_Value);
        }

        f_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
          PendulumQuickStart23_P.BufferSize_Value));
      }

      i_0 = (int32_T)(head_data[0] + 5U);
      if (head_data[0] + 5U > 255U) {
        i_0 = 255;
      }

      g_x = (uint8_T)i_0;
      if (PendulumQuickStart23_P.BufferSize_Value != 0) {
        if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
          j_x = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                          PendulumQuickStart23_P.BufferSize_Value);
        }

        g_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
          PendulumQuickStart23_P.BufferSize_Value));
      }

      i_0 = (int32_T)(head_data[0] + 6U);
      if (head_data[0] + 6U > 255U) {
        i_0 = 255;
      }

      h_x = (uint8_T)i_0;
      if (PendulumQuickStart23_P.BufferSize_Value != 0) {
        if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
          j_x = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                          PendulumQuickStart23_P.BufferSize_Value);
        }

        h_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
          PendulumQuickStart23_P.BufferSize_Value));
      }

      i_0 = (int32_T)(head_data[0] + 7U);
      if (head_data[0] + 7U > 255U) {
        i_0 = 255;
      }

      i_x = (uint8_T)i_0;
      if (PendulumQuickStart23_P.BufferSize_Value != 0) {
        if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
          j_x = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                          PendulumQuickStart23_P.BufferSize_Value);
        }

        i_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
          PendulumQuickStart23_P.BufferSize_Value));
      }

      i_0 = (int32_T)(head_data[0] + 8U);
      if (head_data[0] + 8U > 255U) {
        i_0 = 255;
      }

      j_x = (uint8_T)i_0;
      if (PendulumQuickStart23_P.BufferSize_Value != 0) {
        if (PendulumQuickStart23_P.BufferSize_Value == 0U) {
          j_x = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          j_x = (uint8_T)((uint32_T)(uint8_T)i_0 /
                          PendulumQuickStart23_P.BufferSize_Value);
        }

        j_x = (uint8_T)((uint32_T)(uint8_T)i_0 - (uint8_T)((uint32_T)j_x *
          PendulumQuickStart23_P.BufferSize_Value));
      }

      i_0 = (int32_T)(xi + 1U);
      if (xi + 1U > 255U) {
        i_0 = 255;
      }

      PendulumQuickStart23_DW.packetindex[0] = (uint8_T)i_0;
      i_0 = (int32_T)(status + 1U);
      if (status + 1U > 255U) {
        i_0 = 255;
      }

      PendulumQuickStart23_DW.packetindex[1] = (uint8_T)i_0;
      i_0 = (int32_T)(c_x + 1U);
      if (c_x + 1U > 255U) {
        i_0 = 255;
      }

      PendulumQuickStart23_DW.packetindex[2] = (uint8_T)i_0;
      i_0 = (int32_T)(d_x + 1U);
      if (d_x + 1U > 255U) {
        i_0 = 255;
      }

      PendulumQuickStart23_DW.packetindex[3] = (uint8_T)i_0;
      i_0 = (int32_T)(e_x + 1U);
      if (e_x + 1U > 255U) {
        i_0 = 255;
      }

      PendulumQuickStart23_DW.packetindex[4] = (uint8_T)i_0;
      i_0 = (int32_T)(f_x + 1U);
      if (f_x + 1U > 255U) {
        i_0 = 255;
      }

      PendulumQuickStart23_DW.packetindex[5] = (uint8_T)i_0;
      i_0 = (int32_T)(g_x + 1U);
      if (g_x + 1U > 255U) {
        i_0 = 255;
      }

      PendulumQuickStart23_DW.packetindex[6] = (uint8_T)i_0;
      i_0 = (int32_T)(h_x + 1U);
      if (h_x + 1U > 255U) {
        i_0 = 255;
      }

      PendulumQuickStart23_DW.packetindex[7] = (uint8_T)i_0;
      i_0 = (int32_T)(i_x + 1U);
      if (i_x + 1U > 255U) {
        i_0 = 255;
      }

      PendulumQuickStart23_DW.packetindex[8] = (uint8_T)i_0;
      i_0 = (int32_T)(j_x + 1U);
      if (j_x + 1U > 255U) {
        i_0 = 255;
      }

      PendulumQuickStart23_DW.packetindex[9] = (uint8_T)i_0;
    }

    for (i_0 = 0; i_0 < 10; i_0++) {
      PendulumQuickStart23_B.packet[i_0] =
        PendulumQuickStart23_DW.bff.data[PendulumQuickStart23_DW.packetindex[i_0]
        - 1];
    }

    /* End of MATLAB Function: '<S9>/MATLAB Function1' */

    /* MATLAB Function: '<S9>/MATLAB Function2' */
    qY = MAX_uint32_T;
    for (i = 0; i < 6; i++) {
      rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[i]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          j_x = (uint8_T)rtb_Product;
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

    PendulumQuickStart23_B.crc = qY;

    /* End of MATLAB Function: '<S9>/MATLAB Function2' */

    /* MATLAB Function: '<S9>/uint32_in2' */
    rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[6]);
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        t_0[0] = (uint8_T)rtb_Product;
      } else {
        t_0[0] = 0U;
      }
    } else {
      t_0[0] = MAX_uint8_T;
    }

    rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[7]);
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        t_0[1] = (uint8_T)rtb_Product;
      } else {
        t_0[1] = 0U;
      }
    } else {
      t_0[1] = MAX_uint8_T;
    }

    rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[8]);
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        t_0[2] = (uint8_T)rtb_Product;
      } else {
        t_0[2] = 0U;
      }
    } else {
      t_0[2] = MAX_uint8_T;
    }

    rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[9]);
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        t_0[3] = (uint8_T)rtb_Product;
      } else {
        t_0[3] = 0U;
      }
    } else {
      t_0[3] = MAX_uint8_T;
    }

    memcpy((void *)&PendulumQuickStart23_B.y, (void *)&t_0[0], (size_t)1 *
           sizeof(uint32_T));

    /* End of MATLAB Function: '<S9>/uint32_in2' */

    /* MATLAB Function: '<S9>/MATLAB Function3' */
    if (!PendulumQuickStart23_DW.validpack_not_empty) {
      rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[2]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[0] = (uint8_T)rtb_Product;
        } else {
          t[0] = 0U;
        }
      } else {
        t[0] = MAX_uint8_T;
      }

      rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[3]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[1] = (uint8_T)rtb_Product;
        } else {
          t[1] = 0U;
        }
      } else {
        t[1] = MAX_uint8_T;
      }

      memcpy((void *)&PendulumQuickStart23_DW.validpack, (void *)&t[0], (size_t)
             1 * sizeof(int16_T));
      PendulumQuickStart23_DW.validpack_not_empty = true;
    }

    if (!PendulumQuickStart23_DW.validpack2_not_empty) {
      rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[4]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[0] = (uint8_T)rtb_Product;
        } else {
          t[0] = 0U;
        }
      } else {
        t[0] = MAX_uint8_T;
      }

      rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[5]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[1] = (uint8_T)rtb_Product;
        } else {
          t[1] = 0U;
        }
      } else {
        t[1] = MAX_uint8_T;
      }

      memcpy((void *)&PendulumQuickStart23_DW.validpack2, (void *)&t[0], (size_t)
             1 * sizeof(int16_T));
      PendulumQuickStart23_DW.validpack2_not_empty = true;
    }

    if (PendulumQuickStart23_B.crc == PendulumQuickStart23_B.y) {
      rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[2]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[0] = (uint8_T)rtb_Product;
        } else {
          t[0] = 0U;
        }
      } else {
        t[0] = MAX_uint8_T;
      }

      rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[3]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[1] = (uint8_T)rtb_Product;
        } else {
          t[1] = 0U;
        }
      } else {
        t[1] = MAX_uint8_T;
      }

      memcpy((void *)&PendulumQuickStart23_DW.validpack, (void *)&t[0], (size_t)
             1 * sizeof(int16_T));
      rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[4]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[0] = (uint8_T)rtb_Product;
        } else {
          t[0] = 0U;
        }
      } else {
        t[0] = MAX_uint8_T;
      }

      rtb_Product = rt_roundd_snf(PendulumQuickStart23_B.packet[5]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[1] = (uint8_T)rtb_Product;
        } else {
          t[1] = 0U;
        }
      } else {
        t[1] = MAX_uint8_T;
      }

      memcpy((void *)&PendulumQuickStart23_DW.validpack2, (void *)&t[0], (size_t)
             1 * sizeof(int16_T));
      rod = PendulumQuickStart23_DW.validpack;
      cart = PendulumQuickStart23_DW.validpack2;
    } else {
      rod = PendulumQuickStart23_DW.validpack;
      cart = PendulumQuickStart23_DW.validpack2;
    }

    /* End of MATLAB Function: '<S9>/MATLAB Function3' */

    /* Product: '<S8>/Product' incorporates:
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/Constant1'
     *  DataTypeConversion: '<S26>/Data Type Conversion2'
     *  Product: '<S8>/Divide'
     */
    rtb_Product = (real_T)cart / PendulumQuickStart23_P.Constant_Value *
      PendulumQuickStart23_P.Constant1_Value;

    /* MATLAB Function: '<S1>/Homing Block' incorporates:
     *  Constant: '<S1>/Home'
     *  Constant: '<S1>/Mode'
     */
    if (PendulumQuickStart23_P.Mode_Value == 0.0) {
      if (PendulumQuickStart23_DW.homeval == 0.0) {
        if (PendulumQuickStart23_P.Home_Value == 0.0) {
          PendulumQuickStart23_DW.state = 0.0;
          PendulumQuickStart23_DW.homeval = 0.0;
          PendulumQuickStart23_DW.counter = 0.0;
          PendulumQuickStart23_DW.precart = 0.0;
          PendulumQuickStart23_DW.prepos = 0.0;
          memset(&PendulumQuickStart23_DW.precartArray[0], 0, 10U * sizeof
                 (real_T));
        }

        if (PendulumQuickStart23_DW.state == 0.0) {
          PendulumQuickStart23_DW.torqueval_e = 0.0;
          if (PendulumQuickStart23_P.Home_Value == 1.0) {
            PendulumQuickStart23_DW.state = 1.0;
          }
        } else if (PendulumQuickStart23_DW.state == 1.0) {
          PendulumQuickStart23_DW.torqueval_e = -550.0;
          PendulumQuickStart23_DW.state = 2.0;
        } else if (PendulumQuickStart23_DW.counter == 150.0) {
          Compare = true;
          i = 0;
          exitg1 = false;
          while ((!exitg1) && (i < 10)) {
            if (!(PendulumQuickStart23_DW.precartArray[i] == rtb_Product)) {
              Compare = false;
              exitg1 = true;
            } else {
              i++;
            }
          }

          if (Compare) {
            PendulumQuickStart23_DW.torqueval_e = 0.0;
            PendulumQuickStart23_DW.homeval = 1.0;
            PendulumQuickStart23_DW.prepos = rtb_Product;
          } else {
            PendulumQuickStart23_DW.i++;
            PendulumQuickStart23_DW.precartArray[(int32_T)
              PendulumQuickStart23_DW.i - 1] = PendulumQuickStart23_DW.precart;
            if (PendulumQuickStart23_DW.i == 10.0) {
              PendulumQuickStart23_DW.i = 0.0;
            }

            PendulumQuickStart23_DW.precart = rtb_Product;
          }
        } else {
          PendulumQuickStart23_DW.counter++;
        }
      } else if (PendulumQuickStart23_P.Home_Value == 0.0) {
        PendulumQuickStart23_DW.state = 0.0;
        PendulumQuickStart23_DW.homeval = 0.0;
        PendulumQuickStart23_DW.counter = 0.0;
        PendulumQuickStart23_DW.prepos = 0.0;
      }
    }

    PendulumQuickStart23_B.homed = PendulumQuickStart23_DW.homeval;
    PendulumQuickStart23_B.torque = PendulumQuickStart23_DW.torqueval_e;
    if (PendulumQuickStart23_DW.homeval == 1.0) {
      PendulumQuickStart23_B.cartPos = (PendulumQuickStart23_DW.prepos - 329.0)
        - rtb_Product;
    } else {
      PendulumQuickStart23_B.cartPos = rtb_Product;
    }

    /* End of MATLAB Function: '<S1>/Homing Block' */

    /* DataTypeConversion: '<S26>/Data Type Conversion' */
    PendulumQuickStart23_B.DataTypeConversion = rod;
  }

  /* FromWorkspace: '<S12>/From Workspace' */
  {
    real_T *pDataValues = (real_T *)
      PendulumQuickStart23_DW.FromWorkspace_PWORK.DataPtr;

    {
      int_T elIdx;
      for (elIdx = 0; elIdx < 3; ++elIdx) {
        (&PendulumQuickStart23_B.FromWorkspace[0])[elIdx] = pDataValues[0];
        pDataValues += 1;
      }
    }
  }

  /* Product: '<S12>/Divide' incorporates:
   *  Constant: '<S12>/Constant'
   *  Sum: '<S12>/Subtract'
   */
  rtb_Product = (PendulumQuickStart23_B.FromWorkspace[0] -
                 PendulumQuickStart23_B.FromWorkspace[1]) /
    PendulumQuickStart23_P.Constant_Value_a;

  /* Product: '<S12>/Divide3' */
  PendulumQuickStart23_B.Divide3 = PendulumQuickStart23_B.DataTypeConversion /
    rtb_Product;

  /* If: '<S12>/If' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (rtsiIsModeUpdateTimeStep(&PendulumQuickStart23_M->solverInfo)) {
    rtAction = (int8_T)!(PendulumQuickStart23_B.FromWorkspace[2] <
                         PendulumQuickStart23_P.Constant1_Value_h);
    PendulumQuickStart23_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = PendulumQuickStart23_DW.If_ActiveSubsystem;
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* Merge: '<S12>/Merge' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Sum: '<S13>/Sum'
     */
    PendulumQuickStart23_B.Merge = PendulumQuickStart23_B.FromWorkspace[2] +
      PendulumQuickStart23_P.Constant1_Value_h;
    if (rtsiIsModeUpdateTimeStep(&PendulumQuickStart23_M->solverInfo)) {
      srUpdateBC(PendulumQuickStart23_DW.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* Merge: '<S12>/Merge' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Sum: '<S14>/Sum'
     */
    PendulumQuickStart23_B.Merge = PendulumQuickStart23_B.FromWorkspace[2] -
      PendulumQuickStart23_P.Constant1_Value_h;
    if (rtsiIsModeUpdateTimeStep(&PendulumQuickStart23_M->solverInfo)) {
      srUpdateBC(PendulumQuickStart23_DW.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem1' */
  }

  /* End of If: '<S12>/If' */

  /* Product: '<S12>/Divide1' incorporates:
   *  Constant: '<S12>/RodOffset'
   *  Sum: '<S12>/Sum'
   */
  PendulumQuickStart23_B.Divide1 = (PendulumQuickStart23_P.RodOffset_Value +
    PendulumQuickStart23_B.Merge) / rtb_Product;

  /* Sum: '<S12>/Subtract1' */
  PendulumQuickStart23_B.Subtract1 = PendulumQuickStart23_B.Divide3 -
    PendulumQuickStart23_B.Divide1;
  if (rtmIsMajorTimeStep(PendulumQuickStart23_M)) {
    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    rtb_Product = floor(PendulumQuickStart23_P.Constant1_Value_c);
    if (rtIsNaN(rtb_Product) || rtIsInf(rtb_Product)) {
      rtb_Product = 0.0;
    } else {
      rtb_Product = fmod(rtb_Product, 256.0);
    }

    /* DataTypeConversion: '<S7>/Data Type Conversion' */
    PendulumQuickStart23_B.DataTypeConversion_h = (uint8_T)(rtb_Product < 0.0 ?
      (int32_T)(uint8_T)-(int8_T)(uint8_T)-rtb_Product : (int32_T)(uint8_T)
      rtb_Product);

    /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
     *  Constant: '<S7>/Constant2'
     */
    rtb_Product = floor(PendulumQuickStart23_P.Constant2_Value);
    if (rtIsNaN(rtb_Product) || rtIsInf(rtb_Product)) {
      rtb_Product = 0.0;
    } else {
      rtb_Product = fmod(rtb_Product, 256.0);
    }

    /* DataTypeConversion: '<S7>/Data Type Conversion1' */
    PendulumQuickStart23_B.DataTypeConversion1 = (uint8_T)(rtb_Product < 0.0 ?
      (int32_T)(uint8_T)-(int8_T)(uint8_T)-rtb_Product : (int32_T)(uint8_T)
      rtb_Product);

    /* MATLAB Function: '<S1>/Move to Center' incorporates:
     *  Constant: '<S1>/Move Center'
     */
    if ((PendulumQuickStart23_B.homed == 1.0) &&
        (PendulumQuickStart23_P.MoveCenter_Value == 1.0)) {
      rtb_Product = PendulumQuickStart23_DW.set_pos -
        PendulumQuickStart23_B.cartPos;
      PendulumQuickStart23_B.torqueOut_b = rtb_Product *
        PendulumQuickStart23_DW.kp;
      if (fabs(rtb_Product) < 1.0) {
        PendulumQuickStart23_B.torqueOut_b = 0.0;
      }
    } else {
      PendulumQuickStart23_B.torqueOut_b = PendulumQuickStart23_B.torque;
    }

    PendulumQuickStart23_B.homedOut = PendulumQuickStart23_B.homed;

    /* End of MATLAB Function: '<S1>/Move to Center' */

    /* Gain: '<S5>/Gain' */
    PendulumQuickStart23_B.Gain = PendulumQuickStart23_P.Gain_Gain *
      PendulumQuickStart23_B.cartPos;

    /* Gain: '<S11>/Gain4' incorporates:
     *  Constant: '<S11>/Cart-Pos'
     */
    PendulumQuickStart23_B.Gain4 = PendulumQuickStart23_P.Gain4_Gain *
      PendulumQuickStart23_P.CartPos_Value;
  }

  /* DeadZone: '<S11>/Dead Zone' */
  if (PendulumQuickStart23_B.Subtract1 > PendulumQuickStart23_P.DeadZone_End) {
    /* DeadZone: '<S11>/Dead Zone' */
    PendulumQuickStart23_B.DeadZone = PendulumQuickStart23_B.Subtract1 -
      PendulumQuickStart23_P.DeadZone_End;
  } else if (PendulumQuickStart23_B.Subtract1 >=
             PendulumQuickStart23_P.DeadZone_Start) {
    /* DeadZone: '<S11>/Dead Zone' */
    PendulumQuickStart23_B.DeadZone = 0.0;
  } else {
    /* DeadZone: '<S11>/Dead Zone' */
    PendulumQuickStart23_B.DeadZone = PendulumQuickStart23_B.Subtract1 -
      PendulumQuickStart23_P.DeadZone_Start;
  }

  /* End of DeadZone: '<S11>/Dead Zone' */

  /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant2'
   *  Gain: '<S11>/Gain2'
   *  Gain: '<S11>/Gain3'
   *  Gain: '<S11>/Gain6'
   *  SignalConversion generated from: '<S16>/ SFunction '
   *  TransferFcn: '<S11>/2nd Order'
   *  TransferFcn: '<S11>/Transfer Fcn'
   */
  rtb_Product = PendulumQuickStart23_P.Nbar * PendulumQuickStart23_B.Gain4 *
    0.001 - (((PendulumQuickStart23_P.TransferFcn_C[0] *
               PendulumQuickStart23_X.TransferFcn_CSTATE[0] +
               PendulumQuickStart23_P.TransferFcn_C[1] *
               PendulumQuickStart23_X.TransferFcn_CSTATE[1]) *
              PendulumQuickStart23_P.Gain3_Gain * PendulumQuickStart23_P.K[2] +
              (PendulumQuickStart23_P.Gain2_Gain *
               PendulumQuickStart23_B.DeadZone * PendulumQuickStart23_P.K[1] +
               PendulumQuickStart23_P.K[0] * PendulumQuickStart23_B.Gain)) +
             (PendulumQuickStart23_P.undOrder_C[0] *
              PendulumQuickStart23_X.undOrder_CSTATE[0] +
              PendulumQuickStart23_P.undOrder_C[1] *
              PendulumQuickStart23_X.undOrder_CSTATE[1]) *
             PendulumQuickStart23_P.Gain6_Gain * PendulumQuickStart23_P.K[3]);

  /* Saturate: '<S11>/Saturation' */
  if (rtb_Product > PendulumQuickStart23_P.Saturation_UpperSat) {
    /* Saturate: '<S11>/Saturation' */
    PendulumQuickStart23_B.Saturation =
      PendulumQuickStart23_P.Saturation_UpperSat;
  } else if (rtb_Product < PendulumQuickStart23_P.Saturation_LowerSat) {
    /* Saturate: '<S11>/Saturation' */
    PendulumQuickStart23_B.Saturation =
      PendulumQuickStart23_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S11>/Saturation' */
    PendulumQuickStart23_B.Saturation = rtb_Product;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* TransferFcn: '<S11>/F//Volt' */
  rtb_Product = PendulumQuickStart23_P.FVolt_C *
    PendulumQuickStart23_X.FVolt_CSTATE + PendulumQuickStart23_P.FVolt_D *
    PendulumQuickStart23_B.Saturation;

  /* Saturate: '<S11>/Saturation1' */
  if (rtb_Product > PendulumQuickStart23_P.Saturation1_UpperSat) {
    /* Saturate: '<S11>/Saturation1' */
    PendulumQuickStart23_B.Saturation1 =
      PendulumQuickStart23_P.Saturation1_UpperSat;
  } else if (rtb_Product < PendulumQuickStart23_P.Saturation1_LowerSat) {
    /* Saturate: '<S11>/Saturation1' */
    PendulumQuickStart23_B.Saturation1 =
      PendulumQuickStart23_P.Saturation1_LowerSat;
  } else {
    /* Saturate: '<S11>/Saturation1' */
    PendulumQuickStart23_B.Saturation1 = rtb_Product;
  }

  /* End of Saturate: '<S11>/Saturation1' */

  /* Gain: '<S11>/Gain7' incorporates:
   *  Gain: '<S11>/Gain'
   */
  rtb_Product = PendulumQuickStart23_P.Gain_Gain_h *
    PendulumQuickStart23_B.Saturation1 * PendulumQuickStart23_P.Gain7_Gain;

  /* RelationalOperator: '<S15>/Compare' incorporates:
   *  Abs: '<S11>/Abs'
   *  Constant: '<S15>/Constant'
   */
  Compare = (fabs(rtb_Product) <= PendulumQuickStart23_P.CompareToConstant_const);
  if (rtmIsMajorTimeStep(PendulumQuickStart23_M)) {
    /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S18>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&PendulumQuickStart23_M->solverInfo)) {
      /* SignalConversion generated from: '<S18>/Enable' */
      PendulumQuickStart23_DW.EnabledSubsystem_MODE = Compare;
    }

    /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem' */
  }

  /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (PendulumQuickStart23_DW.EnabledSubsystem_MODE) {
    /* Merge: '<S17>/Merge' incorporates:
     *  Constant: '<S17>/Constant3'
     *  Product: '<S18>/Product'
     */
    PendulumQuickStart23_B.Merge_p = rtb_Product *
      PendulumQuickStart23_P.Constant3_Value;
    if (rtsiIsModeUpdateTimeStep(&PendulumQuickStart23_M->solverInfo)) {
      srUpdateBC(PendulumQuickStart23_DW.EnabledSubsystem_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem' */
  if (rtmIsMajorTimeStep(PendulumQuickStart23_M)) {
    /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S19>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&PendulumQuickStart23_M->solverInfo)) {
      /* Logic: '<S17>/NOT' */
      PendulumQuickStart23_DW.EnabledSubsystem1_MODE = !Compare;
    }

    /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem1' */
  }

  /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  if (PendulumQuickStart23_DW.EnabledSubsystem1_MODE) {
    /* Merge: '<S17>/Merge' incorporates:
     *  SignalConversion generated from: '<S19>/In1'
     */
    PendulumQuickStart23_B.Merge_p = rtb_Product;
    if (rtsiIsModeUpdateTimeStep(&PendulumQuickStart23_M->solverInfo)) {
      srUpdateBC(PendulumQuickStart23_DW.EnabledSubsystem1_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(PendulumQuickStart23_M)) {
    /* MATLAB Function: '<S1>/Selection' incorporates:
     *  Constant: '<S1>/Enable Control'
     *  Constant: '<S1>/Mode'
     *  Gain: '<S1>/Gain'
     *  Saturate: '<S5>/Saturation1'
     */
    if (PendulumQuickStart23_P.Mode_Value == 0.0) {
      PendulumQuickStart23_DW.torqueval = PendulumQuickStart23_B.torqueOut_b;
    }

    if ((PendulumQuickStart23_P.Mode_Value == 1.0) &&
        (PendulumQuickStart23_B.homedOut == 1.0)) {
      if (PendulumQuickStart23_P.EnableControl_Value == 1.0) {
        /* Saturate: '<S5>/Saturation1' */
        if (PendulumQuickStart23_B.Merge_p >
            PendulumQuickStart23_P.Saturation1_UpperSat_c) {
          rtb_Product = PendulumQuickStart23_P.Saturation1_UpperSat_c;
        } else if (PendulumQuickStart23_B.Merge_p <
                   PendulumQuickStart23_P.Saturation1_LowerSat_g) {
          rtb_Product = PendulumQuickStart23_P.Saturation1_LowerSat_g;
        } else {
          rtb_Product = PendulumQuickStart23_B.Merge_p;
        }

        PendulumQuickStart23_DW.torqueval = PendulumQuickStart23_P.Gain_Gain_o *
          rtb_Product;
      } else {
        PendulumQuickStart23_DW.torqueval = 0.0;
      }
    }

    PendulumQuickStart23_B.torqueOut = PendulumQuickStart23_DW.torqueval;

    /* End of MATLAB Function: '<S1>/Selection' */
  }

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Enable'
   *  Constant: '<S1>/Mode'
   */
  if (PendulumQuickStart23_P.Enable_Value == 1.0) {
    rtb_Product = 1.0;
    if (PendulumQuickStart23_P.Mode_Value == 0.0) {
      PendulumQuickStart23_B.PWMOut = PendulumQuickStart23_B.torqueOut;
    } else if ((fabs(PendulumQuickStart23_B.Subtract1) <= 30.0) && (fabs
                (PendulumQuickStart23_B.cartPos) <= 340.0)) {
      PendulumQuickStart23_B.PWMOut = PendulumQuickStart23_B.torqueOut;
    } else {
      rtb_Product = 0.0;
      PendulumQuickStart23_B.PWMOut = 0.0;
    }
  } else {
    rtb_Product = 0.0;
    PendulumQuickStart23_B.PWMOut = 0.0;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* DataTypeConversion: '<S7>/Data Type Conversion4' */
  i_0 = (int32_T)rtb_Product;

  /* Saturate: '<S7>/Saturation1' */
  if (PendulumQuickStart23_B.PWMOut >
      PendulumQuickStart23_P.Saturation1_UpperSat_a) {
    rtb_Product = PendulumQuickStart23_P.Saturation1_UpperSat_a;
  } else if (PendulumQuickStart23_B.PWMOut <
             PendulumQuickStart23_P.Saturation1_LowerSat_f) {
    rtb_Product = PendulumQuickStart23_P.Saturation1_LowerSat_f;
  } else {
    rtb_Product = PendulumQuickStart23_B.PWMOut;
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion7' incorporates:
   *  Saturate: '<S7>/Saturation1'
   */
  rtb_Product = floor(rtb_Product);
  if (rtIsNaN(rtb_Product) || rtIsInf(rtb_Product)) {
    rtb_Product = 0.0;
  } else {
    rtb_Product = fmod(rtb_Product, 65536.0);
  }

  rod = (int16_T)(rtb_Product < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
                  -rtb_Product : (int32_T)(int16_T)(uint16_T)rtb_Product);

  /* End of DataTypeConversion: '<S7>/Data Type Conversion7' */

  /* MATLAB Function: '<S7>/uint16_in1' */
  memcpy((void *)&t[0], (void *)&rod, (size_t)2 * sizeof(uint8_T));

  /* SignalConversion generated from: '<S20>/ SFunction ' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion4'
   *  MATLAB Function: '<S7>/MATLAB Function'
   *  MATLAB Function: '<S7>/uint16_in1'
   */
  rtb_TmpSignalConversionAtSFun_k[0] =
    PendulumQuickStart23_B.DataTypeConversion_h;
  rtb_TmpSignalConversionAtSFun_k[1] =
    PendulumQuickStart23_B.DataTypeConversion1;
  rtb_TmpSignalConversionAtSFun_k[2] = (uint8_T)i_0;
  rtb_TmpSignalConversionAtSFun_k[3] = t[0];
  rtb_TmpSignalConversionAtSFun_k[4] = t[1];

  /* MATLAB Function: '<S7>/MATLAB Function' */
  qY = MAX_uint32_T;
  for (i = 0; i < 5; i++) {
    qY ^= (uint32_T)rtb_TmpSignalConversionAtSFun_k[i] << 24;
    for (inc = 0; inc < 8; inc++) {
      loop_ub = (int32_T)(qY >> 31);
      qY <<= 1;
      if (loop_ub == 1) {
        qY ^= 79764919U;
      }
    }
  }

  /* MATLAB Function: '<S7>/uint32_in' incorporates:
   *  MATLAB Function: '<S7>/MATLAB Function'
   */
  memcpy((void *)&t_0[0], (void *)&qY, (size_t)4 * sizeof(uint8_T));

  /* SignalConversion generated from: '<S7>/Serial Write' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion4'
   *  MATLAB Function: '<S7>/uint16_in1'
   *  MATLAB Function: '<S7>/uint32_in'
   */
  rtb_TmpSignalConversionAtSerial[0] =
    PendulumQuickStart23_B.DataTypeConversion_h;
  rtb_TmpSignalConversionAtSerial[1] =
    PendulumQuickStart23_B.DataTypeConversion1;
  rtb_TmpSignalConversionAtSerial[2] = (uint8_T)i_0;
  rtb_TmpSignalConversionAtSerial[3] = t[0];
  rtb_TmpSignalConversionAtSerial[4] = t[1];
  rtb_TmpSignalConversionAtSerial[5] = t_0[0];
  rtb_TmpSignalConversionAtSerial[6] = t_0[1];
  rtb_TmpSignalConversionAtSerial[7] = t_0[2];
  rtb_TmpSignalConversionAtSerial[8] = t_0[3];

  /* MATLABSystem: '<S7>/Serial Write' */
  memcpy((void *)&TxDataLocChar[0], (void *)&rtb_TmpSignalConversionAtSerial[0],
         (size_t)9 * sizeof(uint8_T));
  MW_SCI_Transmit(PendulumQuickStart23_DW.obj_o.MW_SCIHANDLE, &TxDataLocChar[0],
                  9U);
  if (rtmIsMajorTimeStep(PendulumQuickStart23_M)) {
  }

  if (rtmIsMajorTimeStep(PendulumQuickStart23_M)) {
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        PendulumQuickStart23_M->Timing.t[0];

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(PendulumQuickStart23_M)) {/* Sample time: [0.004s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((PendulumQuickStart23_M->Timing.clockTick1) * 0.004);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(PendulumQuickStart23_M)) {
    rt_ertODEUpdateContinuousStates(&PendulumQuickStart23_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++PendulumQuickStart23_M->Timing.clockTick0;
    PendulumQuickStart23_M->Timing.t[0] = rtsiGetSolverStopTime
      (&PendulumQuickStart23_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.004s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.004, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PendulumQuickStart23_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void PendulumQuickStart23_derivatives(void)
{
  XDot_PendulumQuickStart23_T *_rtXdot;
  _rtXdot = ((XDot_PendulumQuickStart23_T *) PendulumQuickStart23_M->derivs);

  /* Derivatives for TransferFcn: '<S11>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = PendulumQuickStart23_P.TransferFcn_A[0] *
    PendulumQuickStart23_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += PendulumQuickStart23_P.TransferFcn_A[1] *
    PendulumQuickStart23_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] = PendulumQuickStart23_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += PendulumQuickStart23_B.Gain;

  /* Derivatives for TransferFcn: '<S11>/2nd Order' */
  _rtXdot->undOrder_CSTATE[0] = PendulumQuickStart23_P.undOrder_A[0] *
    PendulumQuickStart23_X.undOrder_CSTATE[0];
  _rtXdot->undOrder_CSTATE[0] += PendulumQuickStart23_P.undOrder_A[1] *
    PendulumQuickStart23_X.undOrder_CSTATE[1];
  _rtXdot->undOrder_CSTATE[1] = PendulumQuickStart23_X.undOrder_CSTATE[0];
  _rtXdot->undOrder_CSTATE[0] += PendulumQuickStart23_B.DeadZone;

  /* Derivatives for TransferFcn: '<S11>/F//Volt' */
  _rtXdot->FVolt_CSTATE = PendulumQuickStart23_P.FVolt_A *
    PendulumQuickStart23_X.FVolt_CSTATE;
  _rtXdot->FVolt_CSTATE += PendulumQuickStart23_B.Saturation;
}

/* Model initialize function */
void PendulumQuickStart23_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PendulumQuickStart23_M, 0,
                sizeof(RT_MODEL_PendulumQuickStart23_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PendulumQuickStart23_M->solverInfo,
                          &PendulumQuickStart23_M->Timing.simTimeStep);
    rtsiSetTPtr(&PendulumQuickStart23_M->solverInfo, &rtmGetTPtr
                (PendulumQuickStart23_M));
    rtsiSetStepSizePtr(&PendulumQuickStart23_M->solverInfo,
                       &PendulumQuickStart23_M->Timing.stepSize0);
    rtsiSetdXPtr(&PendulumQuickStart23_M->solverInfo,
                 &PendulumQuickStart23_M->derivs);
    rtsiSetContStatesPtr(&PendulumQuickStart23_M->solverInfo, (real_T **)
                         &PendulumQuickStart23_M->contStates);
    rtsiSetNumContStatesPtr(&PendulumQuickStart23_M->solverInfo,
      &PendulumQuickStart23_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PendulumQuickStart23_M->solverInfo,
      &PendulumQuickStart23_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PendulumQuickStart23_M->solverInfo,
      &PendulumQuickStart23_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PendulumQuickStart23_M->solverInfo,
      &PendulumQuickStart23_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&PendulumQuickStart23_M->solverInfo, (boolean_T**)
      &PendulumQuickStart23_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&PendulumQuickStart23_M->solverInfo,
                          (&rtmGetErrorStatus(PendulumQuickStart23_M)));
    rtsiSetRTModelPtr(&PendulumQuickStart23_M->solverInfo,
                      PendulumQuickStart23_M);
  }

  rtsiSetSimTimeStep(&PendulumQuickStart23_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&PendulumQuickStart23_M->solverInfo,
    false);
  PendulumQuickStart23_M->intgData.y = PendulumQuickStart23_M->odeY;
  PendulumQuickStart23_M->intgData.f[0] = PendulumQuickStart23_M->odeF[0];
  PendulumQuickStart23_M->intgData.f[1] = PendulumQuickStart23_M->odeF[1];
  PendulumQuickStart23_M->intgData.f[2] = PendulumQuickStart23_M->odeF[2];
  PendulumQuickStart23_M->intgData.f[3] = PendulumQuickStart23_M->odeF[3];
  PendulumQuickStart23_M->contStates = ((X_PendulumQuickStart23_T *)
    &PendulumQuickStart23_X);
  PendulumQuickStart23_M->contStateDisabled = ((XDis_PendulumQuickStart23_T *)
    &PendulumQuickStart23_XDis);
  PendulumQuickStart23_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&PendulumQuickStart23_M->solverInfo, (void *)
                    &PendulumQuickStart23_M->intgData);
  rtsiSetSolverName(&PendulumQuickStart23_M->solverInfo,"ode4");
  rtmSetTPtr(PendulumQuickStart23_M, &PendulumQuickStart23_M->Timing.tArray[0]);
  rtmSetTFinal(PendulumQuickStart23_M, -1);
  PendulumQuickStart23_M->Timing.stepSize0 = 0.004;

  /* External mode info */
  PendulumQuickStart23_M->Sizes.checksums[0] = (76800025U);
  PendulumQuickStart23_M->Sizes.checksums[1] = (549421819U);
  PendulumQuickStart23_M->Sizes.checksums[2] = (3168471329U);
  PendulumQuickStart23_M->Sizes.checksums[3] = (3874333471U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[19];
    PendulumQuickStart23_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &PendulumQuickStart23_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &PendulumQuickStart23_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)
      &PendulumQuickStart23_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &PendulumQuickStart23_DW.EnabledSubsystem1_SubsysRanBC;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PendulumQuickStart23_M->extModeInfo,
      &PendulumQuickStart23_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PendulumQuickStart23_M->extModeInfo,
                        PendulumQuickStart23_M->Sizes.checksums);
    rteiSetTPtr(PendulumQuickStart23_M->extModeInfo, rtmGetTPtr
                (PendulumQuickStart23_M));
  }

  /* block I/O */
  (void) memset(((void *) &PendulumQuickStart23_B), 0,
                sizeof(B_PendulumQuickStart23_T));

  /* states (continuous) */
  {
    (void) memset((void *)&PendulumQuickStart23_X, 0,
                  sizeof(X_PendulumQuickStart23_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&PendulumQuickStart23_XDis, 0,
                  sizeof(XDis_PendulumQuickStart23_T));
  }

  /* states (dwork) */
  (void) memset((void *)&PendulumQuickStart23_DW, 0,
                sizeof(DW_PendulumQuickStart23_T));

  /* Start for FromWorkspace: '<S12>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0 } ;

    static real_T pDataValues0[] = { 4095.0, 7.0, 4094.0 } ;

    PendulumQuickStart23_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    PendulumQuickStart23_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    PendulumQuickStart23_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for If: '<S12>/If' */
  PendulumQuickStart23_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn' */
  PendulumQuickStart23_X.TransferFcn_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S11>/2nd Order' */
  PendulumQuickStart23_X.undOrder_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn' */
  PendulumQuickStart23_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S11>/2nd Order' */
  PendulumQuickStart23_X.undOrder_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S11>/F//Volt' */
  PendulumQuickStart23_X.FVolt_CSTATE = 0.0;
  PendulumQuickStart23_DW.bff.size = 0;

  /* SystemInitialize for MATLAB Function: '<S9>/MATLAB Function1' */
  PendulumQuickStart23_DW.val_not_empty = false;
  PendulumQuickStart23_DW.bff_not_empty = false;
  PendulumQuickStart23_DW.val = 0.0;

  /* SystemInitialize for MATLAB Function: '<S9>/MATLAB Function3' */
  PendulumQuickStart23_DW.validpack_not_empty = false;
  PendulumQuickStart23_DW.validpack2_not_empty = false;

  /* SystemInitialize for MATLAB Function: '<S1>/Homing Block' */
  PendulumQuickStart23_DW.torqueval_e = 0.0;
  PendulumQuickStart23_DW.state = 0.0;
  memset(&PendulumQuickStart23_DW.precartArray[0], 0, 10U * sizeof(real_T));
  PendulumQuickStart23_DW.homeval = 0.0;
  PendulumQuickStart23_DW.counter = 0.0;
  PendulumQuickStart23_DW.i = 0.0;
  PendulumQuickStart23_DW.precart = 0.0;
  PendulumQuickStart23_DW.prepos = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/Move to Center' */
  PendulumQuickStart23_DW.set_pos = 0.0;
  PendulumQuickStart23_DW.kp = 4.0;

  /* SystemInitialize for MATLAB Function: '<S1>/Selection' */
  PendulumQuickStart23_DW.torqueval = 0.0;

  /* Start for MATLABSystem: '<S9>/Serial Read' */
  PendulumQuickStart23_DW.obj.isInitialized = 0;
  PendulumQuickStart23_DW.obj.matlabCodegenIsDeleted = false;
  PendulumQuickStart23_DW.obj.SampleTime =
    PendulumQuickStart23_P.SerialRead_SampleTime;
  PendulumQuic_SystemCore_setup_a(&PendulumQuickStart23_DW.obj);

  /* Start for MATLABSystem: '<S7>/Serial Write' */
  PendulumQuickStart23_DW.obj_o.isInitialized = 0;
  PendulumQuickStart23_DW.obj_o.matlabCodegenIsDeleted = false;
  PendulumQuickS_SystemCore_setup(&PendulumQuickStart23_DW.obj_o);
}

/* Model terminate function */
void PendulumQuickStart23_terminate(void)
{
  /* Terminate for MATLABSystem: '<S9>/Serial Read' */
  if (!PendulumQuickStart23_DW.obj.matlabCodegenIsDeleted) {
    PendulumQuickStart23_DW.obj.matlabCodegenIsDeleted = true;
    if ((PendulumQuickStart23_DW.obj.isInitialized == 1) &&
        PendulumQuickStart23_DW.obj.isSetupComplete) {
      MW_SCI_Close(PendulumQuickStart23_DW.obj.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/Serial Read' */
  /* Terminate for MATLABSystem: '<S7>/Serial Write' */
  if (!PendulumQuickStart23_DW.obj_o.matlabCodegenIsDeleted) {
    PendulumQuickStart23_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PendulumQuickStart23_DW.obj_o.isInitialized == 1) &&
        PendulumQuickStart23_DW.obj_o.isSetupComplete) {
      MW_SCI_Close(PendulumQuickStart23_DW.obj_o.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Serial Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
