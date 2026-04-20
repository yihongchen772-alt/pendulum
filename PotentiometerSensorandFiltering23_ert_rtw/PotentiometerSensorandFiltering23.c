/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PotentiometerSensorandFiltering23.c
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
#include "PotentiometerSensorandFiltering23_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "PotentiometerSensorandFiltering23_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stddef.h>

/* Block signals (default storage) */
B_PotentiometerSensorandFilte_T PotentiometerSensorandFilteri_B;

/* Continuous states */
X_PotentiometerSensorandFilte_T PotentiometerSensorandFilteri_X;

/* Disabled State Vector */
XDis_PotentiometerSensorandFi_T PotentiometerSensorandFilt_XDis;

/* Block states (default storage) */
DW_PotentiometerSensorandFilt_T PotentiometerSensorandFilter_DW;

/* Real-time model */
static RT_MODEL_PotentiometerSensora_T PotentiometerSensorandFilter_M_;
RT_MODEL_PotentiometerSensora_T *const PotentiometerSensorandFilter_M =
  &PotentiometerSensorandFilter_M_;

/* Forward declaration for local functions */
static void PotentiometerSensorand_eml_find(const boolean_T x_data[], const
  int32_T *x_size, int32_T i_data[], int32_T *i_size);
static void Potentiomete_SystemCore_setup_o(codertarget_raspi_internal__o_T *obj);
static void PotentiometerS_SystemCore_setup(codertarget_raspi_internal_SC_T *obj);

