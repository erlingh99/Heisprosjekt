/*
 * heli_q8_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8".
 *
 * Model version              : 11.283
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed Nov 17 13:52:05 2021
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8.h"
#include "heli_q8_private.h"

/* Block parameters (default storage) */
P_heli_q8_T heli_q8_P = {
  /* Variable: A_d
   * Referenced by: '<S7>/Constant'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.2234780575259195E-6, 0.0012234780575259196, 0.002, 1.0,
    0.0, 0.0, 8.15652038350613E-10, 1.2234780575259197E-6, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.002, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.002, 1.0 },

  /* Variable: B_d
   * Referenced by: '<S7>/Constant5'
   */
  { 0.0, 0.0, 1.7238955470424939E-7, 0.00017238955470424942, 0.0, 0.0,
    1.0712530712530733E-6, 0.0010712530712530732, 0.0, 0.0,
    2.1844243778923086E-13, 4.3688487557846188E-10 },

  /* Variable: C_d
   * Referenced by: '<S7>/Constant2'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: F
   * Referenced by: '<S8>/Multiply'
   */
  { -2.4105268347398048E-15, 22.451155022986836, 16.250287348225697,
    -7.3702004895866918E-16 },

  /* Variable: Joystick_gain_x
   * Referenced by: '<S6>/Joystick_gain_x'
   */
  1.0,

  /* Variable: Joystick_gain_y
   * Referenced by: '<S6>/Joystick_gain_y'
   */
  -1.0,

  /* Variable: K
   * Referenced by: '<S8>/Multiply1'
   */
  { -2.4105268347398048E-15, 22.451155022986836, 2.9070690279152188E-16,
    15.291545932718398, 16.250287348225697, -7.3702004895866918E-16,
    -3.1048466329631045E-15, 11.180339887498963, 7.0710678118654791,
    8.4794856783728928E-16 },

  /* Variable: P_0
   * Referenced by: '<S7>/Unit Delay1'
   */
  { 0.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.05,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.05, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.05 },

  /* Variable: Q_d
   * Referenced by: '<S7>/Constant6'
   */
  { 1.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-5 },

  /* Variable: R_d
   * Referenced by: '<S7>/Constant4'
   */
  { 0.00147927209305007, 0.000231538235795237, 0.0029479333103103,
    -0.00121913989740227, 5.44408351820512E-5, 1.40651716897892E-6,
    0.000231538235795237, 0.00256433001649051, 0.000699327629497674,
    0.00262424107565141, -3.13503442546672E-5, 0.000421974441812797,
    0.0029479333103103, 0.000699327629497674, 0.0107910904147101,
    -0.00175294068055106, -1.58261274086619E-5, 0.000262833727744328,
    -0.00121913989740227, 0.00262424107565141, -0.00175294068055106,
    0.00943375880136097, -9.60184227425584E-5, 0.000524837203854007,
    5.44408351820512E-5, -3.13503442546672E-5, -1.58261274086619E-5,
    -9.60184227425584E-5, 1.77803756968392E-5, -6.95391493899459E-6,
    1.40651716897892E-6, 0.000421974441812797, 0.000262833727744328,
    0.000524837203854007, -6.95391493899459E-6, 0.000181162935969899 },

  /* Variable: vs_0
   * Referenced by: '<Root>/Constant3'
   */
  7.4,

  /* Variable: x_0
   * Referenced by: '<S7>/Unit Delay'
   */
  { 0.0, 0.0, -0.62831853071795862, 0.0, 0.0, 0.0 },

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S4>/HIL Write Analog'
   */
  { 0U, 1U },

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize1'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize1'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize1'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize1'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize1'
   */
  24305.934065934067,

  /* Expression: pwm_leading_deadband
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: pwm_trailing_deadband
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Expression: 65
   * Referenced by: '<S5>/Constant1'
   */
  65.0,

  /* Expression: [0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<S5>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S5>/Gain2'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: 0.16
   * Referenced by: '<Root>/Constant1'
   */
  0.16,

  /* Expression: 0.12
   * Referenced by: '<Root>/Constant'
   */
  0.12,

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S5>/Gain1'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: 2*pi/8192
   * Referenced by: '<S4>/Travel: Count to rad'
   */
  0.00076699039394282058,

  /* Expression: -2 * pi /4096
   * Referenced by: '<S4>/Elevation: Count to rad'
   */
  -0.0015339807878856412,

  /* Expression: 0.52
   * Referenced by: '<S4>/Constant'
   */
  0.52,

  /* Computed Parameter: ElevationTransferFcn_A
   * Referenced by: '<S4>/Elevation: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: ElevationTransferFcn_C
   * Referenced by: '<S4>/Elevation: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: ElevationTransferFcn_D
   * Referenced by: '<S4>/Elevation: Transfer Fcn'
   */
  50.0,

  /* Expression: -2*pi /4096
   * Referenced by: '<S4>/Pitch: Count to rad'
   */
  -0.0015339807878856412,

  /* Computed Parameter: PitchTransferFcn_A
   * Referenced by: '<S4>/Pitch: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: PitchTransferFcn_C
   * Referenced by: '<S4>/Pitch: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: PitchTransferFcn_D
   * Referenced by: '<S4>/Pitch: Transfer Fcn'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition: x'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S6>/Dead Zone: x'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S6>/Dead Zone: x'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S6>/Gain: x'
   */
  1.1111111111111112,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition: y'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S6>/Dead Zone: y'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S6>/Dead Zone: y'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S6>/Gain: y'
   */
  1.1111111111111112,

  /* Expression: 0.5
   * Referenced by: '<S1>/Back gain'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S1>/Front gain'
   */
  0.5,

  /* Computed Parameter: TravelTransferFcn_A
   * Referenced by: '<S4>/Travel: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: TravelTransferFcn_C
   * Referenced by: '<S4>/Travel: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: TravelTransferFcn_D
   * Referenced by: '<S4>/Travel: Transfer Fcn'
   */
  50.0,

  /* Expression: 5
   * Referenced by: '<S4>/Front motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S4>/Front motor: Saturation'
   */
  -5.0,

  /* Expression: 5
   * Referenced by: '<S4>/Back motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S4>/Back motor: Saturation'
   */
  -5.0,

  /* Computed Parameter: HILInitialize1_CKChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0, 1, 2 },

  /* Computed Parameter: HILInitialize1_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_EIInitial
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POModes
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POConfiguration
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POAlignment
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POPolarity
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Clock
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: StreamCall1_SendBufferSize
   * Referenced by: '<S5>/Stream Call1'
   */
  8000,

  /* Computed Parameter: StreamCall1_ReceiveBufferSize
   * Referenced by: '<S5>/Stream Call1'
   */
  8000,

  /* Computed Parameter: HILInitialize1_AIChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize1_AOChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize1_EIChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize1_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize1'
   */
  4U,

  /* Computed Parameter: HILInitialize1_POChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  500U,

  /* Computed Parameter: StreamFormattedWrite_MaxUnits
   * Referenced by: '<S5>/Stream Formatted Write'
   */
  80U,

  /* Computed Parameter: GameController_BufferSize
   * Referenced by: '<S6>/Game Controller'
   */
  12U,

  /* Computed Parameter: HILInitialize1_Active
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_AOTerminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_AOExit
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_DOTerminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_DOExit
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POTerminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_POExit
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_CKPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_CKPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_CKStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_CKEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_AIPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_AIPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_AOPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_AOPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_AOStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_AOEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_AOReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_DOPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_DOPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_DOStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_DOEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_DOReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_EIPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_EIPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_EIStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_EIEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_POPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_POEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_OOReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_DOFinal
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_DOInitial
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Active
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  1,

  /* Computed Parameter: StreamCall1_NonBlocking
   * Referenced by: '<S5>/Stream Call1'
   */
  1,

  /* Computed Parameter: StreamCall1_Active
   * Referenced by: '<S5>/Stream Call1'
   */
  0,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S4>/HIL Write Analog'
   */
  0,

  /* Computed Parameter: GameController_AutoCenter
   * Referenced by: '<S6>/Game Controller'
   */
  0,

  /* Computed Parameter: GameController_Enabled
   * Referenced by: '<S6>/Game Controller'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  1U,

  /* Expression: value
   * Referenced by: '<S5>/String Constant'
   */
  { 115U, 101U, 114U, 105U, 97U, 108U, 58U, 47U, 47U, 73U, 77U, 85U, 58U, 51U,
    63U, 98U, 97U, 117U, 100U, 61U, 49U, 49U, 53U, 50U, 48U, 48U, 44U, 119U,
    111U, 114U, 100U, 61U, 56U, 44U, 112U, 97U, 114U, 105U, 116U, 121U, 61U,
    110U, 111U, 110U, 101U, 44U, 115U, 116U, 111U, 112U, 61U, 49U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Expression: uri_argument
   * Referenced by: '<S5>/Stream Call1'
   */
  0U,

  /* Computed Parameter: StreamCall1_Endian
   * Referenced by: '<S5>/Stream Call1'
   */
  1U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U,

  /* Computed Parameter: GameController_ControllerNumber
   * Referenced by: '<S6>/Game Controller'
   */
  1U
};
