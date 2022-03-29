#ifndef RBPRINTER_H
#define RBPRINTER_H

#include <windows.h>
#include <QObject>

#include "GlobalHeader.h"


class RBPrinter : QObject
{
    Q_OBJECT
public:
    RBPrinter();

    int Status;

    int CountLength(QString name);

    int  RBOpenPort(QString com);
//    void RBClosePort();

    int RBPrintCheckOut(QString content);
    int RBPrintReceipt(QString pin, QVector<ST_ORDER_INFO> menu_list, int price, QString card_comp, QString card_num, QString approve_num, QString tran_date);
    int RBPrintCancelReceipt(int mode, QVector<ST_ORDER_INFO> menu_list, int price, QString card_comp, QString card_num, QString approve_num, QString tran_date);
    int RBPrintText();
    int RBPrintDayReport(SaleReport _report);
    int RBPrintCardReport(SaleReport _report);

    void RBCheckStatus();
};

#endif // RBPRINTER_H
