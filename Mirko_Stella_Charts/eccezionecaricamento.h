#ifndef ECCEZIONECARICAMENTO_H
#define ECCEZIONECARICAMENTO_H

#include <QErrorMessage>

//usata da GestoreCaricamento
class EccezioneCaricamento:public QErrorMessage
{
    Q_OBJECT
private:
    QString titolo;
    QString messaggio;
public:
    EccezioneCaricamento(const QString&,const QString&);
    EccezioneCaricamento(const EccezioneCaricamento& e);
};

#endif // ECCEZIONECARICAMENTO_H
