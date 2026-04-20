/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PendulumQuickStart.c
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

#include "PendulumQuickStart.h"
#include "PendulumQuickStart_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "PendulumQuickStart_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stddef.h>

/* Block signals (default storage) */
B_PendulumQuickStart_T PendulumQuickStart_B;

/* Continuous states */
X_PendulumQuickStart_T PendulumQuickStart_X;

/* Disabled State Vector */
XDis_PendulumQuickStart_T PendulumQuickStart_XDis;

/* Block states (default storage) */
DW_PendulumQuickStart_T PendulumQuickStart_DW;

/* Real-time model */
static RT_MODEL_PendulumQuickStart_T PendulumQuickStart_M_;
RT_MODEL_PendulumQuickStart_T *const PendulumQuickStart_M =
  &PendulumQuickStart_M_;

/* Forward declaration for local functions */
static void PendulumQuickStart_eml_find(const boolean_T x_data[], const int32_T *
  x_size, int32_T i_data[], int32_T *i_size);
static void PendulumQuickS_SystemCore_setup(codertarget_raspi_internal__a_T *obj);
static void PendulumQuic_SCIWrite_setupImpl(codertarget_raspi_internal_SC_T *obj);

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
  PendulumQuickStart_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  PendulumQuickStart_step();
  PendulumQuickStart_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  PendulumQuickStart_step();
  PendulumQuickStart_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  PendulumQuickStart_step();
  PendulumQuickStart_derivatives();

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
static void PendulumQuickStart_eml_find(const boolean_T x_data[], const int32_T *
  x_size, int32_T i_data[], int32_T *i_size)
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

static void PendulumQuickS_SystemCore_setup(codertarget_raspi_internal__a_T *obj)
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

static void PendulumQuic_SCIWrite_setupImpl(codertarget_raspi_internal_SC_T *obj)
{
  void* SCIModuleVoidPtr;
  int32_T i;
  char_T b_SCIModuleLoc[13];
  static const char_T b_SCIModuleLoc_0[13] = "/dev/serial0";
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
}

