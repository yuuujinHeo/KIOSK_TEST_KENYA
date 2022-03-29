/****************************************************************************
** Meta object code from reading C++ file 'Backend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
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
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Backend_t {
    QByteArrayData data[81];
    char stringdata0[1054];
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
QT_MOC_LITERAL(3, 17, 12), // "doPrintagain"
QT_MOC_LITERAL(4, 30, 5), // "index"
QT_MOC_LITERAL(5, 36, 18), // "setOrderOnSalesLog"
QT_MOC_LITERAL(6, 55, 4), // "date"
QT_MOC_LITERAL(7, 60, 8), // "addLogin"
QT_MOC_LITERAL(8, 69, 4), // "user"
QT_MOC_LITERAL(9, 74, 5), // "login"
QT_MOC_LITERAL(10, 80, 12), // "getCardState"
QT_MOC_LITERAL(11, 93, 14), // "reloadSaleData"
QT_MOC_LITERAL(12, 108, 13), // "reloadContent"
QT_MOC_LITERAL(13, 122, 3), // "idx"
QT_MOC_LITERAL(14, 126, 17), // "reloadContentLast"
QT_MOC_LITERAL(15, 144, 20), // "reloadCheckinContent"
QT_MOC_LITERAL(16, 165, 15), // "getSaleDateSize"
QT_MOC_LITERAL(17, 181, 13), // "getSaleDateAt"
QT_MOC_LITERAL(18, 195, 1), // "i"
QT_MOC_LITERAL(19, 197, 14), // "getContentSize"
QT_MOC_LITERAL(20, 212, 13), // "getContentPin"
QT_MOC_LITERAL(21, 226, 14), // "getContentTime"
QT_MOC_LITERAL(22, 241, 14), // "getContentMenu"
QT_MOC_LITERAL(23, 256, 15), // "getContentPrice"
QT_MOC_LITERAL(24, 272, 18), // "getContentCardComp"
QT_MOC_LITERAL(25, 291, 17), // "getContentCardNum"
QT_MOC_LITERAL(26, 309, 16), // "getContentAppNum"
QT_MOC_LITERAL(27, 326, 18), // "getContentTrandate"
QT_MOC_LITERAL(28, 345, 18), // "getContentIsCancel"
QT_MOC_LITERAL(29, 364, 14), // "getCheckDBSize"
QT_MOC_LITERAL(30, 379, 14), // "getCheckDBDate"
QT_MOC_LITERAL(31, 394, 14), // "getCheckDBTime"
QT_MOC_LITERAL(32, 409, 14), // "getCheckDBUser"
QT_MOC_LITERAL(33, 424, 15), // "getCheckDBLogin"
QT_MOC_LITERAL(34, 440, 17), // "getReportTotalAmt"
QT_MOC_LITERAL(35, 458, 17), // "getReportTotalNum"
QT_MOC_LITERAL(36, 476, 18), // "getReportRefundAmt"
QT_MOC_LITERAL(37, 495, 18), // "getReportRefundNum"
QT_MOC_LITERAL(38, 514, 18), // "getReportPerAmount"
QT_MOC_LITERAL(39, 533, 17), // "getReportMenuSize"
QT_MOC_LITERAL(40, 551, 17), // "getReportMenuName"
QT_MOC_LITERAL(41, 569, 16), // "getReportMenuAmt"
QT_MOC_LITERAL(42, 586, 16), // "getReportMenuNum"
QT_MOC_LITERAL(43, 603, 5), // "_menu"
QT_MOC_LITERAL(44, 609, 21), // "getReportMenuTotalNum"
QT_MOC_LITERAL(45, 631, 17), // "getReportCardSize"
QT_MOC_LITERAL(46, 649, 17), // "getReportCardName"
QT_MOC_LITERAL(47, 667, 15), // "getReportCardGB"
QT_MOC_LITERAL(48, 683, 16), // "getReportCardAmt"
QT_MOC_LITERAL(49, 700, 16), // "getReportCardNum"
QT_MOC_LITERAL(50, 717, 7), // "getYear"
QT_MOC_LITERAL(51, 725, 8), // "getMonth"
QT_MOC_LITERAL(52, 734, 6), // "getDay"
QT_MOC_LITERAL(53, 741, 7), // "getDate"
QT_MOC_LITERAL(54, 749, 8), // "hasSales"
QT_MOC_LITERAL(55, 758, 8), // "hasDatas"
QT_MOC_LITERAL(56, 767, 9), // "setReport"
QT_MOC_LITERAL(57, 777, 11), // "dayCheckOut"
QT_MOC_LITERAL(58, 789, 15), // "dayCheckOutCard"
QT_MOC_LITERAL(59, 805, 8), // "checkOut"
QT_MOC_LITERAL(60, 814, 9), // "startDate"
QT_MOC_LITERAL(61, 824, 7), // "endDate"
QT_MOC_LITERAL(62, 832, 15), // "updateSaleMonth"
QT_MOC_LITERAL(63, 848, 10), // "year_month"
QT_MOC_LITERAL(64, 859, 9), // "setIsTest"
QT_MOC_LITERAL(65, 869, 5), // "onoff"
QT_MOC_LITERAL(66, 875, 9), // "getIsTest"
QT_MOC_LITERAL(67, 885, 16), // "isRobotConnected"
QT_MOC_LITERAL(68, 902, 14), // "getMenuInfoKor"
QT_MOC_LITERAL(69, 917, 4), // "type"
QT_MOC_LITERAL(70, 922, 3), // "num"
QT_MOC_LITERAL(71, 926, 14), // "getMenuInfoEng"
QT_MOC_LITERAL(72, 941, 16), // "getMenuInfoPrice"
QT_MOC_LITERAL(73, 958, 16), // "getMenuInfoImage"
QT_MOC_LITERAL(74, 975, 22), // "getMenuInfoDescription"
QT_MOC_LITERAL(75, 998, 4), // "menu"
QT_MOC_LITERAL(76, 1003, 10), // "getSoldOut"
QT_MOC_LITERAL(77, 1014, 16), // "getOptionSoldOut"
QT_MOC_LITERAL(78, 1031, 11), // "getItemcode"
QT_MOC_LITERAL(79, 1043, 6), // "addLog"
QT_MOC_LITERAL(80, 1050, 3) // "str"

    },
    "Backend\0onTimer\0\0doPrintagain\0index\0"
    "setOrderOnSalesLog\0date\0addLogin\0user\0"
    "login\0getCardState\0reloadSaleData\0"
    "reloadContent\0idx\0reloadContentLast\0"
    "reloadCheckinContent\0getSaleDateSize\0"
    "getSaleDateAt\0i\0getContentSize\0"
    "getContentPin\0getContentTime\0"
    "getContentMenu\0getContentPrice\0"
    "getContentCardComp\0getContentCardNum\0"
    "getContentAppNum\0getContentTrandate\0"
    "getContentIsCancel\0getCheckDBSize\0"
    "getCheckDBDate\0getCheckDBTime\0"
    "getCheckDBUser\0getCheckDBLogin\0"
    "getReportTotalAmt\0getReportTotalNum\0"
    "getReportRefundAmt\0getReportRefundNum\0"
    "getReportPerAmount\0getReportMenuSize\0"
    "getReportMenuName\0getReportMenuAmt\0"
    "getReportMenuNum\0_menu\0getReportMenuTotalNum\0"
    "getReportCardSize\0getReportCardName\0"
    "getReportCardGB\0getReportCardAmt\0"
    "getReportCardNum\0getYear\0getMonth\0"
    "getDay\0getDate\0hasSales\0hasDatas\0"
    "setReport\0dayCheckOut\0dayCheckOutCard\0"
    "checkOut\0startDate\0endDate\0updateSaleMonth\0"
    "year_month\0setIsTest\0onoff\0getIsTest\0"
    "isRobotConnected\0getMenuInfoKor\0type\0"
    "num\0getMenuInfoEng\0getMenuInfoPrice\0"
    "getMenuInfoImage\0getMenuInfoDescription\0"
    "menu\0getSoldOut\0getOptionSoldOut\0"
    "getItemcode\0addLog\0str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Backend[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      68,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  354,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    1,  355,    2, 0x02 /* Public */,
       5,    2,  358,    2, 0x02 /* Public */,
       7,    2,  363,    2, 0x02 /* Public */,
      10,    0,  368,    2, 0x02 /* Public */,
      11,    0,  369,    2, 0x02 /* Public */,
      12,    1,  370,    2, 0x02 /* Public */,
      12,    1,  373,    2, 0x02 /* Public */,
      14,    0,  376,    2, 0x02 /* Public */,
      15,    1,  377,    2, 0x02 /* Public */,
      16,    0,  380,    2, 0x02 /* Public */,
      17,    1,  381,    2, 0x02 /* Public */,
      19,    0,  384,    2, 0x02 /* Public */,
      20,    1,  385,    2, 0x02 /* Public */,
      21,    1,  388,    2, 0x02 /* Public */,
      22,    1,  391,    2, 0x02 /* Public */,
      23,    1,  394,    2, 0x02 /* Public */,
      24,    1,  397,    2, 0x02 /* Public */,
      25,    1,  400,    2, 0x02 /* Public */,
      26,    1,  403,    2, 0x02 /* Public */,
      27,    1,  406,    2, 0x02 /* Public */,
      28,    1,  409,    2, 0x02 /* Public */,
      29,    0,  412,    2, 0x02 /* Public */,
      30,    1,  413,    2, 0x02 /* Public */,
      31,    1,  416,    2, 0x02 /* Public */,
      32,    1,  419,    2, 0x02 /* Public */,
      33,    1,  422,    2, 0x02 /* Public */,
      34,    0,  425,    2, 0x02 /* Public */,
      35,    0,  426,    2, 0x02 /* Public */,
      36,    0,  427,    2, 0x02 /* Public */,
      37,    0,  428,    2, 0x02 /* Public */,
      38,    0,  429,    2, 0x02 /* Public */,
      39,    0,  430,    2, 0x02 /* Public */,
      40,    1,  431,    2, 0x02 /* Public */,
      41,    1,  434,    2, 0x02 /* Public */,
      42,    1,  437,    2, 0x02 /* Public */,
      41,    1,  440,    2, 0x02 /* Public */,
      42,    1,  443,    2, 0x02 /* Public */,
      44,    0,  446,    2, 0x02 /* Public */,
      45,    0,  447,    2, 0x02 /* Public */,
      46,    1,  448,    2, 0x02 /* Public */,
      47,    1,  451,    2, 0x02 /* Public */,
      48,    1,  454,    2, 0x02 /* Public */,
      49,    1,  457,    2, 0x02 /* Public */,
      50,    0,  460,    2, 0x02 /* Public */,
      51,    0,  461,    2, 0x02 /* Public */,
      52,    0,  462,    2, 0x02 /* Public */,
      53,    0,  463,    2, 0x02 /* Public */,
      54,    1,  464,    2, 0x02 /* Public */,
      55,    1,  467,    2, 0x02 /* Public */,
      56,    1,  470,    2, 0x02 /* Public */,
      57,    1,  473,    2, 0x02 /* Public */,
      58,    1,  476,    2, 0x02 /* Public */,
      59,    2,  479,    2, 0x02 /* Public */,
      62,    1,  484,    2, 0x02 /* Public */,
      64,    1,  487,    2, 0x02 /* Public */,
      66,    0,  490,    2, 0x02 /* Public */,
      67,    0,  491,    2, 0x02 /* Public */,
      68,    2,  492,    2, 0x02 /* Public */,
      71,    2,  497,    2, 0x02 /* Public */,
      72,    2,  502,    2, 0x02 /* Public */,
      73,    2,  507,    2, 0x02 /* Public */,
      74,    2,  512,    2, 0x02 /* Public */,
      72,    1,  517,    2, 0x02 /* Public */,
      76,    1,  520,    2, 0x02 /* Public */,
      77,    1,  523,    2, 0x02 /* Public */,
      78,    1,  526,    2, 0x02 /* Public */,
      79,    1,  529,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QDate, QMetaType::Int,    6,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::QDate,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    6,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::Int, QMetaType::Int,   18,
    QMetaType::Int, QMetaType::Int,   18,
    QMetaType::Int, QMetaType::QString,   43,
    QMetaType::Int, QMetaType::QString,   43,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::Int, QMetaType::Int,   18,
    QMetaType::Int, QMetaType::Int,   18,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QDate,
    QMetaType::Int, QMetaType::QDate,    6,
    QMetaType::Int, QMetaType::QDate,    6,
    QMetaType::Void, QMetaType::QDate,    6,
    QMetaType::Void, QMetaType::QDate,    6,
    QMetaType::Void, QMetaType::QDate,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   60,   61,
    QMetaType::Void, QMetaType::QString,   63,
    QMetaType::Void, QMetaType::Int,   65,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,   69,   70,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,   69,   70,
    QMetaType::Int, QMetaType::QString, QMetaType::Int,   69,   70,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,   69,   70,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,   69,   70,
    QMetaType::Int, QMetaType::QString,   75,
    QMetaType::Bool, QMetaType::QString,   75,
    QMetaType::Bool, QMetaType::QString,   75,
    QMetaType::QString, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::QString,   80,

       0        // eod
};

