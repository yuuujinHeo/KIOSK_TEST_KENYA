#include "RBSaleLog.h"
#include <QDebug>
#include <QDateTime>

extern RBLog *rblog;
QMap<QString, int> mapMenuPrice;
QMap<QString, int> mapMenuPricenew;

QString toMoney(int value){
    return QString("%L1").arg(value, 0, 'f',0,' ');
}

RBSaleLog::RBSaleLog()
{
    LocalDB = QSqlDatabase::addDatabase("QSQLITE", "LocalDB");
    LocalDB.setDatabaseName("DB/LocalDB.db");

    CheckDB = QSqlDatabase::addDatabase("QSQLITE", "LocalDB2");
    CheckDB.setDatabaseName("DB/CheckDB.db");

    ReloadSaleDate();
    ReloadSaleDate2();

    mapMenuPrice.clear();
    mapMenuPrice["블랙티"] = 2800;
    mapMenuPrice["베리티"] = 3000;
    mapMenuPrice["말차티"] = 3500;
    mapMenuPrice["콜드브루 커피"] = 3800;
    mapMenuPrice["블랙 밀크티"] = 3300;
    mapMenuPrice["베리 밀크티"] = 3500;
    mapMenuPrice["말차 밀크티"] = 4000;
    mapMenuPrice["콜드브루 밀크커피"] = 4300;

    mapMenuPricenew.clear();
    mapMenuPricenew["블랙티"] = 2800;
    mapMenuPricenew["베리티"] = 3000;
    mapMenuPricenew["말차티"] = 3500;
    mapMenuPricenew["콜드브루 커피"] = 3500;
    mapMenuPricenew["블랙 밀크티"] = 3800;
    mapMenuPricenew["베리 밀크티"] = 4000;
    mapMenuPricenew["말차 밀크티"] = 4500;
    mapMenuPricenew["콜드브루 밀크커피"] = 4500;
    mapMenuPricenew["옛날 커피"] = 2000;
    mapMenuPricenew["비타C쥬스"] = 3000;

    DayReport.total_sale_amt = 0;
    DayReport.total_sale_cnt = 0;
    DayReport.refund_sale_amt = 0;
    DayReport.refund_sale_cnt = 0;

    DayReport.Menu.clear();
    DayReport.Card.clear();
}


void RBSaleLog::SaveData(int mode, QString transaction_number, QString menu_name, int price, QString card_comp, QString card_num,
                         QString approve_num, QString tran_date, QString acqu_code, QString card_gb){

    qDebug() << "savedata";
    QSqlQuery query(LocalDB);

    QString date_format = "yyyy_MM_dd";
    QString time_format = "hh:mm:ss";
    QString date_str = QDateTime::currentDateTime().toString(date_format);
    QString time_str = QDateTime::currentDateTime().toString(time_format);
    qDebug() << date_str;
    qDebug() << time_str;


    QString select_str("select * from RB");
    select_str += date_str;
    qDebug() << select_str;

    QString detail_str = "";
    if(mode == 0)//approve
        detail_str = "승인";
    else
        detail_str = "취소";

    int has_table = query.exec(select_str);

    if(!has_table){
        QString create_str = QString().sprintf("CREATE TABLE RB%s (order_id INTEGER PRIMARY KEY ASC AUTOINCREMENT, time TEXT, menu TEXT, price INT, cardcomp TEXT, cardnum TEXT, appnum TEXT, trandate TEXT, iscancel TEXT, acqu_code TEXT, card_gb TEXT, version INT)", date_str.toStdString().data());
        query.exec(create_str);
        qDebug() << create_str;
        query.exec(select_str);
        rblog->AddLogLine("[DB]         CreateDB : " + create_str);
    }

    QString insert_str = QString().sprintf("INSERT INTO RB%s (time, menu, price, cardcomp, cardnum, appnum, trandate, iscancel, acqu_code, card_gb, version) "
                                           "VALUES (\'%s\', \'%s\', %d, \'%s\', \'%s\', \'%s\', \'%s\', \'%s\', \'%s\', \'%s\', %d)",
                                           date_str.toStdString().data(), time_str.toStdString().data(), menu_name.toStdString().data(),
                                           price, card_comp.toStdString().data(), card_num.toStdString().data(),
                                           approve_num.toStdString().data(), tran_date.toStdString().data(),
                                           detail_str.toStdString().data(), acqu_code.toStdString().data(), card_gb.toStdString().data(), 1);
    query.exec(insert_str);
    qDebug() << insert_str;
    qDebug() << "savedata";
    rblog->AddLogLine("[DB]         AddDB : " + insert_str);
}

