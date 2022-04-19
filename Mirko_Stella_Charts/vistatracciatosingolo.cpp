#include "vistatracciatosingolo.h"

QChart *VistaTracciatoSingolo::creaTorta()
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

               return chart;
}

VistaTracciatoSingolo::VistaTracciatoSingolo(Grafico * g):VistaGrafico(g)
{
    selezioneRappresentazione->addItem("torta");
}

void VistaTracciatoSingolo::cambiaRappresentazione(int selezione)
{
    QChart* temp=getChart();

    if(selezione==0){
        areaGrafico->setChart(creaBarre());
    }
    if(selezione==1){
        areaGrafico->setChart(creaTorta());
    }
    if(selezione==2){
        areaGrafico->setChart(creaSpezzata());
    }
    delete temp;
    areaGrafico->setRenderHint(QPainter::Antialiasing);
}

