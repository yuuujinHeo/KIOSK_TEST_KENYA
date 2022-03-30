/****************************************************************************
** Meta object code from reading C++ file 'OrderManage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../OrderManage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OrderManage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OrderManage_t {
    QByteArrayData data[14];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OrderManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OrderManage_t qt_meta_stringdata_OrderManage = {
    {
QT_MOC_LITERAL(0, 0, 11), // "OrderManage"
QT_MOC_LITERAL(1, 12, 14), // "addOrderToCart"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "menu_id"
QT_MOC_LITERAL(4, 36, 9), // "menu_name"
QT_MOC_LITERAL(5, 46, 19), // "removeOrderFromCart"
QT_MOC_LITERAL(6, 66, 3), // "num"
QT_MOC_LITERAL(7, 70, 9), // "clearCart"
QT_MOC_LITERAL(8, 80, 18), // "getCartMaxItemSize"
QT_MOC_LITERAL(9, 99, 15), // "getCartItemSize"
QT_MOC_LITERAL(10, 115, 15), // "getCartItemMenu"
QT_MOC_LITERAL(11, 131, 15), // "getCartItemName"
QT_MOC_LITERAL(12, 147, 19), // "getCartItemImageSrc"
QT_MOC_LITERAL(13, 167, 11) // "hasAnyOrder"

    },
    "OrderManage\0addOrderToCart\0\0menu_id\0"
    "menu_name\0removeOrderFromCart\0num\0"
    "clearCart\0getCartMaxItemSize\0"
    "getCartItemSize\0getCartItemMenu\0"
    "getCartItemName\0getCartItemImageSrc\0"
    "hasAnyOrder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrderManage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x02 /* Public */,
       5,    1,   64,    2, 0x02 /* Public */,
       7,    0,   67,    2, 0x02 /* Public */,
       8,    0,   68,    2, 0x02 /* Public */,
       9,    0,   69,    2, 0x02 /* Public */,
      10,    1,   70,    2, 0x02 /* Public */,
      11,    1,   73,    2, 0x02 /* Public */,
      12,    1,   76,    2, 0x02 /* Public */,
      13,    0,   79,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Int, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,    6,
    QMetaType::QString, QMetaType::Int,    6,
    QMetaType::QString, QMetaType::Int,    6,
    QMetaType::Bool,

       0        // eod
};

void OrderManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OrderManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->addOrderToCart((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->removeOrderFromCart((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->clearCart(); break;
        case 3: { int _r = _t->getCartMaxItemSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->getCartItemSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getCartItemMenu((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getCartItemName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getCartItemImageSrc((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->hasAnyOrder();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OrderManage::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_OrderManage.data,
    qt_meta_data_OrderManage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OrderManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrderManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OrderManage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OrderManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
