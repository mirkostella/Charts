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
    grafico(g),layPrincipale(new QGridLayout),tabella(nullptr),wPulsanti(new QWidget()),areaGrafico(new QChartView(nullptr,nullptr))
{
    QWidget* centrale=new QWidget();
    setCentralWidget(centrale);
    centrale->setLayout(layPrincipale);
    inizializzaVociMenuPrincipale();

    creaBarre();
    creaTabella();

    tabella->setHidden(true);
    layPrincipale->addWidget(tabella,0,1);
    layPrincipale->addWidget(areaGrafico,0,1);

    QPushButton* pAggiungiCategoria=new QPushButton("Aggiungi Categoria");
    QPushButton* pAggiungiTraccia=new QPushButton("Aggiungi Traccia");
    QHBoxLayout* layPulsantiAggiungi=new QHBoxLayout();
    layPulsantiAggiungi->addSpacing(50);
    layPulsantiAggiungi->addWidget(pAggiungiCategoria);
    layPulsantiAggiungi->addSpacing(50);
    layPulsantiAggiungi->addWidget(pAggiungiTraccia);
    layPulsantiAggiungi->addSpacing(50);
    wPulsanti->setLayout(layPulsantiAggiungi);
    wPulsanti->setHidden(true);
    layPrincipale->addWidget(wPulsanti,1,1);



    //connessioni
    connect(this,SIGNAL(valoreTabellaCambiato(Grafico*,QString,QString,double)),parentWidget(),SIGNAL(aggiorna(Grafico*,QString,QString,double)));



//    connect(tabella,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(evidenziaCoordinate(QTableWidgetItem*)));
      connect(pAggiungiCategoria,SIGNAL(clicked()),this,SLOT(aggiungiCategoria()));
      connect(pAggiungiTraccia,SIGNAL(clicked()),this,SLOT(aggiungiTraccia()));

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
    wPulsanti->setHidden(false);
    areaGrafico->setHidden(true);
}

void VistaGrafico::mostraPrincipale()
{
    QMenuBar* menuPrincipale=new QMenuBar();
    setMenuBar(menuPrincipale);
    inizializzaVociMenuPrincipale();
    tabella->setHidden(true);
    wPulsanti->setHidden(true);
    areaGrafico->setHidden(false);
    aggiornaRappresentazione(static_cast<Chart*>(areaGrafico->chart()));
}

void VistaGrafico::eliminaTraccia(int indice)
{
    QTableWidgetItem* cellaHeader=tabella->horizontalHeaderItem(indice);
    QMessageBox messaggio;
    messaggio.setIcon(QMessageBox::Question);
    QString nomeTraccia=cellaHeader->text();
    QString testoMessaggio="Eliminare la traccia "+nomeTraccia+"?";
    messaggio.setText(testoMessaggio);
    QPushButton *pulsanteElimina = messaggio.addButton(tr("Elimina"), QMessageBox::YesRole);
    QPushButton *pulsanteAnnulla = messaggio.addButton(tr("Annulla"), QMessageBox::RejectRole);

    messaggio.exec();

    if (messaggio.clickedButton() == pulsanteElimina){
        TracciatoMultiplo* tracc= static_cast<TracciatoMultiplo*>(grafico);
        tracc->eliminaTraccia(nomeTraccia);
        tabella->removeColumn(indice);
        tabella->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    }
}

