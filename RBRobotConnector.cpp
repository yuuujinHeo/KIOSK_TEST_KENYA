#include "RBRobotConnector.h"
#include <iostream>
#include <QDataStream>

#define TIMER_MS    250


using namespace std;
KioskHandler::KioskHandler()
{
    // 네트워크 연결 관리
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), &connection_loop, SLOT(quit()));

    checkTimer = new QTimer(this);
    connect(checkTimer, SIGNAL(timeout()), this, SLOT(onCheck()));
    checkTimer->start(TIMER_MS);

}

// 공통적으로 사용되는 POST 구문 : 출력으로 응답 정보를 보냄
QByteArray KioskHandler::generalPost(QByteArray post_data, QString url){
    QByteArray postDataSize = QByteArray::number(post_data.size());

    QUrl serviceURL(url);
    QNetworkRequest request(serviceURL);
    QNetworkReply *reply = manager->post(request, post_data);
    connection_loop.exec();

    reply->waitForReadyRead(200);
    QByteArray ret = reply->readAll();
    reply->deleteLater();

    return ret;
}

void KioskHandler::process_order(QString url)
{
    json_out["MSG_TYPE"] = "REQ_STATUS";

    QByteArray json_string = QJsonDocument(json_out).toJson();
    qDebug() << json_out;


    QByteArray ret = generalPost(json_string, url);

//    QByteArray postDataSize = QByteArray::number(json_string.size());

//    QUrl serviceURL(url);
//    QNetworkRequest request(serviceURL);
//    request.setRawHeader("Content-Type", "application/json");
//    request.setRawHeader("Content-Length", postDataSize);
//    request.setRawHeader("Connection", "Keep-Alive");
//    request.setRawHeader("AcceptEncoding", "gzip, deflate");
//    request.setRawHeader("AcceptLanguage", "ko-KR,en,*");

//    QNetworkReply *reply = manager->post(request, json_string);
//    connection_loop.exec();

//    reply->waitForReadyRead(200);
//    QByteArray ret = reply->readAll();
//    reply->deleteLater();

    json_in = QJsonDocument::fromJson(ret).object();
    qDebug() << json_in;
}

void KioskHandler::send_order(QString url, ST_ORDER_SET order){
    QStringList keys = json_out.keys();
    for(int i=0; i<keys.size(); i++){
        json_out.remove(keys[i]);
    }

    json_out["MSG_TYPE"] = "ORDER";
    json_out["PIN"] = order.pin;
    json_out["BARCODE"] = order.barcode;


    QJsonArray array_menu;
    QJsonObject object_menu;

    for(int i=0; i<order.OrderInfo.size(); i++){
        object_menu["MENU_ID"] = order.OrderInfo[i].menu_id;
        object_menu["MENU_NAME"] = order.OrderInfo[i].menu_name;
        object_menu["OPTION"] = order.OrderInfo[i].option;

        array_menu.push_back(object_menu);
    }

    json_out["MENU"] = array_menu;

    QByteArray json_string = QJsonDocument(json_out).toJson();
    qDebug() << json_out;


    QByteArray ret = generalPost(json_string, url);
    json_in = QJsonDocument::fromJson(ret).object();
    qDebug() << json_in;
}

void KioskHandler::test_order(QString url, int menu_id)
{
//    static int p_in = 100001;
    QString p_in = QDateTime::currentDateTime().toString("hhmmss");
    json_out["MSG_TYPE"] = "ORDER";

    json_out["PIN"] = p_in;//QString().sprintf("%d",p_in);
    json_out["BARCODE"] = "a"+p_in+"z";//QString().sprintf("a%dz",p_in++);

    QJsonArray array_menu;
    QJsonObject object_menu;


    switch(menu_id){
    case 1:
        object_menu["MENU_ID"] = "1100000001";
        object_menu["MENU_NAME"] = "아메리카노";
        object_menu["OPTION"] = "000";
        break;
    case 2:
        object_menu["MENU_ID"] = "1100000002";
        object_menu["MENU_NAME"] = "아이스 아메리카노";
        object_menu["OPTION"] = "000";
        break;
    case 3:
        object_menu["MENU_ID"] = "1100000003";
        object_menu["MENU_NAME"] = "카페라떼";
        object_menu["OPTION"] = "000";
        break;
    case 4:
        object_menu["MENU_ID"] = "1100000004";
        object_menu["MENU_NAME"] = "아이스 카페라떼";
        object_menu["OPTION"] = "000";
        break;
    case 5:
        object_menu["MENU_ID"] = "1100000005";
        object_menu["MENU_NAME"] = "다방커피";
        object_menu["OPTION"] = "000";
        break;
    case 6:
        object_menu["MENU_ID"] = "1100000006";
        object_menu["MENU_NAME"] = "아이스 다방커피";
        object_menu["OPTION"] = "000";
        break;
    case 7:
        object_menu["MENU_ID"] = "1100000007";
        object_menu["MENU_NAME"] = "핫초코";
        object_menu["OPTION"] = "000";
        break;
    case 8:
        object_menu["MENU_ID"] = "1100000008";
        object_menu["MENU_NAME"] = "비타C쥬스";
        object_menu["OPTION"] = "000";
        break;
    case 9:
        object_menu["MENU_ID"] = "1100000009";
        object_menu["MENU_NAME"] = "오늘의메뉴";
        object_menu["OPTION"] = "000";
        break;
    }
    array_menu.push_back(object_menu);

    json_out["MENU"] = array_menu;

    QByteArray json_string = QJsonDocument(json_out).toJson();
    qDebug() << json_out;


    QByteArray ret = generalPost(json_string, url);
    json_in = QJsonDocument::fromJson(ret).object();
    qDebug() << json_in;
}
void KioskHandler::onCheck(){
    static int connection_cnt = 0;
    static int cnt = 0;

}


