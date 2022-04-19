#include "tracciatomultiplo.h"

void TracciatoMultiplo::controlloCompatibilitaTracciato(TracciatoSingolo * nuovoTracciato) const
{
    QString nomeT=nuovoTracciato->getNome();
    //nome grafico giá presente
    if(getNomiTracciati().contains(nomeT)){
        //eccezione nome giá presente
    }
    //aggiusto le categorie del nuovo tracciato o di quelli giá presenti
    for(auto it=categorie.cbegin();it!=categorie.cend();++it){
        if(!nuovoTracciato->getCategorie().contains(*it))
            nuovoTracciato->aggiungiCategoria(*it);
    }

}

TracciatoMultiplo::TracciatoMultiplo()
{


}
//ATTENZIONE!! da sistemare!!!!! se non ci sono elementi in questo modo non inserisce la categoria..
//fare un campo dati che contiene la lista delle categorie.
void TracciatoMultiplo::aggiungiCategoria(const QString & c)
{ 
    if(!categorie.contains(c)){
        categorie.push_back(c);
        for(auto it=tracce.begin();it!=tracce.end();++it)
            (*it)->aggiungiCategoria(c);
    }
    //else
        //categoria giá presente
}

void TracciatoMultiplo::eliminaCategoria(const QString & c)
{
    if(categorie.contains(c)){
        categorie.removeAll(c);
        for(auto it=tracce.begin();it!=tracce.end();++it)
            (*it)->eliminaCoordinata(c);
    }
    //else
        //categoria non presente
}

QList<TracciatoSingolo*> TracciatoMultiplo::getTracce() const
{
    return tracce;
}

//se non trova la traccia ritorna null
TracciatoSingolo* TracciatoMultiplo::getTracce(const QString & nomeTraccia) const
{
    bool trovato=false;
    TracciatoSingolo * ris=nullptr;
    for(auto it=tracce.cbegin();it!=tracce.cend() && !trovato;++it)
        if((*it)->getNome()==nomeTraccia){
            ris=*it;
            trovato=true;
        }

    return ris;

}

QList<QString> TracciatoMultiplo::getCategorie() const
{
    return categorie;

}

QList<QString> TracciatoMultiplo::getNomiTracciati() const
{
    QList<QString> listaNomi;
    for(auto it=tracce.cbegin();it!=tracce.cend();++it)
        listaNomi.push_back((*it)->getNome());
    return listaNomi;
}

//aggiunge un tracciato vuoto
void TracciatoMultiplo::aggiungiTracciato(const QString & nomeTracciato)
{
    TracciatoSingolo* nuovoTracciato=new TracciatoSingolo(nomeTracciato);
    controlloCompatibilitaTracciato(nuovoTracciato);
    tracce.push_back(nuovoTracciato);
}

void TracciatoMultiplo::aggiungiTracciato(TracciatoSingolo * nuovoTracciato)
{
    controlloCompatibilitaTracciato(nuovoTracciato);
    tracce.push_back(nuovoTracciato);
}

void TracciatoMultiplo::salva(QXmlStreamWriter & stream) const
{
    if(stream.device()){
        stream.writeTextElement("tipo","tracciato_multiplo");
        stream.writeTextElement("nome",getNome());
        stream.writeStartElement("dati");
        //ciclo che scrive i dati presenti in traccia
        for(auto it=tracce.cbegin();it!=tracce.cend();++it){
            stream.writeStartElement("traccia");
            (*it)->salva(stream);
            stream.writeEndElement();
        }
        stream.writeEndElement();//fine dati
    }
    else{
        //lo stream non é associato a nessun file
    }
}

TracciatoMultiplo *TracciatoMultiplo::popola(const QDomElement & inizio)
{
    QDomElement elementoNome=inizio.firstChildElement("nome");
    setNome(elementoNome.text());
    QDomNodeList listaTracce=inizio.elementsByTagName("traccia");
    for(int i=0;i<listaTracce.count();++i){
        TracciatoSingolo* nuovaTraccia=new TracciatoSingolo();
        QDomElement elementoTraccia=listaTracce.item(i).toElement();
        QDomElement nomeTraccia=elementoTraccia.firstChildElement("nome");
        nuovaTraccia->setNome(nomeTraccia.text());
        QDomNodeList listaNodoDati=elementoTraccia.elementsByTagName("dati");
        QDomNode nodoDati=listaNodoDati.item(0);
        QDomElement elementoDati=nodoDati.toElement();
        QDomNodeList listaDati=elementoDati.elementsByTagName("dato");
        //per ogni nodo
        for(int i=0;i<listaDati.count();++i){
            QDomElement elementoChiave=listaDati.item(i).firstChildElement("chiave");
            QDomElement elementoValore=listaDati.item(i).firstChildElement("valore");
            QString chiave=elementoChiave.text();
            double valore=elementoValore.text().toDouble();
            nuovaTraccia->aggiungiCategoria(chiave);
            aggiungiCategoria(chiave);
            nuovaTraccia->modificaCoordinata(chiave,valore);
        }
        tracce.append(nuovaTraccia);
    }
    return this;
}

std::ostream& operator<<(std::ostream& os,const TracciatoMultiplo& b){
    QList<TracciatoSingolo*> tracce= b.getTracce();
    for(auto it=tracce.cbegin();it!=tracce.cend();++it){
        os<<"nome:";
        os<<(*it)->getNome().toStdString();
        os<<std::endl;
        QMap<QString,double> t=(*it)->getTraccia();
        for(auto i=t.cbegin();i!=t.cend();++i){
            os<<"chiave:";
            os<<i.key().toStdString();
            os<<std::endl;
            os<<"valore:";
            os<<i.value();
            os<<std::endl;
            os<<std::endl;
        }
    }

    return os;
}
