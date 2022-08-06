/*
 * heli_q8_pres22.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_pres22".
 *
 * Model version              : 11.23
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed Nov 17 13:13:41 2021
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_pres22.h"
#include "heli_q8_pres22_private.h"

/* Block signals (default storage) */
B_heli_q8_pres22_T heli_q8_pres22_B;

/* Continuous states */
X_heli_q8_pres22_T heli_q8_pres22_X;

/* Block states (default storage) */
DW_heli_q8_pres22_T heli_q8_pres22_DW;

/* Real-time model */
static RT_MODEL_heli_q8_pres22_T heli_q8_pres22_M_;
RT_MODEL_heli_q8_pres22_T *const heli_q8_pres22_M = &heli_q8_pres22_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_pres22_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_pres22_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (heli_q8_pres22_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_pres22_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_pres22_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_pres22_M->Timing.perTaskSampleHits[5] =
      heli_q8_pres22_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_pres22_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_pres22_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_pres22_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_q8_pres22_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void heli_q8_pres22_output0(void)      /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_DeadZoney;
  real_T rtb_Joystick_gain_x;
  real_T tmp[5];
  real_T rtb_Sum1[2];
  real_T rtb_ElevationTransferFcn;
  real_T rtb_Frontgain;
  real_T rtb_PitchTransferFcn;
  real_T rtb_TmpSignalConversionAtMatr_0;
  real_T rtb_TmpSignalConversionAtMatr_1;
  int32_T i;
  int32_T i_0;
  if (rtmIsMajorTimeStep(heli_q8_pres22_M)) {
    /* set solver stop time */
    if (!(heli_q8_pres22_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_pres22_M->solverInfo,
                            ((heli_q8_pres22_M->Timing.clockTickH0 + 1) *
        heli_q8_pres22_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_pres22_M->solverInfo,
                            ((heli_q8_pres22_M->Timing.clockTick0 + 1) *
        heli_q8_pres22_M->Timing.stepSize0 +
        heli_q8_pres22_M->Timing.clockTickH0 *
        heli_q8_pres22_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_pres22_M)) {
    heli_q8_pres22_M->Timing.t[0] = rtsiGetT(&heli_q8_pres22_M->solverInfo);
  }

  /* RateTransition: '<S3>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(heli_q8_pres22_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_pres22/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (heli_q8_pres22_DW.HILReadEncoderTimebase_Task, 1,
         &heli_q8_pres22_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_pres22_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_DeadZoney = heli_q8_pres22_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_Joystick_gain_x = heli_q8_pres22_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S2>/Pitch: Count to rad' */
    heli_q8_pres22_B.PitchCounttorad = heli_q8_pres22_P.PitchCounttorad_Gain *
      rtb_DeadZoney;

    /* Gain: '<S2>/Elevation: Count to rad' */
    heli_q8_pres22_B.ElevationCounttorad =
      heli_q8_pres22_P.ElevationCounttorad_Gain * rtb_Joystick_gain_x;
    if (heli_q8_pres22_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S3>/Rate Transition: x' */
      heli_q8_pres22_B.RateTransitionx =
        heli_q8_pres22_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S3>/Dead Zone: x' */
    if (heli_q8_pres22_B.RateTransitionx > heli_q8_pres22_P.DeadZonex_End) {
      /* Gain: '<S3>/Joystick_gain_x' */
      rtb_Joystick_gain_x = heli_q8_pres22_B.RateTransitionx -
        heli_q8_pres22_P.DeadZonex_End;
    } else if (heli_q8_pres22_B.RateTransitionx >=
               heli_q8_pres22_P.DeadZonex_Start) {
      /* Gain: '<S3>/Joystick_gain_x' */
      rtb_Joystick_gain_x = 0.0;
    } else {
      /* Gain: '<S3>/Joystick_gain_x' */
      rtb_Joystick_gain_x = heli_q8_pres22_B.RateTransitionx -
        heli_q8_pres22_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: x' */

    /* Gain: '<S3>/Joystick_gain_x' incorporates:
     *  Gain: '<S3>/Gain: x'
     */
    rtb_Joystick_gain_x = heli_q8_pres22_P.Gainx_Gain * rtb_Joystick_gain_x *
      heli_q8_pres22_P.Joystick_gain_x;

    /* RateTransition: '<S3>/Rate Transition: y' */
    if (heli_q8_pres22_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S3>/Rate Transition: y' */
      heli_q8_pres22_B.RateTransitiony =
        heli_q8_pres22_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: y' */

    /* DeadZone: '<S3>/Dead Zone: y' */
    if (heli_q8_pres22_B.RateTransitiony > heli_q8_pres22_P.DeadZoney_End) {
      /* DeadZone: '<S3>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_pres22_B.RateTransitiony -
        heli_q8_pres22_P.DeadZoney_End;
    } else if (heli_q8_pres22_B.RateTransitiony >=
               heli_q8_pres22_P.DeadZoney_Start) {
      /* DeadZone: '<S3>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S3>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_pres22_B.RateTransitiony -
        heli_q8_pres22_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: y' */

    /* Gain: '<S3>/Joystick_gain_y' incorporates:
     *  Gain: '<S3>/Gain: y'
     */
    heli_q8_pres22_B.Joystick_gain_y = heli_q8_pres22_P.Gainy_Gain *
      rtb_DeadZoney * heli_q8_pres22_P.Joystick_gain_y;

    /* SignalConversion generated from: '<S4>/MatrixMultiply1' */
    rtb_TmpSignalConversionAtMatr_0 = rtb_Joystick_gain_x;
    rtb_TmpSignalConversionAtMatr_1 = heli_q8_pres22_B.Joystick_gain_y;

    /* Product: '<S4>/MatrixMultiply1' incorporates:
     *  Constant: '<S4>/Constant2'
     *  SignalConversion generated from: '<S4>/MatrixMultiply1'
     */
    heli_q8_pres22_B.MatrixMultiply1[0] = 0.0;
    heli_q8_pres22_B.MatrixMultiply1[0] += heli_q8_pres22_P.F[0] *
      rtb_Joystick_gain_x;
    heli_q8_pres22_B.MatrixMultiply1[0] += heli_q8_pres22_P.F[2] *
      heli_q8_pres22_B.Joystick_gain_y;
    heli_q8_pres22_B.MatrixMultiply1[1] = 0.0;
    heli_q8_pres22_B.MatrixMultiply1[1] += heli_q8_pres22_P.F[1] *
      rtb_Joystick_gain_x;
    heli_q8_pres22_B.MatrixMultiply1[1] += heli_q8_pres22_P.F[3] *
      heli_q8_pres22_B.Joystick_gain_y;
  }

  /* End of RateTransition: '<S3>/Rate Transition: x' */

  /* TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  rtb_ElevationTransferFcn = heli_q8_pres22_P.ElevationTransferFcn_C *
    heli_q8_pres22_X.ElevationTransferFcn_CSTATE +
    heli_q8_pres22_P.ElevationTransferFcn_D *
    heli_q8_pres22_B.ElevationCounttorad;

  /* SignalConversion generated from: '<S4>/MatrixMultiply' incorporates:
   *  Integrator: '<S4>/Integrator'
   *  Integrator: '<S4>/Integrator1'
   *  TransferFcn: '<S2>/Pitch: Transfer Fcn'
   */
  tmp[0] = heli_q8_pres22_B.PitchCounttorad;
  tmp[1] = heli_q8_pres22_P.PitchTransferFcn_C *
    heli_q8_pres22_X.PitchTransferFcn_CSTATE +
    heli_q8_pres22_P.PitchTransferFcn_D * heli_q8_pres22_B.PitchCounttorad;
  tmp[2] = rtb_ElevationTransferFcn;
  tmp[3] = heli_q8_pres22_X.Integrator_CSTATE;
  tmp[4] = heli_q8_pres22_X.Integrator1_CSTATE;

  /* Sum: '<S4>/Sum1' incorporates:
   *  Constant: '<S4>/Constant3'
   *  Product: '<S4>/MatrixMultiply'
   */
  for (i = 0; i < 2; i++) {
    rtb_PitchTransferFcn = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_PitchTransferFcn += heli_q8_pres22_P.K[(i_0 << 1) + i] * tmp[i_0];
    }

    rtb_Sum1[i] = heli_q8_pres22_B.MatrixMultiply1[i] - rtb_PitchTransferFcn;
  }

  /* End of Sum: '<S4>/Sum1' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_PitchTransferFcn = rtb_Sum1[0] + heli_q8_pres22_P.vs_0;

  /* Sum: '<S1>/Add' */
  rtb_Frontgain = rtb_PitchTransferFcn - rtb_Sum1[1];

  /* Sum: '<S1>/Subtract' */
  rtb_PitchTransferFcn += rtb_Sum1[1];

  /* Gain: '<S1>/Back gain' */
  rtb_PitchTransferFcn *= heli_q8_pres22_P.Backgain_Gain;

  /* Gain: '<S1>/Front gain' */
  rtb_Frontgain *= heli_q8_pres22_P.Frontgain_Gain;
  if (rtmIsMajorTimeStep(heli_q8_pres22_M)) {
    /* Gain: '<S2>/Travel: Count to rad' */
    heli_q8_pres22_B.TravelCounttorad = heli_q8_pres22_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* Saturate: '<S2>/Front motor: Saturation' */
  if (rtb_Frontgain > heli_q8_pres22_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S2>/Front motor: Saturation' */
    heli_q8_pres22_B.FrontmotorSaturation =
      heli_q8_pres22_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Frontgain < heli_q8_pres22_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S2>/Front motor: Saturation' */
    heli_q8_pres22_B.FrontmotorSaturation =
      heli_q8_pres22_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Front motor: Saturation' */
    heli_q8_pres22_B.FrontmotorSaturation = rtb_Frontgain;
  }

  /* End of Saturate: '<S2>/Front motor: Saturation' */

  /* Saturate: '<S2>/Back motor: Saturation' */
  if (rtb_PitchTransferFcn > heli_q8_pres22_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S2>/Back motor: Saturation' */
    heli_q8_pres22_B.BackmotorSaturation =
      heli_q8_pres22_P.BackmotorSaturation_UpperSat;
  } else if (rtb_PitchTransferFcn <
             heli_q8_pres22_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S2>/Back motor: Saturation' */
    heli_q8_pres22_B.BackmotorSaturation =
      heli_q8_pres22_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Back motor: Saturation' */
    heli_q8_pres22_B.BackmotorSaturation = rtb_PitchTransferFcn;
  }

  /* End of Saturate: '<S2>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_pres22_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: heli_q8_pres22/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_pres22_DW.HILWriteAnalog_Buffer[0] =
        heli_q8_pres22_B.FrontmotorSaturation;
      heli_q8_pres22_DW.HILWriteAnalog_Buffer[1] =
        heli_q8_pres22_B.BackmotorSaturation;
      result = hil_write_analog(heli_q8_pres22_DW.HILInitialize_Card,
        heli_q8_pres22_P.HILWriteAnalog_channels, 2,
        &heli_q8_pres22_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
      }
    }

    /* Sum: '<S4>/Sum' */
    heli_q8_pres22_B.Sum = heli_q8_pres22_B.PitchCounttorad -
      rtb_Joystick_gain_x;
    for (i = 0; i < 5; i++) {
      /* Product: '<S5>/MatrixMultiply' incorporates:
       *  Constant: '<S5>/Constant1'
       */
      heli_q8_pres22_B.MatrixMultiply[i] = 0.0;
      heli_q8_pres22_B.MatrixMultiply[i] += heli_q8_pres22_P.G[i] *
        rtb_TmpSignalConversionAtMatr_0;
      heli_q8_pres22_B.MatrixMultiply[i] += heli_q8_pres22_P.G[i + 5] *
        rtb_TmpSignalConversionAtMatr_1;
    }

    /* Product: '<S5>/MatrixMultiply1' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    heli_q8_pres22_B.MatrixMultiply1_m[0] = 0.0;
    heli_q8_pres22_B.MatrixMultiply1_m[0] += heli_q8_pres22_P.F[0] *
      rtb_TmpSignalConversionAtMatr_0;
    heli_q8_pres22_B.MatrixMultiply1_m[0] += heli_q8_pres22_P.F[2] *
      rtb_TmpSignalConversionAtMatr_1;
    heli_q8_pres22_B.MatrixMultiply1_m[1] = 0.0;
    heli_q8_pres22_B.MatrixMultiply1_m[1] += heli_q8_pres22_P.F[1] *
      rtb_TmpSignalConversionAtMatr_0;
    heli_q8_pres22_B.MatrixMultiply1_m[1] += heli_q8_pres22_P.F[3] *
      rtb_TmpSignalConversionAtMatr_1;
  }

  /* Sum: '<S4>/Sum2' */
  heli_q8_pres22_B.Sum2 = rtb_ElevationTransferFcn -
    heli_q8_pres22_B.Joystick_gain_y;

  /* Sum: '<S5>/Sum1' incorporates:
   *  Constant: '<S5>/Constant3'
   *  Integrator: '<S5>/Integrator'
   *  Product: '<S5>/MatrixMultiply2'
   */
  for (i = 0; i < 2; i++) {
    rtb_PitchTransferFcn = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_PitchTransferFcn += heli_q8_pres22_P.K[(i_0 << 1) + i] *
        heli_q8_pres22_X.Integrator_CSTATE_m[i_0];
    }

    rtb_Sum1[i] = heli_q8_pres22_B.MatrixMultiply1_m[i] - rtb_PitchTransferFcn;
  }

  /* End of Sum: '<S5>/Sum1' */
  for (i = 0; i < 5; i++) {
    /* Sum: '<S5>/Sum2' incorporates:
     *  Constant: '<S5>/Constant5'
     *  Integrator: '<S5>/Integrator'
     *  Product: '<S5>/MatrixMultiply4'
     */
    rtb_PitchTransferFcn = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_PitchTransferFcn += heli_q8_pres22_P.A[5 * i_0 + i] *
        heli_q8_pres22_X.Integrator_CSTATE_m[i_0];
    }

    /* Sum: '<S5>/Sum2' incorporates:
     *  Constant: '<S5>/Constant4'
     *  Constant: '<S5>/Constant5'
     *  Product: '<S5>/MatrixMultiply3'
     *  Product: '<S5>/MatrixMultiply4'
     */
    heli_q8_pres22_B.Sum2_p[i] = (rtb_PitchTransferFcn +
      heli_q8_pres22_B.MatrixMultiply[i]) + (heli_q8_pres22_P.B[i + 5] *
      rtb_Sum1[1] + heli_q8_pres22_P.B[i] * rtb_Sum1[0]);
  }
}

/* Model update function for TID0 */
void heli_q8_pres22_update0(void)      /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(heli_q8_pres22_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_pres22_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_pres22_M->Timing.clockTick0)) {
    ++heli_q8_pres22_M->Timing.clockTickH0;
  }

  heli_q8_pres22_M->Timing.t[0] = rtsiGetSolverStopTime
    (&heli_q8_pres22_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_pres22_M->Timing.clockTick1)) {
    ++heli_q8_pres22_M->Timing.clockTickH1;
  }

  heli_q8_pres22_M->Timing.t[1] = heli_q8_pres22_M->Timing.clockTick1 *
    heli_q8_pres22_M->Timing.stepSize1 + heli_q8_pres22_M->Timing.clockTickH1 *
    heli_q8_pres22_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_pres22_derivatives(void)
{
  XDot_heli_q8_pres22_T *_rtXdot;
  int32_T i;
  _rtXdot = ((XDot_heli_q8_pres22_T *) heli_q8_pres22_M->derivs);

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_pres22_P.PitchTransferFcn_A *
    heli_q8_pres22_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_pres22_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    heli_q8_pres22_P.ElevationTransferFcn_A *
    heli_q8_pres22_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_pres22_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE = heli_q8_pres22_B.Sum;

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = heli_q8_pres22_B.Sum2;

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_pres22_P.TravelTransferFcn_A *
    heli_q8_pres22_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_pres22_B.TravelCounttorad;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  for (i = 0; i < 5; i++) {
    _rtXdot->Integrator_CSTATE_m[i] = heli_q8_pres22_B.Sum2_p[i];
  }

  /* End of Derivatives for Integrator: '<S5>/Integrator' */
}

/* Model output function for TID2 */
void heli_q8_pres22_output2(void)      /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: heli_q8_pres22/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_pres22_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_q8_pres22_DW.GameController_Controller,
        &state, &new_data);
      if (result < 0) {
        new_data = false;
      }

      rtb_GameController_o4 = state.x;
      rtb_GameController_o5 = state.y;
    } else {
      rtb_GameController_o4 = 0;
      rtb_GameController_o5 = 0;
    }
  }

  /* RateTransition: '<S3>/Rate Transition: x' */
  heli_q8_pres22_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S3>/Rate Transition: y' */
  heli_q8_pres22_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void heli_q8_pres22_update2(void)      /* Sample time: [0.01s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_pres22_M->Timing.clockTick2)) {
    ++heli_q8_pres22_M->Timing.clockTickH2;
  }

  heli_q8_pres22_M->Timing.t[2] = heli_q8_pres22_M->Timing.clockTick2 *
    heli_q8_pres22_M->Timing.stepSize2 + heli_q8_pres22_M->Timing.clockTickH2 *
    heli_q8_pres22_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_pres22_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_pres22_output0();
    break;

   case 2 :
    heli_q8_pres22_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_pres22_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_pres22_update0();
    break;

   case 2 :
    heli_q8_pres22_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_pres22_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_pres22/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_pres22_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_q8_pres22_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_pres22_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
      return;
    }

    if ((heli_q8_pres22_P.HILInitialize_AIPStart && !is_switching) ||
        (heli_q8_pres22_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_pres22_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (heli_q8_pres22_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_pres22_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_q8_pres22_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(heli_q8_pres22_DW.HILInitialize_Card,
        heli_q8_pres22_P.HILInitialize_AIChannels, 8U,
        &heli_q8_pres22_DW.HILInitialize_AIMinimums[0],
        &heli_q8_pres22_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_pres22_P.HILInitialize_AOPStart && !is_switching) ||
        (heli_q8_pres22_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_pres22_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (heli_q8_pres22_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_pres22_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_q8_pres22_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(heli_q8_pres22_DW.HILInitialize_Card,
        heli_q8_pres22_P.HILInitialize_AOChannels, 8U,
        &heli_q8_pres22_DW.HILInitialize_AOMinimums[0],
        &heli_q8_pres22_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_pres22_P.HILInitialize_AOStart && !is_switching) ||
        (heli_q8_pres22_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_pres22_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_pres22_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(heli_q8_pres22_DW.HILInitialize_Card,
        heli_q8_pres22_P.HILInitialize_AOChannels, 8U,
        &heli_q8_pres22_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_pres22_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_pres22_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_pres22_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_pres22_DW.HILInitialize_Card,
         heli_q8_pres22_P.HILInitialize_AOChannels, 8U,
         &heli_q8_pres22_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_pres22_P.HILInitialize_EIPStart && !is_switching) ||
        (heli_q8_pres22_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_pres22_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_pres22_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (heli_q8_pres22_DW.HILInitialize_Card,
         heli_q8_pres22_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &heli_q8_pres22_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_pres22_P.HILInitialize_EIStart && !is_switching) ||
        (heli_q8_pres22_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_pres22_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = heli_q8_pres22_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(heli_q8_pres22_DW.HILInitialize_Card,
        heli_q8_pres22_P.HILInitialize_EIChannels, 8U,
        &heli_q8_pres22_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_pres22_P.HILInitialize_POPStart && !is_switching) ||
        (heli_q8_pres22_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_pres22_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_pres22_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_pres22_DW.HILInitialize_Card,
        heli_q8_pres22_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &heli_q8_pres22_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          heli_q8_pres22_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &heli_q8_pres22_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            heli_q8_pres22_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            heli_q8_pres22_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              heli_q8_pres22_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_pres22_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            heli_q8_pres22_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] = heli_q8_pres22_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_pres22_DW.HILInitialize_Card,
          &heli_q8_pres22_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes, &heli_q8_pres22_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_pres22_DW.HILInitialize_Card,
          &heli_q8_pres22_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_pres22_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_pres22_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_pres22_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &heli_q8_pres22_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_pres22_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &heli_q8_pres22_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_pres22_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_pres22_DW.HILInitialize_Card,
        heli_q8_pres22_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &heli_q8_pres22_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_q8_pres22_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_pres22_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &heli_q8_pres22_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_q8_pres22_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_pres22_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_pres22_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_pres22_DW.HILInitialize_Card,
        heli_q8_pres22_P.HILInitialize_POChannels, 8U,
        &heli_q8_pres22_DW.HILInitialize_POSortedFreqs[0],
        &heli_q8_pres22_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_pres22_P.HILInitialize_POStart && !is_switching) ||
        (heli_q8_pres22_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_pres22_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_pres22_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(heli_q8_pres22_DW.HILInitialize_Card,
        heli_q8_pres22_P.HILInitialize_POChannels, 8U,
        &heli_q8_pres22_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_pres22_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_pres22_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_pres22_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_pres22_DW.HILInitialize_Card,
         heli_q8_pres22_P.HILInitialize_POChannels, 8U,
         &heli_q8_pres22_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8_pres22/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_q8_pres22_DW.HILInitialize_Card,
      heli_q8_pres22_P.HILReadEncoderTimebase_SamplesI,
      heli_q8_pres22_P.HILReadEncoderTimebase_Channels, 3,
      &heli_q8_pres22_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (heli_q8_pres22_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (heli_q8_pres22_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  heli_q8_pres22_B.RateTransitionx =
    heli_q8_pres22_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  heli_q8_pres22_B.RateTransitiony =
    heli_q8_pres22_P.RateTransitiony_InitialConditio;

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: heli_q8_pres22/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_pres22_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (heli_q8_pres22_P.GameController_ControllerNumber,
         heli_q8_pres22_P.GameController_BufferSize, deadzone, saturation,
         heli_q8_pres22_P.GameController_AutoCenter, 0, 1.0,
         &heli_q8_pres22_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
    heli_q8_pres22_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
    heli_q8_pres22_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S4>/Integrator' */
    heli_q8_pres22_X.Integrator_CSTATE = heli_q8_pres22_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S4>/Integrator1' */
    heli_q8_pres22_X.Integrator1_CSTATE = heli_q8_pres22_P.Integrator1_IC;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
    heli_q8_pres22_DW.RateTransitionx_Buffer0 =
      heli_q8_pres22_P.RateTransitionx_InitialConditio;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
    heli_q8_pres22_DW.RateTransitiony_Buffer0 =
      heli_q8_pres22_P.RateTransitiony_InitialConditio;

    /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
    heli_q8_pres22_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S5>/Integrator' */
    for (i = 0; i < 5; i++) {
      heli_q8_pres22_X.Integrator_CSTATE_m[i] = heli_q8_pres22_P.Integrator_IC_k;
    }

    /* End of InitializeConditions for Integrator: '<S5>/Integrator' */
  }
}

