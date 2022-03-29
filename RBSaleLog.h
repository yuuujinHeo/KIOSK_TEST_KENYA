#ifndef RBSALELOG_H
#define RBSALELOG_H

#include <QObject>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "globalheader.h"

typedef struct {
    QString pin;
    QString time;
    QString menu;
    int     price;
    QString card_comp;
    QString card_num;
    QString app_num;
    QString tran_date;
    QString is_cancel;
    QString acqu_code;
    QString card_gb;
    QString menu_boba;
    QString menu_syrup;
    int     version;
}SaleContent;

typedef struct {
    QString date;
    QString time;
    QString user;
    QString login;
}SaleCheckin;




class RBSaleLog : QObject
{
    Q_OBJECT
public:
    RBSaleLog();

    void SaveData(int mode, QString transaction_number, QString menu_name, int price, QString card_comp, QString card_num, QString approve_num, QString tran_date, QString acqu_code, QString card_gb);
    void AddCheckIn(QString user, QString login);
    void CreateDate();
    void CreateCheckinDate();
    void ReloadSaleDate();
    void ReloadSaleDate2();
    void ReloadSaleDate(int year, int month);

    void ReloadContent(int idx);
    void ReloadContent(QDate _date);
    void ReloadCheckinContent(QDate _date);

    void ChangeToCreditCancel(int index1, int index2);

    int GetDateIndex(QDate _date);
    QString dayCheckOut(QDate _date);
    QString checkOut(QString startDate, QString endDate);

    int GetIndexCard(QString _card, QString _gb);
    int GetIndexMenu(QString _menu);



    QStringList             SaleDateList;
    QVector<SaleContent>    SaleContentList;
    QStringList             CheckinDateList;
    QVector<SaleCheckin>    CheckinContentList;
    SaleReport              DayReport;

private:
    QSqlDatabase LocalDB;
    QSqlDatabase CheckDB;
};

#endif // RBSALELOG_H