/*
 * This function updates continuous states using the ODE8 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
#define PotentiometerSensorandF_NSTAGES 13

  static real_T rt_ODE8_B[13] = {
    4.174749114153025E-2, 0.0, 0.0, 0.0,
    0.0, -5.54523286112393E-2, 2.393128072011801E-1, 7.03510669403443E-1,
    -7.597596138144609E-1, 6.605630309222863E-1, 1.581874825101233E-1,
    -2.381095387528628E-1, 2.5E-1
  };

  static real_T rt_ODE8_C[13] = {
    0.0, 5.555555555555556E-2, 8.333333333333333E-2, 1.25E-1,
    3.125E-1, 3.75E-1, 1.475E-1, 4.65E-1,
    5.648654513822596E-1, 6.5E-1, 9.246562776405044E-1, 1.0, 1.0
  };

  static real_T rt_ODE8_A[13][13] = {
    /* rt_ODE8_A[0][] */
    { 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[1][] */
    { 5.555555555555556E-2, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[2][] */
    { 2.083333333333333E-2, 6.25E-2, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[3][] */
    { 3.125E-2, 0.0, 9.375E-2, 0.0,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[4][] */
    { 3.125E-1, 0.0, -1.171875, 1.171875,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[5][] */
    { 3.75E-2, 0.0, 0.0, 1.875E-1,
      1.5E-1, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[6][] */
    { 4.791013711111111E-2, 0.0, 0.0, 1.122487127777778E-1,
      -2.550567377777778E-2, 1.284682388888889E-2, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[7][] */
    { 1.691798978729228E-2, 0.0, 0.0, 3.878482784860432E-1,
      3.597736985150033E-2, 1.969702142156661E-1, -1.727138523405018E-1, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[8][] */
    { 6.90957533591923E-2, 0.0, 0.0, -6.342479767288542E-1,
      -1.611975752246041E-1, 1.386503094588253E-1, 9.409286140357563E-1,
      2.11636326481944E-1,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[9][] */
    { 1.835569968390454E-1, 0.0, 0.0, -2.468768084315592,
      -2.912868878163005E-1, -2.647302023311738E-2, 2.8478387641928,
      2.813873314698498E-1,
      1.237448998633147E-1, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[10][] */
    { -1.215424817395888, 0.0, 0.0, 1.667260866594577E1,
      9.157418284168179E-1, -6.056605804357471, -1.600357359415618E1,
      1.484930308629766E1,
      -1.337157573528985E1, 5.134182648179638, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[11][] */
    { 2.588609164382643E-1, 0.0, 0.0, -4.774485785489205,
      -4.350930137770325E-1, -3.049483332072241, 5.577920039936099,
      6.155831589861039,
      -5.062104586736938, 2.193926173180679, 1.346279986593349E-1, 0.0, 0.0 },

    /* rt_ODE8_A[12][] */
    { 8.224275996265075E-1, 0.0, 0.0, -1.165867325727766E1,
      -7.576221166909362E-1, 7.139735881595818E-1, 1.207577498689006E1,
      -2.127659113920403,
      1.990166207048956, -2.342864715440405E-1, 1.758985777079423E-1, 0.0, 0.0 },
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE8_IntgData *intgData = (ODE8_IntgData *)rtsiGetSolverData(si);
  real_T *deltaY = intgData->deltaY;
  real_T *x0 = intgData->x0;
  real_T* f[PotentiometerSensorandF_NSTAGES];
  int_T idx,stagesIdx,statesIdx;
  real_T deltaX;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  f[0] = intgData->f[0];
  f[1] = intgData->f[1];
  f[2] = intgData->f[2];
  f[3] = intgData->f[3];
  f[4] = intgData->f[4];
  f[5] = intgData->f[5];
  f[6] = intgData->f[6];
  f[7] = intgData->f[7];
  f[8] = intgData->f[8];
  f[9] = intgData->f[9];
  f[10] = intgData->f[10];
  f[11] = intgData->f[11];
  f[12] = intgData->f[12];

  /* Save the state values at time t in y and x0*/
  (void) memset(deltaY, 0,
                (uint_T)nXc*sizeof(real_T));
  (void) memcpy(x0, x,
                nXc*sizeof(real_T));
  for (stagesIdx=0;stagesIdx<PotentiometerSensorandF_NSTAGES;stagesIdx++) {
    (void) memcpy(x, x0,
                  (uint_T)nXc*sizeof(real_T));
    for (statesIdx=0;statesIdx<nXc;statesIdx++) {
      deltaX = 0;
      for (idx=0;idx<stagesIdx;idx++) {
        deltaX = deltaX + h*rt_ODE8_A[stagesIdx][idx]*f[idx][statesIdx];
      }

      x[statesIdx] = x0[statesIdx] + deltaX;
    }

    if (stagesIdx==0) {
      rtsiSetdX(si, f[stagesIdx]);
      PotentiometerSensorandFiltering23_derivatives();
    } else {
      (stagesIdx==PotentiometerSensorandF_NSTAGES-1)? rtsiSetT(si, tnew) :
        rtsiSetT(si, t + h*rt_ODE8_C[stagesIdx]);
      rtsiSetdX(si, f[stagesIdx]);
      PotentiometerSensorandFiltering23_step();
      PotentiometerSensorandFiltering23_derivatives();
    }

    for (statesIdx=0;statesIdx<nXc;statesIdx++) {
      deltaY[statesIdx] = deltaY[statesIdx] + h*rt_ODE8_B[stagesIdx]*f[stagesIdx]
        [statesIdx];
    }
  }

  for (statesIdx=0;statesIdx<nXc;statesIdx++) {
    x[statesIdx] = x0[statesIdx] + deltaY[statesIdx];
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

/* Function for MATLAB Function: '<S2>/MATLAB Function1' */
static void PotentiometerSensorand_eml_find(const boolean_T x_data[], const
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

static void Potentiomete_SystemCore_setup_o(codertarget_raspi_internal__o_T *obj)
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

static void PotentiometerS_SystemCore_setup(codertarget_raspi_internal_SC_T *obj)
{
  void* SCIModuleVoidPtr;
  int32_T i;
  char_T b_SCIModuleLoc[13];
  static const char_T b_SCIModuleLoc_0[13] = "/dev/serial0";

  /* Start for MATLABSystem: '<S1>/Serial Write' */
  obj->isInitialized = 1;
  for (i = 0; i < 13; i++) {
    /* Start for MATLABSystem: '<S1>/Serial Write' */
    b_SCIModuleLoc[i] = b_SCIModuleLoc_0[i];
  }

  SCIModuleVoidPtr = (void*)(&b_SCIModuleLoc[0]);

  /* Start for MATLABSystem: '<S1>/Serial Write' */
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleVoidPtr, true, MW_UNDEFINED_VALUE,
    MW_UNDEFINED_VALUE);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, MW_SCI_PARITY_NONE,
                        MW_SCI_STOPBITS_1);
  obj->isSetupComplete = true;
}

/* Model step function */
void PotentiometerSensorandFiltering23_step(void)
{
  if (rtmIsMajorTimeStep(PotentiometerSensorandFilter_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&PotentiometerSensorandFilter_M->solverInfo,
                          ((PotentiometerSensorandFilter_M->Timing.clockTick0+1)*
      PotentiometerSensorandFilter_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PotentiometerSensorandFilter_M)) {
    PotentiometerSensorandFilter_M->Timing.t[0] = rtsiGetT
      (&PotentiometerSensorandFilter_M->solverInfo);
  }

  {
    real_T *lastU;
    int32_T i;
    int32_T inc;
    int32_T j;
    int32_T xfi;
    uint32_T qY;
    int16_T rtb_DataTypeConversion7;
    uint8_T t_0[4];
    uint8_T t[2];
    uint8_T g_r;
    uint8_T h_r;
    uint8_T i_r;
    uint8_T j_r;
    uint8_T k_r;
    uint8_T l_r;
    uint8_T m_r;
    uint8_T rtb_DataTypeConversion;
    uint8_T rtb_DataTypeConversion4;
    uint8_T status;
    if (rtmIsMajorTimeStep(PotentiometerSensorandFilter_M)) {
      /* MATLABSystem: '<S2>/Serial Read' */
      if (PotentiometerSensorandFilter_DW.obj.SampleTime !=
          PotentiometerSensorandFilteri_P.SerialRead_SampleTime) {
        PotentiometerSensorandFilter_DW.obj.SampleTime =
          PotentiometerSensorandFilteri_P.SerialRead_SampleTime;
      }

      status = MW_SCI_Receive(PotentiometerSensorandFilter_DW.obj.MW_SCIHANDLE,
        &PotentiometerSensorandFilteri_B.RxDataLocChar[0], 10U);
      memcpy((void *)&PotentiometerSensorandFilteri_B.RxData[0], (void *)
             &PotentiometerSensorandFilteri_B.RxDataLocChar[0], (size_t)10 *
             sizeof(uint8_T));

      /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
       *  Constant: '<S2>/Buffer Size'
       *  Constant: '<S2>/Constant1'
       *  Constant: '<S2>/Constant4'
       *  MATLABSystem: '<S2>/Serial Read'
       * */
      if (!PotentiometerSensorandFilter_DW.bff_not_empty) {
        for (i = 0; i < 10; i++) {
          PotentiometerSensorandFilter_DW.packetindex[i] = 0U;
        }
      }

      if (!PotentiometerSensorandFilter_DW.val_not_empty) {
        PotentiometerSensorandFilter_DW.val_not_empty = true;
        PotentiometerSensorandFilter_DW.bff.size =
          PotentiometerSensorandFilteri_P.BufferSize_Value;
        i = PotentiometerSensorandFilteri_P.BufferSize_Value;
        if (i - 1 >= 0) {
          memset(&PotentiometerSensorandFilter_DW.bff.data[0], 0, (uint32_T)i *
                 sizeof(real_T));
        }

        PotentiometerSensorandFilter_DW.bff_not_empty =
          (PotentiometerSensorandFilter_DW.bff.size != 0);
        inc = 0;
      } else {
        inc = 1;
      }

      PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
        (PotentiometerSensorandFilter_DW.val - 1.0);
      if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
        if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
          rtb_DataTypeConversion4 = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
        } else {
          rtb_DataTypeConversion4 = 0U;
        }
      } else {
        rtb_DataTypeConversion4 = MAX_uint8_T;
      }

      if (PotentiometerSensorandFilter_DW.val - 1.0 == rtb_DataTypeConversion4)
      {
        if (PotentiometerSensorandFilteri_P.BufferSize_Value != 0) {
          if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
            rtb_DataTypeConversion = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            rtb_DataTypeConversion = (uint8_T)((uint32_T)rtb_DataTypeConversion4
              / PotentiometerSensorandFilteri_P.BufferSize_Value);
          }

          rtb_DataTypeConversion4 = (uint8_T)((uint32_T)rtb_DataTypeConversion4
            - (uint8_T)((uint32_T)rtb_DataTypeConversion *
                        PotentiometerSensorandFilteri_P.BufferSize_Value));
        }
      } else {
        PotentiometerSensorandFilteri_B.b_r =
          PotentiometerSensorandFilter_DW.val - 1.0;
        if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0) {
          if (PotentiometerSensorandFilter_DW.val - 1.0 == 0.0) {
            PotentiometerSensorandFilteri_B.b_r = 0.0;
          }
        } else if (rtIsInf(PotentiometerSensorandFilter_DW.val - 1.0)) {
          PotentiometerSensorandFilteri_B.b_r = (rtNaN);
        } else if (PotentiometerSensorandFilter_DW.val - 1.0 == 0.0) {
          PotentiometerSensorandFilteri_B.b_r = 0.0;
        } else {
          PotentiometerSensorandFilteri_B.b_r = fmod
            (PotentiometerSensorandFilter_DW.val - 1.0,
             PotentiometerSensorandFilteri_P.BufferSize_Value);
          if (PotentiometerSensorandFilteri_B.b_r == 0.0) {
            PotentiometerSensorandFilteri_B.b_r = 0.0;
          } else if (PotentiometerSensorandFilter_DW.val - 1.0 < 0.0) {
            PotentiometerSensorandFilteri_B.b_r += (real_T)
              PotentiometerSensorandFilteri_P.BufferSize_Value;
          }
        }

        PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
          (PotentiometerSensorandFilteri_B.b_r);
        if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
          if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
            rtb_DataTypeConversion4 = (uint8_T)
              PotentiometerSensorandFilteri_B.b_r;
          } else {
            rtb_DataTypeConversion4 = 0U;
          }
        } else {
          rtb_DataTypeConversion4 = MAX_uint8_T;
        }
      }

      j = (int32_T)(rtb_DataTypeConversion4 + 1U);
      if (rtb_DataTypeConversion4 + 1U > 255U) {
        j = 255;
      }

      if (!PotentiometerSensorandFilter_DW.bff_not_empty) {
        PotentiometerSensorandFilter_DW.bff.size =
          PotentiometerSensorandFilteri_P.BufferSize_Value;
        i = PotentiometerSensorandFilteri_P.BufferSize_Value;
        if (i - 1 >= 0) {
          memset(&PotentiometerSensorandFilter_DW.bff.data[0], 0, (uint32_T)i *
                 sizeof(real_T));
        }

        PotentiometerSensorandFilter_DW.bff_not_empty =
          (PotentiometerSensorandFilter_DW.bff.size != 0);
      }

      if (status == 0) {
        for (i = 0; i < 10; i++) {
          xfi = (uint8_T)j + i;
          if (xfi > 255) {
            xfi = 255;
          }

          if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0) {
            rtb_DataTypeConversion = (uint8_T)(xfi - 1);
          } else {
            if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
              rtb_DataTypeConversion = MAX_uint8_T;

              /* Divide by zero handler */
            } else {
              rtb_DataTypeConversion = (uint8_T)((uint32_T)(uint8_T)(xfi - 1) /
                PotentiometerSensorandFilteri_P.BufferSize_Value);
            }

            rtb_DataTypeConversion = (uint8_T)((uint32_T)(uint8_T)(xfi - 1) -
              (uint8_T)((uint32_T)rtb_DataTypeConversion *
                        PotentiometerSensorandFilteri_P.BufferSize_Value));
          }

          xfi = (int32_T)(rtb_DataTypeConversion + 1U);
          if (rtb_DataTypeConversion + 1U > 255U) {
            xfi = 255;
          }

          PotentiometerSensorandFilter_DW.bff.data[xfi - 1] =
            PotentiometerSensorandFilteri_B.RxData[i];
        }

        if (inc == 1) {
          PotentiometerSensorandFilter_DW.val += 10.0;
        }
      }

      xfi = (int32_T)((uint8_T)j + 1U);
      if ((uint8_T)j + 1U > 255U) {
        xfi = 255;
      }

      if ((uint8_T)xfi > PotentiometerSensorandFilter_DW.bff.size) {
        inc = 0;
        i = 0;
      } else {
        inc = (uint8_T)xfi - 1;
        i = PotentiometerSensorandFilter_DW.bff.size;
      }

      i -= inc;
      for (xfi = 0; xfi < i; xfi++) {
        PotentiometerSensorandFilteri_B.tmp_data_m[xfi] =
          (PotentiometerSensorandFilter_DW.bff.data[inc + xfi] ==
           PotentiometerSensorandFilteri_P.Constant4_Value);
      }

      PotentiometerSensorand_eml_find(PotentiometerSensorandFilteri_B.tmp_data_m,
        &i, PotentiometerSensorandFilteri_B.tmp_data, &inc);
      for (xfi = 0; xfi < inc; xfi++) {
        PotentiometerSensorandFilteri_B.b_r = (real_T)
          PotentiometerSensorandFilteri_B.tmp_data[xfi] + (real_T)(uint8_T)j;
        if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
          if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
            PotentiometerSensorandFilteri_B.head_data[xfi] = (uint8_T)
              PotentiometerSensorandFilteri_B.b_r;
          } else {
            PotentiometerSensorandFilteri_B.head_data[xfi] = 0U;
          }
        } else {
          PotentiometerSensorandFilteri_B.head_data[xfi] = MAX_uint8_T;
        }
      }

      if (inc == 0) {
        if (PotentiometerSensorandFilter_DW.bff.size < 1) {
          i = -1;
        } else {
          i = PotentiometerSensorandFilter_DW.bff.size - 1;
        }

        xfi = i + 1;
        for (j = 0; j <= i; j++) {
          PotentiometerSensorandFilteri_B.tmp_data_m[j] =
            (PotentiometerSensorandFilter_DW.bff.data[j] ==
             PotentiometerSensorandFilteri_P.Constant4_Value);
        }

        PotentiometerSensorand_eml_find
          (PotentiometerSensorandFilteri_B.tmp_data_m, &xfi,
           PotentiometerSensorandFilteri_B.tmp_data, &inc);
        for (j = 0; j < inc; j++) {
          xfi = PotentiometerSensorandFilteri_B.tmp_data[j];
          if (xfi < 0) {
            xfi = 0;
          } else if (xfi > 255) {
            xfi = 255;
          }

          PotentiometerSensorandFilteri_B.head_data[j] = (uint8_T)xfi;
        }
      }

      if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0) {
        rtb_DataTypeConversion = PotentiometerSensorandFilteri_B.head_data[0];
      } else {
        if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
          rtb_DataTypeConversion = MAX_uint8_T;

          /* Divide by zero handler */
        } else {
          rtb_DataTypeConversion = (uint8_T)((uint32_T)
            PotentiometerSensorandFilteri_B.head_data[0] /
            PotentiometerSensorandFilteri_P.BufferSize_Value);
        }

        rtb_DataTypeConversion = (uint8_T)((uint32_T)
          PotentiometerSensorandFilteri_B.head_data[0] - (uint8_T)((uint32_T)
          rtb_DataTypeConversion *
          PotentiometerSensorandFilteri_P.BufferSize_Value));
      }

      j = (int32_T)(rtb_DataTypeConversion + 1U);
      if (rtb_DataTypeConversion + 1U > 255U) {
        j = 255;
      }

      if (PotentiometerSensorandFilter_DW.bff.data[j - 1] ==
          PotentiometerSensorandFilteri_P.Constant1_Value_g) {
        qY = PotentiometerSensorandFilteri_B.head_data[0] - 1U;
        if (PotentiometerSensorandFilteri_B.head_data[0] - 1U >
            PotentiometerSensorandFilteri_B.head_data[0]) {
          qY = 0U;
        }

        if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0) {
          status = (uint8_T)qY;
          rtb_DataTypeConversion4 = PotentiometerSensorandFilteri_B.head_data[0];
        } else {
          if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
            rtb_DataTypeConversion = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            rtb_DataTypeConversion = (uint8_T)((uint32_T)(uint8_T)qY /
              PotentiometerSensorandFilteri_P.BufferSize_Value);
          }

          status = (uint8_T)((uint32_T)(uint8_T)qY - (uint8_T)((uint32_T)
            rtb_DataTypeConversion *
            PotentiometerSensorandFilteri_P.BufferSize_Value));
          if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
            rtb_DataTypeConversion = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            rtb_DataTypeConversion = (uint8_T)((uint32_T)
              PotentiometerSensorandFilteri_B.head_data[0] /
              PotentiometerSensorandFilteri_P.BufferSize_Value);
          }

          rtb_DataTypeConversion4 = (uint8_T)((uint32_T)
            PotentiometerSensorandFilteri_B.head_data[0] - (uint8_T)((uint32_T)
            rtb_DataTypeConversion *
            PotentiometerSensorandFilteri_P.BufferSize_Value));
        }

        j = (int32_T)(PotentiometerSensorandFilteri_B.head_data[0] + 1U);
        if (PotentiometerSensorandFilteri_B.head_data[0] + 1U > 255U) {
          j = 255;
        }

        if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0) {
          g_r = (uint8_T)j;
        } else {
          if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
            rtb_DataTypeConversion = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            rtb_DataTypeConversion = (uint8_T)((uint32_T)(uint8_T)j /
              PotentiometerSensorandFilteri_P.BufferSize_Value);
          }

          g_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)
            rtb_DataTypeConversion *
            PotentiometerSensorandFilteri_P.BufferSize_Value));
        }

        j = (int32_T)(PotentiometerSensorandFilteri_B.head_data[0] + 2U);
        if (PotentiometerSensorandFilteri_B.head_data[0] + 2U > 255U) {
          j = 255;
        }

        if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0) {
          h_r = (uint8_T)j;
        } else {
          if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
            rtb_DataTypeConversion = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            rtb_DataTypeConversion = (uint8_T)((uint32_T)(uint8_T)j /
              PotentiometerSensorandFilteri_P.BufferSize_Value);
          }

          h_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)
            rtb_DataTypeConversion *
            PotentiometerSensorandFilteri_P.BufferSize_Value));
        }

        j = (int32_T)(PotentiometerSensorandFilteri_B.head_data[0] + 3U);
        if (PotentiometerSensorandFilteri_B.head_data[0] + 3U > 255U) {
          j = 255;
        }

        if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0) {
          i_r = (uint8_T)j;
        } else {
          if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
            rtb_DataTypeConversion = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            rtb_DataTypeConversion = (uint8_T)((uint32_T)(uint8_T)j /
              PotentiometerSensorandFilteri_P.BufferSize_Value);
          }

          i_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)
            rtb_DataTypeConversion *
            PotentiometerSensorandFilteri_P.BufferSize_Value));
        }

        j = (int32_T)(PotentiometerSensorandFilteri_B.head_data[0] + 4U);
        if (PotentiometerSensorandFilteri_B.head_data[0] + 4U > 255U) {
          j = 255;
        }

        if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0) {
          j_r = (uint8_T)j;
        } else {
          if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
            rtb_DataTypeConversion = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            rtb_DataTypeConversion = (uint8_T)((uint32_T)(uint8_T)j /
              PotentiometerSensorandFilteri_P.BufferSize_Value);
          }

          j_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)
            rtb_DataTypeConversion *
            PotentiometerSensorandFilteri_P.BufferSize_Value));
        }

        j = (int32_T)(PotentiometerSensorandFilteri_B.head_data[0] + 5U);
        if (PotentiometerSensorandFilteri_B.head_data[0] + 5U > 255U) {
          j = 255;
        }

        if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0) {
          k_r = (uint8_T)j;
        } else {
          if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
            rtb_DataTypeConversion = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            rtb_DataTypeConversion = (uint8_T)((uint32_T)(uint8_T)j /
              PotentiometerSensorandFilteri_P.BufferSize_Value);
          }

          k_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)
            rtb_DataTypeConversion *
            PotentiometerSensorandFilteri_P.BufferSize_Value));
        }

        j = (int32_T)(PotentiometerSensorandFilteri_B.head_data[0] + 6U);
        if (PotentiometerSensorandFilteri_B.head_data[0] + 6U > 255U) {
          j = 255;
        }

        if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0) {
          l_r = (uint8_T)j;
        } else {
          if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
            rtb_DataTypeConversion = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            rtb_DataTypeConversion = (uint8_T)((uint32_T)(uint8_T)j /
              PotentiometerSensorandFilteri_P.BufferSize_Value);
          }

          l_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)
            rtb_DataTypeConversion *
            PotentiometerSensorandFilteri_P.BufferSize_Value));
        }

        j = (int32_T)(PotentiometerSensorandFilteri_B.head_data[0] + 7U);
        if (PotentiometerSensorandFilteri_B.head_data[0] + 7U > 255U) {
          j = 255;
        }

        if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0) {
          m_r = (uint8_T)j;
        } else {
          if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
            rtb_DataTypeConversion = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            rtb_DataTypeConversion = (uint8_T)((uint32_T)(uint8_T)j /
              PotentiometerSensorandFilteri_P.BufferSize_Value);
          }

          m_r = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)((uint32_T)
            rtb_DataTypeConversion *
            PotentiometerSensorandFilteri_P.BufferSize_Value));
        }

        j = (int32_T)(PotentiometerSensorandFilteri_B.head_data[0] + 8U);
        if (PotentiometerSensorandFilteri_B.head_data[0] + 8U > 255U) {
          j = 255;
        }

        if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0) {
          rtb_DataTypeConversion = (uint8_T)j;
        } else {
          if (PotentiometerSensorandFilteri_P.BufferSize_Value == 0U) {
            rtb_DataTypeConversion = MAX_uint8_T;

            /* Divide by zero handler */
          } else {
            rtb_DataTypeConversion = (uint8_T)((uint32_T)(uint8_T)j /
              PotentiometerSensorandFilteri_P.BufferSize_Value);
          }

          rtb_DataTypeConversion = (uint8_T)((uint32_T)(uint8_T)j - (uint8_T)
            ((uint32_T)rtb_DataTypeConversion *
             PotentiometerSensorandFilteri_P.BufferSize_Value));
        }

        j = (int32_T)(status + 1U);
        if (status + 1U > 255U) {
          j = 255;
        }

        PotentiometerSensorandFilter_DW.packetindex[0] = (uint8_T)j;
        j = (int32_T)(rtb_DataTypeConversion4 + 1U);
        if (rtb_DataTypeConversion4 + 1U > 255U) {
          j = 255;
        }

        PotentiometerSensorandFilter_DW.packetindex[1] = (uint8_T)j;
        j = (int32_T)(g_r + 1U);
        if (g_r + 1U > 255U) {
          j = 255;
        }

        PotentiometerSensorandFilter_DW.packetindex[2] = (uint8_T)j;
        j = (int32_T)(h_r + 1U);
        if (h_r + 1U > 255U) {
          j = 255;
        }

        PotentiometerSensorandFilter_DW.packetindex[3] = (uint8_T)j;
        j = (int32_T)(i_r + 1U);
        if (i_r + 1U > 255U) {
          j = 255;
        }

        PotentiometerSensorandFilter_DW.packetindex[4] = (uint8_T)j;
        j = (int32_T)(j_r + 1U);
        if (j_r + 1U > 255U) {
          j = 255;
        }

        PotentiometerSensorandFilter_DW.packetindex[5] = (uint8_T)j;
        j = (int32_T)(k_r + 1U);
        if (k_r + 1U > 255U) {
          j = 255;
        }

        PotentiometerSensorandFilter_DW.packetindex[6] = (uint8_T)j;
        j = (int32_T)(l_r + 1U);
        if (l_r + 1U > 255U) {
          j = 255;
        }

        PotentiometerSensorandFilter_DW.packetindex[7] = (uint8_T)j;
        j = (int32_T)(m_r + 1U);
        if (m_r + 1U > 255U) {
          j = 255;
        }

        PotentiometerSensorandFilter_DW.packetindex[8] = (uint8_T)j;
        j = (int32_T)(rtb_DataTypeConversion + 1U);
        if (rtb_DataTypeConversion + 1U > 255U) {
          j = 255;
        }

        PotentiometerSensorandFilter_DW.packetindex[9] = (uint8_T)j;
      }

      for (j = 0; j < 10; j++) {
        PotentiometerSensorandFilteri_B.packet[j] =
          PotentiometerSensorandFilter_DW.bff.data[PotentiometerSensorandFilter_DW.packetindex
          [j] - 1];
      }

      /* End of MATLAB Function: '<S2>/MATLAB Function1' */
      /* MATLAB Function: '<S2>/MATLAB Function2' */
      PotentiometerSensorandFilteri_B.crc = MAX_uint32_T;
      for (i = 0; i < 6; i++) {
        PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
          (PotentiometerSensorandFilteri_B.packet[i]);
        if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
          if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
            rtb_DataTypeConversion = (uint8_T)
              PotentiometerSensorandFilteri_B.b_r;
          } else {
            rtb_DataTypeConversion = 0U;
          }
        } else {
          rtb_DataTypeConversion = MAX_uint8_T;
        }

        PotentiometerSensorandFilteri_B.crc ^= (uint32_T)rtb_DataTypeConversion <<
          24;
        for (j = 0; j < 8; j++) {
          xfi = (int32_T)(PotentiometerSensorandFilteri_B.crc >> 31);
          PotentiometerSensorandFilteri_B.crc <<= 1;
          if (xfi == 1) {
            PotentiometerSensorandFilteri_B.crc ^= 79764919U;
          }
        }
      }

      /* End of MATLAB Function: '<S2>/MATLAB Function2' */

      /* MATLAB Function: '<S2>/uint32_in2' */
      PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
        (PotentiometerSensorandFilteri_B.packet[6]);
      if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
        if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
          t_0[0] = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
        } else {
          t_0[0] = 0U;
        }
      } else {
        t_0[0] = MAX_uint8_T;
      }

      PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
        (PotentiometerSensorandFilteri_B.packet[7]);
      if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
        if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
          t_0[1] = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
        } else {
          t_0[1] = 0U;
        }
      } else {
        t_0[1] = MAX_uint8_T;
      }

      PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
        (PotentiometerSensorandFilteri_B.packet[8]);
      if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
        if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
          t_0[2] = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
        } else {
          t_0[2] = 0U;
        }
      } else {
        t_0[2] = MAX_uint8_T;
      }

      PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
        (PotentiometerSensorandFilteri_B.packet[9]);
      if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
        if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
          t_0[3] = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
        } else {
          t_0[3] = 0U;
        }
      } else {
        t_0[3] = MAX_uint8_T;
      }

      memcpy((void *)&PotentiometerSensorandFilteri_B.y, (void *)&t_0[0],
             (size_t)1 * sizeof(uint32_T));

      /* End of MATLAB Function: '<S2>/uint32_in2' */

      /* MATLAB Function: '<S2>/MATLAB Function3' */
      if (!PotentiometerSensorandFilter_DW.validpack_not_empty) {
        PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
          (PotentiometerSensorandFilteri_B.packet[2]);
        if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
          if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
            t[0] = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
          } else {
            t[0] = 0U;
          }
        } else {
          t[0] = MAX_uint8_T;
        }

        PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
          (PotentiometerSensorandFilteri_B.packet[3]);
        if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
          if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
            t[1] = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
          } else {
            t[1] = 0U;
          }
        } else {
          t[1] = MAX_uint8_T;
        }

        memcpy((void *)&PotentiometerSensorandFilter_DW.validpack, (void *)&t[0],
               (size_t)1 * sizeof(int16_T));
        PotentiometerSensorandFilter_DW.validpack_not_empty = true;
      }

      if (!PotentiometerSensorandFilter_DW.validpack2_not_empty) {
        PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
          (PotentiometerSensorandFilteri_B.packet[4]);
        if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
          if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
            t[0] = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
          } else {
            t[0] = 0U;
          }
        } else {
          t[0] = MAX_uint8_T;
        }

        PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
          (PotentiometerSensorandFilteri_B.packet[5]);
        if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
          if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
            t[1] = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
          } else {
            t[1] = 0U;
          }
        } else {
          t[1] = MAX_uint8_T;
        }

        memcpy((void *)&PotentiometerSensorandFilter_DW.validpack2, (void *)&t[0],
               (size_t)1 * sizeof(int16_T));
        PotentiometerSensorandFilter_DW.validpack2_not_empty = true;
      }

      if (PotentiometerSensorandFilteri_B.crc ==
          PotentiometerSensorandFilteri_B.y) {
        PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
          (PotentiometerSensorandFilteri_B.packet[2]);
        if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
          if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
            t[0] = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
          } else {
            t[0] = 0U;
          }
        } else {
          t[0] = MAX_uint8_T;
        }

        PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
          (PotentiometerSensorandFilteri_B.packet[3]);
        if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
          if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
            t[1] = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
          } else {
            t[1] = 0U;
          }
        } else {
          t[1] = MAX_uint8_T;
        }

        memcpy((void *)&PotentiometerSensorandFilter_DW.validpack, (void *)&t[0],
               (size_t)1 * sizeof(int16_T));
        PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
          (PotentiometerSensorandFilteri_B.packet[4]);
        if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
          if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
            t[0] = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
          } else {
            t[0] = 0U;
          }
        } else {
          t[0] = MAX_uint8_T;
        }

        PotentiometerSensorandFilteri_B.b_r = rt_roundd_snf
          (PotentiometerSensorandFilteri_B.packet[5]);
        if (PotentiometerSensorandFilteri_B.b_r < 256.0) {
          if (PotentiometerSensorandFilteri_B.b_r >= 0.0) {
            t[1] = (uint8_T)PotentiometerSensorandFilteri_B.b_r;
          } else {
            t[1] = 0U;
          }
        } else {
          t[1] = MAX_uint8_T;
        }

        memcpy((void *)&PotentiometerSensorandFilter_DW.validpack2, (void *)&t[0],
               (size_t)1 * sizeof(int16_T));
      }

      /* End of MATLAB Function: '<S2>/MATLAB Function3' */

      /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
       *  DataTypeConversion: '<S9>/Data Type Conversion'
       */
      PotentiometerSensorandFilteri_B.DataTypeConversion =
        PotentiometerSensorandFilter_DW.validpack;

      /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
       *  Constant: '<S1>/Constant1'
       */
      PotentiometerSensorandFilteri_B.b_r = floor
        (PotentiometerSensorandFilteri_P.Constant1_Value);
      if (rtIsNaN(PotentiometerSensorandFilteri_B.b_r) || rtIsInf
          (PotentiometerSensorandFilteri_B.b_r)) {
        PotentiometerSensorandFilteri_B.b_r = 0.0;
      } else {
        PotentiometerSensorandFilteri_B.b_r = fmod
          (PotentiometerSensorandFilteri_B.b_r, 256.0);
      }

      rtb_DataTypeConversion = (uint8_T)(PotentiometerSensorandFilteri_B.b_r <
        0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)
        -PotentiometerSensorandFilteri_B.b_r : (int32_T)(uint8_T)
        PotentiometerSensorandFilteri_B.b_r);

      /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

      /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
       *  Constant: '<S1>/Constant2'
       */
      PotentiometerSensorandFilteri_B.b_r = floor
        (PotentiometerSensorandFilteri_P.Constant2_Value);
      if (rtIsNaN(PotentiometerSensorandFilteri_B.b_r) || rtIsInf
          (PotentiometerSensorandFilteri_B.b_r)) {
        PotentiometerSensorandFilteri_B.b_r = 0.0;
      } else {
        PotentiometerSensorandFilteri_B.b_r = fmod
          (PotentiometerSensorandFilteri_B.b_r, 256.0);
      }

      status = (uint8_T)(PotentiometerSensorandFilteri_B.b_r < 0.0 ? (int32_T)
                         (uint8_T)-(int8_T)(uint8_T)
                         -PotentiometerSensorandFilteri_B.b_r : (int32_T)
                         (uint8_T)PotentiometerSensorandFilteri_B.b_r);

      /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

      /* DataTypeConversion: '<S1>/Data Type Conversion4' incorporates:
       *  Constant: '<Root>/Constant'
       */
      PotentiometerSensorandFilteri_B.b_r = floor
        (PotentiometerSensorandFilteri_P.Constant_Value);
      if (rtIsNaN(PotentiometerSensorandFilteri_B.b_r) || rtIsInf
          (PotentiometerSensorandFilteri_B.b_r)) {
        PotentiometerSensorandFilteri_B.b_r = 0.0;
      } else {
        PotentiometerSensorandFilteri_B.b_r = fmod
          (PotentiometerSensorandFilteri_B.b_r, 256.0);
      }

      rtb_DataTypeConversion4 = (uint8_T)(PotentiometerSensorandFilteri_B.b_r <
        0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)
        -PotentiometerSensorandFilteri_B.b_r : (int32_T)(uint8_T)
        PotentiometerSensorandFilteri_B.b_r);

      /* End of DataTypeConversion: '<S1>/Data Type Conversion4' */

      /* Saturate: '<S1>/Saturation1' incorporates:
       *  Constant: '<Root>/Constant'
       */
      if (PotentiometerSensorandFilteri_P.Constant_Value >
          PotentiometerSensorandFilteri_P.Saturation1_UpperSat) {
        PotentiometerSensorandFilteri_B.b_r =
          PotentiometerSensorandFilteri_P.Saturation1_UpperSat;
      } else if (PotentiometerSensorandFilteri_P.Constant_Value <
                 PotentiometerSensorandFilteri_P.Saturation1_LowerSat) {
        PotentiometerSensorandFilteri_B.b_r =
          PotentiometerSensorandFilteri_P.Saturation1_LowerSat;
      } else {
        PotentiometerSensorandFilteri_B.b_r =
          PotentiometerSensorandFilteri_P.Constant_Value;
      }

      /* DataTypeConversion: '<S1>/Data Type Conversion7' incorporates:
       *  Saturate: '<S1>/Saturation1'
       */
      PotentiometerSensorandFilteri_B.b_r = floor
        (PotentiometerSensorandFilteri_B.b_r);
      if (rtIsNaN(PotentiometerSensorandFilteri_B.b_r) || rtIsInf
          (PotentiometerSensorandFilteri_B.b_r)) {
        PotentiometerSensorandFilteri_B.b_r = 0.0;
      } else {
        PotentiometerSensorandFilteri_B.b_r = fmod
          (PotentiometerSensorandFilteri_B.b_r, 65536.0);
      }

      rtb_DataTypeConversion7 = (int16_T)(PotentiometerSensorandFilteri_B.b_r <
        0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
        -PotentiometerSensorandFilteri_B.b_r : (int32_T)(int16_T)(uint16_T)
        PotentiometerSensorandFilteri_B.b_r);

      /* End of DataTypeConversion: '<S1>/Data Type Conversion7' */

      /* MATLAB Function: '<S1>/uint16_in1' */
      memcpy((void *)&t[0], (void *)&rtb_DataTypeConversion7, (size_t)2 * sizeof
             (uint8_T));

      /* SignalConversion generated from: '<S3>/ SFunction ' incorporates:
       *  MATLAB Function: '<S1>/MATLAB Function'
       *  MATLAB Function: '<S1>/uint16_in1'
       */
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSFunct[0] =
        rtb_DataTypeConversion;
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSFunct[1] = status;
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSFunct[2] =
        rtb_DataTypeConversion4;
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSFunct[3] = t[0];
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSFunct[4] = t[1];

      /* MATLAB Function: '<S1>/MATLAB Function' */
      qY = MAX_uint32_T;
      for (i = 0; i < 5; i++) {
        qY ^= (uint32_T)
          PotentiometerSensorandFilteri_B.TmpSignalConversionAtSFunct[i] << 24;
        for (j = 0; j < 8; j++) {
          xfi = (int32_T)(qY >> 31);
          qY <<= 1;
          if (xfi == 1) {
            qY ^= 79764919U;
          }
        }
      }

      /* MATLAB Function: '<S1>/uint32_in' incorporates:
       *  MATLAB Function: '<S1>/MATLAB Function'
       */
      memcpy((void *)&t_0[0], (void *)&qY, (size_t)4 * sizeof(uint8_T));

      /* SignalConversion generated from: '<S1>/Serial Write' incorporates:
       *  MATLAB Function: '<S1>/uint16_in1'
       *  MATLAB Function: '<S1>/uint32_in'
       */
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSerial[0] =
        rtb_DataTypeConversion;
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSerial[1] = status;
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSerial[2] =
        rtb_DataTypeConversion4;
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSerial[3] = t[0];
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSerial[4] = t[1];
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSerial[5] = t_0[0];
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSerial[6] = t_0[1];
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSerial[7] = t_0[2];
      PotentiometerSensorandFilteri_B.TmpSignalConversionAtSerial[8] = t_0[3];

      /* MATLABSystem: '<S1>/Serial Write' */
      memcpy((void *)&PotentiometerSensorandFilteri_B.TxDataLocChar[0], (void *)
             &PotentiometerSensorandFilteri_B.TmpSignalConversionAtSerial[0],
             (size_t)9 * sizeof(uint8_T));
      MW_SCI_Transmit(PotentiometerSensorandFilter_DW.obj_l.MW_SCIHANDLE,
                      &PotentiometerSensorandFilteri_B.TxDataLocChar[0], 9U);
    }

    /* TransferFcn: '<Root>/Derivative Filter' */
    PotentiometerSensorandFilteri_B.DerivativeFilter = 0.0;
    PotentiometerSensorandFilteri_B.DerivativeFilter +=
      PotentiometerSensorandFilteri_P.DerivativeFilter_C *
      PotentiometerSensorandFilteri_X.DerivativeFilter_CSTATE;
    if (rtmIsMajorTimeStep(PotentiometerSensorandFilter_M)) {
    }

    /* TransferFcn: '<Root>/Filter' */
    PotentiometerSensorandFilteri_B.Filter = 0.0;
    PotentiometerSensorandFilteri_B.Filter +=
      PotentiometerSensorandFilteri_P.Filter_C *
      PotentiometerSensorandFilteri_X.Filter_CSTATE;
    if (rtmIsMajorTimeStep(PotentiometerSensorandFilter_M)) {
    }

    /* Derivative: '<Root>/Derivative Block' */
    PotentiometerSensorandFilteri_B.b_r =
      PotentiometerSensorandFilter_M->Timing.t[0];
    if ((PotentiometerSensorandFilter_DW.TimeStampA >=
         PotentiometerSensorandFilteri_B.b_r) &&
        (PotentiometerSensorandFilter_DW.TimeStampB >=
         PotentiometerSensorandFilteri_B.b_r)) {
      /* Derivative: '<Root>/Derivative Block' */
      PotentiometerSensorandFilteri_B.DerivativeBlock = 0.0;
    } else {
      PotentiometerSensorandFilteri_B.lastTime =
        PotentiometerSensorandFilter_DW.TimeStampA;
      lastU = &PotentiometerSensorandFilter_DW.LastUAtTimeA;
      if (PotentiometerSensorandFilter_DW.TimeStampA <
          PotentiometerSensorandFilter_DW.TimeStampB) {
        if (PotentiometerSensorandFilter_DW.TimeStampB <
            PotentiometerSensorandFilteri_B.b_r) {
          PotentiometerSensorandFilteri_B.lastTime =
            PotentiometerSensorandFilter_DW.TimeStampB;
          lastU = &PotentiometerSensorandFilter_DW.LastUAtTimeB;
        }
      } else if (PotentiometerSensorandFilter_DW.TimeStampA >=
                 PotentiometerSensorandFilteri_B.b_r) {
        PotentiometerSensorandFilteri_B.lastTime =
          PotentiometerSensorandFilter_DW.TimeStampB;
        lastU = &PotentiometerSensorandFilter_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative Block' */
      PotentiometerSensorandFilteri_B.DerivativeBlock =
        (PotentiometerSensorandFilteri_B.Filter - *lastU) /
        (PotentiometerSensorandFilteri_B.b_r -
         PotentiometerSensorandFilteri_B.lastTime);
    }

    /* End of Derivative: '<Root>/Derivative Block' */
    if (rtmIsMajorTimeStep(PotentiometerSensorandFilter_M)) {
    }
  }

  if (rtmIsMajorTimeStep(PotentiometerSensorandFilter_M)) {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative Block' */
    if (PotentiometerSensorandFilter_DW.TimeStampA == (rtInf)) {
      PotentiometerSensorandFilter_DW.TimeStampA =
        PotentiometerSensorandFilter_M->Timing.t[0];
      lastU = &PotentiometerSensorandFilter_DW.LastUAtTimeA;
    } else if (PotentiometerSensorandFilter_DW.TimeStampB == (rtInf)) {
      PotentiometerSensorandFilter_DW.TimeStampB =
        PotentiometerSensorandFilter_M->Timing.t[0];
      lastU = &PotentiometerSensorandFilter_DW.LastUAtTimeB;
    } else if (PotentiometerSensorandFilter_DW.TimeStampA <
               PotentiometerSensorandFilter_DW.TimeStampB) {
      PotentiometerSensorandFilter_DW.TimeStampA =
        PotentiometerSensorandFilter_M->Timing.t[0];
      lastU = &PotentiometerSensorandFilter_DW.LastUAtTimeA;
    } else {
      PotentiometerSensorandFilter_DW.TimeStampB =
        PotentiometerSensorandFilter_M->Timing.t[0];
      lastU = &PotentiometerSensorandFilter_DW.LastUAtTimeB;
    }

    *lastU = PotentiometerSensorandFilteri_B.Filter;

    /* End of Update for Derivative: '<Root>/Derivative Block' */
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        PotentiometerSensorandFilter_M->Timing.t[0];

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(PotentiometerSensorandFilter_M)) {/* Sample time: [0.004s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((PotentiometerSensorandFilter_M->Timing.clockTick1) * 0.004);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(PotentiometerSensorandFilter_M)) {
    rt_ertODEUpdateContinuousStates(&PotentiometerSensorandFilter_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++PotentiometerSensorandFilter_M->Timing.clockTick0;
    PotentiometerSensorandFilter_M->Timing.t[0] = rtsiGetSolverStopTime
      (&PotentiometerSensorandFilter_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.004s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.004, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PotentiometerSensorandFilter_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void PotentiometerSensorandFiltering23_derivatives(void)
{
  XDot_PotentiometerSensorandFi_T *_rtXdot;
  _rtXdot = ((XDot_PotentiometerSensorandFi_T *)
             PotentiometerSensorandFilter_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Derivative Filter' */
  _rtXdot->DerivativeFilter_CSTATE =
    PotentiometerSensorandFilteri_P.DerivativeFilter_A *
    PotentiometerSensorandFilteri_X.DerivativeFilter_CSTATE;
  _rtXdot->DerivativeFilter_CSTATE +=
    PotentiometerSensorandFilteri_B.DerivativeBlock;

  /* Derivatives for TransferFcn: '<Root>/Filter' */
  _rtXdot->Filter_CSTATE = PotentiometerSensorandFilteri_P.Filter_A *
    PotentiometerSensorandFilteri_X.Filter_CSTATE;
  _rtXdot->Filter_CSTATE += PotentiometerSensorandFilteri_B.DataTypeConversion;
}

