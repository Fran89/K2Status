/****************************************************************************
** Meta object code from reading C++ file 'k2status.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/k2status.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'k2status.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_K2Status_t {
    QByteArrayData data[21];
    char stringdata[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_K2Status_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_K2Status_t qt_meta_stringdata_K2Status = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 12),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 14),
QT_MOC_LITERAL(4, 38, 12),
QT_MOC_LITERAL(5, 51, 11),
QT_MOC_LITERAL(6, 63, 7),
QT_MOC_LITERAL(7, 71, 10),
QT_MOC_LITERAL(8, 82, 7),
QT_MOC_LITERAL(9, 90, 5),
QT_MOC_LITERAL(10, 96, 13),
QT_MOC_LITERAL(11, 110, 12),
QT_MOC_LITERAL(12, 123, 7),
QT_MOC_LITERAL(13, 131, 11),
QT_MOC_LITERAL(14, 143, 3),
QT_MOC_LITERAL(15, 147, 7),
QT_MOC_LITERAL(16, 155, 33),
QT_MOC_LITERAL(17, 189, 23),
QT_MOC_LITERAL(18, 213, 29),
QT_MOC_LITERAL(19, 243, 16),
QT_MOC_LITERAL(20, 260, 25)
    },
    "K2Status\0update_gview\0\0QList<stninfo>\0"
    "start_listen\0QTcpSocket*\0Config*\0"
    "Dialog_off\0Config&\0TestC\0has_read_data\0"
    "has_read_tcp\0Message\0tcpmsgtobox\0upd\0"
    "killTCP\0on_actionAdd_Connection_triggered\0"
    "on_actionQuit_triggered\0"
    "on_actionDebug_Mode_triggered\0"
    "UpdateTimeColors\0on_action_Graph_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_K2Status[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06,
       4,    3,   77,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    1,   84,    2, 0x0a,
      10,    0,   87,    2, 0x0a,
      11,    1,   88,    2, 0x0a,
      13,    1,   91,    2, 0x0a,
      15,    0,   94,    2, 0x0a,
      16,    0,   95,    2, 0x08,
      17,    0,   96,    2, 0x08,
      18,    0,   97,    2, 0x08,
      19,    0,   98,    2, 0x08,
      20,    0,   99,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 6, QMetaType::Bool,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void K2Status::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        K2Status *_t = static_cast<K2Status *>(_o);
        switch (_id) {
        case 0: _t->update_gview((*reinterpret_cast< QList<stninfo>(*)>(_a[1]))); break;
        case 1: _t->start_listen((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< Config*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->Dialog_off((*reinterpret_cast< Config(*)>(_a[1]))); break;
        case 3: _t->has_read_data(); break;
        case 4: _t->has_read_tcp((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->tcpmsgtobox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->killTCP(); break;
        case 7: _t->on_actionAdd_Connection_triggered(); break;
        case 8: _t->on_actionQuit_triggered(); break;
        case 9: _t->on_actionDebug_Mode_triggered(); break;
        case 10: _t->UpdateTimeColors(); break;
        case 11: _t->on_action_Graph_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (K2Status::*_t)(QList<stninfo> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&K2Status::update_gview)) {
                *result = 0;
            }
        }
        {
            typedef void (K2Status::*_t)(QTcpSocket * , Config * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&K2Status::start_listen)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject K2Status::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_K2Status.data,
      qt_meta_data_K2Status,  qt_static_metacall, 0, 0}
};


const QMetaObject *K2Status::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *K2Status::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_K2Status.stringdata))
        return static_cast<void*>(const_cast< K2Status*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int K2Status::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void K2Status::update_gview(QList<stninfo> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void K2Status::start_listen(QTcpSocket * _t1, Config * _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
