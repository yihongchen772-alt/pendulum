/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PendulumQuickStart_RL.h
 *
 * Code generated for Simulink model 'PendulumQuickStart_RL'.
 *
 * Model version                  : 14.20
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Fri Apr 17 17:18:53 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef PendulumQuickStart_RL_h_
#define PendulumQuickStart_RL_h_
#ifndef PendulumQuickStart_RL_COMMON_INCLUDES_
#define PendulumQuickStart_RL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_SCI.h"
#endif                              /* PendulumQuickStart_RL_COMMON_INCLUDES_ */

#include "PendulumQuickStart_RL_types.h"
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
  real_T DataTypeConversion;           /* '<S27>/Data Type Conversion' */
  real_T FromWorkspace[3];             /* '<S13>/From Workspace' */
  real_T Divide3;                      /* '<S13>/Divide3' */
  real_T Merge;                        /* '<S13>/Merge' */
  real_T Divide1;                      /* '<S13>/Divide1' */
  real_T Subtract1;                    /* '<S13>/Subtract1' */
  real_T Gain;                         /* '<S5>/Gain' */
  real_T DeadZone;                     /* '<S11>/Dead Zone' */
  real_T Gain4;                        /* '<S11>/Gain4' */
  real_T Saturation;                   /* '<S11>/Saturation' */
  real_T Saturation1;                  /* '<S11>/Saturation1' */
  real_T Merge_p;                      /* '<S18>/Merge' */
  real_T Saturation1_n;                /* '<S5>/Saturation1' */
  real_T Gain3;                        /* '<S5>/Gain3' */
  real_T Gain6;                        /* '<S5>/Gain6' */
  real_T DeadZone_f;                   /* '<S5>/Dead Zone' */
  real_T packet[10];                   /* '<S9>/MATLAB Function1' */
  real_T torqueOut;                    /* '<S1>/Selection' */
  real_T pwm;                          /* '<S5>/RL_Controller' */
  real_T homed;                        /* '<S1>/Homing Block' */
  real_T cartPos;                      /* '<S1>/Homing Block' */
  uint32_T y;                          /* '<S9>/uint32_in2' */
  uint32_T crc;                        /* '<S9>/MATLAB Function2' */
  uint8_T DataTypeConversion_h;        /* '<S7>/Data Type Conversion' */
  uint8_T DataTypeConversion1;         /* '<S7>/Data Type Conversion1' */
} B_PendulumQuickStart_RL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  emxArray_real_T_255_PendulumQ_T bff; /* '<S9>/MATLAB Function1' */
  codertarget_raspi_internal_SC_T obj; /* '<S7>/Serial Write' */
  codertarget_raspi_internal__i_T obj_o;/* '<S9>/Serial Read' */
  real_T val;                          /* '<S9>/MATLAB Function1' */
  real_T torqueval;                    /* '<S1>/Selection' */
  real_T initial_pos;                  /* '<S5>/RL_Controller' */
  real_T kp;                           /* '<S1>/Move to Center' */
  real_T set_pos;                      /* '<S1>/Move to Center' */
  real_T torqueval_d;                  /* '<S1>/Homing Block' */
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
  } FromWorkspace_PWORK;               /* '<S13>/From Workspace' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S11>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<S11>/Scope4' */

  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S13>/From Workspace' */

  int16_T validpack;                   /* '<S9>/MATLAB Function3' */
  int16_T validpack2;                  /* '<S9>/MATLAB Function3' */
  int8_T If_ActiveSubsystem;           /* '<S13>/If' */
  int8_T EnabledSubsystem1_SubsysRanBC;/* '<S18>/Enabled Subsystem1' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S18>/Enabled Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S13>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S13>/If Action Subsystem' */
  uint8_T packetindex[10];             /* '<S9>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit;    /* '<S9>/uint32_in2' */
  boolean_T doneDoubleBufferReInit_p;  /* '<S9>/MATLAB Function3' */
  boolean_T validpack_not_empty;       /* '<S9>/MATLAB Function3' */
  boolean_T validpack2_not_empty;      /* '<S9>/MATLAB Function3' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S9>/MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_j;  /* '<S9>/MATLAB Function1' */
  boolean_T val_not_empty;             /* '<S9>/MATLAB Function1' */
  boolean_T bff_not_empty;             /* '<S9>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_a;  /* '<S7>/uint32_in' */
  boolean_T doneDoubleBufferReInit_g;  /* '<S7>/uint16_in1' */
  boolean_T doneDoubleBufferReInit_o;  /* '<S7>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_i;  /* '<S1>/Selection' */
  boolean_T doneDoubleBufferReInit_l;  /* '<S5>/RL_Controller' */
  boolean_T isLoaded_not_empty;        /* '<S5>/RL_Controller' */
  boolean_T doneDoubleBufferReInit_oo; /* '<S11>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_at; /* '<S1>/Move to Center' */
  boolean_T doneDoubleBufferReInit_b;  /* '<S1>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S1>/Homing Block' */
  boolean_T EnabledSubsystem1_MODE;    /* '<S18>/Enabled Subsystem1' */
  boolean_T EnabledSubsystem_MODE;     /* '<S18>/Enabled Subsystem' */
} DW_PendulumQuickStart_RL_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE[2];        /* '<S11>/Transfer Fcn' */
  real_T undOrder_CSTATE[2];           /* '<S11>/2nd Order' */
  real_T FVolt_CSTATE;                 /* '<S11>/F//Volt' */
  real_T TransferFcn_CSTATE_p[2];      /* '<S5>/Transfer Fcn' */
  real_T undOrder_CSTATE_c[2];         /* '<S5>/2nd Order' */
} X_PendulumQuickStart_RL_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE[2];        /* '<S11>/Transfer Fcn' */
  real_T undOrder_CSTATE[2];           /* '<S11>/2nd Order' */
  real_T FVolt_CSTATE;                 /* '<S11>/F//Volt' */
  real_T TransferFcn_CSTATE_p[2];      /* '<S5>/Transfer Fcn' */
  real_T undOrder_CSTATE_c[2];         /* '<S5>/2nd Order' */
} XDot_PendulumQuickStart_RL_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE[2];     /* '<S11>/Transfer Fcn' */
  boolean_T undOrder_CSTATE[2];        /* '<S11>/2nd Order' */
  boolean_T FVolt_CSTATE;              /* '<S11>/F//Volt' */
  boolean_T TransferFcn_CSTATE_p[2];   /* '<S5>/Transfer Fcn' */
  boolean_T undOrder_CSTATE_c[2];      /* '<S5>/2nd Order' */
} XDis_PendulumQuickStart_RL_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (default storage) */
struct P_PendulumQuickStart_RL_T_ {
  real_T K[4];                         /* Variable: K
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Nbar;                         /* Variable: Nbar
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S16>/Constant'
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
  real_T Home_Value;                   /* Expression: 0
                                        * Referenced by: '<S1>/Home'
                                        */
  real_T Constant_Value_a;             /* Expression: 360
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T RodOffset_Value;              /* Expression: 30
                                        * Referenced by: '<S13>/RodOffset'
                                        */
  real_T Constant1_Value_h;            /* Expression: 2048
                                        * Referenced by: '<S13>/Constant1'
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
  real_T MoveCenter_Value;             /* Expression: 0
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
  real_T CartPos_Value;                /* Expression: 0
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
                                        * Referenced by: '<S18>/Constant3'
                                        */
  real_T Saturation1_UpperSat_c;       /* Expression: 1000
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_g;       /* Expression: -1000
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T TransferFcn_A_o[2];           /* Computed Parameter: TransferFcn_A_o
                                        * Referenced by: '<S5>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_l[2];           /* Computed Parameter: TransferFcn_C_l
                                        * Referenced by: '<S5>/Transfer Fcn'
                                        */
  real_T Gain3_Gain_a;                 /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T undOrder_A_j[2];              /* Computed Parameter: undOrder_A_j
                                        * Referenced by: '<S5>/2nd Order'
                                        */
  real_T undOrder_C_n[2];              /* Computed Parameter: undOrder_C_n
                                        * Referenced by: '<S5>/2nd Order'
                                        */
  real_T Gain6_Gain_n;                 /* Expression: 1*pi/180
                                        * Referenced by: '<S5>/Gain6'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S5>/Switch'
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
  real_T DeadZone_Start_a;             /* Expression: -0.05
                                        * Referenced by: '<S5>/Dead Zone'
                                        */
  real_T DeadZone_End_f;               /* Expression: +0.05
                                        * Referenced by: '<S5>/Dead Zone'
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
struct tag_RTM_PendulumQuickStart_RL_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_PendulumQuickStart_RL_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_PendulumQuickStart_RL_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[9];
  real_T odeF[4][9];
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
extern P_PendulumQuickStart_RL_T PendulumQuickStart_RL_P;

/* Block signals (default storage) */
extern B_PendulumQuickStart_RL_T PendulumQuickStart_RL_B;

/* Continuous states (default storage) */
extern X_PendulumQuickStart_RL_T PendulumQuickStart_RL_X;

/* Disabled states (default storage) */
extern XDis_PendulumQuickStart_RL_T PendulumQuickStart_RL_XDis;

/* Block states (default storage) */
extern DW_PendulumQuickStart_RL_T PendulumQuickStart_RL_DW;

/* Model entry point functions */
extern void PendulumQuickStart_RL_initialize(void);
extern void PendulumQuickStart_RL_step(void);
extern void PendulumQuickStart_RL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PendulumQuickStart_R_T *const PendulumQuickStart_RL_M;
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
 * '<Root>' : 'PendulumQuickStart_RL'
 * '<S1>'   : 'PendulumQuickStart_RL/Pendulum Subsystem'
 * '<S2>'   : 'PendulumQuickStart_RL/Pendulum Subsystem/Homing Block'
 * '<S3>'   : 'PendulumQuickStart_RL/Pendulum Subsystem/MATLAB Function'
 * '<S4>'   : 'PendulumQuickStart_RL/Pendulum Subsystem/Move to Center'
 * '<S5>'   : 'PendulumQuickStart_RL/Pendulum Subsystem/Pendulum Control'
 * '<S6>'   : 'PendulumQuickStart_RL/Pendulum Subsystem/Selection'
 * '<S7>'   : 'PendulumQuickStart_RL/Pendulum Subsystem/Servo Motor'
 * '<S8>'   : 'PendulumQuickStart_RL/Pendulum Subsystem/Subsystem'
 * '<S9>'   : 'PendulumQuickStart_RL/Pendulum Subsystem/Touchscreen'
 * '<S10>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Pendulum Control/Convert'
 * '<S11>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Pendulum Control/LQR controller'
 * '<S12>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Pendulum Control/RL_Controller'
 * '<S13>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Pendulum Control/Convert/Analog to Angle'
 * '<S14>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Pendulum Control/Convert/Analog to Angle/If Action Subsystem'
 * '<S15>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Pendulum Control/Convert/Analog to Angle/If Action Subsystem1'
 * '<S16>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Pendulum Control/LQR controller/Compare To Constant'
 * '<S17>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Pendulum Control/LQR controller/MATLAB Function'
 * '<S18>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Pendulum Control/LQR controller/PWM Gain'
 * '<S19>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Pendulum Control/LQR controller/PWM Gain/Enabled Subsystem'
 * '<S20>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Pendulum Control/LQR controller/PWM Gain/Enabled Subsystem1'
 * '<S21>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Servo Motor/MATLAB Function'
 * '<S22>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Servo Motor/uint16_in1'
 * '<S23>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Servo Motor/uint32_in'
 * '<S24>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Touchscreen/MATLAB Function1'
 * '<S25>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Touchscreen/MATLAB Function2'
 * '<S26>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Touchscreen/MATLAB Function3'
 * '<S27>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Touchscreen/Subsystem2'
 * '<S28>'  : 'PendulumQuickStart_RL/Pendulum Subsystem/Touchscreen/uint32_in2'
 */
#endif                                 /* PendulumQuickStart_RL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
