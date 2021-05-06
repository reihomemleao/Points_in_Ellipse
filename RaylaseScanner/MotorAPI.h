#ifndef _SPICE3_MOTOR_API_
#define _SPICE3_MOTOR_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlMotorInitConfig( rlMotorConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlMotorGetConfig( rlHandle handle, rlMotorConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlMotorGetAxisParameterSet( const rlMotorConfig* config, rlMotorAxis axis, rlMotorAxisParameterSet* out );
extern "C" DLLEXPORT rlResult __stdcall rlMotorSetConfig( rlHandle handle, const rlMotorConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlMotorLoadConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlMotorStoreConfig( rlHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlMotorInitVariables( rlMotorVariables* config );
extern "C" DLLEXPORT rlResult __stdcall rlMotorGetVariables( rlHandle handle, rlMotorVariables* config );
extern "C" DLLEXPORT rlResult __stdcall rlMotorSetVariables( rlHandle handle, const rlMotorVariables* config );
extern "C" DLLEXPORT rlResult __stdcall rlMotorLoadVariables( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlMotorStoreVariables( rlHandle handle );

extern "C" DLLEXPORT rlResult __stdcall	rlMotorReadPosition( rlHandle handle, rlMotorAxis axis, double* out );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorIsWithinSoftLimits( rlHandle handle, rlMotorAxis axis, bool* out );

extern "C" DLLEXPORT rlResult __stdcall	rlMotorHasAlarm( rlHandle handle, rlMotorAxis axis, bool* out );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorHaveAlarm( rlHandle handle, rlMotorAxes axes, bool* out, uint32_t outSize );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorClearAlarm( rlHandle handle, rlMotorAxis axis );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorClearAlarm2( rlHandle handle, rlMotorAxes axes );

extern "C" DLLEXPORT rlResult __stdcall	rlMotorIsHomed( rlHandle handle, rlMotorAxis axis, bool* out );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorAreHomed( rlHandle handle, rlMotorAxes axes, bool* out, uint32_t outSize );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorClearHome( rlHandle handle, rlMotorAxis axis );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorClearHome2( rlHandle handle, rlMotorAxes axes );
extern "C" DLLEXPORT rlResult __stdcall rlMotorHome( rlHandle handle, rlMotorAxis axis, rlHomeInput input, double maxDistance, bool async, bool positionToZero, double* out );

extern "C" DLLEXPORT rlResult __stdcall	rlMotorIsMoving( rlHandle handle, rlMotorAxis axis, bool* out );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorAreMoving( rlHandle handle, rlMotorAxes axes, bool* out, uint32_t outSize );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorMovingDirection( rlHandle handle, rlMotorAxis axis, rlMovingDirection* out );

extern "C" DLLEXPORT rlResult __stdcall	rlMotorMoveAbs( rlHandle handle, rlMotorAxis axis, double target );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorMoveAbs2D( rlHandle handle, const rlPoint2D* target );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorMoveAbs3D( rlHandle handle, const rlPoint3D* target );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorMoveAbs4D( rlHandle handle, const rlPoint4D* target );

extern "C" DLLEXPORT rlResult __stdcall	rlMotorMoveRel( rlHandle handle, rlMotorAxis axis, double target );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorMoveRel2D( rlHandle handle, const rlPoint2D* target );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorMoveRel3D( rlHandle handle, const rlPoint3D* target );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorMoveRel4D( rlHandle handle, const rlPoint4D* target );

extern "C" DLLEXPORT rlResult __stdcall	rlMotorMoveAtVelocity( rlHandle handle, rlMotorAxis axis );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorStop( rlHandle handle, rlMotorAxis axis );
extern "C" DLLEXPORT rlResult __stdcall	rlMotorStop2( rlHandle handle, rlMotorAxes axes );

extern "C" DLLEXPORT rlResult __stdcall rlMotorWaitForHomeDone( rlHandle handle, int32_t timeoutMs, bool* successBeforeTimeout, rlMotorAxis* out );
extern "C" DLLEXPORT rlResult __stdcall rlMotorInterruptWaitForHomeDone( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlMotorWaitForMoveDone( rlHandle handle, int32_t timeoutMs, bool* successBeforeTimeout, rlMotorAxis* out );
extern "C" DLLEXPORT rlResult __stdcall rlMotorWaitForMoveDone2( rlHandle handle, rlMotorAxes axes, int32_t timeoutMs, bool* successBeforeTimeout );
extern "C" DLLEXPORT rlResult __stdcall rlMotorInterruptWaitForMoveDone( rlHandle handle );
extern "C" DLLEXPORT rlCallbackHandle __stdcall rlMotorRegisterHomeDoneCallback( rlHandle handle, rlHomeDoneCallback func );
extern "C" DLLEXPORT rlResult __stdcall rlMotorUnRegisterHomeDoneCallback( rlCallbackHandle handle );
extern "C" DLLEXPORT rlCallbackHandle __stdcall rlMotorRegisterMoveDoneCallback( rlHandle handle, rlMoveDoneCallback func );
extern "C" DLLEXPORT rlResult __stdcall rlMotorUnRegisterMoveDoneCallback( rlCallbackHandle handle );

#endif // _SPICE3_MOTOR_API_