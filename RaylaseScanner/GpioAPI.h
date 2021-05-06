#ifndef _SPICE3_GPIO_API_
#define _SPICE3_GPIO_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlGpioInitConfig( rlGpioConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlGpioLoadConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlGpioStoreConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlGpioGetConfig( rlHandle handle, rlGpioConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlGpioSetConfig( rlHandle handle, const rlGpioConfig* config );

extern "C" DLLEXPORT rlResult __stdcall rlGpioGetPinCount( rlHandle handle, rlIOPort port, int32_t* pinCount );
extern "C" DLLEXPORT rlResult __stdcall rlGpioGetGroupCount( rlHandle handle, rlIOPort port, int32_t* groupCount );
extern "C" DLLEXPORT rlResult __stdcall rlGpioGetSupportedIOLevels( rlHandle handle, rlIOPort port, rlIOVoltage* ioLevels, uint32_t ioLevelsSize, uint32_t* ioLevelsCount );
extern "C" DLLEXPORT rlResult __stdcall rlGpioGetSupportedDirections( rlHandle handle, rlIOPort port, rlIODirection* directions, uint32_t directionsSize, uint32_t* directionsCount );
extern "C" DLLEXPORT rlResult __stdcall rlGpioGetAvailableIOPinMappingList( rlHandle handle, rlIOPinMapping* pinMappings, uint32_t pinMappingsSize, uint32_t* pinMappingsCount );

extern "C" DLLEXPORT rlResult __stdcall rlGpioGetIOLevel( rlHandle handle, rlIOPort port, rlIOVoltage* ioLevel );
extern "C" DLLEXPORT rlResult __stdcall rlGpioSetIOLevel( rlHandle handle, rlIOPort port, rlIOVoltage ioLevel );

extern "C" DLLEXPORT rlResult __stdcall rlGpioGetPolarities( rlHandle handle, rlIOPort port, rlPolarity* polarities, uint32_t polaritiesSize, uint32_t* polaritiesCount );
extern "C" DLLEXPORT rlResult __stdcall rlGpioSetPolarities( rlHandle handle, rlIOPort port, const rlPolarity* polarities, uint32_t polaritiesLength );

extern "C" DLLEXPORT rlResult __stdcall rlGpioGetFunctions( rlHandle handle, rlIOPort port, int32_t* functions, uint32_t functionsSize, uint32_t* functionsCount );
extern "C" DLLEXPORT rlResult __stdcall rlGpioSetFunctions( rlHandle handle, rlIOPort port, const int32_t* functions, uint32_t functionsLength );

extern "C" DLLEXPORT rlResult __stdcall rlGpioGetDirections( rlHandle handle, rlIOPort port, rlIODirection* directions, uint32_t directionsSize, uint32_t* directionsCount );
extern "C" DLLEXPORT rlResult __stdcall rlGpioSetDirections( rlHandle handle, rlIOPort port, const rlIODirection* directions, uint32_t directionsLength );

extern "C" DLLEXPORT rlResult __stdcall rlGpioGetWriteDelay( rlHandle handle, rlIOPort port, double* delay );
extern "C" DLLEXPORT rlResult __stdcall rlGpioSetWriteDelay( rlHandle handle, rlIOPort port, double delay );
extern "C" DLLEXPORT rlResult __stdcall rlGpioGetWriteWidth( rlHandle handle, rlIOPort port, double* width );
extern "C" DLLEXPORT rlResult __stdcall rlGpioSetWriteWidth( rlHandle handle, rlIOPort port, double width );

extern "C" DLLEXPORT rlResult __stdcall rlGpioRead( rlHandle handle, rlIOPort port, uint32_t* value );
extern "C" DLLEXPORT rlResult __stdcall rlGpioGetOutput( rlHandle handle, rlIOPort port, uint32_t* value );
extern "C" DLLEXPORT rlResult __stdcall rlGpioWrite( rlHandle handle, rlIOPort port, rlPinAction action, uint32_t value );

#endif // _SPICE3_GPIO_API_