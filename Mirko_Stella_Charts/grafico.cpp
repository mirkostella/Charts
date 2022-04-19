#include "grafico.h"

Grafico::Grafico():nome("nome Default")
{

}

Grafico::Grafico(const QString & nomeGrafico):nome(nomeGrafico)
{

}

Grafico::~Grafico()
{

}

QString Grafico::getNome() const
{
    return nome;
}

void Grafico::setNome(const QString & nuovoNome)
{
    nome=nuovoNome;
}

