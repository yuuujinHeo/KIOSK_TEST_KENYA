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

    int RBPrintReceipt(QString pin, QVector<ST_ORDER_INFO> menu_list);
    int RBPrintText();
    void RBCheckStatus();
};

#endif // RBPRINTER_H
