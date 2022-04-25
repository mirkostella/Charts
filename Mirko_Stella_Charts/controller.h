#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "modello.h"
#include "mainwindow.h"

class Controller:public QObject
{
    Q_OBJECT
private:
    Modello* modello;
    MainWindow* vistaPrincipale;

public:
    Controller();
public slots:
    void carica(const QString &);
    void salva(const QString &);
    void aggiorna(Grafico*,const QString&,const QString&,double);

signals:
    void visualizzaGrafici(const QList<Grafico*> &);
};

#endif // CONTROLLER_H
