/****************************************************************************
** Meta object code from reading C++ file 'k2status.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
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
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_K2Status_t {
    QByteArrayData data[22];
    char stringdata[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_K2Status_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_K2Status_t qt_meta_stringdata_K2Status = {
    {
QT_MOC_LITERAL(0, 0, 8), // "K2Status"
QT_MOC_LITERAL(1, 9, 12), // "update_gview"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "QList<stninfo>"
QT_MOC_LITERAL(4, 38, 12), // "start_listen"
QT_MOC_LITERAL(5, 51, 11), // "QTcpSocket*"
QT_MOC_LITERAL(6, 63, 7), // "Config*"
QT_MOC_LITERAL(7, 71, 10), // "Dialog_off"
QT_MOC_LITERAL(8, 82, 7), // "Config&"
QT_MOC_LITERAL(9, 90, 5), // "TestC"
QT_MOC_LITERAL(10, 96, 13), // "has_read_data"
QT_MOC_LITERAL(11, 110, 12), // "has_read_tcp"
QT_MOC_LITERAL(12, 123, 7), // "Message"
QT_MOC_LITERAL(13, 131, 11), // "tcpmsgtobox"
QT_MOC_LITERAL(14, 143, 3), // "upd"
QT_MOC_LITERAL(15, 147, 7), // "killTCP"
QT_MOC_LITERAL(16, 155, 33), // "on_actionAdd_Connection_trigg..."
QT_MOC_LITERAL(17, 189, 23), // "on_actionQuit_triggered"
QT_MOC_LITERAL(18, 213, 29), // "on_actionDebug_Mode_triggered"
QT_MOC_LITERAL(19, 243, 16), // "UpdateTimeColors"
QT_MOC_LITERAL(20, 260, 25), // "on_action_Graph_triggered"
QT_MOC_LITERAL(21, 286, 24) // "on_actionAbout_triggered"

    },
    "K2Status\0update_gview\0\0QList<stninfo>\0"
    "start_listen\0QTcpSocket*\0Config*\0"
    "Dialog_off\0Config&\0TestC\0has_read_data\0"
    "has_read_tcp\0Message\0tcpmsgtobox\0upd\0"
    "killTCP\0on_actionAdd_Connection_triggered\0"
    "on_actionQuit_triggered\0"
    "on_actionDebug_Mode_triggered\0"
    "UpdateTimeColors\0on_action_Graph_triggered\0"
    "on_actionAbout_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_K2Status[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    3,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   89,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    1,   93,    2, 0x0a /* Public */,
      13,    1,   96,    2, 0x0a /* Public */,
      15,    0,   99,    2, 0x0a /* Public */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,
      18,    0,  102,    2, 0x08 /* Private */,
      19,    0,  103,    2, 0x08 /* Private */,
      20,    0,  104,    2, 0x08 /* Private */,
      21,    0,  105,    2, 0x08 /* Private */,

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
        case 12: _t->on_actionAbout_triggered(); break;
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
      qt_meta_data_K2Status,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *K2Status::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *K2Status::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void K2Status::update_gview(QList<stninfo> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void K2Status::start_listen(QTcpSocket * _t1, Config * _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
