#ifndef GESTORECARICAMENTO_H
#define GESTORECARICAMENTO_H

//gerarchia
#include "tracciatomultiplo.h"
#include <iostream>
#include <QXmlParseException>

//standard
#include <map>

//QT
#include <QString>
#include <QFile>
#include <QtXml/QDomDocument>

#include "eccezionecaricamento.h"

using std::map;

class GestoreCaricamento
{
private:
    QString path;
public:
    GestoreCaricamento(const QString& p);
    Grafico* carica() const;
};

#endif // GESTORECARICAMENTO_H
