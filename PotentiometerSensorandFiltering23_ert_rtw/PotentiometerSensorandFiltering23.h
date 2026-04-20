/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PotentiometerSensorandFiltering23.h
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

#ifndef RTW_HEADER_PotentiometerSensorandFiltering23_h_
#define RTW_HEADER_PotentiometerSensorandFiltering23_h_
#ifndef PotentiometerSensorandFiltering23_COMMON_INCLUDES_
#define PotentiometerSensorandFiltering23_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_SCI.h"
#endif                  /* PotentiometerSensorandFiltering23_COMMON_INCLUDES_ */

#include "PotentiometerSensorandFiltering23_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeDeltaY
#define rtmGetOdeDeltaY(rtm)           ((rtm)->OdeDeltaY)
#endif

#ifndef rtmSetOdeDeltaY
#define rtmSetOdeDeltaY(rtm, val)      ((rtm)->OdeDeltaY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeX0
#define rtmGetOdeX0(rtm)               ((rtm)->odeX0)
#endif

#ifndef rtmSetOdeX0
#define rtmSetOdeX0(rtm, val)          ((rtm)->odeX0 = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#define PotentiometerSensorandFiltering23_M (PotentiometerSensorandFilter_M)

/* Block signals (default storage) */
typedef struct {
  int32_T tmp_data[255];
  uint8_T head_data[255];
  boolean_T tmp_data_m[255];
  uint8_T RxData[10];
  uint8_T RxDataLocChar[10];
  uint8_T TxDataLocChar[9];
  uint8_T TmpSignalConversionAtSerial[9];
  real_T DataTypeConversion;           /* '<Root>/Data Type Conversion' */
  real_T DerivativeFilter;             /* '<Root>/Derivative Filter' */
  real_T Filter;                       /* '<Root>/Filter' */
  real_T DerivativeBlock;              /* '<Root>/Derivative Block' */
  real_T packet[10];                   /* '<S2>/MATLAB Function1' */
  real_T lastTime;
  real_T b_r;
  uint8_T TmpSignalConversionAtSFunct[5];/* '<S1>/MATLAB Function' */
  uint32_T y;                          /* '<S2>/uint32_in2' */
  uint32_T crc;                        /* '<S2>/MATLAB Function2' */
} B_PotentiometerSensorandFilte_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  emxArray_real_T_255_Potentiom_T bff; /* '<S2>/MATLAB Function1' */
  codertarget_raspi_internal__o_T obj; /* '<S2>/Serial Read' */
  codertarget_raspi_internal_SC_T obj_l;/* '<S1>/Serial Write' */
  real_T TimeStampA;                   /* '<Root>/Derivative Block' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative Block' */
  real_T TimeStampB;                   /* '<Root>/Derivative Block' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative Block' */
  real_T val;                          /* '<S2>/MATLAB Function1' */
  struct {
    void *LoggedData;
  } RodPositionWithoutFilter_PWORK;   /* '<Root>/Rod Position Without Filter' */

  struct {
    void *LoggedData;
  } DerivativeWithFilter_PWORK;        /* '<Root>/Derivative With Filter' */

  struct {
    void *LoggedData;
  } RodPositionWithFilter_PWORK;       /* '<Root>/Rod Position With Filter' */

  struct {
    void *LoggedData;
  } DerivativeWithoutFilter_PWORK;     /* '<Root>/Derivative Without Filter' */

  int16_T validpack;                   /* '<S2>/MATLAB Function3' */
  int16_T validpack2;                  /* '<S2>/MATLAB Function3' */
  uint8_T is_active_c20_PotentiometerSens;/* '<S2>/uint32_in2' */
  uint8_T is_active_c19_PotentiometerSens;/* '<S2>/MATLAB Function3' */
  uint8_T is_active_c18_PotentiometerSens;/* '<S2>/MATLAB Function2' */
  uint8_T is_active_c17_PotentiometerSens;/* '<S2>/MATLAB Function1' */
  uint8_T packetindex[10];             /* '<S2>/MATLAB Function1' */
  uint8_T is_active_c16_PotentiometerSens;/* '<S1>/uint32_in' */
  uint8_T is_active_c15_PotentiometerSens;/* '<S1>/uint16_in1' */
  uint8_T is_active_c11_PotentiometerSens;/* '<S1>/MATLAB Function' */
  boolean_T validpack_not_empty;       /* '<S2>/MATLAB Function3' */
  boolean_T validpack2_not_empty;      /* '<S2>/MATLAB Function3' */
  boolean_T val_not_empty;             /* '<S2>/MATLAB Function1' */
  boolean_T bff_not_empty;             /* '<S2>/MATLAB Function1' */
} DW_PotentiometerSensorandFilt_T;

