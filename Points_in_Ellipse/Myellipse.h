#pragma once
#include <QPainter>
#include<QGraphicsItem>
#include<QDebug>
#include<QtGui>
#include<QtCore>
#include <math.h>



//#include"points_in_ellipse.h"

//esta é uma classe c++ e nao qt, tudo aqui teve de ser escrito
class Myellipse :public QGraphicsItem
{
private:
	/*Ui::Points_in_EllipseClass ui;
	Points_in_Ellipse* pontos;*/
	int m_zoom;
	bool m_malen;
	QList<double> listx;
	QList<double> listy;

	QList<double> list_malenx;
	QList<double> list_maleny;
	

public:
	Myellipse();
	~Myellipse();

	void setMalenValue(bool);
	void setZoomValue(int);

	void setlistxValue(double);
	void setlistyValue(double);

	void setListMalenxValue(double);
	void setListMalenyValue(double);

	void ListMalenxValueClear();
	void ListMalenyValueClear();

	void listxValueClear();
	void listyValueClear();



	QRectF boundingRect() const;

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	
	double el_x = 0, el_y = 0 ,el_size=200;
	double el_dm = 200;

	//QList<QPoint> Lista(double a, double b);
	QList<QPoint> myList;
	

	int listn = 0;


	 
};

