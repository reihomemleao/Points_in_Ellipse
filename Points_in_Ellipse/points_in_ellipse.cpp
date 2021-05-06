#include "points_in_ellipse.h"
#include "stdafx.h"
#include <QProcess>
#include <chrono>
#include <thread>
#include<fstream>
#include <QFiledialog>
#include <QMessageBox>
#include <QDir>


using namespace std;
//Hier oben sind die Funktionen(nicht Methode) von struckt (eine Dynamische Dantenstruktur(Liste))
//double Y_Lunopoints_at(Lunopoints* anker, int nummer) {
//	if (nummer == 0 || nummer < 0) {
//		nummer = 1;
//	}
//
//	if (anker == nullptr) {
//		qDebug() << "liste leer";
//	}
//	else {
//		bool da = true;
//		Lunopoints* ptr = anker;
//		int i = 1;
//		while (i != nummer) {
//			ptr = ptr->next;
//			if (ptr->next == nullptr) {
//				qDebug() << "existiert nicht ";
//				da = false;
//				break;
//			}
//			i++;
//		}
//		if (da)
//			return ptr->Y;
//	}
//}
//
//
//int Lunopoints_processParamId_at(Lunopoints* anker, int nummer) {
//	if (nummer == 0 || nummer < 0) {
//		nummer = 1;
//	}
//
//	if (anker == nullptr) {
//		qDebug() << "liste leer";
//	}
//	else {
//		bool da = true;
//		Lunopoints* ptr = anker;
//		int i = 1;
//		while (i != nummer) {
//			ptr = ptr->next;
//			if (ptr->next == nullptr) {
//				qDebug() << "existiert nicht ";
//				da = false;
//				break;
//			}
//			i++;
//		}
//		if (da)
//			return ptr->processParamId;
//		else {
//			//nicht ganz sicher
//			return -1;
//		}
//	}
//	
//}
//
//
//int Lunopoints_scanFieldId_at(Lunopoints* anker, int nummer) {
//	if (nummer == 0 || nummer < 0) {
//		nummer = 1;
//	}
//
//	if (anker == nullptr) {
//		qDebug() << "liste leer";
//	}
//	else {
//		bool da = true;
//		Lunopoints* ptr = anker;
//		int i = 1;
//		while (i != nummer) {
//			ptr = ptr->next;
//			if (ptr->next == nullptr) {
//				qDebug() << "existiert nicht ";
//				da = false;
//				break;
//			}
//			i++;
//		}
//		if (da)
//			return ptr->scanFieldId;
//	}
//}
//void append_Lunopoints(Lunopoints*& anker,  double x,  double y, int scanFieldid) {
//
//	Lunopoints* neuer_eintrag = new Lunopoints;
//	neuer_eintrag->X = x;
//	neuer_eintrag->Y = y;
//
//	neuer_eintrag->scanFieldId = scanFieldid;
//	neuer_eintrag->next = nullptr;
//
//	if (anker == nullptr) {
//		neuer_eintrag->prev = nullptr;
//		anker = neuer_eintrag;
//	}
//	else
//	{
//		Lunopoints* ptr = anker;
//		while (ptr->next != nullptr) {
//			ptr = ptr->next;
//		}
//		ptr->next = neuer_eintrag;
//		//previous agora aponta para o eintrag antes do ultimo
//		neuer_eintrag->prev = ptr;
//	}
//	anker->amount++;
//}
//
//void append_Lunopoints(Lunopoints*& anker, double x, double y, int processParamid, int scanFieldid) {
//
//	Lunopoints* neuer_eintrag = new Lunopoints;
//	neuer_eintrag->X = x;
//	neuer_eintrag->Y = y;
//	neuer_eintrag->processParamId = processParamid;
//	neuer_eintrag->scanFieldId = scanFieldid;
//	neuer_eintrag->next = nullptr;
//
//	if (anker == nullptr) {
//		neuer_eintrag->prev = nullptr;
//		anker = neuer_eintrag;
//	}
//	else
//	{
//		Lunopoints* ptr = anker;
//		while (ptr->next != nullptr) {
//			ptr = ptr->next;
//		}
//		ptr->next = neuer_eintrag;
//		//previous agora aponta para o eintrag antes do ultimo
//		neuer_eintrag->prev = ptr;
//
//	}
//
//	anker->amount++;
//
//}
////Die Struct Funktionen enden hier



