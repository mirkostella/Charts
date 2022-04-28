QT       += core gui
QT += charts
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chart.cpp \
    chartbarre.cpp \
    chartspezzata.cpp \
    controller.cpp \
    eccezionecaricamento.cpp \
    gestorecaricamento.cpp \
    giallo.cpp \
    listwidgetitem.cpp \
    main.cpp \
    grafico.cpp \
    mainwindow.cpp \
    materiale.cpp \
    modello.cpp \
    rosso.cpp \
    tablewidgetitem.cpp \
    traccia.cpp \
    tracciatomultiplo.cpp \
    verde.cpp \
    vistagrafico.cpp \
    vistatracciatosingolo.cpp

HEADERS += \
    chart.h \
    chartbarre.h \
    chartspezzata.h \
    controller.h \
    eccezionecaricamento.h \
    gestorecaricamento.h \
    giallo.h \
    grafico.h \
    listwidgetitem.h \
    mainwindow.h \
    materiale.h \
    modello.h \
    rosso.h \
    tablewidgetitem.h \
    traccia.h \
    tracciatomultiplo.h \
    verde.h \
    vistagrafico.h \
    vistatracciatosingolo.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
