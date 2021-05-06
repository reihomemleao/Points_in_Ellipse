#pragma once

struct Lunopoints {
	double X; //(1)
	double Y; //(1)
	int processParamId = 1; //(1)
	int scanFieldId; //(2)
};

struct Lunoscanfeld
{
	double	x0, y0;
	double xmax, ymax;
	int scanFeldI;
};

struct LunoProcessparam
{
	double LaserOnDelay;
	double LaserOffDelay;
	double JumpSpeed;
	double JumpDelay;
	double PolyDelay;
	int pulsePerDrill;
	double durationPerDrill; //(in microns)
	double laserPower;
	int processParamId;
};



//void append_Lunopoints(Lunopoints*& anker, const int x, const int y, int processParamid, int scanFieldid);
double X_Lunopoints_at(Lunopoints* anker, int nummer);
double Y_Lunopoints_at(Lunopoints* anker, int nummer);
int Lunopoints_processParamId_at(Lunopoints* anker, int nummer);
int Lunopoints_scanFieldId_at(Lunopoints* anker, int nummer);

void append_Lunoscanfeld(Lunoscanfeld*& anker, const int wert);
void append_LunoProcessparam(LunoProcessparam*& anker, const int wert);