void RBSaleLog::AddCheckIn(QString user, QString login){

    qDebug() << "savecheckindata";
    QSqlQuery query(CheckDB);

    QString date_format = "yyyy_MM_dd";
    QString time_format = "hh:mm:ss";
    QString date_str = QDateTime::currentDateTime().toString(date_format);
    QString time_str = QDateTime::currentDateTime().toString(time_format);
    qDebug() << date_str;
    qDebug() << time_str;


    QString select_str = QString().sprintf("select * from RB");
    select_str += date_str;
    qDebug() << select_str;

    QString detail_str = "";

    int has_table = query.exec(select_str);

    if(!has_table){
        QString create_str = QString().sprintf("CREATE TABLE RB%s (date TEXT, time TEXT, user TEXT, log TEXT)",date_str.toStdString().data());
        query.exec(create_str);
        qDebug() << create_str;
        query.exec(select_str);
        rblog->AddLogLine("[DB]         CreateCheckDB : " + create_str);
    }

    QString insert_str = QString().sprintf("INSERT INTO RB%s (date, time, user, log) "
                                           "VALUES (\'%s\', \'%s\', \'%s\', \'%s\')",
                                           date_str.toStdString().data(),date_str.toStdString().data(), time_str.toStdString().data(),
                                           user.toStdString().data(), login.toStdString().data());
    query.exec(insert_str);
    rblog->AddLogLine("[DB]         AddCheckDB : " + insert_str);
}

void RBSaleLog::CreateDate(){

    QSqlQuery query(LocalDB);
    QString date_format = "yyyy_MM_dd";
    QString time_format = "hh:mm:ss";
    QString date_str = QDateTime::currentDateTime().toString(date_format);

    qDebug() << date_str;
    QString select_str("select * from RB");
    select_str += date_str;
    qDebug() << select_str;

    QString create_str = QString().sprintf("CREATE TABLE RB%s (order_id INTEGER PRIMARY KEY ASC AUTOINCREMENT, time TEXT, menu TEXT, price INT, cardcomp TEXT, cardnum TEXT, appnum TEXT, trandate TEXT, iscancel TEXT, acqu_code TEXT, card_gb TEXT, version INT)", date_str.toStdString().data());
    query.exec(create_str);
    qDebug() << create_str;
    query.exec(select_str);

    rblog->AddLogLine("[DB]         CreateDB : " + create_str);
}

void RBSaleLog::CreateCheckinDate(){

    QSqlQuery query(CheckDB);

    QString date_format = "yyyy_MM_dd";
    QString date_str = QDateTime::currentDateTime().toString(date_format);

    QString select_str("select * from RB");
    select_str += date_str;
    qDebug() << select_str;

    QString create_str = QString().sprintf("CREATE TABLE RB%s (order_id INTEGER PRIMARY KEY ASC AUTOINCREMENT, date TEXT, time TEXT, user TEXT, log TEXT)", date_str.toStdString().data());
    query.exec(create_str);
    qDebug() << create_str;
    query.exec(select_str);

    rblog->AddLogLine("[DB]         CreateCheckDB : " + create_str);
}

void RBSaleLog::ReloadSaleDate(){
    if(!LocalDB.open()){
        qDebug() << "DB open fail";
    }
//    qDebug() << LocalDB.tables();
    QString compareStr = QString().sprintf("RB");
    SaleDateList = LocalDB.tables();
    for(int i=SaleDateList.size()-1; i>=0; i--){
        QString temp = SaleDateList.at(i);
        if(temp.mid(0,2) == compareStr){

        }else{
            SaleDateList.removeAt(i);
        }
    }
    rblog->AddLogLine("[DB]         ReloadDate ");
    qDebug() << SaleDateList;
}

