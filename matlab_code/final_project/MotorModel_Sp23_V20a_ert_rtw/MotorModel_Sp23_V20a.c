/*
 * MotorModel_Sp23_V20a.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MotorModel_Sp23_V20a".
 *
 * Model version              : 10
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Mon Dec  4 09:31:48 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorModel_Sp23_V20a.h"
#include "MotorModel_Sp23_V20a_private.h"

/* Block signals (default storage) */
B_MotorModel_Sp23_V20a_T MotorModel_Sp23_V20a_B;

/* Continuous states */
X_MotorModel_Sp23_V20a_T MotorModel_Sp23_V20a_X;

/* Block states (default storage) */
DW_MotorModel_Sp23_V20a_T MotorModel_Sp23_V20a_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_MotorModel_Sp23_V20a_T MotorModel_Sp23_V20a_Y;

/* Real-time model */
RT_MODEL_MotorModel_Sp23_V20a_T MotorModel_Sp23_V20a_M_;
RT_MODEL_MotorModel_Sp23_V20a_T *const MotorModel_Sp23_V20a_M =
  &MotorModel_Sp23_V20a_M_;

/* Forward declaration for local functions */
static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_inter_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0);
static void arduino_PWMOutput_set_pinNumb_j(codertarget_arduinobase_inter_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0);
static void matlabCodegenHandle_matlabC_jln(Encoder_arduino_MotorModel_Sp_T *obj);
static void MotorModel_S_SystemCore_release(codertarget_arduinobase_inter_T *obj);
static void MotorModel_SystemCore_delete_jl(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCo_jl(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;
  boolean_T isNegative1;
  boolean_T isNegative2;
  uint32_T cb1;
  uint32_T cb2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  int16_T i;
  int16_T exp_0;
  uint32_T u1i;
  uint32_T cb;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648UL) != 0UL) {
    cb = 1UL;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  MotorModel_Sp23_V20a_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  MotorModel_Sp23_V20a_step();
  MotorModel_Sp23_V20a_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  MotorModel_Sp23_V20a_step();
  MotorModel_Sp23_V20a_derivatives();

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

/*
 * Output and update for action system:
 *    '<S3>/Motor Direction1'
 *    '<S3>/Motor Direction 2'
 *    '<S3>/Constant Position'
 *    '<S4>/Motor Direction1'
 *    '<S4>/Motor Direction 2'
 *    '<S4>/Constant Position'
 */
void MotorModel_Sp23_MotorDirection1(real_T *rty_IN1, real_T *rty_IN2,
  P_MotorDirection1_MotorModel__T *localP)
{
  if (1) {
    /* Constant: '<S103>/Constant' */
    *rty_IN1 = localP->Constant_Value;

    /* Constant: '<S103>/Constant1' */
    *rty_IN2 = localP->Constant1_Value;
  }
}

static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_inter_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0)
{
  iobj_0->AvailablePwmPinNames.f1 = '2';
  iobj_0->AvailablePwmPinNames.f2 = '3';
  iobj_0->AvailablePwmPinNames.f3 = '4';
  iobj_0->AvailablePwmPinNames.f4 = '5';
  iobj_0->AvailablePwmPinNames.f5 = '6';
  iobj_0->AvailablePwmPinNames.f6 = '7';
  iobj_0->AvailablePwmPinNames.f7 = '8';
  iobj_0->AvailablePwmPinNames.f8 = '9';
  iobj_0->AvailablePwmPinNames.f9[0] = '1';
  iobj_0->AvailablePwmPinNames.f9[1] = '0';
  iobj_0->AvailablePwmPinNames.f10[0] = '1';
  iobj_0->AvailablePwmPinNames.f10[1] = '1';
  iobj_0->AvailablePwmPinNames.f11[0] = '1';
  iobj_0->AvailablePwmPinNames.f11[1] = '2';
  iobj_0->AvailablePwmPinNames.f12[0] = '1';
  iobj_0->AvailablePwmPinNames.f12[1] = '3';
  obj->Hw = iobj_0;
  obj->PinPWM = 5UL;
}

