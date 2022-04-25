#include "vistagrafico.h"

//crea il menu principale e lo imposta come menuBar
void VistaGrafico::inizializzaVociMenuPrincipale()
{
    QMenuBar* menuPrincipale=new QMenuBar();
    //la funzione si preoccupa della distruzione del menu giá presente
    setMenuBar(menuPrincipale);
    QAction* modifica=new QAction("Modifica");
    QAction* vediBarre=new QAction("Barre");
    QAction* vediSpezzata=new QAction("Spezzata");
    menuPrincipale->addAction(modifica);
    QMenu* rappresentazione=menuPrincipale->addMenu("Cambia rappresentazione");
    rappresentazione->addAction(vediBarre);
    rappresentazione->addAction(vediSpezzata);

    connect(modifica,SIGNAL(triggered()),this,SLOT(mostraModifica()));
    connect(vediBarre,SIGNAL(triggered()),this,SLOT(mostraBarre()));
    connect(vediSpezzata,SIGNAL(triggered()),this,SLOT(mostraSpezzata()));
}

//crea il menu per la modifica e lo imposta come menuBar
void VistaGrafico::inizializzaVociMenuModifica()
{
    QMenuBar* menuModifica=new QMenuBar();
    //la funzione si preoccupa della distruzione del menu giá presente
    setMenuBar(menuModifica);
    QAction* torna=new QAction("Torna al Grafico");
    menuModifica->addAction(torna);
    connect(torna,SIGNAL(triggered()),this,SLOT(mostraPrincipale()));
}

VistaGrafico::VistaGrafico(QWidget * parent, Grafico * g):QMainWindow(parent),
    grafico(g),layPrincipale(new QGridLayout),tabella(new QTableWidget()),areaGrafico(new QChartView)
{
    QWidget* centrale=new QWidget();
    setCentralWidget(centrale);
    centrale->setLayout(layPrincipale);
    inizializzaVociMenuPrincipale();
    layPrincipale->addWidget(tabella,0,0,Qt::AlignLeft);
    layPrincipale->addWidget(areaGrafico,0,1);


    creaBarre();
    creaTabella();
    tabella->setHidden(true);
    tabella->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);


    //connessioni
    connect(tabella,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(apriDialogoCella(QTableWidgetItem*)));
    connect(tabella,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(aggiornaValore(QTableWidgetItem*)));
    connect(this,SIGNAL(valoreTabellaCambiato(Grafico*,QString,QString,double)),parentWidget(),SIGNAL(aggiorna(Grafico*,QString,QString,double)));
}

void VistaGrafico::aggiornaValore(QTableWidgetItem* i)
{
    TableWidgetItem* cellaConv=static_cast<TableWidgetItem*>(i);
    QString nomeTraccia=cellaConv->getNomeTraccia();
    QString nomeCategoria=cellaConv->getNomeCategoria();
    QString testoCella=i->text();
    double nuovoValore=testoCella.toDouble();

    //se non é presente del testo ripristino il valore che era presente prima della cancellazione
    if(i->text()==""){
        TracciatoMultiplo* t=static_cast<TracciatoMultiplo*>(grafico);
        Traccia* tracc=t->getTraccia(nomeTraccia);
        QMap<QString,double> coordinate=tracc->getTraccia();
        double valorePrecedente=coordinate[nomeCategoria];
        i->setText(QString::number(valorePrecedente));
    }
    else
        emit valoreTabellaCambiato(grafico,nomeTraccia,nomeCategoria,nuovoValore);


}

void VistaGrafico::apriDialogoCella(QTableWidgetItem * cella)
{
    TableWidgetItem* cellaConv=static_cast<TableWidgetItem*>(cella);
//    VistaModificaGrafico* vistaModifica=new VistaModificaGrafico(this,cellaConv);
//    vistaModifica->exec();
    //recupero il valore della cella
    double valoreCella=cellaConv->text().toDouble();
    bool ok;
    double d = QInputDialog::getDouble(this,"Modifica Coordinata",
                                           "Valore:",valoreCella, -10000, 10000, 2, &ok,
                                           Qt::WindowFlags(), 1);
        if(ok){
            cellaConv->setText(QString::number(d));
            cellaConv->setData(Qt::EditRole,QVariant(d));
        }
}

void VistaGrafico::mostraBarre()
{
    creaBarre();
}

void VistaGrafico::mostraSpezzata()
{
    creaSpezzata();
}

Grafico *VistaGrafico::getGrafico() const
{
    return grafico;
}

