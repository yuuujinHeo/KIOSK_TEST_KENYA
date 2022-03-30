#ifndef ORDERMANAGE_H
#define ORDERMANAGE_H

#include <QObject>
#include <QVector>
#include <QDebug>

#include "GlobalHeader.h"




class OrderManage : public QObject
{
    Q_OBJECT
public:
    explicit OrderManage(QObject *parent = nullptr);


    Q_INVOKABLE int addOrderToCart(QString menu_id, QString menu_name);
    Q_INVOKABLE int removeOrderFromCart(int num);
    Q_INVOKABLE void clearCart();

    Q_INVOKABLE int getCartMaxItemSize();
    Q_INVOKABLE int getCartItemSize();
    Q_INVOKABLE QString getCartItemMenu(int num);
    Q_INVOKABLE QString getCartItemName(int num);

    Q_INVOKABLE QString getCartItemImageSrc(int num);

    Q_INVOKABLE bool hasAnyOrder();
};

#endif // ORDERMANAGE_H
