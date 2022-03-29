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
    robotCon = new RBRobotConnector();

    int index = db->GetDateIndex(QDate::currentDate());
    if(index==-1){
        rblog->AddLogLine("[BACKEND]    CreateDB : "+QDateTime::currentDateTime().toString("yyMMdd"));
        db->CreateDate();
        reloadSaleData();
        reloadContent(QDate::currentDate());
        lastReceiptnum = 0;
    }else{
        reloadContent(index);
        reloadCheckinContent(QDate::currentDate());
        if(db->SaleContentList.size() > 0){
            lastReceiptnum  = db->SaleContentList[db->SaleContentList.size()-1].pin.toInt();
            qDebug() << "lastreceiptnum initz = " << lastReceiptnum;


        }else{
            lastReceiptnum  = 0;
            qDebug() << "lastreceiptnum init = " << lastReceiptnum;
        }
    }

    QSettings settings(IS_TEST_INI_PATH, QSettings::IniFormat);
    ___IS_THIS_TEST_MODE___ = settings.value("is_test").toBool();
    qsrand(QDateTime::currentDateTime().toString("MMddhhmmss").toInt());


    connection_check = false;
    connect_cnt = 0;
    isconnected = false;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start(500);
}

void Backend::onTimer(){
    static int tmr_cnt = 0;


    int index = db->GetDateIndex(QDate::currentDate());
    if(index==-1){
        rblog->AddLogLine("[BACKEND]    CreateDB : "+QDateTime::currentDateTime().toString("yyMMdd"));
        db->CreateDate();
        reloadSaleData();
        reloadContent(QDate::currentDate());
        lastReceiptnum = 0;
    }else{

    }

    qDebug() << "lastReceiptnum = " << lastReceiptnum;

    switch(robotCon->State_Boba){
    case BOBA_STATE_IDLE:
        break;
    case BOBA_STATE_MAINTENANCE:
        qDebug() << "On BOBA_STATE_MAINTENANCE On";
        QMetaObject::invokeMethod(object, "maintenance");
//        robotCon->State_Boba = BOBA_STATE_IDLE;
        break;
    case BOBA_STATE_FULL:
        qDebug() << "On BOBA_STATE_FULL On";
        QMetaObject::invokeMethod(object, "waitNotice");
//        robotCon->State_Boba = BOBA_STATE_IDLE;
        break;
    case BOBA_STATE_CLEANING:
        qDebug() << "On BOBA_STATE_CLEANING On";
        QMetaObject::invokeMethod(object, "cleaningNotice");
//        robotCon->State_Boba = BOBA_STATE_IDLE;
        break;
    case BOBA_STATE_RESTART:
        qDebug() << "On BOBA_STATE_RESTART On";
        QMetaObject::invokeMethod(object, "restart");
        robotCon->State_Boba = BOBA_STATE_IDLE;
        break;
    case BOBA_STATE_PREPARING_CLEANING:
        qDebug() << "On BOBA_STATE_PREPARING_CLEANING On";
        QMetaObject::invokeMethod(object, "precleaning");
//        robotCon->State_Boba = BOBA_STATE_IDLE;
        break;
    case BOBA_STATE_PREPARING_OPERATION:
        qDebug() << "On BOBA_STATE_PREPARING_OPERATION On";
        QMetaObject::invokeMethod(object, "preoperation");
//        robotCon->State_Boba = BOBA_STATE_IDLE;
        break;
    }

    // FOR TEST MODE -- WITHOUT CREDIT CARD PAYMENT
    if(___IS_THIS_TEST_MODE___){
        ___TEST_MODE_TIMEOUT___--;
        if(___TEST_MODE_TIMEOUT___ == 3){
            QMetaObject::invokeMethod(object, "creditNotiApproving");
        }else if(___TEST_MODE_TIMEOUT___ == 0){

        }
    }


    tmr_cnt++;
    if(tmr_cnt%4 == 0){
        printer->RBCheckStatus();
        if(((printer->Status & 32) == 32) ||
            ((printer->Status & 32) == 32) ||
            ((printer->Status & 32) == 32)){
            robotCon->is_printer_error = true;
        }else{
            robotCon->is_printer_error = false;
        }
    }



}


void Backend::addLogin(QString user, QString login){
    qDebug() << "login = " << login << "," << user;
    rblog->AddLogLine("[BACKEND]    AddLogin : "+user+"("+login+")");
    db->AddCheckIn(user,login);
}

