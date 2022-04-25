#ifndef TABLEWIDGETITEM_H
#define TABLEWIDGETITEM_H

#include <QTableWidgetItem>

class TableWidgetItem:public QTableWidgetItem
{
private:
    QString nomeTraccia;
    QString nomeCategoria;
public:
    TableWidgetItem(const QString&,const QString&,const QString&);
    void setNomeTraccia(const QString&);
    void setNomeCategoria(const QString&);
    QString getNomeTraccia() const;
    QString getNomeCategoria() const;
};

#endif // TABLEWIDGETITEM_H
