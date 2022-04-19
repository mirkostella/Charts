#include "tracciatosingolo.h"

TracciatoSingolo::TracciatoSingolo(){}

TracciatoSingolo::TracciatoSingolo(const QString & nome):Grafico(nome)
{

}

TracciatoSingolo::~TracciatoSingolo()
{

}

QMap<QString,double> TracciatoSingolo::getTraccia() const
{
    return traccia;
}

QList<QString> TracciatoSingolo::getCategorie() const
{
    return traccia.keys();
}

void TracciatoSingolo::aggiungiCategoria(const QString & c)
{
    if(!traccia.contains(c))
        traccia.insert(c,0);
    else
    {
        //categoria giá presente
    }
}

//se la chiave é presente modifica il corrispettivo valore altrimenti inserisci un nuovo elemento
void TracciatoSingolo::modificaCoordinata(const QString & c, const double & nuovoValore)
{
   if(traccia.contains(c))
        traccia.insert(c,nuovoValore);
   else{
       //categoria non presente
   }
}

void TracciatoSingolo::eliminaCoordinata(const QString& chiave)
{
    traccia.remove(chiave);
}

void TracciatoSingolo::salva(QXmlStreamWriter& stream) const
{

    if(stream.device()){
        stream.writeTextElement("tipo","tracciato_singolo");
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
    }
    else{
        //lo stream non é associato a nessun file
    }
}

TracciatoSingolo* TracciatoSingolo::popola(const QDomElement & inizio)
{
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
std::ostream& operator<<(std::ostream& os,const TracciatoSingolo& b){
    os<<"nome:";
    os<<b.getNome().toStdString();
    os<<std::endl;
    QMap<QString,double> t=b.getTraccia();
    for(auto it=t.cbegin();it!=t.cend();++it){
        os<<"chiave:";
        os<<it.key().toStdString();
        os<<std::endl;
        os<<"valore:";
        os<<it.value();
        os<<std::endl;
        os<<std::endl;
    }
    return os;
}
double &TracciatoSingolo::operator [](const QString& key){
    return traccia[key];
}
