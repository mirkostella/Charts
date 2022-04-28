#include "chartspezzata.h"

void ChartSpezzata::impostaValori(Grafico * g)
{
//        TracciatoMultiplo* tracc=static_cast<TracciatoMultiplo*>(g);
//        QList<Traccia*> listaTracce=tracc->getTracce();
//        QList<QString> listaCategorie=tracc->getCategorie();

//        for(auto it=listaTracce.cbegin();it!=listaTracce.cend();++it){
//            QLineSeries* series = new QLineSeries();
//            series->setName((*it)->getNome());
//            for(auto i=listaCategorie.cbegin();i!=listaCategorie.cend();++i){


//            }

//        }
//        series->setPointsVisible();
//        series->setPointLabelsVisible();


//        series->append(1,6.11);
//        series->append(2,4.6);
//        series->append(3,3);
//        series->append(4,9.4);
//        addSeries(series);

//        QLineSeries* series2 = new QLineSeries();
//        series2->setName("perdite");
//        QColor colore("red");
//        series2->setColor(colore);
//        series2->setPointsVisible();
//        series2->setPointLabelsVisible();


//        series2->append(0,7);
//        series2->append(1,9.7);
//        series2->append(2,2);
//        series2->append(3,1);
//        series2->append(4,5);
//        addSeries(series2);

//        QCategoryAxis *axisX = new QCategoryAxis();
//        axisX->append("Gennaio",1);
//        axisX->append("Febbraio",2);
//        axisX->append("Marzo",3);
//        addAxis(axisX, Qt::AlignBottom);
//        series->attachAxis(axisX);

//        QValueAxis *axisY = new QValueAxis();
//        addAxis(axisY, Qt::AlignLeft);
//        series->attachAxis(axisY);
}

ChartSpezzata::ChartSpezzata(Grafico * g)
{
    impostaValori(g);
}

void ChartSpezzata::aggiornaChart(Grafico * g)
{
    removeAllSeries();
    impostaValori(g);
}