/* Model step function */
void PendulumQuickStart_step(void)
{
  real_T rtb_Product;
  real_T rtb_homedOut;
  real_T rtb_torque;
  real_T rtb_torqueOut;
  int32_T tmp_data_0[255];
  int32_T i;
  int32_T i_0;
  int32_T inc;
  int32_T loop_ub;
  uint32_T qY;
  uint32_T rtb_crc;
  int16_T rtb_cart;
  int16_T rtb_rod;
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T head_data[255];
  uint8_T RxDataLocChar[10];
  uint8_T rtb_SerialRead_o1_0[10];
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
  boolean_T tmp;
  boolean_T y;
  if (rtmIsMajorTimeStep(PendulumQuickStart_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&PendulumQuickStart_M->solverInfo,
                          ((PendulumQuickStart_M->Timing.clockTick0+1)*
      PendulumQuickStart_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PendulumQuickStart_M)) {
    PendulumQuickStart_M->Timing.t[0] = rtsiGetT
      (&PendulumQuickStart_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(PendulumQuickStart_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PendulumQuickStart_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PendulumQuickStart_DW.EnabledSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PendulumQuickStart_DW.EnabledSubsystem1_SubsysRanBC);
  tmp = rtmIsMajorTimeStep(PendulumQuickStart_M);
  if (tmp) {
    /* MATLABSystem: '<S9>/Serial Read' */
    status = MW_SCI_Receive(PendulumQuickStart_DW.obj_o.MW_SCIHANDLE,
      &RxDataLocChar[0], 10U);
    memcpy((void *)&rtb_SerialRead_o1_0[0], (void *)&RxDataLocChar[0], (uint32_T)
           ((size_t)10 * sizeof(uint8_T)));

    /* MATLAB Function: '<S9>/MATLAB Function1' incorporates:
     *  Constant: '<S9>/Buffer Size'
     *  Constant: '<S9>/Constant1'
     *  Constant: '<S9>/Constant4'
     *  MATLABSystem: '<S9>/Serial Read'
     * */
    if (!PendulumQuickStart_DW.bff_not_empty) {
      for (i = 0; i < 10; i++) {
        PendulumQuickStart_DW.packetindex[i] = 0U;
      }
    }

    if (!PendulumQuickStart_DW.val_not_empty) {
      PendulumQuickStart_DW.val_not_empty = true;
      PendulumQuickStart_DW.bff.size = PendulumQuickStart_P.BufferSize_Value;
      loop_ub = PendulumQuickStart_P.BufferSize_Value;
      if (loop_ub - 1 >= 0) {
        memset(&PendulumQuickStart_DW.bff.data[0], 0, (uint32_T)loop_ub * sizeof
               (real_T));
      }

      PendulumQuickStart_DW.bff_not_empty = (PendulumQuickStart_DW.bff.size != 0);
      inc = 0;
    } else {
      inc = 1;
    }

    rtb_Product = rt_roundd_snf(PendulumQuickStart_DW.val - 1.0);
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        xi = (uint8_T)rtb_Product;
      } else {
        xi = 0U;
      }
    } else {
      xi = MAX_uint8_T;
    }

    if (PendulumQuickStart_DW.val - 1.0 == xi) {
      if (PendulumQuickStart_P.BufferSize_Value != 0) {
        xi -= (uint8_T)((uint8_T)((uint32_T)xi /
          PendulumQuickStart_P.BufferSize_Value) *
                        PendulumQuickStart_P.BufferSize_Value);
      }
    } else {
      if (PendulumQuickStart_P.BufferSize_Value == 0) {
        rtb_torque = PendulumQuickStart_DW.val - 1.0;
        if (PendulumQuickStart_DW.val - 1.0 == 0.0) {
          rtb_torque = 0.0;
        }
      } else if (rtIsInf(PendulumQuickStart_DW.val - 1.0)) {
        rtb_torque = (rtNaN);
      } else {
        rtb_torque = fmod(PendulumQuickStart_DW.val - 1.0,
                          PendulumQuickStart_P.BufferSize_Value);
        if (rtb_torque == 0.0) {
          rtb_torque = 0.0;
        } else if (rtb_torque < 0.0) {
          rtb_torque = (real_T)PendulumQuickStart_P.BufferSize_Value - 1.0;
        }
      }

      rtb_Product = rt_roundd_snf(rtb_torque);
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

    qY = xi + 1U;
    if (xi + 1U > 255U) {
      qY = 255U;
    }

    if (!PendulumQuickStart_DW.bff_not_empty) {
      PendulumQuickStart_DW.bff.size = PendulumQuickStart_P.BufferSize_Value;
      loop_ub = PendulumQuickStart_P.BufferSize_Value;
      if (loop_ub - 1 >= 0) {
        memset(&PendulumQuickStart_DW.bff.data[0], 0, (uint32_T)loop_ub * sizeof
               (real_T));
      }

      PendulumQuickStart_DW.bff_not_empty = (PendulumQuickStart_DW.bff.size != 0);
    }

    if (status == 0) {
      for (i = 0; i < 10; i++) {
        i_0 = (uint8_T)qY + i;
        if (i_0 > 255) {
          i_0 = 255;
        }

        status = (uint8_T)(i_0 - 1);
        if (PendulumQuickStart_P.BufferSize_Value != 0) {
          status = (uint8_T)((uint8_T)(i_0 - 1) - (uint8_T)((uint8_T)((uint32_T)
            (uint8_T)(i_0 - 1) / PendulumQuickStart_P.BufferSize_Value) *
            PendulumQuickStart_P.BufferSize_Value));
        }

        rtb_crc = status + 1U;
        if (status + 1U > 255U) {
          rtb_crc = 255U;
        }

        PendulumQuickStart_DW.bff.data[(int32_T)rtb_crc - 1] =
          rtb_SerialRead_o1_0[i];
      }

      if (inc == 1) {
        PendulumQuickStart_DW.val += 10.0;
      }
    }

    rtb_crc = (uint8_T)qY + 1U;
    if ((uint8_T)qY + 1U > 255U) {
      rtb_crc = 255U;
    }

    if ((uint8_T)rtb_crc > PendulumQuickStart_DW.bff.size) {
      i = 0;
      inc = 0;
    } else {
      i = (uint8_T)rtb_crc - 1;
      inc = PendulumQuickStart_DW.bff.size;
    }

    loop_ub = inc - i;
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      tmp_data[i_0] = (PendulumQuickStart_DW.bff.data[i + i_0] ==
                       PendulumQuickStart_P.Constant4_Value);
    }

    PendulumQuickStart_eml_find(tmp_data, &loop_ub, tmp_data_0, &inc);
    for (i_0 = 0; i_0 < inc; i_0++) {
      rtb_Product = (real_T)tmp_data_0[i_0] + (real_T)(uint8_T)qY;
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          head_data[i_0] = (uint8_T)rtb_Product;
        } else {
          head_data[i_0] = 0U;
        }
      } else {
        head_data[i_0] = MAX_uint8_T;
      }
    }

    if (inc == 0) {
      i = PendulumQuickStart_DW.bff.size;
      loop_ub = PendulumQuickStart_DW.bff.size;
      for (i_0 = 0; i_0 < loop_ub; i_0++) {
        tmp_data[i_0] = (PendulumQuickStart_DW.bff.data[i_0] ==
                         PendulumQuickStart_P.Constant4_Value);
      }

      PendulumQuickStart_eml_find(tmp_data, &i, tmp_data_0, &inc);
      for (i_0 = 0; i_0 < inc; i_0++) {
        i = tmp_data_0[i_0];
        if (i < 0) {
          i = 0;
        } else if (i > 255) {
          i = 255;
        }

        head_data[i_0] = (uint8_T)i;
      }
    }

    if (PendulumQuickStart_P.BufferSize_Value == 0) {
      xi = head_data[0];
    } else {
      xi = (uint8_T)(head_data[0] - (uint8_T)((uint8_T)((uint32_T)head_data[0] /
        PendulumQuickStart_P.BufferSize_Value) *
        PendulumQuickStart_P.BufferSize_Value));
    }

    qY = xi + 1U;
    if (xi + 1U > 255U) {
      qY = 255U;
    }

    if (PendulumQuickStart_DW.bff.data[(int32_T)qY - 1] ==
        PendulumQuickStart_P.Constant1_Value_h5) {
      qY = head_data[0] -
        /*MW:operator MISRA2012:D4.1 CERT-C:INT30-C 'Justifying MISRA C rule violation'*/
        /*MW:OvSatOk*/ 1U;
      if (head_data[0] - 1U > head_data[0]) {
        qY = 0U;
      }

      xi = (uint8_T)qY;
      if (PendulumQuickStart_P.BufferSize_Value == 0) {
        status = head_data[0];
      } else {
        xi = (uint8_T)((uint8_T)qY - (uint8_T)((uint8_T)((uint32_T)(uint8_T)qY /
          PendulumQuickStart_P.BufferSize_Value) *
          PendulumQuickStart_P.BufferSize_Value));
        status = (uint8_T)(head_data[0] - (uint8_T)((uint8_T)((uint32_T)
          head_data[0] / PendulumQuickStart_P.BufferSize_Value) *
          PendulumQuickStart_P.BufferSize_Value));
      }

      qY = head_data[0] + 1U;
      if (head_data[0] + 1U > 255U) {
        qY = 255U;
      }

      c_x = (uint8_T)qY;
      if (PendulumQuickStart_P.BufferSize_Value != 0) {
        c_x = (uint8_T)((uint8_T)qY - (uint8_T)((uint8_T)((uint32_T)(uint8_T)qY /
          PendulumQuickStart_P.BufferSize_Value) *
          PendulumQuickStart_P.BufferSize_Value));
      }

      qY = head_data[0] + 2U;
      if (head_data[0] + 2U > 255U) {
        qY = 255U;
      }

      d_x = (uint8_T)qY;
      if (PendulumQuickStart_P.BufferSize_Value != 0) {
        d_x = (uint8_T)((uint8_T)qY - (uint8_T)((uint8_T)((uint32_T)(uint8_T)qY /
          PendulumQuickStart_P.BufferSize_Value) *
          PendulumQuickStart_P.BufferSize_Value));
      }

      qY = head_data[0] + 3U;
      if (head_data[0] + 3U > 255U) {
        qY = 255U;
      }

      e_x = (uint8_T)qY;
      if (PendulumQuickStart_P.BufferSize_Value != 0) {
        e_x = (uint8_T)((uint8_T)qY - (uint8_T)((uint8_T)((uint32_T)(uint8_T)qY /
          PendulumQuickStart_P.BufferSize_Value) *
          PendulumQuickStart_P.BufferSize_Value));
      }

      qY = head_data[0] + 4U;
      if (head_data[0] + 4U > 255U) {
        qY = 255U;
      }

      f_x = (uint8_T)qY;
      if (PendulumQuickStart_P.BufferSize_Value != 0) {
        f_x = (uint8_T)((uint8_T)qY - (uint8_T)((uint8_T)((uint32_T)(uint8_T)qY /
          PendulumQuickStart_P.BufferSize_Value) *
          PendulumQuickStart_P.BufferSize_Value));
      }

      qY = head_data[0] + 5U;
      if (head_data[0] + 5U > 255U) {
        qY = 255U;
      }

      g_x = (uint8_T)qY;
      if (PendulumQuickStart_P.BufferSize_Value != 0) {
        g_x = (uint8_T)((uint8_T)qY - (uint8_T)((uint8_T)((uint32_T)(uint8_T)qY /
          PendulumQuickStart_P.BufferSize_Value) *
          PendulumQuickStart_P.BufferSize_Value));
      }

      qY = head_data[0] + 6U;
      if (head_data[0] + 6U > 255U) {
        qY = 255U;
      }

      h_x = (uint8_T)qY;
      if (PendulumQuickStart_P.BufferSize_Value != 0) {
        h_x = (uint8_T)((uint8_T)qY - (uint8_T)((uint8_T)((uint32_T)(uint8_T)qY /
          PendulumQuickStart_P.BufferSize_Value) *
          PendulumQuickStart_P.BufferSize_Value));
      }

      qY = head_data[0] + 7U;
      if (head_data[0] + 7U > 255U) {
        qY = 255U;
      }

      i_x = (uint8_T)qY;
      if (PendulumQuickStart_P.BufferSize_Value != 0) {
        i_x = (uint8_T)((uint8_T)qY - (uint8_T)((uint8_T)((uint32_T)(uint8_T)qY /
          PendulumQuickStart_P.BufferSize_Value) *
          PendulumQuickStart_P.BufferSize_Value));
      }

      qY = head_data[0] + 8U;
      if (head_data[0] + 8U > 255U) {
        qY = 255U;
      }

      j_x = (uint8_T)qY;
      if (PendulumQuickStart_P.BufferSize_Value != 0) {
        j_x = (uint8_T)((uint8_T)qY - (uint8_T)((uint8_T)((uint32_T)(uint8_T)qY /
          PendulumQuickStart_P.BufferSize_Value) *
          PendulumQuickStart_P.BufferSize_Value));
      }

      qY = xi + 1U;
      if (xi + 1U > 255U) {
        qY = 255U;
      }

      PendulumQuickStart_DW.packetindex[0] = (uint8_T)qY;
      qY = status + 1U;
      if (status + 1U > 255U) {
        qY = 255U;
      }

      PendulumQuickStart_DW.packetindex[1] = (uint8_T)qY;
      qY = c_x + 1U;
      if (c_x + 1U > 255U) {
        qY = 255U;
      }

      PendulumQuickStart_DW.packetindex[2] = (uint8_T)qY;
      qY = d_x + 1U;
      if (d_x + 1U > 255U) {
        qY = 255U;
      }

      PendulumQuickStart_DW.packetindex[3] = (uint8_T)qY;
      qY = e_x + 1U;
      if (e_x + 1U > 255U) {
        qY = 255U;
      }

      PendulumQuickStart_DW.packetindex[4] = (uint8_T)qY;
      qY = f_x + 1U;
      if (f_x + 1U > 255U) {
        qY = 255U;
      }

      PendulumQuickStart_DW.packetindex[5] = (uint8_T)qY;
      qY = g_x + 1U;
      if (g_x + 1U > 255U) {
        qY = 255U;
      }

      PendulumQuickStart_DW.packetindex[6] = (uint8_T)qY;
      qY = h_x + 1U;
      if (h_x + 1U > 255U) {
        qY = 255U;
      }

      PendulumQuickStart_DW.packetindex[7] = (uint8_T)qY;
      qY = i_x + 1U;
      if (i_x + 1U > 255U) {
        qY = 255U;
      }

      PendulumQuickStart_DW.packetindex[8] = (uint8_T)qY;
      qY = j_x + 1U;
      if (j_x + 1U > 255U) {
        qY = 255U;
      }

      PendulumQuickStart_DW.packetindex[9] = (uint8_T)qY;
    }

    for (i_0 = 0; i_0 < 10; i_0++) {
      PendulumQuickStart_B.packet[i_0] =
        PendulumQuickStart_DW.bff.data[PendulumQuickStart_DW.packetindex[i_0] -
        1];
    }

    /* End of MATLAB Function: '<S9>/MATLAB Function1' */

    /* MATLAB Function: '<S9>/MATLAB Function2' */
    PendulumQuickStart_B.crc = MAX_uint32_T;
    for (i = 0; i < 6; i++) {
      rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[i]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          status = (uint8_T)rtb_Product;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      PendulumQuickStart_B.crc ^= (uint32_T)status << 24;
      for (inc = 0; inc < 8; inc++) {
        qY = PendulumQuickStart_B.crc >> 31;
        PendulumQuickStart_B.crc <<= 1;
        if (qY == 1U) {
          PendulumQuickStart_B.crc ^= 79764919U;
        }
      }
    }

    /* End of MATLAB Function: '<S9>/MATLAB Function2' */

    /* MATLAB Function: '<S9>/uint32_in2' */
    rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[6]);
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        t_0[0] = (uint8_T)rtb_Product;
      } else {
        t_0[0] = 0U;
      }
    } else {
      t_0[0] = MAX_uint8_T;
    }

    rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[7]);
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        t_0[1] = (uint8_T)rtb_Product;
      } else {
        t_0[1] = 0U;
      }
    } else {
      t_0[1] = MAX_uint8_T;
    }

    rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[8]);
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        t_0[2] = (uint8_T)rtb_Product;
      } else {
        t_0[2] = 0U;
      }
    } else {
      t_0[2] = MAX_uint8_T;
    }

    rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[9]);
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        t_0[3] = (uint8_T)rtb_Product;
      } else {
        t_0[3] = 0U;
      }
    } else {
      t_0[3] = MAX_uint8_T;
    }

    memcpy((void *)&PendulumQuickStart_B.y, (void *)&t_0[0], (uint32_T)((size_t)
            1 * sizeof(uint32_T)));

    /* End of MATLAB Function: '<S9>/uint32_in2' */

    /* MATLAB Function: '<S9>/MATLAB Function3' */
    if (!PendulumQuickStart_DW.validpack_not_empty) {
      rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[2]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[0] = (uint8_T)rtb_Product;
        } else {
          t[0] = 0U;
        }
      } else {
        t[0] = MAX_uint8_T;
      }

      rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[3]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[1] = (uint8_T)rtb_Product;
        } else {
          t[1] = 0U;
        }
      } else {
        t[1] = MAX_uint8_T;
      }

      memcpy((void *)&PendulumQuickStart_DW.validpack, (void *)&t[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
      PendulumQuickStart_DW.validpack_not_empty = true;
    }

    if (!PendulumQuickStart_DW.validpack2_not_empty) {
      rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[4]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[0] = (uint8_T)rtb_Product;
        } else {
          t[0] = 0U;
        }
      } else {
        t[0] = MAX_uint8_T;
      }

      rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[5]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[1] = (uint8_T)rtb_Product;
        } else {
          t[1] = 0U;
        }
      } else {
        t[1] = MAX_uint8_T;
      }

      memcpy((void *)&PendulumQuickStart_DW.validpack2, (void *)&t[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
      PendulumQuickStart_DW.validpack2_not_empty = true;
    }

    if (PendulumQuickStart_B.crc == PendulumQuickStart_B.y) {
      rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[2]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[0] = (uint8_T)rtb_Product;
        } else {
          t[0] = 0U;
        }
      } else {
        t[0] = MAX_uint8_T;
      }

      rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[3]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[1] = (uint8_T)rtb_Product;
        } else {
          t[1] = 0U;
        }
      } else {
        t[1] = MAX_uint8_T;
      }

      memcpy((void *)&PendulumQuickStart_DW.validpack, (void *)&t[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
      rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[4]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[0] = (uint8_T)rtb_Product;
        } else {
          t[0] = 0U;
        }
      } else {
        t[0] = MAX_uint8_T;
      }

      rtb_Product = rt_roundd_snf(PendulumQuickStart_B.packet[5]);
      if (rtb_Product < 256.0) {
        if (rtb_Product >= 0.0) {
          t[1] = (uint8_T)rtb_Product;
        } else {
          t[1] = 0U;
        }
      } else {
        t[1] = MAX_uint8_T;
      }

      memcpy((void *)&PendulumQuickStart_DW.validpack2, (void *)&t[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
      rtb_rod = PendulumQuickStart_DW.validpack;
      rtb_cart = PendulumQuickStart_DW.validpack2;
    } else {
      rtb_rod = PendulumQuickStart_DW.validpack;
      rtb_cart = PendulumQuickStart_DW.validpack2;
    }

    /* End of MATLAB Function: '<S9>/MATLAB Function3' */

    /* Product: '<S8>/Product' incorporates:
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/Constant1'
     *  DataTypeConversion: '<S26>/Data Type Conversion2'
     *  Product: '<S8>/Divide'
     */
    rtb_Product = (real_T)rtb_cart / PendulumQuickStart_P.Constant_Value *
      PendulumQuickStart_P.Constant1_Value;

    /* MATLAB Function: '<S1>/Homing Block' incorporates:
     *  Constant: '<S1>/Home'
     *  Constant: '<S1>/Mode'
     */
    if (PendulumQuickStart_P.Mode_Value == 0.0) {
      if (PendulumQuickStart_DW.homeval == 0.0) {
        if (PendulumQuickStart_P.Home_Value == 0.0) {
          PendulumQuickStart_DW.state = 0.0;
          PendulumQuickStart_DW.homeval = 0.0;
          PendulumQuickStart_DW.counter = 0.0;
          PendulumQuickStart_DW.precart = 0.0;
          PendulumQuickStart_DW.prepos = 0.0;
          memset(&PendulumQuickStart_DW.precartArray[0], 0, 10U * sizeof(real_T));
        }

        if (PendulumQuickStart_DW.state == 0.0) {
          PendulumQuickStart_DW.torqueval_d = 0.0;
          if (PendulumQuickStart_P.Home_Value == 1.0) {
            PendulumQuickStart_DW.state = 1.0;
          }
        } else if (PendulumQuickStart_DW.state == 1.0) {
          PendulumQuickStart_DW.torqueval_d = -550.0;
          PendulumQuickStart_DW.state = 2.0;
        } else if (PendulumQuickStart_DW.counter == 150.0) {
          y = true;
          i = 0;
          exitg1 = false;
          while ((!exitg1) && (i < 10)) {
            if (!(PendulumQuickStart_DW.precartArray[i] == rtb_Product)) {
              y = false;
              exitg1 = true;
            } else {
              i++;
            }
          }

          if (y) {
            PendulumQuickStart_DW.torqueval_d = 0.0;
            PendulumQuickStart_DW.homeval = 1.0;
            PendulumQuickStart_DW.prepos = rtb_Product;
          } else {
            PendulumQuickStart_DW.i++;
            PendulumQuickStart_DW.precartArray[(int32_T)PendulumQuickStart_DW.i
              - 1] = PendulumQuickStart_DW.precart;
            if (PendulumQuickStart_DW.i == 10.0) {
              PendulumQuickStart_DW.i = 0.0;
            }

            PendulumQuickStart_DW.precart = rtb_Product;
          }
        } else {
          PendulumQuickStart_DW.counter++;
        }
      } else if (PendulumQuickStart_P.Home_Value == 0.0) {
        PendulumQuickStart_DW.state = 0.0;
        PendulumQuickStart_DW.homeval = 0.0;
        PendulumQuickStart_DW.counter = 0.0;
        PendulumQuickStart_DW.prepos = 0.0;
      }
    }

    PendulumQuickStart_B.homed = PendulumQuickStart_DW.homeval;
    rtb_torque = PendulumQuickStart_DW.torqueval_d;
    if (PendulumQuickStart_DW.homeval == 1.0) {
      PendulumQuickStart_B.cartPos = (PendulumQuickStart_DW.prepos - 329.0) -
        rtb_Product;
    } else {
      PendulumQuickStart_B.cartPos = rtb_Product;
    }

    /* End of MATLAB Function: '<S1>/Homing Block' */

    /* DataTypeConversion: '<S26>/Data Type Conversion' */
    PendulumQuickStart_B.DataTypeConversion = rtb_rod;
  }

  /* FromWorkspace: '<S12>/From Workspace' */
  {
    real_T *pDataValues = (real_T *)
      PendulumQuickStart_DW.FromWorkspace_PWORK.DataPtr;

    {
      int_T elIdx;
      for (elIdx = 0; elIdx < 3; ++elIdx) {
        (PendulumQuickStart_B.FromWorkspace)[elIdx] = pDataValues[0];
        pDataValues += 1;
      }
    }
  }

  /* Product: '<S12>/Divide' incorporates:
   *  Constant: '<S12>/Constant'
   *  Sum: '<S12>/Subtract'
   */
  rtb_Product = (PendulumQuickStart_B.FromWorkspace[0] -
                 PendulumQuickStart_B.FromWorkspace[1]) /
    PendulumQuickStart_P.Constant_Value_a;

  /* Product: '<S12>/Divide3' */
  PendulumQuickStart_B.Divide3 = PendulumQuickStart_B.DataTypeConversion /
    rtb_Product;

  /* If: '<S12>/If' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  rtPrevAction = PendulumQuickStart_DW.If_ActiveSubsystem;

  /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
   *  ActionPort: '<S13>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S14>/Action Port'
   */
  y = rtsiIsModeUpdateTimeStep(&PendulumQuickStart_M->solverInfo);

  /* End of Outputs for SubSystem: '<S12>/If Action Subsystem1' */
  /* End of Outputs for SubSystem: '<S12>/If Action Subsystem' */
  /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem1' */
  if (y) {
    rtAction = (int8_T)!(PendulumQuickStart_B.FromWorkspace[2] <
                         PendulumQuickStart_P.Constant1_Value_h);
    PendulumQuickStart_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = PendulumQuickStart_DW.If_ActiveSubsystem;
  }

  if (rtPrevAction != rtAction) {
    rtsiSetBlockStateForSolverChangedAtMajorStep
      (&PendulumQuickStart_M->solverInfo, true);
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* Merge: '<S12>/Merge' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Sum: '<S13>/Sum'
     */
    PendulumQuickStart_B.Merge = PendulumQuickStart_B.FromWorkspace[2] +
      PendulumQuickStart_P.Constant1_Value_h;
    if (y) {
      srUpdateBC(PendulumQuickStart_DW.IfActionSubsystem_SubsysRanBC);
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
    PendulumQuickStart_B.Merge = PendulumQuickStart_B.FromWorkspace[2] -
      PendulumQuickStart_P.Constant1_Value_h;
    if (y) {
      srUpdateBC(PendulumQuickStart_DW.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem1' */
  }

  /* End of If: '<S12>/If' */

  /* Product: '<S12>/Divide1' incorporates:
   *  Constant: '<S12>/RodOffset'
   *  Sum: '<S12>/Sum'
   */
  PendulumQuickStart_B.Divide1 = (PendulumQuickStart_P.RodOffset_Value +
    PendulumQuickStart_B.Merge) / rtb_Product;

  /* Sum: '<S12>/Subtract1' */
  PendulumQuickStart_B.Subtract1 = PendulumQuickStart_B.Divide3 -
    PendulumQuickStart_B.Divide1;
  if (tmp) {
    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    rtb_Product = floor(PendulumQuickStart_P.Constant1_Value_c);
    if (rtIsNaN(rtb_Product) || rtIsInf(rtb_Product)) {
      rtb_Product = 0.0;
    } else {
      rtb_Product = fmod(rtb_Product, 256.0);
    }

    /* DataTypeConversion: '<S7>/Data Type Conversion' */
    PendulumQuickStart_B.DataTypeConversion_h = (uint8_T)(rtb_Product < 0.0 ?
      (int32_T)(uint8_T)-(int8_T)(uint8_T)-rtb_Product : (int32_T)(uint8_T)
      rtb_Product);

    /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
     *  Constant: '<S7>/Constant2'
     */
    rtb_Product = floor(PendulumQuickStart_P.Constant2_Value);
    if (rtIsNaN(rtb_Product) || rtIsInf(rtb_Product)) {
      rtb_Product = 0.0;
    } else {
      rtb_Product = fmod(rtb_Product, 256.0);
    }

    /* DataTypeConversion: '<S7>/Data Type Conversion1' */
    PendulumQuickStart_B.DataTypeConversion1 = (uint8_T)(rtb_Product < 0.0 ?
      (int32_T)(uint8_T)-(int8_T)(uint8_T)-rtb_Product : (int32_T)(uint8_T)
      rtb_Product);

    /* MATLAB Function: '<S1>/Move to Center' incorporates:
     *  Constant: '<S1>/Move Center'
     */
    if ((PendulumQuickStart_B.homed == 1.0) &&
        (PendulumQuickStart_P.MoveCenter_Value == 1.0)) {
      rtb_torqueOut = (PendulumQuickStart_DW.set_pos -
                       PendulumQuickStart_B.cartPos) * PendulumQuickStart_DW.kp;
      if (fabs(PendulumQuickStart_DW.set_pos - PendulumQuickStart_B.cartPos) <
          1.0) {
        rtb_torqueOut = 0.0;
      }
    } else {
      rtb_torqueOut = rtb_torque;
    }

    rtb_homedOut = PendulumQuickStart_B.homed;

    /* End of MATLAB Function: '<S1>/Move to Center' */

    /* Gain: '<S5>/Gain' */
    PendulumQuickStart_B.Gain = PendulumQuickStart_P.Gain_Gain *
      PendulumQuickStart_B.cartPos;

    /* Gain: '<S11>/Gain4' incorporates:
     *  Constant: '<S11>/Cart-Pos'
     */
    PendulumQuickStart_B.Gain4 = PendulumQuickStart_P.Gain4_Gain *
      PendulumQuickStart_P.CartPos_Value;
  }

  /* DeadZone: '<S11>/Dead Zone' */
  if (PendulumQuickStart_B.Subtract1 > PendulumQuickStart_P.DeadZone_End) {
    /* DeadZone: '<S11>/Dead Zone' */
    PendulumQuickStart_B.DeadZone = PendulumQuickStart_B.Subtract1 -
      PendulumQuickStart_P.DeadZone_End;
  } else if (PendulumQuickStart_B.Subtract1 >=
             PendulumQuickStart_P.DeadZone_Start) {
    /* DeadZone: '<S11>/Dead Zone' */
    PendulumQuickStart_B.DeadZone = 0.0;
  } else {
    /* DeadZone: '<S11>/Dead Zone' */
    PendulumQuickStart_B.DeadZone = PendulumQuickStart_B.Subtract1 -
      PendulumQuickStart_P.DeadZone_Start;
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
  rtb_torque = PendulumQuickStart_P.Nbar * PendulumQuickStart_B.Gain4 * 0.001 -
    (((PendulumQuickStart_P.TransferFcn_C[0] *
       PendulumQuickStart_X.TransferFcn_CSTATE[0] +
       PendulumQuickStart_P.TransferFcn_C[1] *
       PendulumQuickStart_X.TransferFcn_CSTATE[1]) *
      PendulumQuickStart_P.Gain3_Gain * PendulumQuickStart_P.K[2] +
      (PendulumQuickStart_P.Gain2_Gain * PendulumQuickStart_B.DeadZone *
       PendulumQuickStart_P.K[1] + PendulumQuickStart_P.K[0] *
       PendulumQuickStart_B.Gain)) + (PendulumQuickStart_P.undOrder_C[0] *
      PendulumQuickStart_X.undOrder_CSTATE[0] + PendulumQuickStart_P.undOrder_C
      [1] * PendulumQuickStart_X.undOrder_CSTATE[1]) *
     PendulumQuickStart_P.Gain6_Gain * PendulumQuickStart_P.K[3]);

  /* Saturate: '<S11>/Saturation' */
  if (rtb_torque > PendulumQuickStart_P.Saturation_UpperSat) {
    /* Saturate: '<S11>/Saturation' */
    PendulumQuickStart_B.Saturation = PendulumQuickStart_P.Saturation_UpperSat;
  } else if (rtb_torque < PendulumQuickStart_P.Saturation_LowerSat) {
    /* Saturate: '<S11>/Saturation' */
    PendulumQuickStart_B.Saturation = PendulumQuickStart_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S11>/Saturation' */
    PendulumQuickStart_B.Saturation = rtb_torque;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* TransferFcn: '<S11>/F//Volt' */
  rtb_Product = PendulumQuickStart_P.FVolt_C * PendulumQuickStart_X.FVolt_CSTATE
    + PendulumQuickStart_P.FVolt_D * PendulumQuickStart_B.Saturation;

  /* Saturate: '<S11>/Saturation1' */
  if (rtb_Product > PendulumQuickStart_P.Saturation1_UpperSat) {
    /* Saturate: '<S11>/Saturation1' */
    PendulumQuickStart_B.Saturation1 = PendulumQuickStart_P.Saturation1_UpperSat;
  } else if (rtb_Product < PendulumQuickStart_P.Saturation1_LowerSat) {
    /* Saturate: '<S11>/Saturation1' */
    PendulumQuickStart_B.Saturation1 = PendulumQuickStart_P.Saturation1_LowerSat;
  } else {
    /* Saturate: '<S11>/Saturation1' */
    PendulumQuickStart_B.Saturation1 = rtb_Product;
  }

  /* End of Saturate: '<S11>/Saturation1' */

  /* Gain: '<S11>/Gain7' incorporates:
   *  Gain: '<S11>/Gain'
   */
  rtb_torque = PendulumQuickStart_P.Gain_Gain_h *
    PendulumQuickStart_B.Saturation1 * PendulumQuickStart_P.Gain7_Gain;

  /* RelationalOperator: '<S15>/Compare' incorporates:
   *  Abs: '<S11>/Abs'
   *  Constant: '<S15>/Constant'
   */
  Compare = (fabs(rtb_torque) <= PendulumQuickStart_P.CompareToConstant_const);
  if (tmp) {
    /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S18>/Enable'
     */
    if (y) {
      /* SignalConversion generated from: '<S18>/Enable' */
      PendulumQuickStart_DW.EnabledSubsystem_MODE = Compare;
    }

    /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem' */
  }

  /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (PendulumQuickStart_DW.EnabledSubsystem_MODE) {
    /* Merge: '<S17>/Merge' incorporates:
     *  Constant: '<S17>/Constant3'
     *  Product: '<S18>/Product'
     */
    PendulumQuickStart_B.Merge_p = rtb_torque *
      PendulumQuickStart_P.Constant3_Value;
    if (y) {
      srUpdateBC(PendulumQuickStart_DW.EnabledSubsystem_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem' */
  if (tmp) {
    /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S19>/Enable'
     */
    if (y) {
      /* Logic: '<S17>/NOT' */
      PendulumQuickStart_DW.EnabledSubsystem1_MODE = !Compare;
    }

    /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem1' */
  }

  /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  if (PendulumQuickStart_DW.EnabledSubsystem1_MODE) {
    /* Merge: '<S17>/Merge' incorporates:
     *  SignalConversion generated from: '<S19>/In1'
     */
    PendulumQuickStart_B.Merge_p = rtb_torque;
    if (y) {
      srUpdateBC(PendulumQuickStart_DW.EnabledSubsystem1_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem1' */
  if (tmp) {
    /* MATLAB Function: '<S1>/Selection' incorporates:
     *  Constant: '<S1>/Enable Control'
     *  Constant: '<S1>/Mode'
     *  Gain: '<S1>/Gain'
     *  Saturate: '<S5>/Saturation1'
     */
    if (PendulumQuickStart_P.Mode_Value == 0.0) {
      PendulumQuickStart_DW.torqueval = rtb_torqueOut;
    }

    if ((PendulumQuickStart_P.Mode_Value == 1.0) && (rtb_homedOut == 1.0)) {
      if (PendulumQuickStart_P.EnableControl_Value == 1.0) {
        /* Saturate: '<S5>/Saturation1' */
        if (PendulumQuickStart_B.Merge_p >
            PendulumQuickStart_P.Saturation1_UpperSat_c) {
          rtb_Product = PendulumQuickStart_P.Saturation1_UpperSat_c;
        } else if (PendulumQuickStart_B.Merge_p <
                   PendulumQuickStart_P.Saturation1_LowerSat_g) {
          rtb_Product = PendulumQuickStart_P.Saturation1_LowerSat_g;
        } else {
          rtb_Product = PendulumQuickStart_B.Merge_p;
        }

        PendulumQuickStart_DW.torqueval = PendulumQuickStart_P.Gain_Gain_o *
          rtb_Product;
      } else {
        PendulumQuickStart_DW.torqueval = 0.0;
      }
    }

    PendulumQuickStart_B.torqueOut = PendulumQuickStart_DW.torqueval;

    /* End of MATLAB Function: '<S1>/Selection' */
  }

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Enable'
   *  Constant: '<S1>/Mode'
   */
  if (PendulumQuickStart_P.Enable_Value == 1.0) {
    rtb_torqueOut = 1.0;
    if (PendulumQuickStart_P.Mode_Value == 0.0) {
      rtb_homedOut = PendulumQuickStart_B.torqueOut;
    } else if ((fabs(PendulumQuickStart_B.Subtract1) <= 30.0) && (fabs
                (PendulumQuickStart_B.cartPos) <= 340.0)) {
      rtb_homedOut = PendulumQuickStart_B.torqueOut;
    } else {
      rtb_torqueOut = 0.0;
      rtb_homedOut = 0.0;
    }
  } else {
    rtb_torqueOut = 0.0;
    rtb_homedOut = 0.0;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* DataTypeConversion: '<S7>/Data Type Conversion4' */
  i_0 = (int32_T)rtb_torqueOut;

  /* Saturate: '<S7>/Saturation1' */
  if (rtb_homedOut > PendulumQuickStart_P.Saturation1_UpperSat_a) {
    rtb_homedOut = PendulumQuickStart_P.Saturation1_UpperSat_a;
  } else if (rtb_homedOut < PendulumQuickStart_P.Saturation1_LowerSat_f) {
    rtb_homedOut = PendulumQuickStart_P.Saturation1_LowerSat_f;
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion7' incorporates:
   *  Saturate: '<S7>/Saturation1'
   */
  rtb_Product = floor(rtb_homedOut);
  if (rtIsNaN(rtb_Product) || rtIsInf(rtb_Product)) {
    rtb_Product = 0.0;
  } else {
    rtb_Product = fmod(rtb_Product, 65536.0);
  }

  rtb_rod = (int16_T)(rtb_Product < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
                      -rtb_Product : (int32_T)(int16_T)(uint16_T)rtb_Product);

  /* End of DataTypeConversion: '<S7>/Data Type Conversion7' */

  /* MATLAB Function: '<S7>/uint16_in1' */
  memcpy((void *)&t[0], (void *)&rtb_rod, (uint32_T)((size_t)2 * sizeof(uint8_T)));

  /* SignalConversion generated from: '<S20>/ SFunction ' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion4'
   *  MATLAB Function: '<S7>/MATLAB Function'
   *  MATLAB Function: '<S7>/uint16_in1'
   */
  rtb_TmpSignalConversionAtSFun_k[0] = PendulumQuickStart_B.DataTypeConversion_h;
  rtb_TmpSignalConversionAtSFun_k[1] = PendulumQuickStart_B.DataTypeConversion1;
  rtb_TmpSignalConversionAtSFun_k[2] = (uint8_T)i_0;
  rtb_TmpSignalConversionAtSFun_k[3] = t[0];
  rtb_TmpSignalConversionAtSFun_k[4] = t[1];

  /* MATLAB Function: '<S7>/MATLAB Function' */
  rtb_crc = MAX_uint32_T;
  for (i = 0; i < 5; i++) {
    rtb_crc ^= (uint32_T)rtb_TmpSignalConversionAtSFun_k[i] << 24;
    for (inc = 0; inc < 8; inc++) {
      qY = rtb_crc >> 31;
      rtb_crc <<= 1;
      if (qY == 1U) {
        rtb_crc ^= 79764919U;
      }
    }
  }

  /* MATLAB Function: '<S7>/uint32_in' */
  memcpy((void *)&t_0[0], (void *)&rtb_crc, (uint32_T)((size_t)4 * sizeof
          (uint8_T)));

  /* SignalConversion generated from: '<S7>/Serial Write' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion4'
   *  MATLAB Function: '<S7>/uint16_in1'
   *  MATLAB Function: '<S7>/uint32_in'
   */
  rtb_TmpSignalConversionAtSerial[0] = PendulumQuickStart_B.DataTypeConversion_h;
  rtb_TmpSignalConversionAtSerial[1] = PendulumQuickStart_B.DataTypeConversion1;
  rtb_TmpSignalConversionAtSerial[2] = (uint8_T)i_0;
  rtb_TmpSignalConversionAtSerial[3] = t[0];
  rtb_TmpSignalConversionAtSerial[4] = t[1];
  rtb_TmpSignalConversionAtSerial[5] = t_0[0];
  rtb_TmpSignalConversionAtSerial[6] = t_0[1];
  rtb_TmpSignalConversionAtSerial[7] = t_0[2];
  rtb_TmpSignalConversionAtSerial[8] = t_0[3];

  /* MATLABSystem: '<S7>/Serial Write' */
  memcpy((void *)&TxDataLocChar[0], (void *)&rtb_TmpSignalConversionAtSerial[0],
         (uint32_T)((size_t)9 * sizeof(uint8_T)));
  MW_SCI_Transmit(PendulumQuickStart_DW.obj.MW_SCIHANDLE, &TxDataLocChar[0], 9U);
  if (tmp) {
  }

  if (rtmIsMajorTimeStep(PendulumQuickStart_M)) {
    if (rtmIsMajorTimeStep(PendulumQuickStart_M)) {/* Sample time: [0.004s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((PendulumQuickStart_M->Timing.clockTick1) * 0.004);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(PendulumQuickStart_M)) {
    rt_ertODEUpdateContinuousStates(&PendulumQuickStart_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++PendulumQuickStart_M->Timing.clockTick0;
    PendulumQuickStart_M->Timing.t[0] = rtsiGetSolverStopTime
      (&PendulumQuickStart_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.004s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.004, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PendulumQuickStart_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void PendulumQuickStart_derivatives(void)
{
  XDot_PendulumQuickStart_T *_rtXdot;
  _rtXdot = ((XDot_PendulumQuickStart_T *) PendulumQuickStart_M->derivs);

  /* Derivatives for TransferFcn: '<S11>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = PendulumQuickStart_P.TransferFcn_A[0] *
    PendulumQuickStart_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += PendulumQuickStart_P.TransferFcn_A[1] *
    PendulumQuickStart_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] = PendulumQuickStart_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += PendulumQuickStart_B.Gain;

  /* Derivatives for TransferFcn: '<S11>/2nd Order' */
  _rtXdot->undOrder_CSTATE[0] = PendulumQuickStart_P.undOrder_A[0] *
    PendulumQuickStart_X.undOrder_CSTATE[0];
  _rtXdot->undOrder_CSTATE[0] += PendulumQuickStart_P.undOrder_A[1] *
    PendulumQuickStart_X.undOrder_CSTATE[1];
  _rtXdot->undOrder_CSTATE[1] = PendulumQuickStart_X.undOrder_CSTATE[0];
  _rtXdot->undOrder_CSTATE[0] += PendulumQuickStart_B.DeadZone;

  /* Derivatives for TransferFcn: '<S11>/F//Volt' */
  _rtXdot->FVolt_CSTATE = PendulumQuickStart_P.FVolt_A *
    PendulumQuickStart_X.FVolt_CSTATE;
  _rtXdot->FVolt_CSTATE += PendulumQuickStart_B.Saturation;
}

/* Model initialize function */
void PendulumQuickStart_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PendulumQuickStart_M, 0,
                sizeof(RT_MODEL_PendulumQuickStart_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PendulumQuickStart_M->solverInfo,
                          &PendulumQuickStart_M->Timing.simTimeStep);
    rtsiSetTPtr(&PendulumQuickStart_M->solverInfo, &rtmGetTPtr
                (PendulumQuickStart_M));
    rtsiSetStepSizePtr(&PendulumQuickStart_M->solverInfo,
                       &PendulumQuickStart_M->Timing.stepSize0);
    rtsiSetdXPtr(&PendulumQuickStart_M->solverInfo,
                 &PendulumQuickStart_M->derivs);
    rtsiSetContStatesPtr(&PendulumQuickStart_M->solverInfo, (real_T **)
                         &PendulumQuickStart_M->contStates);
    rtsiSetNumContStatesPtr(&PendulumQuickStart_M->solverInfo,
      &PendulumQuickStart_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PendulumQuickStart_M->solverInfo,
      &PendulumQuickStart_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PendulumQuickStart_M->solverInfo,
      &PendulumQuickStart_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PendulumQuickStart_M->solverInfo,
      &PendulumQuickStart_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&PendulumQuickStart_M->solverInfo, (boolean_T**)
      &PendulumQuickStart_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&PendulumQuickStart_M->solverInfo, (&rtmGetErrorStatus
      (PendulumQuickStart_M)));
    rtsiSetRTModelPtr(&PendulumQuickStart_M->solverInfo, PendulumQuickStart_M);
  }

  rtsiSetSimTimeStep(&PendulumQuickStart_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&PendulumQuickStart_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&PendulumQuickStart_M->solverInfo, false);
  PendulumQuickStart_M->intgData.y = PendulumQuickStart_M->odeY;
  PendulumQuickStart_M->intgData.f[0] = PendulumQuickStart_M->odeF[0];
  PendulumQuickStart_M->intgData.f[1] = PendulumQuickStart_M->odeF[1];
  PendulumQuickStart_M->intgData.f[2] = PendulumQuickStart_M->odeF[2];
  PendulumQuickStart_M->intgData.f[3] = PendulumQuickStart_M->odeF[3];
  PendulumQuickStart_M->contStates = ((X_PendulumQuickStart_T *)
    &PendulumQuickStart_X);
  PendulumQuickStart_M->contStateDisabled = ((XDis_PendulumQuickStart_T *)
    &PendulumQuickStart_XDis);
  PendulumQuickStart_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&PendulumQuickStart_M->solverInfo, (void *)
                    &PendulumQuickStart_M->intgData);
  rtsiSetSolverName(&PendulumQuickStart_M->solverInfo,"ode4");
  rtmSetTPtr(PendulumQuickStart_M, &PendulumQuickStart_M->Timing.tArray[0]);
  rtmSetTFinal(PendulumQuickStart_M, -1);
  PendulumQuickStart_M->Timing.stepSize0 = 0.004;

  /* External mode info */
  PendulumQuickStart_M->Sizes.checksums[0] = (492186454U);
  PendulumQuickStart_M->Sizes.checksums[1] = (1410834224U);
  PendulumQuickStart_M->Sizes.checksums[2] = (3345197367U);
  PendulumQuickStart_M->Sizes.checksums[3] = (2166133401U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[19];
    PendulumQuickStart_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &PendulumQuickStart_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &PendulumQuickStart_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)
      &PendulumQuickStart_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &PendulumQuickStart_DW.EnabledSubsystem1_SubsysRanBC;
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
    rteiSetModelMappingInfoPtr(PendulumQuickStart_M->extModeInfo,
      &PendulumQuickStart_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PendulumQuickStart_M->extModeInfo,
                        PendulumQuickStart_M->Sizes.checksums);
    rteiSetTPtr(PendulumQuickStart_M->extModeInfo, rtmGetTPtr
                (PendulumQuickStart_M));
  }

  /* block I/O */
  (void) memset(((void *) &PendulumQuickStart_B), 0,
                sizeof(B_PendulumQuickStart_T));

  /* states (continuous) */
  {
    (void) memset((void *)&PendulumQuickStart_X, 0,
                  sizeof(X_PendulumQuickStart_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&PendulumQuickStart_XDis, 0,
                  sizeof(XDis_PendulumQuickStart_T));
  }

  /* states (dwork) */
  (void) memset((void *)&PendulumQuickStart_DW, 0,
                sizeof(DW_PendulumQuickStart_T));

  /* Start for FromWorkspace: '<S12>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0 } ;

    static real_T pDataValues0[] = { 4095.0, 11.0, 4095.0 } ;

    PendulumQuickStart_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    PendulumQuickStart_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    PendulumQuickStart_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for If: '<S12>/If' */
  PendulumQuickStart_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn' */
  PendulumQuickStart_X.TransferFcn_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S11>/2nd Order' */
  PendulumQuickStart_X.undOrder_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn' */
  PendulumQuickStart_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S11>/2nd Order' */
  PendulumQuickStart_X.undOrder_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S11>/F//Volt' */
  PendulumQuickStart_X.FVolt_CSTATE = 0.0;
  PendulumQuickStart_DW.bff.size = 0;

  /* SystemInitialize for MATLAB Function: '<S9>/MATLAB Function1' */
  PendulumQuickStart_DW.val_not_empty = false;
  PendulumQuickStart_DW.bff_not_empty = false;
  PendulumQuickStart_DW.val = 0.0;

  /* SystemInitialize for MATLAB Function: '<S9>/MATLAB Function3' */
  PendulumQuickStart_DW.validpack_not_empty = false;
  PendulumQuickStart_DW.validpack2_not_empty = false;

  /* SystemInitialize for MATLAB Function: '<S1>/Homing Block' */
  PendulumQuickStart_DW.torqueval_d = 0.0;
  PendulumQuickStart_DW.state = 0.0;
  memset(&PendulumQuickStart_DW.precartArray[0], 0, 10U * sizeof(real_T));
  PendulumQuickStart_DW.homeval = 0.0;
  PendulumQuickStart_DW.counter = 0.0;
  PendulumQuickStart_DW.i = 0.0;
  PendulumQuickStart_DW.precart = 0.0;
  PendulumQuickStart_DW.prepos = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/Move to Center' */
  PendulumQuickStart_DW.set_pos = 0.0;
  PendulumQuickStart_DW.kp = 4.0;

  /* SystemInitialize for MATLAB Function: '<S1>/Selection' */
  PendulumQuickStart_DW.torqueval = 0.0;

  /* Start for MATLABSystem: '<S9>/Serial Read' */
  PendulumQuickStart_DW.obj_o.isInitialized = 0;
  PendulumQuickStart_DW.obj_o.matlabCodegenIsDeleted = false;
  PendulumQuickS_SystemCore_setup(&PendulumQuickStart_DW.obj_o);

  /* Start for MATLABSystem: '<S7>/Serial Write' */
  PendulumQuickStart_DW.obj.matlabCodegenIsDeleted = false;
  PendulumQuickStart_DW.obj.isSetupComplete = false;
  PendulumQuickStart_DW.obj.isInitialized = 1;
  PendulumQuic_SCIWrite_setupImpl(&PendulumQuickStart_DW.obj);
  PendulumQuickStart_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void PendulumQuickStart_terminate(void)
{
  /* Terminate for MATLABSystem: '<S9>/Serial Read' */
  if (!PendulumQuickStart_DW.obj_o.matlabCodegenIsDeleted) {
    PendulumQuickStart_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PendulumQuickStart_DW.obj_o.isInitialized == 1) &&
        PendulumQuickStart_DW.obj_o.isSetupComplete) {
      MW_SCI_Close(PendulumQuickStart_DW.obj_o.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/Serial Read' */
  /* Terminate for MATLABSystem: '<S7>/Serial Write' */
  if (!PendulumQuickStart_DW.obj.matlabCodegenIsDeleted) {
    PendulumQuickStart_DW.obj.matlabCodegenIsDeleted = true;
    if ((PendulumQuickStart_DW.obj.isInitialized == 1) &&
        PendulumQuickStart_DW.obj.isSetupComplete) {
      MW_SCI_Close(PendulumQuickStart_DW.obj.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Serial Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