void Backend::setOrderOnSalesLog(QDate date, int index2){
    if(index2<0 || index2>=db->SaleContentList.size()){
        return;
    }
    int index1 = db->GetDateIndex(date);
    rblog->AddLogLine("[BACKEND]    doCancel : "+date.toString("yyyyMMdd ")+QString().sprintf("%d",index2));

    OrderOnSalesLog.clear();

    QStringList list = db->SaleContentList[index2].menu.split("\n");

    for(int i=0; i<list.size(); i++){
        QStringList menuname = list[i].split("+");
        ST_ORDER_INFO temp;
        temp.menu = menuname[0];
        temp.price = getMenuInfoPrice(menuname[0]);
        if(menuname.size() > 1){
            temp.optionBoba = 1;
            temp.price += 500;
        }else{
            temp.optionBoba = 0;
        }
        rblog->AddLogLine("[BACKEND]    setOrderOnSalesLog : " + temp.menu);//QString().sprintf("%d", index2));

        OrderOnSalesLog.push_back(temp);
    }

}



void Backend::doPrintagain(int index2){
    int price = db->SaleContentList[index2].price;
    QString card_comp = db->SaleContentList[index2].card_comp;
    QString card_num = db->SaleContentList[index2].card_num;
    QString app_num = db->SaleContentList[index2].app_num;
//    QString app_num = db->SaleContentList[index2].pin;
    QString tran_date = db->SaleContentList[index2].tran_date;
    QString is_cancel = db->SaleContentList[index2].is_cancel;

    qDebug() << "app_num = " << app_num;

    if(is_cancel == "취소"){
        rblog->AddLogLine("[BACKEND]    Print Again (cancel) : "+app_num);
        printer->RBPrintCancelReceipt(1, OrderOnSalesLog, price, card_comp, card_num, app_num, tran_date);
    }else{
        rblog->AddLogLine("[BACKEND]    Print Again : "+app_num);
        printer->RBPrintCancelReceipt(0, OrderOnSalesLog, price, card_comp, card_num, app_num, tran_date);
    }
}


QString Backend::getCardState(){
    QSettings onecap("HKEY_CURRENT_USER\\Software\\KFTC_VAN\\KFTCOneCAP\\TCP", QSettings::NativeFormat);
    return onecap.value("NOTIFY_STATUS").toString();
}


void Backend::reloadSaleData(){
    rblog->AddLogLine("[BACKEND]    reloadSaleData");
    db->ReloadSaleDate();
}
void Backend::reloadContent(int idx){
    rblog->AddLogLine("[BACKEND]    reloadContent : " + QString().sprintf("%d",idx));
    db->ReloadContent(idx);
}

void Backend::reloadContent(QDate date){
    rblog->AddLogLine("[BACKEND]    reloadContent : " +date.toString("yyyyMMdd"));
    db->ReloadContent(date);
}

void Backend::reloadContentLast(){
    rblog->AddLogLine("[BACKEND]    reloadContentLast");
    db->ReloadContent(db->SaleDateList.size()-1);
}

void Backend::reloadCheckinContent(QDate date){
    rblog->AddLogLine("[BACKEND]    reloadCheckinContent");
    db->ReloadCheckinContent(date);
}

int Backend::getSaleDateSize(){
    return db->SaleDateList.size();
}
QString Backend::getSaleDateAt(int i){
    return db->SaleDateList[i];
}

int Backend::getContentSize(){
    return db->SaleContentList.size();
}

QString Backend::getContentPin(int i){
    return db->SaleContentList[i].pin;
}
QString Backend::getContentTime(int i){
    return db->SaleContentList[i].time;
}
QString Backend::getContentMenu(int i){
    return db->SaleContentList[i].menu;
}
QString Backend::getContentPrice(int i){
//    return QString().sprintf("%d", db->SaleContentList[i].price);
    return QString("%L1").arg(db->SaleContentList[i].price ,5,'f',0,' ');
}
QString Backend::getContentCardComp(int i){
    return db->SaleContentList[i].card_comp;
}
QString Backend::getContentCardNum(int i){
    return db->SaleContentList[i].card_num;
}
QString Backend::getContentAppNum(int i){
    return db->SaleContentList[i].app_num;
}
QString Backend::getContentTrandate(int i){
    return db->SaleContentList[i].tran_date;
}
QString Backend::getContentIsCancel(int i){
    return db->SaleContentList[i].is_cancel;
}