/* Continuous states (default storage) */
typedef struct {
  real_T DerivativeFilter_CSTATE;      /* '<Root>/Derivative Filter' */
  real_T Filter_CSTATE;                /* '<Root>/Filter' */
} X_PotentiometerSensorandFilte_T;

/* State derivatives (default storage) */
typedef struct {
  real_T DerivativeFilter_CSTATE;      /* '<Root>/Derivative Filter' */
  real_T Filter_CSTATE;                /* '<Root>/Filter' */
} XDot_PotentiometerSensorandFi_T;

/* State disabled  */
typedef struct {
  boolean_T DerivativeFilter_CSTATE;   /* '<Root>/Derivative Filter' */
  boolean_T Filter_CSTATE;             /* '<Root>/Filter' */
} XDis_PotentiometerSensorandFi_T;

#ifndef ODE8_INTG
#define ODE8_INTG

/* ODE8 Integration Data */
typedef struct {
  real_T *deltaY;                      /* output diff */
  real_T *f[13];                       /* derivatives */
  real_T *x0;                          /* Initial State */
} ODE8_IntgData;

#endif

/* Parameters (default storage) */
struct P_PotentiometerSensorandFilte_T_ {
  real_T SerialRead_SampleTime;        /* Expression: SampleTime
                                        * Referenced by: '<S2>/Serial Read'
                                        */
  real_T Constant1_Value;              /* Expression: 85
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 191
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1000
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1000
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T DerivativeFilter_A;           /* Computed Parameter: DerivativeFilter_A
                                        * Referenced by: '<Root>/Derivative Filter'
                                        */
  real_T DerivativeFilter_C;           /* Computed Parameter: DerivativeFilter_C
                                        * Referenced by: '<Root>/Derivative Filter'
                                        */
  real_T Filter_A;                     /* Computed Parameter: Filter_A
                                        * Referenced by: '<Root>/Filter'
                                        */
  real_T Filter_C;                     /* Computed Parameter: Filter_C
                                        * Referenced by: '<Root>/Filter'
                                        */
  uint8_T BufferSize_Value;            /* Computed Parameter: BufferSize_Value
                                        * Referenced by: '<S2>/Buffer Size'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S2>/Constant4'
                                        */
  uint8_T Constant1_Value_g;           /* Computed Parameter: Constant1_Value_g
                                        * Referenced by: '<S2>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PotentiometerSensoran_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_PotentiometerSensorandFilte_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_PotentiometerSensorandFi_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T OdeDeltaY[2];
  real_T odeF[13][2];
  real_T odeX0[2];
  ODE8_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_PotentiometerSensorandFilte_T PotentiometerSensorandFilteri_P;

/* Block signals (default storage) */
extern B_PotentiometerSensorandFilte_T PotentiometerSensorandFilteri_B;

/* Continuous states (default storage) */
extern X_PotentiometerSensorandFilte_T PotentiometerSensorandFilteri_X;

/* Disabled states (default storage) */
extern XDis_PotentiometerSensorandFi_T PotentiometerSensorandFilt_XDis;

/* Block states (default storage) */
extern DW_PotentiometerSensorandFilt_T PotentiometerSensorandFilter_DW;

/* Model entry point functions */
extern void PotentiometerSensorandFiltering23_initialize(void);
extern void PotentiometerSensorandFiltering23_step(void);
extern void PotentiometerSensorandFiltering23_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PotentiometerSensora_T *const PotentiometerSensorandFilter_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/Data Type Conversion2' : Unused code path elimination
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion5' : Eliminate redundant data type conversion
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
 * '<Root>' : 'PotentiometerSensorandFiltering23'
 * '<S1>'   : 'PotentiometerSensorandFiltering23/DC Motor'
 * '<S2>'   : 'PotentiometerSensorandFiltering23/Touchscreen'
 * '<S3>'   : 'PotentiometerSensorandFiltering23/DC Motor/MATLAB Function'
 * '<S4>'   : 'PotentiometerSensorandFiltering23/DC Motor/uint16_in1'
 * '<S5>'   : 'PotentiometerSensorandFiltering23/DC Motor/uint32_in'
 * '<S6>'   : 'PotentiometerSensorandFiltering23/Touchscreen/MATLAB Function1'
 * '<S7>'   : 'PotentiometerSensorandFiltering23/Touchscreen/MATLAB Function2'
 * '<S8>'   : 'PotentiometerSensorandFiltering23/Touchscreen/MATLAB Function3'
 * '<S9>'   : 'PotentiometerSensorandFiltering23/Touchscreen/Subsystem2'
 * '<S10>'  : 'PotentiometerSensorandFiltering23/Touchscreen/uint32_in2'
 */
#endif                     /* RTW_HEADER_PotentiometerSensorandFiltering23_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
