/*
 * heli_q8.c
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
#include "heli_q8_dt.h"

t_stream heli_q8_rtZt_stream = NULL;

/* Block signals (default storage) */
B_heli_q8_T heli_q8_B;

/* Continuous states */
X_heli_q8_T heli_q8_X;

/* Block states (default storage) */
DW_heli_q8_T heli_q8_DW;

/* Real-time model */
static RT_MODEL_heli_q8_T heli_q8_M_;
RT_MODEL_heli_q8_T *const heli_q8_M = &heli_q8_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_M, 2);
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
  if (heli_q8_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_M->Timing.perTaskSampleHits[5] =
      heli_q8_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_q8_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void heli_q8_output0(void)             /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamCall1_o1;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_DeadZoney;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamCall1_o3;
  int32_T rtb_StreamRead1_o5;
  boolean_T rtb_StreamRead1_o3;
  real_T A[36];
  real_T A_0[36];
  real_T A_tmp[36];
  real_T X[36];
  real_T X_0[36];
  real_T b_I_0[36];
  real_T b_I_1[36];
  real_T tmp_0[9];
  real_T tmp_1[6];
  real_T tmp_2[6];
  real_T tmp_3[6];
  real_T tmp[5];
  real_T euler_rates_tmp;
  real_T euler_rates_tmp_0;
  real_T rtb_e;
  real_T rtb_p;
  int32_T A_tmp_tmp;
  int32_T c_ix;
  int32_T i;
  int32_T ijA;
  int32_T ix;
  int32_T iy;
  int32_T jBcol;
  int32_T kBcol;
  int8_T b_I[36];
  int8_T ipiv[6];
  int8_T ipiv_0;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* set solver stop time */
    if (!(heli_q8_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_M->solverInfo,
                            ((heli_q8_M->Timing.clockTickH0 + 1) *
        heli_q8_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_M->solverInfo,
                            ((heli_q8_M->Timing.clockTick0 + 1) *
        heli_q8_M->Timing.stepSize0 + heli_q8_M->Timing.clockTickH0 *
        heli_q8_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_M)) {
    heli_q8_M->Timing.t[0] = rtsiGetT(&heli_q8_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8/Heli 3D1/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(heli_q8_DW.HILReadEncoderTimebase_Task, 1,
        &heli_q8_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_q8_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney = heli_q8_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* S-Function (stream_call_block): '<S5>/Stream Call1' incorporates:
     *  Constant: '<S5>/Constant'
     *  S-Function (string_constant_block): '<S5>/String Constant'
     */

    /* S-Function Block: heli_q8/IMU1/Stream Call1 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (heli_q8_P.Constant_Value != 0);
      rtb_StreamCall1_o1 = NULL;
      switch (heli_q8_DW.StreamCall1_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) heli_q8_P.StringConstant_Value, 255) ==
                255) {
              rtmSetErrorStatus(heli_q8_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *) heli_q8_P.StringConstant_Value,
                heli_q8_P.StreamCall1_NonBlocking != 0,
                heli_q8_P.StreamCall1_SendBufferSize,
                heli_q8_P.StreamCall1_ReceiveBufferSize,
                &heli_q8_DW.StreamCall1_Stream);
              if (result == 0) {
                heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(heli_q8_DW.StreamCall1_Stream,
                                      (t_stream_byte_order)
                                      heli_q8_P.StreamCall1_Endian);
                rtb_StreamCall1_o1 = &heli_q8_DW.StreamCall1_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTING;
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

            result = stream_poll(heli_q8_DW.StreamCall1_Stream, &timeout,
                                 STREAM_POLL_CONNECT);
            if (result > 0) {
              heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_q8_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    heli_q8_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &heli_q8_DW.StreamCall1_Stream;
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
          rtb_StreamCall1_o1 = &heli_q8_DW.StreamCall1_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close(heli_q8_DW.StreamCall1_Stream);
          if (close_result == 0) {
            heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
            heli_q8_DW.StreamCall1_Stream = NULL;
            rtb_StreamCall1_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      heli_q8_B.StreamCall1_o2 = heli_q8_DW.StreamCall1_State;
      rtb_StreamCall1_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_write_block): '<S5>/Stream Formatted Write' incorporates:
     *  Constant: '<S5>/Constant1'
     */
    {
      t_error result;
      if (rtb_StreamCall1_o1 != NULL) {
        result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
          heli_q8_P.StreamFormattedWrite_MaxUnits, &rtb_StreamFormattedWrite_o2,
          "%c\n"
          , (char) heli_q8_P.Constant1_Value
          );
        if (result > 0) {
          result = stream_flush(*rtb_StreamCall1_o1);
        }

        if (result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      }
    }

    /* S-Function (stream_read_block): '<S5>/Stream Read1' incorporates:
     *  Constant: '<S5>/Constant1'
     *  S-Function (stream_call_block): '<S5>/Stream Call1'
     *  S-Function (stream_formatted_write_block): '<S5>/Stream Formatted Write'
     */

    /* S-Function Block: heli_q8/IMU1/Stream Read1 (stream_read_block) */
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
      /* Switch: '<S5>/Switch' */
      if (rtb_StreamRead1_o3) {
        /* Switch: '<S5>/Switch' incorporates:
         *  DataTypeConversion: '<S5>/Data Type Conversion'
         */
        heli_q8_B.Switch[i] = rtb_StreamRead1_o2[i];
      } else {
        /* Switch: '<S5>/Switch' incorporates:
         *  Memory: '<S5>/Memory'
         */
        heli_q8_B.Switch[i] = heli_q8_DW.Memory_PreviousInput[i];
      }

      /* End of Switch: '<S5>/Switch' */
    }

    for (iy = 0; iy < 3; iy++) {
      /* Gain: '<S5>/Gain2' */
      heli_q8_B.Gain2[iy] = 0.0;
      heli_q8_B.Gain2[iy] += heli_q8_P.Gain2_Gain[iy] * heli_q8_B.Switch[0];
      heli_q8_B.Gain2[iy] += heli_q8_P.Gain2_Gain[iy + 3] * heli_q8_B.Switch[1];
      heli_q8_B.Gain2[iy] += heli_q8_P.Gain2_Gain[iy + 6] * heli_q8_B.Switch[2];
    }

    /* MATLAB Function: '<Root>/MATLAB Function1' */
    /* MATLAB Function 'MATLAB Function1': '<S9>:1' */
    /* '<S9>:1:3' */
    if (heli_q8_B.Gain2[2] == 0.0) {
      /* '<S9>:1:4' */
      /* '<S9>:1:5' */
      if (heli_q8_B.Gain2[1] < 0.0) {
        rtb_e = -1.0;
      } else if (heli_q8_B.Gain2[1] > 0.0) {
        rtb_e = 1.0;
      } else if (heli_q8_B.Gain2[1] == 0.0) {
        rtb_e = 0.0;
      } else {
        rtb_e = (rtNaN);
      }

      rtb_p = rtb_e * 3.1415926535897931 / 2.0;
    } else {
      /* '<S9>:1:7' */
      rtb_p = atan(heli_q8_B.Gain2[1] / heli_q8_B.Gain2[2]);
    }

    if ((heli_q8_B.Gain2[1] == 0.0) && (heli_q8_B.Gain2[2] == 0.0)) {
      /* '<S9>:1:10' */
      /* '<S9>:1:11' */
      if (heli_q8_B.Gain2[0] < 0.0) {
        rtb_e = -1.0;
      } else if (heli_q8_B.Gain2[0] > 0.0) {
        rtb_e = 1.0;
      } else if (heli_q8_B.Gain2[0] == 0.0) {
        rtb_e = 0.0;
      } else {
        rtb_e = (rtNaN);
      }

      rtb_e = rtb_e * 3.1415926535897931 / 2.0;
    } else {
      /* '<S9>:1:13' */
      rtb_e = atan(heli_q8_B.Gain2[0] / sqrt(heli_q8_B.Gain2[1] *
        heli_q8_B.Gain2[1] + heli_q8_B.Gain2[2] * heli_q8_B.Gain2[2]));
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function1' */

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    heli_q8_B.Sum2 = rtb_e - heli_q8_P.Constant1_Value_k;

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant'
     */
    heli_q8_B.Sum3 = heli_q8_P.Constant_Value_p + rtb_p;
    for (iy = 0; iy < 3; iy++) {
      /* Gain: '<S5>/Gain1' */
      heli_q8_B.Gain1[iy] = 0.0;
      heli_q8_B.Gain1[iy] += heli_q8_P.Gain1_Gain[iy] * heli_q8_B.Switch[3];
      heli_q8_B.Gain1[iy] += heli_q8_P.Gain1_Gain[iy + 3] * heli_q8_B.Switch[4];
      heli_q8_B.Gain1[iy] += heli_q8_P.Gain1_Gain[iy + 6] * heli_q8_B.Switch[5];
    }

    /* Gain: '<S4>/Travel: Count to rad' */
    heli_q8_B.TravelCounttorad = heli_q8_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travel rate]' incorporates:
     *  SignalConversion generated from: '<S3>/ SFunction '
     */
    /* MATLAB Function 'Gyro vector to [pitch rate, elevation rate, travel rate]': '<S3>:1' */
    /* '<S3>:1:3' */
    /* '<S3>:1:4' */
    /* '<S3>:1:8' */
    /* '<S3>:1:11' */
    rtb_p = tan(heli_q8_B.Sum2);
    rtb_e = sin(heli_q8_B.Sum3);
    euler_rates_tmp = cos(heli_q8_B.Sum3);
    euler_rates_tmp_0 = cos(heli_q8_B.Sum2);
    tmp_0[0] = 1.0;
    tmp_0[3] = rtb_e * rtb_p;
    tmp_0[6] = euler_rates_tmp * rtb_p;
    tmp_0[1] = 0.0;
    tmp_0[4] = euler_rates_tmp;
    tmp_0[7] = -rtb_e;
    tmp_0[2] = 0.0;
    tmp_0[5] = rtb_e / euler_rates_tmp_0;
    tmp_0[8] = euler_rates_tmp / euler_rates_tmp_0;
    for (iy = 0; iy < 3; iy++) {
      heli_q8_B.euler_rates[iy] = 0.0;
      heli_q8_B.euler_rates[iy] += tmp_0[iy] * heli_q8_B.Gain1[0];
      heli_q8_B.euler_rates[iy] += tmp_0[iy + 3] * heli_q8_B.Gain1[1];
      heli_q8_B.euler_rates[iy] += tmp_0[iy + 6] * heli_q8_B.Gain1[2];
    }

    /* End of MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travel rate]' */
    for (i = 0; i < 6; i++) {
      /* UnitDelay: '<S7>/Unit Delay' */
      heli_q8_B.UnitDelay[i] = heli_q8_DW.UnitDelay_DSTATE[i];
    }

    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    /* MATLAB Function 'Kalman/MATLAB Function2': '<S12>:1' */
    if (heli_q8_P.ManualSwitch_CurrentSetting == 1) {
      rtb_e = heli_q8_P.Constant4_Value;
    } else {
      rtb_e = rtb_StreamRead1_o3;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* MATLAB Function: '<S7>/MATLAB Function2' incorporates:
     *  Constant: '<S7>/Constant2'
     *  Constant: '<S7>/Constant4'
     *  UnitDelay: '<S7>/Unit Delay1'
     */
    if (rtb_e != 0.0) {
      /* '<S12>:1:3' */
      /* '<S12>:1:4' */
      for (iy = 0; iy < 6; iy++) {
        for (ix = 0; ix < 6; ix++) {
          A_tmp_tmp = 6 * ix + iy;
          A_tmp[ix + 6 * iy] = heli_q8_P.C_d[A_tmp_tmp];
          X[A_tmp_tmp] = 0.0;
          for (i = 0; i < 6; i++) {
            X[A_tmp_tmp] += heli_q8_P.C_d[6 * i + iy] *
              heli_q8_DW.UnitDelay1_DSTATE[6 * ix + i];
          }
        }
      }

      for (iy = 0; iy < 6; iy++) {
        for (ix = 0; ix < 6; ix++) {
          rtb_e = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_e += X[6 * i + iy] * A_tmp[6 * ix + i];
          }

          i = 6 * ix + iy;
          A[i] = heli_q8_P.R_d[i] + rtb_e;
        }

        ipiv[iy] = (int8_T)(iy + 1);
      }

      for (i = 0; i < 5; i++) {
        jBcol = i * 7;
        iy = 0;
        ix = jBcol;
        rtb_p = fabs(A[jBcol]);
        for (kBcol = 2; kBcol <= 6 - i; kBcol++) {
          ix++;
          rtb_e = fabs(A[ix]);
          if (rtb_e > rtb_p) {
            iy = kBcol - 1;
            rtb_p = rtb_e;
          }
        }

        if (A[jBcol + iy] != 0.0) {
          if (iy != 0) {
            iy += i;
            ipiv[i] = (int8_T)(iy + 1);
            ix = i;
            for (kBcol = 0; kBcol < 6; kBcol++) {
              rtb_p = A[ix];
              A[ix] = A[iy];
              A[iy] = rtb_p;
              ix += 6;
              iy += 6;
            }
          }

          iy = (jBcol - i) + 6;
          for (ix = jBcol + 1; ix < iy; ix++) {
            A[ix] /= A[jBcol];
          }
        }

        iy = jBcol;
        ix = jBcol + 6;
        for (kBcol = 0; kBcol <= 4 - i; kBcol++) {
          if (A[ix] != 0.0) {
            rtb_p = -A[ix];
            c_ix = jBcol + 1;
            A_tmp_tmp = (iy - i) + 12;
            for (ijA = iy + 7; ijA < A_tmp_tmp; ijA++) {
              A[ijA] += A[c_ix] * rtb_p;
              c_ix++;
            }
          }

          ix += 6;
          iy += 6;
        }
      }

      for (iy = 0; iy < 6; iy++) {
        for (ix = 0; ix < 6; ix++) {
          A_tmp_tmp = ix + 6 * iy;
          X[A_tmp_tmp] = 0.0;
          for (i = 0; i < 6; i++) {
            X[A_tmp_tmp] += heli_q8_DW.UnitDelay1_DSTATE[6 * i + ix] * A_tmp[6 *
              iy + i];
          }
        }
      }

      for (i = 0; i < 6; i++) {
        jBcol = 6 * i;
        for (ix = 0; ix < i; ix++) {
          kBcol = 6 * ix;
          if (A[ix + jBcol] != 0.0) {
            for (c_ix = 0; c_ix < 6; c_ix++) {
              A_tmp_tmp = c_ix + jBcol;
              X[A_tmp_tmp] -= A[ix + jBcol] * X[c_ix + kBcol];
            }
          }
        }

        rtb_p = 1.0 / A[i + jBcol];
        for (iy = 0; iy < 6; iy++) {
          A_tmp_tmp = iy + jBcol;
          X[A_tmp_tmp] *= rtb_p;
        }
      }

      for (i = 5; i >= 0; i--) {
        jBcol = 6 * i;
        iy = 6 * i - 1;
        for (ix = i + 2; ix < 7; ix++) {
          kBcol = (ix - 1) * 6;
          if (A[ix + iy] != 0.0) {
            for (c_ix = 0; c_ix < 6; c_ix++) {
              A_tmp_tmp = c_ix + jBcol;
              X[A_tmp_tmp] -= A[ix + iy] * X[c_ix + kBcol];
            }
          }
        }
      }

      for (i = 4; i >= 0; i--) {
        ipiv_0 = ipiv[i];
        if (i + 1 != ipiv_0) {
          for (iy = 0; iy < 6; iy++) {
            ix = 6 * i + iy;
            rtb_p = X[ix];
            A_tmp_tmp = (ipiv_0 - 1) * 6 + iy;
            X[ix] = X[A_tmp_tmp];
            X[A_tmp_tmp] = rtb_p;
          }
        }
      }

      /* SignalConversion generated from: '<S12>/ SFunction ' incorporates:
       *  Constant: '<S7>/Constant2'
       *  Constant: '<S7>/Constant4'
       *  UnitDelay: '<S7>/Unit Delay1'
       */
      /* '<S12>:1:5' */
      tmp_1[0] = heli_q8_B.Sum3;
      tmp_1[1] = heli_q8_B.euler_rates[0];
      tmp_1[2] = heli_q8_B.Sum2;
      tmp_1[3] = heli_q8_B.euler_rates[1];
      tmp_1[4] = heli_q8_B.TravelCounttorad;
      tmp_1[5] = heli_q8_B.euler_rates[2];
      for (iy = 0; iy < 6; iy++) {
        tmp_2[iy] = 0.0;
        for (ix = 0; ix < 6; ix++) {
          tmp_2[iy] += heli_q8_P.C_d[6 * ix + iy] * heli_q8_B.UnitDelay[ix];
        }

        tmp_3[iy] = tmp_1[iy] - tmp_2[iy];
      }

      for (iy = 0; iy < 6; iy++) {
        rtb_e = 0.0;
        for (ix = 0; ix < 6; ix++) {
          rtb_e += X[6 * ix + iy] * tmp_3[ix];
        }

        heli_q8_B.x_hat[iy] = heli_q8_B.UnitDelay[iy] + rtb_e;
      }

      for (iy = 0; iy < 36; iy++) {
        A[iy] = 0.0;
      }

      for (i = 0; i < 6; i++) {
        A[i + 6 * i] = 1.0;
      }

      /* '<S12>:1:6' */
      for (iy = 0; iy < 36; iy++) {
        b_I[iy] = 0;
      }

      for (i = 0; i < 6; i++) {
        b_I[i + 6 * i] = 1;
        for (iy = 0; iy < 6; iy++) {
          A_tmp_tmp = i + 6 * iy;
          A_tmp[A_tmp_tmp] = 0.0;
          for (ix = 0; ix < 6; ix++) {
            A_tmp[A_tmp_tmp] += X[6 * ix + i] * heli_q8_P.C_d[6 * iy + ix];
          }
        }
      }

      for (iy = 0; iy < 36; iy++) {
        b_I_0[iy] = (real_T)b_I[iy] - A_tmp[iy];
      }

      for (iy = 0; iy < 6; iy++) {
        for (ix = 0; ix < 6; ix++) {
          A_tmp_tmp = iy + 6 * ix;
          b_I_1[A_tmp_tmp] = 0.0;
          A_0[ix + 6 * iy] = A[A_tmp_tmp] - A_tmp[A_tmp_tmp];
          X_0[A_tmp_tmp] = 0.0;
          for (i = 0; i < 6; i++) {
            kBcol = 6 * i + iy;
            c_ix = 6 * ix + i;
            b_I_1[A_tmp_tmp] += b_I_0[kBcol] * heli_q8_DW.UnitDelay1_DSTATE[c_ix];
            X_0[A_tmp_tmp] += X[kBcol] * heli_q8_P.R_d[c_ix];
          }
        }
      }

      for (iy = 0; iy < 6; iy++) {
        for (ix = 0; ix < 6; ix++) {
          A_tmp_tmp = iy + 6 * ix;
          b_I_0[A_tmp_tmp] = 0.0;
          A_tmp[A_tmp_tmp] = 0.0;
          for (i = 0; i < 6; i++) {
            kBcol = 6 * i + iy;
            b_I_0[A_tmp_tmp] += b_I_1[kBcol] * A_0[6 * ix + i];
            A_tmp[A_tmp_tmp] += X_0[kBcol] * X[6 * i + ix];
          }
        }
      }

      for (iy = 0; iy < 36; iy++) {
        heli_q8_B.P_hat[iy] = b_I_0[iy] + A_tmp[iy];
      }
    } else {
      /* '<S12>:1:8' */
      for (i = 0; i < 6; i++) {
        heli_q8_B.x_hat[i] = heli_q8_B.UnitDelay[i];
      }

      /* '<S12>:1:9' */
      memcpy(&heli_q8_B.P_hat[0], &heli_q8_DW.UnitDelay1_DSTATE[0], 36U * sizeof
             (real_T));
    }

    /* End of MATLAB Function: '<S7>/MATLAB Function2' */

    /* Gain: '<S4>/Elevation: Count to rad' */
    heli_q8_B.ElevationCounttorad = heli_q8_P.ElevationCounttorad_Gain *
      rtb_DeadZoney;

    /* Sum: '<S4>/Sum' incorporates:
     *  Constant: '<S4>/Constant'
     */
    heli_q8_B.Sum = heli_q8_B.ElevationCounttorad - heli_q8_P.Constant_Value_m;
  }

  /* TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  heli_q8_B.ElevationTransferFcn = 0.0;
  heli_q8_B.ElevationTransferFcn += heli_q8_P.ElevationTransferFcn_C *
    heli_q8_X.ElevationTransferFcn_CSTATE;
  heli_q8_B.ElevationTransferFcn += heli_q8_P.ElevationTransferFcn_D *
    heli_q8_B.ElevationCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* Gain: '<S4>/Pitch: Count to rad' */
    heli_q8_B.PitchCounttorad = heli_q8_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;
  }

  /* TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  heli_q8_B.PitchTransferFcn = 0.0;
  heli_q8_B.PitchTransferFcn += heli_q8_P.PitchTransferFcn_C *
    heli_q8_X.PitchTransferFcn_CSTATE;
  heli_q8_B.PitchTransferFcn += heli_q8_P.PitchTransferFcn_D *
    heli_q8_B.PitchCounttorad;

  /* RateTransition: '<S6>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* MATLAB Function: '<Root>/Extract diagonal' */
    /* MATLAB Function 'Extract diagonal': '<S2>:1' */
    /* '<S2>:1:4' */
    for (ix = 0; ix < 6; ix++) {
      heli_q8_B.y[ix] = heli_q8_B.P_hat[6 * ix + ix];
    }

    /* End of MATLAB Function: '<Root>/Extract diagonal' */
    if (heli_q8_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S6>/Rate Transition: x' */
      heli_q8_B.RateTransitionx = heli_q8_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S6>/Dead Zone: x' */
    if (heli_q8_B.RateTransitionx > heli_q8_P.DeadZonex_End) {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_B.RateTransitionx - heli_q8_P.DeadZonex_End;
    } else if (heli_q8_B.RateTransitionx >= heli_q8_P.DeadZonex_Start) {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_B.RateTransitionx - heli_q8_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: x' */

    /* Gain: '<S6>/Joystick_gain_x' incorporates:
     *  Gain: '<S6>/Gain: x'
     */
    heli_q8_B.Joystick_gain_x = heli_q8_P.Gainx_Gain * rtb_DeadZoney *
      heli_q8_P.Joystick_gain_x;

    /* RateTransition: '<S6>/Rate Transition: y' */
    if (heli_q8_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S6>/Rate Transition: y' */
      heli_q8_B.RateTransitiony = heli_q8_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S6>/Rate Transition: y' */

    /* DeadZone: '<S6>/Dead Zone: y' */
    if (heli_q8_B.RateTransitiony > heli_q8_P.DeadZoney_End) {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_B.RateTransitiony - heli_q8_P.DeadZoney_End;
    } else if (heli_q8_B.RateTransitiony >= heli_q8_P.DeadZoney_Start) {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_B.RateTransitiony - heli_q8_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: y' */

    /* Gain: '<S6>/Joystick_gain_y' incorporates:
     *  Gain: '<S6>/Gain: y'
     */
    heli_q8_B.Joystick_gain_y = heli_q8_P.Gainy_Gain * rtb_DeadZoney *
      heli_q8_P.Joystick_gain_y;

    /* Gain: '<S8>/Multiply' incorporates:
     *  SignalConversion generated from: '<S8>/Multiply'
     */
    heli_q8_B.Multiply[0] = 0.0;
    heli_q8_B.Multiply[0] += heli_q8_P.F[0] * heli_q8_B.Joystick_gain_x;
    heli_q8_B.Multiply[0] += heli_q8_P.F[2] * heli_q8_B.Joystick_gain_y;
    heli_q8_B.Multiply[1] = 0.0;
    heli_q8_B.Multiply[1] += heli_q8_P.F[1] * heli_q8_B.Joystick_gain_x;
    heli_q8_B.Multiply[1] += heli_q8_P.F[3] * heli_q8_B.Joystick_gain_y;
  }

  /* End of RateTransition: '<S6>/Rate Transition: x' */

  /* SignalConversion generated from: '<S8>/Multiply1' incorporates:
   *  Integrator: '<S8>/Integrator'
   *  Integrator: '<S8>/Integrator1'
   */
  tmp[0] = heli_q8_B.x_hat[0];
  tmp[1] = heli_q8_B.x_hat[1];
  tmp[2] = heli_q8_B.x_hat[3];
  tmp[3] = heli_q8_X.Integrator_CSTATE;
  tmp[4] = heli_q8_X.Integrator1_CSTATE;
  for (iy = 0; iy < 2; iy++) {
    /* Sum: '<S8>/Sum1' incorporates:
     *  Gain: '<S8>/Multiply1'
     */
    rtb_e = 0.0;
    for (ix = 0; ix < 5; ix++) {
      rtb_e += heli_q8_P.K[(ix << 1) + iy] * tmp[ix];
    }

    heli_q8_B.Sum1[iy] = heli_q8_B.Multiply[iy] - rtb_e;

    /* End of Sum: '<S8>/Sum1' */
  }

  if (rtmIsMajorTimeStep(heli_q8_M)) {
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtb_p = heli_q8_P.vs_0 + heli_q8_B.Sum1[0];

  /* Sum: '<S1>/Add' */
  rtb_e = rtb_p - heli_q8_B.Sum1[1];

  /* Sum: '<S1>/Subtract' */
  rtb_p += heli_q8_B.Sum1[1];

  /* Gain: '<S1>/Back gain' */
  rtb_p *= heli_q8_P.Backgain_Gain;

  /* Gain: '<S1>/Front gain' */
  rtb_e *= heli_q8_P.Frontgain_Gain;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
  }

  /* TransferFcn: '<S4>/Travel: Transfer Fcn' */
  heli_q8_B.TravelTransferFcn = 0.0;
  heli_q8_B.TravelTransferFcn += heli_q8_P.TravelTransferFcn_C *
    heli_q8_X.TravelTransferFcn_CSTATE;
  heli_q8_B.TravelTransferFcn += heli_q8_P.TravelTransferFcn_D *
    heli_q8_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
  }

  /* Saturate: '<S4>/Front motor: Saturation' */
  if (rtb_e > heli_q8_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S4>/Front motor: Saturation' */
    heli_q8_B.FrontmotorSaturation = heli_q8_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_e < heli_q8_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S4>/Front motor: Saturation' */
    heli_q8_B.FrontmotorSaturation = heli_q8_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S4>/Front motor: Saturation' */
    heli_q8_B.FrontmotorSaturation = rtb_e;
  }

  /* End of Saturate: '<S4>/Front motor: Saturation' */

  /* Saturate: '<S4>/Back motor: Saturation' */
  if (rtb_p > heli_q8_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S4>/Back motor: Saturation' */
    heli_q8_B.BackmotorSaturation = heli_q8_P.BackmotorSaturation_UpperSat;
  } else if (rtb_p < heli_q8_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S4>/Back motor: Saturation' */
    heli_q8_B.BackmotorSaturation = heli_q8_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S4>/Back motor: Saturation' */
    heli_q8_B.BackmotorSaturation = rtb_p;
  }

  /* End of Saturate: '<S4>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

    /* S-Function Block: heli_q8/Heli 3D1/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_DW.HILWriteAnalog_Buffer[0] = heli_q8_B.FrontmotorSaturation;
      heli_q8_DW.HILWriteAnalog_Buffer[1] = heli_q8_B.BackmotorSaturation;
      result = hil_write_analog(heli_q8_DW.HILInitialize1_Card,
        heli_q8_P.HILWriteAnalog_channels, 2, &heli_q8_DW.HILWriteAnalog_Buffer
        [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      }
    }

    /* S-Function (stop_with_error_block): '<S5>/Stop with Call Error' */

    /* S-Function Block: heli_q8/IMU1/Stop with Call Error (stop_with_error_block) */
    {
      if (rtb_StreamCall1_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall1_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (stop_with_error_block): '<S5>/Stop with Read Error' */

    /* S-Function Block: heli_q8/IMU1/Stop with Read Error (stop_with_error_block) */
    {
      if (rtb_StreamRead1_o5 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }
  }

  /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant5'
   *  Constant: '<S7>/Constant6'
   */
  /* MATLAB Function 'Kalman/MATLAB Function': '<S11>:1' */
  /* '<S11>:1:2' */
  /* '<S11>:1:3' */
  for (iy = 0; iy < 6; iy++) {
    tmp_1[iy] = 0.0;
    for (ix = 0; ix < 6; ix++) {
      i = 6 * ix + iy;
      X[i] = 0.0;
      for (A_tmp_tmp = 0; A_tmp_tmp < 6; A_tmp_tmp++) {
        X[i] += heli_q8_P.A_d[6 * A_tmp_tmp + iy] * heli_q8_B.P_hat[6 * ix +
          A_tmp_tmp];
      }

      tmp_1[iy] += heli_q8_P.A_d[i] * heli_q8_B.x_hat[ix];
    }

    heli_q8_B.x_bar[iy] = tmp_1[iy] + (heli_q8_P.B_d[iy + 6] * heli_q8_B.Sum1[1]
      + heli_q8_P.B_d[iy] * heli_q8_B.Sum1[0]);
    for (ix = 0; ix < 6; ix++) {
      rtb_e = 0.0;
      for (i = 0; i < 6; i++) {
        rtb_e += X[6 * i + iy] * heli_q8_P.A_d[6 * i + ix];
      }

      i = 6 * ix + iy;
      heli_q8_B.P_bar[i] = heli_q8_P.Q_d[i] + rtb_e;
    }
  }

  /* End of MATLAB Function: '<S7>/MATLAB Function' */
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* Sum: '<S8>/Sum' */
    heli_q8_B.Sum_f = heli_q8_B.x_hat[0] - heli_q8_B.Joystick_gain_x;

    /* Sum: '<S8>/Sum2' */
    heli_q8_B.Sum2_l = heli_q8_B.x_hat[3] - heli_q8_B.Joystick_gain_y;
  }
}

/* Model update function for TID0 */
void heli_q8_update0(void)             /* Sample time: [0.0s, 0.0s] */
{
  int32_T i;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* Update for Memory: '<S5>/Memory' */
    memcpy(&heli_q8_DW.Memory_PreviousInput[0], &heli_q8_B.Switch[0], 10U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S7>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      heli_q8_DW.UnitDelay_DSTATE[i] = heli_q8_B.x_bar[i];
    }

    /* End of Update for UnitDelay: '<S7>/Unit Delay' */

    /* Update for UnitDelay: '<S7>/Unit Delay1' */
    memcpy(&heli_q8_DW.UnitDelay1_DSTATE[0], &heli_q8_B.P_bar[0], 36U * sizeof
           (real_T));
  }

  if (rtmIsMajorTimeStep(heli_q8_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_M->solverInfo);
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
  if (!(++heli_q8_M->Timing.clockTick0)) {
    ++heli_q8_M->Timing.clockTickH0;
  }

  heli_q8_M->Timing.t[0] = rtsiGetSolverStopTime(&heli_q8_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_M->Timing.clockTick1)) {
    ++heli_q8_M->Timing.clockTickH1;
  }

  heli_q8_M->Timing.t[1] = heli_q8_M->Timing.clockTick1 *
    heli_q8_M->Timing.stepSize1 + heli_q8_M->Timing.clockTickH1 *
    heli_q8_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_derivatives(void)
{
  XDot_heli_q8_T *_rtXdot;
  _rtXdot = ((XDot_heli_q8_T *) heli_q8_M->derivs);

  /* Derivatives for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_P.ElevationTransferFcn_A *
    heli_q8_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_P.PitchTransferFcn_A *
    heli_q8_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_B.PitchCounttorad;

  /* Derivatives for Integrator: '<S8>/Integrator' */
  _rtXdot->Integrator_CSTATE = heli_q8_B.Sum_f;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = heli_q8_B.Sum2_l;

  /* Derivatives for TransferFcn: '<S4>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_P.TravelTransferFcn_A *
    heli_q8_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_B.TravelCounttorad;
}

/* Model output function for TID2 */
void heli_q8_output2(void)             /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8/Joystick1/Game Controller (game_controller_block) */
  {
    if (heli_q8_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_q8_DW.GameController_Controller, &state,
        &new_data);
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

  /* RateTransition: '<S6>/Rate Transition: x' */
  heli_q8_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S6>/Rate Transition: y' */
  heli_q8_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void heli_q8_update2(void)             /* Sample time: [0.01s, 0.0s] */
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
  if (!(++heli_q8_M->Timing.clockTick2)) {
    ++heli_q8_M->Timing.clockTickH2;
  }

  heli_q8_M->Timing.t[2] = heli_q8_M->Timing.clockTick2 *
    heli_q8_M->Timing.stepSize2 + heli_q8_M->Timing.clockTickH2 *
    heli_q8_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_output0();
    break;

   case 2 :
    heli_q8_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_update0();
    break;

   case 2 :
    heli_q8_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: heli_q8/HIL Initialize1 (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_DW.HILInitialize1_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_q8_DW.HILInitialize1_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_DW.HILInitialize1_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      return;
    }

    if ((heli_q8_P.HILInitialize1_AIPStart && !is_switching) ||
        (heli_q8_P.HILInitialize1_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_DW.HILInitialize1_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (heli_q8_P.HILInitialize1_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_DW.HILInitialize1_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_q8_P.HILInitialize1_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(heli_q8_DW.HILInitialize1_Card,
        heli_q8_P.HILInitialize1_AIChannels, 8U,
        &heli_q8_DW.HILInitialize1_AIMinimums[0],
        &heli_q8_DW.HILInitialize1_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize1_AOPStart && !is_switching) ||
        (heli_q8_P.HILInitialize1_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_DW.HILInitialize1_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (heli_q8_P.HILInitialize1_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_DW.HILInitialize1_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_q8_P.HILInitialize1_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(heli_q8_DW.HILInitialize1_Card,
        heli_q8_P.HILInitialize1_AOChannels, 8U,
        &heli_q8_DW.HILInitialize1_AOMinimums[0],
        &heli_q8_DW.HILInitialize1_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize1_AOStart && !is_switching) ||
        (heli_q8_P.HILInitialize1_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_DW.HILInitialize1_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_P.HILInitialize1_AOInitial;
        }
      }

      result = hil_write_analog(heli_q8_DW.HILInitialize1_Card,
        heli_q8_P.HILInitialize1_AOChannels, 8U,
        &heli_q8_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_P.HILInitialize1_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_DW.HILInitialize1_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_P.HILInitialize1_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_DW.HILInitialize1_Card, heli_q8_P.HILInitialize1_AOChannels, 8U,
         &heli_q8_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize1_EIPStart && !is_switching) ||
        (heli_q8_P.HILInitialize1_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_DW.HILInitialize1_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_P.HILInitialize1_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(heli_q8_DW.HILInitialize1_Card,
        heli_q8_P.HILInitialize1_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &heli_q8_DW.HILInitialize1_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize1_EIStart && !is_switching) ||
        (heli_q8_P.HILInitialize1_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_DW.HILInitialize1_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = heli_q8_P.HILInitialize1_EIInitial;
        }
      }

      result = hil_set_encoder_counts(heli_q8_DW.HILInitialize1_Card,
        heli_q8_P.HILInitialize1_EIChannels, 8U,
        &heli_q8_DW.HILInitialize1_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize1_POPStart && !is_switching) ||
        (heli_q8_P.HILInitialize1_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_DW.HILInitialize1_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_P.HILInitialize1_POModes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_DW.HILInitialize1_Card,
        heli_q8_P.HILInitialize1_POChannels, 8U, (t_pwm_mode *)
        &heli_q8_DW.HILInitialize1_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize1_POChannels =
          heli_q8_P.HILInitialize1_POChannels;
        int32_T *dw_POModeValues = &heli_q8_DW.HILInitialize1_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            heli_q8_DW.HILInitialize1_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize1_POChannels[i1]);
            heli_q8_DW.HILInitialize1_POSortedFreqs[num_duty_cycle_modes] =
              heli_q8_P.HILInitialize1_POFrequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_DW.HILInitialize1_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize1_POChannels[i1]);
            heli_q8_DW.HILInitialize1_POSortedFreqs[7U - num_frequency_modes] =
              heli_q8_P.HILInitialize1_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_DW.HILInitialize1_Card,
          &heli_q8_DW.HILInitialize1_POSortedChans[0], num_duty_cycle_modes,
          &heli_q8_DW.HILInitialize1_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_DW.HILInitialize1_Card,
          &heli_q8_DW.HILInitialize1_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_DW.HILInitialize1_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_DW.HILInitialize1_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_P.HILInitialize1_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &heli_q8_DW.HILInitialize1_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_P.HILInitialize1_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &heli_q8_DW.HILInitialize1_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_P.HILInitialize1_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_DW.HILInitialize1_Card,
        heli_q8_P.HILInitialize1_POChannels, 8U,
        (t_pwm_configuration *) &heli_q8_DW.HILInitialize1_POModeValues[0],
        (t_pwm_alignment *) &heli_q8_DW.HILInitialize1_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_DW.HILInitialize1_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &heli_q8_DW.HILInitialize1_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_q8_P.HILInitialize1_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_P.HILInitialize1_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_DW.HILInitialize1_Card,
        heli_q8_P.HILInitialize1_POChannels, 8U,
        &heli_q8_DW.HILInitialize1_POSortedFreqs[0],
        &heli_q8_DW.HILInitialize1_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize1_POStart && !is_switching) ||
        (heli_q8_P.HILInitialize1_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_P.HILInitialize1_POInitial;
        }
      }

      result = hil_write_pwm(heli_q8_DW.HILInitialize1_Card,
        heli_q8_P.HILInitialize1_POChannels, 8U,
        &heli_q8_DW.HILInitialize1_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_P.HILInitialize1_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_P.HILInitialize1_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_DW.HILInitialize1_Card, heli_q8_P.HILInitialize1_POChannels, 8U,
         &heli_q8_DW.HILInitialize1_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8/Heli 3D1/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_q8_DW.HILInitialize1_Card,
      heli_q8_P.HILReadEncoderTimebase_SamplesI,
      heli_q8_P.HILReadEncoderTimebase_Channels, 3,
      &heli_q8_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (heli_q8_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (heli_q8_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_M, _rt_error_message);
    }
  }

  /* Start for S-Function (stream_call_block): '<S5>/Stream Call1' incorporates:
   *  Constant: '<S5>/Constant'
   *  S-Function (string_constant_block): '<S5>/String Constant'
   */

  /* S-Function Block: heli_q8/IMU1/Stream Call1 (stream_call_block) */
  {
    heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
    heli_q8_DW.StreamCall1_Stream = NULL;
  }

  /* Start for RateTransition: '<S6>/Rate Transition: x' */
  heli_q8_B.RateTransitionx = heli_q8_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S6>/Rate Transition: y' */
  heli_q8_B.RateTransitiony = heli_q8_P.RateTransitiony_InitialConditio;

  /* Start for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8/Joystick1/Game Controller (game_controller_block) */
  {
    if (heli_q8_P.GameController_Enabled) {
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

      result = game_controller_open(heli_q8_P.GameController_ControllerNumber,
        heli_q8_P.GameController_BufferSize, deadzone, saturation,
        heli_q8_P.GameController_AutoCenter, 0, 1.0,
        &heli_q8_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for Memory: '<S5>/Memory' */
    memcpy(&heli_q8_DW.Memory_PreviousInput[0],
           &heli_q8_P.Memory_InitialCondition[0], 10U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      heli_q8_DW.UnitDelay_DSTATE[i] = heli_q8_P.x_0[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S7>/Unit Delay' */

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay1' */
    memcpy(&heli_q8_DW.UnitDelay1_DSTATE[0], &heli_q8_P.P_0[0], 36U * sizeof
           (real_T));

    /* InitializeConditions for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
    heli_q8_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
    heli_q8_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S8>/Integrator' */
    heli_q8_X.Integrator_CSTATE = heli_q8_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S8>/Integrator1' */
    heli_q8_X.Integrator1_CSTATE = heli_q8_P.Integrator1_IC;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition: x' */
    heli_q8_DW.RateTransitionx_Buffer0 =
      heli_q8_P.RateTransitionx_InitialConditio;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition: y' */
    heli_q8_DW.RateTransitiony_Buffer0 =
      heli_q8_P.RateTransitiony_InitialConditio;

    /* InitializeConditions for TransferFcn: '<S4>/Travel: Transfer Fcn' */
    heli_q8_X.TravelTransferFcn_CSTATE = 0.0;
  }
}

/* Model terminate function */
void heli_q8_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: heli_q8/HIL Initialize1 (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_DW.HILInitialize1_Card);
    hil_monitor_stop_all(heli_q8_DW.HILInitialize1_Card);
    is_switching = false;
    if ((heli_q8_P.HILInitialize1_AOTerminate && !is_switching) ||
        (heli_q8_P.HILInitialize1_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_DW.HILInitialize1_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_P.HILInitialize1_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((heli_q8_P.HILInitialize1_POTerminate && !is_switching) ||
        (heli_q8_P.HILInitialize1_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_P.HILInitialize1_POFinal;
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
      result = hil_write(heli_q8_DW.HILInitialize1_Card
                         , heli_q8_P.HILInitialize1_AOChannels,
                         num_final_analog_outputs
                         , heli_q8_P.HILInitialize1_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_DW.HILInitialize1_AOVoltages[0]
                         , &heli_q8_DW.HILInitialize1_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_DW.HILInitialize1_Card,
            heli_q8_P.HILInitialize1_AOChannels, num_final_analog_outputs,
            &heli_q8_DW.HILInitialize1_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_DW.HILInitialize1_Card,
            heli_q8_P.HILInitialize1_POChannels, num_final_pwm_outputs,
            &heli_q8_DW.HILInitialize1_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_DW.HILInitialize1_Card);
    hil_monitor_delete_all(heli_q8_DW.HILInitialize1_Card);
    hil_close(heli_q8_DW.HILInitialize1_Card);
    heli_q8_DW.HILInitialize1_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S5>/Stream Call1' incorporates:
   *  Constant: '<S5>/Constant'
   *  S-Function (string_constant_block): '<S5>/String Constant'
   */

  /* S-Function Block: heli_q8/IMU1/Stream Call1 (stream_call_block) */
  {
    if (heli_q8_DW.StreamCall1_Stream != NULL) {
      stream_close(heli_q8_DW.StreamCall1_Stream);
      heli_q8_DW.StreamCall1_Stream = NULL;
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8/Joystick1/Game Controller (game_controller_block) */
  {
    if (heli_q8_P.GameController_Enabled) {
      game_controller_close(heli_q8_DW.GameController_Controller);
      heli_q8_DW.GameController_Controller = NULL;
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
  heli_q8_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_update(tid);
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
  heli_q8_initialize();
}

void MdlTerminate(void)
{
  heli_q8_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_T *heli_q8(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)heli_q8_M, 0,
                sizeof(RT_MODEL_heli_q8_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_M->solverInfo, &heli_q8_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_M->solverInfo, &rtmGetTPtr(heli_q8_M));
    rtsiSetStepSizePtr(&heli_q8_M->solverInfo, &heli_q8_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_M->solverInfo, &heli_q8_M->derivs);
    rtsiSetContStatesPtr(&heli_q8_M->solverInfo, (real_T **)
                         &heli_q8_M->contStates);
    rtsiSetNumContStatesPtr(&heli_q8_M->solverInfo,
      &heli_q8_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_M->solverInfo,
      &heli_q8_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_M->solverInfo,
      &heli_q8_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_M->solverInfo,
      &heli_q8_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_M->solverInfo, (&rtmGetErrorStatus(heli_q8_M)));
    rtsiSetRTModelPtr(&heli_q8_M->solverInfo, heli_q8_M);
  }

  rtsiSetSimTimeStep(&heli_q8_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_M->intgData.f[0] = heli_q8_M->odeF[0];
  heli_q8_M->contStates = ((real_T *) &heli_q8_X);
  rtsiSetSolverData(&heli_q8_M->solverInfo, (void *)&heli_q8_M->intgData);
  rtsiSetSolverName(&heli_q8_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_M->Timing.sampleTimes = (&heli_q8_M->Timing.sampleTimesArray[0]);
    heli_q8_M->Timing.offsetTimes = (&heli_q8_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_M, &heli_q8_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_q8_M->Timing.perTaskSampleHitsArray;
    heli_q8_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_M, -1);
  heli_q8_M->Timing.stepSize0 = 0.002;
  heli_q8_M->Timing.stepSize1 = 0.002;
  heli_q8_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_M->Sizes.checksums[0] = (382816599U);
  heli_q8_M->Sizes.checksums[1] = (3980665657U);
  heli_q8_M->Sizes.checksums[2] = (1363506072U);
  heli_q8_M->Sizes.checksums[3] = (1771417608U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    heli_q8_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(heli_q8_M->extModeInfo,
      &heli_q8_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_M->extModeInfo, heli_q8_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_M->extModeInfo, rtmGetTPtr(heli_q8_M));
  }

  heli_q8_M->solverInfoPtr = (&heli_q8_M->solverInfo);
  heli_q8_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_M->blockIO = ((void *) &heli_q8_B);
  (void) memset(((void *) &heli_q8_B), 0,
                sizeof(B_heli_q8_T));

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_B.UnitDelay[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_B.x_hat[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_B.P_hat[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_B.x_bar[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_B.P_bar[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_B.y[i] = 0.0;
    }

    heli_q8_B.Gain2[0] = 0.0;
    heli_q8_B.Gain2[1] = 0.0;
    heli_q8_B.Gain2[2] = 0.0;
    heli_q8_B.Sum2 = 0.0;
    heli_q8_B.Sum3 = 0.0;
    heli_q8_B.Gain1[0] = 0.0;
    heli_q8_B.Gain1[1] = 0.0;
    heli_q8_B.Gain1[2] = 0.0;
    heli_q8_B.TravelCounttorad = 0.0;
    heli_q8_B.ElevationCounttorad = 0.0;
    heli_q8_B.Sum = 0.0;
    heli_q8_B.ElevationTransferFcn = 0.0;
    heli_q8_B.PitchCounttorad = 0.0;
    heli_q8_B.PitchTransferFcn = 0.0;
    heli_q8_B.RateTransitionx = 0.0;
    heli_q8_B.Joystick_gain_x = 0.0;
    heli_q8_B.RateTransitiony = 0.0;
    heli_q8_B.Joystick_gain_y = 0.0;
    heli_q8_B.Multiply[0] = 0.0;
    heli_q8_B.Multiply[1] = 0.0;
    heli_q8_B.Sum1[0] = 0.0;
    heli_q8_B.Sum1[1] = 0.0;
    heli_q8_B.TravelTransferFcn = 0.0;
    heli_q8_B.FrontmotorSaturation = 0.0;
    heli_q8_B.BackmotorSaturation = 0.0;
    heli_q8_B.Sum_f = 0.0;
    heli_q8_B.Sum2_l = 0.0;
    heli_q8_B.euler_rates[0] = 0.0;
    heli_q8_B.euler_rates[1] = 0.0;
    heli_q8_B.euler_rates[2] = 0.0;
  }

  /* parameters */
  heli_q8_M->defaultParam = ((real_T *)&heli_q8_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_X;
    heli_q8_M->contStates = (x);
    (void) memset((void *)&heli_q8_X, 0,
                  sizeof(X_heli_q8_T));
  }

  /* states (dwork) */
  heli_q8_M->dwork = ((void *) &heli_q8_DW);
  (void) memset((void *)&heli_q8_DW, 0,
                sizeof(DW_heli_q8_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_q8_DW.UnitDelay_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      heli_q8_DW.UnitDelay1_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize1_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize1_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize1_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize1_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize1_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize1_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize1_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize1_POValues[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_DW.Memory_PreviousInput[i] = 0.0;
    }
  }

  heli_q8_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_DW.RateTransitiony_Buffer0 = 0.0;
  heli_q8_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_M->Sizes.numContStates = (5);/* Number of continuous states */
  heli_q8_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  heli_q8_M->Sizes.numY = (0);         /* Number of model outputs */
  heli_q8_M->Sizes.numU = (0);         /* Number of model inputs */
  heli_q8_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_M->Sizes.numSampTimes = (3); /* Number of sample times */
  heli_q8_M->Sizes.numBlocks = (101);  /* Number of blocks */
  heli_q8_M->Sizes.numBlockIO = (30);  /* Number of block outputs */
  heli_q8_M->Sizes.numBlockPrms = (648);/* Sum of parameter "widths" */
  return heli_q8_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
