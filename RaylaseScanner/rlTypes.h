#include "rlAPI.h"

#ifndef _RL_TYPES_H_
#define _RL_TYPES_H_

#define rlSNMAXLEN 40
#define rlIPMAXLEN 60
#define rlTIMEZONEMAXLEN 128

#define rlMAXSCANHEADS 2
#define rlSPIModuleCount 4
#define rlQuadratureDecoderModuleCount 2

#define rlMaxSupportedMotorAxes 4

#define rlMAXONOFFPATTERNLEN 128

#define rlCORRECTIONHASHLEN 128

#define rlNEWLINEMAXLEN 128

typedef enum
{
	rlERROR = -1,
	rlSUCCESS = 0
} rlResult;

typedef int32_t rlHandle;
typedef int64_t rlFontHandle;
typedef int64_t rlCommandListHandle;
typedef int64_t rlCallbackHandle;
#define rlInvalidHandle rlERROR

typedef enum
{
	lsNotExisting = 0,
	lsIdle = 1,
	lsInExecutionQueue = 2,
	lsProcessing = 3
}rlListStatus;

typedef enum
{
	lsNone = 0,
	lsPilot = 1,
	lsArmed = 2,
	lsAlarm = 4,
}rlLaserStatus;

typedef enum
{
	plActiveHigh = 0,
	plActiveLow = 1
}rlPolarity;

typedef enum
{
	etListDone = 1 << 0,
	etListIdle = 1 << 1,
	etListIdleAtLimit = 1 << 21
}rlEventType;

typedef enum
{
	ioPortA = 0,
	ioPortB = 1,
	ioPortC = 2,
	ioPortD = 3,
	ioPortE = 4,
	ioLaserIn = 11,
	ioLaserOut = 12,
}rlIOPort;

typedef enum
{
	ioNone = 0,
	ioZero = 1,
	ioThreePointThree = 2,
	ioFive = 3
}rlIOVoltage;

typedef enum
{
	ioInput = 0,
	ioOutput = 1,
}rlIODirection;

typedef enum
{
	Sfr0 = 0,
	Sfr1 = 1,
	Sfr2 = 2,
	Sfr3 = 3,
} rlSfRegister;

typedef enum
{
	sfr0None = 0,
	sfr0StartMark = 1 << 0,
	sfr0AbortMark = 1 << 1,
	sfr0PartSensor = 1 << 2,
	sfr0LaserAlarm = 1 << 7,
	sfr0StartMarkAsserted = sfr0StartMark << 8,
	sfr0AbortMarkAsserted = sfr0AbortMark << 8,
	sfr0PartSensorAsserted = sfr0PartSensor << 8,
	sfr0LaserAlarmAsserted = sfr0LaserAlarm << 8,
	sfr0StartMarkDeasserted = sfr0StartMark << 16,
	sfr0AbortMarkDeasserted = sfr0AbortMark << 16,
	sfr0PartSensorDeasserted = sfr0PartSensor << 16,
	sfr0LaserAlarmDeasserted = sfr0LaserAlarm << 16,
}rlSfr0Bits;

typedef enum
{
	sfr1None = 0,
	sfr1QA0 = 0x0100,
	sfr1QB0 = 0x0200,
	sfr1Index0 = 0x0400,
	sfr1QA1 = 0x1000,
	sfr1QB1 = 0x2000,
	sfr1Index1 = 0x4000,
	sfr1PartSensor = 0x10000,
}rlSfr1Bits;

typedef enum
{
	sfr2None = 0,
	sfr2Home0 = 1 << 0,
	sfr2Home1 = 1 << 1,
	sfr2Home2 = 1 << 2,
	sfr2Home3 = 1 << 3,

	sfr2Home0Rise = sfr2Home0 << 8,
	sfr2Home1Rise = sfr2Home1 << 8,
	sfr2Home2Rise = sfr2Home2 << 8,
	sfr2Home3Rise = sfr2Home3 << 8,

	sfr2Home0Fall = sfr2Home0 << 16,
	sfr2Home1Fall = sfr2Home1 << 16,
	sfr2Home2Fall = sfr2Home2 << 16,
	sfr2Home3Fall = sfr2Home3 << 16,
}rlSfr2Bits;

