#ifndef _SPICE3_MOTF_API_
#define _SPICE3_MOTF_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlMotfQuadratureDecoderInitConfig( rlQuadratureDecoderConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlMotfQuadratureDecoderLoadConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlMotfQuadratureDecoderStoreConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlMotfQuadratureDecoderGetConfig( rlHandle handle, rlQuadratureDecoderConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlMotfQuadratureDecoderSetConfig( rlHandle handle, const rlQuadratureDecoderConfig* config );

extern "C" DLLEXPORT rlResult __stdcall rlMotfInitConfig( rlMotfConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlMotfGetConfig( rlHandle handle, rlMotfConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlMotfSetConfig( rlHandle handle, const rlMotfConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlMotfLoadConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlMotfStoreConfig( rlHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlMotfConfigSetDirectionFromAngle( rlMotfConfig* config, double angle );

// DEPRECATED, use QuadratureDecoderModule.SimulateDecoder instead.
//extern "C" DLLEXPORT rlResult __stdcall rlMotfIsEncoderSimulated( rlHandle handle, int32_t encoderID, bool* isSimulated );
// DEPRECATED, use QuadratureDecoderModule.SimulateDecoder instead.
//extern "C" DLLEXPORT rlResult __stdcall rlMotfSimulateEncoder( rlHandle handle, int32_t encoderID, bool simulate );
// DEPRECATED, use QuadratureDecoderModule.SimulateSimulationAcceleration instead.
//extern "C" DLLEXPORT rlResult __stdcall rlMotfGetSimulationAcceleration( rlHandle handle, int32_t encoderID, double* acceleration );
// DEPRECATED, use QuadratureDecoderModule.SimulateSimulationSpeed instead.
//extern "C" DLLEXPORT rlResult __stdcall rlMotfGetSimulationSpeed( rlHandle handle, int32_t encoderID, double* speed );
// DEPRECATED, use QuadratureDecoderModule.SimulateSimulationSpeed instead.
//extern "C" DLLEXPORT rlResult __stdcall rlMotfSetSimulationSpeed( rlHandle handle, int32_t encoderID, double speed, double acceleration );

extern "C" DLLEXPORT rlResult __stdcall rlMotfQuadratureDecoderResetEncoderPosition( rlHandle handle, int32_t encoderID );
extern "C" DLLEXPORT rlResult __stdcall rlMotfQuadratureDecoderReadEncoderPosition( rlHandle handle, int32_t encoderID, int32_t* position );

extern "C" DLLEXPORT rlResult __stdcall rlMotfResetState( rlHandle handle );

#endif // _SPICE3_MOTF_API_