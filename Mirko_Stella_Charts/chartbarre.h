#ifndef CHARTISTOGRAMMA_H
#define CHARTISTOGRAMMA_H

#include "chart.h"

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
using QtCharts::QBarSet;
using QtCharts::QBarSeries;
using QtCharts::QBarCategoryAxis;
using QtCharts::QValueAxis;
using QtCharts::QAbstractAxis;

#include "tracciatomultiplo.h"

class ChartBarre:public Chart
{
private:
    QBarCategoryAxis* asseX;
    QValueAxis* asseY;
    QBarSeries* serie;
    void impostaValori(Grafico*);
public:
    ChartBarre(Grafico*);
    void aggiornaChart(Grafico*);
};

#endif // CHARTISTOGRAMMA_H