typedef enum
{
	sfr3None = 0,
	sfr3Limit0_0 = 1 << 0,
	sfr3Limit1_0 = 1 << 1,
	sfr3Limit2_0 = 1 << 2,
	sfr3Limit3_0 = 1 << 3,
	sfr3Limit0_1 = 1 << 4,
	sfr3Limit1_1 = 1 << 5,
	sfr3Limit2_1 = 1 << 6,
	sfr3Limit3_1 = 1 << 7,

	sfr3Limit0_0Rise = sfr3Limit0_0 << 8,
	sfr3Limit1_0Rise = sfr3Limit1_0 << 8,
	sfr3Limit2_0Rise = sfr3Limit2_0 << 8,
	sfr3Limit3_0Rise = sfr3Limit3_0 << 8,
	sfr3Limit0_1Rise = sfr3Limit0_1 << 8,
	sfr3Limit1_1Rise = sfr3Limit1_1 << 8,
	sfr3Limit2_1Rise = sfr3Limit2_1 << 8,
	sfr3Limit3_1Rise = sfr3Limit3_1 << 8,

	sfr3Limit0_0Fall = sfr3Limit0_0 << 16,
	sfr3Limit1_0Fall = sfr3Limit1_0 << 16,
	sfr3Limit2_0Fall = sfr3Limit2_0 << 16,
	sfr3Limit3_0Fall = sfr3Limit3_0 << 16,
	sfr3Limit0_1Fall = sfr3Limit0_1 << 16,
	sfr3Limit1_1Fall = sfr3Limit1_1 << 16,
	sfr3Limit2_1Fall = sfr3Limit2_1 << 16,
	sfr3Limit3_1Fall = sfr3Limit3_1 << 16,
}rlSfr3Bits;

typedef enum
{
	dsBINFILES = 0,
	dsCORRFILES = 1,
	dsJOBFILES = 2,
	dsLISTFILES = 3,
	dsPROCVARFILES = 4
}rlDirectorySelector;

typedef enum
{
	ptNone = 0,
	ptDac0 = 1,
	ptDac1 = 2,
	ptDigital1Bit = 3,
	ptDigital2Bit = 4,
	ptDigital8Bit = 5,
	ptDigital16Bit = 6,
	ptLmFrequency = 11,
	ptLmWidth = 12
}rlPowerTarget;

typedef enum
{
	L1 = -1,
	L2 = 0,
	L3 = 1,
	L5 = 2,
	L9 = 3,
	L17 = 4,
	L33 = 5,
	L65 = 6,
	L129 = 7,
	L257 = 8
}rlLayers;

typedef enum
{
	aiX = 0,
	aiY = 1,
	aiZ = 2,
	aiZoom = 3,
	aiSensorZ = 5
}rlAxis;

typedef enum
{
	axNone = 0x00,
	axX = 0x01,
	axY = 0x02,
	axZ = 0x04,
	axZoom = 0x08,
	axSensorZ = 0x20,
	axXY = axX | axY,         // for convenience when working with 2D
	axXYZ = axX | axY | axZ
}rlAxes;

typedef enum
{
	maIllegalValue = -1,
	maM0 = 0,
	maM1 = 1,
	maM2 = 2,
	maM3 = 3,
	maCoordinated = 30
}rlMotorAxis;

typedef enum
{
	mxNone = 0x00,
	mxM0 = 1 << maM0,
	mxM1 = 1 << maM1,
	mxM2 = 1 << maM2,
	mxM3 = 1 << maM3,
	mxAll = mxM0 | mxM1 | mxM2 | mxM3,
	mxCoordinated = 1 << maCoordinated
}rlMotorAxes;

typedef enum
{
	NotMoving = 0,
	Positive = 1,
	Negative = 2,
}rlMovingDirection;

typedef enum
{
	hmCurrentPosition = 0,
	hmMinimumLimit = 1,
	hmMaximumLimit = 2,
	hmMinimumHome = 3,
	hmMaximumHome = 4
}rlHomingMethod;

