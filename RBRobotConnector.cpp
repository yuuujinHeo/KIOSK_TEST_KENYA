#include "RBRobotConnector.h"
#include <QDataStream>
#include <iostream>

using namespace std;
extern RBLog *rblog;

RBRobotConnector::RBRobotConnector()
{
    orders.clear();


    connection_count = 10;
    is_connected = false;


    fixxingOnFlag = false;
    fixxingOffFlag = false;


    // 키오스크 서버 (포트 8000)
    server = new QtHttpServer(this);
    connect(server, SIGNAL(requestNeedsReply(QtHttpRequest *, QtHttpReply *)), this, SLOT(onRequestReply(QtHttpRequest *, QtHttpReply *)));
    server->start(8000);


    checkTimer = new QTimer(this);
    connect(checkTimer, SIGNAL(timeout()), this, SLOT(onCheck()));
    checkTimer->start(1000);
}


void RBRobotConnector::generalReply(QtHttpReply *reply, QByteArray post_data){
    QByteArray postDataSize = QByteArray::number(post_data.size());

    reply->addHeader(QtHttpHeader::ContentType, QByteArrayLiteral("application/json"));
    reply->addHeader(QtHttpHeader::ContentLength, postDataSize);
    reply->addHeader(QtHttpHeader::Connection, QByteArrayLiteral("Keep-Alive"));
    reply->addHeader(QtHttpHeader::AcceptEncoding, QByteArrayLiteral("gzip, deflate"));
    reply->addHeader(QtHttpHeader::AcceptLanguage, QByteArrayLiteral("ko-KR,en,*"));

    reply->appendRawData(post_data);

    emit reply->requestSendHeaders();
    emit reply->requestSendData();
}


// 키오스크 서버 - 클라이언트 요청 수신 --> 응답
void RBRobotConnector::onRequestReply(QtHttpRequest *request, QtHttpReply *reply){
    QByteArray rcvData = request->getRawData();
    QJsonObject json_input = QJsonDocument::fromJson(rcvData).object();

    QString msgType = json_input["MSG_TYPE"].toString();

    qDebug() << json_input;

    if(msgType == "REQUEST_ORDER"){
        replyRequestOrder(reply);
    }else if(msgType == "DELETE_ORDER"){
        replyDeleteOrder(reply, json_input);
    }else if(msgType == "SET_STATE"){
        setState(json_input);
        replySetState(reply);
    }else if(msgType == "REQUEST_ERROR"){
        replyRequestError(reply);
    }

    connection_count = 0;
}

// 주문 요청에 대한 응답
void RBRobotConnector::replyRequestOrder(QtHttpReply *reply){
    QJsonObject json_output;
    json_output["MSG_TYPE"] = "REPLY_REQUEST_ORDER";

    if(orders.size() > 0){
        json_output["HAS_ANY_ORDER_YN"] = "Y";
        ST_ORDER_SET temp_order = orders[0];

//        json_output["PLATFORM_ID"] = temp_order.PlatformID;
//        json_output["PHONE_NUMBER"] = temp_order.PhoneNumber;
//        json_output["DATE"] = temp_order.Date;
        json_output["TRANSACTION_NUMBER"] = temp_order.TransactionNumber.right(5);

        QJsonArray menu_array;
        QString menu_str;
        for(int i=0; i<temp_order.OrderInfo.size(); i++){
            int option_ice = temp_order.OrderInfo[i].optionIce;
            int option_boba = temp_order.OrderInfo[i].optionBoba;
            int option_syrup = temp_order.OrderInfo[i].optionSyrup;

            QJsonObject menu_obj;
            menu_str += temp_order.OrderInfo[i].menu;
            qDebug() << temp_order.OrderInfo[i].menu;
            qDebug() << mapMenuEng[temp_order.OrderInfo[i].menu];
            menu_obj["DRINK_NAME"] = mapMenuEng[temp_order.OrderInfo[i].menu];//temp_order.OrderInfo[i].menu;
            menu_obj["DRINK_ID"] = temp_order.TransactionNumber.right(5);
            menu_obj["DRINK_SIZE"] = "";


            menu_obj["TYPE_CUP"] = "COLD";
            menu_obj["SIZE_CUP"] = "REGULAR";

            menu_obj["TYPE_ICE"] = "NUGGET";
            if(option_ice == 0){
                menu_obj["SIZE_ICE"] = "REGULAR";
            }else{
                menu_obj["SIZE_ICE"] = "EXTRA";
            }

            menu_obj["TYPE_BOBA"] = "CRYSTAL";
            if(option_boba == 1){
                menu_obj["SIZE_BOBA"] = "REGULAR";
            }else{
                menu_obj["SIZE_BOBA"] = "NONE";
            }

            menu_obj["TYPE_SYRUP"] = "SUGAR";
            if(option_syrup == 1){
                menu_obj["SIZE_SYRUP"] = "LESS";
            }else if(option_syrup == 2){
                menu_obj["SIZE_SYRUP"] = "REGULAR";
            }else if(option_syrup == 3){
                menu_obj["SIZE_SYRUP"] = "EXTRA";
            }else{
                menu_obj["SIZE_SYRUP"] = "NONE";
            }

//            menu_obj["TYPE_TEA"] = mapMenuEng[temp_order.OrderInfo[i].menu];
//            menu_obj["SIZE_TEA"] = "";
//            menu_obj["TYPE_MILK"] = "WHOLE";
//            menu_obj["SIZE_MILK"] = "";

            menu_array.append(menu_obj);
        }
        json_output["ORDER_DATA"] = menu_array;

        rblog->AddLogLine("[KIOSKtoPC]  SendOrder : " + menu_str);
    }else{
        json_output["HAS_ANY_ORDER_YN"] = "N";
    }

    qDebug() << json_output;
    QByteArray json_string = QJsonDocument(json_output).toJson();
    generalReply(reply, json_string);
}