QChart *VistaGrafico::getChart() const
{
    return areaGrafico->chart();
}

QMenu *VistaGrafico::getMenuPrincipale() const
{

}

QMenu *VistaGrafico::getMenuModifica() const
{

}

void VistaGrafico::mostraModifica()
{
    QMenuBar* menuModifica=new QMenuBar();
    setMenuBar(menuModifica);
    inizializzaVociMenuModifica();
    tabella->setHidden(false);
    areaGrafico->setHidden(true);
}

void VistaGrafico::mostraPrincipale()
{
    QMenuBar* menuPrincipale=new QMenuBar();
    setMenuBar(menuPrincipale);
    inizializzaVociMenuPrincipale();
    tabella->setHidden(true);
    areaGrafico->setHidden(false);
    QChart* chartAttuale=areaGrafico->chart();
    chartAttuale->aggiorna();

}
void VistaGrafico::creaTabella()
{
    //crea la tabella
    TracciatoMultiplo* gr=dynamic_cast<TracciatoMultiplo*>(grafico);
    QList<Traccia*> listaTracce= gr->getTracce();
    QList<QString> listaCategorie= gr->getCategorie();
    tabella->setColumnCount(listaTracce.count());
    tabella->setRowCount(listaCategorie.count());
    tabella->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    int y=0;
    for(auto i=listaCategorie.cbegin();i!=listaCategorie.cend();++i){
        QTableWidgetItem* oggetto=new QTableWidgetItem(*i);
        oggetto->setTextAlignment(Qt::AlignCenter);
        tabella->setVerticalHeaderItem(y,oggetto);
        y++;
    }
    y=0;
    int x=0;

    for(auto it=listaTracce.cbegin();it!=listaTracce.cend();++it){
        QTableWidgetItem* oggetto=new QTableWidgetItem((*it)->getNome());
        tabella->setHorizontalHeaderItem(y,oggetto);
            while(x<tabella->rowCount()){
                QTableWidgetItem* headerCategoria=tabella->verticalHeaderItem(x);
                QString nomeCategoria=headerCategoria->text();
                QString nomeTraccia=(*it)->getNome();
                QString testoCella=QString::number((*it)->getTraccia()[nomeCategoria]);
                TableWidgetItem* campo=new TableWidgetItem(testoCella,nomeTraccia,nomeCategoria);
                campo->setTextAlignment(Qt::AlignCenter);
                campo->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
                tabella->setItem(x,y,campo);
                x++;
            }
        x=0;
        y++;
        }
}


void VistaGrafico::creaBarre()
{
//    delete areaGrafico->chart();
    TracciatoMultiplo* g=dynamic_cast<TracciatoMultiplo*>(grafico);
    QList<Traccia*> listaTracce= g->getTracce();
    QList<QString> listaCategorie= g->getCategorie();
    QStringList categories;

    for(auto i=listaCategorie.cbegin();i!=listaCategorie.cend();++i)
        categories<<*i;

    QBarSeries *series = new QBarSeries();
    if(!listaTracce.isEmpty()){
    for(auto it=listaTracce.cbegin();it!=listaTracce.cend();++it){
        QBarSet *set = new QBarSet((**it).getNome());
        for(auto i=listaCategorie.cbegin();i!=listaCategorie.cend();++i){
            *set<<(*it)->getTraccia()[*i];
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
                   areaGrafico->setChart(chart);
                   areaGrafico->setRenderHint(QPainter::Antialiasing);
}

void VistaGrafico::creaSpezzata()
{
//    delete areaGrafico->chart();
    QChart *chart = new QChart();
    QLineSeries* series = new QLineSeries();
    series->setName("bilancio");
    series->setPointsVisible();
    series->setPointLabelsVisible();


    series->append(1,6.11);
    series->append(2,4.6);
    series->append(3,3);
    series->append(4,9.4);
    chart->addSeries(series);

    QLineSeries* series2 = new QLineSeries();
    series2->setName("perdite");
    QColor colore("red");
    series2->setColor(colore);
    series2->setPointsVisible();
    series2->setPointLabelsVisible();


    series2->append(0,7);
    series2->append(1,9.7);
    series2->append(2,2);
    series2->append(3,1);
    series2->append(4,5);
    chart->addSeries(series2);

    QCategoryAxis *axisX = new QCategoryAxis();
    axisX->append("Gennaio",1);
    axisX->append("Febbraio",2);
    axisX->append("Marzo",3);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    areaGrafico->setChart(chart);
    areaGrafico->setRenderHint(QPainter::Antialiasing);
}

