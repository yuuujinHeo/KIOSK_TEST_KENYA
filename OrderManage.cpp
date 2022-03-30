#include "OrderManage.h"
#include <QQmlApplicationEngine>
#include "Menu.h"

extern QObject *object;
extern RBLog *rblog;
extern Menu *menu;

QVector<ST_ORDER_INFO> OrderInCart;
QVector<ST_ORDER_INFO> OrderOnProgress;
QVector<ST_ORDER_INFO> OrderOnSalesLog;


OrderManage::OrderManage(QObject *parent)
    : QObject(parent)
{
    OrderInCart.clear();
    OrderOnProgress.clear();
    OrderOnSalesLog.clear();
}


// 장바구니에 음료 추가
int OrderManage::addOrderToCart(QString menu_id, QString menu_name){
    // 장바구니에 담을 수 있는 최대 음료 수량 확인
    int quantity = OrderInCart.size();

    if(quantity >= MAX_ORDER_QUANTITY){
        // 장바구니에 담을 수 있는 최대 수량이 이미 차 있어서 추가가 안됨
        return -1;
    }

    qDebug() << menu_name;
    ST_ORDER_INFO temp_order;
    temp_order.menu_id = menu_id;
    temp_order.menu_name = menu_name;
    temp_order.option = "";

    OrderInCart.push_back(temp_order);

    qDebug() << "AddOrderToCart Result";
    for(int i=0; i<OrderInCart.size(); i++){
        qDebug() << OrderInCart[i].menu_name;
    }

    // 장바구니 UI 업데이트
    QMetaObject::invokeMethod(object, "cartUpdate");
    return 1;
}


// 장바구니에서 음료 제거
int OrderManage::removeOrderFromCart(int num){
    if(num > OrderInCart.size()-1){
        return false;
    }
    OrderInCart.remove(num);
    rblog->AddLogLine("[OrderManage] removeOrder : " + QString().sprintf("%d",num));

    // 장바구니 UI 업데이트
    QMetaObject::invokeMethod(object, "cartUpdate");
    return 1;
}


// 장바구니 비우기
void OrderManage::clearCart(){
    OrderInCart.clear();
    rblog->AddLogLine("[OrderManage] clearCart");

    // 장바구니 UI 업데이트
    QMetaObject::invokeMethod(object, "cartUpdate");
}


// OrderInCart 내용 QML로 전달
int OrderManage::getCartMaxItemSize(){
    return MAX_ORDER_QUANTITY;
}
int OrderManage::getCartItemSize(){
    return OrderInCart.size();
}
QString OrderManage::getCartItemMenu(int num){
    QString ret = "";
    ret = OrderInCart[num].menu_name;
    return ret;
}

QString OrderManage::getCartItemName(int num){
    QString ret = "";
    ret = OrderInCart[num].menu_name;
    return ret;
}

QString OrderManage::getCartItemImageSrc(int num){
//    QString menu = OrderInCart[num].menu_id;
//    return pmenu->getMenuImage(menu);
    return "";
}


bool OrderManage::hasAnyOrder(){
    if(OrderInCart.size() > 0){
        return true;
    }else{
        return false;
    }
}
