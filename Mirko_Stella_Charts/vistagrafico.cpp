#include "vistagrafico.h"


VistaGrafico::VistaGrafico(Grafico * g):
    grafico(g),layPrincipale(new QHBoxLayout),layGrafico(new QVBoxLayout),layModifica(new QVBoxLayout),
    areaGrafico(new QChartView),pulsanteModifica(new QPushButton("modifica")),selezioneRappresentazione(new QComboBox())
{
    layPrincipale->addLayout(layModifica);
    layPrincipale->addLayout(layGrafico);
    layGrafico->addWidget(areaGrafico);
    setLayout(layPrincipale);
    layPrincipale->addWidget(pulsanteModifica);
    areaGrafico->setChart(new QChart());

    layPrincipale->addWidget(selezioneRappresentazione);
    selezioneRappresentazione->addItem("barre");
    selezioneRappresentazione->addItem("spezzata");
    creaBarre();
    connect(selezioneRappresentazione,SIGNAL(currentIndexChanged(int)),this,SLOT(cambiaRappresentazione(int)));
}

void VistaGrafico::impostaGrafico(QtCharts::QChart * c)
{
    if(c)
        areaGrafico->setChart(c);
}

Grafico *VistaGrafico::getGrafico() const
{
    return grafico;
}

QChart *VistaGrafico::getChart() const
{
    return areaGrafico->chart();
}

void VistaGrafico::cambiaRappresentazione(int selezione)
{
    QChart* temp=areaGrafico->chart();

    if(selezione==0){
        areaGrafico->setChart(creaBarre());
    }
    if(selezione==2){
        areaGrafico->setChart(creaSpezzata());
    }
    delete temp;
    areaGrafico->setRenderHint(QPainter::Antialiasing);
}


//da sistemare
QChart *VistaGrafico::creaBarre()
{
    TracciatoMultiplo* gMulti=dynamic_cast<TracciatoMultiplo*>(grafico);

    QList<TracciatoSingolo*> listaTracce= gMulti->getTracce();
    QList<QString> listaCategorie= gMulti->getCategorie();
    QStringList categories;

    for(auto i=listaCategorie.cbegin();i!=listaCategorie.cend();++i){
        std::cout<<i->toStdString();
        categories<<*i;
    }
    QBarSeries *series = new QBarSeries();
    if(!listaTracce.isEmpty()){



    for(auto it=listaTracce.cbegin();it!=listaTracce.cend();++it){
        QBarSet *set = new QBarSet((**it).getNome());
        for(auto i=listaCategorie.cbegin();i!=listaCategorie.cend();++i){
            *set<<(**it).getTraccia()[*i];
        }
        series->append(set);
    }
    }
    else{
        QBarSet *set = new QBarSet("");
        *set<<1;
        series->append(set);
    }


          QChart *chart = new QChart();
             chart->addSeries(series);
             chart->setTitle("Simple barchart example");
             chart->setAnimationOptions(QChart::SeriesAnimations);


                QBarCategoryAxis *axisX = new QBarCategoryAxis();
                axisX->append(categories);
                chart->addAxis(axisX, Qt::AlignBottom);
                series->attachAxis(axisX);

                QValueAxis *axisY = new QValueAxis();
                chart->addAxis(axisY, Qt::AlignLeft);
                series->attachAxis(axisY);

                chart->legend()->setVisible(true);
                   chart->legend()->setAlignment(Qt::AlignBottom);

                   return chart;
}

QChart *VistaGrafico::creaSpezzata()
{

}

