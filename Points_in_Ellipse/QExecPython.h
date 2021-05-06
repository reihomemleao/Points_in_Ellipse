#pragma once
#include <QtCore\qstring.h>

class QExecPython {

public:
	bool startProcess(QString radius,QString delta, QString xscan, QString yscan,QString griddelta, QString skript, QString path);
	bool startProcess(QString textos);

	
};