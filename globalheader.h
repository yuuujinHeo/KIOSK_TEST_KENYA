#ifndef GLOBALHEADER_H
#define GLOBALHEADER_H

#include <QVector>
#include <QString>
#include <QMap>
#include <QDate>
#include <RBLog.h>

typedef struct{
    QString menu_id;
    QString menu_type;
    QString menu_name;
    QString image;
}ST_MENU_DETAIL;

//extern QVector<MENU_DETAILS> menuList;
//extern QMap<QString, QString> mapMenuImage;
//extern QMap<QString, QString> mapMixxImage;
//extern QMap<QString, QString> mapMenuEng;
//extern QMap<QString, QString> mapMenuID;


#define MAX_ORDER_QUANTITY  9999
typedef struct{
    QString menu_id;
    QString menu_name;
    QString option;
}ST_ORDER_INFO;

extern QVector<ST_ORDER_INFO> OrderInCart;
extern QVector<ST_ORDER_INFO> OrderOnProgress;
extern QVector<ST_ORDER_INFO> OrderOnSalesLog;


typedef struct{
    // Transaction Data
    QString pin;
    QString barcode;

    // Order Data
    QVector<ST_ORDER_INFO> OrderInfo;
}ST_ORDER_SET;

#endif // GLOBALHEADER_H
