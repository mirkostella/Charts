#include "controller.h"

Controller::Controller():modello(new Modello()),vistaPrincipale(new MainWindow)
{
    vistaPrincipale->show();
    connect(vistaPrincipale,SIGNAL(carica(QString)),this,SLOT(carica(QString)));
    connect(vistaPrincipale,SIGNAL(salva(QString)),this,SLOT(salva(QString)));
    connect(this,SIGNAL(visualizzaGrafici(QList<Grafico*>)),vistaPrincipale,SLOT(visualizzaElencoGrafici(QList<Grafico*>)));
}

void Controller::carica(const QString& path)
{
    modello->caricaDaFile(path);
    emit visualizzaGrafici(modello->getGrafici());
}

void Controller::salva(const QString & path)
{
    modello->salvaSuFile(path);
}

