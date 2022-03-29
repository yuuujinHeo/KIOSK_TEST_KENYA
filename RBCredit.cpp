#include "RBCredit.h"
#include <iostream>


#define NICECAT __declspec(dllimport)

typedef void (__stdcall *FUNCTION_CALLBACK)(int val);

extern "C" NICECAT int __stdcall NICEVCAT(char *send_data, char *recv_data);
extern "C" NICECAT int __stdcall RESTART();
extern "C" NICECAT int __stdcall REQ_STOP();
extern "C" NICECAT void __stdcall CallBackReg(void __stdcall callback(int val));
//extern "C" NICECAT void __stdcall CallBackReg(FUNCTION_CALLBACK);
extern "C" NICECAT void __stdcall ReaderPortOpen();
extern "C" NICECAT void __stdcall ReaderPortClose();
extern "C" NICECAT int __stdcall CHK_CARDBIN(char *recv_data);
extern "C" NICECAT int __stdcall CHK_CARDIN();
//extern "C" NICECAT void __stdcall READ_STATUS(char *msgstatus, char *msg);

using namespace std;
extern RBLog *rblog;

extern "C" void __stdcall callback(int val){
    cout << "WOW" << endl;
    cout << "EVENT --> " << val << endl;
    return;
}




RBCredit::RBCredit()
{
//    credit_result= CREDIT_RESULT_NON;
    credit_queue.clear();
//    CREDIT_DATA init = initdata();
//    credit_queue

//    CallBackReg(callback);

//    credit_queue[0].CREDIT_TOT_AMT = 0;
//    credit_queue[0].CREDIT_TAX = 0;
//    credit_queue[0].CREDIT_APPROVE_FLAG = 0;
//    credit_queue[0].CREDIT_CANCEL_FLAG = 0;
}

void RBCredit::onThread(){
    static int cnt = 0;


//    CallBackReg(callback);


    while(1){
        Sleep(100);

//        if(CREDIT_APPROVE_FLAG == 1){
//            int ret = NiceReadStatus();
//            if(ret == 1){
//                CREDIT_APPROVE_FLAG = 2;
//            }else{
//                ;
//            }
//        }else if(CREDIT_APPROVE_FLAG == 2){
        if(credit_queue[0].CREDIT_APPROVE_FLAG == 1){
            credit_queue[0].CREDIT_APPROVE_FLAG = 0;

            rblog->AddLogLine("[RBCredit]   Approve : " + QString().sprintf("%d",credit_queue[0].CREDIT_TOT_AMT));
            int ret = NiceCreditApprove(credit_queue[0].CREDIT_TOT_AMT, credit_queue[0].CREDIT_TAX);
            rblog->AddLogLine("[RBCredit]   Approve result : " + QString().sprintf("%d",ret));
            if(ret == 1 && credit_queue[0].m_return_code == "0000"){
                credit_queue[0].credit_type = CREDIT_TYPE_CREDIT_APPROVE;
                credit_queue[0].credit_result = CREDIT_RESULT_SUCCESS;

            }else{
                credit_queue[0].credit_type = CREDIT_TYPE_CREDIT_APPROVE;
                credit_queue[0].credit_result = CREDIT_RESULT_FAIL;

                if(ret == -1){
                    credit_queue[0].m_error_msg = "NVCAT 실행중이 아님";
                }else if(ret == -2){
                    credit_queue[0].m_error_msg = "거래금액이 존재하지 않음";
                }else if(ret == -3){
                    credit_queue[0].m_error_msg = "환경정보 읽기 실패";
                }else if(ret == -4){
                    credit_queue[0].m_error_msg = "NVCAT 연동 오류 실패 (망상 취소 필요)";
                }else if(ret == -5){
                    credit_queue[0].m_error_msg = "기타 응답데이터 오류 (망상 취소 필요)";
                }else if(ret == -6){
                    credit_queue[0].m_error_msg = "카드리딩 타임아웃";
                }else if(ret == -7){
                    credit_queue[0].m_error_msg = "사용자 및 리더기 취소 요청";
                }else if(ret == -8){
                    credit_queue[0].m_error_msg = "IC 인식 실패";
                }else if(ret == -9){
                    credit_queue[0].m_error_msg = "기타 오류";
                }else if(ret == -10){
                    credit_queue[0].m_error_msg = "IC 우선 거래 요청 필요";
                }else if(ret == -11){
                    credit_queue[0].m_error_msg = "FALLBACK 거래 아님";
                }else if(ret == -12){
                    credit_queue[0].m_error_msg = "거래불가 카드";
                }else if(ret == -13){
                    credit_queue[0].m_error_msg = "서명 요청 오류";
                }else if(ret == -14){
                    credit_queue[0].m_error_msg = "요청 전문 데이터 포맷 오류";
                }else if(ret == -15){
                    credit_queue[0].m_error_msg = "카드리더 PORT OPEN 오류";
                }else if(ret == -16){
                    credit_queue[0].m_error_msg = "직전거래 망상취소 불가";
                }else if(ret == -17){
                    credit_queue[0].m_error_msg = "중복 요청 불가";
                }else if(ret == -18){
                    credit_queue[0].m_error_msg = "지원되지 않는 카드";
                }else if(ret == -19){
                    credit_queue[0].m_error_msg = "현금IC카드 복수계좌 미지원";
                }else if(ret == -20){
                    credit_queue[0].m_error_msg = "TIT 카드리더기 오류";
                }else if(ret == -21){
                    credit_queue[0].m_error_msg = "NVACT 내부 망상취소 실패 (해당카드사 확인 요망)";
                }else{
                    credit_queue[0].m_error_msg = QString().sprintf("미확인 오류 : %d", ret);
                }
            }
        }
        else if(credit_queue[0].CREDIT_CANCEL_FLAG == true){
            credit_queue[0].CREDIT_CANCEL_FLAG = false;

            rblog->AddLogLine("[RBCredit]   Cancel : " + QString().sprintf("%d",credit_queue[0].CREDIT_TOT_AMT));

            int ret = NiceCreditCancel(credit_queue[0].CREDIT_TOT_AMT, credit_queue[0].CREDIT_APPNUM, credit_queue[0].CREDIT_APPDATE);
            rblog->AddLogLine("[RBCredit]   Cancel result : " + QString().sprintf("%d",ret));
            if(ret == 1 && credit_queue[0].m_return_code == "0000"){
                credit_queue[0].credit_type = CREDIT_TYPE_CREDIT_CANCEL;
                credit_queue[0].credit_result = CREDIT_RESULT_SUCCESS;
                //cancel recipt print
            }else{
                credit_queue[0].credit_type = CREDIT_TYPE_CREDIT_CANCEL;
                credit_queue[0].credit_result = CREDIT_RESULT_FAIL;
                qDebug() << "RESPONSE CODE: " << credit_queue[0].m_resp_msg;
            }
        }
    }
}


