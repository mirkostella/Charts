#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <grafico.h>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFileDialog>
#include <QLabel>
#include <iostream>
#include <QListWidgetItem>
#include "listwidgetitem.h"
#include "vistagrafico.h"
#include "vistatracciatosingolo.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

    QWidget* widgetCentrale;
    QVBoxLayout* layCentrale;
    QPushButton* pulsanteCarica;
    QPushButton* pulsanteSalva;
    QLabel* labelCategoria;
    QLabel* labelValore;
    QLineEdit* categoria;
    QLineEdit* valore;
    QPushButton* pulsanteInvio;
    QFileDialog* esplora;
    QListWidget* listaGrafici;
    VistaGrafico* graficoDaVisualizzare;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    //privato per impedire che venga passato un QListWidgetItem che non sia un ListWidgetItem
    void visualizzaGraficoSelezionato(QListWidgetItem *);
public slots:
    void emettiCarica();
    void emettiSalva();
    void emettiInvio();
    void visualizzaElencoGrafici(const QList<Grafico*>&);
signals:
    void carica(const QString &);
    void salva(const QString &);
    void invio(const QString &,const QString &);
};
#endif // MAINWINDOW_H
