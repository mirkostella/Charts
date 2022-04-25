QT       += core gui
QT += charts
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    eccezionecaricamento.cpp \
    gestorecaricamento.cpp \
    listwidgetitem.cpp \
    main.cpp \
    grafico.cpp \
    mainwindow.cpp \
    modello.cpp \
    tablewidgetitem.cpp \
    traccia.cpp \
    tracciatomultiplo.cpp \
    vistagrafico.cpp \
    vistamodificagrafico.cpp \
    vistatracciatosingolo.cpp

HEADERS += \
    controller.h \
    eccezionecaricamento.h \
    gestorecaricamento.h \
    grafico.h \
    listwidgetitem.h \
    mainwindow.h \
    modello.h \
    tablewidgetitem.h \
    traccia.h \
    tracciatomultiplo.h \
    vistagrafico.h \
    vistamodificagrafico.h \
    vistatracciatosingolo.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
