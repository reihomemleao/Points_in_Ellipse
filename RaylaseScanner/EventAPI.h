#ifndef _SPICE3_EVENT_API_
#define _SPICE3_EVENT_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlEventInitConfig( rlEventConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlEventStoreConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlEventLoadConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlEventGetConfig( rlHandle handle, rlEventConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlEventSetConfig( rlHandle handle, const rlEventConfig* config );

#endif // _SPICE3_EVENT_API_