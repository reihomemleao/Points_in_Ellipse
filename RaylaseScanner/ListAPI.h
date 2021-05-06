#ifndef _SPICE3_LIST_API_
#define _SPICE3_LIST_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlCommandListHandle __stdcall rlListAllocate( rlHandle handle );
extern "C" DLLEXPORT rlCommandListHandle __stdcall rlListAllocateFromString( rlHandle handle, const char* commandList );

extern "C" DLLEXPORT rlResult __stdcall rlListReleaseHandle( rlCommandListHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlListSet( rlHandle handle, int32_t listID, rlCommandListHandle list, bool append, int executionLimit );
extern "C" DLLEXPORT rlResult __stdcall rlListGet( rlHandle handle, int32_t listID, rlCommandListHandle list );
extern "C" DLLEXPORT rlResult __stdcall rlListLoad( rlHandle handle, int32_t listID );
extern "C" DLLEXPORT rlResult __stdcall rlListStore( rlHandle handle, int32_t listID );

extern "C" DLLEXPORT rlResult __stdcall rlListExecute( rlHandle handle, int32_t listID );
extern "C" DLLEXPORT rlResult __stdcall rlListDelete( rlHandle handle, int32_t listID, bool fromDisk );

extern "C" DLLEXPORT rlResult __stdcall rlListResetExecution( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlListAbortExecution( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlListGetListStatus( rlHandle handle, int32_t listId, rlListStatus* listStatus );
extern "C" DLLEXPORT rlResult __stdcall rlListIsExecutionInProgress( rlHandle handle, bool* inProgress );

extern "C" DLLEXPORT rlResult __stdcall rlListGetListCaret( rlHandle handle, int32_t listId, int32_t* caret );
extern "C" DLLEXPORT rlResult __stdcall rlListGetStoredListIDs( rlHandle handle, uint32_t* outBuffer, uint32_t bufferLen, uint32_t* outLen );

extern "C" DLLEXPORT rlResult __stdcall rlListClearPendingEvents( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlListWaitForListIdle( rlHandle handle, int32_t timeoutMs, bool* successBeforeTimeout, int32_t* listId );
extern "C" DLLEXPORT rlResult __stdcall rlListWaitForListDone( rlHandle handle, int32_t timeoutMs, bool* successBeforeTimeout, int32_t* listId );
extern "C" DLLEXPORT rlResult __stdcall rlListWaitForProgress( rlHandle handle, int32_t timeoutMs, bool* successBeforeTimeout, int32_t* progressId );

extern "C" DLLEXPORT rlResult __stdcall rlListInterruptWaitForListIdle( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlListInterruptWaitForListDone( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlListInterruptWaitForProgress( rlHandle handle );

extern "C" DLLEXPORT rlCallbackHandle __stdcall rlListRegisterListIdleCallback( rlHandle handle, rlListIdleCallback func );
extern "C" DLLEXPORT rlResult __stdcall rlListUnRegisterListIdleCallback( rlCallbackHandle handle );
extern "C" DLLEXPORT rlCallbackHandle __stdcall rlListRegisterListDoneCallback( rlHandle handle, rlListDoneCallback func );
extern "C" DLLEXPORT rlResult __stdcall rlListUnRegisterListDoneCallback( rlCallbackHandle handle );
extern "C" DLLEXPORT rlCallbackHandle __stdcall rlListRegisterProgressCallback( rlHandle handle, rlProgressCallback func );
extern "C" DLLEXPORT rlResult __stdcall rlListUnRegisterProgressCallback( rlCallbackHandle handle );
extern "C" DLLEXPORT rlCallbackHandle __stdcall rlListRegisterErrorEventCallback( rlHandle handle, rlErrorCallback func );
extern "C" DLLEXPORT rlResult __stdcall rlListUnRegisterErrorEventCallback( rlCallbackHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendCommandFromString( rlCommandListHandle handle, const char* command );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendList( rlCommandListHandle handle, rlCommandListHandle other );
extern "C" DLLEXPORT rlResult __stdcall rlListStringLen( rlCommandListHandle handle, uint32_t* stringLength );
extern "C" DLLEXPORT rlResult __stdcall rlListToString( rlCommandListHandle handle, char* buffer, uint32_t bufferSize, uint32_t* stringLength );
extern "C" DLLEXPORT rlResult __stdcall rlListCommandCount( rlCommandListHandle handle, uint32_t* count );

extern "C" DLLEXPORT rlResult __stdcall rlListClear( rlCommandListHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlListSetExecutionLimit( rlCommandListHandle handle, int executionLimit );
extern "C" DLLEXPORT rlResult __stdcall rlListGetExecutionLimit( rlCommandListHandle handle, int* limit );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendLmFrequency( rlCommandListHandle handle, double frequency );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendLmWidth( rlCommandListHandle handle, double width );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendJumpSpeed( rlCommandListHandle handle, double speed );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMarkSpeed( rlCommandListHandle handle, double speed );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMagnificationSpeed( rlCommandListHandle handle, double speed );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendJumpDelay( rlCommandListHandle handle, double delay );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendEnableVariableJumpDelay( rlCommandListHandle handle, bool enable );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMinJumpDelay( rlCommandListHandle handle, double delay );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendJumpLengthLimit( rlCommandListHandle handle, double length );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMarkDelay( rlCommandListHandle handle, double delay );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendPolyDelay( rlCommandListHandle handle, double delay );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendEnableVariablePolyDelay( rlCommandListHandle handle, bool enable );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendLaserOnDelay( rlCommandListHandle handle, double delay );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendLaserOffDelay( rlCommandListHandle handle, double delay );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendEvaluationLeadTime( rlCommandListHandle handle, double time );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendIncrementCounter( rlCommandListHandle handle, const char* counterName );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBooleanSet( rlCommandListHandle handle, const char* variableName, bool value );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendIntegerSet( rlCommandListHandle handle, const char* variableName, int32_t value );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendProgress( rlCommandListHandle handle, uint32_t id );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendEnablePilot( rlCommandListHandle handle, bool enable );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendArmLaser( rlCommandListHandle handle, bool enable );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendEnableVelocityCorrection( rlCommandListHandle handle, bool enable );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendEnablePowerCorrection( rlCommandListHandle handle, bool enable );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendEnablePowerCalibration( rlCommandListHandle handle, bool enable );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendLaserOn2( rlCommandListHandle handle, uint32_t pulses );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendLaserOn( rlCommandListHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendLaserOff( rlCommandListHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendPower( rlCommandListHandle handle, uint16_t power );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendPower2( rlCommandListHandle handle, uint16_t power, double powerChangeRate );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendSimmerPower( rlCommandListHandle handle, uint16_t power );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendEnableDashedLine( rlCommandListHandle handle, bool enable, double start );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendDashedLinePattern( rlCommandListHandle handle, const double* onOffPattern, uint32_t onOffPatternLength );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendScalingFactor( rlCommandListHandle handle, double x, double y );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendTransformation( rlCommandListHandle handle, rlTransform3D* transformation );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendWaitStart( rlCommandListHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendStartMotf( rlCommandListHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendStopMotf2D( rlCommandListHandle handle, double x, double y );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendStopMotf3D( rlCommandListHandle handle, double x, double y, double z );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotfWaitPart( rlCommandListHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotfWaitDistance( rlCommandListHandle handle, double distance, rlMotfDistanceMode mode );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendSleep( rlCommandListHandle handle, double delay );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendEnableSkyWriting( rlCommandListHandle handle, bool enable );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendSkyWritingMinCoH( rlCommandListHandle handle, double minCoH );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendJumpAbs2D( rlCommandListHandle handle, double x, double y );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendJumpRel2D( rlCommandListHandle handle, double x, double y );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendJumpAbs3D( rlCommandListHandle handle, double x, double y, double z );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendJumpRel3D( rlCommandListHandle handle, double x, double y, double z );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMarkAbs2D( rlCommandListHandle handle, double x, double y );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMarkRel2D( rlCommandListHandle handle, double x, double y );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMarkAbs3D( rlCommandListHandle handle, double x, double y, double z );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMarkRel3D( rlCommandListHandle handle, double x, double y, double z );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendMagnificationAbs( rlCommandListHandle handle, double magnification, bool async );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMagnificationRel( rlCommandListHandle handle, double magnification, bool async );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendLabel( rlCommandListHandle handle, const char* label );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchAbs( rlCommandListHandle handle, int32_t pos );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchRel( rlCommandListHandle handle, int32_t pos );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchToLabel( rlCommandListHandle handle, const char* label );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchAbsCondPort( rlCommandListHandle handle, int32_t pos, uint32_t cond, rlIOPort port, bool compareAsMask, bool ifNotTrue, uint32_t mask );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchRelCondPort( rlCommandListHandle handle, int32_t pos, uint32_t cond, rlIOPort port, bool compareAsMask, bool ifNotTrue, uint32_t mask );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchToLabelCondPort( rlCommandListHandle handle, const char* label, uint32_t cond, rlIOPort port, bool compareAsMask, bool ifNotTrue, uint32_t mask );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchAbsCondFlag( rlCommandListHandle handle, int32_t pos, const char* variableName, bool ifNotTrue );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchRelCondFlag( rlCommandListHandle handle, int32_t pos, const char* variableName, bool ifNotTrue );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchToLabelCondFlag( rlCommandListHandle handle, const char* label, const char* variableName, bool ifNotTrue );

// No longer supported, use  rlListAppendCallList*() that offers the same functionality
//extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchToList( rlCommandListHandle handle, int32_t listID );
//extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchToListCond( rlCommandListHandle handle, int32_t listID, uint16_t condMask, rlIOPort port );
//extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchToListCondFlag( rlCommandListHandle handle, int32_t listID, rlBooleanVariableHandle variable );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchList( rlCommandListHandle handle, int32_t listID );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchListCondPort( rlCommandListHandle handle, int32_t listID, uint32_t cond, rlIOPort port, bool compareAsMask, bool ifNotTrue, uint32_t mask );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchListCondFlag( rlCommandListHandle handle, int32_t listID, const char* variableName, bool ifNotTrue );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCallList( rlCommandListHandle handle, int32_t listID );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCallListCondPort( rlCommandListHandle handle, int32_t listID, uint32_t cond, rlIOPort port, bool compareAsMask, bool ifNotTrue, uint32_t mask );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCallListCondFlag( rlCommandListHandle handle, int32_t listID, const char* variableName, bool ifNotTrue );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendLoopStart( rlCommandListHandle handle, int32_t count );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendLoopEnd( rlCommandListHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendLoopBreak( rlCommandListHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendSwitchPort( rlCommandListHandle handle, rlIOPort port, bool compareAsMask, uint32_t mask );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendSwitchValue( rlCommandListHandle handle, const char* variableName );

// No longer supported, use  rlListAppendCaseCallListPort() that offers the same functionality
//extern "C" DLLEXPORT rlResult __stdcall rlListAppendCaseList( rlCommandListHandle handle, int32_t listID, uint16_t condMask );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCaseBranchListPort( rlCommandListHandle handle, int32_t listID, uint32_t cond );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCaseCallListPort( rlCommandListHandle handle, int32_t listID, uint32_t cond );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendCaseAbsPort( rlCommandListHandle handle, int32_t pos, uint32_t cond );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCaseRelPort( rlCommandListHandle handle, int32_t pos, uint32_t cond );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCaseToLabelPort( rlCommandListHandle handle, const char* label, uint32_t cond );

// No longer supported, use  rlListAppendCaseCallListValue() that offers the same functionality
//extern "C" DLLEXPORT rlResult __stdcall rlListAppendCaseListValue( rlCommandListHandle handle, int32_t listID, int32_t value );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCaseBranchListValue( rlCommandListHandle handle, int32_t listID, int32_t value );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCaseCallListValue( rlCommandListHandle handle, int32_t listID, int32_t value );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendCaseAbsValue( rlCommandListHandle handle, int32_t pos, int32_t value );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCaseRelValue( rlCommandListHandle handle, int32_t pos, int32_t value );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCaseToLabelValue( rlCommandListHandle handle, const char* label, int32_t value );

// No longer supported, use  rlListAppendDefaultCallList*() that offers the same functionality
//extern "C" DLLEXPORT rlResult __stdcall rlListAppendDefaultList( rlCommandListHandle handle, int32_t listID );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendDefaultBranchList( rlCommandListHandle handle, int32_t listID );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendDefaultCallList( rlCommandListHandle handle, int32_t listID );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendDefaultAbs( rlCommandListHandle handle, int32_t pos );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendDefaultRel( rlCommandListHandle handle, int32_t pos );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendDefaultToLabel( rlCommandListHandle handle, const char* label );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendExitList( rlCommandListHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendExitListCondPort( rlCommandListHandle handle, uint32_t cond, rlIOPort port, bool compareAsMask, bool ifNotTrue, uint32_t mask );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendExitListCondFlag( rlCommandListHandle handle, const char* variableName, bool ifNotTrue );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendBranchStandAloneList( rlCommandListHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendSelectFont( rlCommandListHandle handle, int32_t fontID );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMarkChar( rlCommandListHandle handle, char c );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMarkText( rlCommandListHandle handle, const char* text );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMarkTime( rlCommandListHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMarkCounter( rlCommandListHandle handle, const char* counterName, int32_t len );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendArcAbs2D( rlCommandListHandle handle, double x, double y, double sweep );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendArcAbs3D( rlCommandListHandle handle, double x, double y, double z, double sweep );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendArcRel2D( rlCommandListHandle handle, double x, double y, double sweep );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendArcRel3D( rlCommandListHandle handle, double x, double y, double z, double sweep );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendEllipseAbs2D( rlCommandListHandle handle, double x, double y, double sweep, double rotation, double ratio );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendEllipseAbs3D( rlCommandListHandle handle, double x, double y, double z, double sweep, double rotation, double ratio );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendEllipseRel2D( rlCommandListHandle handle, double x, double y, double sweep, double rotation, double ratio );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendEllipseRel3D( rlCommandListHandle handle, double x, double y, double z, double sweep, double rotation, double ratio );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendEllipticCurveAbs2D( rlCommandListHandle handle, double x, double y, double sweep, double rotation, double ratio );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendEllipticCurveAbs3D( rlCommandListHandle handle, double x, double y, double z, double sweep, double rotation, double ratio );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendEllipticCurveRel2D( rlCommandListHandle handle, double x, double y, double sweep, double rotation, double ratio );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendEllipticCurveRel3D( rlCommandListHandle handle, double x, double y, double z, double sweep, double rotation, double ratio );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendQuadraticBezierAbs2D( rlCommandListHandle handle, double targetX, double targetY, double controlX, double controlY );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendQuadraticBezierAbs3D( rlCommandListHandle handle, double targetX, double targetY, double targetZ, double controlX, double controlY, double controlZ );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendQuadraticBezierRel2D( rlCommandListHandle handle, double targetX, double targetY, double controlX, double controlY );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendQuadraticBezierRel3D( rlCommandListHandle handle, double targetX, double targetY, double targetZ, double controlX, double controlY, double controlZ );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCubicBezierAbs2D( rlCommandListHandle handle, double targetX, double targetY, double control0X, double control0Y, double control1X, double control1Y );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCubicBezierAbs3D( rlCommandListHandle handle, double targetX, double targetY, double targetZ, double control0X, double control0Y, double control0Z, double control1X, double control1Y, double control1Z );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCubicBezierRel2D( rlCommandListHandle handle, double targetX, double targetY, double control0X, double control0Y, double control1X, double control1Y );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendCubicBezierRel3D( rlCommandListHandle handle, double targetX, double targetY, double targetZ, double control0X, double control0Y, double control0Z, double control1X, double control1Y, double control1Z );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendBitmapLineAbs2D( rlCommandListHandle handle, double start_x, double start_y, double end_x, double end_y, const uint16_t* values, int32_t valuesLength );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBitmapLineRel2D( rlCommandListHandle handle, double start_x, double start_y, double end_x, double end_y, const uint16_t* values, int32_t valuesLength );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBitmapLineAbs3D( rlCommandListHandle handle, double start_x, double start_y, double start_z, double end_x, double end_y, double end_z, const uint16_t* values, int32_t valuesLength );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendBitmapLineRel3D( rlCommandListHandle handle, double start_x, double start_y, double start_z, double end_x, double end_y, double end_z, const uint16_t* values, int32_t valuesLength );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendPointAndShootLineAbs2D( rlCommandListHandle handle, double start_x, double start_y, double end_x, double end_y, const double* exposureTimes, int32_t exposureTimesLength, const uint16_t* powerValues, int32_t powerValuesLength );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendPointAndShootLineRel2D( rlCommandListHandle handle, double start_x, double start_y, double end_x, double end_y, const double* exposureTimes, int32_t exposureTimesLength, const uint16_t* powerValues, int32_t powerValuesLength );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendPointAndShootLineAbs3D( rlCommandListHandle handle, double start_x, double start_y, double start_z, double end_x, double end_y, double end_z, const double* exposureTimes, int32_t exposureTimesLength, const uint16_t* powerValues, int32_t powerValuesLength );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendPointAndShootLineRel3D( rlCommandListHandle handle, double start_x, double start_y, double start_z, double end_x, double end_y, double end_z, const double* exposureTimes, int32_t exposureTimesLength, const uint16_t* powerValues, int32_t powerValuesLength );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendEnhancedCommand( rlCommandListHandle handle, int32_t head, rlAxis axis, uint32_t command );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendGpioValue( rlCommandListHandle handle, rlIOPort port, rlPinAction mode, uint32_t value );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendDacValue( rlCommandListHandle handle, rlPowerTarget dac, uint32_t value );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendTraceConfig( rlCommandListHandle handle, const rlTraceBufferConfig* config, rlPinAction mode );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendTraceLabel( rlCommandListHandle handle, int32_t value );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendSpiWrite( rlCommandListHandle handle, int32_t module, uint32_t value );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendSelectHeadCorrection( rlCommandListHandle handle, std::int32_t head, std::int32_t correction );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendEnableWobble( rlCommandListHandle handle, bool enable );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendWobbleAmplitude( rlCommandListHandle handle, const rlPoint2D* amplitude );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendWobbleFrequency( rlCommandListHandle handle, const rlPoint2D* frequency );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendWobblePhase( rlCommandListHandle handle, const rlPoint2D* phase );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendWobbleCircle( rlCommandListHandle handle, double amplitude, double frequency );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendWobbleEight( rlCommandListHandle handle, const rlPoint2D* amplitude, double baseFrequency );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorVelocity( rlCommandListHandle handle, rlMotorAxis axis, double velocity );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorAcceleration( rlCommandListHandle handle, rlMotorAxis axis, double acceleration );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorHomingMethod( rlCommandListHandle handle, rlMotorAxis axis, rlHomingMethod homing );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorHomingFastSpeed( rlCommandListHandle handle, rlMotorAxis axis, double speed );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorHomingSlowSpeed( rlCommandListHandle handle, rlMotorAxis axis, double speed );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorHomingAcceleration( rlCommandListHandle handle, rlMotorAxis axis, double acceleration );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorOriginPosition( rlCommandListHandle handle, rlMotorAxis axis, double position );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorHomeOffset( rlCommandListHandle handle, rlMotorAxis axis, double offset );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorMoveAbs( rlCommandListHandle handle, rlMotorAxis axis, double target );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorMoveAbs2D( rlCommandListHandle handle, rlPoint2D* target );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorMoveAbs3D( rlCommandListHandle handle, rlPoint3D* target );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorMoveAbs4D( rlCommandListHandle handle, rlPoint4D* target );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorMoveRel( rlCommandListHandle handle, rlMotorAxis axis, double target );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorMoveRel2D( rlCommandListHandle handle, rlPoint2D* target );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorMoveRel3D( rlCommandListHandle handle, rlPoint3D* target );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendMotorMoveRel4D( rlCommandListHandle handle, rlPoint4D* target );

extern "C" DLLEXPORT rlResult __stdcall rlListAppendSerialPortTransmitString( rlCommandListHandle handle, const char* transmitMessage );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendSerialPortTransmitLine( rlCommandListHandle handle, const char* transmitMessage );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendSerialPortTransmitBytes( rlCommandListHandle handle, const std::uint8_t* transmitMessage, std::uint32_t transmitMessageLength );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendSerialPortVerifyResponseString( rlCommandListHandle handle, const char* transmitMessage, const char* goodResponse );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendSerialPortVerifyResponseLine( rlCommandListHandle handle, const char* transmitMessage, const char* goodResponse );
extern "C" DLLEXPORT rlResult __stdcall rlListAppendSerialPortVerifyResponseBytes( rlCommandListHandle handle, const std::uint8_t* transmitMessage, uint32_t transmitMessageLength, const std::uint8_t* goodResponse, uint32_t goodResponseLength );

#endif // _SPICE3_LIST_API_
