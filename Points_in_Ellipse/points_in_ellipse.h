#pragma once

#include <QtWidgets/QWidget>
#include "ui_points_in_ellipse.h"
#include "Myellipse.h"
#include"LunoStructs.h"
#include"QExecPython.h"
#include"QParsePointList.h"
#include "SettingsVals.h"

#include"Image.h"

//#include "SettingsVals.h"a

class Points_in_Ellipse : public QWidget
{
    Q_OBJECT

public:
    Points_in_Ellipse(QWidget *parent = Q_NULLPTR);
    
    

private:
    Ui::Points_in_EllipseClass ui;
    LUNOBackend::SettingsVals m_settings;


    QGraphicsScene* scene;
    Myellipse square;

    std::string m_ADSAddr;

    

public:
    QExecPython pythonexec;
    QParsePointList parsing;

    QList<Lunopoints> pont;
    
    QList<QPoint> pointlist(double x , double y);

    QString yscan, xscan, griddelta, radius, delta,name;
    
    //Liste die, die normale koordinaten bekommen
    QList<double> listX;
    QList<double> listY;
    
    //lpython ist die Liste die, die Datei txt hat
    QList<QString> lpython;
    //lpath ist die Liste die, die verschiedene paths hat
    QList<QString> lpath;
    //die Liste lfile sollte die txt dateien bekommen, aber die kommen in der combobox
    //QList<QString> lfile;

 
    // pos ist wichtig, weil sie uns erlaubt die Gewählte punkte zu mahlen
    int pos=0;
    bool point=false;
    bool skrypt = false;

    bool list_color = false;
      
    //File die, die Koordinaten hat
    //Este codigo significa que vamos rodar o codigo em Python e depois colocar os argumentos(numeros/variaveis)) atravez do sys e depois o codigo sera gerado no caminho que esta no lado direito
    QString textos;
    QString skript;



    QString texto, grid;
    QString mypython, mypath;

   // LUNOBackend::SettingsVals settings;
public slots:
    void setShow();
    void pbskript();
    void pbMalen();
    void pbadd();
    void pbreset();
    void writer(QString pyskript, QString path, QString pythontext);
    void read_to_list();

    void createBitmap();

};
