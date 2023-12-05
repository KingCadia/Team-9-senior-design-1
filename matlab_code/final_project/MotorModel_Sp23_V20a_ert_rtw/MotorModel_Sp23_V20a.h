/*
 * MotorModel_Sp23_V20a.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MotorModel_Sp23_V20a".
 *
 * Model version              : 14
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Mon Dec  4 19:22:37 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MotorModel_Sp23_V20a_h_
#define RTW_HEADER_MotorModel_Sp23_V20a_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef MotorModel_Sp23_V20a_COMMON_INCLUDES_
# define MotorModel_Sp23_V20a_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_work.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "encoder_arduino.h"
#endif                               /* MotorModel_Sp23_V20a_COMMON_INCLUDES_ */

#include "MotorModel_Sp23_V20a_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<S3>/Motor Direction1' */
typedef struct {
  int8_T MotorDirection1_SubsysRanBC;  /* '<S3>/Motor Direction1' */
} DW_MotorDirection1_MotorModel_T;

/* Block signals (default storage) */
typedef struct {
  real_T ProportionalGain;             /* '<S41>/Proportional Gain' */
  real_T IntegralGain;                 /* '<S33>/Integral Gain' */
  real_T DerivativeGain_e;             /* '<S78>/Derivative Gain' */
  real_T FilterCoefficient_b;          /* '<S87>/Filter Coefficient' */
  real_T ProportionalGain_a;           /* '<S89>/Proportional Gain' */
  real_T IntegralGain_h;               /* '<S81>/Integral Gain' */
  real_T sampleTime;
  real_T Abs;                          /* '<S4>/Abs' */
  real_T ErrorSignal;                  /* '<Root>/Sum2' */
  int64m_T angular_positionrelative_countC;
  /* '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
  int64m_T angular_positionrelative_coun_d;
  /* '<S4>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
  real_T DerivativeGain;               /* '<S30>/Derivative Gain' */
  real_T FilterCoefficient;            /* '<S39>/Filter Coefficient' */
  int32_T MATLABSystem;                /* '<S4>/MATLAB System' */
  int32_T MATLABSystem_b;              /* '<S3>/MATLAB System' */
} B_MotorModel_Sp23_V20a_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S4>/Enable' */
  codertarget_arduinobase_inter_T obj_b;/* '<S3>/Enable' */
  Encoder_arduino_MotorModel_Sp_T obj_f;/* '<S4>/MATLAB System' */
  Encoder_arduino_MotorModel_Sp_T obj_m;/* '<S3>/MATLAB System' */
  j_codertarget_arduinobase_int_T gobj_1;/* '<S4>/Enable' */
  j_codertarget_arduinobase_int_T gobj_2;/* '<S4>/Enable' */
  j_codertarget_arduinobase_int_T gobj_3;/* '<S4>/Enable' */
  j_codertarget_arduinobase_int_T gobj_4;/* '<S4>/Enable' */
  j_codertarget_arduinobase_int_T gobj_1_b;/* '<S3>/Enable' */
  j_codertarget_arduinobase_int_T gobj_2_i;/* '<S3>/Enable' */
  j_codertarget_arduinobase_int_T gobj_3_k;/* '<S3>/Enable' */
  j_codertarget_arduinobase_int_T gobj_4_d;/* '<S3>/Enable' */
  codertarget_arduinobase_block_T obj_k;/* '<S4>/Driver In1' */
  codertarget_arduinobase_block_T obj_kr;/* '<S4>/Driver In2' */
  codertarget_arduinobase_block_T obj_l;/* '<S3>/Driver In1' */
  codertarget_arduinobase_block_T obj_fl;/* '<S3>/Driver In2' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/magnet' */
  int8_T ChooseDirection_ActiveSubsystem;/* '<S3>/Choose Direction' */
  int8_T ChooseDirection_ActiveSubsyst_a;/* '<S4>/Choose Direction' */
  boolean_T objisempty;                /* '<S4>/MATLAB System' */
  boolean_T objisempty_n;              /* '<S4>/Enable' */
  boolean_T objisempty_j;              /* '<S4>/Driver In1' */
  boolean_T objisempty_g;              /* '<S4>/Driver In2' */
  boolean_T objisempty_p;              /* '<S3>/MATLAB System' */
  boolean_T objisempty_k;              /* '<S3>/Enable' */
  boolean_T objisempty_b;              /* '<S3>/Driver In1' */
  boolean_T objisempty_e;              /* '<S3>/Driver In2' */
  boolean_T objisempty_m;              /* '<Root>/magnet' */
  DW_MotorDirection1_MotorModel_T ConstantPosition_n;/* '<S4>/Constant Position' */
  DW_MotorDirection1_MotorModel_T MotorDirection2_o;/* '<S4>/Motor Direction 2' */
  DW_MotorDirection1_MotorModel_T MotorDirection1_n;/* '<S4>/Motor Direction1' */
  DW_MotorDirection1_MotorModel_T ConstantPosition;/* '<S3>/Constant Position' */
  DW_MotorDirection1_MotorModel_T MotorDirection2;/* '<S3>/Motor Direction 2' */
  DW_MotorDirection1_MotorModel_T MotorDirection1;/* '<S3>/Motor Direction1' */
} DW_MotorModel_Sp23_V20a_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Filter_CSTATE_d;              /* '<S79>/Filter' */
  real_T Integrator_CSTATE_p;          /* '<S84>/Integrator' */
} X_MotorModel_Sp23_V20a_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Filter_CSTATE_d;              /* '<S79>/Filter' */
  real_T Integrator_CSTATE_p;          /* '<S84>/Integrator' */
} XDot_MotorModel_Sp23_V20a_T;