int RBCredit::NiceCreditApprove(int tot_amt, int tax){

    credit_queue[0].credit_result = 0;
    credit_queue[0].credit_type = CREDIT_TYPE_CREDIT_APPROVE;

    QByteArray sendData;
    unsigned char FS = 28;
    sendData += "0200";
    sendData += FS;
    sendData += "10";
    sendData += FS;
    sendData += "C";
    sendData += FS;
    sendData += QString().sprintf("%d", tot_amt);
    sendData += FS;
    sendData += QString().sprintf("%d", tax);
    sendData += FS;
    sendData += FS;
    sendData += "00";
    sendData += FS;
    sendData += FS;
    sendData += FS;
    sendData += FS;
    sendData += FS;

    sendData += FS;
    sendData += FS;
    sendData += FS;
    sendData += FS;
    sendData += FS;

    sendData += FS;
    sendData += FS;
    sendData += FS;
    sendData += FS;
    sendData += FS;

    sendData += FS;
    sendData += FS;
    sendData += FS;

    char recv_data[1024] = {0,};
    int ret = NICEVCAT(sendData.data(), recv_data);

    if(ret == 1){
        QByteArray temp(recv_data);
        QList<QByteArray> list = temp.split(28);

        qDebug() << "RETURN: " << ret;
        qDebug() << "APPROVE/CANCEL : " << QString::fromLocal8Bit(list[0].data());
        qDebug() << "CREDIT_CARD    : " << QString::fromLocal8Bit(list[1].data());
        qDebug() << "RETURN CODE    : " << QString::fromLocal8Bit(list[2].data());
        qDebug() << "TOTAL AMOUNT   : " << QString::fromLocal8Bit(list[3].data());
        qDebug() << "TAX            : " << QString::fromLocal8Bit(list[4].data());
        qDebug() << "SERVICE        : " << QString::fromLocal8Bit(list[5].data());
        qDebug() << "SEPERATE       : " << QString::fromLocal8Bit(list[6].data());
        qDebug() << "APPROVE NUM    : " << QString::fromLocal8Bit(list[7].data());
        qDebug() << "APPROVE DATE   : " << QString::fromLocal8Bit(list[8].data());
        qDebug() << "CARD COMP NUM  : " << QString::fromLocal8Bit(list[9].data());
        qDebug() << "CART COMP NAME : " << QString::fromLocal8Bit(list[10].data());
        qDebug() << "매입사 코드      : " << QString::fromLocal8Bit(list[11].data());
        qDebug() << "매입사 명       : " << QString::fromLocal8Bit(list[12].data());
        qDebug() << "가맹점 번호     : " << QString::fromLocal8Bit(list[13].data());
        qDebug() << "승인 CATID     : " << QString::fromLocal8Bit(list[14].data());
        qDebug() << "잔액           : " << QString::fromLocal8Bit(list[15].data());
        qDebug() << "응답메시지      : " << QString::fromLocal8Bit(list[16].data());
        qDebug() << "카드 빈         : " << QString::fromLocal8Bit(list[17].data());
        qDebug() << "카드구분(신용)   : " << QString::fromLocal8Bit(list[18].data());
        qDebug() << "전문관리번호     : " << QString::fromLocal8Bit(list[19].data());
        qDebug() << "거래일련번호     : " << QString::fromLocal8Bit(list[20].data());
        qDebug() << "기기번호        : " << QString::fromLocal8Bit(list[21].data());

        credit_queue[0].m_tot_amt = QString::fromLocal8Bit(list[3].data()).toInt();
        credit_queue[0].m_tax = QString::fromLocal8Bit(list[4].data()).toInt();
        credit_queue[0].m_appnum = QString::fromLocal8Bit(list[7].data()).trimmed();
        credit_queue[0].m_cardnum = QString::fromLocal8Bit(list[17].data());
        credit_queue[0].m_month = QString::fromLocal8Bit(list[6].data());
        credit_queue[0].m_return_code = QString::fromLocal8Bit(list[2].data());
        credit_queue[0].m_resp_msg = QString::fromLocal8Bit(list[16].data());
        credit_queue[0].m_tran_date = QString::fromLocal8Bit(list[8].data());
        credit_queue[0].m_card_name = QString::fromLocal8Bit(list[10].data());
        credit_queue[0].m_card_name = QString::fromLocal8Bit(list[9].data());
        credit_queue[0].m_acqu_code = QString::fromLocal8Bit(list[11].data());
        credit_queue[0].m_acqu_name = QString::fromLocal8Bit(list[12].data());
        credit_queue[0].m_card_gb = QString::fromLocal8Bit(list[18].data());
    }else{
        qDebug() << "RETURN: " << ret;
        reset_values(0);
    }
    return ret;
}


