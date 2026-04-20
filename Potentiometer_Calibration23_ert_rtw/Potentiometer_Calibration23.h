/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Potentiometer_Calibration23.h
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

#ifndef RTW_HEADER_Potentiometer_Calibration23_h_
#define RTW_HEADER_Potentiometer_Calibration23_h_
#ifndef Potentiometer_Calibration23_COMMON_INCLUDES_
#define Potentiometer_Calibration23_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SCI.h"
#endif                        /* Potentiometer_Calibration23_COMMON_INCLUDES_ */

#include "Potentiometer_Calibration23_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  int32_T tmp_data[255];
  uint8_T head_data[255];
  boolean_T tmp_data_m[255];
  real_T VectorConcatenate[4];         /* '<Root>/Vector Concatenate' */
  real_T packet[10];                   /* '<S2>/MATLAB Function1' */
  uint8_T RxData[10];
  uint8_T RxDataLocChar[10];
  uint8_T TxDataLocChar[9];
  uint8_T TmpSignalConversionAtSerial[9];
  real_T b_r;
  real_T d;
  uint32_T y;                          /* '<S2>/uint32_in2' */
  uint32_T crc_c;                      /* '<S2>/MATLAB Function2' */
} B_Potentiometer_Calibration23_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  emxArray_real_T_255_Potentiom_T bff; /* '<S2>/MATLAB Function1' */
  codertarget_raspi_internal_SC_T obj; /* '<S2>/Serial Read' */
  codertarget_raspi_internal__m_T obj_o;/* '<S3>/Serial Write' */
  real_T val;                          /* '<S2>/MATLAB Function1' */
  real_T maxAnalog;                    /* '<Root>/MATLAB Function' */
  real_T minAnalog;                    /* '<Root>/MATLAB Function' */
  int16_T validpack;                   /* '<S2>/MATLAB Function3' */
  int16_T validpack2;                  /* '<S2>/MATLAB Function3' */
  uint8_T is_active_c16_Potentiometer_Cal;/* '<S3>/uint32_in' */
  uint8_T is_active_c15_Potentiometer_Cal;/* '<S3>/uint16_in1' */
  uint8_T is_active_c11_Potentiometer_Cal;/* '<S3>/MATLAB Function' */
  uint8_T is_active_c20_Potentiometer_Cal;/* '<S2>/uint32_in2' */
  uint8_T is_active_c19_Potentiometer_Cal;/* '<S2>/MATLAB Function3' */
  uint8_T is_active_c18_Potentiometer_Cal;/* '<S2>/MATLAB Function2' */
  uint8_T is_active_c17_Potentiometer_Cal;/* '<S2>/MATLAB Function1' */
  uint8_T packetindex[10];             /* '<S2>/MATLAB Function1' */
  uint8_T is_active_c2_Potentiometer_Cali;/* '<Root>/MATLAB Function' */
  boolean_T validpack_not_empty;       /* '<S2>/MATLAB Function3' */
  boolean_T validpack2_not_empty;      /* '<S2>/MATLAB Function3' */
  boolean_T val_not_empty;             /* '<S2>/MATLAB Function1' */
  boolean_T bff_not_empty;             /* '<S2>/MATLAB Function1' */
} DW_Potentiometer_Calibration2_T;

/* Parameters (default storage) */
struct P_Potentiometer_Calibration23_T_ {
  real_T SerialRead_SampleTime;        /* Expression: SampleTime
                                        * Referenced by: '<S2>/Serial Read'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Save_Value;                   /* Expression: 1
                                        * Referenced by: '<Root>/Save'
                                        */
  real_T Constant1_Value_h;            /* Expression: 85
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 191
                                        * Referenced by: '<S3>/Constant2'
                                        */
  uint8_T BufferSize_Value;            /* Computed Parameter: BufferSize_Value
                                        * Referenced by: '<S2>/Buffer Size'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S2>/Constant4'
                                        */
  uint8_T Constant1_Value_k;           /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S2>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Potentiometer_Calibra_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Potentiometer_Calibration23_T Potentiometer_Calibration23_P;

/* Block signals (default storage) */
extern B_Potentiometer_Calibration23_T Potentiometer_Calibration23_B;

/* Block states (default storage) */
extern DW_Potentiometer_Calibration2_T Potentiometer_Calibration23_DW;

/* Model entry point functions */
extern void Potentiometer_Calibration23_initialize(void);
extern void Potentiometer_Calibration23_step(void);
extern void Potentiometer_Calibration23_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Potentiometer_Calibr_T *const Potentiometer_Calibration23_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Data Type Conversion2' : Unused code path elimination
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion5' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Potentiometer_Calibration23'
 * '<S1>'   : 'Potentiometer_Calibration23/MATLAB Function'
 * '<S2>'   : 'Potentiometer_Calibration23/Read from System'
 * '<S3>'   : 'Potentiometer_Calibration23/Write to Motor'
 * '<S4>'   : 'Potentiometer_Calibration23/Read from System/MATLAB Function1'
 * '<S5>'   : 'Potentiometer_Calibration23/Read from System/MATLAB Function2'
 * '<S6>'   : 'Potentiometer_Calibration23/Read from System/MATLAB Function3'
 * '<S7>'   : 'Potentiometer_Calibration23/Read from System/Subsystem2'
 * '<S8>'   : 'Potentiometer_Calibration23/Read from System/uint32_in2'
 * '<S9>'   : 'Potentiometer_Calibration23/Write to Motor/MATLAB Function'
 * '<S10>'  : 'Potentiometer_Calibration23/Write to Motor/uint16_in1'
 * '<S11>'  : 'Potentiometer_Calibration23/Write to Motor/uint32_in'
 */
#endif                           /* RTW_HEADER_Potentiometer_Calibration23_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
