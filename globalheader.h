#ifndef GLOBALHEADER_H
#define GLOBALHEADER_H

#include <QVector>
#include <QString>
#include <QMap>
#include <QDate>
#include <RBLog.h>


#define BOBA_KIOSK_VERSION      210510

typedef struct{
    QString kor;
    QString eng;
}ST_MENU_TYPE;

typedef struct{
    QString code;
    QString kor;
    QString eng;
    int price;
    QString image;
    QString description;
}ST_MENU_DETAIL;
typedef QVector<ST_MENU_DETAIL> MENU_DETAILS;


extern QVector<ST_MENU_TYPE> menuTypeList;
extern QVector<MENU_DETAILS> menuList;
extern QMap<QString, QString> mapMenuImage;
extern QMap<QString, QString> mapMixxImage;
extern QMap<QString, QString> mapMenuEng;


#define MAX_ORDER_QUANTITY  2
typedef struct{
    QString menu;
    int optionIce;
    int optionBoba;
    int optionSyrup;
    int price;
}ST_ORDER_INFO;

extern QVector<ST_ORDER_INFO> OrderInCart;
extern QVector<ST_ORDER_INFO> OrderOnProgress;
extern QVector<ST_ORDER_INFO> OrderOnSalesLog;


typedef struct{
    // Transaction Data
    QString PlatformID;
    QString PhoneNumber;
    QString Date;
    QString TransactionNumber;

    // Order Data
    QVector<ST_ORDER_INFO> OrderInfo;
}ST_ORDER_SET;


typedef struct {
    QString card_name;
    QString sale_gb;
    int     amt;
    int     num;
}SaleByCardComp;

typedef struct {
    QString menu_name;
    int     amt;
    int     num;
}SaleByMenu;

typedef struct {
    int total_sale_amt;
    int total_sale_cnt;
    int refund_sale_amt;
    int refund_sale_cnt;

    QVector<SaleByCardComp> Card;
    QVector<SaleByMenu> Menu;
    QDate Day;

}SaleReport;




#endif // GLOBALHEADER_H