int Backend::getCheckDBSize(){
    return db->CheckinContentList.size();
}

QString Backend::getCheckDBDate(int i){
    return db->CheckinContentList[i].date;
}
QString Backend::getCheckDBTime(int i){
    return db->CheckinContentList[i].time;
}
QString Backend::getCheckDBUser(int i){
    return db->CheckinContentList[i].user;
}
QString Backend::getCheckDBLogin(int i){
    return db->CheckinContentList[i].login;
}


int Backend::getReportTotalAmt(){
    return db->DayReport.total_sale_amt;
}
int Backend::getReportTotalNum(){
    qDebug() << "total count - " << db->DayReport.total_sale_cnt;
    return db->DayReport.total_sale_cnt;
}
int Backend::getReportRefundAmt(){
    return db->DayReport.refund_sale_amt;
}
int Backend::getReportRefundNum(){
    return db->DayReport.refund_sale_cnt;
}


int Backend::getReportMenuSize(){
        if(db->DayReport.Menu.isEmpty()) return 0;
        return db->DayReport.Menu.size();
}
QString Backend::getReportMenuName(int i){
    if(db->DayReport.Menu.size() > 0)
        return db->DayReport.Menu[i].menu_name;
    else {
        return "";
    }
}
int Backend::getReportMenuAmt(int i){
    if(db->DayReport.Menu.size() > 0)
        return db->DayReport.Menu[i].amt;
    else
        return 0;
}
int Backend::getReportMenuNum(int i){
    if(db->DayReport.Menu.size() > 0)
        return db->DayReport.Menu[i].num;
    else
        return 0;
}

int Backend::getReportMenuAmt(QString _menu){
    for(int i=0; i<db->DayReport.Menu.size();i++)
    {
        if(db->DayReport.Menu[i].menu_name == _menu){
            return db->DayReport.Menu[i].amt;
        }
    }
    return 0;
}
int Backend::getReportMenuNum(QString _menu){
    for(int i=0; i<db->DayReport.Menu.size();i++)
    {
        if(db->DayReport.Menu[i].menu_name == _menu){
            return db->DayReport.Menu[i].num;
        }
    }
    return 0;
}

int Backend::getReportCardSize(){
    return 0;
    if(db->DayReport.Card.isEmpty()) return 0;
    else return db->DayReport.Card.size();
}
QString Backend::getReportCardName(int i){
    if(db->DayReport.Card.size() > 0)
        return db->DayReport.Card[i].card_name;
    else
        return "";
}
QString Backend::getReportCardGB(int i){
    if(db->DayReport.Card.size() > 0)
        return db->DayReport.Card[i].sale_gb;
    else
        return "";
}
int Backend::getReportCardAmt(int i){
    if(db->DayReport.Card.size() > 0)
        return db->DayReport.Card[i].amt;
    else
        return 0;
}
int Backend::getReportCardNum(int i){
    if(db->DayReport.Card.size() > 0)
        return db->DayReport.Card[i].num;
    else
        return 0;
}

int Backend::getReportMenuTotalNum(){
    int total_num = 0;
    for(int i=0;i<db->DayReport.Menu.size();i++){
        total_num += db->DayReport.Menu[i].num;
    }
    return total_num;
}

