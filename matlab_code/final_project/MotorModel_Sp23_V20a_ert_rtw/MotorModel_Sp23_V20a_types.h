/*
 * MotorModel_Sp23_V20a_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MotorModel_Sp23_V20a".
 *
 * Model version              : 8
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Sun Dec  3 17:18:43 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MotorModel_Sp23_V20a_types_h_
#define RTW_HEADER_MotorModel_Sp23_V20a_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_E7ZjpEHEQzzHgi4oOkm0RC
#define struct_tag_E7ZjpEHEQzzHgi4oOkm0RC

struct tag_E7ZjpEHEQzzHgi4oOkm0RC
{
  int16_T __dummy;
};

#endif                                 /*struct_tag_E7ZjpEHEQzzHgi4oOkm0RC*/

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_E7ZjpEHEQzzHgi4oOkm0RC b_arduinodriver_ArduinoDigita_T;

#endif                               /*typedef_b_arduinodriver_ArduinoDigita_T*/

#ifndef struct_tag_KPrkuOK6ssObybfxqijZPC
#define struct_tag_KPrkuOK6ssObybfxqijZPC

struct tag_KPrkuOK6ssObybfxqijZPC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /*struct_tag_KPrkuOK6ssObybfxqijZPC*/

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_KPrkuOK6ssObybfxqijZPC codertarget_arduinobase_block_T;

#endif                               /*typedef_codertarget_arduinobase_block_T*/

/* Custom Type definition for MATLABSystem: '<S1>/Enable' */
#include "MW_SVD.h"
#ifndef struct_tag_Vdrvk2IQsOqPlWl1GaayPG
#define struct_tag_Vdrvk2IQsOqPlWl1GaayPG

struct tag_Vdrvk2IQsOqPlWl1GaayPG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif                                 /*struct_tag_Vdrvk2IQsOqPlWl1GaayPG*/

#ifndef typedef_Encoder_arduino_MotorModel_Sp_T
#define typedef_Encoder_arduino_MotorModel_Sp_T

typedef struct tag_Vdrvk2IQsOqPlWl1GaayPG Encoder_arduino_MotorModel_Sp_T;

#endif                               /*typedef_Encoder_arduino_MotorModel_Sp_T*/

#ifndef struct_tag_GtaT2TPu8wQVLKHBwLo3ME
#define struct_tag_GtaT2TPu8wQVLKHBwLo3ME

struct tag_GtaT2TPu8wQVLKHBwLo3ME
{
  char_T f1;
  char_T f2;
  char_T f3;
  char_T f4;
  char_T f5;
  char_T f6;
  char_T f7;
  char_T f8;
  char_T f9[2];
  char_T f10[2];
  char_T f11[2];
  char_T f12[2];
};

#endif                                 /*struct_tag_GtaT2TPu8wQVLKHBwLo3ME*/

#ifndef typedef_cell_MotorModel_Sp23_V20a_T
#define typedef_cell_MotorModel_Sp23_V20a_T

typedef struct tag_GtaT2TPu8wQVLKHBwLo3ME cell_MotorModel_Sp23_V20a_T;

#endif                                 /*typedef_cell_MotorModel_Sp23_V20a_T*/

#ifndef struct_tag_O2Hap3tiAr1xYyd5SB7jqH
#define struct_tag_O2Hap3tiAr1xYyd5SB7jqH

struct tag_O2Hap3tiAr1xYyd5SB7jqH
{
  cell_MotorModel_Sp23_V20a_T AvailablePwmPinNames;
};

#endif                                 /*struct_tag_O2Hap3tiAr1xYyd5SB7jqH*/

#ifndef typedef_j_codertarget_arduinobase_int_T
#define typedef_j_codertarget_arduinobase_int_T

typedef struct tag_O2Hap3tiAr1xYyd5SB7jqH j_codertarget_arduinobase_int_T;

#endif                               /*typedef_j_codertarget_arduinobase_int_T*/

#ifndef struct_tag_ZksrEzekLFp3nSi7noWstB
#define struct_tag_ZksrEzekLFp3nSi7noWstB

struct tag_ZksrEzekLFp3nSi7noWstB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  j_codertarget_arduinobase_int_T *Hw;
  MW_Handle_Type MW_PWM_HANDLE;
  uint32_T PinPWM;
};

#endif                                 /*struct_tag_ZksrEzekLFp3nSi7noWstB*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_ZksrEzekLFp3nSi7noWstB codertarget_arduinobase_inter_T;

#endif                               /*typedef_codertarget_arduinobase_inter_T*/

/* Parameters for system: '<S1>/Motor Direction1' */
typedef struct P_MotorDirection1_MotorModel__T_ P_MotorDirection1_MotorModel__T;

/* Parameters (default storage) */
typedef struct P_MotorModel_Sp23_V20a_T_ P_MotorModel_Sp23_V20a_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_MotorModel_Sp23_V20a_T RT_MODEL_MotorModel_Sp23_V20a_T;

#endif                            /* RTW_HEADER_MotorModel_Sp23_V20a_types_h_ */
