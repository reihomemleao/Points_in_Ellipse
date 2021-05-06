#include <QDir>
#include"QParsePointList.h"
#include <QMessageBox>
#include <chrono>
#include <thread>
#include <QFiledialog>

bool QParsePointList::ParsePoints(QString grid, QList<double> &lista, QList<double> &listb) {

	QByteArray contenido;
	QFile b;
	QList<QString> list;
	//der txt file mit den Koordinaten wird hier geöffnet
		//b.setFileName("C:/Users/L.Candido/Documents/Leandro/Pyton/Scripts-Python/LargeGrid.txt");
	b.setFileName(grid);
	while (!b.exists()) {
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(1ms);
	}
	if (!b.exists()) {
		//QMessageBox::information(this, " Information", "Der File existiert nicht");
		return 0;
	}
	else {
		b.open(QIODevice::ReadOnly | QIODevice::Text);
		if (!b.isOpen()) {
			//QMessageBox::information(this, " Information", "Der File koennte nicht geoeffnet werden bitte seien Sie sicher, dass die Koordinaten richtig sind", "Ok");
			return 0;
		}
		else {
			/*using namespace std::chrono_literals;
			std::this_thread::sleep_for(5000ms);*/
			contenido = b.readAll();

			QString in1 = contenido;

			while (in1.at(in1.length() - 1) != "\n") {
				using namespace std::chrono_literals;
				std::this_thread::sleep_for(1ms);
			}

			//Der letzte character muss gelöscht werden

			if (in1.at(in1.length() - 1) == "\n")
				in1.truncate(in1.length() - 1);

			//Liste mit der Nummer von Punkten
			list = in1.split("\n");

			//QList<double> listb;

			QListIterator<QString> iter(list);

			int counter = 0;
			while (iter.hasNext()) {
				QString i = iter.next();
				lista.append(i.split("\t")[0].toDouble());
				//square.setlistxValue(lista.at(counter));

				listb.append(i.split("\t")[1].toDouble());
				//square.setlistyValue(listb.at(counter));
				counter++;

					
			}
			b.close();
			return 1;
		}
	}
}

