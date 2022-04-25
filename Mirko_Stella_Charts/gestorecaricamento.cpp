#include "gestorecaricamento.h"

GestoreCaricamento::GestoreCaricamento(const QString &p):path(p)
{

}

Grafico *GestoreCaricamento::carica() const
{
 QFile f(path);
 if(!f.open(QFile::ReadOnly | QFile::Text))
    throw EccezioneCaricamento("Errore caricamento file","Impossibile aprire il file selezionato");
 QDomDocument documento;
 if(!documento.setContent(&f))
    throw EccezioneCaricamento("Errore caricamento file","Errore durante l'analisi del file selezionato");
 f.close();
 QDomNodeList listaElementoTipo=documento.elementsByTagName("radice");
 QDomNode nodoRadice=listaElementoTipo.item(0);
 QDomElement elementoRadice=nodoRadice.toElement();
 QDomElement elementoTipo=elementoRadice.firstChildElement("tipo");
 QString tipoGrafico=elementoTipo.text();
 std::cout<<tipoGrafico.toStdString();
 Grafico* g=nullptr;
 if(tipoGrafico=="tracciato"){
     g=new TracciatoMultiplo();
     g->popola(elementoRadice);
 }
return g;

}
