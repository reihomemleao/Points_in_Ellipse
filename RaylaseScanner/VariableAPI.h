#ifndef _SPICE3_VARIABLE_API_
#define _SPICE3_VARIABLE_API_

#include "rlTypes.h"

extern "C" DLLEXPORT rlResult __stdcall rlVariableBooleanCreate( rlHandle handle, const char* name, bool initialValue );
extern "C" DLLEXPORT rlResult __stdcall rlVariableBooleanDelete( rlHandle handle, const char* name, bool fromDisk );
extern "C" DLLEXPORT rlResult __stdcall rlVariableBooleanLoad( rlHandle handle, const char* name );
extern "C" DLLEXPORT rlResult __stdcall rlVariableBooleanStore( rlHandle handle, const char* name );

extern "C" DLLEXPORT rlResult __stdcall rlVariableBooleanGetValue( rlHandle handle, const char* name, bool* value );
extern "C" DLLEXPORT rlResult __stdcall rlVariableBooleanSetValue( rlHandle handle, const char* name, bool value );
extern "C" DLLEXPORT rlResult __stdcall rlVariableBooleanToggleValue( rlHandle handle, const char* name );

extern "C" DLLEXPORT rlResult __stdcall rlVariableIntegerCreate( rlHandle handle, const char* name, int32_t initialValue );
extern "C" DLLEXPORT rlResult __stdcall rlVariableIntegerDelete( rlHandle handle, const char* name, bool fromDisk );
extern "C" DLLEXPORT rlResult __stdcall rlVariableIntegerLoad( rlHandle handle, const char* name );
extern "C" DLLEXPORT rlResult __stdcall rlVariableIntegerStore( rlHandle handle, const char* name );

extern "C" DLLEXPORT rlResult __stdcall rlVariableIntegerGetValue( rlHandle handle, const char* name, int32_t* value );
extern "C" DLLEXPORT rlResult __stdcall rlVariableIntegerSetValue( rlHandle handle, const char* name, int32_t value );
extern "C" DLLEXPORT rlResult __stdcall rlVariableIntegerIncrementValue( rlHandle handle, const char* name );
extern "C" DLLEXPORT rlResult __stdcall rlVariableIntegerDecrementValue( rlHandle handle, const char* name );

extern "C" DLLEXPORT rlResult __stdcall rlVariableMarkCounterCreate( rlHandle handle, const char* name, int32_t initialValue );
extern "C" DLLEXPORT rlResult __stdcall rlVariableMarkCounterDelete( rlHandle handle, const char* name, bool fromDisk );
extern "C" DLLEXPORT rlResult __stdcall rlVariableMarkCounterLoad( rlHandle handle, const char* name );
extern "C" DLLEXPORT rlResult __stdcall rlVariableMarkCounterStore( rlHandle handle, const char* name );

extern "C" DLLEXPORT rlResult __stdcall rlVariableMarkCounterGetValue( rlHandle handle, const char* name, int32_t* value );
extern "C" DLLEXPORT rlResult __stdcall rlVariableMarkCounterSetValue( rlHandle handle, const char* name, int32_t value );
extern "C" DLLEXPORT rlResult __stdcall rlVariableMarkCounterGetAndResetValue( rlHandle handle, const char* name, int32_t* value );

extern "C" DLLEXPORT rlResult __stdcall rlVariableMarkCounterGetMarkTimeFormat( rlHandle handle, char* buffer, uint32_t bufferSize, uint32_t* stringLength );
extern "C" DLLEXPORT rlResult __stdcall rlVariableMarkCounterSetMarkTimeFormat( rlHandle handle, const char* format );

#endif // _SPICE3_VARIABLE_API_
