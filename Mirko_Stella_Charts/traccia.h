#ifndef TRACCIA_H
#define TRACCIA_H

#include <QString>
#include <QXmlStreamWriter>
#include <QDomElement>
#include <QMap>

class Traccia
{
private:
   QMap<QString,double> traccia;
   QString nome;
public:
    Traccia();
    Traccia(const QString &);
    ~Traccia();

    QMap<QString,double> getTraccia() const;
    QString getNome() const;
    void setNome(const QString&);
    QList<QString> getCategorie() const;
    void aggiungiCategoria(const QString&);
    void modificaCoordinata(const QString&,const double&);
    void eliminaCoordinata(const QString&);
    virtual double& operator[](const QString &);
    virtual void scriviSuStream(QXmlStreamWriter&) const;

    //inserisce in traccia i valori presi da un QDomElement
    virtual Traccia* popola(const QDomElement&);

};

#endif // TRACCIA_H
