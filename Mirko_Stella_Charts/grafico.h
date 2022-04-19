#ifndef GRAFICO_H
#define GRAFICO_H

//inclusioni QT
#include <QString>
#include <QFile>
#include <QSaveFile>
#include <QDomDocument>
#include <QXmlStreamWriter>

//classe base astratta
class Grafico
{
private:
    QString nome;
public:
    Grafico();
    Grafico(const QString&);
    virtual ~Grafico();
    QString getNome() const;
    void setNome(const QString&);
    virtual void salva(QXmlStreamWriter&) const=0;
    virtual Grafico* popola(const QDomElement&)=0;

};

#endif // GRAFICO_H
