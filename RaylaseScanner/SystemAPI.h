#ifndef _SPICE3_SYSTEM_API_
#define _SPICE3_SYSTEM_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlSystemInitConfig( rlSystemConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlSystemLoadConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlSystemStoreConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlSystemGetConfig( rlHandle handle, rlSystemConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlSystemSetConfig( rlHandle handle, const rlSystemConfig* config );

extern "C" DLLEXPORT rlResult __stdcall rlSystemGetFirmwareVersion( rlHandle handle, char* buffer, uint32_t bufferSize, uint32_t* stringLength );
extern "C" DLLEXPORT rlResult __stdcall rlSystemGetFirmwareProductVersion( rlHandle handle, char* buffer, uint32_t bufferSize, uint32_t* stringLength );
extern "C" DLLEXPORT rlResult __stdcall rlSystemGetFPGAVersion( rlHandle handle, char* buffer, uint32_t bufferSize, uint32_t* stringLength );
extern "C" DLLEXPORT rlResult __stdcall rlSystemGetOSVersion( rlHandle handle, char* buffer, uint32_t bufferSize, uint32_t* stringLength );
extern "C" DLLEXPORT rlResult __stdcall rlSystemGetCardSerialNumber( rlHandle handle, char* buffer, uint32_t bufferSize, uint32_t* stringLength );

extern "C" DLLEXPORT rlResult __stdcall rlSystemGetConnectionLimit( rlHandle handle, int32_t* out );
extern "C" DLLEXPORT rlResult __stdcall rlSystemGetUniversalTime( rlHandle handle, time_t* out );
extern "C" DLLEXPORT rlResult __stdcall rlSystemGetTime( rlHandle handle, time_t* out );
extern "C" DLLEXPORT rlResult __stdcall rlSystemSetSystemTime( rlHandle handle, time_t time );

extern "C" DLLEXPORT rlResult __stdcall rlSystemGetSupportedTimeZones( rlHandle handle, rlTimeZone* buffer, uint32_t bufferSize, uint32_t* outCount );

extern "C" DLLEXPORT rlResult __stdcall rlSystemResetToDefaults( rlHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlSystemResetOperatingState( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlSystemGetOperatingState( rlHandle handle, rlOperatingState* result );
#endif // _SPICE3_SYSTEM_API_