int RBCredit::NiceCreditCancel(int tot_amt, QString appnum, QString appdate){

    credit_queue[0].credit_result = 0;
    credit_queue[0].credit_type = CREDIT_TYPE_CREDIT_APPROVE;

    QByteArray sendData;
    unsigned char FS = 28;
    sendData += "0420";
    sendData += FS;
    sendData += "10";
    sendData += FS;
    sendData += "C";
    sendData += FS;
    sendData += QString().sprintf("%d", tot_amt);
    sendData += FS;
//    sendData += QString().sprintf("%d", tax);
    sendData += FS;
    sendData += FS;
    sendData += "00";
    sendData += FS;
    sendData += appnum;
    sendData += FS;
    sendData += appdate;
    sendData += FS;
    sendData += FS;
    sendData += FS;

    sendData += FS;
    sendData += FS;
    sendData += FS;
    sendData += FS;
    sendData += FS;

    sendData += FS;
    sendData += FS;
    sendData += FS;
    sendData += FS;
    sendData += FS;

    sendData += FS;
    sendData += FS;
    sendData += FS;

    char recv_data[1024] = {0,};
    int ret = NICEVCAT(sendData.data(), recv_data);

    if(ret == 1){
        QByteArray temp(recv_data);
        QList<QByteArray> list = temp.split(28);

        qDebug() << "RETURN: " << ret;
        qDebug() << "APPROVE/CANCEL : " << QString::fromLocal8Bit(list[0].data());
        qDebug() << "CREDIT_CARD    : " << QString::fromLocal8Bit(list[1].data());
        qDebug() << "RETURN CODE    : " << QString::fromLocal8Bit(list[2].data());
        qDebug() << "TOTAL AMOUNT   : " << QString::fromLocal8Bit(list[3].data());
        qDebug() << "TAX            : " << QString::fromLocal8Bit(list[4].data());
        qDebug() << "SERVICE        : " << QString::fromLocal8Bit(list[5].data());
        qDebug() << "SEPERATE       : " << QString::fromLocal8Bit(list[6].data());
        qDebug() << "APPROVE NUM    : " << QString::fromLocal8Bit(list[7].data());
        qDebug() << "APPROVE DATE   : " << QString::fromLocal8Bit(list[8].data());
        qDebug() << "CARD COMP NUM  : " << QString::fromLocal8Bit(list[9].data());
        qDebug() << "CART COMP NAME : " << QString::fromLocal8Bit(list[10].data());
        qDebug() << "매입사 코드      : " << QString::fromLocal8Bit(list[11].data());
        qDebug() << "매입사 명       : " << QString::fromLocal8Bit(list[12].data());
        qDebug() << "가맹점 번호     : " << QString::fromLocal8Bit(list[13].data());
        qDebug() << "승인 CATID     : " << QString::fromLocal8Bit(list[14].data());
        qDebug() << "잔액           : " << QString::fromLocal8Bit(list[15].data());
        qDebug() << "응답메시지      : " << QString::fromLocal8Bit(list[16].data());
        qDebug() << "카드 빈         : " << QString::fromLocal8Bit(list[17].data());
        qDebug() << "카드구분(신용)   : " << QString::fromLocal8Bit(list[18].data());
        qDebug() << "전문관리번호     : " << QString::fromLocal8Bit(list[19].data());
        qDebug() << "거래일련번호     : " << QString::fromLocal8Bit(list[20].data());
        qDebug() << "기기번호        : " << QString::fromLocal8Bit(list[21].data());

        credit_queue[0].m_tot_amt = QString::fromLocal8Bit(list[3].data()).toInt();
        credit_queue[0].m_tax = QString::fromLocal8Bit(list[4].data()).toInt();
        credit_queue[0].m_appnum = QString::fromLocal8Bit(list[7].data()).trimmed();
        credit_queue[0].m_cardnum = QString::fromLocal8Bit(list[17].data());
        credit_queue[0].m_month = QString::fromLocal8Bit(list[6].data());
        credit_queue[0].m_return_code = QString::fromLocal8Bit(list[2].data());
        credit_queue[0].m_resp_msg = QString::fromLocal8Bit(list[16].data());
        credit_queue[0].m_tran_date = QString::fromLocal8Bit(list[8].data());
        credit_queue[0].m_card_name = QString::fromLocal8Bit(list[10].data());

    }else{
        qDebug() << "RETURN: " << ret;
        reset_values(0);
    }
    return ret;
}