// 주문 삭제에 대한 응답
void RBRobotConnector::replyDeleteOrder(QtHttpReply *reply, QJsonObject json){
    QJsonObject json_output;
    json_output["MSG_TYPE"] = "REPLY_DELETE_ORDER";

    QString transaction_number = json["DELETE_TRANSACTION_NUMBER"].toString();

    if(orders.size() > 0){
        ST_ORDER_SET temp_order = orders[0];
        if((temp_order.TransactionNumber.right(5) == transaction_number)){
            // 매칭되는 주문이 있으므로 삭제
            rblog->AddLogLine("[PCtoKIOSK]  DeleteOrder(SUCCESS): %d" + orders[0].TransactionNumber);
            orders.pop_front();
            json_output["RET_RESULT"] = "SUCCESS";
        }else{
            // 매칭되는 주문이 없음
            rblog->AddLogLine("[PCtoKIOSK]  DeleteOrder(NO MATCH): %d" + orders[0].TransactionNumber);
            json_output["RET_RESULT"] = "NO_MATCHING_ORDER";
        }
    }else{
        // 주문이 없는데 삭제 요청이 들어옴
        rblog->AddLogLine("[PCtoKIOSK]  DeleteOrder(NO ORDER)");
        json_output["RET_RESULT"] = "ZERO_ORDER";
    }

    QByteArray json_string = QJsonDocument(json_output).toJson();
    generalReply(reply, json_string);
}

// 에러 요청에 대한 응답
void RBRobotConnector::replyRequestError(QtHttpReply *reply){
    QJsonObject json_output;
    json_output["MSG_TYPE"] = "REPLY_REQUEST_ERROR";

    if(is_printer_error == true){
        json_output["PRINTER_ERROR_YN"] = "Y";
    }else{
        json_output["PRINTER_ERROR_YN"] = "N";
    }

    QByteArray json_string = QJsonDocument(json_output).toJson();
    generalReply(reply, json_string);
}

// 상태 값 전달에 대한 응답
void RBRobotConnector::replySetState(QtHttpReply *reply){
    QJsonObject json_output;
    json_output["MSG_TYPE"] = "REPLY_SET_STATE";


    QByteArray json_string = QJsonDocument(json_output).toJson();
    generalReply(reply, json_string);
}

// 상태 값 설정
void RBRobotConnector::setState(QJsonObject json){
    QJsonArray soldout_array = json["SOLDOUT_MENU"].toArray();
    for(int i=0; i<soldout_array.size(); i++){
        QJsonObject soldout_detail = soldout_array[i].toObject();
        QString so_menu = soldout_detail["MENU"].toString();
        QString so_yn = soldout_detail["SOLDOUT_YN"].toString();

//        qDebug()<<so_yn;
        if(so_yn == "Y"){
            soldout_map[so_menu] = true;
        }else{
            soldout_map[so_menu] = false;
        }
//        qDebug() << "soldout :: " << so_menu << ":" << so_yn;
    }

    qDebug() << soldout_map["BOBA"];
    qDebug() << soldout_map["SYRUP"];


    qDebug() << json["PLATFORM_STATUS"].toString();


    if(json["PLATFORM_STATUS"].toString() == "NEED_MAINTENANCE"){
        State_Boba = BOBA_STATE_MAINTENANCE;
        rblog->AddLogLine("[PCtoKIOSK]  SetMode : Maintenance");
    }else if(json["PLATFORM_STATUS"].toString() == "IN_CLEANING"){
        State_Boba = BOBA_STATE_CLEANING;
        qDebug() << "Cleaning";
        rblog->AddLogLine("[PCtoKIOSK]  SetMode : Cleaning");
    }else if(json["PLATFORM_STATUS"].toString() == "PREPARING_CLEANING"){
        State_Boba = BOBA_STATE_PREPARING_CLEANING;
        rblog->AddLogLine("[PCtoKIOSK]  SetMode : preCleaning");
    }else if(json["PLATFORM_STATUS"].toString() == "PREPARING_OPERATION"){
        State_Boba = BOBA_STATE_PREPARING_OPERATION;
        rblog->AddLogLine("[PCtoKIOSK]  SetMode : preOperation");
    }else if(json["PLATFORM_STATUS"].toString() == "PLEASE_WAIT"){
        State_Boba = BOBA_STATE_FULL;
        rblog->AddLogLine("[PCtoKIOSK]  SetMode : please wait");
    }else if(json["PLATFORM_STATUS"].toString() == "IN_OPERATION" || json["PLATFORM_STATUS"].toString() == "OK"){
        if(State_Boba != BOBA_STATE_IDLE){
            State_Boba = BOBA_STATE_RESTART;
            rblog->AddLogLine("[PCtoKIOSK]  SetMode : restart"+json["PLATFORM_STATUS"].toString());
        }else{
            State_Boba = BOBA_STATE_IDLE;
        }
    }
}



void RBRobotConnector::onCheck(){
    static int cnt = 0;
    cnt++;

    connection_count++;
    // 30초 동안 MixxAdmin으로부터 아무런 메시지가 없으면 로봇 연결이 끊어진 것으로 간주
    if(connection_count > 5){
        is_connected = false;
    }else{
        is_connected = true;
    }
}