typedef enum
{
	lmNone = 0x0,
	lmMinimum = 0x1,
	lmMaximum = 0x2,
	lmBoth = ( 0x1 | 0x2 )
}rlLimit;

typedef enum
{
	hiNone = -1,
	hiHome = 0,
	hiLimit0 = 1,
	hiLimit1 = 2
}rlHomeInput;

typedef enum
{
	shfXY2_100 = 0,

	shfSL2_Single3D = 1,
	shfSL2_Single3DX = 1 | ( 1 << 5 ),
	shfSL2_Single4D = 1 | ( 1 << 6 ),
	shfSL2_Single4DX = 1 | ( 1 << 5 ) | ( 1 << 6 ),
	shfSL2_Dual2D = 1 | ( 1 << 3 ),

	shfRL3_Single3D = 2,
	shfRL3_Single3DX = 2 | ( 1 << 5 ),
	shfRL3_Single4D = 2 | ( 1 << 6 ),
	shfRL3_Single4DX = 2 | ( 1 << 5 ) | ( 1 << 6 ),
	shfRL3_Dual3D = 2 | ( 1 << 3 )
}rlScanHeadFormat;

typedef enum
{
	paClear = 0,
	paToggle = 1,
	paSet = 2,
	paWrite = 3
}rlPinAction;

typedef enum
{
	setDataMode = 0x05000,
	updatePermanateMemory = 0x0A000,
	selectTuning = 0x11000,
	setPositionScaleFactor = 0x12000,
	setPosAcknowledgeLevel = 0x15000,
	dataModeStorage = 0x17000,
	setEchoMode = 0x21000
}rlEPCommandCode;

typedef enum
{
	statusWord = 0x00000,
	currentPosition = 0x00010,
	targetPosition = 0x00020,
	positionError = 0x00030,
	outputCurrent = 0x00040,
	relativeOutputCurrent = 0x00050,
	currentVelocity = 0x00060,
	galvoTemperature = 0x00140,
	servoBoardTemperature = 0x00150,
	pdAGCVoltage = 0x00160,
	dspCoreVoltage = 0x00170,
	dspIOVoltage = 0x00180,
	analogSupplyVoltage = 0x00190,
	adcSupplyVoltage = 0x001A0,
	pdAGCCurrent = 0x001B0,
	relativeHeatingOutput = 0x001D0,
	serialNumberLow = 0x001E0,
	serialNumberHigh = 0x001F0,
	articleNumberLow = 0x00200,
	articleNumberHigh = 0x00210,
	firmwareVersion = 0x00220,
	calibrationFactor = 0x00230,
	aperture = 0x00240,
	wavelength = 0x00250,
	tuningNumber = 0x00260,
	dataModeNumber = 0x00270,
	stateFlagsLow = 0x00280,
	stateFlagsHigh = 0x00290,
	stopEventCode = 0x002A0,
	stopFlagsLow = 0x002B0,
	stopFlagsHigh = 0x002C0,
	runningTimeSeconds = 0x002F0,
	runningTimeMinutes = 0x00300,
	runningTimeHours = 0x00310,
	runningTimeDays = 0x00320,
	positionScale = 0x003F0,
	raylaseStatusWord = 0x00800,
}rlEPDataMode;

typedef enum
{
	changeScaleFactor = 0x00830,

	scaleFactorOne = 0x00000,
	scaleFactorHalf = 0x00010,
	scaleFactorQuarter = 0x00020,
	scaleFactorEighth = 0x00030
}rlEPPositionScaleFactor;

typedef enum
{
	dmSave = 0x00FF0,
	dmRecall = 0x00000,
}rlEPDMStorage;

typedef enum
{
	smSyncPerWord = 0,
	smSyncPerFrame = 1,
	smMarkEndOfWord = 2,
	smMarkEndOfFrame = 3,
	smMarkPostWord = 4
}rlSyncMode;

typedef enum
{
	deSpi = 0,
	deSpiListCommand = 1,
	deScannerCommunication = 2
}rlDataSource;

typedef enum
{
	stInactive = 0,
	stActive = 1
}rlState;

typedef enum
{
	orMsbFirst = 0,
	orLsbFirst = 1
}rlOrder;

