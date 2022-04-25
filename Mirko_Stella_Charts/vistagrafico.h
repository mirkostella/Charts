#ifndef VISTAGRAFICO_H
#define VISTAGRAFICO_H

#include <QDialog>
#include "tracciatomultiplo.h"
#include <QChartView>
#include <QtCharts/QChart>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QScrollArea>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QGridLayout>
#include <QTableWidget>
#include "tablewidgetitem.h"
#include "vistamodificagrafico.h"
#include <QInputDialog>
#include <QVariant>

#include <iostream>
using std::cout;
using std::endl;


using QtCharts::QCategoryAxis;
using QtCharts::QLineSeries;
using QtCharts::QPieSeries;
using QtCharts::QPieSlice;
using QtCharts::QValueAxis;
using QtCharts::QBarCategoryAxis;
using QtCharts::QBarSet;
using QtCharts::QBarSeries;
using QtCharts::QChartView;
using QtCharts::QChart;

//classe astratta che fornisce una rappresentazione base
class VistaGrafico:public QMainWindow
{
    Q_OBJECT
private:
    Grafico* grafico;
    QGridLayout* layPrincipale;
    QTableWidget* tabella;

    void creaTabella();
    void creaBarre();
    void creaSpezzata();

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
signals:
    //emesso quando cambia il valore di una cella nella tabella di modifica
    void valoreTabellaCambiato(Grafico*,const QString&,const QString&,double);

};

#endif // VISTAGRAFICO_H