/* Model terminate function */
void heli_q8_pres22_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_pres22/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_pres22_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_pres22_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_pres22_P.HILInitialize_AOTerminate && !is_switching) ||
        (heli_q8_pres22_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_pres22_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_pres22_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((heli_q8_pres22_P.HILInitialize_POTerminate && !is_switching) ||
        (heli_q8_pres22_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_pres22_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_pres22_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_pres22_DW.HILInitialize_Card
                         , heli_q8_pres22_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , heli_q8_pres22_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_pres22_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_pres22_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_pres22_DW.HILInitialize_Card,
            heli_q8_pres22_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &heli_q8_pres22_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_pres22_DW.HILInitialize_Card,
            heli_q8_pres22_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &heli_q8_pres22_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_pres22_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_pres22_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_pres22_DW.HILInitialize_Card);
    hil_close(heli_q8_pres22_DW.HILInitialize_Card);
    heli_q8_pres22_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: heli_q8_pres22/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_pres22_P.GameController_Enabled) {
      game_controller_close(heli_q8_pres22_DW.GameController_Controller);
      heli_q8_pres22_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_pres22_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_pres22_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  heli_q8_pres22_initialize();
}

void MdlTerminate(void)
{
  heli_q8_pres22_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_pres22_T *heli_q8_pres22(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)heli_q8_pres22_M, 0,
                sizeof(RT_MODEL_heli_q8_pres22_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_pres22_M->solverInfo,
                          &heli_q8_pres22_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_pres22_M->solverInfo, &rtmGetTPtr(heli_q8_pres22_M));
    rtsiSetStepSizePtr(&heli_q8_pres22_M->solverInfo,
                       &heli_q8_pres22_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_pres22_M->solverInfo, &heli_q8_pres22_M->derivs);
    rtsiSetContStatesPtr(&heli_q8_pres22_M->solverInfo, (real_T **)
                         &heli_q8_pres22_M->contStates);
    rtsiSetNumContStatesPtr(&heli_q8_pres22_M->solverInfo,
      &heli_q8_pres22_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_pres22_M->solverInfo,
      &heli_q8_pres22_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_pres22_M->solverInfo,
      &heli_q8_pres22_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_pres22_M->solverInfo,
      &heli_q8_pres22_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_pres22_M->solverInfo, (&rtmGetErrorStatus
      (heli_q8_pres22_M)));
    rtsiSetRTModelPtr(&heli_q8_pres22_M->solverInfo, heli_q8_pres22_M);
  }

  rtsiSetSimTimeStep(&heli_q8_pres22_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_pres22_M->intgData.f[0] = heli_q8_pres22_M->odeF[0];
  heli_q8_pres22_M->contStates = ((real_T *) &heli_q8_pres22_X);
  rtsiSetSolverData(&heli_q8_pres22_M->solverInfo, (void *)
                    &heli_q8_pres22_M->intgData);
  rtsiSetSolverName(&heli_q8_pres22_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_pres22_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_pres22_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_pres22_M->Timing.sampleTimes =
      (&heli_q8_pres22_M->Timing.sampleTimesArray[0]);
    heli_q8_pres22_M->Timing.offsetTimes =
      (&heli_q8_pres22_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_pres22_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_pres22_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_pres22_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_pres22_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_pres22_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_pres22_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_pres22_M, &heli_q8_pres22_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_pres22_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      heli_q8_pres22_M->Timing.perTaskSampleHitsArray;
    heli_q8_pres22_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_pres22_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_pres22_M, -1);
  heli_q8_pres22_M->Timing.stepSize0 = 0.002;
  heli_q8_pres22_M->Timing.stepSize1 = 0.002;
  heli_q8_pres22_M->Timing.stepSize2 = 0.01;
  heli_q8_pres22_M->solverInfoPtr = (&heli_q8_pres22_M->solverInfo);
  heli_q8_pres22_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_pres22_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_pres22_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_pres22_M->blockIO = ((void *) &heli_q8_pres22_B);

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      heli_q8_pres22_B.MatrixMultiply[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      heli_q8_pres22_B.Sum2_p[i] = 0.0;
    }

    heli_q8_pres22_B.PitchCounttorad = 0.0;
    heli_q8_pres22_B.ElevationCounttorad = 0.0;
    heli_q8_pres22_B.RateTransitionx = 0.0;
    heli_q8_pres22_B.RateTransitiony = 0.0;
    heli_q8_pres22_B.Joystick_gain_y = 0.0;
    heli_q8_pres22_B.MatrixMultiply1[0] = 0.0;
    heli_q8_pres22_B.MatrixMultiply1[1] = 0.0;
    heli_q8_pres22_B.TravelCounttorad = 0.0;
    heli_q8_pres22_B.FrontmotorSaturation = 0.0;
    heli_q8_pres22_B.BackmotorSaturation = 0.0;
    heli_q8_pres22_B.Sum = 0.0;
    heli_q8_pres22_B.Sum2 = 0.0;
    heli_q8_pres22_B.MatrixMultiply1_m[0] = 0.0;
    heli_q8_pres22_B.MatrixMultiply1_m[1] = 0.0;
  }

  /* parameters */
  heli_q8_pres22_M->defaultParam = ((real_T *)&heli_q8_pres22_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_pres22_X;
    heli_q8_pres22_M->contStates = (x);
    (void) memset((void *)&heli_q8_pres22_X, 0,
                  sizeof(X_heli_q8_pres22_T));
  }

  /* states (dwork) */
  heli_q8_pres22_M->dwork = ((void *) &heli_q8_pres22_DW);
  (void) memset((void *)&heli_q8_pres22_DW, 0,
                sizeof(DW_heli_q8_pres22_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres22_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres22_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres22_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres22_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres22_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres22_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres22_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres22_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_q8_pres22_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_pres22_DW.RateTransitiony_Buffer0 = 0.0;
  heli_q8_pres22_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_pres22_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* Initialize Sizes */
  heli_q8_pres22_M->Sizes.numContStates = (10);/* Number of continuous states */
  heli_q8_pres22_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  heli_q8_pres22_M->Sizes.numY = (0);  /* Number of model outputs */
  heli_q8_pres22_M->Sizes.numU = (0);  /* Number of model inputs */
  heli_q8_pres22_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_pres22_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_q8_pres22_M->Sizes.numBlocks = (50);/* Number of blocks */
  heli_q8_pres22_M->Sizes.numBlockIO = (14);/* Number of block outputs */
  heli_q8_pres22_M->Sizes.numBlockPrms = (199);/* Sum of parameter "widths" */
  return heli_q8_pres22_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