/* State disabled  */
typedef struct {
  boolean_T Filter_CSTATE;             /* '<S31>/Filter' */
  boolean_T Integrator_CSTATE;         /* '<S36>/Integrator' */
  boolean_T Filter_CSTATE_d;           /* '<S79>/Filter' */
  boolean_T Integrator_CSTATE_p;       /* '<S84>/Integrator' */
} XDis_MotorModel_Sp23_V20a_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int64m_T motorPos_Out;               /* '<Root>/motorPos_Out' */
  int64m_T motorPos_Out1;              /* '<Root>/motorPos_Out1' */
} ExtY_MotorModel_Sp23_V20a_T;

/* Parameters for system: '<S3>/Motor Direction1' */
struct P_MotorDirection1_MotorModel__T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S103>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S103>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_MotorModel_Sp23_V20a_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S30>/Derivative Gain'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S78>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S33>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S81>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S31>/Filter'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S79>/Filter'
                               */
  real_T PIDController_InitialConditio_o;
                              /* Mask Parameter: PIDController_InitialConditio_o
                               * Referenced by: '<S36>/Integrator'
                               */
  real_T PIDController1_InitialConditi_l;
                              /* Mask Parameter: PIDController1_InitialConditi_l
                               * Referenced by: '<S84>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S39>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S87>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S41>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S89>/Proportional Gain'
                                        */
  real_T MATLABSystem_SampleTime;      /* Expression: 0.001
                                        * Referenced by: '<S3>/MATLAB System'
                                        */
  real_T MATLABSystem_SampleTime_h;    /* Expression: 0.001
                                        * Referenced by: '<S4>/MATLAB System'
                                        */
  real_T horzAngle_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/horzAngle'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 255/3
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T vertAngle_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/vertAngle'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 5
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -5
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 255/3
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T magnetController_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/magnetController'
                                        */
  int32_T angular_positionrelative_countC;
                          /* Computed Parameter: angular_positionrelative_countC
                           * Referenced by: '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
                           */
  int32_T angular_positionrelative_coun_d;
                          /* Computed Parameter: angular_positionrelative_coun_d
                           * Referenced by: '<S4>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
                           */
  P_MotorDirection1_MotorModel__T ConstantPosition_n;/* '<S4>/Constant Position' */
  P_MotorDirection1_MotorModel__T MotorDirection2_o;/* '<S4>/Motor Direction 2' */
  P_MotorDirection1_MotorModel__T MotorDirection1_n;/* '<S4>/Motor Direction1' */
  P_MotorDirection1_MotorModel__T ConstantPosition;/* '<S3>/Constant Position' */
  P_MotorDirection1_MotorModel__T MotorDirection2;/* '<S3>/Motor Direction 2' */
  P_MotorDirection1_MotorModel__T MotorDirection1;/* '<S3>/Motor Direction1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_MotorModel_Sp23_V20a_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_MotorModel_Sp23_V20a_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
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
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_MotorModel_Sp23_V20a_T MotorModel_Sp23_V20a_P;

/* Block signals (default storage) */
extern B_MotorModel_Sp23_V20a_T MotorModel_Sp23_V20a_B;