//wichtig jedes mal, dass die Python datei debbugd wird muss man die letzte Leerzeichen weg machen


Points_in_Ellipse::Points_in_Ellipse(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    connect(ui.pbshow, &QPushButton::clicked, this, &Points_in_Ellipse::setShow);
	connect(ui.pbskript, &QPushButton::clicked, this, &Points_in_Ellipse::pbskript);
	connect(ui.pbMalen, &QPushButton::clicked, this, &Points_in_Ellipse::pbMalen);
	connect(ui.pbadd, &QPushButton::clicked, this, &Points_in_Ellipse::pbadd);
	connect(ui.pbreset, &QPushButton::clicked, this, &Points_in_Ellipse::pbreset);

	//Default Koordinaten
	ui.comboBox->addItem("C:/Users/L.Candido/Documents/Leandro/Pyton/Scripts-Python/Meu.py");
	lpython.append("C:/Users/L.Candido/Documents/Leandro/Pyton/Scripts-Python/LeandroGrid.txt");
	lpath.append("C:/Users/L.Candido/Documents/Leandro/Pyton/Scripts-Python/");

	for(int i=0;i<=4;i++)
	ui.zBox->addItem(QString::number(i));

	scene = new QGraphicsScene(this);
	ui.graphicsView->setScene(scene);

	//read_to_list() funktion die, die Punkte(skript, path usw) in einem txt datei speichert
	read_to_list();
	//Funktion die ein bitmap file erstellt
	//createBitmap();

	

	//init Settings
	bool InitFileStatus = m_settings.init("C:\\Users\\L.Candido\\source\\repos\\Points_in_Ellipse\\Points_in_Ellipse\\Resources\\Settings.def");
	m_settings.getValString("ADSAddr", m_ADSAddr);
	int ret = m_settings.setValString("ADSAddr", "0.123");
}

void Points_in_Ellipse::setShow() {

	
	//Hier werden die Punkte gezeigt und die Liste die Recht steht

	//Die Variable Skrypt muss true sein, weil zuerst ein Skript gewählt werden muss
	if (skrypt == true) {

		//square.setMalenValue(false);

		//Hier bekommen wir den Wert von Zoom, der muss auf dem Klass Myellipse verwendet werden
		
		square.setZoomValue(ui.zBox->currentIndex());
		
		
		//square.setMalenValue(false);
		//Class Myellipse rufen
		scene = new QGraphicsScene(this);
		//Jedes mal, dass die Klasse gerufen wird muss die Scene gekleart werden, damit die Punkte nicht auf einander gezeichnet werden
		scene->clear();
		ui.graphicsView->setScene(scene);

		scene->addItem(&square);

		//Nur wenn list_color == false ist wird die Liste Erstellt und gezeigt 
		if (list_color == false) {
			ui.listWidget->clear();
			//Hier wird die Liste Erstellt und gezeigt
			for (int i = 0; i < listX.length(); i++) {
				ui.listWidget->addItem("Punkt Nummer :" + QString::number(i + 1) + " X Koordinaten: " + QString::number(listX.at(i)) + " Y Koordinaten: " + QString::number(listY.at(i)));

			}
			list_color = true;
		}
	}

	else {
		QMessageBox::warning(this, " Warnung", "Bitte laden Sie zuerst ein Skrypt");
	}
}

