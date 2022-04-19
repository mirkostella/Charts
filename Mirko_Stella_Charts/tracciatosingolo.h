#ifndef TRACCIATOSINGOLO_H
#define TRACCIATOSINGOLO_H
//standard
#include <iostream>
using std::cout;
#include <QString>
#include <QMap>
//gerarchia
#include <grafico.h>

class TracciatoSingolo:public Grafico
{
private:
   QMap<QString,double> traccia;
public:
    TracciatoSingolo();
    TracciatoSingolo(const QString &);
    ~TracciatoSingolo();

    QMap<QString,double> getTraccia() const;
    QList<QString> getCategorie() const;
    void aggiungiCategoria(const QString&);
    void modificaCoordinata(const QString&,const double&);
    void eliminaCoordinata(const QString&);
    virtual double& operator[](const QString &);


    //virtual
    void salva(QXmlStreamWriter&) const;
    TracciatoSingolo* popola(const QDomElement&);
    void stampa() const;
};
std::ostream& operator<<(std::ostream&,const TracciatoSingolo&);

#endif // TRACCIATOSINGOLO_H
