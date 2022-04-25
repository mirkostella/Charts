#ifndef MODELLO_H
#define MODELLO_H


#include "tracciatomultiplo.h"
#include "gestorecaricamento.h"

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
    void aggiornaValore(Grafico*,const QString&,const QString&,double);

};

#endif // MODELLO_H
