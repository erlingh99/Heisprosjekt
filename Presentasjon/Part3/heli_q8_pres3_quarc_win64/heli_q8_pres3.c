/*
 * heli_q8_pres3.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_pres3".
 *
 * Model version              : 11.121
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed Nov 17 13:23:36 2021
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_pres3.h"
#include "heli_q8_pres3_private.h"

t_stream heli_q8_pres3_rtZt_stream = NULL;

/* Block signals (default storage) */
B_heli_q8_pres3_T heli_q8_pres3_B;

/* Continuous states */
X_heli_q8_pres3_T heli_q8_pres3_X;

/* Block states (default storage) */
DW_heli_q8_pres3_T heli_q8_pres3_DW;

/* Real-time model */
static RT_MODEL_heli_q8_pres3_T heli_q8_pres3_M_;
RT_MODEL_heli_q8_pres3_T *const heli_q8_pres3_M = &heli_q8_pres3_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_pres3_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_pres3_M, 2);
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
  if (heli_q8_pres3_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_pres3_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_pres3_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_pres3_M->Timing.perTaskSampleHits[5] =
      heli_q8_pres3_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_pres3_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_pres3_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_pres3_M->Timing.TaskCounters.TID[2] = 0;
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
  heli_q8_pres3_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void heli_q8_pres3_output0(void)       /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamCall1_o1;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamCall1_o3;
  int32_T rtb_StreamRead1_o5;
  uint8_T rtb_StreamCall1_o2;
  boolean_T rtb_StreamRead1_o3;
  real_T tmp_1[9];
  real_T rtb_p_0[5];
  real_T tmp[5];
  real_T tmp_0[5];
  real_T rtb_Gain2[3];
  real_T tmp_2[3];
  real_T rtb_Sum1[2];
  real_T rtb_Backgain;
  real_T rtb_Frontgain;
  real_T rtb_e;
  real_T rtb_euler_rates_tmp;
  real_T rtb_euler_rates_tmp_0;
  real_T rtb_euler_rates_tmp_1;
  real_T rtb_euler_rates_tmp_2;
  real_T rtb_p;
  int32_T i;
  int32_T i_0;
  int32_T tmp_3;
  if (rtmIsMajorTimeStep(heli_q8_pres3_M)) {
    /* set solver stop time */
    if (!(heli_q8_pres3_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_pres3_M->solverInfo,
                            ((heli_q8_pres3_M->Timing.clockTickH0 + 1) *
        heli_q8_pres3_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_pres3_M->solverInfo,
                            ((heli_q8_pres3_M->Timing.clockTick0 + 1) *
        heli_q8_pres3_M->Timing.stepSize0 + heli_q8_pres3_M->Timing.clockTickH0 *
        heli_q8_pres3_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_pres3_M)) {
    heli_q8_pres3_M->Timing.t[0] = rtsiGetT(&heli_q8_pres3_M->solverInfo);
  }

  /* RateTransition: '<S5>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(heli_q8_pres3_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_pres3/Heli 3D1/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (heli_q8_pres3_DW.HILReadEncoderTimebase_Task, 1,
         &heli_q8_pres3_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_pres3_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_q8_pres3_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          heli_q8_pres3_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* S-Function (stream_call_block): '<S4>/Stream Call1' incorporates:
     *  Constant: '<S4>/Constant'
     *  S-Function (string_constant_block): '<S4>/String Constant'
     */

    /* S-Function Block: heli_q8_pres3/IMU1/Stream Call1 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (heli_q8_pres3_P.Constant_Value != 0);
      rtb_StreamCall1_o1 = NULL;
      switch (heli_q8_pres3_DW.StreamCall1_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) heli_q8_pres3_P.StringConstant_Value, 255)
                == 255) {
              rtmSetErrorStatus(heli_q8_pres3_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *)
                heli_q8_pres3_P.StringConstant_Value,
                heli_q8_pres3_P.StreamCall1_NonBlocking != 0,
                heli_q8_pres3_P.StreamCall1_SendBufferSize,
                heli_q8_pres3_P.StreamCall1_ReceiveBufferSize,
                &heli_q8_pres3_DW.StreamCall1_Stream);
              if (result == 0) {
                heli_q8_pres3_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(heli_q8_pres3_DW.StreamCall1_Stream,
                                      (t_stream_byte_order)
                                      heli_q8_pres3_P.StreamCall1_Endian);
                rtb_StreamCall1_o1 = &heli_q8_pres3_DW.StreamCall1_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                heli_q8_pres3_DW.StreamCall1_State =
                  STREAM_CALL_STATE_CONNECTING;
                result = 0;
              }
            }
          }
          break;
        }

       case STREAM_CALL_STATE_CONNECTING:
        {
          if (!close_flag) {
            const t_timeout timeout = { 0, 0, false };/* zero seconds */

            result = stream_poll(heli_q8_pres3_DW.StreamCall1_Stream, &timeout,
                                 STREAM_POLL_CONNECT);
            if (result > 0) {
              heli_q8_pres3_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_q8_pres3_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    heli_q8_pres3_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &heli_q8_pres3_DW.StreamCall1_Stream;
              result = 0;
              break;
            } else if (result == 0) {
              break;
            }
          }

          /* Fall through deliberately */
        }

       case STREAM_CALL_STATE_CONNECTED:
        {
          rtb_StreamCall1_o1 = &heli_q8_pres3_DW.StreamCall1_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close
            (heli_q8_pres3_DW.StreamCall1_Stream);
          if (close_result == 0) {
            heli_q8_pres3_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
            heli_q8_pres3_DW.StreamCall1_Stream = NULL;
            rtb_StreamCall1_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      rtb_StreamCall1_o2 = heli_q8_pres3_DW.StreamCall1_State;
      rtb_StreamCall1_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_write_block): '<S4>/Stream Formatted Write' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    {
      t_error result;
      if (rtb_StreamCall1_o1 != NULL) {
        result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
          heli_q8_pres3_P.StreamFormattedWrite_MaxUnits,
          &rtb_StreamFormattedWrite_o2, "%c\n"
          , (char) heli_q8_pres3_P.Constant1_Value
          );
        if (result > 0) {
          result = stream_flush(*rtb_StreamCall1_o1);
        }

        if (result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      }
    }

    /* S-Function (stream_read_block): '<S4>/Stream Read1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  S-Function (stream_call_block): '<S4>/Stream Call1'
     *  S-Function (stream_formatted_write_block): '<S4>/Stream Formatted Write'
     */

    /* S-Function Block: heli_q8_pres3/IMU1/Stream Read1 (stream_read_block) */
    {
      t_error result;
      memset(&rtb_StreamRead1_o2[0], 0, 10 * sizeof(real32_T));
      if (((t_stream_ptr)rtb_StreamCall1_o1) != NULL) {
        result = stream_receive_unit_array(*((t_stream_ptr)rtb_StreamCall1_o1),
          &rtb_StreamRead1_o2[0], sizeof(real32_T), 10);
        rtb_StreamRead1_o3 = (result > 0);
        if (result > 0 || result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      } else {
        rtb_StreamRead1_o3 = false;
        result = 0;
      }

      rtb_StreamRead1_o5 = (int32_T) result;
    }

    for (i = 0; i < 10; i++) {
      /* Switch: '<S4>/Switch' */
      if (rtb_StreamRead1_o3) {
        /* Switch: '<S4>/Switch' incorporates:
         *  DataTypeConversion: '<S4>/Data Type Conversion'
         */
        heli_q8_pres3_B.Switch[i] = rtb_StreamRead1_o2[i];
      } else {
        /* Switch: '<S4>/Switch' incorporates:
         *  Memory: '<S4>/Memory'
         */
        heli_q8_pres3_B.Switch[i] = heli_q8_pres3_DW.Memory_PreviousInput[i];
      }

      /* End of Switch: '<S4>/Switch' */
    }

    /* Gain: '<S4>/Gain2' */
    for (i = 0; i < 3; i++) {
      rtb_Gain2[i] = heli_q8_pres3_P.Gain2_Gain[i + 6] * heli_q8_pres3_B.Switch
        [2] + (heli_q8_pres3_P.Gain2_Gain[i + 3] * heli_q8_pres3_B.Switch[1] +
               heli_q8_pres3_P.Gain2_Gain[i] * heli_q8_pres3_B.Switch[0]);
    }

    /* End of Gain: '<S4>/Gain2' */

    /* MATLAB Function: '<Root>/MATLAB Function1' */
    /* MATLAB Function 'MATLAB Function1': '<S7>:1' */
    /* '<S7>:1:3' */
    if (rtb_Gain2[2] == 0.0) {
      /* '<S7>:1:4' */
      /* '<S7>:1:5' */
      if (rtb_Gain2[1] < 0.0) {
        rtb_e = -1.0;
      } else if (rtb_Gain2[1] > 0.0) {
        rtb_e = 1.0;
      } else if (rtb_Gain2[1] == 0.0) {
        rtb_e = 0.0;
      } else {
        rtb_e = (rtNaN);
      }

      rtb_p = rtb_e * 3.1415926535897931 / 2.0;
    } else {
      /* '<S7>:1:7' */
      rtb_p = atan(rtb_Gain2[1] / rtb_Gain2[2]);
    }

    if ((rtb_Gain2[1] == 0.0) && (rtb_Gain2[2] == 0.0)) {
      /* '<S7>:1:10' */
      /* '<S7>:1:11' */
      if (rtb_Gain2[0] < 0.0) {
        rtb_e = -1.0;
      } else if (rtb_Gain2[0] > 0.0) {
        rtb_e = 1.0;
      } else if (rtb_Gain2[0] == 0.0) {
        rtb_e = 0.0;
      } else {
        rtb_e = (rtNaN);
      }

      rtb_e = rtb_e * 3.1415926535897931 / 2.0;
    } else {
      /* '<S7>:1:13' */
      rtb_e = atan(rtb_Gain2[0] / sqrt(rtb_Gain2[1] * rtb_Gain2[1] + rtb_Gain2[2]
        * rtb_Gain2[2]));
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function1' */

    /* Sum: '<Root>/Add1' incorporates:
     *  Constant: '<Root>/p_bias'
     */
    rtb_p += heli_q8_pres3_P.p_bias_Value;

    /* Sum: '<Root>/Add2' incorporates:
     *  Constant: '<Root>/e_bias'
     */
    rtb_e += heli_q8_pres3_P.e_bias_Value;
    if (heli_q8_pres3_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S5>/Rate Transition: x' */
      heli_q8_pres3_B.RateTransitionx = heli_q8_pres3_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S5>/Dead Zone: x' */
    if (heli_q8_pres3_B.RateTransitionx > heli_q8_pres3_P.DeadZonex_End) {
      rtb_Backgain = heli_q8_pres3_B.RateTransitionx -
        heli_q8_pres3_P.DeadZonex_End;
    } else if (heli_q8_pres3_B.RateTransitionx >=
               heli_q8_pres3_P.DeadZonex_Start) {
      rtb_Backgain = 0.0;
    } else {
      rtb_Backgain = heli_q8_pres3_B.RateTransitionx -
        heli_q8_pres3_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S5>/Dead Zone: x' */

    /* Gain: '<S5>/Joystick_gain_x' incorporates:
     *  Gain: '<S5>/Gain: x'
     */
    heli_q8_pres3_B.Joystick_gain_x = heli_q8_pres3_P.Gainx_Gain * rtb_Backgain *
      heli_q8_pres3_P.Joystick_gain_x;

    /* RateTransition: '<S5>/Rate Transition: y' */
    if (heli_q8_pres3_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S5>/Rate Transition: y' */
      heli_q8_pres3_B.RateTransitiony = heli_q8_pres3_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S5>/Rate Transition: y' */

    /* DeadZone: '<S5>/Dead Zone: y' */
    if (heli_q8_pres3_B.RateTransitiony > heli_q8_pres3_P.DeadZoney_End) {
      rtb_Backgain = heli_q8_pres3_B.RateTransitiony -
        heli_q8_pres3_P.DeadZoney_End;
    } else if (heli_q8_pres3_B.RateTransitiony >=
               heli_q8_pres3_P.DeadZoney_Start) {
      rtb_Backgain = 0.0;
    } else {
      rtb_Backgain = heli_q8_pres3_B.RateTransitiony -
        heli_q8_pres3_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S5>/Dead Zone: y' */

    /* Gain: '<S5>/Joystick_gain_y' incorporates:
     *  Gain: '<S5>/Gain: y'
     */
    heli_q8_pres3_B.Joystick_gain_y = heli_q8_pres3_P.Gainy_Gain * rtb_Backgain *
      heli_q8_pres3_P.Joystick_gain_y;

    /* Gain: '<S6>/Multiply' incorporates:
     *  SignalConversion generated from: '<S6>/Multiply'
     */
    heli_q8_pres3_B.Multiply[0] = 0.0;
    heli_q8_pres3_B.Multiply[0] += heli_q8_pres3_P.F[0] *
      heli_q8_pres3_B.Joystick_gain_x;
    heli_q8_pres3_B.Multiply[0] += heli_q8_pres3_P.F[2] *
      heli_q8_pres3_B.Joystick_gain_y;
    heli_q8_pres3_B.Multiply[1] = 0.0;
    heli_q8_pres3_B.Multiply[1] += heli_q8_pres3_P.F[1] *
      heli_q8_pres3_B.Joystick_gain_x;
    heli_q8_pres3_B.Multiply[1] += heli_q8_pres3_P.F[3] *
      heli_q8_pres3_B.Joystick_gain_y;
  }

  /* End of RateTransition: '<S5>/Rate Transition: x' */

  /* SignalConversion generated from: '<S6>/Multiply1' incorporates:
   *  Integrator: '<S6>/Integrator'
   *  Integrator: '<S6>/Integrator1'
   *  Integrator: '<S8>/Integrator'
   */
  rtb_p_0[0] = heli_q8_pres3_X.Integrator_CSTATE[0];
  rtb_p_0[1] = heli_q8_pres3_X.Integrator_CSTATE[1];
  rtb_p_0[2] = heli_q8_pres3_X.Integrator_CSTATE[3];
  rtb_p_0[3] = heli_q8_pres3_X.Integrator_CSTATE_d;
  rtb_p_0[4] = heli_q8_pres3_X.Integrator1_CSTATE;

  /* Sum: '<S6>/Sum1' incorporates:
   *  Gain: '<S6>/Multiply1'
   */
  for (i = 0; i < 2; i++) {
    rtb_Backgain = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_Backgain += heli_q8_pres3_P.K[(i_0 << 1) + i] * rtb_p_0[i_0];
    }

    rtb_Sum1[i] = heli_q8_pres3_B.Multiply[i] - rtb_Backgain;
  }

  /* End of Sum: '<S6>/Sum1' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtb_Backgain = heli_q8_pres3_P.vs_0 + rtb_Sum1[0];

  /* Sum: '<S1>/Add' */
  rtb_Frontgain = rtb_Backgain - rtb_Sum1[1];

  /* Sum: '<S1>/Subtract' */
  rtb_Backgain += rtb_Sum1[1];

  /* Gain: '<S1>/Back gain' */
  rtb_Backgain *= heli_q8_pres3_P.Backgain_Gain;

  /* Gain: '<S1>/Front gain' */
  rtb_Frontgain *= heli_q8_pres3_P.Frontgain_Gain;
  if (rtmIsMajorTimeStep(heli_q8_pres3_M)) {
    /* Gain: '<S3>/Travel: Count to rad' */
    heli_q8_pres3_B.TravelCounttorad = heli_q8_pres3_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travel rate]' incorporates:
     *  SignalConversion generated from: '<S2>/ SFunction '
     */
    /* MATLAB Function 'Gyro vector to [pitch rate, elevation rate, travel rate]': '<S2>:1' */
    /* '<S2>:1:3' */
    /* '<S2>:1:4' */
    /* '<S2>:1:8' */
    /* '<S2>:1:11' */
    rtb_euler_rates_tmp = tan(rtb_e);
    rtb_euler_rates_tmp_0 = sin(rtb_p);
    rtb_euler_rates_tmp_1 = cos(rtb_p);
    rtb_euler_rates_tmp_2 = cos(rtb_e);
    tmp_1[0] = 1.0;
    tmp_1[3] = rtb_euler_rates_tmp_0 * rtb_euler_rates_tmp;
    tmp_1[6] = rtb_euler_rates_tmp_1 * rtb_euler_rates_tmp;
    tmp_1[1] = 0.0;
    tmp_1[4] = rtb_euler_rates_tmp_1;
    tmp_1[7] = -rtb_euler_rates_tmp_0;
    tmp_1[2] = 0.0;
    tmp_1[5] = rtb_euler_rates_tmp_0 / rtb_euler_rates_tmp_2;
    tmp_1[8] = rtb_euler_rates_tmp_1 / rtb_euler_rates_tmp_2;

    /* Gain: '<S4>/Gain1' */
    for (i = 0; i < 3; i++) {
      tmp_2[i] = heli_q8_pres3_P.Gain1_Gain[i + 6] * heli_q8_pres3_B.Switch[5] +
        (heli_q8_pres3_P.Gain1_Gain[i + 3] * heli_q8_pres3_B.Switch[4] +
         heli_q8_pres3_P.Gain1_Gain[i] * heli_q8_pres3_B.Switch[3]);
    }

    /* End of Gain: '<S4>/Gain1' */

    /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travel rate]' */
    for (i = 0; i < 3; i++) {
      rtb_Gain2[i] = tmp_1[i + 6] * tmp_2[2] + (tmp_1[i + 3] * tmp_2[1] +
        tmp_1[i] * tmp_2[0]);
    }

    /* SignalConversion generated from: '<Root>/Gain' */
    rtb_p_0[0] = rtb_p;
    rtb_p_0[1] = rtb_Gain2[0];
    rtb_p_0[2] = rtb_e;
    rtb_p_0[3] = rtb_Gain2[1];
    rtb_p_0[4] = rtb_Gain2[2];
    for (i = 0; i < 5; i++) {
      /* Gain: '<Root>/Gain' */
      heli_q8_pres3_B.Gain[i] = 0.0;
      for (i_0 = 0; i_0 < 5; i_0++) {
        heli_q8_pres3_B.Gain[i] += heli_q8_pres3_P.C[5 * i_0 + i] * rtb_p_0[i_0];
      }

      /* End of Gain: '<Root>/Gain' */
    }

    /* Gain: '<S3>/Elevation: Count to rad' */
    heli_q8_pres3_B.ElevationCounttorad =
      heli_q8_pres3_P.ElevationCounttorad_Gain * rtb_HILReadEncoderTimebase_o3;

    /* Gain: '<S3>/Pitch: Count to rad' */
    heli_q8_pres3_B.PitchCounttorad = heli_q8_pres3_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;
  }

  /* Saturate: '<S3>/Front motor: Saturation' */
  if (rtb_Frontgain > heli_q8_pres3_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S3>/Front motor: Saturation' */
    heli_q8_pres3_B.FrontmotorSaturation =
      heli_q8_pres3_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Frontgain < heli_q8_pres3_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S3>/Front motor: Saturation' */
    heli_q8_pres3_B.FrontmotorSaturation =
      heli_q8_pres3_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S3>/Front motor: Saturation' */
    heli_q8_pres3_B.FrontmotorSaturation = rtb_Frontgain;
  }

  /* End of Saturate: '<S3>/Front motor: Saturation' */

  /* Saturate: '<S3>/Back motor: Saturation' */
  if (rtb_Backgain > heli_q8_pres3_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S3>/Back motor: Saturation' */
    heli_q8_pres3_B.BackmotorSaturation =
      heli_q8_pres3_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Backgain < heli_q8_pres3_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S3>/Back motor: Saturation' */
    heli_q8_pres3_B.BackmotorSaturation =
      heli_q8_pres3_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S3>/Back motor: Saturation' */
    heli_q8_pres3_B.BackmotorSaturation = rtb_Backgain;
  }

  /* End of Saturate: '<S3>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_pres3_M)) {
    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: heli_q8_pres3/Heli 3D1/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_pres3_DW.HILWriteAnalog_Buffer[0] =
        heli_q8_pres3_B.FrontmotorSaturation;
      heli_q8_pres3_DW.HILWriteAnalog_Buffer[1] =
        heli_q8_pres3_B.BackmotorSaturation;
      result = hil_write_analog(heli_q8_pres3_DW.HILInitialize1_Card,
        heli_q8_pres3_P.HILWriteAnalog_channels, 2,
        &heli_q8_pres3_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
      }
    }

    /* S-Function (stop_with_error_block): '<S4>/Stop with Call Error' */

    /* S-Function Block: heli_q8_pres3/IMU1/Stop with Call Error (stop_with_error_block) */
    {
      if (rtb_StreamCall1_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall1_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (stop_with_error_block): '<S4>/Stop with Read Error' */

    /* S-Function Block: heli_q8_pres3/IMU1/Stop with Read Error (stop_with_error_block) */
    {
      if (rtb_StreamRead1_o5 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }
    }
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Integrator: '<S8>/Integrator'
   */
  heli_q8_pres3_B.Sum = heli_q8_pres3_X.Integrator_CSTATE[0] -
    heli_q8_pres3_B.Joystick_gain_x;

  /* Sum: '<S6>/Sum2' incorporates:
   *  Integrator: '<S8>/Integrator'
   */
  heli_q8_pres3_B.Sum2 = heli_q8_pres3_X.Integrator_CSTATE[3] -
    heli_q8_pres3_B.Joystick_gain_y;
  for (i = 0; i < 5; i++) {
    /* Sum: '<S8>/Sum' incorporates:
     *  Gain: '<S8>/Multiply3'
     *  Integrator: '<S8>/Integrator'
     */
    rtb_Backgain = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_Backgain += heli_q8_pres3_P.C[5 * i_0 + i] *
        heli_q8_pres3_X.Integrator_CSTATE[i_0];
    }

    rtb_p_0[i] = heli_q8_pres3_B.Gain[i] - rtb_Backgain;

    /* End of Sum: '<S8>/Sum' */

    /* Gain: '<S8>/Multiply1' */
    tmp[i] = heli_q8_pres3_P.B_est[i + 5] * rtb_Sum1[1] +
      heli_q8_pres3_P.B_est[i] * rtb_Sum1[0];
  }

  for (i = 0; i < 5; i++) {
    /* Gain: '<S8>/Multiply2' */
    tmp_0[i] = 0.0;

    /* Sum: '<S8>/Sum2' */
    rtb_Backgain = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      /* Sum: '<S8>/Sum2' incorporates:
       *  Gain: '<S8>/Multiply'
       *  Gain: '<S8>/Multiply2'
       */
      tmp_3 = 5 * i_0 + i;

      /* Sum: '<S8>/Sum2' incorporates:
       *  Gain: '<S8>/Multiply'
       *  Integrator: '<S8>/Integrator'
       */
      rtb_Backgain += heli_q8_pres3_P.A_est[tmp_3] *
        heli_q8_pres3_X.Integrator_CSTATE[i_0];

      /* Gain: '<S8>/Multiply2' */
      tmp_0[i] += heli_q8_pres3_P.L[tmp_3] * rtb_p_0[i_0];
    }

    /* Sum: '<S8>/Sum2' incorporates:
     *  Gain: '<S8>/Multiply'
     */
    heli_q8_pres3_B.Sum2_b[i] = (tmp[i] + tmp_0[i]) + rtb_Backgain;
  }
}

/* Model update function for TID0 */
void heli_q8_pres3_update0(void)       /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(heli_q8_pres3_M)) {
    /* Update for Memory: '<S4>/Memory' */
    memcpy(&heli_q8_pres3_DW.Memory_PreviousInput[0], &heli_q8_pres3_B.Switch[0],
           10U * sizeof(real_T));
  }

  if (rtmIsMajorTimeStep(heli_q8_pres3_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_pres3_M->solverInfo);
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
  if (!(++heli_q8_pres3_M->Timing.clockTick0)) {
    ++heli_q8_pres3_M->Timing.clockTickH0;
  }

  heli_q8_pres3_M->Timing.t[0] = rtsiGetSolverStopTime
    (&heli_q8_pres3_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_pres3_M->Timing.clockTick1)) {
    ++heli_q8_pres3_M->Timing.clockTickH1;
  }

  heli_q8_pres3_M->Timing.t[1] = heli_q8_pres3_M->Timing.clockTick1 *
    heli_q8_pres3_M->Timing.stepSize1 + heli_q8_pres3_M->Timing.clockTickH1 *
    heli_q8_pres3_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_pres3_derivatives(void)
{
  XDot_heli_q8_pres3_T *_rtXdot;
  int32_T i;
  _rtXdot = ((XDot_heli_q8_pres3_T *) heli_q8_pres3_M->derivs);

  /* Derivatives for Integrator: '<S8>/Integrator' */
  for (i = 0; i < 5; i++) {
    _rtXdot->Integrator_CSTATE[i] = heli_q8_pres3_B.Sum2_b[i];
  }

  /* End of Derivatives for Integrator: '<S8>/Integrator' */

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE_d = heli_q8_pres3_B.Sum;

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = heli_q8_pres3_B.Sum2;

  /* Derivatives for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_pres3_P.ElevationTransferFcn_A
    * heli_q8_pres3_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_pres3_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_pres3_P.PitchTransferFcn_A *
    heli_q8_pres3_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_pres3_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_pres3_P.TravelTransferFcn_A *
    heli_q8_pres3_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_pres3_B.TravelCounttorad;
}

/* Model output function for TID2 */
void heli_q8_pres3_output2(void)       /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S5>/Game Controller' */

  /* S-Function Block: heli_q8_pres3/Joystick1/Game Controller (game_controller_block) */
  {
    if (heli_q8_pres3_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_q8_pres3_DW.GameController_Controller,
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

  /* RateTransition: '<S5>/Rate Transition: x' */
  heli_q8_pres3_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S5>/Rate Transition: y' */
  heli_q8_pres3_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void heli_q8_pres3_update2(void)       /* Sample time: [0.01s, 0.0s] */
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
  if (!(++heli_q8_pres3_M->Timing.clockTick2)) {
    ++heli_q8_pres3_M->Timing.clockTickH2;
  }

  heli_q8_pres3_M->Timing.t[2] = heli_q8_pres3_M->Timing.clockTick2 *
    heli_q8_pres3_M->Timing.stepSize2 + heli_q8_pres3_M->Timing.clockTickH2 *
    heli_q8_pres3_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_pres3_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_pres3_output0();
    break;

   case 2 :
    heli_q8_pres3_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_pres3_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_pres3_update0();
    break;

   case 2 :
    heli_q8_pres3_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_pres3_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: heli_q8_pres3/HIL Initialize1 (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_pres3_DW.HILInitialize1_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_q8_pres3_DW.HILInitialize1_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_pres3_DW.HILInitialize1_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
      return;
    }

    if ((heli_q8_pres3_P.HILInitialize1_AIPStart && !is_switching) ||
        (heli_q8_pres3_P.HILInitialize1_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_pres3_DW.HILInitialize1_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (heli_q8_pres3_P.HILInitialize1_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_pres3_DW.HILInitialize1_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_q8_pres3_P.HILInitialize1_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(heli_q8_pres3_DW.HILInitialize1_Card,
        heli_q8_pres3_P.HILInitialize1_AIChannels, 8U,
        &heli_q8_pres3_DW.HILInitialize1_AIMinimums[0],
        &heli_q8_pres3_DW.HILInitialize1_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_pres3_P.HILInitialize1_AOPStart && !is_switching) ||
        (heli_q8_pres3_P.HILInitialize1_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_pres3_DW.HILInitialize1_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (heli_q8_pres3_P.HILInitialize1_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_pres3_DW.HILInitialize1_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_q8_pres3_P.HILInitialize1_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(heli_q8_pres3_DW.HILInitialize1_Card,
        heli_q8_pres3_P.HILInitialize1_AOChannels, 8U,
        &heli_q8_pres3_DW.HILInitialize1_AOMinimums[0],
        &heli_q8_pres3_DW.HILInitialize1_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_pres3_P.HILInitialize1_AOStart && !is_switching) ||
        (heli_q8_pres3_P.HILInitialize1_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_pres3_DW.HILInitialize1_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_pres3_P.HILInitialize1_AOInitial;
        }
      }

      result = hil_write_analog(heli_q8_pres3_DW.HILInitialize1_Card,
        heli_q8_pres3_P.HILInitialize1_AOChannels, 8U,
        &heli_q8_pres3_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_pres3_P.HILInitialize1_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_pres3_DW.HILInitialize1_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_pres3_P.HILInitialize1_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_pres3_DW.HILInitialize1_Card,
         heli_q8_pres3_P.HILInitialize1_AOChannels, 8U,
         &heli_q8_pres3_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_pres3_P.HILInitialize1_EIPStart && !is_switching) ||
        (heli_q8_pres3_P.HILInitialize1_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_pres3_DW.HILInitialize1_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_pres3_P.HILInitialize1_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (heli_q8_pres3_DW.HILInitialize1_Card,
         heli_q8_pres3_P.HILInitialize1_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &heli_q8_pres3_DW.HILInitialize1_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_pres3_P.HILInitialize1_EIStart && !is_switching) ||
        (heli_q8_pres3_P.HILInitialize1_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_pres3_DW.HILInitialize1_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = heli_q8_pres3_P.HILInitialize1_EIInitial;
        }
      }

      result = hil_set_encoder_counts(heli_q8_pres3_DW.HILInitialize1_Card,
        heli_q8_pres3_P.HILInitialize1_EIChannels, 8U,
        &heli_q8_pres3_DW.HILInitialize1_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_pres3_P.HILInitialize1_POPStart && !is_switching) ||
        (heli_q8_pres3_P.HILInitialize1_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_pres3_DW.HILInitialize1_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_pres3_P.HILInitialize1_POModes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_pres3_DW.HILInitialize1_Card,
        heli_q8_pres3_P.HILInitialize1_POChannels, 8U, (t_pwm_mode *)
        &heli_q8_pres3_DW.HILInitialize1_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize1_POChannels =
          heli_q8_pres3_P.HILInitialize1_POChannels;
        int32_T *dw_POModeValues =
          &heli_q8_pres3_DW.HILInitialize1_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            heli_q8_pres3_DW.HILInitialize1_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize1_POChannels[i1]);
            heli_q8_pres3_DW.HILInitialize1_POSortedFreqs[num_duty_cycle_modes] =
              heli_q8_pres3_P.HILInitialize1_POFrequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_pres3_DW.HILInitialize1_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize1_POChannels[i1]);
            heli_q8_pres3_DW.HILInitialize1_POSortedFreqs[7U -
              num_frequency_modes] = heli_q8_pres3_P.HILInitialize1_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_pres3_DW.HILInitialize1_Card,
          &heli_q8_pres3_DW.HILInitialize1_POSortedChans[0],
          num_duty_cycle_modes, &heli_q8_pres3_DW.HILInitialize1_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_pres3_DW.HILInitialize1_Card,
          &heli_q8_pres3_DW.HILInitialize1_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_pres3_DW.HILInitialize1_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_pres3_DW.HILInitialize1_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_pres3_P.HILInitialize1_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &heli_q8_pres3_DW.HILInitialize1_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_pres3_P.HILInitialize1_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &heli_q8_pres3_DW.HILInitialize1_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_pres3_P.HILInitialize1_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_pres3_DW.HILInitialize1_Card,
        heli_q8_pres3_P.HILInitialize1_POChannels, 8U,
        (t_pwm_configuration *) &heli_q8_pres3_DW.HILInitialize1_POModeValues[0],
        (t_pwm_alignment *) &heli_q8_pres3_DW.HILInitialize1_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_pres3_DW.HILInitialize1_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &heli_q8_pres3_DW.HILInitialize1_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_q8_pres3_P.HILInitialize1_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_pres3_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_pres3_P.HILInitialize1_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_pres3_DW.HILInitialize1_Card,
        heli_q8_pres3_P.HILInitialize1_POChannels, 8U,
        &heli_q8_pres3_DW.HILInitialize1_POSortedFreqs[0],
        &heli_q8_pres3_DW.HILInitialize1_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_pres3_P.HILInitialize1_POStart && !is_switching) ||
        (heli_q8_pres3_P.HILInitialize1_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_pres3_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_pres3_P.HILInitialize1_POInitial;
        }
      }

      result = hil_write_pwm(heli_q8_pres3_DW.HILInitialize1_Card,
        heli_q8_pres3_P.HILInitialize1_POChannels, 8U,
        &heli_q8_pres3_DW.HILInitialize1_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_pres3_P.HILInitialize1_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_pres3_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_pres3_P.HILInitialize1_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_pres3_DW.HILInitialize1_Card,
         heli_q8_pres3_P.HILInitialize1_POChannels, 8U,
         &heli_q8_pres3_DW.HILInitialize1_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8_pres3/Heli 3D1/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_q8_pres3_DW.HILInitialize1_Card,
      heli_q8_pres3_P.HILReadEncoderTimebase_SamplesI,
      heli_q8_pres3_P.HILReadEncoderTimebase_Channels, 3,
      &heli_q8_pres3_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (heli_q8_pres3_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (heli_q8_pres3_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
    }
  }

  /* Start for S-Function (stream_call_block): '<S4>/Stream Call1' incorporates:
   *  Constant: '<S4>/Constant'
   *  S-Function (string_constant_block): '<S4>/String Constant'
   */

  /* S-Function Block: heli_q8_pres3/IMU1/Stream Call1 (stream_call_block) */
  {
    heli_q8_pres3_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
    heli_q8_pres3_DW.StreamCall1_Stream = NULL;
  }

  /* Start for RateTransition: '<S5>/Rate Transition: x' */
  heli_q8_pres3_B.RateTransitionx =
    heli_q8_pres3_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S5>/Rate Transition: y' */
  heli_q8_pres3_B.RateTransitiony =
    heli_q8_pres3_P.RateTransitiony_InitialConditio;

  /* Start for S-Function (game_controller_block): '<S5>/Game Controller' */

  /* S-Function Block: heli_q8_pres3/Joystick1/Game Controller (game_controller_block) */
  {
    if (heli_q8_pres3_P.GameController_Enabled) {
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
        (heli_q8_pres3_P.GameController_ControllerNumber,
         heli_q8_pres3_P.GameController_BufferSize, deadzone, saturation,
         heli_q8_pres3_P.GameController_AutoCenter, 0, 1.0,
         &heli_q8_pres3_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for Memory: '<S4>/Memory' */
    memcpy(&heli_q8_pres3_DW.Memory_PreviousInput[0],
           &heli_q8_pres3_P.Memory_InitialCondition[0], 10U * sizeof(real_T));

    /* InitializeConditions for Integrator: '<S8>/Integrator' */
    for (i = 0; i < 5; i++) {
      heli_q8_pres3_X.Integrator_CSTATE[i] = heli_q8_pres3_P.Integrator_IC;
    }

    /* End of InitializeConditions for Integrator: '<S8>/Integrator' */

    /* InitializeConditions for Integrator: '<S6>/Integrator' */
    heli_q8_pres3_X.Integrator_CSTATE_d = heli_q8_pres3_P.Integrator_IC_g;

    /* InitializeConditions for Integrator: '<S6>/Integrator1' */
    heli_q8_pres3_X.Integrator1_CSTATE = heli_q8_pres3_P.Integrator1_IC;

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition: x' */
    heli_q8_pres3_DW.RateTransitionx_Buffer0 =
      heli_q8_pres3_P.RateTransitionx_InitialConditio;

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition: y' */
    heli_q8_pres3_DW.RateTransitiony_Buffer0 =
      heli_q8_pres3_P.RateTransitiony_InitialConditio;

    /* InitializeConditions for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
    heli_q8_pres3_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
    heli_q8_pres3_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S3>/Travel: Transfer Fcn' */
    heli_q8_pres3_X.TravelTransferFcn_CSTATE = 0.0;
  }
}

/* Model terminate function */
void heli_q8_pres3_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: heli_q8_pres3/HIL Initialize1 (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_pres3_DW.HILInitialize1_Card);
    hil_monitor_stop_all(heli_q8_pres3_DW.HILInitialize1_Card);
    is_switching = false;
    if ((heli_q8_pres3_P.HILInitialize1_AOTerminate && !is_switching) ||
        (heli_q8_pres3_P.HILInitialize1_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_pres3_DW.HILInitialize1_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_pres3_P.HILInitialize1_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((heli_q8_pres3_P.HILInitialize1_POTerminate && !is_switching) ||
        (heli_q8_pres3_P.HILInitialize1_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_pres3_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_pres3_P.HILInitialize1_POFinal;
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
      result = hil_write(heli_q8_pres3_DW.HILInitialize1_Card
                         , heli_q8_pres3_P.HILInitialize1_AOChannels,
                         num_final_analog_outputs
                         , heli_q8_pres3_P.HILInitialize1_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_pres3_DW.HILInitialize1_AOVoltages[0]
                         , &heli_q8_pres3_DW.HILInitialize1_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_pres3_DW.HILInitialize1_Card,
            heli_q8_pres3_P.HILInitialize1_AOChannels, num_final_analog_outputs,
            &heli_q8_pres3_DW.HILInitialize1_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_pres3_DW.HILInitialize1_Card,
            heli_q8_pres3_P.HILInitialize1_POChannels, num_final_pwm_outputs,
            &heli_q8_pres3_DW.HILInitialize1_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_pres3_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_pres3_DW.HILInitialize1_Card);
    hil_monitor_delete_all(heli_q8_pres3_DW.HILInitialize1_Card);
    hil_close(heli_q8_pres3_DW.HILInitialize1_Card);
    heli_q8_pres3_DW.HILInitialize1_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S4>/Stream Call1' incorporates:
   *  Constant: '<S4>/Constant'
   *  S-Function (string_constant_block): '<S4>/String Constant'
   */

  /* S-Function Block: heli_q8_pres3/IMU1/Stream Call1 (stream_call_block) */
  {
    if (heli_q8_pres3_DW.StreamCall1_Stream != NULL) {
      stream_close(heli_q8_pres3_DW.StreamCall1_Stream);
      heli_q8_pres3_DW.StreamCall1_Stream = NULL;
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S5>/Game Controller' */

  /* S-Function Block: heli_q8_pres3/Joystick1/Game Controller (game_controller_block) */
  {
    if (heli_q8_pres3_P.GameController_Enabled) {
      game_controller_close(heli_q8_pres3_DW.GameController_Controller);
      heli_q8_pres3_DW.GameController_Controller = NULL;
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
  heli_q8_pres3_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_pres3_update(tid);
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
  heli_q8_pres3_initialize();
}

void MdlTerminate(void)
{
  heli_q8_pres3_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_pres3_T *heli_q8_pres3(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)heli_q8_pres3_M, 0,
                sizeof(RT_MODEL_heli_q8_pres3_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_pres3_M->solverInfo,
                          &heli_q8_pres3_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_pres3_M->solverInfo, &rtmGetTPtr(heli_q8_pres3_M));
    rtsiSetStepSizePtr(&heli_q8_pres3_M->solverInfo,
                       &heli_q8_pres3_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_pres3_M->solverInfo, &heli_q8_pres3_M->derivs);
    rtsiSetContStatesPtr(&heli_q8_pres3_M->solverInfo, (real_T **)
                         &heli_q8_pres3_M->contStates);
    rtsiSetNumContStatesPtr(&heli_q8_pres3_M->solverInfo,
      &heli_q8_pres3_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_pres3_M->solverInfo,
      &heli_q8_pres3_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_pres3_M->solverInfo,
      &heli_q8_pres3_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_pres3_M->solverInfo,
      &heli_q8_pres3_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_pres3_M->solverInfo, (&rtmGetErrorStatus
      (heli_q8_pres3_M)));
    rtsiSetRTModelPtr(&heli_q8_pres3_M->solverInfo, heli_q8_pres3_M);
  }

  rtsiSetSimTimeStep(&heli_q8_pres3_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_pres3_M->intgData.f[0] = heli_q8_pres3_M->odeF[0];
  heli_q8_pres3_M->contStates = ((real_T *) &heli_q8_pres3_X);
  rtsiSetSolverData(&heli_q8_pres3_M->solverInfo, (void *)
                    &heli_q8_pres3_M->intgData);
  rtsiSetSolverName(&heli_q8_pres3_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_pres3_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_pres3_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_pres3_M->Timing.sampleTimes =
      (&heli_q8_pres3_M->Timing.sampleTimesArray[0]);
    heli_q8_pres3_M->Timing.offsetTimes =
      (&heli_q8_pres3_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_pres3_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_pres3_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_pres3_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_pres3_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_pres3_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_pres3_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_pres3_M, &heli_q8_pres3_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_pres3_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_q8_pres3_M->Timing.perTaskSampleHitsArray;
    heli_q8_pres3_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_pres3_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_pres3_M, -1);
  heli_q8_pres3_M->Timing.stepSize0 = 0.002;
  heli_q8_pres3_M->Timing.stepSize1 = 0.002;
  heli_q8_pres3_M->Timing.stepSize2 = 0.01;
  heli_q8_pres3_M->solverInfoPtr = (&heli_q8_pres3_M->solverInfo);
  heli_q8_pres3_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_pres3_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_pres3_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_pres3_M->blockIO = ((void *) &heli_q8_pres3_B);

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_pres3_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      heli_q8_pres3_B.Gain[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      heli_q8_pres3_B.Sum2_b[i] = 0.0;
    }

    heli_q8_pres3_B.RateTransitionx = 0.0;
    heli_q8_pres3_B.Joystick_gain_x = 0.0;
    heli_q8_pres3_B.RateTransitiony = 0.0;
    heli_q8_pres3_B.Joystick_gain_y = 0.0;
    heli_q8_pres3_B.Multiply[0] = 0.0;
    heli_q8_pres3_B.Multiply[1] = 0.0;
    heli_q8_pres3_B.TravelCounttorad = 0.0;
    heli_q8_pres3_B.ElevationCounttorad = 0.0;
    heli_q8_pres3_B.PitchCounttorad = 0.0;
    heli_q8_pres3_B.FrontmotorSaturation = 0.0;
    heli_q8_pres3_B.BackmotorSaturation = 0.0;
    heli_q8_pres3_B.Sum = 0.0;
    heli_q8_pres3_B.Sum2 = 0.0;
  }

  /* parameters */
  heli_q8_pres3_M->defaultParam = ((real_T *)&heli_q8_pres3_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_pres3_X;
    heli_q8_pres3_M->contStates = (x);
    (void) memset((void *)&heli_q8_pres3_X, 0,
                  sizeof(X_heli_q8_pres3_T));
  }

  /* states (dwork) */
  heli_q8_pres3_M->dwork = ((void *) &heli_q8_pres3_DW);
  (void) memset((void *)&heli_q8_pres3_DW, 0,
                sizeof(DW_heli_q8_pres3_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres3_DW.HILInitialize1_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres3_DW.HILInitialize1_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres3_DW.HILInitialize1_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres3_DW.HILInitialize1_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres3_DW.HILInitialize1_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres3_DW.HILInitialize1_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres3_DW.HILInitialize1_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_pres3_DW.HILInitialize1_POValues[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_pres3_DW.Memory_PreviousInput[i] = 0.0;
    }
  }

  heli_q8_pres3_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_pres3_DW.RateTransitiony_Buffer0 = 0.0;
  heli_q8_pres3_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_pres3_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* Initialize Sizes */
  heli_q8_pres3_M->Sizes.numContStates = (10);/* Number of continuous states */
  heli_q8_pres3_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  heli_q8_pres3_M->Sizes.numY = (0);   /* Number of model outputs */
  heli_q8_pres3_M->Sizes.numU = (0);   /* Number of model inputs */
  heli_q8_pres3_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_pres3_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_q8_pres3_M->Sizes.numBlocks = (67);/* Number of blocks */
  heli_q8_pres3_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  heli_q8_pres3_M->Sizes.numBlockPrms = (533);/* Sum of parameter "widths" */
  return heli_q8_pres3_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
