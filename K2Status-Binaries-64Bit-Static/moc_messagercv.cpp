/****************************************************************************
** Meta object code from reading C++ file 'messagercv.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/messagercv.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messagercv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MessageRcv_t {
    QByteArrayData data[12];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageRcv_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageRcv_t qt_meta_stringdata_MessageRcv = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MessageRcv"
QT_MOC_LITERAL(1, 11, 13), // "ReturnMessage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "data"
QT_MOC_LITERAL(4, 31, 15), // "CloseConnection"
QT_MOC_LITERAL(5, 47, 12), // "updatetxtbox"
QT_MOC_LITERAL(6, 60, 13), // "ListenMessage"
QT_MOC_LITERAL(7, 74, 11), // "QTcpSocket*"
QT_MOC_LITERAL(8, 86, 4), // "sock"
QT_MOC_LITERAL(9, 91, 7), // "Config*"
QT_MOC_LITERAL(10, 99, 5), // "Debug"
QT_MOC_LITERAL(11, 105, 13) // "sendHeartbeat"

    },
    "MessageRcv\0ReturnMessage\0\0data\0"
    "CloseConnection\0updatetxtbox\0ListenMessage\0"
    "QTcpSocket*\0sock\0Config*\0Debug\0"
    "sendHeartbeat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageRcv[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,
       5,    1,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   46,    2, 0x0a /* Public */,
      11,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 9, QMetaType::Bool,    8,    2,   10,
    QMetaType::Void,

       0        // eod
};

void MessageRcv::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageRcv *_t = static_cast<MessageRcv *>(_o);
        switch (_id) {
        case 0: _t->ReturnMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->CloseConnection(); break;
        case 2: _t->updatetxtbox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->ListenMessage((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< Config*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->sendHeartbeat(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
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
            typedef void (MessageRcv::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageRcv::updatetxtbox)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MessageRcv::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MessageRcv.data,
      qt_meta_data_MessageRcv,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MessageRcv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageRcv::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MessageRcv::ReturnMessage(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MessageRcv::CloseConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MessageRcv::updatetxtbox(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