typedef enum
{
	dmRelativeToCurrent = 0,
	dmRelativeToPrevious = 1
}rlMotfDistanceMode;

typedef enum
{
	stQuadratureDecoder = 0,
	stSpi = 1
}rlMotfSourceType;

typedef enum
{
	pyNone = 0,
	pyOdd = 1,
	pyEven = 2,
	pyMark = 3,
	pySpace = 4
}rlParity;

typedef enum
{
	hsNone = 0,
	hsXOnXOff = 1,
	hsRequestToSend = 2,
	hsRequestToSendXOnXOff = 3
}rlHandshake;

typedef enum
{
	sbNone = 0,
	sbOne = 1,
	sbTwo = 2,
	sbOnePointFive = 3
}rlStopBits;

typedef enum
{
	opsNormal = 0,
	opsConfigurationFailed = ( 1 << 0 ),
	opsInitializationFailed = ( 1 << 1 ),
	opsScannerError = ( 1 << 2 )
}rlOperatingState;

typedef struct
{
	double X;
	double Y;
}rlPoint2D;

typedef struct
{
	double X;
	double Y;
	double Z;
}rlPoint3D;

typedef struct
{
	double X;
	double Y;
	double Z;
	double M;
}rlPoint4D;

typedef struct
{
	rlIOPort Port;
	rlIODirection Direction;
	int32_t PinIndex;
	char Functions[4][60];
}rlIOPinMapping;

typedef struct
{
	int ConfigVersion;

	rlIOVoltage IOLevel;
	rlPolarity Polarities[32];
	uint32_t PolaritiesLen;
	rlIODirection Directions[32];
	uint32_t DirectionsLen;
	int32_t Functions[32];
	uint32_t FunctionsLen;
	double WriteDelay;
	double WriteWidth;
}rlPortConfig;

typedef struct
{
	rlIOPort port;
	rlPortConfig Config;
}rlPortsDict;

typedef struct
{
	int ConfigVersion;

	rlPortsDict Ports[16];
	int32_t PortsLen;
}rlGpioConfig;

typedef struct
{
	bool EnableGlobally;
	int32_t Exclusions[64];
	int32_t ExclusionsLen;
}rlEventStatus;

typedef struct
{
	rlEventType type;
	rlEventStatus EventStatus;
}rlEventsDict;

typedef struct
{
	int ConfigVersion;

	rlEventsDict Events[16];
	int32_t EventsLen;
}rlEventConfig;

typedef struct
{
	double A[3][3];
	double b[3];
}rlTransform3D;

typedef struct
{
	int ConfigVersion;
	rlPolarity FpsPolarity;
	rlPolarity GatePolarity;
	rlPolarity LMPolarity;
	double FpsStart;
	double FpsWidth;
	double GateSetup;
	double GateHold;
	double LaserTriggerDelay;
	double PowerScale;
	double PowerChangeSetup;
	double PowerWriteDelay;
	double PowerWriteWidth;
	rlPowerTarget HotPowerTarget;
	uint16_t OffPower;
	uint16_t StandbyPower;
	rlPowerTarget SimmerPowerTarget;
	uint16_t SimmerPower;
	bool EnableTickle;
	double TickleFrequency;
	double TickleWidth;
	bool EnableLaserSync;
	bool EnableGateModulatesLm;
	bool EnablePowerCorrection;
	bool EnableVelocityCorrection;
	bool EnablePowerCalibration;
	bool EnableEquallySpacedPulses;
}rlLaserConfig;

typedef struct
{
	double AccelerationTime;
	double TrackingError;
	double HeadBias;
} rlAxisParameterSet;

typedef struct
{
	int ConfigVersion;
	rlTransform3D FieldTransform;
	rlAxisParameterSet Axes[5];
	bool EnableFieldCorrection;
} rlScanHeadConfig;

typedef struct
{
	int ConfigVersion;
	rlPoint3D FieldSize;
	int32_t HeadCount;
	rlScanHeadConfig Heads[rlMAXSCANHEADS];
	double ScanHeadDelay;
	rlScanHeadFormat HeadFormat;
	double MaxMagnification;
}rlScannerConfig;

