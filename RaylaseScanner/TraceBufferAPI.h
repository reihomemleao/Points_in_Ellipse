#ifndef _SPICE3_TRACEBUFFER_API_
#define _SPICE3_TRACEBUFFER_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlTraceBufferInitConfig( rlTraceBufferConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlTraceBufferSetConfig( rlHandle handle, const rlTraceBufferConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlTraceBufferGetConfig( rlHandle handle, rlTraceBufferConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlTraceBufferLoadConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlTraceBufferStoreConfig( rlHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlTraceBufferClearBuffer( rlHandle handle );

#endif // _SPICE3_TRACEBUFFER_API_