void RBSaleLog::ReloadSaleDate2(){
    if(!CheckDB.open()){
        qDebug() << "DB open fail";
    }
    QString compareStr = QString().sprintf("RB");
    CheckinDateList = CheckDB.tables();
    for(int i=CheckinDateList.size()-1; i>=0; i--){
        QString temp = CheckinDateList.at(i);
        if(temp.mid(0,2) == compareStr){

        }else{
            CheckinDateList.removeAt(i);
        }
    }
    rblog->AddLogLine("[DB]         ReloadCheckDB ");
    qDebug() << CheckDB.tables();
}

void RBSaleLog::ReloadSaleDate(int year, int month){
    if(!LocalDB.open()){
        rblog->AddLogLine("[DB]         ReloadDate open fail");
        qDebug() << "DB open fail";
    }
    rblog->AddLogLine("[DB]         ReloadDate : " + QString().sprintf("%d-%d",year,month));
    qDebug() << LocalDB.tables();
    QString compareStr = QString().sprintf("RB%4d_%02d", year, month);
    SaleDateList = LocalDB.tables();
    for(int i=SaleDateList.size()-1; i>=0; i--){
        QString temp = SaleDateList.at(i);
        if(temp.mid(0,9) == compareStr){

        }else{
            SaleDateList.removeAt(i);
        }
    }
}


void RBSaleLog::ReloadContent(int idx){
    rblog->AddLogLine("[DB]         ReloadContent : " + QString().sprintf("%d",idx));
    qDebug() << "idx = " << idx;
    qDebug() << "SaleDataList.size() = " << SaleDateList.size();
    if(idx >= SaleDateList.size()){
        rblog->AddLogLine("[DB]         ReloadContent size 0 : "+QString().sprintf("%d",SaleDateList.size()));
        return;
    }
    SaleContentList.clear();

    QString select_str("select * from ");
    select_str += SaleDateList[idx];

    qDebug() << select_str;

    QSqlQuery query(LocalDB);

    // count column
    query.exec(select_str);
    query.next();
    int count = 0;
    for(int i=0; i<20; i++){
        if(!(query.value(i).isValid())){
            count = i;
            break;
        }
    }
    rblog->AddLogLine("[DB]         ReloadContent count : "+QString().sprintf("%d",count));

    query.exec(select_str);
    int query_count = 0;
    rblog->AddLogLine("[DB]         select_str : "+select_str);
    while(query.next()){
        SaleContent temp;
        if(count == 12){
            // new format
            temp.pin = query.value(0).toString();
            temp.time = query.value(1).toString();
            temp.menu = query.value(2).toString();
            temp.price = query.value(3).toInt();
            temp.card_comp = query.value(4).toString();
            temp.card_num = query.value(5).toString();
            temp.app_num = query.value(6).toString();
            temp.tran_date = query.value(7).toString();
            temp.is_cancel = query.value(8).toString();
            temp.acqu_code = query.value(9).toString();
            temp.card_gb = query.value(10).toString();
            temp.version = query.value(11).toInt();

        }else{
            // new format
            temp.pin = query.value(0).toString();
            temp.time = query.value(1).toString();
            temp.menu = query.value(2).toString();
            temp.price = query.value(3).toInt();
            temp.card_comp = query.value(4).toString();
            temp.card_num = query.value(5).toString();
            temp.app_num = query.value(6).toString();
            temp.tran_date = query.value(7).toString();
            temp.is_cancel = query.value(8).toString();
            temp.acqu_code = query.value(9).toString();
            temp.card_gb = query.value(10).toString();
//            temp.menu_boba = query.value(11).toString();
//            temp.menu_syrup = query.value(12).toString();
        }
        query_count++;
//        rblog->AddLogLine("[DB]         ReloadContent : "+temp.menu);

        SaleContentList.push_back(temp);
    }
    rblog->AddLogLine("[DB]         reloadcontent load : "+QString().sprintf("%d",query_count));
}

