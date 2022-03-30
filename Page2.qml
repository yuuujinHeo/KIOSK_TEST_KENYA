import QtQuick 2.10
import QtQuick.Controls 2.3
import io.qt.Backend 1.0
import io.qt.OrderManage 1.0
import QtQuick.Layouts 1.0
//import QtMultimedia 5.0


Page {
    property bool mCartClicked : true

    id: page2
    width: 1080
    height: 1920

    function clearPage(){
        // 장바구니 비우기
        orderManage.clearCart()
    }


    function checkSoldout(){

    }

    function cartReload(){
        pageCart.reloadCart()
        //        if(orderManage.hasAnyOrder()){
        //            circleCart.visible = true;
        //            textCartItemNum.text = orderManage.getCartItemSize();
        //        }else{
        //            circleCart.visible = false;
        //            textCartItemNum.text = orderManage.getCartItemSize();
        //        }
    }



    // 메뉴창의 음료 그림 선택시 시그널
    signal sigItem(string menuKor, string menuEng, string description, string imageSrc, int price, int type)
    signal deleteItem(string menu_name)




    Connections{
        target: page2
        // 메뉴창의 음료 그림 선택시 발생하는 함수
        onSigItem:{
            // 장바구니가 가득 차있으면 Warning 메시지
            // 장바구니가 비어있으면 옵션 선택 팝업

            console.log(menuKor)
            orderManage.addOrderToCart(menu.getMenuID(menuKor), menuKor)
//            swipeView.currentIndex = 3  // cart page
            clickSound.play()


            //                optionPage.setDrink(menuKor, menuEng, description, imageSrc, price, type);
            //                swipeView.currentIndex = 2;

        }
        onDeleteItem:{

        }
    }



    // Background -------------------------------------
    Image{
        id: rectBackground
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        source: "file:C:/Users/POS/Desktop/BobaMenuImage/background_order.png"
//        source: "image/background_order.png"
        fillMode: Image.Stretch


        Rectangle {
            id: btn_coffee
            x: 69
            y: 215
            width: 145
            height: 77
            color: "#E7E6E6"
            Text {
                color: "#141414"
                text: "COFFEE"
                anchors.fill: parent
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
            }

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onReleased:{
                    menuSwipeView.currentIndex=0
                }
            }
        }



        Rectangle {
            id: btn_tea
            x: 230
            y: 215
            width: 144
            height: 77
            color: "#E7E6E6"
            Text {
                color: "#141414"
                text: "TEA"
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea {
                id: mouseArea1
                anchors.fill: parent
                onReleased:{
                    menuSwipeView.currentIndex=1
                }
            }
        }

        CartPage{
            id: pageCart
            y: 1621
            height: 299
            anchors.right: parent.right
            anchors.rightMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 0
//            anchors.fill: parent
        }

//        ScrollView {
//            id: cartView
//            y: 1621
//            height: 299
//            anchors.right: parent.right
//            anchors.rightMargin: 8
//            anchors.left: parent.left
//            anchors.leftMargin: 0
//            clip: true

//            ScrollBar.horizontal: ScrollBar{
//                width: 1033
//                height: 20

//                policy:ScrollBar.AlwaysOn
//            }

//            CartPage{
//                id: pageCart
//                anchors.fill: parent
//            }

//            //            Rectangle{
//            //                anchors.fill: parent
//            //                color: "#222222"
//            //            }
//        }

        Item{
            x: 86
            y: 324
            width: 900
            height: 888

            SwipeView {
                id: menuSwipeView
                anchors.fill:parent
                clip: true
                interactive: true
                currentIndex: 0

                MenuPage_Coffee {
                    id: pageCoffee
                    //1200
                }

                MenuPage_Tea {
                    id: pageTea
                }
            }
        }



        MouseArea {
            x: 34
            y: 24
            anchors.leftMargin: 18
            anchors.topMargin: 21
            anchors.rightMargin: 928
            anchors.bottomMargin: 1778
            anchors.fill: parent
            onClicked: {
                swipeView.currentIndex = 0
            }
        }

        MouseArea {
            x: 118
            y: 807
            anchors.rightMargin: 31
            anchors.bottomMargin: 296
            anchors.leftMargin: 752
            anchors.topMargin: 1485
            anchors.fill: parent
            onReleased: {
                if(!mCartClicked){
//                    rectCart.opacity = 1.0
                    mCartClicked = true;
                    if(orderManage.hasAnyOrder() === true){
                        swipeView.currentIndex = 0;
                        backend.newOrder() // 결제진행
                    }else{
                    }
                    clickSound.play()
                }
            }
            onPressed:{
                if(mCartClicked){
//                    rectCart.opacity = 0.7
                    mCartClicked = false;
                }
            }
        }

        Rectangle {
            id: btn_icecream
            x: 389
            y: 215
            width: 176
            height: 77
            color: "#E7E6E6"
            Text {
                color: "#141414"
                text: "ICECREAM"
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea {
                id: mouseArea2
                anchors.fill: parent
            }
        }
    }
    // ------------------------------------------------




    //---------------------------------------------------------------





    //Recommend Image (Upper)


    //Recommend Image (Lower)


    //---------------------------------------------------------------

}





/*##^## Designer {
    D{i:5;anchors_height:100;anchors_width:100;anchors_x:38;anchors_y:17}D{i:8;anchors_height:100;anchors_width:100;anchors_x:38;anchors_y:17}
D{i:14;anchors_height:100;anchors_width:100;anchors_x:38;anchors_y:17}D{i:20;anchors_height:100;anchors_width:100;anchors_x:38;anchors_y:17}
}
 ##^##*/
