#include "modello.h"

//note
//aggiungere il costruttore con il nome a grafico
Modello::Modello(){
    Grafico* primo=new TracciatoMultiplo();
    listaGrafici.push_back(primo);
    TracciatoMultiplo* primoc=dynamic_cast<TracciatoMultiplo*>(primo);
    primoc->aggiungiCategoria("legno");
    primoc->aggiungiCategoria("marmo");
    primoc->setNome("primo a tracciato multiplo");
//    //aggiungere aggiungi tracciato passando il nome del tracciato
    primoc->aggiungiTraccia("Mirko");
    Traccia* mirko=primoc->getTraccia("Mirko");
    mirko->modificaCoordinata("legno",24);

    primoc->aggiungiTraccia("Nadia");
    primoc->aggiungiTraccia("Matteo");
    primoc->aggiungiTraccia("Giulia");
    primoc->aggiungiTraccia("Mariano");
    primoc->aggiungiCategoria("mais");
    primoc->aggiungiCategoria("carbone");
    primoc->aggiungiCategoria("acciaio");
    mirko->modificaCoordinata("carbone",12);
    mirko->modificaCoordinata("mais",87);
    Traccia* giulia=primoc->getTraccia("Giulia");
    giulia->modificaCoordinata("acciaio",45);
    Traccia* nadia=primoc->getTraccia("Nadia");
    nadia->modificaCoordinata("mais",33);
    giulia->aggiungiCategoria("oro");
    giulia->modificaCoordinata("argento",55);
}

void Modello::caricaDaFile(const QString & path)
{
    QFile file(path);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        //file non aperto
    }
    QDomDocument documento;
    if(!documento.setContent(&file)){
        //parse del file fallito
    }
    listaGrafici.clear();
    QDomNodeList listaRadice=documento.elementsByTagName("radice");
    QDomNode nodoRadice=listaRadice.item(0);
    QDomElement elementoRadice=nodoRadice.toElement();
    QDomElement corrente=elementoRadice.firstChildElement("grafico");
    while(!corrente.isNull()){
        Grafico* g=nullptr;
        QString tipo=corrente.firstChildElement("tipo").text();
        if(tipo=="tracciato"){
            g=new TracciatoMultiplo();
            g->popola(corrente);
        }
        listaGrafici.push_front(g);
        corrente=corrente.nextSiblingElement("grafico");
    }
    file.close();
}

void Modello::salvaSuFile(const QString & path) const
{
    QSaveFile file(path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        //file non aperto
    }
    QXmlStreamWriter stream(&file);
    stream.writeStartDocument();
    stream.setAutoFormatting(true);
    stream.writeStartElement("radice");
    for(auto it=listaGrafici.cbegin();it!=listaGrafici.cend();++it){
        stream.writeStartElement("grafico");
        (*it)->salva(stream);
        stream.writeEndElement();
    }
    stream.writeEndDocument();//fine radice
    stream.writeEndDocument();//fine documento
    file.commit();
}

void Modello::aggiungiGrafico(Grafico * g)
{
    if(g){
        listaGrafici.push_front(g);
    }
    else{
        //grafico non trovato
    }

}

void Modello::eliminaGrafico(Grafico * g)
{
    bool sent=false;
    if(g){
    for(auto it=listaGrafici.begin();it!=listaGrafici.end() && !sent;++it){
        if(&**it==&*g){
            sent=true;
            listaGrafici.erase(it);
        }
    }
        if(!sent){
            //grafico non trovato
        }
    }
}

QList<Grafico*> Modello::getGrafici() const
{
    return listaGrafici;
}

void Modello::aggiornaValore(Grafico * g, const QString & t, const QString & c, double v)
{
    TracciatoMultiplo* conv=dynamic_cast<TracciatoMultiplo*>(g);
    Traccia* trac=conv->getTraccia(t);
    trac->modificaCoordinata(c,v);

}