void RBSaleLog::ReloadContent(QDate _date){
//    qDebug() << _date;
    SaleContentList.clear();

    rblog->AddLogLine("[DB]         ReloadContent : " + _date.toString("yyyy-MM-dd"));

    QString select_str = QString().sprintf("select * from RB%d_%02d_%02d",_date.year(),_date.month(),_date.day());
    QSqlQuery query(LocalDB);

    qDebug() << select_str;
    // count column
    query.exec(select_str);

    if(query.next() == false){
        rblog->AddLogLine("[DB]         Content load Fail : " + _date.toString("yyyy-MM-dd"));
        
//        qDebug() << "NULL=======================" << _date;
        SaleContentList.clear();
        return;
    }

//    query.next();
    int count = 0;
    for(int i=0; i<20; i++){
        if(!(query.value(i).isValid())){
            count = i;
            break;
        }
    }
    rblog->AddLogLine("[DB]         Content count : " + QString().sprintf("%d",count));

    query.exec(select_str);
    int query_count = 0;
    rblog->AddLogLine("[DB]         select_str : "+select_str);
    while(query.next()){
        SaleContent temp;
        if(count == 12){
            // new format
            temp.pin = query.value(0).toString();
            temp.time = query.value(1).toString();
            temp.menu = query.value(2).toString();
            temp.price = query.value(3).toInt();
            temp.card_comp = query.value(4).toString();
            temp.card_num = query.value(5).toString();
            temp.app_num = query.value(6).toString();
            temp.tran_date = query.value(7).toString();
            temp.is_cancel = query.value(8).toString();
            temp.acqu_code = query.value(9).toString();
            temp.card_gb = query.value(10).toString();
            temp.version = query.value(11).toInt();
        }else{
            // new format
            temp.pin = query.value(0).toString();
            temp.time = query.value(1).toString();
            temp.menu = query.value(2).toString();
            temp.price = query.value(3).toInt();
            temp.card_comp = query.value(4).toString();
            temp.card_num = query.value(5).toString();
            temp.app_num = query.value(6).toString();
            temp.tran_date = query.value(7).toString();
            temp.is_cancel = query.value(8).toString();
            temp.acqu_code = query.value(9).toString();
            temp.card_gb = query.value(10).toString();
//            temp.menu_boba = query.value(11).toString();
//            temp.menu_syrup = query.value(12).toString();
        }
//        rblog->AddLogLine("[DB]         ReloadContent : "+temp.menu);
        query_count++;
        SaleContentList.push_back(temp);
    }
    rblog->AddLogLine("[DB]         reloadcontent load : "+QString().sprintf("%d",query_count));
}

int RBSaleLog::GetDateIndex(QDate _date){
    for(int i=0;i<SaleDateList.size();i++){
        int y;
        int m;
        int d;
        sscanf(SaleDateList[i].toStdString().data(), "RB%d_%d_%d", &y, &m, &d);

        QDate dbdate;
        dbdate.setDate(y,m,d);

        if(dbdate == _date){
//            rblog->AddLogLine("[DB]             GetDateIndex : "+_date.toString("yyyyMMdd")+QString().sprintf("%d",i));
           return i;
        }
    }
    return -1;
}
void RBSaleLog::ReloadCheckinContent(QDate _date){
//    qDebug() << "date = " << _date;
//    rblog->AddLogLine("[DB]         ReloadCheckDB : " + _date.toString("yyyy-MM-dd"));

    CheckinContentList.clear();

    QString select_str = QString().sprintf("select * from RB%d_%02d_%02d",_date.year(),_date.month(),_date.day());
    qDebug() << select_str;
    QSqlQuery query(CheckDB);

    // count column
    query.exec(select_str);
    query.next();
    int count = 0;
    for(int i=0; i<20; i++){
        if(!(query.value(i).isValid())){
            count = i;
            break;
        }
    }

    query.exec(select_str);
    while(query.next()){
        SaleCheckin temp;

        temp.date = query.value(0).toString();
        temp.time = query.value(1).toString();
        temp.user = query.value(2).toString();
        temp.login = query.value(3).toString();

        CheckinContentList.push_back(temp);
    }
}

void RBSaleLog::ChangeToCreditCancel(int index1, int index2){
    QString select_str("select * from ");
    select_str += SaleDateList[index1];

    qDebug() << select_str;
    QSqlQuery query(LocalDB);
    query.exec(select_str);
    for(int i=0; i<index2; i++){
        query.next();
    }
    QString update_str = QString().sprintf("UPDATE %s set iscancel = \'-\' where appnum = \'%s\'",
                                           SaleDateList[index1].toStdString().data(),
                                           SaleContentList[index2].app_num.toStdString().data());
    qDebug() << "index1,2" << index1 << ", " << index2;
    qDebug() << update_str;
    query.exec(update_str);
    rblog->AddLogLine("[DB]         ChangeToCreditCancel : "+QString().sprintf("%d,%d",index1,index2));
}

