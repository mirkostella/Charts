#include "tracciatomultiplo.h"

void TracciatoMultiplo::aggiustaDati(Traccia * nuovaTraccia)
{
    QString nomeT=nuovaTraccia->getNome();
    //nome grafico giá presente
    if(getNomiTracciati().contains(nomeT)){
        //eccezione nome giá presente
    }
    QList<QString> categorieNuovaTraccia=nuovaTraccia->getCategorie();
    //aggiungo le categorie mancanti alla nuova traccia
    for(auto it=categorie.cbegin();it!=categorie.cend();++it){
        if(!nuovaTraccia->getCategorie().contains(*it))
            nuovaTraccia->aggiungiCategoria(*it);
    }
    //aggiungo alle categorie le categorie della nuova traccia che non sono ancora presenti nel tracciato
    for(auto it=categorieNuovaTraccia.cbegin();it!=categorieNuovaTraccia.cend();++it){
        if(!categorie.contains(*it))
            aggiungiCategoria(*it);
    }

}

TracciatoMultiplo::TracciatoMultiplo()
{


}

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

QList<Traccia*> TracciatoMultiplo::getTracce() const
{
    return tracce;
}

//se non trova la traccia ritorna null
Traccia* TracciatoMultiplo::getTraccia(const QString & nomeTraccia) const
{
    bool trovato=false;
    Traccia * ris=nullptr;
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
void TracciatoMultiplo::aggiungiTraccia(const QString & nomeTraccia)
{
    Traccia* nuovaTraccia=new Traccia(nomeTraccia);
    aggiustaDati(nuovaTraccia);
    tracce.push_back(nuovaTraccia);
}

void TracciatoMultiplo::aggiungiTraccia(Traccia * nuovaTraccia)
{
    aggiustaDati(nuovaTraccia);
    tracce.push_back(nuovaTraccia);
}

void TracciatoMultiplo::salva(QXmlStreamWriter & stream) const
{
    if(stream.device()){
        stream.writeTextElement("tipo","tracciato");
        stream.writeTextElement("nome",getNome());
        stream.writeStartElement("dati");
        //ciclo che scrive i dati presenti in tracce
        for(auto it=tracce.cbegin();it!=tracce.cend();++it){
            (*it)->scriviSuStream(stream);
        }
        stream.writeEndElement();//fine dati
        stream.writeEndElement();//fine tracciato
    }
    else{
        //lo stream non é associato a nessun file
    }
}

//popola con i dati contenuti all'interno del tag inizio
TracciatoMultiplo *TracciatoMultiplo::popola(const QDomElement & inizio)
{
    QDomElement elementoNome=inizio.firstChildElement("nome");
    setNome(elementoNome.text());
    QDomNodeList listaTracce=inizio.elementsByTagName("traccia");
    for(int i=0;i<listaTracce.count();++i){
        Traccia* nuovaTraccia=new Traccia();
        QDomElement elementoNuovaTraccia=listaTracce.at(i).toElement();
        nuovaTraccia->popola(elementoNuovaTraccia);
        aggiungiTraccia(nuovaTraccia);
    }
    return this;
}







