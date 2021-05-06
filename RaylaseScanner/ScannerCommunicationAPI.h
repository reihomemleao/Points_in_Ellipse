#ifndef _SPICE3_SCANNERCOMMUNICATION_API_
#define _SPICE3_SCANNERCOMMUNICATION_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall	rlScannerCommunicationTransceiveEnhanced( rlHandle handle, int32_t head, rlAxes axes, const uint32_t* commands, uint32_t commandsLength, int32_t timeoutMilliseconds, uint32_t* buffer, uint32_t bufferSize, uint32_t* receiveCount );
extern "C" DLLEXPORT rlResult __stdcall	rlScannerCommunicationTransmitEnhanced( rlHandle handle, int32_t head, rlAxes axes, const uint32_t* commands, uint32_t commandsLength, int32_t timeoutMilliseconds );
extern "C" DLLEXPORT rlResult __stdcall	rlScannerCommunicationReceiveEnhanced( rlHandle handle, int32_t head, rlAxes axes, int32_t timeoutMilliseconds, uint32_t* buffer, uint32_t bufferSize, uint32_t* receiveCount );
extern "C" DLLEXPORT rlResult __stdcall	rlScannerCommunicationTransceiveRaylase( rlHandle handle, int32_t head, rlAxis axis, const unsigned char* transmitMessage, uint32_t transmitMessageLength, int32_t timeoutMilliseconds, unsigned char* buffer, uint32_t bufferSize, uint32_t* receiveCount );
extern "C" DLLEXPORT rlResult __stdcall	rlScannerCommunicationTransmitRaylase( rlHandle handle, int32_t head, rlAxis axis, const unsigned char* transmitMessage, uint32_t transmitMessageLength, int32_t timeoutMilliseconds );

#endif // _SPICE3_SCANNERCOMMUNICATION_API_