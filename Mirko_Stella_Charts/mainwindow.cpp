#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),widgetCentrale(new QWidget),layCentrale(new QVBoxLayout),
      pulsanteCarica(new QPushButton("Carica")),pulsanteSalva(new QPushButton("Salva")),
      labelCategoria(new QLabel("Categoria",this)),labelValore(new QLabel("Valore",this)),
      categoria(new QLineEdit),valore(new QLineEdit),pulsanteInvio(new QPushButton("Invio")),esplora(new QFileDialog(this))
       ,listaGrafici(new QListWidget()),graficoDaVisualizzare(nullptr)
{
    setCentralWidget(widgetCentrale);
    widgetCentrale->setLayout(layCentrale);
    layCentrale->addWidget(pulsanteCarica);
    layCentrale->addWidget(pulsanteSalva);
    layCentrale->addWidget(labelCategoria);
    layCentrale->addWidget(categoria);
    layCentrale->addWidget(labelValore);
    layCentrale->addWidget(valore);
    layCentrale->addWidget(pulsanteInvio);

    connect(pulsanteCarica,SIGNAL(clicked()),this,SLOT(emettiCarica()));
    connect(pulsanteSalva,SIGNAL(clicked()),this,SLOT(emettiSalva()));
    connect(pulsanteInvio,SIGNAL(clicked()),this,SLOT(emettiInvio()));
}
MainWindow::~MainWindow()
{
}

void MainWindow::emettiCarica()
{
    esplora->setFileMode(QFileDialog::ExistingFile);
    esplora->setNameFilter(tr("Documento(*.xml *.txt)"));
    esplora->setWindowTitle("Carica");
    QDir dir("../");
    esplora->setDirectory(dir);
    if(esplora->exec()){
    QStringList listaPath=esplora->selectedFiles();
    QString path=listaPath.at(0);
    emit carica(path);
    }
}

void MainWindow::emettiSalva()
{
//    QFileDialog::getSaveFileName(this,tr("Salva file"),"../",
//                               tr("Documento(*.xml *.txt)"));
    esplora->setFileMode(QFileDialog::AnyFile);
    esplora->setNameFilter(tr("Documento(*.xml *.txt)"));
    esplora->setWindowTitle("Salva");
    QDir dir("../");
    esplora->setDirectory(dir);
    if(esplora->exec()){
        QStringList listaPath=esplora->selectedFiles();
        QString path=listaPath.at(0);
        emit salva(path);
    }
    //    emit salva(path);
}

void MainWindow::emettiInvio()
{
    emit invio(categoria->text(),valore->text());
}

void MainWindow::visualizzaElencoGrafici(const QList<Grafico *> & lista)
{
    for(auto it=lista.cbegin();it!=lista.cend();++it){
        ListWidgetItem* oggetto=new ListWidgetItem(*it);
        oggetto->setText((*it)->getNome());
        listaGrafici->addItem(oggetto);   
    }
    connect(listaGrafici,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(visualizzaGraficoSelezionato(QListWidgetItem*)));
    layCentrale->addWidget(listaGrafici);
}

void MainWindow::visualizzaGraficoSelezionato(QListWidgetItem *selezione)
{
    Grafico* daVisualizzare=static_cast<ListWidgetItem*>(selezione)->getGrafico();
    if(dynamic_cast<TracciatoMultiplo*>(daVisualizzare))
        graficoDaVisualizzare=new VistaGrafico(this,daVisualizzare);
//    if(dynamic_cast<TracciatoSingolo*>(daVisualizzare))
//        graficoDaVisualizzare=new VistaTracciatoSingolo(daVisualizzare);
    graficoDaVisualizzare->show();
}

