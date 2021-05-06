#ifndef _SPICE3_SPI_API_
#define _SPICE3_SPI_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlSfioRead( rlHandle handle, rlSfRegister reg, uint32_t* value );

extern "C" DLLEXPORT rlResult __stdcall rlSfioSpiInitConfig( rlSpiConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlSfioSpiLoadConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlSfioSpiStoreConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlSfioSpiGetConfig( rlHandle handle, rlSpiConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlSfioSpiSetConfig( rlHandle handle, const rlSpiConfig* config );

extern "C" DLLEXPORT rlResult __stdcall rlSfioSpiTransmit( rlHandle handle, int32_t module, const uint32_t* transmitMessage, uint32_t transmitMessageLength, bool async );
extern "C" DLLEXPORT rlResult __stdcall rlSfioSpiTransceive( rlHandle handle, int32_t module, const uint32_t* transmitMessage, uint32_t transmitMessageLength, int32_t timeoutMs, uint32_t* buffer, uint32_t bufferSize, uint32_t* receiveCount );
extern "C" DLLEXPORT rlResult __stdcall rlSfioSpiReceive( rlHandle handle, int32_t module, uint32_t readCount, int32_t timeoutMs, uint32_t* buffer, uint32_t bufferSize, uint32_t* receiveCount );

extern "C" DLLEXPORT rlResult __stdcall rlSfioSpiWaitForActiveTransfersDone( rlHandle handle, int32_t module );

#endif // _SPICE3_SPI_API_
