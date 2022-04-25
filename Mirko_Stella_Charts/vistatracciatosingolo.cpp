#include "vistatracciatosingolo.h"

void VistaTracciatoSingolo::creaTorta()
{
    QPieSeries *series = new QPieSeries();
       series->append("Jane", 1);
       series->append("Joe", 2);
       series->append("Andy", 3);
       series->append("Barbara", 4);
       series->append("Axel", 5);
       QPieSlice *slice = series->slices().at(1);
           slice->setExploded();
           slice->setLabelVisible();
           slice->setPen(QPen(Qt::darkGreen, 2));
           slice->setBrush(Qt::green);
           QChart *chart = new QChart();
               chart->addSeries(series);
               chart->setTitle("Simple piechart example");
               chart->legend()->hide();
               areaGrafico->setChart(chart);
}

void VistaTracciatoSingolo::inizializzaVociMenuPrincipale()
{
    VistaGrafico::inizializzaVociMenuPrincipale();
    QAction* vediTorta=new QAction("Torta");
    menuBar()->addAction(vediTorta);
    connect(vediTorta,SIGNAL(triggered()),this,SLOT(mostraTorta()));
}

VistaTracciatoSingolo::VistaTracciatoSingolo(QWidget* p,Grafico * g):VistaGrafico(p,g)
{
    QMenu* menuPrincipale=getMenuPrincipale();
    QAction* vediTorta=new QAction("Torta");
    menuPrincipale->addAction(vediTorta);
}

void VistaTracciatoSingolo::mostraTorta()
{
    creaTorta();
}