void VistaGrafico::eliminaCategoria(int indice)
{
    QTableWidgetItem* cellaHeader=tabella->verticalHeaderItem(indice);
    QMessageBox messaggio;
    messaggio.setIcon(QMessageBox::Question);
    QString nomeCategoria=cellaHeader->text();
    QString testoMessaggio="Eliminare la categoria "+nomeCategoria+"?";
    messaggio.setText(testoMessaggio);
    QPushButton *pulsanteElimina = messaggio.addButton(tr("Elimina"), QMessageBox::YesRole);
    QPushButton *pulsanteAnnulla = messaggio.addButton(tr("Annulla"), QMessageBox::RejectRole);

    messaggio.exec();

    if (messaggio.clickedButton() == pulsanteElimina){
        TracciatoMultiplo* tracc= static_cast<TracciatoMultiplo*>(grafico);
        tracc->eliminaCategoria(nomeCategoria);
        tabella->removeRow(indice);
        tabella->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
}

void VistaGrafico::aggiungiTraccia()
{
    bool ok=false;
    QString nuovaTraccia=QInputDialog::getText(this,"Nuova Traccia","Nome Traccia",QLineEdit::Normal,"",&ok);

    if(ok && nuovaTraccia!=""){
        TracciatoMultiplo* tracc=static_cast<TracciatoMultiplo*>(grafico);
        tracc->aggiungiTraccia(nuovaTraccia);
        creaTabella();
    }

}

void VistaGrafico::aggiungiCategoria()
{
    bool ok=false;
    QString nuovaCategoria=QInputDialog::getText(this,"Nuova Categoria","Nome Categoria",QLineEdit::Normal,QString(),&ok);
    if(ok && nuovaCategoria!=""){
        TracciatoMultiplo* tracc=static_cast<TracciatoMultiplo*>(grafico);
        tracc->aggiungiCategoria(nuovaCategoria);
        creaTabella();
    }
}

//void VistaGrafico::evidenziaCoordinate(QTableWidgetItem * oggetto)
//{
//    QColor* colore=new QColor("red");
//    int riga=tabella->currentRow();
//    tabella->verticalHeaderItem(riga)->setBackgroundColor(*colore);




//}
void VistaGrafico::creaTabella()
{
    QTableWidget* tabellaPrec=tabella;
    tabella=new QTableWidget();
    layPrincipale->addWidget(tabella,0,1);
    if(tabellaPrec)
        delete tabellaPrec;

//    tabella->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    tabella->verticalHeader()->setSectionResizeMode(QHeaderView::Custom);
    tabella->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    tabella->horizontalHeader()->setMinimumSectionSize(70);
    tabella->horizontalHeader()->setSectionsClickable(true);

    tabella->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    tabella->verticalHeader()->setMinimumSectionSize(30);
    tabella->verticalHeader()->setMaximumWidth(100);
    tabella->verticalHeader()->setSectionsClickable(true);
    TracciatoMultiplo* gr=dynamic_cast<TracciatoMultiplo*>(grafico);
    QList<Traccia*> listaTracce= gr->getTracce();
    QList<QString> listaCategorie= gr->getCategorie();
    tabella->verticalHeader()->setSortIndicator(4,Qt::SortOrder::AscendingOrder);

    tabella->setColumnCount(listaTracce.count());
    tabella->setRowCount(listaCategorie.count());
    int y=0;
    for(auto i=listaCategorie.cbegin();i!=listaCategorie.cend();++i){
        QTableWidgetItem* oggetto=new QTableWidgetItem(*i);
        if(i->length()>15){
            oggetto->setTextAlignment(Qt::AlignLeft);
        }
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

    //connessioni
    connect(tabella,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(apriDialogoCella(QTableWidgetItem*)));
    connect(tabella,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(aggiornaValore(QTableWidgetItem*)));
    connect(tabella->horizontalHeader(),SIGNAL(sectionDoubleClicked(int)),this,SLOT(eliminaTraccia(int)));
    connect(tabella->verticalHeader(),SIGNAL(sectionDoubleClicked(int)),this,SLOT(eliminaCategoria(int)));
}


void VistaGrafico::creaBarre()
{
       QChart* chartPrecedente=areaGrafico->chart();
       ChartBarre* nuovoBarre=new ChartBarre(grafico);
       areaGrafico->setChart(nuovoBarre);
       delete chartPrecedente;
       nuovoBarre->legend()->setVisible(true);
       nuovoBarre->legend()->setAlignment(Qt::AlignBottom);
       areaGrafico->setRenderHint(QPainter::Antialiasing);
}

void VistaGrafico::aggiornaRappresentazione(Chart* c)
{
    c->aggiornaChart(grafico);
}

void VistaGrafico::creaSpezzata()
{
    QChart* chartPrecedente=areaGrafico->chart();
    ChartSpezzata* nuovoSpezzata=new ChartSpezzata(grafico);
    areaGrafico->setChart(nuovoSpezzata);
    delete chartPrecedente;
    nuovoSpezzata->legend()->setVisible(true);
    nuovoSpezzata->legend()->setAlignment(Qt::AlignBottom);
    areaGrafico->setRenderHint(QPainter::Antialiasing);
}