QString RBSaleLog::dayCheckOut(QDate _date){
    DayReport.total_sale_amt = 0;
    DayReport.total_sale_cnt = 0;
    DayReport.refund_sale_amt = 0;
    DayReport.refund_sale_cnt = 0;

    DayReport.Card.clear();
    DayReport.Menu.clear();
    DayReport.Day = _date;

    for(int i=0; i<SaleContentList.size(); i++){
        if(SaleContentList[i].is_cancel == "취소"){
            DayReport.refund_sale_amt += SaleContentList[i].price;
            DayReport.refund_sale_cnt++;

            //카드사별 매출 정리
            int index = GetIndexCard(SaleContentList[i].card_comp,SaleContentList[i].is_cancel);

            if(index == -1){
                SaleByCardComp temp;
                temp.card_name = SaleContentList[i].card_comp;
                temp.amt = SaleContentList[i].price;
                temp.sale_gb = SaleContentList[i].is_cancel;
                temp.num = 1;
                DayReport.Card.push_back(temp);
            }else{
                DayReport.Card[index].amt += SaleContentList[i].price;
                DayReport.Card[index].num++;
            }
        }else if(SaleContentList[i].is_cancel == "승인"){
            DayReport.total_sale_amt += SaleContentList[i].price;
            DayReport.total_sale_cnt++;
            qDebug() << DayReport.total_sale_cnt;
            //Menu별 매출 정리
            QStringList menu_list = SaleContentList[i].menu.split("\n");
//            qDebug() << menu_list;

            for(int m=0; m<menu_list.size(); m++){
                QStringList menu_name = menu_list[m].split("+");
//                qDebug() << menu_name;

                //보바 있음
                if(menu_name.size() > 1){
                    //List에 보바 있는지 확인
                    int index = GetIndexMenu("보바");

                    //List에 보바 없음 -> 생성
                    if(index == -1){
                        SaleByMenu temp;
                        temp.menu_name = "보바";
                        temp.amt = 500;
                        temp.num = 1;
                        DayReport.Menu.push_back(temp);
                    }else{
                        DayReport.Menu[index].amt += 500;
                        DayReport.Menu[index].num++;
                    }
                }

                //List에 메뉴 있는지 확인
                int index = GetIndexMenu(menu_name[0]);


                //List에 메뉴 없음 -> 생성
                if(index == -1){
                    SaleByMenu temp;
                    temp.menu_name = menu_name[0];

                    if(SaleContentList[i].version == 1)
                        temp.amt = mapMenuPricenew[menu_name[0]];
                    else
                        temp.amt = mapMenuPrice[menu_name[0]];
                    temp.num = 1;
                    DayReport.Menu.push_back(temp);
                }else{
                    if(SaleContentList[i].version == 1)
                        DayReport.Menu[index].amt += mapMenuPricenew[menu_name[0]];
                    else
                        DayReport.Menu[index].amt += mapMenuPrice[menu_name[0]];
                    DayReport.Menu[index].num++;
                }
            }


            //카드사별 매출 정리
            int index = GetIndexCard(SaleContentList[i].card_comp,SaleContentList[i].is_cancel);

            if(index == -1){
                SaleByCardComp temp;
                temp.card_name = SaleContentList[i].card_comp;
                temp.amt = SaleContentList[i].price;
                temp.sale_gb = SaleContentList[i].is_cancel;
                temp.num = 1;
                DayReport.Card.push_back(temp);
            }else{
                DayReport.Card[index].amt += SaleContentList[i].price;
                DayReport.Card[index].num++;
            }
        }
    }

        rblog->AddLogLine("[DB]         DayCheckout : " + _date.toString("yyyy-MM-dd") + QString().sprintf("%d",DayReport.total_sale_amt));
    return "";
}

