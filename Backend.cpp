#include "Backend.h"
#include <QQmlApplicationEngine>
#include <QKeyEvent>
#include <iostream>
#include <QTextCodec>
#include <QSslSocket>
#include <windows.h>

extern QObject *object;
extern Menu *menu;
extern RBLog *rblog;

int ___IS_THIS_TEST_MODE___ = true;//true;
int ___TEST_MODE_TIMEOUT___ = 0;


int cancel_db_index1 = 0;
int cancel_db_index2 = 0;


using namespace std;
Backend::Backend(QObject *parent)
    : QObject(parent)
{

    printer = new RBPrinter();
    robotCon = new KioskHandler();

    connection_check = false;
    connect_cnt = 0;
    isconnected = false;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start(500);


}

void Backend::onTimer(){
    static int tmr_cnt = 0;

//    qDebug() << "lastReceiptnum = " << lastReceiptnum;

    tmr_cnt++;
    if(tmr_cnt%4 == 0){
        printer->RBCheckStatus();
        if(((printer->Status & 32) == 32) ||
            ((printer->Status & 32) == 32) ||
            ((printer->Status & 32) == 32)){
//            robotCon->is_printer_error = true;
        }else{
//            robotCon->is_printer_error = false;
        }
    }

}


int Backend::getYear(){
    QString temp = QDateTime::currentDateTime().toString("yyyy");
    return temp.toInt()-2020;
}
int Backend::getMonth(){
    QString temp = QDateTime::currentDateTime().toString("MM");
    return temp.toInt()-1;
}
int Backend::getDay(){
    QString temp = QDateTime::currentDateTime().toString("d");
    qDebug()<<temp;
    return temp.toInt()-1;
}

QDate Backend::getDate(){
    qDebug()<<QDate::currentDate();
    return QDate::currentDate();
}

bool Backend::isRobotConnected(){
    return true; //robotCon->is_connected;
}


// 메뉴에 대한 정보 요청
QString Backend::getMenuInfoKor(QString type, int num){
    qDebug() << type << num;
//    qDebug() << menu->menu_List[type].size();
//    qDebug() << menu->menu_List.size();
//    if(menu->menu_List[type].size() > num){
//        qDebug() <<menu->menu_List[type][num].menu_name;
//        return menu->menu_List[type][num].menu_name;
//    }

    return "";
}

QString Backend::getMenuInfoImage(QString type, int num){
//    if(menu->menu_List[type].size() > num){
//        qDebug() <<menu->menu_List[type][num].image;
//        return menu->menu_List[type][num].image;
//    }

    return "";
}

bool Backend::getSoldOut(QString menu){
    return false;//robotCon->soldout_map[mapMenuEng[menu]];
}


bool Backend::getOptionSoldOut(QString menu){
    return false;// robotCon->soldout_map[menu];
}

void Backend::newOrder(){
    OrderOnProgress = OrderInCart;
    OrderInCart.clear();

    ST_ORDER_SET temp_order;
    temp_order.pin = QDateTime::currentDateTime().toString("ddhhmmss");
    temp_order.barcode = "a" + temp_order.pin + "z";
    temp_order.OrderInfo = OrderOnProgress;
    robotCon->send_order(ROBOT_URL, temp_order);

    printer->RBPrintReceipt(temp_order.pin, OrderOnProgress);

}
QString Backend::getItemcode(QString _menu){
//    for(int i=0;i<menuList.size();i++){
//        for(int j=0;j<menuList[0].size();j++){
//            if(menuList[i][j].kor == _menu){
//                return menuList[i][j].code;
//            }
//        }

//    }
    return "";
}
