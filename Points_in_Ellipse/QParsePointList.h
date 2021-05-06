#pragma once
//#include <QtCore\qstring.h>
#include <QtWidgets/QWidget>

class QParsePointList {

public:
	bool ParsePoints(QString grid, QList<double> &lista, QList<double> &listb);
};