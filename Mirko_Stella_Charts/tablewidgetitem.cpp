#include "tablewidgetitem.h"

TableWidgetItem::TableWidgetItem(const QString& testoCella,const QString & nomeT, const QString & nomeC):
    QTableWidgetItem(testoCella),nomeTraccia(nomeT),nomeCategoria(nomeC)
{

}

void TableWidgetItem::setNomeTraccia(const QString& nuovoNome)
{
    nomeTraccia=nuovoNome;
}

void TableWidgetItem::setNomeCategoria(const QString & nuovoNome)
{
    nomeCategoria=nuovoNome;
}

QString TableWidgetItem::getNomeTraccia() const
{
    return nomeTraccia;
}

QString TableWidgetItem::getNomeCategoria() const
{
    return nomeCategoria;
}
