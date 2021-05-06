#ifndef _SPICE3_PROCESS_API_
#define _SPICE3_PROCESS_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlProcessInitVariables( rlProcessVariables* variables );
extern "C" DLLEXPORT rlResult __stdcall rlProcessLoadVariables( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlProcessStoreVariables( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlProcessGetVariables( rlHandle handle, rlProcessVariables* variables );
extern "C" DLLEXPORT rlResult __stdcall rlProcessSetVariables( rlHandle handle, const rlProcessVariables* variables );

extern "C" DLLEXPORT rlResult __stdcall rlProcessGetSpeedScale( rlHandle handle, double* out );
extern "C" DLLEXPORT rlResult __stdcall rlProcessSetSpeedScale( rlHandle handle, double scale );

extern "C" DLLEXPORT rlResult __stdcall rlProcessWobbleSetCircle( rlHandle handle, rlProcessVariables* variables, double amplitude, double frequency );
extern "C" DLLEXPORT rlResult __stdcall rlProcessWobbleSetEight( rlHandle handle, rlProcessVariables* variables, const rlPoint2D* amplitude, double frequency );

#endif // _SPICE3_PROCESS_API_
