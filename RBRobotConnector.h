#ifndef KIOSKHANDLER_H
#define KIOSKHANDLER_H

#include <QObject>
#include <QtNetwork>
#include <QTimer>
#include <QDebug>

// json -----------------------
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

// connection ------------------
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QNetworkRequest>

// websocket ------------------
#include <QtHttpServer.h>
#include <QtHttpRequest.h>
#include <QtHttpReply.h>
#include <QtHttpHeader.h>
#include "globalheader.h"
#define KIOSK_URL   "http://127.0.0.1:8080"
//#define ROBOT_URL   "http://127.0.0.1:8080"
#define ROBOT_URL   "http://192.168.100.100:8080"

class KioskHandler : QObject
{
    Q_OBJECT

public:
    KioskHandler();
    QByteArray generalPost(QByteArray post_data, QString url);

    void process_order(QString url);
    void send_order(QString url, ST_ORDER_SET order);
    void test_order(QString url, int menu_id);

    QJsonObject json_out;
    QJsonObject json_in;

public slots:
    void onCheck();

private:
    QTimer *checkTimer;
    // 네트워크 커넥션 관리 -----------------
    QNetworkAccessManager   *manager;
    QEventLoop              connection_loop;

};

#endif // KIOSKHANDLER_H