typedef struct
{
	int ConfigVersion;
	rlMotfSourceType SourceType;
	int32_t ModuleID;
}rlMotfSource;

typedef struct
{
	int ConfigVersion;
	rlMotfSource MainSource;
	bool UseCompensation;
	rlMotfSource CompensationSource;
	bool EnableDebounce;
	double DebounceTime;
	bool EnableSuppression;
	double SuppressionDistance;
	double PartDistance;
	double ResponseTime;
	rlPoint3D MainDirection;
	rlPoint3D CompensationDirection;
	rlPoint3D Offset;
}rlMotfConfig;

typedef struct
{
	int ConfigVersion;
	rlPoint2D Amplitude;
	rlPoint2D Frequency;
	rlPoint2D Phase;
}rlWobbleSettings;

typedef struct
{
	int ConfigVersion;
	double SpeedScale;
	double JumpSpeed;
	double JumpDelay;
	bool EnableVariableJumpDelay;
	double MinJumpDelay;
	double JumpLengthLimit;
	double MarkSpeed;
	double MarkDelay;
	double MagnificationSpeed;
	bool EnableVariablePolyDelay;
	double PolyDelay;
	double LaserOnDelay;
	double LaserOffDelay;
	double MaxDwellTime;
	double LmFrequency;
	double LmWidth;
	uint16_t Power;
	rlTransform3D Transform;
	uint32_t OnOffPatternCount;
	double OnOffPattern[rlMAXONOFFPATTERNLEN];
	bool EnableDashedLine;
	double EvaluationLeadTime;
	bool EnableSkyWriting;
	double SkyWritingMinCoH;

	rlWobbleSettings Wobble;
}rlProcessVariables;

typedef struct
{
	int ConfigVersion;
	int32_t Head;
	rlScanHeadFormat HeadFormat;
	rlLayers XLayers;
	rlLayers YLayers;
	rlLayers ZLayers;
	rlLayers MLayers;
	double MaxAngleX;
	double MaxAngleY;
	double MaxMagnification;
	double Y2Z0;
	double X2Y;
	double O2X;
	double FocalLength;
	double MaxLensTravel;
	rlPoint3D FieldSize;
	rlPoint3D FieldOffset;
	double Aperture;
	double WorkingDistance;
	uint32_t HashLen;
	char Hash[rlCORRECTIONHASHLEN];
}rlOpticalParameters;

typedef struct
{
	int ConfigVersion;
	bool PortA;
	bool PortB;
	bool PortC;
	bool PortDLow;
	bool PortDHigh;
	bool PortELow;
	bool PortEHigh;
	bool PortLaserIn;
	bool PortLaserIn0;
	bool PortLaserIn1;
	bool PortLaserOut;
	bool PortLaserOut0;
	bool PortLaserOut1;
	bool PortLaserOut2;
	bool Dac0;
	bool Dac1;
	bool LaserPower16;
	bool LaserPower8;
	bool LaserPower4;
	bool LaserPower2;
	bool LaserPower1;
	bool Fps;
	bool Gate;
	bool Lm;
	bool LaserTriggered;
	bool StartMark;
	bool AbortMark;
	bool MotorStep;
	bool MotorDirection;
}rlTraceBufferConfig0;

typedef struct
{
	int ConfigVersion;
	bool Head0TxX;
	bool Head0TxY;
	bool Head0TxZ;
	bool Head0RxX;
	bool Head0RxY;
	bool Head0RxZ;
	bool Head1TxX;
	bool Head1TxY;
	bool Head1TxZ;
	bool Head1RxX;
	bool Head1RxY;
	bool Head1RxZ;
}rlTraceBufferConfig1;

typedef struct
{
	int ConfigVersion;
	bool IOEventChange;
	bool PositionEventChange;
	bool ControlEventChange;
	bool Label;
}rlTraceBufferConfig3;

typedef struct
{
	int ConfigVersion;
	rlTraceBufferConfig0 IOEvents;
	rlTraceBufferConfig1 PositionEvents;
	rlTraceBufferConfig3 ControlEvents;
}rlTraceBufferConfig;

