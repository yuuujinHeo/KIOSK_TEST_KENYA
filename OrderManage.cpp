#include "OrderManage.h"
#include <QQmlApplicationEngine>

extern QObject *object;
extern RBLog *rblog;

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
int OrderManage::addOrderToCart(QString menu, int optIce, int optBoba, int optSyrup, int price){
    // 장바구니에 담을 수 있는 최대 음료 수량 확인
    int quantity = OrderInCart.size();
    rblog->AddLogLine("[OrderManage] addOrder : " + menu + QString().sprintf("(%d) %d, %d, %d, %d",quantity,optIce,optBoba,optSyrup,price));

    if(quantity >= MAX_ORDER_QUANTITY){
        // 장바구니에 담을 수 있는 최대 수량이 이미 차 있어서 추가가 안됨
        return -1;
    }

    QStringList list = menu.split("\n");

    qDebug() << list;
    ST_ORDER_INFO temp_order;
    temp_order.menu = list.last();
    temp_order.optionIce = optIce;
    temp_order.optionBoba = optBoba;
    temp_order.optionSyrup = optSyrup;
    temp_order.price = price;

    OrderInCart.push_back(temp_order);
    rblog->AddLogLine("[OrderManage] addOrder : OK");

    qDebug() << "AddOrderToCart Result";
    for(int i=0; i<OrderInCart.size(); i++){
        qDebug() << OrderInCart[i].menu
                << OrderInCart[i].optionIce
                << OrderInCart[i].optionBoba
                << OrderInCart[i].optionSyrup
                << OrderInCart[i].price;
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
    ret = OrderInCart[num].menu;

//    if(OrderInCart[num].optionBoba == 1){
//        ret += "+보바(+500원)";
//    }
    return ret;
}
QString OrderManage::getCartItemOptionString(int num){
    QString ret = "";
    if(OrderInCart[num].optionIce == 0){
        ret += "얼음(보통)";
    }else if(OrderInCart[num].optionIce == 1){
        ret += "얼음(많음)";
    }
    ret += " , ";
    if(OrderInCart[num].optionSyrup == 0){
        ret += "시럽(없음)";
    }else if(OrderInCart[num].optionSyrup == 1){
        ret += "시럽(적음)";
    }else if(OrderInCart[num].optionSyrup == 2){
        ret += "시럽(보통)";
    }else if(OrderInCart[num].optionSyrup == 3){
        ret += "시럽(많음)";
    }
    return ret;
}

QString OrderManage::getCartItemImageSrc(int num){
    QString menu = OrderInCart[num].menu;
    if(menu.indexOf("+") > 0){
        return "";
    }else{
        return mapMenuImage[menu];
    }
}

int OrderManage::getTotalPrice(){
    int tot_price = 0;
    for(int i=0; i<OrderInCart.size(); i++){
        tot_price += OrderInCart[i].price;
    }
    return tot_price;
}

bool OrderManage::hasAnyOrder(){
    if(OrderInCart.size() > 0){
        return true;
    }else{
        return false;
    }
}
