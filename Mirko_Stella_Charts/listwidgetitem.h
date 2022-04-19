#ifndef LISTWIDGETITEM_H
#define LISTWIDGETITEM_H
#include <QListWidgetItem>
class Grafico;
class ListWidgetItem:public QListWidgetItem
{
private:
    Grafico* grafico;
public:
    ListWidgetItem(Grafico*);
    Grafico* getGrafico() const;
};

#endif // LISTWIDGETITEM_H
