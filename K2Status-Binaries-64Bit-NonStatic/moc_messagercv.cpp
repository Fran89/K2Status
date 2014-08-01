/****************************************************************************
** Meta object code from reading C++ file 'messagercv.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../K2Status-static-ImportExport/messagercv.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messagercv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MessageRcv_t {
    QByteArrayData data[13];
    char stringdata[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MessageRcv_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MessageRcv_t qt_meta_stringdata_MessageRcv = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 13),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 4),
QT_MOC_LITERAL(4, 31, 15),
QT_MOC_LITERAL(5, 47, 14),
QT_MOC_LITERAL(6, 62, 11),
QT_MOC_LITERAL(7, 74, 4),
QT_MOC_LITERAL(8, 79, 7),
QT_MOC_LITERAL(9, 87, 5),
QT_MOC_LITERAL(10, 93, 12),
QT_MOC_LITERAL(11, 106, 13),
QT_MOC_LITERAL(12, 120, 14)
    },
    "MessageRcv\0ReturnMessage\0\0data\0"
    "CloseConnection\0LastServerBeat\0"
    "QTcpSocket*\0sock\0Config*\0Debug\0"
    "updatetxtbox\0ListenMessage\0echo_Heartbeat\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageRcv[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       4,    0,   47,    2, 0x06,
       5,    3,   48,    2, 0x06,
      10,    1,   55,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    3,   58,    2, 0x0a,
      12,    3,   65,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, QMetaType::Bool,    7,    2,    9,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, QMetaType::Bool,    7,    2,    9,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, QMetaType::Bool,    7,    2,    9,

       0        // eod
};

void MessageRcv::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageRcv *_t = static_cast<MessageRcv *>(_o);
        switch (_id) {
        case 0: _t->ReturnMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->CloseConnection(); break;
        case 2: _t->LastServerBeat((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< Config*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->updatetxtbox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->ListenMessage((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< Config*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->echo_Heartbeat((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< Config*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 5:
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
            typedef void (MessageRcv::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageRcv::ReturnMessage)) {
                *result = 0;
            }
        }
        {
            typedef void (MessageRcv::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageRcv::CloseConnection)) {
                *result = 1;
            }
        }
        {
            typedef void (MessageRcv::*_t)(QTcpSocket * , Config * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageRcv::LastServerBeat)) {
                *result = 2;
            }
        }
        {
            typedef void (MessageRcv::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageRcv::updatetxtbox)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MessageRcv::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MessageRcv.data,
      qt_meta_data_MessageRcv,  qt_static_metacall, 0, 0}
};


const QMetaObject *MessageRcv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageRcv::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MessageRcv.stringdata))
        return static_cast<void*>(const_cast< MessageRcv*>(this));
    return QObject::qt_metacast(_clname);
}

int MessageRcv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MessageRcv::ReturnMessage(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MessageRcv::CloseConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MessageRcv::LastServerBeat(QTcpSocket * _t1, Config * _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MessageRcv::updatetxtbox(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
