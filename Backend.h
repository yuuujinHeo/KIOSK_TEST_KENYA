#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QTimer>
#include <QThread>

#include "RBPrinter.h"
#include "RBRobotConnector.h"
#include "RBSaleLog.h"
#include "Menu.h"

#define IS_TEST_INI_PATH    "INI/IS_TEST.ini"

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = nullptr);

    QThread     *creditThread;


    RBPrinter   *printer;
    RBRobotConnector    *robotCon;
    RBSaleLog   *db;

    int connect_cnt;
    int connection_check;
    int isconnected;
    int lastReceiptnum;

    Q_INVOKABLE void doPrintagain(int index);
    Q_INVOKABLE void setOrderOnSalesLog(QDate date, int index);

    Q_INVOKABLE void addLogin(QString user, QString login);

    Q_INVOKABLE QString getCardState();

    Q_INVOKABLE void reloadSaleData();
    Q_INVOKABLE void reloadContent(int idx);
    Q_INVOKABLE void reloadContent(QDate date);
    Q_INVOKABLE void reloadContentLast();
    Q_INVOKABLE void reloadCheckinContent(QDate date);
    Q_INVOKABLE int getSaleDateSize();
    Q_INVOKABLE QString getSaleDateAt(int i);

    Q_INVOKABLE int getContentSize();
    Q_INVOKABLE QString getContentPin(int i);
    Q_INVOKABLE QString getContentTime(int i);
    Q_INVOKABLE QString getContentMenu(int i);
    Q_INVOKABLE QString getContentPrice(int i);
    Q_INVOKABLE QString getContentCardComp(int i);
    Q_INVOKABLE QString getContentCardNum(int i);
    Q_INVOKABLE QString getContentAppNum(int i);
    Q_INVOKABLE QString getContentTrandate(int i);
    Q_INVOKABLE QString getContentIsCancel(int i);

    Q_INVOKABLE int getCheckDBSize();
    Q_INVOKABLE QString getCheckDBDate(int i);
    Q_INVOKABLE QString getCheckDBTime(int i);
    Q_INVOKABLE QString getCheckDBUser(int i);
    Q_INVOKABLE QString getCheckDBLogin(int i);

    Q_INVOKABLE int getReportTotalAmt();
    Q_INVOKABLE int getReportTotalNum();
    Q_INVOKABLE int getReportRefundAmt();
    Q_INVOKABLE int getReportRefundNum();

    Q_INVOKABLE QString getReportPerAmount();
    Q_INVOKABLE int getReportMenuSize();
    Q_INVOKABLE QString getReportMenuName(int i);
    Q_INVOKABLE int getReportMenuAmt(int i);
    Q_INVOKABLE int getReportMenuNum(int i);
    Q_INVOKABLE int getReportMenuAmt(QString _menu);
    Q_INVOKABLE int getReportMenuNum(QString _menu);
    Q_INVOKABLE int getReportMenuTotalNum();

    Q_INVOKABLE int getReportCardSize();
    Q_INVOKABLE QString getReportCardName(int i);
    Q_INVOKABLE QString getReportCardGB(int i);
    Q_INVOKABLE int getReportCardAmt(int i);
    Q_INVOKABLE int getReportCardNum(int i);

    Q_INVOKABLE int getYear();
    Q_INVOKABLE int getMonth();
    Q_INVOKABLE int getDay();
    Q_INVOKABLE QDate getDate();

    Q_INVOKABLE int hasSales(const QDate &date);
    Q_INVOKABLE int hasDatas(const QDate &date);

    Q_INVOKABLE void setReport(QDate date);
    Q_INVOKABLE void dayCheckOut(QDate date);
    Q_INVOKABLE void dayCheckOutCard(QDate date);
    Q_INVOKABLE void checkOut(QString startDate, QString endDate);
    Q_INVOKABLE void updateSaleMonth(QString year_month);



    Q_INVOKABLE void setIsTest(int onoff);
    Q_INVOKABLE int getIsTest();

    Q_INVOKABLE bool isRobotConnected();


    Q_INVOKABLE QString getMenuInfoKor(QString type, int num);
    Q_INVOKABLE QString getMenuInfoEng(QString type, int num);
    Q_INVOKABLE int getMenuInfoPrice(QString type, int num);
    Q_INVOKABLE QString getMenuInfoImage(QString type, int num);
    Q_INVOKABLE QString getMenuInfoDescription(QString type, int num);
    Q_INVOKABLE int getMenuInfoPrice(QString menu);


    Q_INVOKABLE bool getSoldOut(QString menu);
    Q_INVOKABLE bool getOptionSoldOut(QString menu);

    Q_INVOKABLE QString getItemcode(QString _menu);

    Q_INVOKABLE void addLog(QString str);
public slots:
    void onTimer();


private:
    QTimer *timer;
};

#endif // BACKEND_H
