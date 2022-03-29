import QtQuick 2.10
import QtQuick.Controls 2.3
import io.qt.Backend 1.0
import io.qt.OrderManage 1.0
import QtQuick.Layouts 1.0
//import QtMultimedia 5.0


Page {

    id: page4
    width: 1080
    height: 1920

    property bool mBackToMenuClicked : true
    property bool mCreditClicked : true

    property bool mMenuRemoveClicked : true
    property bool mMenuAddClicked : true

    property int __total_money : 2000

    property bool mBlockButton : false


    // Background -------------------------------------
    Rectangle{
        id: rectBackground
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        color: "#f3f3f3"

        Image {
            id: imageLogo
            x: 446
            y: 92
            width: 188
            height: 221
            source: "image/order_page/logo_boba.png"
            fillMode: Image.PreserveAspectFit
        }



        Rectangle {
            x: 104
            y: 358
            width: 874
            height: 129
            color: "#201547"
            Text {
                anchors.fill: parent
                color: "#ffffff"
                text: "장바구니"
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 65
            }
        }

        Image{
            id: imageCart
            x: 420
            y: 528
            width: 240
            height: 242
            fillMode: Image.PreserveAspectFit
            source: "image/cart_page/cart.png"
        }

        Text {
            x: 240
            y: 809
            width: 600
            height: 76
            color: "#4c4e54"
            text: "주문 음료를 확인해주세요."
            lineHeight: 1.2
            font.family: fontBold.name
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 50
        }
        Text {
            x: 298
            y: 880
            width: 210
            height: 76
            color: "#4c4e54"
            text: "최대 2잔"
            font.family: fontBold.name
            verticalAlignment: Text.AlignVCenter
            lineHeight: 1.2
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 36
        }

        Text {
            x: 459
            y: 883
            width: 299
            height: 76
            color: "#4c4e54";
            text: "까지 주문 가능합니다.";
            font.family: fontLight.name
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 1.2
            font.pixelSize: 30
        }

        Rectangle {
            x: 115
            y: 967
            width: 854
            height: 412
            color: "transparent"//"#ffffff"

            ListView {
                id: listViewCart
                anchors.fill: parent
                boundsBehavior: Flickable.StopAtBounds
                orientation: ListView.Vertical
                flickableDirection: Flickable.VerticalFlick
                model: ListModel {}
                delegate: contactDelegateCart
            }
        }

        Rectangle {
            id: rectTotalMoney
            x: 115
            y: 1382
            width: 854
            height: 118
            color: "#dcdce5"


            Text {
                x: 0
                y: 21
                width: 370
                height: 76
                color: "#5b5e66"
                text: "총 주문 금액"
                lineHeight: 1.2
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 50
            }

            Text {
                id: textTotalMoney
                x: 537
                y: 21
                width: 317
                height: 76
                color: "#5b5e66"
                text: "\\ " + formatToCurrency(__total_money)
                font.family: fontBold.name
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                lineHeight: 1.2
                font.pixelSize: 50
            }
        }


        Image{
            id: imageMenuAdd
            x: 298
            y: 1512
            width: 484
            height: 115
            fillMode: Image.PreserveAspectFit
            source: "image/cart_page/menu_add.png"

            Text {
                x: 113
                y: 20
                width: 317
                height: 76
                color: "#ffffff"
                text: "메뉴 추가"
                font.family: fontBold.name
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                lineHeight: 1.2
                font.pixelSize: 50
            }

            MouseArea {
                anchors.fill: parent
                onReleased: {
                    if(!mMenuAddClicked){
                        imageMenuAdd.opacity = 1.0
                        mMenuAddClicked = true;
                        swipeView.currentIndex = 1;  // menu page
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(mMenuAddClicked){
                        imageMenuAdd.opacity = 0.7
                        mMenuAddClicked = false;
                    }
                }
            }
        }


        Rectangle{
            id: rectBackToMenu
            x: 0
            y: 1686
            width: parent.width/2
            height: 234
            color: "#3b3a51"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                text: "    메뉴화면"
                font.pixelSize: 60
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                anchors.fill: parent
                onReleased: {
                    if(!mBackToMenuClicked){
                        rectBackToMenu.opacity = 1.0
                        mBackToMenuClicked = true;
                        swipeView.currentIndex = 1;  // menu page
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(mBackToMenuClicked){
                        rectBackToMenu.opacity = 0.7
                        mBackToMenuClicked = false;
                    }
                }
            }

            Image {
                id: image
                x: 98
                y: 83
                width: 62
                height: 69
                source: "image/common/back.png"
                fillMode: Image.PreserveAspectFit
            }
        }


        Rectangle{
            id: rectCredit
            x: parent.width/2
            y: 1686
            width: parent.width/2
            height: 234
            color: "#7647c0"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                text: "    결제하기"
                font.pixelSize: 60
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                anchors.fill: parent
                onReleased: {
                    if(mBlockButton == true){
                        rectCredit.opacity = 1.0
                        mCreditClicked = true;
                    }else{
                        if(!mCreditClicked){
                            rectCredit.opacity = 1.0
                            mCreditClicked = true;

                            backend.addLog("[QML]     Credit");
                            creditPage.newCreditReady();    // 버튼 활성화
                            swipeView.currentIndex = 4      // credit page
                            backend.doCredit(__total_money) // 결제진행
                            clickSound.play()
                        }
                    }
                }
                onPressed:{
                    if(mBlockButton == true){
                        rectCredit.opacity = 1.0
                        mCreditClicked = true;
                    }else{
                        if(mCreditClicked){
                            rectCredit.opacity = 0.7
                            mCreditClicked = false;
                        }
                    }
                }
            }

            Image {
                id: image1
                x: 84
                y: 81
                width: 71
                height: 73
                source: "image/common/check.png"
                fillMode: Image.PreserveAspectFit
            }
        }


    }
    // ------------------------------------------------



    function cartReload(){
        listViewCart.model.clear()

        for(var i = 0; i < orderManage.getCartItemSize(); i++){//리스트의 개수만큼 for문을 돌린다.
            listViewCart.model.append({"menu_text": orderManage.getCartItemMenu(i),
                                          "option_string": orderManage.getCartItemOptionString(i)})
        }
        __total_money = orderManage.getTotalPrice()
        globalOrderPrice = __total_money;

        rectTotalMoney.y = 970 + orderManage.getCartItemSize() * 206;
        imageMenuAdd.y = 1100 + orderManage.getCartItemSize() * 206;

        if(orderManage.getCartItemSize() > 1){
            imageMenuAdd.visible = false;
        }else{
            imageMenuAdd.visible = true;
        }

        if(orderManage.getCartItemSize() === 0){
            mBlockButton = true;
            rectCredit.color = "#aba9ab";
        }else{
            mBlockButton = false;
            rectCredit.color = "#7647c0";
        }
    }


    Component {//리스트 뷰의 틀을 만든다.
        id: contactDelegateCart
        Item {
            x: 0
            y: 0
            width: 854
            height: 206

            Rectangle{
                x: 0
                y: 3
                width: 854
                height: 200
                color: "#ffffff"

                Text {
                    x: 60
                    y: 60
                    width: 600
                    height: 50
                    color: "#5b5e66"
                    text: menu_text
                    font.pixelSize: 44
                    font.family: fontBold.name
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                }
                Text {
                    x: 60
                    y: 120
                    width: 600
                    height: 40
                    color: "#5b5e66"
                    text: option_string
                    font.pixelSize: 34
                    font.family: fontLight.name
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                }
                Image{
                    id: imageMenuRemove
                    x: 720
                    y: 70
                    width: 70
                    height: 70
                    source: "image/cart_page/menu_remove.png"

                    MouseArea {
                        anchors.fill: parent
                        onReleased: {
                            if(!mMenuRemoveClicked){
                                imageMenuRemove.opacity = 1.0
                                mMenuRemoveClicked = true;
                                orderManage.removeOrderFromCart(index)
                                clickSound.play()
                            }
                        }
                        onPressed:{
                            if(mMenuRemoveClicked){
                                imageMenuRemove.opacity = 0.7
                                mMenuRemoveClicked = false;
                            }
                        }
                    }
                }
            }
        }
    }


}