void Backend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Backend *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimer(); break;
        case 1: _t->doPrintagain((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setOrderOnSalesLog((*reinterpret_cast< QDate(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->addLogin((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: { QString _r = _t->getCardState();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->reloadSaleData(); break;
        case 6: _t->reloadContent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->reloadContent((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 8: _t->reloadContentLast(); break;
        case 9: _t->reloadCheckinContent((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 10: { int _r = _t->getSaleDateSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->getSaleDateAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->getContentSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->getContentPin((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->getContentTime((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->getContentMenu((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->getContentPrice((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 17: { QString _r = _t->getContentCardComp((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->getContentCardNum((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { QString _r = _t->getContentAppNum((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 20: { QString _r = _t->getContentTrandate((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 21: { QString _r = _t->getContentIsCancel((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 22: { int _r = _t->getCheckDBSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 23: { QString _r = _t->getCheckDBDate((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->getCheckDBTime((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: { QString _r = _t->getCheckDBUser((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: { QString _r = _t->getCheckDBLogin((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 27: { int _r = _t->getReportTotalAmt();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 28: { int _r = _t->getReportTotalNum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 29: { int _r = _t->getReportRefundAmt();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 30: { int _r = _t->getReportRefundNum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 31: { QString _r = _t->getReportPerAmount();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 32: { int _r = _t->getReportMenuSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 33: { QString _r = _t->getReportMenuName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 34: { int _r = _t->getReportMenuAmt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 35: { int _r = _t->getReportMenuNum((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 36: { int _r = _t->getReportMenuAmt((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 37: { int _r = _t->getReportMenuNum((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 38: { int _r = _t->getReportMenuTotalNum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 39: { int _r = _t->getReportCardSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 40: { QString _r = _t->getReportCardName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 41: { QString _r = _t->getReportCardGB((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 42: { int _r = _t->getReportCardAmt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 43: { int _r = _t->getReportCardNum((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 44: { int _r = _t->getYear();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 45: { int _r = _t->getMonth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 46: { int _r = _t->getDay();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 47: { QDate _r = _t->getDate();
            if (_a[0]) *reinterpret_cast< QDate*>(_a[0]) = std::move(_r); }  break;
        case 48: { int _r = _t->hasSales((*reinterpret_cast< const QDate(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 49: { int _r = _t->hasDatas((*reinterpret_cast< const QDate(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 50: _t->setReport((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 51: _t->dayCheckOut((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 52: _t->dayCheckOutCard((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 53: _t->checkOut((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 54: _t->updateSaleMonth((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 55: _t->setIsTest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 56: { int _r = _t->getIsTest();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 57: { bool _r = _t->isRobotConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 58: { QString _r = _t->getMenuInfoKor((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 59: { QString _r = _t->getMenuInfoEng((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 60: { int _r = _t->getMenuInfoPrice((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 61: { QString _r = _t->getMenuInfoImage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 62: { QString _r = _t->getMenuInfoDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 63: { int _r = _t->getMenuInfoPrice((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 64: { bool _r = _t->getSoldOut((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 65: { bool _r = _t->getOptionSoldOut((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 66: { QString _r = _t->getItemcode((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 67: _t->addLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Backend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
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
        if (_id < 68)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 68;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 68)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 68;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