QString Backend::getReportPerAmount(){
    if(db->DayReport.total_sale_cnt == 0) return "0";
    return QString().sprintf("%d",(int)(db->DayReport.total_sale_amt/db->DayReport.total_sale_cnt));
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

int Backend::hasSales(const QDate &date){
    db->ReloadContent(date);
    return db->SaleContentList.size();
}

int Backend::hasDatas(const QDate &date){
    qDebug() << "hasDatas : " << date.toString();
    db->ReloadCheckinContent(date);
    return db->CheckinContentList.size();
}

void Backend::setReport(QDate date){
    rblog->AddLogLine("[BACKEND]    setReport");
    db->ReloadContent(date);
    QString checkoutResult = db->dayCheckOut(date);
}

void Backend::dayCheckOut(QDate date){
    rblog->AddLogLine("[BACKEND]    dayCheckOut");
    db->ReloadContent(date);
    QString checkoutResult = db->dayCheckOut(date);

    printer->RBPrintDayReport(db->DayReport);
}

void Backend::dayCheckOutCard(QDate date){
    rblog->AddLogLine("[BACKEND]    dayCheckOutCard");
    db->ReloadContent(date);
    QString checkoutResult = db->dayCheckOut(date);

    printer->RBPrintCardReport(db->DayReport);
}


void Backend::checkOut(QString startDate, QString endDate){
    rblog->AddLogLine("[BACKEND]    checkOut");
    QString checkoutResult = db->checkOut(startDate, endDate);

    printer->RBPrintCheckOut(checkoutResult);

//    qDebug() << checkoutResult;
}



void Backend::updateSaleMonth(QString year_month){
    rblog->AddLogLine("[BACKEND]    updateSaleMonth");
    int year;
    int month;
    sscanf(year_month.toStdString().data(), "%d-%d", &year, &month);

    db->ReloadSaleDate(year, month);
}

void Backend::setIsTest(int onoff){
    rblog->AddLogLine("[BACKEND]    setIsTest");
    QSettings settings(IS_TEST_INI_PATH, QSettings::IniFormat);
    ___IS_THIS_TEST_MODE___ = onoff;
    settings.setValue("is_test", onoff);
}

int Backend::getIsTest(){
    return ___IS_THIS_TEST_MODE___;
}

bool Backend::isRobotConnected(){
    return robotCon->is_connected;
}


// 메뉴에 대한 정보 요청
QString Backend::getMenuInfoKor(QString type, int num){
    int menutype = -1;
    for(int i=0; i<menuTypeList.size(); i++){
        if(menuTypeList[i].kor == type){
            menutype = i;
            break;
        }
    }
    if(menutype < 0){
        return "";
    }

    if(num >= menuList[menutype].size()){
        return "";
    }
    return menuList[menutype][num].kor;
}

QString Backend::getMenuInfoEng(QString type, int num){
    int menutype = -1;
    for(int i=0; i<menuTypeList.size(); i++){
        if(menuTypeList[i].kor == type){
            menutype = i;
            break;
        }
    }
    if(menutype < 0){
        return "";
    }

    if(num >= menuList[menutype].size()){
        return "";
    }
    return menuList[menutype][num].eng;
}

int Backend::getMenuInfoPrice(QString type, int num){
    int menutype = -1;
    for(int i=0; i<menuTypeList.size(); i++){
        if(menuTypeList[i].kor == type){
            menutype = i;
            break;
        }
    }
    if(menutype < 0){
        return -1;
    }

    if(num >= menuList[menutype].size()){
        return -1;
    }
    return menuList[menutype][num].price;
}

int Backend::getMenuInfoPrice(QString menu){
    for(int i=0; i<menuTypeList.size(); i++){
        for(int j=0; j<menuList[i].size(); j++){
            if(menuList[i][j].kor == menu){
                qDebug() << "find = " << menu;
                return menuList[i][j].price;
            }
        }
    }

    qDebug() << "can't find menu : " << menu;
    return 0;

}

QString Backend::getMenuInfoImage(QString type, int num){
    int menutype = -1;
    for(int i=0; i<menuTypeList.size(); i++){
        if(menuTypeList[i].kor == type){
            menutype = i;
            break;
        }
    }
    if(menutype < 0){
        return "";
    }

    if(num >= menuList[menutype].size()){
        return "";
    }
    qDebug() <<  menuList[menutype][num].image;
    return menuList[menutype][num].image;
}

QString Backend::getMenuInfoDescription(QString type, int num){
    int menutype = -1;
    for(int i=0; i<menuTypeList.size(); i++){
        if(menuTypeList[i].kor == type){
            menutype = i;
            break;
        }
    }
    if(menutype < 0){
        return "";
    }

    if(num >= menuList[menutype].size()){
        return "";
    }
//    qDebug() << menuList[menutype][num].description;
    return menuList[menutype][num].description;
}

bool Backend::getSoldOut(QString menu){
    return robotCon->soldout_map[mapMenuEng[menu]];
}


bool Backend::getOptionSoldOut(QString menu){
    return robotCon->soldout_map[menu];
}


QString Backend::getItemcode(QString _menu){
    for(int i=0;i<menuList.size();i++){
        for(int j=0;j<menuList[0].size();j++){
            if(menuList[i][j].kor == _menu){
                return menuList[i][j].code;
            }
        }

    }
    return "";
}

void Backend::addLog(QString str){
    rblog->AddLogLine(str);
}
