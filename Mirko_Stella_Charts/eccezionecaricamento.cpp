#include "eccezionecaricamento.h"

EccezioneCaricamento::EccezioneCaricamento(const QString& t, const QString & m):titolo(t),messaggio(m){
    setWindowTitle(titolo);
    showMessage(messaggio);
    exec();
}

EccezioneCaricamento::EccezioneCaricamento(const EccezioneCaricamento &e):QErrorMessage()
{
    setWindowTitle(e.titolo);
    showMessage(e.messaggio);
}