typedef struct
{
	int ConfigVersion;
	bool Enabled;
	rlSyncMode SpiSyncMode;
	uint16_t BitsPerWord;
	double PreDelay;
	double PostDelay;
	double FrameDelay;
	rlDataSource OutputSource;
	rlOrder BitOrder;
	double ClockPeriod;
}rlSpiModule;

typedef struct
{
	int ConfigVersion;
	rlSpiModule Modules[rlSPIModuleCount];
}rlSpiConfig;

typedef struct
{
	int ConfigVersion;
	bool SimulateEncoder;
	double SimulationSpeed;
	double SimulationAcceleration;
	bool InvertDirection;
	bool EnableIndex;
	double DistancePerCount;
}rlQuadratureDecoderModule;

typedef struct
{
	int ConfigVersion;
	rlQuadratureDecoderModule Modules[rlQuadratureDecoderModuleCount];
}rlQuadratureDecoderConfig;

typedef struct
{
	rlPoint4D NominalBeforeTransformation;
	rlPoint4D NominalAfterTransformation;
	rlPoint3D Laser;
	rlPoint3D User;
	rlPoint3D Motf;
	rlPoint4D Actual[rlMAXSCANHEADS];
	rlPoint3D Head[rlMAXSCANHEADS];
}rlPositions;

typedef struct
{
	uint32_t IdLen;
	char Id[rlTIMEZONEMAXLEN];
}rlTimeZone;

typedef struct
{
	bool Enabled;
	uint32_t Command;
	uint32_t Mask;
	uint32_t GoodValue;
	int32_t Period;
	int32_t MinConsecutiveErrors;
	bool ContinueOnError;
	rlAxes ScanHeadAxes[rlMAXSCANHEADS];
}rlScannerMonitoringConfig;

typedef struct
{
	int ConfigVersion;
	rlTimeZone TimeZone;
	bool EnableStandAloneMode;
	int32_t StandAloneListID;
	int32_t StandAloneExecuteOnErrorListID;
	rlScannerMonitoringConfig ScannerMonitoring;
}rlSystemConfig;

typedef struct
{
	char SerialNumber[rlSNMAXLEN];
	int32_t Port;
	char Ip[rlIPMAXLEN];
}rlCardInfo;

typedef struct
{
	double Velocity;
	double Acceleration;
	rlHomingMethod HomingMethod;
	double HomingFastSpeed;
	double HomingSlowSpeed;
	double HomingAcceleration;
	double OriginPosition;
	double HomeOffset;
}rlMotorAxisVariables;

typedef struct
{
	double ConfigVersion;
	double CoordinatedAcceleration;
	double CoordinatedVelocity;
	rlMotorAxisVariables Axes[rlMaxSupportedMotorAxes];
}rlMotorVariables;

typedef struct
{
	double UnitsPerStep;
	double MaximumSoftLimit;
	double MinimumSoftLimit;
	rlLimit EnableSoftLimit;
	bool EnableLimitSensor;
	double MinimumVelocity;
	double StepWidth;
}rlMotorAxisParameterSet;

typedef struct
{
	double ConfigVersion;
	rlMotorAxisParameterSet Axes[rlMaxSupportedMotorAxes];
}rlMotorConfig;

typedef struct
{
	int ConfigVersion;
	bool Enabled;
	int BaudRate;
	rlParity Parity;
	int DataBits;
	rlStopBits StopBits;
	rlHandshake Handshake;
	int ReadTimeout;
	int WriteTimeout;
	uint32_t NewLineLen;
	char NewLine[rlNEWLINEMAXLEN];
}rlSerialPortConfig;

typedef void( *rlListDoneCallback )( rlHandle, int32_t );
typedef void( *rlListIdleCallback )( rlHandle, int32_t );
typedef void( *rlProgressCallback )( rlHandle, int32_t );
typedef void( *rlHomeDoneCallback )( rlHandle, int32_t );
typedef void( *rlMoveDoneCallback )( rlHandle, int32_t );
typedef void( *rlErrorCallback )( rlHandle, int32_t, const char*, uint32_t );

#endif // _RL_TYPES_H_
