#ifndef _SPICE3_POWERCORRECTION_API_
#define _SPICE3_POWERCORRECTION_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlPowerCorrectionCreate( rlHandle handle, const rlOpticalParameters* parameters );
extern "C" DLLEXPORT rlResult __stdcall rlPowerCorrectionSet( rlHandle handle, const char* localFileName );
extern "C" DLLEXPORT rlResult __stdcall rlPowerCorrectionGet( rlHandle handle, const char* localFileName );
extern "C" DLLEXPORT rlResult __stdcall rlPowerCorrectionLoad( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlPowerCorrectionStore( rlHandle handle );

extern "C" DLLEXPORT rlResult __stdcall rlPowerCorrectionChangeValue( rlHandle handle, rlPoint3D position, double factor );

extern "C" DLLEXPORT rlResult __stdcall rlPowerCorrectionGetOpticalParameters( rlHandle handle, rlOpticalParameters* parameters );

#endif // _SPICE3_POWERCORRECTION_API_
