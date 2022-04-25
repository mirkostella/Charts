/****************************************************************************
** Meta object code from reading C++ file 'vistagrafico.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Mirko_Stella_Charts/vistagrafico.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vistagrafico.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VistaGrafico_t {
    QByteArrayData data[13];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VistaGrafico_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VistaGrafico_t qt_meta_stringdata_VistaGrafico = {
    {
QT_MOC_LITERAL(0, 0, 12), // "VistaGrafico"
QT_MOC_LITERAL(1, 13, 21), // "valoreTabellaCambiato"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 8), // "Grafico*"
QT_MOC_LITERAL(4, 45, 14), // "aggiornaValore"
QT_MOC_LITERAL(5, 60, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(6, 78, 16), // "apriDialogoCella"
QT_MOC_LITERAL(7, 95, 29), // "inizializzaVociMenuPrincipale"
QT_MOC_LITERAL(8, 125, 27), // "inizializzaVociMenuModifica"
QT_MOC_LITERAL(9, 153, 11), // "mostraBarre"
QT_MOC_LITERAL(10, 165, 14), // "mostraSpezzata"
QT_MOC_LITERAL(11, 180, 14), // "mostraModifica"
QT_MOC_LITERAL(12, 195, 16) // "mostraPrincipale"

    },
    "VistaGrafico\0valoreTabellaCambiato\0\0"
    "Grafico*\0aggiornaValore\0QTableWidgetItem*\0"
    "apriDialogoCella\0inizializzaVociMenuPrincipale\0"
    "inizializzaVociMenuModifica\0mostraBarre\0"
    "mostraSpezzata\0mostraModifica\0"
    "mostraPrincipale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VistaGrafico[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   68,    2, 0x08 /* Private */,
       6,    1,   71,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString, QMetaType::Double,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VistaGrafico::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VistaGrafico *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valoreTabellaCambiato((*reinterpret_cast< Grafico*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 1: _t->aggiornaValore((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->apriDialogoCella((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->inizializzaVociMenuPrincipale(); break;
        case 4: _t->inizializzaVociMenuModifica(); break;
        case 5: _t->mostraBarre(); break;
        case 6: _t->mostraSpezzata(); break;
        case 7: _t->mostraModifica(); break;
        case 8: _t->mostraPrincipale(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VistaGrafico::*)(Grafico * , const QString & , const QString & , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VistaGrafico::valoreTabellaCambiato)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VistaGrafico::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_VistaGrafico.data,
    qt_meta_data_VistaGrafico,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VistaGrafico::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VistaGrafico::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VistaGrafico.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VistaGrafico::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void VistaGrafico::valoreTabellaCambiato(Grafico * _t1, const QString & _t2, const QString & _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
