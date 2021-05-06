#ifndef _SPICE3_FONT_API_
#define _SPICE3_FONT_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlFontHandle __stdcall rlFontGet( rlHandle handle, int32_t fontId );
extern "C" DLLEXPORT rlResult __stdcall rlFontSet( rlHandle handle, rlFontHandle fontHandle );
extern "C" DLLEXPORT rlResult __stdcall rlFontLoad( rlHandle handle, int32_t fontId );
extern "C" DLLEXPORT rlResult __stdcall rlFontStore( rlHandle handle, int32_t fontId );
extern "C" DLLEXPORT rlResult __stdcall rlFontDelete( rlHandle handle, int32_t fontId );
extern "C" DLLEXPORT rlResult __stdcall rlFontSetActive( rlHandle handle, int32_t fontId );

extern "C" DLLEXPORT rlFontHandle __stdcall rlFontAllocate( rlHandle handle, int32_t fontId );
extern "C" DLLEXPORT rlResult __stdcall rlFontAddChar( rlFontHandle handle, char c, rlCommandListHandle listHandle );
extern "C" DLLEXPORT rlResult __stdcall rlFontRemoveChar( rlFontHandle handle, char c );
extern "C" DLLEXPORT rlCommandListHandle __stdcall rlFontGetChar( rlFontHandle handle, char c );
extern "C" DLLEXPORT rlResult __stdcall rlFontClear( rlFontHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlFontChars( rlFontHandle handle, char* buffer, uint32_t bufferSize, uint32_t* charCount );
extern "C" DLLEXPORT rlResult __stdcall rlFontCharsLen( rlFontHandle handle, uint32_t* charCount );

extern "C" DLLEXPORT rlResult __stdcall rlFontReleaseHandle( rlFontHandle handle );

#endif // _SPICE3_FONT_API_