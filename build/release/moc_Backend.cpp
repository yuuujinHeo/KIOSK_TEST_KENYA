/****************************************************************************
** Meta object code from reading C++ file 'Backend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Backend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Backend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Backend_t {
    QByteArrayData data[18];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Backend_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Backend_t qt_meta_stringdata_Backend = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Backend"
QT_MOC_LITERAL(1, 8, 7), // "onTimer"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 7), // "getYear"
QT_MOC_LITERAL(4, 25, 8), // "getMonth"
QT_MOC_LITERAL(5, 34, 6), // "getDay"
QT_MOC_LITERAL(6, 41, 7), // "getDate"
QT_MOC_LITERAL(7, 49, 16), // "isRobotConnected"
QT_MOC_LITERAL(8, 66, 14), // "getMenuInfoKor"
QT_MOC_LITERAL(9, 81, 4), // "type"
QT_MOC_LITERAL(10, 86, 3), // "num"
QT_MOC_LITERAL(11, 90, 16), // "getMenuInfoImage"
QT_MOC_LITERAL(12, 107, 8), // "newOrder"
QT_MOC_LITERAL(13, 116, 10), // "getSoldOut"
QT_MOC_LITERAL(14, 127, 4), // "menu"
QT_MOC_LITERAL(15, 132, 16), // "getOptionSoldOut"
QT_MOC_LITERAL(16, 149, 11), // "getItemcode"
QT_MOC_LITERAL(17, 161, 5) // "_menu"

    },
    "Backend\0onTimer\0\0getYear\0getMonth\0"
    "getDay\0getDate\0isRobotConnected\0"
    "getMenuInfoKor\0type\0num\0getMenuInfoImage\0"
    "newOrder\0getSoldOut\0menu\0getOptionSoldOut\0"
    "getItemcode\0_menu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Backend[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   75,    2, 0x02 /* Public */,
       4,    0,   76,    2, 0x02 /* Public */,
       5,    0,   77,    2, 0x02 /* Public */,
       6,    0,   78,    2, 0x02 /* Public */,
       7,    0,   79,    2, 0x02 /* Public */,
       8,    2,   80,    2, 0x02 /* Public */,
      11,    2,   85,    2, 0x02 /* Public */,
      12,    0,   90,    2, 0x02 /* Public */,
      13,    1,   91,    2, 0x02 /* Public */,
      15,    1,   94,    2, 0x02 /* Public */,
      16,    1,   97,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QDate,
    QMetaType::Bool,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,    9,   10,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::QString, QMetaType::QString,   17,

       0        // eod
};

void Backend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Backend *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimer(); break;
        case 1: { int _r = _t->getYear();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->getMonth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->getDay();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { QDate _r = _t->getDate();
            if (_a[0]) *reinterpret_cast< QDate*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->isRobotConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getMenuInfoKor((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getMenuInfoImage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->newOrder(); break;
        case 9: { bool _r = _t->getSoldOut((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->getOptionSoldOut((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->getItemcode((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Backend::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Backend.data,
    qt_meta_data_Backend,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Backend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Backend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Backend.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Backend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
