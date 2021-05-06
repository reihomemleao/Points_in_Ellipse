#include "rlTypes.h"

#ifndef _CORRECTION_FILE_H_
#define _CORRECTION_FILE_H_

typedef int64_t rlCFHandle;

extern "C" DLLEXPORT rlCFHandle __stdcall rlCFOpen( const char* fileName );
extern "C" DLLEXPORT rlCFHandle __stdcall rlCFCreate( const char* fileName, const rlOpticalParameters* param, char** correctionTables, uint32_t* correctionLen, uint32_t tableCount );

extern "C" DLLEXPORT rlResult __stdcall rlCFClose( rlCFHandle fileHandle );
extern "C" DLLEXPORT rlResult __stdcall rlCFGetOpticalParameters( rlCFHandle fileHandle, rlOpticalParameters* out );
extern "C" DLLEXPORT rlResult __stdcall rlCFTableReadByte( rlCFHandle fileHandle, char* buffer, uint32_t bufferLen, uint32_t offset, uint32_t count, std::uint32_t table );
extern "C" DLLEXPORT rlResult __stdcall rlCFTableReadUInt64( rlCFHandle fileHandle, uint64_t* buffer, uint32_t bufferLen, uint32_t offset, uint32_t count, std::uint32_t table );
extern "C" DLLEXPORT rlResult __stdcall rlCFGetTableLen( rlCFHandle fileHandle, std::uint32_t* outLen, std::uint32_t table );
extern "C" DLLEXPORT rlResult __stdcall rlCFGetTableCount( rlCFHandle fileHandle, std::uint32_t* outCount );

extern "C" DLLEXPORT void __stdcall rlCFGetLastError( char* buffer, int32_t bufferLen );
extern "C" DLLEXPORT int32_t __stdcall rlCFGetLastErrorLen();
#endif // _CORRECTION_FILE_H_
