#ifndef RBROBOTCONNECTOR_H
#define RBROBOTCONNECTOR_H

#include <QObject>
#include <QTimer>

// json -----------------------
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

// websocket ------------------
#include <QtHttpServer.h>
#include <QtHttpRequest.h>
#include <QtHttpReply.h>
#include <QtHttpHeader.h>

#include "GlobalHeader.h"

enum{RBLAN_SUCCESS = 0, RBLAN_FAIL};
enum{RBLAN_CS_CONNECTED = 0, RBLAN_CS_DISCONNECTED};



enum{
    ACTION_STATE_IDLE = 0,
    ACTION_STATE_GET_CUP,
    ACTION_STATE_GET_DRINK,
    ACTION_STATE_GET_WATER,
    ACTION_STATE_GO_OUTLET,
    ACTION_NUM
};
const QString ACTION_STATE_NAME[ACTION_NUM] = {
    "IDLE",
    "GET_CUP",
    "GET_DRINK",
    "GET_WATER",
    "GO_OUTLET"
};

enum{
    ED_STATE_IDLE = 0,
    ED_STATE_ON_PREPARING,
    ED_STATE_ON_WAITING,
    ED_STATE_ON_RETURNING,
    ED_NUM
};
const QString ED_STATE_NAME[ED_NUM] = {
    "IDLE",
    "ON_PREPARING",
    "ON_WAITING",
    "ON_RETURNING"
};

enum{
    BOBA_STATE_IDLE = 0,
    BOBA_STATE_MAINTENANCE,
    BOBA_STATE_CLEANING,
    BOBA_STATE_FULL,
    BOBA_STATE_RESTART,
    BOBA_STATE_PREPARING_CLEANING,
    BOBA_STATE_PREPARING_OPERATION,
    BOBA_STATE_DISCONNECTED
};


class RBTCPServer;

class RBRobotConnector : QObject
{
    Q_OBJECT
public:
    RBRobotConnector();

    bool is_connected;

    //int ROBOT_STATE;
    int ACTION_STATE;
    int ED_STATE;

    int fixxingOnFlag;
    int fixxingOffFlag;
    int State_Boba = BOBA_STATE_IDLE;
    QString Platform_state;

    bool is_printer_error;

    void generalReply(QtHttpReply *reply, QByteArray post_data);

    void replyRequestOrder(QtHttpReply *reply);
    void replyDeleteOrder(QtHttpReply *reply, QJsonObject json);
    void replyRequestError(QtHttpReply *reply);
    void replySetState(QtHttpReply *reply);
    void setState(QJsonObject json);


    QVector<ST_ORDER_SET> orders;

    QMap<QString, bool> soldout_map;


public slots:
    void onCheck();
    void onRequestReply(QtHttpRequest *request, QtHttpReply *reply);


private:
    QTimer *checkTimer;

    QtHttpServer    *server;

    int connection_count;
};






#endif // RBROBOTCONNECTOR_H
