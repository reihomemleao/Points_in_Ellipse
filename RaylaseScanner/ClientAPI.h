/***********************************************************************************************
 * Only this header-file has to be included in your application to use the RAYLASE SP-ICE-3 API.
 * Everything is included from this file.
 ***********************************************************************************************/
#ifndef _SPICE3_CLIENT_API_
#define _SPICE3_CLIENT_API_

 /* Global defines and types used in the SPICE3 API */
#include "rlTypes.h"

/* All headers containing the API function calls are included here */
#include "FontAPI.h"
#include "GpioAPI.h"
#include "LaserAPI.h"
#include "ListAPI.h"
#include "EventAPI.h"
#include "MotFAPI.h"
#include "MotorAPI.h"
#include "ProcessAPI.h"
#include "VariableAPI.h"
#include "HeadCorrectionAPI.h"
#include "PowerCorrectionAPI.h"
#include "ScannerAPI.h"
#include "ScannerCommunicationAPI.h"
#include "SystemAPI.h"
#include "SfioAPI.h"
#include "SerialPortAPI.h"
#include "TraceBufferAPI.h"
#include "InternalAPI.h"

extern "C" DLLEXPORT rlHandle __stdcall rlConnect( const char* hostNameOrAddress, int32_t port );
extern "C" DLLEXPORT rlHandle __stdcall rlConnectByCardInfo( const rlCardInfo* card );
extern "C" DLLEXPORT rlResult __stdcall rlIsConnected( rlHandle handle, bool* isConnected );
extern "C" DLLEXPORT rlResult __stdcall rlDisconnect( rlHandle connection );
extern "C" DLLEXPORT rlResult __stdcall rlDiscover( rlCardInfo* discoveredCards, uint32_t discoveredCardsSize, uint32_t* discoveredCardsCount );
extern "C" DLLEXPORT rlResult __stdcall rlDiscoverByPinging( int32_t fromSerialNumber, int32_t toSerialNumber, rlCardInfo* discoveredCards, uint32_t discoveredCardsSize, uint32_t* discoveredCardsCount );
extern "C" DLLEXPORT rlResult __stdcall rlEnableCommandLogging( rlHandle handle, const char* path, std::int32_t truncateArgumentsAfter );
extern "C" DLLEXPORT rlResult __stdcall rlDisableCommandLogging( rlHandle handle );

#endif // _SPICE3_CLIENT_API_