static void arduino_PWMOutput_set_pinNumb_j(codertarget_arduinobase_inter_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0)
{
  iobj_0->AvailablePwmPinNames.f1 = '2';
  iobj_0->AvailablePwmPinNames.f2 = '3';
  iobj_0->AvailablePwmPinNames.f3 = '4';
  iobj_0->AvailablePwmPinNames.f4 = '5';
  iobj_0->AvailablePwmPinNames.f5 = '6';
  iobj_0->AvailablePwmPinNames.f6 = '7';
  iobj_0->AvailablePwmPinNames.f7 = '8';
  iobj_0->AvailablePwmPinNames.f8 = '9';
  iobj_0->AvailablePwmPinNames.f9[0] = '1';
  iobj_0->AvailablePwmPinNames.f9[1] = '0';
  iobj_0->AvailablePwmPinNames.f10[0] = '1';
  iobj_0->AvailablePwmPinNames.f10[1] = '1';
  iobj_0->AvailablePwmPinNames.f11[0] = '1';
  iobj_0->AvailablePwmPinNames.f11[1] = '2';
  iobj_0->AvailablePwmPinNames.f12[0] = '1';
  iobj_0->AvailablePwmPinNames.f12[1] = '3';
  obj->Hw = iobj_0;
  obj->PinPWM = 6UL;
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

static void matlabCodegenHandle_matlabC_jln(Encoder_arduino_MotorModel_Sp_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void MotorModel_S_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_SetDutyCycle(obj->MW_PWM_HANDLE, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void MotorModel_SystemCore_delete_jl(codertarget_arduinobase_inter_T *obj)
{
  MotorModel_S_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCo_jl(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    MotorModel_SystemCore_delete_jl(obj);
  }
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function */
void MotorModel_Sp23_V20a_step(void)
{
  /* local block i/o variables */
  real_T rtb_Merge1;
  real_T rtb_Merge2;
  real_T rtb_Merge1_a;
  real_T rtb_Merge2_c;
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_Abs1;
  uint32_T tmp;
  uint32_T tmp_0;
  uint8_T tmp_1;
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
    /* set solver stop time */
    if (!(MotorModel_Sp23_V20a_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&MotorModel_Sp23_V20a_M->solverInfo,
                            ((MotorModel_Sp23_V20a_M->Timing.clockTickH0 + 1) *
        MotorModel_Sp23_V20a_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&MotorModel_Sp23_V20a_M->solverInfo,
                            ((MotorModel_Sp23_V20a_M->Timing.clockTick0 + 1) *
        MotorModel_Sp23_V20a_M->Timing.stepSize0 +
        MotorModel_Sp23_V20a_M->Timing.clockTickH0 *
        MotorModel_Sp23_V20a_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(MotorModel_Sp23_V20a_M)) {
    MotorModel_Sp23_V20a_M->Timing.t[0] = rtsiGetT
      (&MotorModel_Sp23_V20a_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(MotorModel_Sp23_V20a_DW.MotorDirection1.MotorDirection1_SubsysRanBC);
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
    /* MATLABSystem: '<S3>/MATLAB System' */
    if (MotorModel_Sp23_V20a_DW.obj_m.SampleTime !=
        MotorModel_Sp23_V20a_P.MATLABSystem_SampleTime) {
      MotorModel_Sp23_V20a_DW.obj_m.SampleTime =
        MotorModel_Sp23_V20a_P.MATLABSystem_SampleTime;
    }

    MotorModel_Sp23_V20a_B.MATLABSystem_b = enc_output(0.0);

    /* End of MATLABSystem: '<S3>/MATLAB System' */

    /* Gain: '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
    tmp = (uint32_T)MotorModel_Sp23_V20a_P.angular_positionrelative_countC;
    tmp_0 = (uint32_T)MotorModel_Sp23_V20a_B.MATLABSystem_b;
    sMultiWordMul(&tmp, 1, &tmp_0, 1,
                  &MotorModel_Sp23_V20a_B.angular_positionrelative_countC.chunks[
                  0U], 2);

    /* Outport: '<Root>/motorPos_Out' */
    MotorModel_Sp23_V20a_Y.motorPos_Out =
      MotorModel_Sp23_V20a_B.angular_positionrelative_countC;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/horzAngle'
     */
    MotorModel_Sp23_V20a_B.ErrorSignal = MotorModel_Sp23_V20a_P.horzAngle_Value
      - sMultiWord2Double
      (&MotorModel_Sp23_V20a_B.angular_positionrelative_countC.chunks[0U], 2, 0)
      * 1.1641532182693481E-10;

    /* Gain: '<S30>/Derivative Gain' */
    MotorModel_Sp23_V20a_B.DerivativeGain =
      MotorModel_Sp23_V20a_P.PIDController_D *
      MotorModel_Sp23_V20a_B.ErrorSignal;

    /* Gain: '<S41>/Proportional Gain' */
    MotorModel_Sp23_V20a_B.ProportionalGain =
      MotorModel_Sp23_V20a_P.PIDController_P *
      MotorModel_Sp23_V20a_B.ErrorSignal;
  }

  /* Gain: '<S39>/Filter Coefficient' incorporates:
   *  Integrator: '<S31>/Filter'
   *  Sum: '<S31>/SumD'
   */
  MotorModel_Sp23_V20a_B.FilterCoefficient =
    (MotorModel_Sp23_V20a_B.DerivativeGain -
     MotorModel_Sp23_V20a_X.Filter_CSTATE) *
    MotorModel_Sp23_V20a_P.PIDController_N;

  /* Sum: '<S45>/Sum' incorporates:
   *  Integrator: '<S36>/Integrator'
   */
  rtb_Abs1 = (MotorModel_Sp23_V20a_B.ProportionalGain +
              MotorModel_Sp23_V20a_X.Integrator_CSTATE) +
    MotorModel_Sp23_V20a_B.FilterCoefficient;

  /* Abs: '<S3>/Abs1' */
  MotorModel_Sp23_V20a_B.Abs = fabs(rtb_Abs1);

  /* Saturate: '<S3>/Saturation' */
  if (rtb_Abs1 > MotorModel_Sp23_V20a_P.Saturation_UpperSat) {
    rtb_Abs1 = MotorModel_Sp23_V20a_P.Saturation_UpperSat;
  } else {
    if (rtb_Abs1 < MotorModel_Sp23_V20a_P.Saturation_LowerSat) {
      rtb_Abs1 = MotorModel_Sp23_V20a_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* If: '<S3>/Choose Direction' */
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
    if ((rtb_Abs1 > 0.0) && (MotorModel_Sp23_V20a_B.Abs > 3.0)) {
      MotorModel_Sp23_V20a_DW.ChooseDirection_ActiveSubsystem = 0;
    } else if ((rtb_Abs1 < 0.0) && (MotorModel_Sp23_V20a_B.Abs > 3.0)) {
      MotorModel_Sp23_V20a_DW.ChooseDirection_ActiveSubsystem = 1;
    } else {
      MotorModel_Sp23_V20a_DW.ChooseDirection_ActiveSubsystem = 2;
    }
  }

  switch (MotorModel_Sp23_V20a_DW.ChooseDirection_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S3>/Motor Direction1' incorporates:
     *  ActionPort: '<S103>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(&rtb_Merge1, &rtb_Merge2,
      &MotorModel_Sp23_V20a_P.MotorDirection1);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
      srUpdateBC
        (MotorModel_Sp23_V20a_DW.MotorDirection1.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S3>/Motor Direction1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S3>/Motor Direction 2' incorporates:
     *  ActionPort: '<S102>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(&rtb_Merge1, &rtb_Merge2,
      &MotorModel_Sp23_V20a_P.MotorDirection2);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
      srUpdateBC
        (MotorModel_Sp23_V20a_DW.MotorDirection2.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S3>/Motor Direction 2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S3>/Constant Position' incorporates:
     *  ActionPort: '<S101>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(&rtb_Merge1, &rtb_Merge2,
      &MotorModel_Sp23_V20a_P.ConstantPosition);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
      srUpdateBC
        (MotorModel_Sp23_V20a_DW.ConstantPosition.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S3>/Constant Position' */
    break;
  }

  /* End of If: '<S3>/Choose Direction' */

  /* Abs: '<S3>/Abs' */
  rtb_Abs1 = fabs(rtb_Abs1);

  /* MATLABSystem: '<S3>/Enable' */
  obj = &MotorModel_Sp23_V20a_DW.obj_b;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(MotorModel_Sp23_V20a_DW.obj_b.PinPWM);

  /* Gain: '<S3>/Gain' */
  rtb_Abs1 *= MotorModel_Sp23_V20a_P.Gain_Gain;

  /* MATLABSystem: '<S3>/Enable' */
  if (!(rtb_Abs1 < 255.0)) {
    rtb_Abs1 = 255.0;
  }

  if (!(rtb_Abs1 > 0.0)) {
    rtb_Abs1 = 0.0;
  }

  MW_PWM_SetDutyCycle(MotorModel_Sp23_V20a_DW.obj_b.MW_PWM_HANDLE, rtb_Abs1);
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
    /* Gain: '<S33>/Integral Gain' */
    MotorModel_Sp23_V20a_B.IntegralGain = MotorModel_Sp23_V20a_P.PIDController_I
      * MotorModel_Sp23_V20a_B.ErrorSignal;

    /* MATLABSystem: '<S3>/Driver In1' */
    MotorModel_Sp23_V20a_B.ErrorSignal = rt_roundd_snf(rtb_Merge1);
    if (MotorModel_Sp23_V20a_B.ErrorSignal < 256.0) {
      if (MotorModel_Sp23_V20a_B.ErrorSignal >= 0.0) {
        tmp_1 = (uint8_T)MotorModel_Sp23_V20a_B.ErrorSignal;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(30, tmp_1);

    /* End of MATLABSystem: '<S3>/Driver In1' */

    /* MATLABSystem: '<S3>/Driver In2' */
    MotorModel_Sp23_V20a_B.ErrorSignal = rt_roundd_snf(rtb_Merge2);
    if (MotorModel_Sp23_V20a_B.ErrorSignal < 256.0) {
      if (MotorModel_Sp23_V20a_B.ErrorSignal >= 0.0) {
        tmp_1 = (uint8_T)MotorModel_Sp23_V20a_B.ErrorSignal;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(31, tmp_1);

    /* End of MATLABSystem: '<S3>/Driver In2' */

    /* MATLABSystem: '<S4>/MATLAB System' */
    if (MotorModel_Sp23_V20a_DW.obj_p.SampleTime !=
        MotorModel_Sp23_V20a_P.MATLABSystem_SampleTime_f) {
      if (((!rtIsInf(MotorModel_Sp23_V20a_P.MATLABSystem_SampleTime_f)) &&
           (!rtIsNaN(MotorModel_Sp23_V20a_P.MATLABSystem_SampleTime_f))) ||
          rtIsInf(MotorModel_Sp23_V20a_P.MATLABSystem_SampleTime_f)) {
        MotorModel_Sp23_V20a_B.sampleTime =
          MotorModel_Sp23_V20a_P.MATLABSystem_SampleTime_f;
      }

      MotorModel_Sp23_V20a_DW.obj_p.SampleTime =
        MotorModel_Sp23_V20a_B.sampleTime;
    }

    MotorModel_Sp23_V20a_B.MATLABSystem = enc_output(0.0);

    /* End of MATLABSystem: '<S4>/MATLAB System' */

    /* Gain: '<S4>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
    tmp = (uint32_T)MotorModel_Sp23_V20a_P.angular_positionrelative_coun_e;
    tmp_0 = (uint32_T)MotorModel_Sp23_V20a_B.MATLABSystem;
    sMultiWordMul(&tmp, 1, &tmp_0, 1,
                  &MotorModel_Sp23_V20a_B.angular_positionrelative_coun_h.chunks[
                  0U], 2);

    /* Outport: '<Root>/motorPos_Out1' */
    MotorModel_Sp23_V20a_Y.motorPos_Out1 =
      MotorModel_Sp23_V20a_B.angular_positionrelative_coun_h;

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/vertAngle'
     */
    MotorModel_Sp23_V20a_B.ErrorSignal = MotorModel_Sp23_V20a_P.vertAngle_Value
      - sMultiWord2Double
      (&MotorModel_Sp23_V20a_B.angular_positionrelative_coun_h.chunks[0U], 2, 0)
      * 1.1641532182693481E-10;

    /* Gain: '<S78>/Derivative Gain' */
    MotorModel_Sp23_V20a_B.DerivativeGain_c =
      MotorModel_Sp23_V20a_P.PIDController1_D *
      MotorModel_Sp23_V20a_B.ErrorSignal;

    /* Gain: '<S89>/Proportional Gain' */
    MotorModel_Sp23_V20a_B.ProportionalGain_p =
      MotorModel_Sp23_V20a_P.PIDController1_P *
      MotorModel_Sp23_V20a_B.ErrorSignal;
  }

  /* Gain: '<S87>/Filter Coefficient' incorporates:
   *  Integrator: '<S79>/Filter'
   *  Sum: '<S79>/SumD'
   */
  MotorModel_Sp23_V20a_B.FilterCoefficient_i =
    (MotorModel_Sp23_V20a_B.DerivativeGain_c -
     MotorModel_Sp23_V20a_X.Filter_CSTATE_m) *
    MotorModel_Sp23_V20a_P.PIDController1_N;

  /* Sum: '<S93>/Sum' incorporates:
   *  Integrator: '<S84>/Integrator'
   */
  MotorModel_Sp23_V20a_B.Abs = (MotorModel_Sp23_V20a_B.ProportionalGain_p +
    MotorModel_Sp23_V20a_X.Integrator_CSTATE_k) +
    MotorModel_Sp23_V20a_B.FilterCoefficient_i;

  /* Abs: '<S4>/Abs1' */
  rtb_Abs1 = fabs(MotorModel_Sp23_V20a_B.Abs);

  /* Saturate: '<S4>/Saturation' */
  if (MotorModel_Sp23_V20a_B.Abs > MotorModel_Sp23_V20a_P.Saturation_UpperSat_e)
  {
    MotorModel_Sp23_V20a_B.Abs = MotorModel_Sp23_V20a_P.Saturation_UpperSat_e;
  } else {
    if (MotorModel_Sp23_V20a_B.Abs <
        MotorModel_Sp23_V20a_P.Saturation_LowerSat_b) {
      MotorModel_Sp23_V20a_B.Abs = MotorModel_Sp23_V20a_P.Saturation_LowerSat_b;
    }
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* If: '<S4>/Choose Direction' */
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
    if ((MotorModel_Sp23_V20a_B.Abs > 0.0) && (rtb_Abs1 > 3.0)) {
      MotorModel_Sp23_V20a_DW.ChooseDirection_ActiveSubsyst_g = 0;
    } else if ((MotorModel_Sp23_V20a_B.Abs < 0.0) && (rtb_Abs1 > 3.0)) {
      MotorModel_Sp23_V20a_DW.ChooseDirection_ActiveSubsyst_g = 1;
    } else {
      MotorModel_Sp23_V20a_DW.ChooseDirection_ActiveSubsyst_g = 2;
    }
  }

  switch (MotorModel_Sp23_V20a_DW.ChooseDirection_ActiveSubsyst_g) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S4>/Motor Direction1' incorporates:
     *  ActionPort: '<S106>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(&rtb_Merge1_a, &rtb_Merge2_c,
      &MotorModel_Sp23_V20a_P.MotorDirection1_l);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
      srUpdateBC
        (MotorModel_Sp23_V20a_DW.MotorDirection1_l.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S4>/Motor Direction1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S4>/Motor Direction 2' incorporates:
     *  ActionPort: '<S105>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(&rtb_Merge1_a, &rtb_Merge2_c,
      &MotorModel_Sp23_V20a_P.MotorDirection2_c);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
      srUpdateBC
        (MotorModel_Sp23_V20a_DW.MotorDirection2_c.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S4>/Motor Direction 2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S4>/Constant Position' incorporates:
     *  ActionPort: '<S104>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(&rtb_Merge1_a, &rtb_Merge2_c,
      &MotorModel_Sp23_V20a_P.ConstantPosition_f);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
      srUpdateBC
        (MotorModel_Sp23_V20a_DW.ConstantPosition_f.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S4>/Constant Position' */
    break;
  }

  /* End of If: '<S4>/Choose Direction' */

  /* Abs: '<S4>/Abs' */
  MotorModel_Sp23_V20a_B.Abs = fabs(MotorModel_Sp23_V20a_B.Abs);

  /* MATLABSystem: '<S4>/Enable' */
  obj = &MotorModel_Sp23_V20a_DW.obj;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(MotorModel_Sp23_V20a_DW.obj.PinPWM);

  /* Gain: '<S4>/Gain' */
  rtb_Abs1 = MotorModel_Sp23_V20a_P.Gain_Gain_b * MotorModel_Sp23_V20a_B.Abs;

  /* MATLABSystem: '<S4>/Enable' */
  if (!(rtb_Abs1 < 255.0)) {
    rtb_Abs1 = 255.0;
  }

  if (!(rtb_Abs1 > 0.0)) {
    rtb_Abs1 = 0.0;
  }

  MW_PWM_SetDutyCycle(MotorModel_Sp23_V20a_DW.obj.MW_PWM_HANDLE, rtb_Abs1);
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
    /* Gain: '<S81>/Integral Gain' */
    MotorModel_Sp23_V20a_B.IntegralGain_n =
      MotorModel_Sp23_V20a_P.PIDController1_I *
      MotorModel_Sp23_V20a_B.ErrorSignal;

    /* MATLABSystem: '<S4>/Driver In1' */
    MotorModel_Sp23_V20a_B.ErrorSignal = rt_roundd_snf(rtb_Merge1_a);
    if (MotorModel_Sp23_V20a_B.ErrorSignal < 256.0) {
      if (MotorModel_Sp23_V20a_B.ErrorSignal >= 0.0) {
        tmp_1 = (uint8_T)MotorModel_Sp23_V20a_B.ErrorSignal;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(32, tmp_1);

    /* End of MATLABSystem: '<S4>/Driver In1' */

    /* MATLABSystem: '<S4>/Driver In2' */
    MotorModel_Sp23_V20a_B.ErrorSignal = rt_roundd_snf(rtb_Merge2_c);
    if (MotorModel_Sp23_V20a_B.ErrorSignal < 256.0) {
      if (MotorModel_Sp23_V20a_B.ErrorSignal >= 0.0) {
        tmp_1 = (uint8_T)MotorModel_Sp23_V20a_B.ErrorSignal;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(33, tmp_1);

    /* End of MATLABSystem: '<S4>/Driver In2' */
  }

  if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, (real_T)MotorModel_Sp23_V20a_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {/* Sample time: [0.001s, 0.0s] */
      rtExtModeUpload(1, (real_T)(((MotorModel_Sp23_V20a_M->Timing.clockTick1+
        MotorModel_Sp23_V20a_M->Timing.clockTickH1* 4294967296.0)) * 0.001));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(MotorModel_Sp23_V20a_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(MotorModel_Sp23_V20a_M)!=-1) &&
          !((rtmGetTFinal(MotorModel_Sp23_V20a_M)-
             (((MotorModel_Sp23_V20a_M->Timing.clockTick1+
                MotorModel_Sp23_V20a_M->Timing.clockTickH1* 4294967296.0)) *
              0.001)) > (((MotorModel_Sp23_V20a_M->Timing.clockTick1+
                           MotorModel_Sp23_V20a_M->Timing.clockTickH1*
                           4294967296.0)) * 0.001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(MotorModel_Sp23_V20a_M, "Simulation finished");
      }

      if (rtmGetStopRequested(MotorModel_Sp23_V20a_M)) {
        rtmSetErrorStatus(MotorModel_Sp23_V20a_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&MotorModel_Sp23_V20a_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++MotorModel_Sp23_V20a_M->Timing.clockTick0)) {
      ++MotorModel_Sp23_V20a_M->Timing.clockTickH0;
    }

    MotorModel_Sp23_V20a_M->Timing.t[0] = rtsiGetSolverStopTime
      (&MotorModel_Sp23_V20a_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      MotorModel_Sp23_V20a_M->Timing.clockTick1++;
      if (!MotorModel_Sp23_V20a_M->Timing.clockTick1) {
        MotorModel_Sp23_V20a_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void MotorModel_Sp23_V20a_derivatives(void)
{
  XDot_MotorModel_Sp23_V20a_T *_rtXdot;
  _rtXdot = ((XDot_MotorModel_Sp23_V20a_T *) MotorModel_Sp23_V20a_M->derivs);

  /* Derivatives for Integrator: '<S31>/Filter' */
  _rtXdot->Filter_CSTATE = MotorModel_Sp23_V20a_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE = MotorModel_Sp23_V20a_B.IntegralGain;

  /* Derivatives for Integrator: '<S79>/Filter' */
  _rtXdot->Filter_CSTATE_m = MotorModel_Sp23_V20a_B.FilterCoefficient_i;

  /* Derivatives for Integrator: '<S84>/Integrator' */
  _rtXdot->Integrator_CSTATE_k = MotorModel_Sp23_V20a_B.IntegralGain_n;
}

/* Model initialize function */
void MotorModel_Sp23_V20a_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)MotorModel_Sp23_V20a_M, 0,
                sizeof(RT_MODEL_MotorModel_Sp23_V20a_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&MotorModel_Sp23_V20a_M->solverInfo,
                          &MotorModel_Sp23_V20a_M->Timing.simTimeStep);
    rtsiSetTPtr(&MotorModel_Sp23_V20a_M->solverInfo, &rtmGetTPtr
                (MotorModel_Sp23_V20a_M));
    rtsiSetStepSizePtr(&MotorModel_Sp23_V20a_M->solverInfo,
                       &MotorModel_Sp23_V20a_M->Timing.stepSize0);
    rtsiSetdXPtr(&MotorModel_Sp23_V20a_M->solverInfo,
                 &MotorModel_Sp23_V20a_M->derivs);
    rtsiSetContStatesPtr(&MotorModel_Sp23_V20a_M->solverInfo, (real_T **)
                         &MotorModel_Sp23_V20a_M->contStates);
    rtsiSetNumContStatesPtr(&MotorModel_Sp23_V20a_M->solverInfo,
      &MotorModel_Sp23_V20a_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&MotorModel_Sp23_V20a_M->solverInfo,
      &MotorModel_Sp23_V20a_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&MotorModel_Sp23_V20a_M->solverInfo,
      &MotorModel_Sp23_V20a_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&MotorModel_Sp23_V20a_M->solverInfo,
      &MotorModel_Sp23_V20a_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&MotorModel_Sp23_V20a_M->solverInfo,
                          (&rtmGetErrorStatus(MotorModel_Sp23_V20a_M)));
    rtsiSetRTModelPtr(&MotorModel_Sp23_V20a_M->solverInfo,
                      MotorModel_Sp23_V20a_M);
  }

  rtsiSetSimTimeStep(&MotorModel_Sp23_V20a_M->solverInfo, MAJOR_TIME_STEP);
  MotorModel_Sp23_V20a_M->intgData.y = MotorModel_Sp23_V20a_M->odeY;
  MotorModel_Sp23_V20a_M->intgData.f[0] = MotorModel_Sp23_V20a_M->odeF[0];
  MotorModel_Sp23_V20a_M->intgData.f[1] = MotorModel_Sp23_V20a_M->odeF[1];
  MotorModel_Sp23_V20a_M->intgData.f[2] = MotorModel_Sp23_V20a_M->odeF[2];
  MotorModel_Sp23_V20a_M->contStates = ((X_MotorModel_Sp23_V20a_T *)
    &MotorModel_Sp23_V20a_X);
  rtsiSetSolverData(&MotorModel_Sp23_V20a_M->solverInfo, (void *)
                    &MotorModel_Sp23_V20a_M->intgData);
  rtsiSetSolverName(&MotorModel_Sp23_V20a_M->solverInfo,"ode3");
  rtmSetTPtr(MotorModel_Sp23_V20a_M, &MotorModel_Sp23_V20a_M->Timing.tArray[0]);
  rtmSetTFinal(MotorModel_Sp23_V20a_M, 100000.0);
  MotorModel_Sp23_V20a_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  MotorModel_Sp23_V20a_M->Sizes.checksums[0] = (3244076673U);
  MotorModel_Sp23_V20a_M->Sizes.checksums[1] = (442383943U);
  MotorModel_Sp23_V20a_M->Sizes.checksums[2] = (2555278911U);
  MotorModel_Sp23_V20a_M->Sizes.checksums[3] = (4047438086U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    MotorModel_Sp23_V20a_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &MotorModel_Sp23_V20a_DW.ConstantPosition.MotorDirection1_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &MotorModel_Sp23_V20a_DW.MotorDirection2.MotorDirection1_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &MotorModel_Sp23_V20a_DW.MotorDirection1.MotorDirection1_SubsysRanBC;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = (sysRanDType *)
      &MotorModel_Sp23_V20a_DW.ConstantPosition_f.MotorDirection1_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &MotorModel_Sp23_V20a_DW.MotorDirection2_c.MotorDirection1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &MotorModel_Sp23_V20a_DW.MotorDirection1_l.MotorDirection1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(MotorModel_Sp23_V20a_M->extModeInfo,
      &MotorModel_Sp23_V20a_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(MotorModel_Sp23_V20a_M->extModeInfo,
                        MotorModel_Sp23_V20a_M->Sizes.checksums);
    rteiSetTPtr(MotorModel_Sp23_V20a_M->extModeInfo, rtmGetTPtr
                (MotorModel_Sp23_V20a_M));
  }

  /* block I/O */
  (void) memset(((void *) &MotorModel_Sp23_V20a_B), 0,
                sizeof(B_MotorModel_Sp23_V20a_T));

  /* states (continuous) */
  {
    (void) memset((void *)&MotorModel_Sp23_V20a_X, 0,
                  sizeof(X_MotorModel_Sp23_V20a_T));
  }

  /* states (dwork) */
  (void) memset((void *)&MotorModel_Sp23_V20a_DW, 0,
                sizeof(DW_MotorModel_Sp23_V20a_T));

  /* external outputs */
  (void) memset((void *)&MotorModel_Sp23_V20a_Y, 0,
                sizeof(ExtY_MotorModel_Sp23_V20a_T));

  {
    codertarget_arduinobase_inter_T *obj;
    real_T sampleTime;

    /* Start for MATLABSystem: '<S3>/MATLAB System' */
    MotorModel_Sp23_V20a_DW.obj_m.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V20a_DW.objisempty_p = true;
    MotorModel_Sp23_V20a_DW.obj_m.SampleTime =
      MotorModel_Sp23_V20a_P.MATLABSystem_SampleTime;
    MotorModel_Sp23_V20a_DW.obj_m.isInitialized = 1L;
    enc_init(0.0, 2.0, 3.0);
    MotorModel_Sp23_V20a_DW.obj_m.isSetupComplete = true;

    /* Start for If: '<S3>/Choose Direction' */
    MotorModel_Sp23_V20a_DW.ChooseDirection_ActiveSubsystem = -1;

    /* Start for MATLABSystem: '<S3>/Enable' */
    MotorModel_Sp23_V20a_DW.obj_b.matlabCodegenIsDeleted = true;
    MotorModel_Sp23_V20a_DW.obj_b.isInitialized = 0L;
    MotorModel_Sp23_V20a_DW.obj_b.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V20a_DW.objisempty_k = true;
    arduino_PWMOutput_set_pinNumber(&MotorModel_Sp23_V20a_DW.obj_b,
      &MotorModel_Sp23_V20a_DW.gobj_2_i);
    obj = &MotorModel_Sp23_V20a_DW.obj_b;
    MotorModel_Sp23_V20a_DW.obj_b.isSetupComplete = false;
    MotorModel_Sp23_V20a_DW.obj_b.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(MotorModel_Sp23_V20a_DW.obj_b.PinPWM, 0.0,
      0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(MotorModel_Sp23_V20a_DW.obj_b.PinPWM);
    MW_PWM_Start(MotorModel_Sp23_V20a_DW.obj_b.MW_PWM_HANDLE);
    MotorModel_Sp23_V20a_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Driver In1' */
    MotorModel_Sp23_V20a_DW.obj_l.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V20a_DW.objisempty_b = true;
    MotorModel_Sp23_V20a_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(30, 1);
    MotorModel_Sp23_V20a_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Driver In2' */
    MotorModel_Sp23_V20a_DW.obj_f.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V20a_DW.objisempty_e = true;
    MotorModel_Sp23_V20a_DW.obj_f.isInitialized = 1L;
    digitalIOSetup(31, 1);
    MotorModel_Sp23_V20a_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/MATLAB System' */
    MotorModel_Sp23_V20a_DW.obj_p.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V20a_DW.objisempty = true;
    if (((!rtIsInf(MotorModel_Sp23_V20a_P.MATLABSystem_SampleTime_f)) &&
         (!rtIsNaN(MotorModel_Sp23_V20a_P.MATLABSystem_SampleTime_f))) ||
        rtIsInf(MotorModel_Sp23_V20a_P.MATLABSystem_SampleTime_f)) {
      sampleTime = MotorModel_Sp23_V20a_P.MATLABSystem_SampleTime_f;
    }

    MotorModel_Sp23_V20a_DW.obj_p.SampleTime = sampleTime;
    MotorModel_Sp23_V20a_DW.obj_p.isInitialized = 1L;
    enc_init(0.0, 50.0, 51.0);
    MotorModel_Sp23_V20a_DW.obj_p.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/MATLAB System' */

    /* Start for If: '<S4>/Choose Direction' */
    MotorModel_Sp23_V20a_DW.ChooseDirection_ActiveSubsyst_g = -1;

    /* Start for MATLABSystem: '<S4>/Enable' */
    MotorModel_Sp23_V20a_DW.obj.matlabCodegenIsDeleted = true;
    MotorModel_Sp23_V20a_DW.obj.isInitialized = 0L;
    MotorModel_Sp23_V20a_DW.obj.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V20a_DW.objisempty_f = true;
    arduino_PWMOutput_set_pinNumb_j(&MotorModel_Sp23_V20a_DW.obj,
      &MotorModel_Sp23_V20a_DW.gobj_2);
    obj = &MotorModel_Sp23_V20a_DW.obj;
    MotorModel_Sp23_V20a_DW.obj.isSetupComplete = false;
    MotorModel_Sp23_V20a_DW.obj.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(MotorModel_Sp23_V20a_DW.obj.PinPWM, 0.0,
      0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(MotorModel_Sp23_V20a_DW.obj.PinPWM);
    MW_PWM_Start(MotorModel_Sp23_V20a_DW.obj.MW_PWM_HANDLE);
    MotorModel_Sp23_V20a_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Driver In1' */
    MotorModel_Sp23_V20a_DW.obj_h.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V20a_DW.objisempty_h = true;
    MotorModel_Sp23_V20a_DW.obj_h.isInitialized = 1L;
    digitalIOSetup(32, 1);
    MotorModel_Sp23_V20a_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Driver In2' */
    MotorModel_Sp23_V20a_DW.obj_g.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V20a_DW.objisempty_m = true;
    MotorModel_Sp23_V20a_DW.obj_g.isInitialized = 1L;
    digitalIOSetup(33, 1);
    MotorModel_Sp23_V20a_DW.obj_g.isSetupComplete = true;
  }

  /* InitializeConditions for Integrator: '<S31>/Filter' */
  MotorModel_Sp23_V20a_X.Filter_CSTATE =
    MotorModel_Sp23_V20a_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S36>/Integrator' */
  MotorModel_Sp23_V20a_X.Integrator_CSTATE =
    MotorModel_Sp23_V20a_P.PIDController_InitialConditio_o;

  /* InitializeConditions for Integrator: '<S79>/Filter' */
  MotorModel_Sp23_V20a_X.Filter_CSTATE_m =
    MotorModel_Sp23_V20a_P.PIDController1_InitialCondition;

  /* InitializeConditions for Integrator: '<S84>/Integrator' */
  MotorModel_Sp23_V20a_X.Integrator_CSTATE_k =
    MotorModel_Sp23_V20a_P.PIDController1_InitialConditi_a;
}

/* Model terminate function */
void MotorModel_Sp23_V20a_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/MATLAB System' */
  matlabCodegenHandle_matlabC_jln(&MotorModel_Sp23_V20a_DW.obj_m);

  /* Terminate for MATLABSystem: '<S3>/Enable' */
  matlabCodegenHandle_matlabCo_jl(&MotorModel_Sp23_V20a_DW.obj_b);

  /* Terminate for MATLABSystem: '<S3>/Driver In1' */
  matlabCodegenHandle_matlabCodeg(&MotorModel_Sp23_V20a_DW.obj_l);

  /* Terminate for MATLABSystem: '<S3>/Driver In2' */
  matlabCodegenHandle_matlabCodeg(&MotorModel_Sp23_V20a_DW.obj_f);

  /* Terminate for MATLABSystem: '<S4>/MATLAB System' */
  matlabCodegenHandle_matlabC_jln(&MotorModel_Sp23_V20a_DW.obj_p);

  /* Terminate for MATLABSystem: '<S4>/Enable' */
  matlabCodegenHandle_matlabCo_jl(&MotorModel_Sp23_V20a_DW.obj);

  /* Terminate for MATLABSystem: '<S4>/Driver In1' */
  matlabCodegenHandle_matlabCodeg(&MotorModel_Sp23_V20a_DW.obj_h);

  /* Terminate for MATLABSystem: '<S4>/Driver In2' */
  matlabCodegenHandle_matlabCodeg(&MotorModel_Sp23_V20a_DW.obj_g);
}
