/****************************************************************************
** Meta object code from reading C++ file 'graphviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/graphviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphViewer_t {
    QByteArrayData data[6];
    char stringdata[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphViewer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphViewer_t qt_meta_stringdata_GraphViewer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GraphViewer"
QT_MOC_LITERAL(1, 12, 14), // "update_archive"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "QList<stninfo>"
QT_MOC_LITERAL(4, 43, 24), // "on_do_graph_temp_clicked"
QT_MOC_LITERAL(5, 68, 24) // "on_do_graph_volt_clicked"

    },
    "GraphViewer\0update_archive\0\0QList<stninfo>\0"
    "on_do_graph_temp_clicked\0"
    "on_do_graph_volt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphViewer *_t = static_cast<GraphViewer *>(_o);
        switch (_id) {
        case 0: _t->update_archive((*reinterpret_cast< QList<stninfo>(*)>(_a[1]))); break;
        case 1: _t->on_do_graph_temp_clicked(); break;
        case 2: _t->on_do_graph_volt_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject GraphViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GraphViewer.data,
      qt_meta_data_GraphViewer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GraphViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GraphViewer.stringdata))
        return static_cast<void*>(const_cast< GraphViewer*>(this));
    return QWidget::qt_metacast(_clname);
}

int GraphViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
