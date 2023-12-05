/*
 * MotorModel_Sp23_V20a_data.c
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

#include "MotorModel_Sp23_V20a.h"
#include "MotorModel_Sp23_V20a_private.h"

/* Block parameters (default storage) */
P_MotorModel_Sp23_V20a_T MotorModel_Sp23_V20a_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S30>/Derivative Gain'
   */
  0.001,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S78>/Derivative Gain'
   */
  0.001,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S33>/Integral Gain'
   */
  0.01,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S81>/Integral Gain'
   */
  0.1,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S31>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S79>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_o
   * Referenced by: '<S36>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_l
   * Referenced by: '<S84>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S39>/Filter Coefficient'
   */
  200.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S87>/Filter Coefficient'
   */
  200.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S41>/Proportional Gain'
   */
  0.8,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S89>/Proportional Gain'
   */
  0.8,

  /* Expression: 0.001
   * Referenced by: '<S3>/MATLAB System'
   */
  0.001,

  /* Expression: 0.001
   * Referenced by: '<S4>/MATLAB System'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/horzAngle'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S3>/Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S3>/Saturation'
   */
  -5.0,

  /* Expression: 255/3
   * Referenced by: '<S3>/Gain'
   */
  85.0,

  /* Expression: 0
   * Referenced by: '<Root>/vertAngle'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S4>/Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S4>/Saturation'
   */
  -5.0,

  /* Expression: 255/3
   * Referenced by: '<S4>/Gain'
   */
  85.0,

  /* Expression: 0
   * Referenced by: '<Root>/magnetController'
   */
  0.0,

  /* Computed Parameter: angular_positionrelative_countC
   * Referenced by: '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
   */
  1932735283,

  /* Computed Parameter: angular_positionrelative_coun_d
   * Referenced by: '<S4>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
   */
  1932735283,

  /* Start of '<S4>/Constant Position' */
  {
    /* Expression: 0
     * Referenced by: '<S104>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S104>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S4>/Constant Position' */

  /* Start of '<S4>/Motor Direction 2' */
  {
    /* Expression: 0
     * Referenced by: '<S105>/Constant'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S105>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S4>/Motor Direction 2' */

  /* Start of '<S4>/Motor Direction1' */
  {
    /* Expression: 1
     * Referenced by: '<S106>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S106>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S4>/Motor Direction1' */

  /* Start of '<S3>/Constant Position' */
  {
    /* Expression: 0
     * Referenced by: '<S101>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S101>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S3>/Constant Position' */

  /* Start of '<S3>/Motor Direction 2' */
  {
    /* Expression: 0
     * Referenced by: '<S102>/Constant'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S102>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S3>/Motor Direction 2' */

  /* Start of '<S3>/Motor Direction1' */
  {
    /* Expression: 1
     * Referenced by: '<S103>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S103>/Constant1'
     */
    0.0
  }
  /* End of '<S3>/Motor Direction1' */
};
