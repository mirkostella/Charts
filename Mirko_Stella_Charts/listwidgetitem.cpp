#include "listwidgetitem.h"

ListWidgetItem::ListWidgetItem(Grafico * g):QListWidgetItem(nullptr,1000),grafico(g)
{

}

Grafico *ListWidgetItem::getGrafico() const
{
    return grafico;
}
