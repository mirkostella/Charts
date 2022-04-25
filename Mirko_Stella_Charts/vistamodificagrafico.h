#ifndef VISTAMODIFICAGRAFICO_H
#define VISTAMODIFICAGRAFICO_H

#include <QInputDialog>
#include <QLabel>
#include <QAction>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include "tablewidgetitem.h"
class VistaModificaGrafico:public QInputDialog
{
private:
//    QVBoxLayout lay;
//    QLabel labelTraccia;
//    QLabel labelCategoria;
//    QLineEdit nuovoValore;
//    QPushButton pConferma;
//    QPushButton pAnnulla;
public:
    VistaModificaGrafico(QWidget*,TableWidgetItem*);
//public slots:
//    void inviaNuovoValore();
//signals:
//    void Conferma();
};

#endif // VISTAMODIFICAGRAFICO_H