QString RBSaleLog::checkOut(QString startDate, QString endDate){
    int st_year;
    int st_month;
    int st_day;
    int end_year;
    int end_month;
    int end_day;
    sscanf(startDate.toStdString().data(), "%d-%d-%d", &st_year, &st_month, &st_day);
    sscanf(endDate.toStdString().data(), "%d-%d-%d", &end_year, &end_month, &end_day);

    int stNum = st_year*10000 + st_month*100 + st_day;
    int endNum = end_year*10000 + end_month*100 + end_day;
    QStringList totList = LocalDB.tables();
    for(int i=totList.size()-1; i>=0; i--){
        int year;
        int month;
        int day;
        QString temp = totList.at(i);
        sscanf(temp.toStdString().data(), "RB%d_%d_%d", &year, &month, &day);
        int curNum = year*10000 + month*100 + day;
        if(curNum >= stNum && curNum <=endNum){
            ;
        }else{
            totList.removeAt(i);
        }
    }

    int total_amt = 0;
    int total_cnt = 0;
    int free_amt = 0;
    int free_cnt = 0;
    int refund_amt = 0;
    int refund_cnt = 0;
    QVector<SaleByCardComp> sbc;

    for(int i=0; i<totList.size(); i++){
        QString select_str("select * from ");
        select_str += totList[i];

        QSqlQuery query(LocalDB);

        // count column
        query.exec(select_str);
        query.next();
        int count = 0;
        for(int i=0; i<20; i++){
            if(!(query.value(i).isValid())){
                count = i;
                break;
            }
        }


        query.exec(select_str);

        while(query.next()){
            int price;
            QString is_cancel;
            QString card_comp;
            if(count == 8){
                // old format
                price = query.value(2).toInt();
                is_cancel = query.value(7).toString();
                card_comp = query.value(3).toString();
            }else{
                // new format
                price = query.value(3).toInt();
                is_cancel = query.value(8).toString();
                card_comp = query.value(4).toString();
            }

            if(is_cancel == "환불"){
                refund_amt += price;
                refund_cnt++;
            }else{
                if((card_comp == "레인보우은행") || (card_comp == "")){
                    free_amt += price;
                    free_cnt++;
                }else{
                    total_amt += price;
                    total_cnt++;


                    // 카드사별로 금액 분류
                    bool has_list = false;
                    int list_index = 0;
                    for(int i=0; i<sbc.size(); i++){
                        if(card_comp == sbc[i].card_name){
                            has_list = true;
                            list_index = i;
                            break;
                        }
                    }

                    if(has_list == true){
                        sbc[list_index].amt += price;
                    }else{
                        SaleByCardComp temp_sbc;
                        temp_sbc.card_name = card_comp;
                        temp_sbc.amt = price;
                        sbc.push_back(temp_sbc);
                    }
                }
            }
        }
    }

    QString retMsg = "";
    retMsg += "결산일 : " + QString().sprintf("%d년 %02d월 %02d일 ~ %d년 %02d월 %02d일\n", st_year, st_month, st_day, end_year, end_month, end_day);
    retMsg += "-----------------------\n";
    retMsg += "판매잔수: " + toMoney(total_cnt) + "\n";
    retMsg += "판매금액: " + toMoney(total_amt) + "\n";
    retMsg += "-----------------------\n";
    retMsg += "무료잔수: " + toMoney(free_cnt) + "\n";
    retMsg += "무료금액: " + toMoney(free_amt) + "\n";
    retMsg += "-----------------------\n";
    retMsg += "환불잔수: " + toMoney(refund_cnt) + "\n";
    retMsg += "환불금액: " + toMoney(refund_amt) + "\n";
    retMsg += "-----------------------\n\n\n";
    retMsg += "-----------------------\n";
    for(int i=0; i<sbc.size(); i++){
        retMsg += sbc[i].card_name + QString().sprintf(": %d\n", sbc[i].amt);
    }

    return retMsg;
}

int RBSaleLog::GetIndexMenu(QString _menu){
    for(int i=0; i<DayReport.Menu.size();i++){
        if(_menu == DayReport.Menu[i].menu_name){
            return i;
        }
    }
    return -1;
}

int RBSaleLog::GetIndexCard(QString _card, QString _gb){
    for(int i=0; i<DayReport.Card.size();i++){
        if(_card == DayReport.Card[i].card_name){
            if(_gb == DayReport.Card[i].sale_gb){
                return i;
            }
        }
    }
    return -1;
}