void Points_in_Ellipse::pbadd(){
	//Hier werden die Skripte Addiert

	QString skript=" ";
	bool richtig = false;
	
	QMessageBox msgBox;
	msgBox.setText("Symcondrill ");
	msgBox.setInformativeText("Bitte waehlen Sie ein Skrypt");
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();

	bool cancel = false, cnl =false;
	if (ret == QMessageBox::Ok) {
		
		do {
			skript = QFileDialog::getOpenFileName(this, "Open a File", QDir::homePath());
			//Hier wird gefragt ob die 3 lätzte buchstaben .py sind, wenn ja gehts weiter und wird was anders gewählt sonst muss man nochmal wählen 
			if (skript.at(skript.length() - 1) == 'y' && skript.at(skript.length() - 2) == 'p' && skript.at(skript.length() - 3) == '.') {
				QMessageBox::information(this, "Symcondrill", "Richtiger file gewaehlt: " + skript, "OK");
				richtig = true;
			}
			else {
				
				QMessageBox Box;
				Box.setText("Symcondrill ");
				Box.setInformativeText("Der file musste .py sein, bitte waehlen sie nochmal ihr File: ");
				Box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
				//Box.setDefaultButton(QMessageBox::Ok);
				int rot = Box.exec();

				if (rot != QMessageBox::Ok) {
					cancel = true;
				}
				
				//QMessageBox::critical(this, "Symcondrill", "Der file musste .py sein, bitte waehlen sie nochmal ihr File: " + skript, " OK");

			}
		} while (richtig == false && cancel == false);

		if(cancel==false){
		
			richtig = false;

		//QMessageBox::information(this, "Symcondrill","Bitte waehlen Sie das Verzeichnis wo die Koordinaten generiert werden: ", "OK");
		QMessageBox msg;
		msg.setText("Symcondrill ");
		msg.setInformativeText("Bitte waehlen Sie das Verzeichnis wo die Koordinaten generiert werden ");
		msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
		msg.setDefaultButton(QMessageBox::Ok);
		int rat = msg.exec();

		if (rat == QMessageBox::Ok) {

			QString mypath = QFileDialog::getExistingDirectory(this, "Open a Directory", QDir::homePath());

			QMessageBox::information(this, "Symcondrill", "Sie haben den path: " + mypath + "gewaehlt", " OK");

			radius = ui.radiusEdit->text(); //1
			delta = ui.deltaEdit->text(); //2
			xscan = ui.xScanEdit->text(); //3
			yscan = ui.yScanEdit->text();//4
			griddelta = ui.gridDEltaEdit->text();//5


			QString python = "python";

			//texto = python + " \"" + ui.comboBox->currentText() + "\" " + radius + " " + delta + " " + xscan + " " + yscan + " " + griddelta + " " + lpath.at(ui.comboBox->currentIndex());
			QString textos = "python \"" + skript + "\" " + radius + " " + delta + " " + xscan + " " + yscan + " " + griddelta + " " + mypath + "/";
			//ui.lineEdit->setText(textos);

			//commandline code
			//QProcess process;
			//process.startDetached(textos);
			pythonexec.startProcess(textos);

			QMessageBox ms;
			ms.setText("Symcondrill ");
			ms.setInformativeText("Bitte waehlen Sie ein text mit dem Koordinaten ");
			ms.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
			ms.setDefaultButton(QMessageBox::Ok);
			int rit = ms.exec();
			
			if (rit == QMessageBox::Ok) {
				do {
					mypython = QFileDialog::getOpenFileName(this, "Open a File", QDir::homePath());
					
					//Hier wird gefragt ob die letzte Buchstaben .txt sind
					if (mypython.at(mypython.length() - 1) == 't' && mypython.at(mypython.length() - 2) == 'x' && mypython.at(mypython.length() - 3) == 't' && mypython.at(mypython.length() - 4) == '.') {
						QMessageBox::information(this, "Symcondrill", "Richtiger file gewaehlt: " + mypython, "OK");
						richtig = true;
					}
					else {
						//QMessageBox::critical(this, "Symcondrill", "Der file musste .txt sein, bitte waehlen sie nochmal ihr File: " + mypython, "OK");
						QMessageBox Box;
						Box.setText("Symcondrill ");
						Box.setInformativeText("Der file musste .txt sein, bitte waehlen sie nochmal ihr File: ");
						Box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
						//Box.setDefaultButton(QMessageBox::Ok);
						int rot = Box.exec();

						if (rot != QMessageBox::Ok) {
							cnl = true;
						}
					}
				} while (richtig == false && cnl==false);
				if (cnl == false) {

					//lpython ist die Liste die, die Datei txt hat
					//lpython.append(mypython);

					//////lpath hat, den Path des Verzeichnis
					//lpath.append(mypath);

					//////ui.comboBox hat die Skripte py
					//ui.comboBox->addItem(skript);

					//In dieser Methode werden die infos in einem Text genannt infos.text gespeichert 
					writer(skript, mypath,mypython);
					read_to_list();

					//init Settings
					/*bool InitFileStatus = m_settings.init("Resources\\Settings.def");
					m_settings.getValString("ADSAddr", m_ADSAddr);*/

					//m_settings.setValString("SKript", "Skript");

				}
			}
		}
		}
	}
}