/* Continuous states (default storage) */
extern X_MotorModel_Sp23_V20a_T MotorModel_Sp23_V20a_X;

/* Block states (default storage) */
extern DW_MotorModel_Sp23_V20a_T MotorModel_Sp23_V20a_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_MotorModel_Sp23_V20a_T MotorModel_Sp23_V20a_Y;

/* Model entry point functions */
extern void MotorModel_Sp23_V20a_initialize(void);
extern void MotorModel_Sp23_V20a_step(void);
extern void MotorModel_Sp23_V20a_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MotorModel_Sp23_V20a_T *const MotorModel_Sp23_V20a_M;

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
 * '<Root>' : 'MotorModel_Sp23_V20a'
 * '<S1>'   : 'MotorModel_Sp23_V20a/PID Controller'
 * '<S2>'   : 'MotorModel_Sp23_V20a/PID Controller1'
 * '<S3>'   : 'MotorModel_Sp23_V20a/horz motor'
 * '<S4>'   : 'MotorModel_Sp23_V20a/horz motor1'
 * '<S5>'   : 'MotorModel_Sp23_V20a/PID Controller/Anti-windup'
 * '<S6>'   : 'MotorModel_Sp23_V20a/PID Controller/D Gain'
 * '<S7>'   : 'MotorModel_Sp23_V20a/PID Controller/Filter'
 * '<S8>'   : 'MotorModel_Sp23_V20a/PID Controller/Filter ICs'
 * '<S9>'   : 'MotorModel_Sp23_V20a/PID Controller/I Gain'
 * '<S10>'  : 'MotorModel_Sp23_V20a/PID Controller/Ideal P Gain'
 * '<S11>'  : 'MotorModel_Sp23_V20a/PID Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'MotorModel_Sp23_V20a/PID Controller/Integrator'
 * '<S13>'  : 'MotorModel_Sp23_V20a/PID Controller/Integrator ICs'
 * '<S14>'  : 'MotorModel_Sp23_V20a/PID Controller/N Copy'
 * '<S15>'  : 'MotorModel_Sp23_V20a/PID Controller/N Gain'
 * '<S16>'  : 'MotorModel_Sp23_V20a/PID Controller/P Copy'
 * '<S17>'  : 'MotorModel_Sp23_V20a/PID Controller/Parallel P Gain'
 * '<S18>'  : 'MotorModel_Sp23_V20a/PID Controller/Reset Signal'
 * '<S19>'  : 'MotorModel_Sp23_V20a/PID Controller/Saturation'
 * '<S20>'  : 'MotorModel_Sp23_V20a/PID Controller/Saturation Fdbk'
 * '<S21>'  : 'MotorModel_Sp23_V20a/PID Controller/Sum'
 * '<S22>'  : 'MotorModel_Sp23_V20a/PID Controller/Sum Fdbk'
 * '<S23>'  : 'MotorModel_Sp23_V20a/PID Controller/Tracking Mode'
 * '<S24>'  : 'MotorModel_Sp23_V20a/PID Controller/Tracking Mode Sum'
 * '<S25>'  : 'MotorModel_Sp23_V20a/PID Controller/Tsamp - Integral'
 * '<S26>'  : 'MotorModel_Sp23_V20a/PID Controller/Tsamp - Ngain'
 * '<S27>'  : 'MotorModel_Sp23_V20a/PID Controller/postSat Signal'
 * '<S28>'  : 'MotorModel_Sp23_V20a/PID Controller/preSat Signal'
 * '<S29>'  : 'MotorModel_Sp23_V20a/PID Controller/Anti-windup/Passthrough'
 * '<S30>'  : 'MotorModel_Sp23_V20a/PID Controller/D Gain/Internal Parameters'
 * '<S31>'  : 'MotorModel_Sp23_V20a/PID Controller/Filter/Cont. Filter'
 * '<S32>'  : 'MotorModel_Sp23_V20a/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S33>'  : 'MotorModel_Sp23_V20a/PID Controller/I Gain/Internal Parameters'
 * '<S34>'  : 'MotorModel_Sp23_V20a/PID Controller/Ideal P Gain/Passthrough'
 * '<S35>'  : 'MotorModel_Sp23_V20a/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'MotorModel_Sp23_V20a/PID Controller/Integrator/Continuous'
 * '<S37>'  : 'MotorModel_Sp23_V20a/PID Controller/Integrator ICs/Internal IC'
 * '<S38>'  : 'MotorModel_Sp23_V20a/PID Controller/N Copy/Disabled'
 * '<S39>'  : 'MotorModel_Sp23_V20a/PID Controller/N Gain/Internal Parameters'
 * '<S40>'  : 'MotorModel_Sp23_V20a/PID Controller/P Copy/Disabled'
 * '<S41>'  : 'MotorModel_Sp23_V20a/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S42>'  : 'MotorModel_Sp23_V20a/PID Controller/Reset Signal/Disabled'
 * '<S43>'  : 'MotorModel_Sp23_V20a/PID Controller/Saturation/Passthrough'
 * '<S44>'  : 'MotorModel_Sp23_V20a/PID Controller/Saturation Fdbk/Disabled'
 * '<S45>'  : 'MotorModel_Sp23_V20a/PID Controller/Sum/Sum_PID'
 * '<S46>'  : 'MotorModel_Sp23_V20a/PID Controller/Sum Fdbk/Disabled'
 * '<S47>'  : 'MotorModel_Sp23_V20a/PID Controller/Tracking Mode/Disabled'
 * '<S48>'  : 'MotorModel_Sp23_V20a/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'MotorModel_Sp23_V20a/PID Controller/Tsamp - Integral/Passthrough'
 * '<S50>'  : 'MotorModel_Sp23_V20a/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'MotorModel_Sp23_V20a/PID Controller/postSat Signal/Forward_Path'
 * '<S52>'  : 'MotorModel_Sp23_V20a/PID Controller/preSat Signal/Forward_Path'
 * '<S53>'  : 'MotorModel_Sp23_V20a/PID Controller1/Anti-windup'
 * '<S54>'  : 'MotorModel_Sp23_V20a/PID Controller1/D Gain'
 * '<S55>'  : 'MotorModel_Sp23_V20a/PID Controller1/Filter'
 * '<S56>'  : 'MotorModel_Sp23_V20a/PID Controller1/Filter ICs'
 * '<S57>'  : 'MotorModel_Sp23_V20a/PID Controller1/I Gain'
 * '<S58>'  : 'MotorModel_Sp23_V20a/PID Controller1/Ideal P Gain'
 * '<S59>'  : 'MotorModel_Sp23_V20a/PID Controller1/Ideal P Gain Fdbk'
 * '<S60>'  : 'MotorModel_Sp23_V20a/PID Controller1/Integrator'
 * '<S61>'  : 'MotorModel_Sp23_V20a/PID Controller1/Integrator ICs'
 * '<S62>'  : 'MotorModel_Sp23_V20a/PID Controller1/N Copy'
 * '<S63>'  : 'MotorModel_Sp23_V20a/PID Controller1/N Gain'
 * '<S64>'  : 'MotorModel_Sp23_V20a/PID Controller1/P Copy'
 * '<S65>'  : 'MotorModel_Sp23_V20a/PID Controller1/Parallel P Gain'
 * '<S66>'  : 'MotorModel_Sp23_V20a/PID Controller1/Reset Signal'
 * '<S67>'  : 'MotorModel_Sp23_V20a/PID Controller1/Saturation'
 * '<S68>'  : 'MotorModel_Sp23_V20a/PID Controller1/Saturation Fdbk'
 * '<S69>'  : 'MotorModel_Sp23_V20a/PID Controller1/Sum'
 * '<S70>'  : 'MotorModel_Sp23_V20a/PID Controller1/Sum Fdbk'
 * '<S71>'  : 'MotorModel_Sp23_V20a/PID Controller1/Tracking Mode'
 * '<S72>'  : 'MotorModel_Sp23_V20a/PID Controller1/Tracking Mode Sum'
 * '<S73>'  : 'MotorModel_Sp23_V20a/PID Controller1/Tsamp - Integral'
 * '<S74>'  : 'MotorModel_Sp23_V20a/PID Controller1/Tsamp - Ngain'
 * '<S75>'  : 'MotorModel_Sp23_V20a/PID Controller1/postSat Signal'
 * '<S76>'  : 'MotorModel_Sp23_V20a/PID Controller1/preSat Signal'
 * '<S77>'  : 'MotorModel_Sp23_V20a/PID Controller1/Anti-windup/Passthrough'
 * '<S78>'  : 'MotorModel_Sp23_V20a/PID Controller1/D Gain/Internal Parameters'
 * '<S79>'  : 'MotorModel_Sp23_V20a/PID Controller1/Filter/Cont. Filter'
 * '<S80>'  : 'MotorModel_Sp23_V20a/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S81>'  : 'MotorModel_Sp23_V20a/PID Controller1/I Gain/Internal Parameters'
 * '<S82>'  : 'MotorModel_Sp23_V20a/PID Controller1/Ideal P Gain/Passthrough'
 * '<S83>'  : 'MotorModel_Sp23_V20a/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S84>'  : 'MotorModel_Sp23_V20a/PID Controller1/Integrator/Continuous'
 * '<S85>'  : 'MotorModel_Sp23_V20a/PID Controller1/Integrator ICs/Internal IC'
 * '<S86>'  : 'MotorModel_Sp23_V20a/PID Controller1/N Copy/Disabled'
 * '<S87>'  : 'MotorModel_Sp23_V20a/PID Controller1/N Gain/Internal Parameters'
 * '<S88>'  : 'MotorModel_Sp23_V20a/PID Controller1/P Copy/Disabled'
 * '<S89>'  : 'MotorModel_Sp23_V20a/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S90>'  : 'MotorModel_Sp23_V20a/PID Controller1/Reset Signal/Disabled'
 * '<S91>'  : 'MotorModel_Sp23_V20a/PID Controller1/Saturation/Passthrough'
 * '<S92>'  : 'MotorModel_Sp23_V20a/PID Controller1/Saturation Fdbk/Disabled'
 * '<S93>'  : 'MotorModel_Sp23_V20a/PID Controller1/Sum/Sum_PID'
 * '<S94>'  : 'MotorModel_Sp23_V20a/PID Controller1/Sum Fdbk/Disabled'
 * '<S95>'  : 'MotorModel_Sp23_V20a/PID Controller1/Tracking Mode/Disabled'
 * '<S96>'  : 'MotorModel_Sp23_V20a/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S97>'  : 'MotorModel_Sp23_V20a/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S98>'  : 'MotorModel_Sp23_V20a/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S99>'  : 'MotorModel_Sp23_V20a/PID Controller1/postSat Signal/Forward_Path'
 * '<S100>' : 'MotorModel_Sp23_V20a/PID Controller1/preSat Signal/Forward_Path'
 * '<S101>' : 'MotorModel_Sp23_V20a/horz motor/Constant Position'
 * '<S102>' : 'MotorModel_Sp23_V20a/horz motor/Motor Direction 2'
 * '<S103>' : 'MotorModel_Sp23_V20a/horz motor/Motor Direction1'
 * '<S104>' : 'MotorModel_Sp23_V20a/horz motor1/Constant Position'
 * '<S105>' : 'MotorModel_Sp23_V20a/horz motor1/Motor Direction 2'
 * '<S106>' : 'MotorModel_Sp23_V20a/horz motor1/Motor Direction1'
 */
#endif                                 /* RTW_HEADER_MotorModel_Sp23_V20a_h_ */
