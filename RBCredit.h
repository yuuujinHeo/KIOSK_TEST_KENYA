#ifndef RBCREDIT_H
#define RBCREDIT_H

#include <windows.h>
#include <QObject>
#include <QString>
#include <QTimer>
#include <QtNetwork>
#include <QEventLoop>
#include <QTextCodec>
#include "globalheader.h"


typedef enum{
    CREDIT_TYPE_CREDIT_APPROVE = 0,
    CREDIT_TYPE_CREDIT_CANCEL
}CREDIT_TYPE;

typedef enum{
    CREDIT_RESULT_NON = 0,
    CREDIT_RESULT_SUCCESS,
    CREDIT_RESULT_FAIL
}CREDIT_RESULT;

typedef struct{
    int		m_tot_amt;
    QString	m_appnum;
    QString	m_cardnum;
    QString	m_month;
    QString m_return_code;
    QString	m_resp_msg;
    int		m_tax;
    QString	m_tran_date;
    QString	m_card_name;
    QString m_card_code;
    QString m_error_msg;
    QString m_acqu_code;
    QString m_acqu_name;
    QString m_card_gb;


    int credit_result;
    int credit_type;


    int CREDIT_TOT_AMT;
    int CREDIT_TAX;
    int CREDIT_APPROVE_FLAG;
    int CREDIT_CANCEL_FLAG;
    QString CREDIT_APPNUM;
    QString CREDIT_APPDATE;
}CREDIT_DATA;

class RBCredit : public QObject
{
    Q_OBJECT
public:
    RBCredit();

    QVector<CREDIT_DATA> credit_queue;

    int NiceCreditApprove(int tot_amt, int tax);
    int NiceCreditCancel(int tot_amt, QString appnum, QString appdate);

    void NiceStopCredit();
    int NiceReadStatus();


    CREDIT_DATA initcreditdata(int tot_amt, int tax);
    CREDIT_DATA inittestdata();
    CREDIT_DATA initcanceldata(int tot_amt, QString appnum, QString appdate);
    void setCreditQueue(CREDIT_DATA _data);
    CREDIT_DATA getCreditQueue();
    void delete0CreditQueue();

public slots:
    void onThread();

private:
    void reset_values(int idx);


};

#endif // RBCREDIT_H