void Points_in_Ellipse::pbskript() {

	//Die Liste müssen entleert werden sonst bekommen sie mehr und mehr Punkte
	listX.clear();
	listY.clear();
	ui.listWidget->clear();

	//die Liste müssen entleert werden
	square.ListMalenxValueClear();
	square.ListMalenyValueClear();

	square.listxValueClear();
	square.listxValueClear();

	QByteArray contenido;
	QFile b;
	QString linha;

	radius = ui.radiusEdit->text(); //1
	delta = ui.deltaEdit->text(); //2
	xscan = ui.xScanEdit->text(); //3
	yscan = ui.yScanEdit->text();//4
	griddelta = ui.gridDEltaEdit->text();//5

	QString python = "python";
	QString textos = "python \"" + ui.comboBox->currentText() + "\" " + radius + " " + delta + " " + xscan + " " + yscan + " " + griddelta + " " + lpath.at(ui.comboBox->currentIndex()) + "/";
	
	//commandline code

	/*QProcess process;
	process.startDetached(textos);*/

	//funktion von QExecPython
	pythonexec.startProcess(radius, delta, xscan, yscan, griddelta, ui.comboBox->currentText(), lpath.at(ui.comboBox->currentIndex()));

	//File die, die Koordinaten hat
	//grid= "C:/Users/L.Candido/Documents/Leandro/Pyton/Scripts-Python/LargeGrid.txt";
	//grid = "C:/Users/L.Candido/Documents/Leandro/Pyton/Scripts-Python/LeandroGrid.txt";
	grid = lpython.at(ui.comboBox->currentIndex());

	//der txt file mit den Koordinaten wird geöffnet und geparst in dieser Funktion
	bool result = parsing.ParsePoints(grid, listX, listY);
	if (!result) {
		QMessageBox::information(this, " Information", "Der File koennte nicht geoeffnet werden bitte seien Sie sicher, dass die Koordinaten richtig sind", "Ok");
	}
	else {

		//hier wird die Liste geladen, dass die Punkte zeichnet
		

		for (int i = 0; i < listX.length(); i++) {
			square.setlistxValue(listX.at(i));
			square.setlistyValue(listY.at(i));
			//
			/*QPoint p;
			p.setX(4);
			p.setY(5);
			p.x();*/
			//pointlist(listX.at(i), listY.at(i));
			/*Lunopoints pt;
			pt.X = 1;
			pt.Y = 2;
			pt.processParamId = 4;
			pt.scanFieldId = 1;
			pont.append(pt);*/
		}

		ui.insgesamtEdit->setText(QString::number(listX.length()));
		//ui.insgesamtEdit->setText(QString::number(square.listn));

	//Skrypt muss true sein, damit Die Methode Show funktioniert
		skrypt = true;
		list_color = false;
	}
	//QMessageBox::information(this, " Information", ui.comboBox->currentText()+" wurde gewaehlt bitte druecken sie auf Show um den Graph zu sehen");
	//Funktion die ein bitmap file erstellt
	createBitmap();
}

void Points_in_Ellipse::pbMalen(){

	if (ui.listWidget->count() != 0) {
		if (ui.listWidget->currentItem()) {
			pos = ui.listWidget->currentRow();
			
				//Liste die bekommt die Punkte, die gemahlt werden

			square.setListMalenxValue(listX.at(pos));
			square.setListMalenyValue(listY.at(pos));
			
			ui.listWidget->currentItem()->setText( "Hinzugefuegt "+ ui.listWidget->currentItem()->text());
			
			QListWidgetItem* itm = ui.listWidget->currentItem();
			itm->setTextColor(Qt::red);
			itm->setBackgroundColor(Qt::black);

			list_color = true;
		}
	}
else
QMessageBox::warning(this, " Warnung", "Bitte waehlen Sie zerst einen Punkt", "ok ");	
}

void Points_in_Ellipse::pbreset() {	
	//Die Zeile muss da sein, sonst funktioniert der Code nicht
	scene = new QGraphicsScene(this);

	scene->clear();
	ui.graphicsView->setScene(scene);

	if(!listX.isEmpty())
	listX.clear();

	if (!listY.isEmpty())
	listY.clear();

	
	skrypt = false;

	list_color = false;

	ui.listWidget->clear();
	square.ListMalenxValueClear();
	square.ListMalenyValueClear();
	square.listxValueClear();
	square.listyValueClear();

	radius = "1.500"; // ui.radiusEdit->text(); //1
	delta = "0.050"; //ui.deltaEdit->text(); //2
	xscan = "35.000";   //ui.xScanEdit->text(); //3
	yscan = "35.000";//ui.yScanEdit->text();//4
	griddelta = "4.000";//ui.gridDEltaEdit->text();//5

	ui.radiusEdit->setText(radius);
	ui.deltaEdit->setText(delta);
	ui.xScanEdit->setText(xscan);
	ui.yScanEdit->setText(yscan);
	ui.gridDEltaEdit->setText(griddelta);

	ui.insgesamtEdit->clear(); 

	//scene = new QGraphicsScene(this);
}

