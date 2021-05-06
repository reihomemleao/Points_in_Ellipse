#include "Myellipse.h"
#include <QList>
#include <QFile>

#include"points_in_ellipse.h"

#include <chrono>
#include <thread>


Myellipse::Myellipse() {


}

Myellipse:: ~Myellipse() {

}



QRectF Myellipse::boundingRect() const {

	//Hier wird die Basis, vorbereitet wo unser Objekt gezeichnet wird

	switch (m_zoom) {
	case(0):
		//ohne zoom
		return QRectF(0, 0, 50, 50);
		break;
	case(1):
		//zoom 1
		return QRectF(0, 0, 500, 500);
		break;
	case(2):
		//zoom 2
		return QRectF(0, 0, 2000, 2000);
		break;
	case(3):
		//zoom 3
		return QRectF(0, 0, 6000, 6000);
		break;
	case(4):
		//zoom 4
		
		return QRectF(0, 0, 9000, 9000);
		break;
	}
}

 void Myellipse::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
	QRectF rec = boundingRect();

	QPainterPath path;
	QPen blackpen(Qt::blue);
	QPen redpen(Qt::red);

	blackpen.setWidth(1);
	redpen.setWidth(1);

	painter->setPen(blackpen);

	
	QBrush brush(Qt::white);
	QBrush ebrush(Qt::black);

	painter->fillRect(rec,brush);
	
	
	
	
	
	//if (!m_malen) {
	bool ger = 0;
	int y_achse1 = 0, y_achse2=0;

	//Fläche oder laserscannfeld
	//switch (m_zoom) {
	//	
	//case(0):
	//	painter->setBrush(Qt::green);
	//	//original painter->drawRect(2.7, 1.5, 33.5, 35);
	//    //Erste quadrant (hoch Links)
	//	//painter->drawRect(2.7, 1.5, ((33.5)/2), ((35)/2));
	//	//Zweite Quadrant (Hoch rechts)
	//	painter->drawRect(33.5 / 2, 1.5, 33.5/1.5 , 35 / 2);
	//	////Dritte Quadrant (unten Links)
	//	//painter->drawRect(2.7, 35 / 2, 33.5, 35 );
	//	////Vierte Quadrant (unten rechts)
	//	//painter->drawRect(33.5 / 2, 35 / 2, 33.5, 35);
	//
	//	break;
	//case(1):
	//	painter->setBrush(Qt::green);
	//	// original painter->drawRect((2.7 * 10) + 45, (1.5 * 10) + 50, 33.5 * 10, 35 * 10);
	//	//painter->drawRect((2.7 * 10) + 68, (1.5 * 10) + 52,35 ,33 );
	//	painter->drawRect((2.7 * 10) + 46, (1.5 * 10) + (87 +(4*69)), 33, 33);
	//	//painter->drawRect((2.7 * 10) + 46, (1.5 * 10) + (66 + 40), 33, 33);
	//	//painter->drawRect((2.7 * 10) + 60+45, (1.5 * 10) + 52, 40, 33);

	//	//i =Y ; j=X achse
	//	
	//	for (int i = 0; i < 10; i++) {
	//		
	//		for ( int z=0; z < 8; z++) {
	//			int e = i;
	//			if (ger == 0) {
	//				//painter->drawRect((2.7 * 10) + (66+40*z), (1.5 * 10) + (52), 33, 33);
	//				painter->drawRect((2.7 * 10) + (66 + 40 * z), (1.5 * 10) + (52 + (y_achse1 * 69)), 33, 33);
	//				
	//			}
	//			else {
	//				painter->drawRect((2.7 * 10) + 46 + 40 * z, (1.5 * 10) + (87 + (y_achse2 * 69)), 33, 33);
	//				//painter->drawRect((2.7 * 10) + (45+40*z), (1.5 * 10) + 45*i, 33, 33);
	//				
	//			}
	//		}
	//		if (ger == 0) {
	//			ger = 1;
	//			y_achse1++;
	//		}
	//		else {
	//			ger = 0;
	//			y_achse2++;
	//		}
	//	}

	//	break;
	//case(2):
	//	painter->setBrush(Qt::green);
	//	painter->drawRect(2.7 * 45 - 50, 1.5 * 50 - 50, 33.5 * 50 , 35 * 50);
	//	break;
	//case(3):
	//	painter->setBrush(Qt::green);
	//	painter->drawRect(2.7 * 150 - 500, 1.5 * 150 - 50, 33.5 * 150 , 35 * 150 );
	//	break;
	//case(4):
	//	painter->setBrush(Qt::green);
	//	painter->drawRect(2.7 * 200 - 800, 1.5 * 200- 300, 33.5 * 200, 35 * 200);
	//	break;


	//}


		painter->setPen(redpen);
		for (int i = 0; i < listx.length(); i++) {

			//Hier werden die normale Punkte gezeichnet
			
			switch (m_zoom) {
			case(0):
				//ohne zoom
				
				painter->drawPoint(listx.at(i), listy.at(i));
				
				break;
				// Die normale Punkte sind hier unten. Aber damit man fake zoom macht muss man dir Koordinaten durch eine Nummer multiplizieren 
			case(1):
				//zoom 1
				painter->drawPoint((listx.at(i)*10)+50, (listy.at(i)*10)+50);
				break;

			case(2):
				//zoom 2
				painter->drawPoint(listx.at(i)*50 -50, listy.at(i)*50 -50);
				break;
			case(3):
				//zoom 3
				painter->drawPoint(listx.at(i)*150 -500, listy.at(i)*150-50);
				break;
			case(4):
				//zoom4
				//hier unten sind die Kreise (Fake zoom)
				
				painter->drawEllipse((listx.at(i)*200) -800, (listy.at(i) *200)-300,7,7);
				/*QPolygonF poley;
				poley << QPointF(20+ (listx.at(i) * 200) - 800, 10+ (listy.at(i) * 200) - 300) << QPointF(40+ (listx.at(i) * 200) - 800, 10+ (listy.at(i) * 200) - 300) << QPointF(55+ (listx.at(i) * 200) - 800 - 5, 30+ (listy.at(i) * 200) - 300) << QPointF(40+ (listx.at(i) * 200) - 800, 48+ (listy.at(i) * 200) - 300) << QPointF(20+ (listx.at(i) * 200) - 800, 48+ (listy.at(i) * 200) - 300) << QPointF(5 + 5+ (listx.at(i) * 200) - 800, 30+ (listy.at(i) * 200) - 300);
				painter->drawPolygon(poley);*/
				
				break;
			}
		}

	//}else{
		//Hier werden die Punkte mit Farbe gezeichnet

		painter->setPen(blackpen);
		//Code die, die Punkte Fühlt
		painter->setBrush(QBrush(Qt::black, Qt::SolidPattern));
		for (int i = 0; i < list_malenx.length(); i++) {
			
			switch (m_zoom) {
			case(0):
				//ohne zoom
				painter->drawPoint(list_malenx.at(i), list_maleny.at(i));
				break;
				// Die normale Punkte sind hier unten. Aber damit man fake zoom macht muss man dir Koordinaten durch eine Nummer multiplizieren 
			case(1):
				//zoom 1
				painter->drawPoint((list_malenx.at(i) * 10) + 50, (list_maleny.at(i) * 10) + 50);
				break;

			case(2):
				//zoom 2
				painter->drawPoint(list_malenx.at(i) * 50 - 50, list_maleny.at(i) * 50 - 50);
				break;

			case(3):
				//zoom 3
				blackpen.setWidth(3);
				painter->drawPoint((list_malenx.at(i) * 150) - 500, (list_maleny.at(i) * 150) - 50);
			
		
				break;
			case(4):
				//zoom4
				//hier unten sind die Kreise (Fake zoom)
				painter->drawEllipse(((list_malenx.at(i) * 200) - 800), ((list_maleny.at(i) * 200) - 300), 7, 7);
				break;
			}
			
		}
		painter->setPen(blackpen);
	//}

 }

 void Myellipse::setZoomValue(int value) {
	 m_zoom = value;
 }


 void Myellipse::setlistxValue(double coordx) {
	  listx.append(coordx);
 }

 void Myellipse::setlistyValue(double coordx) {
	 listy.append(coordx);
 }

 void Myellipse::setMalenValue(bool malen) {
	 m_malen = malen;
 }

 void Myellipse::setListMalenxValue(double coordx) {
	 list_malenx.append(coordx);
 }

 void Myellipse::setListMalenyValue(double coordy) {
	 list_maleny.append(coordy);
 }

 void Myellipse::ListMalenxValueClear() {
	 list_malenx.clear();
 }


 void Myellipse::ListMalenyValueClear() {
	 list_maleny.clear();
 }

 void Myellipse::listxValueClear() {
	 listx.clear();
 }

 void Myellipse::listyValueClear() {
	 listy.clear();
 }