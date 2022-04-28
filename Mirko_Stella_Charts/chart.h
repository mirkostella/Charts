#ifndef CHART_H
#define CHART_H

#include <QtCharts/QChart>
using QtCharts::QChart;

class Grafico;

#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

using QtCharts::QPieSeries;
using QtCharts::QPieSlice;


//classe creata per fornire una funzione di  aggiornamento per ciascun chart
class Chart:public QChart
{
public:
    Chart();
    virtual void aggiornaChart(Grafico*)=0;
};

#endif // CHART_H