void  Points_in_Ellipse::writer(QString pyskript, QString path, QString pythontext) {

	fstream d2("infos.txt", ios::in);

	if (!d2) {
		qDebug() << "Unable to open file" << endl;
		fstream d3("infos.txt", ios::out);
		d3 << pyskript.toStdString() + "\t" + path.toStdString() + +"\t" + pythontext.toStdString()+ "\n";
		/*lpython.append(pyskript);
		lpath.append(path);*/
		qDebug() << "Writen1";
		d3.close();
	}
	else {

		fstream d3("infos.txt", ios::app);
		d3 << pyskript.toStdString() + "\t" + path.toStdString() + "\t" + pythontext.toStdString() + "\n";
		/*ui.comboBox->addItem(pyskript);
		lpath.append(path);*/
		qDebug() << "Writen n";
		d3.close();
	}

	d2.close();

}

void Points_in_Ellipse::read_to_list() {
	QByteArray contenido;
	QFile b;
	b.setFileName("infos.txt"); //("C:/Users/L.Candido/Documents/Leandro/Pyton/Scripts-Python/Qfile_test.txt");
	if (!b.exists()) {
		// ui.textEdit->setText
		//qDebug() << ("The file doesnt exist");
		QMessageBox::information(this, " Information", "Der File existiert nicht");

	}
	else {
		b.open(QIODevice::ReadOnly | QIODevice::Text);
		if (!b.isOpen()) {
			//ui.textEdit->setText
			//qDebug() << ("the file could not be openned");
			QMessageBox::information(this, " Information", "Der File koennte nicht geoeffnet werden bitte seien Sie sicher, dass die Koordinaten richtig sind", "Ok");
		}
		else {
			//contenido bekommt alles von der File und ist eine QString
			contenido = b.readAll();

			QString in1 = contenido;
			QList<QString> list = in1.split("\n");

			if (in1.at(in1.length() - 1) == "\n")
				in1.truncate(in1.length() - 1);

			/*
			//lpython ist die Liste die, die Datei txt hat
			lpython.append(mypython);

			////lpath hat, den Path des Verzeichnis
			lpath.append(mypath);

			////ui.comboBox hat die Skripte py
			ui.comboBox->addItem(skript);
			*/

			for (int i = 0; i < list.length() - 1; i++) {
				//skript py
				ui.comboBox->addItem(list.at(i).split("\t")[0]);
				//path
				lpath.append(list.at(i).split("\t")[1]);
				//txt file mit den Koordinaten
				lpython.append(list.at(i).split("\t")[2]);
			}
		}
	}
}


void Points_in_Ellipse::createBitmap() {
	const int width = 500;
	const int height = 500;

	Image image(width, height);

	//in the beginning all the bitmap pixels are black 
	//in the first loop i will paint the whole map with the white color
	//and only in the second is possible to manipulate the points 
	for (double y = 0; y < height; y += 1) {
		for (double x = 0; x < width; x += 1) {
			//image.setColor(Color((float)x/(float)width,1.0f-((float)x/(float)width),(float)y/(float)height),x,y);
			//0.992187500 is for the color white 
			image.setColor(Color(0.992187500, 0.992187500, 0.992187500), x, y);

		}
	}
	//for (double y = 0; y < height; y += 5) {
	//	for (double x = 0; x < width; x += 5) {
	//		//image.setColor(Color((float)x/(float)width,1.0f-((float)x/(float)width),(float)y/(float)height),x,y);
	//		for (int i = 0; i < listX.size(); i++) {
	//			if (x == listX.at(i) && y < height / 2)
	//				image.setColor(Color(255, 255, 255), x, y);
	//			else
	//				image.setColor(Color(0.992187500, 0.992187500, 0.992187500), x, y);

	//		}
	//	}
	//}
	
	for (int i = 0; i < listX.size(); i++) {
			image.setColor(Color(0, 0, 0),listX.at(i) * 10 + 50, listY.at(i) * 10 + 50);
	}

	image.Export("image.bmp");

}