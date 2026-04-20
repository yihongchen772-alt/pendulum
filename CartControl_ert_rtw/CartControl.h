/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CartControl.h
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

#ifndef RTW_HEADER_CartControl_h_
#define RTW_HEADER_CartControl_h_
#ifndef CartControl_COMMON_INCLUDES_
#define CartControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_SCI.h"
#endif                                 /* CartControl_COMMON_INCLUDES_ */

#include "CartControl_types.h"
#include "rt_nonfinite.h"
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

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
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

/* Block signals (default storage) */
typedef struct {
  int32_T tmp_data[255];
  uint8_T head_data[255];
  boolean_T tmp_data_m[255];
  uint8_T RxData[10];
  uint8_T RxDataLocChar[10];
  uint8_T TxDataLocChar[9];
  uint8_T TmpSignalConversionAtSerial[9];
  real_T DataTypeConversion2;          /* '<S14>/Data Type Conversion2' */
  real_T Product;                      /* '<S7>/Product' */
  real_T Setpointmm;                   /* '<S1>/Setpoint(mm)' */
  real_T ProportionGain;               /* '<S4>/Proportion Gain' */
  real_T DerivativeGain;               /* '<S4>/Derivative Gain' */
  real_T Gain1;                        /* '<S4>/Gain1' */
  real_T DataTypeConversion;           /* '<S14>/Data Type Conversion' */
  real_T packet[10];                   /* '<S6>/MATLAB Function1' */
  real_T torque;                       /* '<S1>/Homing Block' */
  real_T homed;                        /* '<S1>/Homing Block' */
  real_T cartPos;                      /* '<S1>/Homing Block' */
  real_T DeadZone;                     /* '<S4>/Dead Zone' */
  real_T u0;
  uint32_T y;                          /* '<S6>/uint32_in2' */
  uint32_T crc;                        /* '<S6>/MATLAB Function2' */
  int16_T rod;                         /* '<S6>/MATLAB Function3' */
} B_CartControl_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  emxArray_real_T_255_CartContr_T bff; /* '<S6>/MATLAB Function1' */
  codertarget_raspi_internal__a_T obj; /* '<S6>/Serial Read' */
  codertarget_raspi_internal_SC_T obj_m;/* '<S2>/Serial Write' */
  real_T val;                          /* '<S6>/MATLAB Function1' */
  real_T torqueval;                    /* '<S1>/Selection' */
  real_T torqueval_p;                  /* '<S1>/Homing Block' */
  real_T state;                        /* '<S1>/Homing Block' */
  real_T homeval;                      /* '<S1>/Homing Block' */
  real_T counter;                      /* '<S1>/Homing Block' */
  real_T i;                            /* '<S1>/Homing Block' */
  real_T precart;                      /* '<S1>/Homing Block' */
  real_T prepos;                       /* '<S1>/Homing Block' */
  real_T precartArray[10];             /* '<S1>/Homing Block' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int16_T validpack;                   /* '<S6>/MATLAB Function3' */
  int16_T validpack2;                  /* '<S6>/MATLAB Function3' */
  uint8_T is_active_c20_CartControl;   /* '<S6>/uint32_in2' */
  uint8_T is_active_c19_CartControl;   /* '<S6>/MATLAB Function3' */
  uint8_T is_active_c18_CartControl;   /* '<S6>/MATLAB Function2' */
  uint8_T is_active_c17_CartControl;   /* '<S6>/MATLAB Function1' */
  uint8_T packetindex[10];             /* '<S6>/MATLAB Function1' */
  uint8_T is_active_c5_CartControl;    /* '<S1>/Selection' */
  uint8_T is_active_c6_CartControl;    /* '<S1>/Homing Block' */
  uint8_T is_active_c16_CartControl;   /* '<S2>/uint32_in' */
  uint8_T is_active_c15_CartControl;   /* '<S2>/uint16_in1' */
  uint8_T is_active_c11_CartControl;   /* '<S2>/MATLAB Function' */
  boolean_T validpack_not_empty;       /* '<S6>/MATLAB Function3' */
  boolean_T validpack2_not_empty;      /* '<S6>/MATLAB Function3' */
  boolean_T val_not_empty;             /* '<S6>/MATLAB Function1' */
  boolean_T bff_not_empty;             /* '<S6>/MATLAB Function1' */
} DW_CartControl_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<S4>/Transfer Fcn' */
} X_CartControl_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<S4>/Transfer Fcn' */
} XDot_CartControl_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S4>/Integrator' */
  boolean_T TransferFcn_CSTATE;        /* '<S4>/Transfer Fcn' */
} XDis_CartControl_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_CartControl_T_ {
  real_T SerialRead_SampleTime;        /* Expression: SampleTime
                                        * Referenced by: '<S6>/Serial Read'
                                        */
  real_T Constant1_Value;              /* Expression: 85
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 191
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Enable_Value;                 /* Expression: 0
                                        * Referenced by: '<S1>/Enable '
                                        */
  real_T Mode_Value;                   /* Expression: 1
                                        * Referenced by: '<S1>/Mode'
                                        */
  real_T Constant_Value;               /* Expression: -5279
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 658
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Home_Value;                   /* Expression: 0
                                        * Referenced by: '<S1>/Home'
                                        */
  real_T Setpointmm_Value;             /* Expression: 91.31957559317379
                                        * Referenced by: '<S1>/Setpoint(mm)'
                                        */
  real_T DeadZone_Start;               /* Expression: -1
                                        * Referenced by: '<S4>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 1
                                        * Referenced by: '<S4>/Dead Zone'
                                        */
  real_T ProportionGain_Gain;          /* Expression: 117
                                        * Referenced by: '<S4>/Proportion Gain'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: 350
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: -350
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T DerivativeGain_Gain;          /* Expression: 1
                                        * Referenced by: '<S4>/Derivative Gain'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T TransferFcn_D;                /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1500
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1500
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Saturation1_UpperSat_a;       /* Expression: 1000
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_h;       /* Expression: -1000
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 20
                                        * Referenced by: '<S4>/Gain1'
                                        */
  uint8_T BufferSize_Value;            /* Computed Parameter: BufferSize_Value
                                        * Referenced by: '<S6>/Buffer Size'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S6>/Constant4'
                                        */
  uint8_T Constant1_Value_e;           /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S6>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_CartControl_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_CartControl_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_CartControl_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

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
extern P_CartControl_T CartControl_P;

/* Block signals (default storage) */
extern B_CartControl_T CartControl_B;

/* Continuous states (default storage) */
extern X_CartControl_T CartControl_X;

/* Disabled states (default storage) */
extern XDis_CartControl_T CartControl_XDis;

/* Block states (default storage) */
extern DW_CartControl_T CartControl_DW;

/* Model entry point functions */
extern void CartControl_initialize(void);
extern void CartControl_step(void);
extern void CartControl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CartControl_T *const CartControl_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'CartControl'
 * '<S1>'   : 'CartControl/Pendulum Subsystem'
 * '<S2>'   : 'CartControl/Pendulum Subsystem/DC Motor'
 * '<S3>'   : 'CartControl/Pendulum Subsystem/Homing Block'
 * '<S4>'   : 'CartControl/Pendulum Subsystem/Motion Control'
 * '<S5>'   : 'CartControl/Pendulum Subsystem/Selection'
 * '<S6>'   : 'CartControl/Pendulum Subsystem/Touchscreen'
 * '<S7>'   : 'CartControl/Pendulum Subsystem/encoder to mm'
 * '<S8>'   : 'CartControl/Pendulum Subsystem/DC Motor/MATLAB Function'
 * '<S9>'   : 'CartControl/Pendulum Subsystem/DC Motor/uint16_in1'
 * '<S10>'  : 'CartControl/Pendulum Subsystem/DC Motor/uint32_in'
 * '<S11>'  : 'CartControl/Pendulum Subsystem/Touchscreen/MATLAB Function1'
 * '<S12>'  : 'CartControl/Pendulum Subsystem/Touchscreen/MATLAB Function2'
 * '<S13>'  : 'CartControl/Pendulum Subsystem/Touchscreen/MATLAB Function3'
 * '<S14>'  : 'CartControl/Pendulum Subsystem/Touchscreen/Subsystem2'
 * '<S15>'  : 'CartControl/Pendulum Subsystem/Touchscreen/uint32_in2'
 */
#endif                                 /* RTW_HEADER_CartControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
