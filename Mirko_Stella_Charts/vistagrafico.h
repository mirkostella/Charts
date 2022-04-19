#ifndef VISTAGRAFICO_H
#define VISTAGRAFICO_H

#include <QDialog>
#include "tracciatomultiplo.h"
#include "tracciatosingolo.h"
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
#include <iostream>
using std::cout;


using QtCharts::QPieSeries;
using QtCharts::QPieSlice;
using QtCharts::QValueAxis;
using QtCharts::QBarCategoryAxis;
using QtCharts::QBarSet;
using QtCharts::QBarSeries;
using QtCharts::QChartView;
using QtCharts::QChart;

//classe astratta che fornisce una rappresentazione base
class VistaGrafico:public QDialog
{
    Q_OBJECT
private:
    Grafico* grafico;
    QHBoxLayout* layPrincipale;
    QVBoxLayout* layGrafico;
    QVBoxLayout* layModifica;
    QPushButton* pulsanteModifica;
protected:
    QChartView* areaGrafico;
    QComboBox* selezioneRappresentazione;
    QChart* creaBarre();
    QChart* creaSpezzata();
public:
    VistaGrafico(Grafico*);
    void impostaGrafico(QChart*);
    Grafico* getGrafico() const;
    QChart* getChart() const;

public slots:
    virtual void cambiaRappresentazione(int);

};

#endif // VISTAGRAFICO_H
