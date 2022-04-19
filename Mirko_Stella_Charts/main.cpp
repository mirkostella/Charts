#include "mainwindow.h"

#include <QApplication>
#include "tracciatosingolo.h"
#include "gestorecaricamento.h"
#include <iostream>
#include <map>
#include "controller.h"
using std::cout;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller c;

//C:/Users/stell/Desktop/cartellaProvaFile/nuovo.txt
    return a.exec();
}
