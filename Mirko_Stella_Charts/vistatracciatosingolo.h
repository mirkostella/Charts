#ifndef VISTATRACCIATOSINGOLO_H
#define VISTATRACCIATOSINGOLO_H

#include "vistagrafico.h"
class VistaTracciatoSingolo:public VistaGrafico
{
private:
    void creaTorta();
    //overriding
public:
    VistaTracciatoSingolo(QWidget*,Grafico*);
public slots:
    void inizializzaVociMenuPrincipale();
    void mostraTorta();

};

#endif // VISTATRACCIATOSINGOLO_H
