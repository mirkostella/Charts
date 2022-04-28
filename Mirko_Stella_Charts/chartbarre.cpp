#include "chartbarre.h"

void ChartBarre::impostaValori(Grafico * grafico)
{
    TracciatoMultiplo* g=static_cast<TracciatoMultiplo*>(grafico);
    QList<QString> categorie=g->getCategorie();
    for(auto it=categorie.cbegin();it!=categorie.cend();++it)
        asseX->append(*it);

    QList<Traccia*> listaTracce= g->getTracce();

    if(!listaTracce.isEmpty()){
    for(auto it=listaTracce.cbegin();it!=listaTracce.cend();++it){
        QBarSet *set = new QBarSet((**it).getNome());
        for(auto i=categorie.cbegin();i!=categorie.cend();++i){
            *set<<(*it)->getTraccia()[*i];
        }
        serie->append(set);
    }
    }
    else{
        QBarSet *set = new QBarSet("");
        *set<<1;
        serie->append(set);
    }

}

ChartBarre::ChartBarre(Grafico* grafico):asseX(new QBarCategoryAxis()),asseY(new QValueAxis()),serie(new QBarSeries())
{
    impostaValori(grafico);
    addSeries(serie);
    addAxis(asseX, Qt::AlignBottom);
    addAxis(asseY, Qt::AlignLeft);
    serie->attachAxis(asseX);
    serie->attachAxis(asseY);
    this->setAnimationOptions(QChart::SeriesAnimations);
}

//svuota il grafico e lo risetta con i valori nuovi
void ChartBarre::aggiornaChart(Grafico* grafico)
{
    asseX->clear();
    removeSeries(serie);
    serie->clear();
    removeAxis(asseY);
    delete asseY;
    asseY=new QValueAxis();
    impostaValori(grafico);
    addSeries(serie);
    addAxis(asseY,Qt::AlignLeft);
    serie->attachAxis(asseY);
}
