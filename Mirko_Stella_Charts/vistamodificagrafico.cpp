#include "vistamodificagrafico.h"

VistaModificaGrafico::VistaModificaGrafico(QWidget* parent,TableWidgetItem* c):QInputDialog(parent)
//    labelTraccia(c->getNomeTraccia(),this),labelCategoria(c->getNomeCategoria(),this)
//  ,pConferma("Applica"),pAnnulla("Annula")
{
    setWindowTitle("Modifica Coordinata");
    addAction(new QAction("ciao"));
    setCancelButtonText("Annulla");
    setOkButtonText("Applica");
    setInputMode(QInputDialog::DoubleInput);
    setDoubleMaximum(LONG_MAX);
    setLabelText("Valore");
//    resize(50,100);
//    nuovoValore.setText(c->text());
//    lay.addWidget(&labelTraccia);
//    lay.addWidget(&labelCategoria);
//    lay.addWidget(&nuovoValore);
//    QHBoxLayout* layPulsanti=new QHBoxLayout();
//    layPulsanti->addWidget(&pAnnulla);
//    layPulsanti->addWidget(&pConferma);
//    lay.addLayout(layPulsanti);
//    labelCategoria.setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
//    labelTraccia.setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
//    labelCategoria.setTextInteractionFlags(Qt::LinksAccessibleByMouse);
//    labelCategoria.setBuddy(&nuovoValore);

//    connect(&pAnnulla,SIGNAL(clicked()),this,SLOT(inviaNuovoValore()));

}
