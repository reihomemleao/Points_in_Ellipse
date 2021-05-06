#ifndef _SPICE3_SCANNER_API_
#define _SPICE3_SCANNER_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlScannerInitConfig( rlScannerConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlScannerGetAxisParameterSet( const rlScannerConfig* config, int32_t head, rlAxis axis, rlAxisParameterSet* out );
extern "C" DLLEXPORT rlResult __stdcall rlScannerSetConfig( rlHandle handle, const rlScannerConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlScannerGetConfig( rlHandle handle, rlScannerConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlScannerLoadConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlScannerStoreConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall	rlScannerGetNominalPosition( rlHandle handle, double* x, double* y, double* z );
extern "C" DLLEXPORT rlResult __stdcall	rlScannerReadPositions( rlHandle handle, rlPositions* positions );
extern "C" DLLEXPORT rlResult __stdcall	rlScannerReadLastPositions( rlHandle handle, rlPositions* positions );

extern "C" DLLEXPORT rlResult __stdcall	rlScannerHeadFormatGetHeadCount( rlScanHeadFormat headFormat, int32_t* out );
extern "C" DLLEXPORT rlResult __stdcall	rlScannerHeadFormatGetAxisCount( rlScanHeadFormat headFormat, int32_t* out );
extern "C" DLLEXPORT rlResult __stdcall	rlScannerHeadFormatGetDimensions( rlScanHeadFormat headFormat, int32_t* out );
extern "C" DLLEXPORT rlResult __stdcall	rlScannerHeadFormatGetAxes( rlScanHeadFormat headFormat, rlAxes* out );
extern "C" DLLEXPORT rlResult __stdcall	rlScannerHeadFormatHasOpticalZoom( rlScanHeadFormat headFormat, bool* out );
extern "C" DLLEXPORT rlResult __stdcall	rlScannerHeadFormatIsExtended( rlScanHeadFormat headFormat, bool* out );

#endif // _SPICE3_SCANNER_API_