/* Model initialize function */
void PotentiometerSensorandFiltering23_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PotentiometerSensorandFilter_M, 0,
                sizeof(RT_MODEL_PotentiometerSensora_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PotentiometerSensorandFilter_M->solverInfo,
                          &PotentiometerSensorandFilter_M->Timing.simTimeStep);
    rtsiSetTPtr(&PotentiometerSensorandFilter_M->solverInfo, &rtmGetTPtr
                (PotentiometerSensorandFilter_M));
    rtsiSetStepSizePtr(&PotentiometerSensorandFilter_M->solverInfo,
                       &PotentiometerSensorandFilter_M->Timing.stepSize0);
    rtsiSetdXPtr(&PotentiometerSensorandFilter_M->solverInfo,
                 &PotentiometerSensorandFilter_M->derivs);
    rtsiSetContStatesPtr(&PotentiometerSensorandFilter_M->solverInfo, (real_T **)
                         &PotentiometerSensorandFilter_M->contStates);
    rtsiSetNumContStatesPtr(&PotentiometerSensorandFilter_M->solverInfo,
      &PotentiometerSensorandFilter_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PotentiometerSensorandFilter_M->solverInfo,
      &PotentiometerSensorandFilter_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&PotentiometerSensorandFilter_M->solverInfo,
       &PotentiometerSensorandFilter_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&PotentiometerSensorandFilter_M->solverInfo,
       &PotentiometerSensorandFilter_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&PotentiometerSensorandFilter_M->solverInfo,
      (boolean_T**) &PotentiometerSensorandFilter_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&PotentiometerSensorandFilter_M->solverInfo,
                          (&rtmGetErrorStatus(PotentiometerSensorandFilter_M)));
    rtsiSetRTModelPtr(&PotentiometerSensorandFilter_M->solverInfo,
                      PotentiometerSensorandFilter_M);
  }

  rtsiSetSimTimeStep(&PotentiometerSensorandFilter_M->solverInfo,
                     MAJOR_TIME_STEP);
  PotentiometerSensorandFilter_M->intgData.deltaY=
    PotentiometerSensorandFilter_M->OdeDeltaY;
  PotentiometerSensorandFilter_M->intgData.f[0] =
    PotentiometerSensorandFilter_M->odeF[0];
  PotentiometerSensorandFilter_M->intgData.f[1] =
    PotentiometerSensorandFilter_M->odeF[1];
  PotentiometerSensorandFilter_M->intgData.f[2] =
    PotentiometerSensorandFilter_M->odeF[2];
  PotentiometerSensorandFilter_M->intgData.f[3] =
    PotentiometerSensorandFilter_M->odeF[3];
  PotentiometerSensorandFilter_M->intgData.f[4] =
    PotentiometerSensorandFilter_M->odeF[4];
  PotentiometerSensorandFilter_M->intgData.f[5] =
    PotentiometerSensorandFilter_M->odeF[5];
  PotentiometerSensorandFilter_M->intgData.f[6] =
    PotentiometerSensorandFilter_M->odeF[6];
  PotentiometerSensorandFilter_M->intgData.f[7] =
    PotentiometerSensorandFilter_M->odeF[7];
  PotentiometerSensorandFilter_M->intgData.f[8] =
    PotentiometerSensorandFilter_M->odeF[8];
  PotentiometerSensorandFilter_M->intgData.f[9] =
    PotentiometerSensorandFilter_M->odeF[9];
  PotentiometerSensorandFilter_M->intgData.f[10] =
    PotentiometerSensorandFilter_M->odeF[10];
  PotentiometerSensorandFilter_M->intgData.f[11] =
    PotentiometerSensorandFilter_M->odeF[11];
  PotentiometerSensorandFilter_M->intgData.f[12] =
    PotentiometerSensorandFilter_M->odeF[12];
  PotentiometerSensorandFilter_M->intgData.x0 =
    PotentiometerSensorandFilter_M->odeX0;
  PotentiometerSensorandFilter_M->contStates = ((X_PotentiometerSensorandFilte_T
    *) &PotentiometerSensorandFilteri_X);
  PotentiometerSensorandFilter_M->contStateDisabled =
    ((XDis_PotentiometerSensorandFi_T *) &PotentiometerSensorandFilt_XDis);
  PotentiometerSensorandFilter_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&PotentiometerSensorandFilter_M->solverInfo, (void *)
                    &PotentiometerSensorandFilter_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange
    (&PotentiometerSensorandFilter_M->solverInfo, false);
  rtsiSetSolverName(&PotentiometerSensorandFilter_M->solverInfo,"ode8");
  rtmSetTPtr(PotentiometerSensorandFilter_M,
             &PotentiometerSensorandFilter_M->Timing.tArray[0]);
  rtmSetTFinal(PotentiometerSensorandFilter_M, -1);
  PotentiometerSensorandFilter_M->Timing.stepSize0 = 0.004;

  /* External mode info */
  PotentiometerSensorandFilter_M->Sizes.checksums[0] = (2952891506U);
  PotentiometerSensorandFilter_M->Sizes.checksums[1] = (3580181539U);
  PotentiometerSensorandFilter_M->Sizes.checksums[2] = (2882362821U);
  PotentiometerSensorandFilter_M->Sizes.checksums[3] = (52695799U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    PotentiometerSensorandFilter_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(PotentiometerSensorandFilter_M->extModeInfo,
      &PotentiometerSensorandFilter_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PotentiometerSensorandFilter_M->extModeInfo,
                        PotentiometerSensorandFilter_M->Sizes.checksums);
    rteiSetTPtr(PotentiometerSensorandFilter_M->extModeInfo, rtmGetTPtr
                (PotentiometerSensorandFilter_M));
  }

  /* block I/O */
  (void) memset(((void *) &PotentiometerSensorandFilteri_B), 0,
                sizeof(B_PotentiometerSensorandFilte_T));

  /* states (continuous) */
  {
    (void) memset((void *)&PotentiometerSensorandFilteri_X, 0,
                  sizeof(X_PotentiometerSensorandFilte_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&PotentiometerSensorandFilt_XDis, 0,
                  sizeof(XDis_PotentiometerSensorandFi_T));
  }

  /* states (dwork) */
  (void) memset((void *)&PotentiometerSensorandFilter_DW, 0,
                sizeof(DW_PotentiometerSensorandFilt_T));

  /* InitializeConditions for TransferFcn: '<Root>/Derivative Filter' */
  PotentiometerSensorandFilteri_X.DerivativeFilter_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Filter' */
  PotentiometerSensorandFilteri_X.Filter_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative Block' */
  PotentiometerSensorandFilter_DW.TimeStampA = (rtInf);
  PotentiometerSensorandFilter_DW.TimeStampB = (rtInf);
  PotentiometerSensorandFilter_DW.bff.size = 0;

  /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function1' */
  PotentiometerSensorandFilter_DW.val_not_empty = false;
  PotentiometerSensorandFilter_DW.bff_not_empty = false;
  PotentiometerSensorandFilter_DW.val = 0.0;

  /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function3' */
  PotentiometerSensorandFilter_DW.validpack_not_empty = false;
  PotentiometerSensorandFilter_DW.validpack2_not_empty = false;

  /* Start for MATLABSystem: '<S2>/Serial Read' */
  PotentiometerSensorandFilter_DW.obj.isInitialized = 0;
  PotentiometerSensorandFilter_DW.obj.matlabCodegenIsDeleted = false;
  PotentiometerSensorandFilter_DW.obj.SampleTime =
    PotentiometerSensorandFilteri_P.SerialRead_SampleTime;
  Potentiomete_SystemCore_setup_o(&PotentiometerSensorandFilter_DW.obj);

  /* Start for MATLABSystem: '<S1>/Serial Write' */
  PotentiometerSensorandFilter_DW.obj_l.isInitialized = 0;
  PotentiometerSensorandFilter_DW.obj_l.matlabCodegenIsDeleted = false;
  PotentiometerS_SystemCore_setup(&PotentiometerSensorandFilter_DW.obj_l);
}

/* Model terminate function */
void PotentiometerSensorandFiltering23_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Serial Read' */
  if (!PotentiometerSensorandFilter_DW.obj.matlabCodegenIsDeleted) {
    PotentiometerSensorandFilter_DW.obj.matlabCodegenIsDeleted = true;
    if ((PotentiometerSensorandFilter_DW.obj.isInitialized == 1) &&
        PotentiometerSensorandFilter_DW.obj.isSetupComplete) {
      MW_SCI_Close(PotentiometerSensorandFilter_DW.obj.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Read' */
  /* Terminate for MATLABSystem: '<S1>/Serial Write' */
  if (!PotentiometerSensorandFilter_DW.obj_l.matlabCodegenIsDeleted) {
    PotentiometerSensorandFilter_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((PotentiometerSensorandFilter_DW.obj_l.isInitialized == 1) &&
        PotentiometerSensorandFilter_DW.obj_l.isSetupComplete) {
      MW_SCI_Close(PotentiometerSensorandFilter_DW.obj_l.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Serial Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