CREDIT_DATA RBCredit::getCreditQueue(){
    return credit_queue[0];
}

void RBCredit::setCreditQueue(CREDIT_DATA _data){
    credit_queue.push_back(_data);
}


void RBCredit::NiceStopCredit(){
    rblog->AddLogLine("[RBCredit]   Requset Stop");
    REQ_STOP();
}

CREDIT_DATA RBCredit::initcreditdata(int tot_amt, int tax){
    CREDIT_DATA temp;
    temp.m_tot_amt = 0;
    temp.m_appnum = "";
    temp.m_cardnum = "";
    temp.m_month = "";
    temp.m_return_code = "";
    temp.m_resp_msg = "";
    temp.m_tax = 0;
    temp.m_tran_date = "";
    temp.m_card_name = "";
    temp.m_error_msg = "";

    temp.CREDIT_TOT_AMT = tot_amt;
    temp.CREDIT_TAX = tax;
    temp.CREDIT_APPROVE_FLAG = 1;
    return temp;
}

CREDIT_DATA RBCredit::initcanceldata(int tot_amt, QString appnum, QString appdate){
    CREDIT_DATA temp;
    temp.m_tot_amt = 0;
    temp.m_appnum = "";
    temp.m_cardnum = "";
    temp.m_month = "";
    temp.m_return_code = "";
    temp.m_resp_msg = "";
    temp.m_tax = 0;
    temp.m_tran_date = "";
    temp.m_card_name = "";
    temp.m_error_msg = "";


    temp.CREDIT_TOT_AMT = tot_amt;
    temp.CREDIT_APPNUM = appnum;
    temp.CREDIT_APPDATE = appdate;
    temp.CREDIT_CANCEL_FLAG = true;
    return temp;
}

CREDIT_DATA RBCredit::inittestdata(){
    CREDIT_DATA temp;
    temp.m_tot_amt = 0;
    temp.m_appnum = "0025316";
    temp.m_cardnum = "";
    temp.m_month = "";
    temp.m_return_code = "";
    temp.m_resp_msg = "";
    temp.m_tax = 0;
    temp.m_tran_date = "";
    temp.m_card_name = "";
    temp.m_error_msg = "";
    temp.credit_type = CREDIT_TYPE_CREDIT_APPROVE;
    temp.credit_result = CREDIT_RESULT_SUCCESS;
    return temp;
}


void RBCredit::reset_values(int idx){
    credit_queue[idx].m_tot_amt = 0;
    credit_queue[idx].m_appnum = "";
    credit_queue[idx].m_cardnum = "";
    credit_queue[idx].m_month = "";
    credit_queue[idx].m_return_code = "";
    credit_queue[idx].m_resp_msg = "";
    credit_queue[idx].m_tax = 0;
    credit_queue[idx].m_tran_date = "";
    credit_queue[idx].m_card_name = "";
    credit_queue[idx].m_error_msg = "";
}

void RBCredit::delete0CreditQueue(){
    rblog->AddLogLine("[RBCredit]   Delete Credit queue : " + credit_queue[0].m_appnum);
    credit_queue.pop_front();
}
