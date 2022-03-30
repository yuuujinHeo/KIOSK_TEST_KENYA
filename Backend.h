#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QTimer>
#include <QThread>

#include "RBRobotConnector.h"
#include "RBPrinter.h"
#include "Menu.h"

#define IS_TEST_INI_PATH    "INI/IS_TEST.ini"

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = nullptr);

    QThread     *creditThread;

    RBPrinter   *printer;
    KioskHandler   *robotCon;

    int connect_cnt;
    int connection_check;
    int isconnected;
    int lastReceiptnum;

    Q_INVOKABLE int getYear();
    Q_INVOKABLE int getMonth();
    Q_INVOKABLE int getDay();
    Q_INVOKABLE QDate getDate();

    Q_INVOKABLE bool isRobotConnected();

    Q_INVOKABLE QString getMenuInfoKor(QString type, int num);
    Q_INVOKABLE QString getMenuInfoImage(QString type, int num);


    Q_INVOKABLE void newOrder();

    Q_INVOKABLE bool getSoldOut(QString menu);
    Q_INVOKABLE bool getOptionSoldOut(QString menu);

    Q_INVOKABLE QString getItemcode(QString _menu);

public slots:
    void onTimer();


private:
    QTimer *timer;
};

#endif // BACKEND_H
