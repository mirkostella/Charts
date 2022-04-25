#include "traccia.h"

Traccia::Traccia():nome("senza nome"){}

Traccia::Traccia(const QString & n):nome(n)
{

}

Traccia::~Traccia()
{

}

QMap<QString,double> Traccia::getTraccia() const
{
    return traccia;
}

QString Traccia::getNome() const
{
    return nome;
}

void Traccia::setNome(const QString & nuovoNome)
{
    nome=nuovoNome;
}

QList<QString> Traccia::getCategorie() const
{
    return traccia.keys();
}

void Traccia::aggiungiCategoria(const QString & c)
{
    if(!traccia.contains(c))
        traccia.insert(c,0);
    else
    {
        //categoria giá presente
    }
}

//se la chiave é presente modifica il corrispettivo valore altrimenti inserisci un nuovo elemento
void Traccia::modificaCoordinata(const QString & c, const double & nuovoValore)
{
   if(traccia.contains(c))
        traccia.insert(c,nuovoValore);
   else{
       //categoria non presente
   }
}

void Traccia::eliminaCoordinata(const QString& chiave)
{
    traccia.remove(chiave);
}



double &Traccia::operator [](const QString& key){
    return traccia[key];
}
void Traccia::scriviSuStream(QXmlStreamWriter& stream) const
{

    if(stream.device()){
        stream.writeStartElement("traccia");
        stream.writeTextElement("nome",getNome());
        stream.writeStartElement("dati");
        //ciclo che scrive i dati presenti in traccia
        for(auto it=traccia.cbegin();it!=traccia.cend();++it){
            stream.writeStartElement("dato");
            stream.writeTextElement("chiave",it.key());
            stream.writeTextElement("valore",QString::number(it.value()));
            stream.writeEndElement();
        }
        stream.writeEndElement();//fine dati
        stream.writeEndElement();//fine traccia
    }
    else{
        //lo stream non é associato a nessun file
    }
}
Traccia* Traccia::popola(const QDomElement & inizio)
{
    //parse dell'elemento che ne controlla il formato
    QDomElement elementoNome=inizio.firstChildElement("nome");
    setNome(elementoNome.text());
    QDomNodeList listaNodoDati=inizio.elementsByTagName("dati");
    QDomNode nodoDati=listaNodoDati.item(0);
    QDomElement elementoDati=nodoDati.toElement();
    QDomNodeList listaDati=elementoDati.elementsByTagName("dato");
    //per ogni nodo
    for(int i=0;i<listaDati.count();++i){
        QDomElement elementoChiave=listaDati.item(i).firstChildElement("chiave");
        QDomElement elementoValore=listaDati.item(i).firstChildElement("valore");
        QString chiave=elementoChiave.text();
        double valore=elementoValore.text().toDouble();
        traccia.insert(chiave,valore);
    }
    return this;
}
