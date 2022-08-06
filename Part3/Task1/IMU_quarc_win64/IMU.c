/*
 * IMU.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "IMU".
 *
 * Model version              : 11.9
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed Oct 27 09:35:34 2021
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IMU.h"
#include "IMU_private.h"
#include "IMU_dt.h"

t_stream IMU_rtZt_stream = NULL;

/* Block signals (default storage) */
B_IMU_T IMU_B;

/* Block states (default storage) */
DW_IMU_T IMU_DW;

/* Real-time model */
static RT_MODEL_IMU_T IMU_M_;
RT_MODEL_IMU_T *const IMU_M = &IMU_M_;

/* Model output function */
void IMU_output(void)
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamCall1_o1;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamCall1_o3;
  int32_T rtb_StreamRead1_o5;
  boolean_T rtb_StreamRead1_o3;
  int32_T i;

  /* S-Function (stream_call_block): '<S1>/Stream Call1' incorporates:
   *  Constant: '<S1>/Constant'
   *  S-Function (string_constant_block): '<S1>/String Constant'
   */

  /* S-Function Block: IMU/IMU/Stream Call1 (stream_call_block) */
  {
    t_error result = 0;
    t_boolean close_flag = (IMU_P.Constant_Value != 0);
    rtb_StreamCall1_o1 = NULL;
    switch (IMU_DW.StreamCall1_State) {
     case STREAM_CALL_STATE_NOT_CONNECTED:
      {
        if (!close_flag) {
          /* Make sure URI is null-terminated */
          if (string_length((char *) IMU_P.StringConstant_Value, 255) == 255) {
            rtmSetErrorStatus(IMU_M,
                              "URI passed to Stream Call block is not null-terminated!");
            result = -QERR_STRING_NOT_TERMINATED;
          } else {
            result = stream_connect((char *) IMU_P.StringConstant_Value,
              IMU_P.StreamCall1_NonBlocking != 0,
              IMU_P.StreamCall1_SendBufferSize,
              IMU_P.StreamCall1_ReceiveBufferSize, &IMU_DW.StreamCall1_Stream);
            if (result == 0) {
              IMU_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(IMU_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    IMU_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &IMU_DW.StreamCall1_Stream;
            } else if (result == -QERR_WOULD_BLOCK) {
              IMU_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTING;
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

          result = stream_poll(IMU_DW.StreamCall1_Stream, &timeout,
                               STREAM_POLL_CONNECT);
          if (result > 0) {
            IMU_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
            stream_set_byte_order(IMU_DW.StreamCall1_Stream,
                                  (t_stream_byte_order) IMU_P.StreamCall1_Endian);
            rtb_StreamCall1_o1 = &IMU_DW.StreamCall1_Stream;
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
        rtb_StreamCall1_o1 = &IMU_DW.StreamCall1_Stream;
        if (!close_flag) {
          break;
        }

        /* Fall through deliberately */
      }

     default:
      {
        t_error close_result = stream_close(IMU_DW.StreamCall1_Stream);
        if (close_result == 0) {
          IMU_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
          IMU_DW.StreamCall1_Stream = NULL;
          rtb_StreamCall1_o1 = NULL;
        } else if (result == 0) {
          result = close_result;
        }
        break;
      }
    }

    IMU_B.StreamCall1_o2 = IMU_DW.StreamCall1_State;
    rtb_StreamCall1_o3 = (int32_T) result;
  }

  /* S-Function (stream_formatted_write_block): '<S1>/Stream Formatted Write' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  {
    t_error result;
    if (rtb_StreamCall1_o1 != NULL) {
      result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
        IMU_P.StreamFormattedWrite_MaxUnits, &rtb_StreamFormattedWrite_o2,
        "%c\n"
        , (char) IMU_P.Constant1_Value
        );
      if (result > 0) {
        result = stream_flush(*rtb_StreamCall1_o1);
      }

      if (result == -QERR_WOULD_BLOCK) {
        result = 0;
      }
    }
  }

  /* S-Function (stream_read_block): '<S1>/Stream Read1' incorporates:
   *  Constant: '<S1>/Constant1'
   *  S-Function (stream_call_block): '<S1>/Stream Call1'
   *  S-Function (stream_formatted_write_block): '<S1>/Stream Formatted Write'
   */

  /* S-Function Block: IMU/IMU/Stream Read1 (stream_read_block) */
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
    /* Switch: '<S1>/Switch' */
    if (rtb_StreamRead1_o3) {
      /* Switch: '<S1>/Switch' incorporates:
       *  DataTypeConversion: '<S1>/Data Type Conversion'
       */
      IMU_B.Switch[i] = rtb_StreamRead1_o2[i];
    } else {
      /* Switch: '<S1>/Switch' incorporates:
       *  Memory: '<S1>/Memory'
       */
      IMU_B.Switch[i] = IMU_DW.Memory_PreviousInput[i];
    }

    /* End of Switch: '<S1>/Switch' */
  }

  for (i = 0; i < 3; i++) {
    /* Gain: '<S1>/Gain1' */
    IMU_B.Gain1[i] = 0.0;
    IMU_B.Gain1[i] += IMU_P.Gain1_Gain[i] * IMU_B.Switch[3];
    IMU_B.Gain1[i] += IMU_P.Gain1_Gain[i + 3] * IMU_B.Switch[4];
    IMU_B.Gain1[i] += IMU_P.Gain1_Gain[i + 6] * IMU_B.Switch[5];
  }

  for (i = 0; i < 3; i++) {
    /* Gain: '<S1>/Gain2' */
    IMU_B.Gain2[i] = 0.0;
    IMU_B.Gain2[i] += IMU_P.Gain2_Gain[i] * IMU_B.Switch[0];
    IMU_B.Gain2[i] += IMU_P.Gain2_Gain[i + 3] * IMU_B.Switch[1];
    IMU_B.Gain2[i] += IMU_P.Gain2_Gain[i + 6] * IMU_B.Switch[2];
  }

  /* S-Function (stop_with_error_block): '<S1>/Stop with Call Error' */

  /* S-Function Block: IMU/IMU/Stop with Call Error (stop_with_error_block) */
  {
    if (rtb_StreamCall1_o3 < 0) {
      msg_get_error_messageA(NULL, rtb_StreamCall1_o3, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(IMU_M, _rt_error_message);
      return;
    }
  }

  /* S-Function (stop_with_error_block): '<S1>/Stop with Read Error' */

  /* S-Function Block: IMU/IMU/Stop with Read Error (stop_with_error_block) */
  {
    if (rtb_StreamRead1_o5 < 0) {
      msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(IMU_M, _rt_error_message);
      return;
    }
  }
}

/* Model update function */
void IMU_update(void)
{
  /* Update for Memory: '<S1>/Memory' */
  memcpy(&IMU_DW.Memory_PreviousInput[0], &IMU_B.Switch[0], 10U * sizeof(real_T));

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++IMU_M->Timing.clockTick0)) {
    ++IMU_M->Timing.clockTickH0;
  }

  IMU_M->Timing.t[0] = IMU_M->Timing.clockTick0 * IMU_M->Timing.stepSize0 +
    IMU_M->Timing.clockTickH0 * IMU_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void IMU_initialize(void)
{
  /* Start for S-Function (stream_call_block): '<S1>/Stream Call1' incorporates:
   *  Constant: '<S1>/Constant'
   *  S-Function (string_constant_block): '<S1>/String Constant'
   */

  /* S-Function Block: IMU/IMU/Stream Call1 (stream_call_block) */
  {
    IMU_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
    IMU_DW.StreamCall1_Stream = NULL;
  }

  /* InitializeConditions for Memory: '<S1>/Memory' */
  memcpy(&IMU_DW.Memory_PreviousInput[0], &IMU_P.Memory_InitialCondition[0], 10U
         * sizeof(real_T));
}

/* Model terminate function */
void IMU_terminate(void)
{
  /* Terminate for S-Function (stream_call_block): '<S1>/Stream Call1' incorporates:
   *  Constant: '<S1>/Constant'
   *  S-Function (string_constant_block): '<S1>/String Constant'
   */

  /* S-Function Block: IMU/IMU/Stream Call1 (stream_call_block) */
  {
    if (IMU_DW.StreamCall1_Stream != NULL) {
      stream_close(IMU_DW.StreamCall1_Stream);
      IMU_DW.StreamCall1_Stream = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  IMU_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  IMU_update();
  UNUSED_PARAMETER(tid);
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
  IMU_initialize();
}

void MdlTerminate(void)
{
  IMU_terminate();
}

/* Registration function */
RT_MODEL_IMU_T *IMU(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)IMU_M, 0,
                sizeof(RT_MODEL_IMU_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = IMU_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    IMU_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    IMU_M->Timing.sampleTimes = (&IMU_M->Timing.sampleTimesArray[0]);
    IMU_M->Timing.offsetTimes = (&IMU_M->Timing.offsetTimesArray[0]);

    /* task periods */
    IMU_M->Timing.sampleTimes[0] = (0.002);

    /* task offsets */
    IMU_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(IMU_M, &IMU_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = IMU_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    IMU_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(IMU_M, -1);
  IMU_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  IMU_M->Sizes.checksums[0] = (2374521592U);
  IMU_M->Sizes.checksums[1] = (323576762U);
  IMU_M->Sizes.checksums[2] = (8702828U);
  IMU_M->Sizes.checksums[3] = (1862786073U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    IMU_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(IMU_M->extModeInfo,
      &IMU_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(IMU_M->extModeInfo, IMU_M->Sizes.checksums);
    rteiSetTPtr(IMU_M->extModeInfo, rtmGetTPtr(IMU_M));
  }

  IMU_M->solverInfoPtr = (&IMU_M->solverInfo);
  IMU_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&IMU_M->solverInfo, 0.002);
  rtsiSetSolverMode(&IMU_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  IMU_M->blockIO = ((void *) &IMU_B);
  (void) memset(((void *) &IMU_B), 0,
                sizeof(B_IMU_T));

  /* parameters */
  IMU_M->defaultParam = ((real_T *)&IMU_P);

  /* states (dwork) */
  IMU_M->dwork = ((void *) &IMU_DW);
  (void) memset((void *)&IMU_DW, 0,
                sizeof(DW_IMU_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    IMU_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  IMU_M->Sizes.numContStates = (0);    /* Number of continuous states */
  IMU_M->Sizes.numY = (0);             /* Number of model outputs */
  IMU_M->Sizes.numU = (0);             /* Number of model inputs */
  IMU_M->Sizes.sysDirFeedThru = (0);   /* The model is not direct feedthrough */
  IMU_M->Sizes.numSampTimes = (1);     /* Number of sample times */
  IMU_M->Sizes.numBlocks = (17);       /* Number of blocks */
  IMU_M->Sizes.numBlockIO = (4);       /* Number of block outputs */
  IMU_M->Sizes.numBlockPrms = (292);   /* Sum of parameter "widths" */
  return IMU_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
