#ifndef MODELLO_H
#define MODELLO_H

#include "tracciatosingolo.h"
#include "tracciatomultiplo.h"
#include "gestorecaricamento.h"

#include <QString>
#include <QList>
using std::list;

class Modello
{
private:
    QList<Grafico*> listaGrafici;
public:
    Modello();
    void caricaDaFile(const QString&);
    void salvaSuFile(const QString&) const;
    void aggiungiGrafico(Grafico*);
    void eliminaGrafico(Grafico*);
    QList<Grafico*> getGrafici() const;
    void stampa() const;
};

#endif // MODELLO_H
