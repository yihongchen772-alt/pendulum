/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PendulumQuickStart23.h
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

#ifndef RTW_HEADER_PendulumQuickStart23_h_
#define RTW_HEADER_PendulumQuickStart23_h_
#ifndef PendulumQuickStart23_COMMON_INCLUDES_
#define PendulumQuickStart23_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_SCI.h"
#endif                               /* PendulumQuickStart23_COMMON_INCLUDES_ */

#include "PendulumQuickStart23_types.h"
#include <math.h>
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
  real_T DataTypeConversion;           /* '<S26>/Data Type Conversion' */
  real_T FromWorkspace[3];             /* '<S12>/From Workspace' */
  real_T Divide3;                      /* '<S12>/Divide3' */
  real_T Merge;                        /* '<S12>/Merge' */
  real_T Divide1;                      /* '<S12>/Divide1' */
  real_T Subtract1;                    /* '<S12>/Subtract1' */
  real_T Gain;                         /* '<S5>/Gain' */
  real_T DeadZone;                     /* '<S11>/Dead Zone' */
  real_T Gain4;                        /* '<S11>/Gain4' */
  real_T Saturation;                   /* '<S11>/Saturation' */
  real_T Saturation1;                  /* '<S11>/Saturation1' */
  real_T Merge_p;                      /* '<S17>/Merge' */
  real_T packet[10];                   /* '<S9>/MATLAB Function1' */
  real_T torqueOut;                    /* '<S1>/Selection' */
  real_T homedOut;                     /* '<S1>/Move to Center' */
  real_T torqueOut_b;                  /* '<S1>/Move to Center' */
  real_T PWMOut;                       /* '<S1>/MATLAB Function' */
  real_T torque;                       /* '<S1>/Homing Block' */
  real_T homed;                        /* '<S1>/Homing Block' */
  real_T cartPos;                      /* '<S1>/Homing Block' */
  uint32_T y;                          /* '<S9>/uint32_in2' */
  uint32_T crc;                        /* '<S9>/MATLAB Function2' */
  uint8_T DataTypeConversion_h;        /* '<S7>/Data Type Conversion' */
  uint8_T DataTypeConversion1;         /* '<S7>/Data Type Conversion1' */
} B_PendulumQuickStart23_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  emxArray_real_T_255_PendulumQ_T bff; /* '<S9>/MATLAB Function1' */
  codertarget_raspi_internal__a_T obj; /* '<S9>/Serial Read' */
  codertarget_raspi_internal_SC_T obj_o;/* '<S7>/Serial Write' */
  real_T val;                          /* '<S9>/MATLAB Function1' */
  real_T torqueval;                    /* '<S1>/Selection' */
  real_T kp;                           /* '<S1>/Move to Center' */
  real_T set_pos;                      /* '<S1>/Move to Center' */
  real_T torqueval_e;                  /* '<S1>/Homing Block' */
  real_T state;                        /* '<S1>/Homing Block' */
  real_T homeval;                      /* '<S1>/Homing Block' */
  real_T counter;                      /* '<S1>/Homing Block' */
  real_T i;                            /* '<S1>/Homing Block' */
  real_T precart;                      /* '<S1>/Homing Block' */
  real_T prepos;                       /* '<S1>/Homing Block' */
  real_T precartArray[10];             /* '<S1>/Homing Block' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S12>/From Workspace' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S11>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<S11>/Scope4' */

  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S12>/From Workspace' */

  int16_T validpack;                   /* '<S9>/MATLAB Function3' */
  int16_T validpack2;                  /* '<S9>/MATLAB Function3' */
  int8_T If_ActiveSubsystem;           /* '<S12>/If' */
  int8_T EnabledSubsystem1_SubsysRanBC;/* '<S17>/Enabled Subsystem1' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S17>/Enabled Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S12>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S12>/If Action Subsystem' */
  uint8_T is_active_c20_PendulumQuickStar;/* '<S9>/uint32_in2' */
  uint8_T is_active_c19_PendulumQuickStar;/* '<S9>/MATLAB Function3' */
  uint8_T is_active_c18_PendulumQuickStar;/* '<S9>/MATLAB Function2' */
  uint8_T is_active_c17_PendulumQuickStar;/* '<S9>/MATLAB Function1' */
  uint8_T packetindex[10];             /* '<S9>/MATLAB Function1' */
  uint8_T is_active_c16_PendulumQuickStar;/* '<S7>/uint32_in' */
  uint8_T is_active_c15_PendulumQuickStar;/* '<S7>/uint16_in1' */
  uint8_T is_active_c11_PendulumQuickStar;/* '<S7>/MATLAB Function' */
  uint8_T is_active_c5_PendulumQuickStart;/* '<S1>/Selection' */
  uint8_T is_active_c3_PendulumQuickStart;/* '<S11>/MATLAB Function' */
  uint8_T is_active_c4_PendulumQuickStart;/* '<S1>/Move to Center' */
  uint8_T is_active_c2_PendulumQuickStart;/* '<S1>/MATLAB Function' */
  uint8_T is_active_c6_PendulumQuickStart;/* '<S1>/Homing Block' */
  boolean_T validpack_not_empty;       /* '<S9>/MATLAB Function3' */
  boolean_T validpack2_not_empty;      /* '<S9>/MATLAB Function3' */
  boolean_T val_not_empty;             /* '<S9>/MATLAB Function1' */
  boolean_T bff_not_empty;             /* '<S9>/MATLAB Function1' */
  boolean_T EnabledSubsystem1_MODE;    /* '<S17>/Enabled Subsystem1' */
  boolean_T EnabledSubsystem_MODE;     /* '<S17>/Enabled Subsystem' */
} DW_PendulumQuickStart23_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE[2];        /* '<S11>/Transfer Fcn' */
  real_T undOrder_CSTATE[2];           /* '<S11>/2nd Order' */
  real_T FVolt_CSTATE;                 /* '<S11>/F//Volt' */
} X_PendulumQuickStart23_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE[2];        /* '<S11>/Transfer Fcn' */
  real_T undOrder_CSTATE[2];           /* '<S11>/2nd Order' */
  real_T FVolt_CSTATE;                 /* '<S11>/F//Volt' */
} XDot_PendulumQuickStart23_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE[2];     /* '<S11>/Transfer Fcn' */
  boolean_T undOrder_CSTATE[2];        /* '<S11>/2nd Order' */
  boolean_T FVolt_CSTATE;              /* '<S11>/F//Volt' */
} XDis_PendulumQuickStart23_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (default storage) */
struct P_PendulumQuickStart23_T_ {
  real_T K[4];                         /* Variable: K
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Nbar;                         /* Variable: Nbar
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S15>/Constant'
                                       */
  real_T SerialRead_SampleTime;        /* Expression: SampleTime
                                        * Referenced by: '<S9>/Serial Read'
                                        */
  real_T Mode_Value;                   /* Expression: 0
                                        * Referenced by: '<S1>/Mode'
                                        */
  real_T Constant_Value;               /* Expression: 5268
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 658
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Home_Value;                   /* Expression: 1
                                        * Referenced by: '<S1>/Home'
                                        */
  real_T Constant_Value_a;             /* Expression: 360
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T RodOffset_Value;              /* Expression: -800
                                        * Referenced by: '<S12>/RodOffset'
                                        */
  real_T Constant1_Value_h;            /* Expression: 2048
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Constant1_Value_c;            /* Expression: 85
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 191
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Enable_Value;                 /* Expression: 1
                                        * Referenced by: '<S1>/Enable'
                                        */
  real_T MoveCenter_Value;             /* Expression: 1
                                        * Referenced by: '<S1>/Move Center'
                                        */
  real_T Gain_Gain;                    /* Expression: -1e-3
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T DeadZone_Start;               /* Expression: -0.05
                                        * Referenced by: '<S11>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: +0.05
                                        * Referenced by: '<S11>/Dead Zone'
                                        */
  real_T Gain2_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S11>/Gain2'
                                        */
  real_T TransferFcn_A[2];             /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S11>/Transfer Fcn'
                                        */
  real_T TransferFcn_C[2];             /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S11>/Transfer Fcn'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S11>/Gain3'
                                        */
  real_T undOrder_A[2];                /* Computed Parameter: undOrder_A
                                        * Referenced by: '<S11>/2nd Order'
                                        */
  real_T undOrder_C[2];                /* Computed Parameter: undOrder_C
                                        * Referenced by: '<S11>/2nd Order'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1*pi/180
                                        * Referenced by: '<S11>/Gain6'
                                        */
  real_T CartPos_Value;                /* Expression: -3.397053617623811
                                        * Referenced by: '<S11>/Cart-Pos'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<S11>/Gain4'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 35
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -35
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T FVolt_A;                      /* Computed Parameter: FVolt_A
                                        * Referenced by: '<S11>/F//Volt'
                                        */
  real_T FVolt_C;                      /* Computed Parameter: FVolt_C
                                        * Referenced by: '<S11>/F//Volt'
                                        */
  real_T FVolt_D;                      /* Computed Parameter: FVolt_D
                                        * Referenced by: '<S11>/F//Volt'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1000
                                        * Referenced by: '<S11>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1000
                                        * Referenced by: '<S11>/Saturation1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 1000/12
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1
                                        * Referenced by: '<S11>/Gain7'
                                        */
  real_T Constant3_Value;              /* Expression: 1.2
                                        * Referenced by: '<S17>/Constant3'
                                        */
  real_T Saturation1_UpperSat_c;       /* Expression: 1000
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_g;       /* Expression: -1000
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T EnableControl_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/Enable Control'
                                        */
  real_T Saturation1_UpperSat_a;       /* Expression: 1000
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_f;       /* Expression: -1000
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  uint8_T BufferSize_Value;            /* Computed Parameter: BufferSize_Value
                                        * Referenced by: '<S9>/Buffer Size'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S9>/Constant4'
                                        */
  uint8_T Constant1_Value_h5;          /* Computed Parameter: Constant1_Value_h5
                                        * Referenced by: '<S9>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PendulumQuickStart23_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_PendulumQuickStart23_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_PendulumQuickStart23_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[5];
  real_T odeF[4][5];
  ODE4_IntgData intgData;

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
extern P_PendulumQuickStart23_T PendulumQuickStart23_P;

/* Block signals (default storage) */
extern B_PendulumQuickStart23_T PendulumQuickStart23_B;

/* Continuous states (default storage) */
extern X_PendulumQuickStart23_T PendulumQuickStart23_X;

/* Disabled states (default storage) */
extern XDis_PendulumQuickStart23_T PendulumQuickStart23_XDis;

/* Block states (default storage) */
extern DW_PendulumQuickStart23_T PendulumQuickStart23_DW;

/* Model entry point functions */
extern void PendulumQuickStart23_initialize(void);
extern void PendulumQuickStart23_step(void);
extern void PendulumQuickStart23_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PendulumQuickStart23_T *const PendulumQuickStart23_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion5' : Eliminate redundant data type conversion
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
 * '<Root>' : 'PendulumQuickStart23'
 * '<S1>'   : 'PendulumQuickStart23/Pendulum Subsystem'
 * '<S2>'   : 'PendulumQuickStart23/Pendulum Subsystem/Homing Block'
 * '<S3>'   : 'PendulumQuickStart23/Pendulum Subsystem/MATLAB Function'
 * '<S4>'   : 'PendulumQuickStart23/Pendulum Subsystem/Move to Center'
 * '<S5>'   : 'PendulumQuickStart23/Pendulum Subsystem/Pendulum Control'
 * '<S6>'   : 'PendulumQuickStart23/Pendulum Subsystem/Selection'
 * '<S7>'   : 'PendulumQuickStart23/Pendulum Subsystem/Servo Motor'
 * '<S8>'   : 'PendulumQuickStart23/Pendulum Subsystem/Subsystem'
 * '<S9>'   : 'PendulumQuickStart23/Pendulum Subsystem/Touchscreen'
 * '<S10>'  : 'PendulumQuickStart23/Pendulum Subsystem/Pendulum Control/Convert'
 * '<S11>'  : 'PendulumQuickStart23/Pendulum Subsystem/Pendulum Control/LQR controller'
 * '<S12>'  : 'PendulumQuickStart23/Pendulum Subsystem/Pendulum Control/Convert/Analog to Angle'
 * '<S13>'  : 'PendulumQuickStart23/Pendulum Subsystem/Pendulum Control/Convert/Analog to Angle/If Action Subsystem'
 * '<S14>'  : 'PendulumQuickStart23/Pendulum Subsystem/Pendulum Control/Convert/Analog to Angle/If Action Subsystem1'
 * '<S15>'  : 'PendulumQuickStart23/Pendulum Subsystem/Pendulum Control/LQR controller/Compare To Constant'
 * '<S16>'  : 'PendulumQuickStart23/Pendulum Subsystem/Pendulum Control/LQR controller/MATLAB Function'
 * '<S17>'  : 'PendulumQuickStart23/Pendulum Subsystem/Pendulum Control/LQR controller/PWM Gain'
 * '<S18>'  : 'PendulumQuickStart23/Pendulum Subsystem/Pendulum Control/LQR controller/PWM Gain/Enabled Subsystem'
 * '<S19>'  : 'PendulumQuickStart23/Pendulum Subsystem/Pendulum Control/LQR controller/PWM Gain/Enabled Subsystem1'
 * '<S20>'  : 'PendulumQuickStart23/Pendulum Subsystem/Servo Motor/MATLAB Function'
 * '<S21>'  : 'PendulumQuickStart23/Pendulum Subsystem/Servo Motor/uint16_in1'
 * '<S22>'  : 'PendulumQuickStart23/Pendulum Subsystem/Servo Motor/uint32_in'
 * '<S23>'  : 'PendulumQuickStart23/Pendulum Subsystem/Touchscreen/MATLAB Function1'
 * '<S24>'  : 'PendulumQuickStart23/Pendulum Subsystem/Touchscreen/MATLAB Function2'
 * '<S25>'  : 'PendulumQuickStart23/Pendulum Subsystem/Touchscreen/MATLAB Function3'
 * '<S26>'  : 'PendulumQuickStart23/Pendulum Subsystem/Touchscreen/Subsystem2'
 * '<S27>'  : 'PendulumQuickStart23/Pendulum Subsystem/Touchscreen/uint32_in2'
 */
#endif                                 /* RTW_HEADER_PendulumQuickStart23_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
