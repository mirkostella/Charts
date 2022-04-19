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
    //aggiungere aggiungi tracciato passando il nome del tracciato
    primoc->aggiungiTracciato("Mirko");
    TracciatoSingolo* mirko=primoc->getTracce("Mirko");
    mirko->modificaCoordinata("legno",24);

    primoc->aggiungiTracciato("Nadia");
    primoc->aggiungiTracciato("Matteo");
    primoc->aggiungiTracciato("Giulia");
    primoc->aggiungiTracciato("Mariano");
    primoc->aggiungiCategoria("mais");
    primoc->aggiungiCategoria("carbone");
    primoc->aggiungiCategoria("acciaio");
    mirko->modificaCoordinata("carbone",12);
    mirko->modificaCoordinata("mais",87);
    TracciatoSingolo* giulia=primoc->getTracce("Giulia");
    giulia->modificaCoordinata("acciaio",45);
    TracciatoSingolo* nadia=primoc->getTracce("Nadia");
    nadia->modificaCoordinata("mais",33);
    giulia->aggiungiCategoria("oro");
    giulia->modificaCoordinata("argento",55);



    //grafico a tracciato singolo
    Grafico* secondo=new TracciatoSingolo();
    listaGrafici.push_back(secondo);
    TracciatoSingolo* secondoc=dynamic_cast<TracciatoSingolo*>(secondo);
    secondoc->aggiungiCategoria("covid19");
    secondoc->modificaCoordinata("covid19",20);
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
        if(tipo=="tracciato_singolo"){
            g=new TracciatoSingolo();
            g->popola(corrente);
        }
        if(tipo=="tracciato_multiplo"){
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

void Modello::stampa() const
{
    for(auto it=listaGrafici.cbegin();it!=listaGrafici.cend();++it){
       if(dynamic_cast<TracciatoSingolo*>(*it))
           cout<<*static_cast<TracciatoSingolo*>(*it);
       if(dynamic_cast<TracciatoMultiplo*>(*it))
           cout<<*static_cast<TracciatoMultiplo*>(*it);
    }
}



