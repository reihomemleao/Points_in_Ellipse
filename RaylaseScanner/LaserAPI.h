#ifndef _SPICE3_LASER_API_
#define _SPICE3_LASER_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlLaserInitConfig( rlLaserConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlLaserLoadConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlLaserStoreConfig( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlLaserGetConfig( rlHandle handle, rlLaserConfig* config );
extern "C" DLLEXPORT rlResult __stdcall rlLaserSetConfig( rlHandle handle, const rlLaserConfig* config );

extern "C" DLLEXPORT rlResult __stdcall rlLaserCreatePowerCalibration( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlLaserLoadPowerCalibration( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlLaserStorePowerCalibration( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlLaserGetPowerCalibration( rlHandle handle, uint32_t* buffer, int32_t bufferSize, int32_t* calibrationValuesCount );
extern "C" DLLEXPORT rlResult __stdcall rlLaserSetPowerCalibration( rlHandle handle, const uint32_t* calibrationValues, int32_t calibrationValuesLength );
extern "C" DLLEXPORT rlResult __stdcall rlLaserPowerCalibrationSet( rlHandle handle, const char* localFileName );
extern "C" DLLEXPORT rlResult __stdcall rlLaserPowerCalibrationGet( rlHandle handle, const char* localFileName );

extern "C" DLLEXPORT rlResult __stdcall rlLaserIsPilotEnabled( rlHandle handle, bool* enabled );
extern "C" DLLEXPORT rlResult __stdcall rlLaserEnablePilot( rlHandle handle, bool enable );

extern "C" DLLEXPORT rlResult __stdcall rlLaserIsLaserArmed( rlHandle handle, bool* armed );
extern "C" DLLEXPORT rlResult __stdcall rlLaserArmLaser( rlHandle handle, bool arm );

extern "C" DLLEXPORT rlResult __stdcall rlLaserReadLaserStatus( rlHandle handle, rlLaserStatus* laserStatus );

extern "C" DLLEXPORT rlResult __stdcall rlLaserGetPowerScale( rlHandle handle, double* out );
extern "C" DLLEXPORT rlResult __stdcall rlLaserSetPowerScale( rlHandle handle, double scale );

extern "C" DLLEXPORT rlResult __stdcall rlLaserLaserOn( rlHandle handle );
extern "C" DLLEXPORT rlResult __stdcall rlLaserLaserOff( rlHandle handle );

#endif // _SPICE3_LASER_API_
