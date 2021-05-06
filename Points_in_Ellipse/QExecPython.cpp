#include"QExecPython.h"
#include <QProcess>


//Funktion die, die Variabeln von unserem Qt Programm im Skript lädt 
bool QExecPython::startProcess(QString radius, QString delta, QString xscan, 
	QString yscan, QString griddelta, QString skript, QString path) {

	QString textos = "python \"" + skript /*ui.comboBox->currentText()*/ + "\" " + radius + " " + delta + " " + xscan + " " + yscan + " " + griddelta + " " + path /*lpath.at(ui.comboBox->currentIndex())*/ + "/";
	QProcess process;
	process.startDetached(textos);
	return 1;
}

//Funktion die, die Variabeln von unserem Qt Programm im Skript lädt 

bool QExecPython::startProcess(QString textos) {
	QProcess process;
	process.startDetached(textos);
	return 1;

}