#ifndef _SPICE3_HEADCORRECTION_API_
#define _SPICE3_HEADCORRECTION_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlHeadCorrectionCreate( rlHandle handle, rlOpticalParameters op, int32_t head, int32_t correction );
extern "C" DLLEXPORT rlResult __stdcall rlHeadCorrectionGet( rlHandle handle, int32_t head, int32_t correction, const char* localFileName );
extern "C" DLLEXPORT rlResult __stdcall rlHeadCorrectionSet( rlHandle handle, int32_t head, int32_t correction, const char* localFileName );
extern "C" DLLEXPORT rlResult __stdcall rlHeadCorrectionSetGcd( rlHandle handle, int32_t head, int32_t correction, const char* localFileName );

extern "C" DLLEXPORT rlResult __stdcall rlHeadCorrectionLoad( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlHeadCorrectionStore( rlHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlHeadCorrectionInitOpticalParameters( rlOpticalParameters* parameters );
extern "C" DLLEXPORT rlResult __stdcall rlHeadCorrectionGetOpticalParameters( rlHandle handle, int32_t head, int32_t correction, rlOpticalParameters* parameters );

extern "C" DLLEXPORT rlResult __stdcall rlHeadCorrectionSelectCorrection( rlHandle handle, int32_t head, int32_t correction );
extern "C" DLLEXPORT rlResult __stdcall rlHeadCorrectionGetSelectedCorrection( rlHandle handle, int32_t head, int32_t* outSelectedCorrection );

#endif // _SPICE3_HEADCORRECTION_API_
