@echo on
@call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Auxiliary\Build\VCVARSALL.BAT " x86_amd64
set MATLAB=C:\PROGRA~1\MATLAB\R2020b
nmake -f heli_q8_pres4.mk  EXT_MODE=1 EXTMODE_STATIC_ALLOC=0 TMW_EXTMODE_TESTING=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 SHOW_TIMES=0 DEBUG=0 DEBUG_HEAP=0 INCLUDE_MDL_TERMINATE_FCN=1 OPTS="-DEXT_MODE -DON_TARGET_WAIT_FOR_START=1 -DTID01EQ=1"
