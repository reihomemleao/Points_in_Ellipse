#ifndef _SPICE3_SERIAL_PORT_API_
#define _SPICE3_SERIAL_PORT_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlSerialPortInitConfig( rlSerialPortConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlSerialPortLoadConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlSerialPortStoreConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlSerialPortGetConfig( rlHandle handle, rlSerialPortConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlSerialPortSetConfig( rlHandle handle, const rlSerialPortConfig* config );

extern "C" DLLEXPORT rlResult __stdcall rlSerialPortTransmitString( rlHandle handle, const char* transmitMessage, uint32_t transmitMessageLength );
extern "C" DLLEXPORT rlResult __stdcall rlSerialPortTransmitLine( rlHandle handle, const char* transmitMessage, uint32_t transmitMessageLength );
extern "C" DLLEXPORT rlResult __stdcall rlSerialPortTransmitBytes( rlHandle handle, const std::uint8_t* transmitMessage, std::uint32_t transmitMessageLength );

extern "C" DLLEXPORT rlResult __stdcall rlSerialPortVerifyResponseString( rlHandle handle, const char* transmitMessage, uint32_t transmitMessageLength, const char* goodResponse, uint32_t goodResponseLength, uint32_t* successFlag );
extern "C" DLLEXPORT rlResult __stdcall rlSerialPortVerifyResponseLine( rlHandle handle, const char* transmitMessage, uint32_t transmitMessageLength, const char* goodResponse, uint32_t goodResponseLength, uint32_t* successFlag );
extern "C" DLLEXPORT rlResult __stdcall rlSerialPortVerifyResponseBytes( rlHandle handle, const std::uint8_t* transmitMessage, uint32_t transmitMessageLength, const std::uint8_t* goodResponse, uint32_t goodResponseLength, uint32_t* successFlag );

extern "C" DLLEXPORT rlResult __stdcall rlSerialPortReceiveString( rlHandle handle, uint32_t readCount, char* outBuffer, uint32_t bufferLen, uint32_t* outLen );
extern "C" DLLEXPORT rlResult __stdcall rlSerialPortReceiveLine( rlHandle handle, char* outBuffer, uint32_t bufferLen, uint32_t* outLen );
extern "C" DLLEXPORT rlResult __stdcall rlSerialPortReceiveBytes( rlHandle handle, uint32_t readCount, uint8_t* outBuffer, uint32_t bufferLen, uint32_t* outLen );

#endif // _SPICE3_SERIAL_PORT_API_