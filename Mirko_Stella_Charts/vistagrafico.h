#ifndef VISTAGRAFICO_H
#define VISTAGRAFICO_H

#include "tracciatomultiplo.h"
#include "chartbarre.h"
#include "chartspezzata.h"
#include "tablewidgetitem.h"

#include <QChartView>

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QScrollArea>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QGridLayout>
#include <QTableWidget>
#include <QInputDialog>
#include <QVariant>
#include <QHeaderView>
#include <QMessageBox>

#include <iostream>
using std::cout;
using std::endl;


using QtCharts::QChartView;

//classe astratta che fornisce una rappresentazione base
class VistaGrafico:public QMainWindow
{
    Q_OBJECT
private:
    Grafico* grafico;
    QGridLayout* layPrincipale;
    QTableWidget* tabella;
    QWidget* wPulsanti;

    void creaTabella();
    void creaBarre();
    void creaSpezzata();
    void aggiornaRappresentazione(Chart*);

protected:
    QChartView* areaGrafico;
public:
    VistaGrafico(QWidget*,Grafico*);
    Grafico* getGrafico() const;
    QChart* getChart() const;
    QMenu* getMenuPrincipale() const;
    QMenu* getMenuModifica() const;

private slots:
    void aggiornaValore(QTableWidgetItem *);
    void apriDialogoCella(QTableWidgetItem*);
public slots:
    void inizializzaVociMenuPrincipale();
    void inizializzaVociMenuModifica();
    void mostraBarre();
    void mostraSpezzata();
    void mostraModifica();
    void mostraPrincipale();
    void eliminaTraccia(int);
    void eliminaCategoria(int);
    void aggiungiTraccia();
    void aggiungiCategoria();
    //facoltatico
//    void evidenziaCoordinate(QTableWidgetItem*);
signals:
    //emesso quando cambia il valore di una cella nella tabella di modifica
    void valoreTabellaCambiato(Grafico*,const QString&,const QString&,double);
    void invioNuovaTraccia(const QString &);
    void invioNuovaCategoria(const QString &);

};

#endif // VISTAGRAFICO_H
