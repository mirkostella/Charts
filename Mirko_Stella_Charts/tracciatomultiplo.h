#ifndef TRACCIATOMULTIPLO_H
#define TRACCIATOMULTIPLO_H

#include "tracciatosingolo.h"
#include <QList>

class TracciatoMultiplo:public Grafico
{
private:
    QList<TracciatoSingolo*> tracce;
    QList<QString> categorie;
    //modifica l'oggetto puntato dal parametro formale
    void controlloCompatibilitaTracciato(TracciatoSingolo*) const;

public:
    TracciatoMultiplo();
    void aggiungiCategoria(const QString&);
    void eliminaCategoria(const QString&);
    QList<TracciatoSingolo*> getTracce() const;
    TracciatoSingolo *getTracce(const QString&) const;
    QList<QString> getCategorie() const;
    QList<QString> getNomiTracciati() const;
    void aggiungiTracciato(const QString&);
    void aggiungiTracciato(TracciatoSingolo *);
    void salva(QXmlStreamWriter&) const;
    TracciatoMultiplo *popola(const QDomElement&);

};
std::ostream& operator<<(std::ostream&,const TracciatoMultiplo&);
#endif // TRACCIATOMULTIPLO_H
