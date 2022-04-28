#ifndef CHARTSPEZZATA_H
#define CHARTSPEZZATA_H

#include "chart.h"
#include "tracciatomultiplo.h"

#include <QtCharts/QLineSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
using QtCharts::QLineSeries;
using QtCharts::QBarCategoryAxis;
using QtCharts::QValueAxis;
using QtCharts::QCategoryAxis;

class ChartSpezzata:public Chart
{
private:
    void impostaValori(Grafico*);
public:
    ChartSpezzata(Grafico *);
    void aggiornaChart(Grafico*);
};

#endif // CHARTSPEZZATA_H
