#ifdef _WIN32
#include <windows.h>
#endif
#include <time.h>
// Check if C99 is supported by the compiler so that stdint.h can be used. The MSC-compiler from VisualStudio 2010 or above does not
// support the full C99 standard but has stdint.h, same with embarcadero C++ compiler.
// stdint.h is needed to have integer types with a specified width defined.
// If your stdlib has stdint.h but your compiler does not support C99, you can define "STDINTSUPPORT" to be able to include this.
#if defined(__cplusplus ) && ( __cplusplus >= 201102L ) \
	|| ( defined( _MSC_VER ) && _MSC_VER >= 1600 )
#include <cstdint>
using namespace std;
#elif ( defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
	|| (defined(__CODEGEARC__) && __CODEGEARC__ >= 0x0640) \
	|| defined(STDINTSUPPORT)
#ifndef _CSTDINT_
#ifndef _STDINT
#include <stdint.h>
#define _STDINT
#define _CSTDINT_
#endif
#endif
#else
#error Error in rlAPI.h: "stdint.h" is needed, which is required by the C99 standard. If stdint.h exists but your compiler does not support C99, please define "STDINTSUPPORT"
#endif

#ifdef _WIN32
#ifdef COMPILING_DLL
//#define DLLEXPORT __declspec(dllexport)
#define DLLEXPORT
#else
#define DLLEXPORT __declspec(dllimport)
#endif // COMPILING_DLL
#else
#define DLLEXPORT
#define __stdcall
#endif // _WIN32
#ifndef _RL_API_H_
#define _RL_API_H_
#ifdef __cplusplus
extern "C"
{
#endif
extern const uint32_t rlMaxHostnameLen;
extern const uint32_t rlMaxFilenameLen;
extern const uint32_t rlMaxTextLen;
extern const uint32_t rlMaxListDocumentLen;

extern "C" DLLEXPORT void __stdcall rlGetLastError( char* buffer, int32_t bufferSize );
extern "C" DLLEXPORT int32_t __stdcall rlGetLastErrorLen( void );
#ifdef __cplusplus
}
#endif
#endif // _RL_API_H_
