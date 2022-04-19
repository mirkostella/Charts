#ifndef VISTATRACCIATOSINGOLO_H
#define VISTATRACCIATOSINGOLO_H

#include "vistagrafico.h"
class VistaTracciatoSingolo:public VistaGrafico
{
private:
    QChart* creaTorta();
public:
    VistaTracciatoSingolo(Grafico*);
public slots:
    virtual void cambiaRappresentazione(int);

};

#endif // VISTATRACCIATOSINGOLO_H
