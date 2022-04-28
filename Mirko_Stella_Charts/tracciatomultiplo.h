#ifndef TRACCIATOMULTIPLO_H
#define TRACCIATOMULTIPLO_H

#include "grafico.h"
#include "traccia.h"
#include <QList>

class TracciatoMultiplo:public Grafico
{
private:
    QList<Traccia*> tracce;
    QList<QString> categorie;
    //modifica l'oggetto puntato dal parametro formale
    void aggiustaDati(Traccia*);


public:
    TracciatoMultiplo();
    void aggiungiCategoria(const QString&);
    void eliminaCategoria(const QString&);
    void eliminaTraccia(Traccia* const);
    void eliminaTraccia(const QString&);
    QList<Traccia*> getTracce() const;
    Traccia *getTraccia(const QString&) const;
    QList<QString> getCategorie() const;
    QList<QString> getNomiTracciati() const;
    void aggiungiTraccia(const QString&);
    void aggiungiTraccia(Traccia *);

    void salva(QXmlStreamWriter&) const;
    TracciatoMultiplo *popola(const QDomElement&);

};
std::ostream& operator<<(std::ostream&,const TracciatoMultiplo&);
#endif // TRACCIATOMULTIPLO_H
