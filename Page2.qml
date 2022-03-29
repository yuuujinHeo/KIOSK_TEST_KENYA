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
        pageMilkTea.checkSoldout();
        pageTea.checkSoldout();
    }

    function cartReload(){
        if(orderManage.hasAnyOrder()){
            circleCart.visible = true;
            textCartItemNum.text = orderManage.getCartItemSize();
        }else{
            circleCart.visible = false;
            textCartItemNum.text = orderManage.getCartItemSize();
        }
    }



    // 메뉴창의 음료 그림 선택시 시그널
    signal sigItem(string menuKor, string menuEng, string imageSrc, int price, int type)





    Connections{
        target: page2
        // 메뉴창의 음료 그림 선택시 발생하는 함수
        onSigItem:{
            // 장바구니가 가득 차있으면 Warning 메시지
            // 장바구니가 비어있으면 옵션 선택 팝업
            if(orderManage.getCartItemSize() >= orderManage.getCartMaxItemSize()){
                warningPopup.closeTimeout = 6
                warningPopup.setType(2)
                warningPopup.open();
            }else{
                optionPage.setDrink(menuKor, menuEng, imageSrc, price, type);
                swipeView.currentIndex = 2;
            }
        }
    }



    // Background -------------------------------------
    Rectangle{
        id: rectBackground
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        color: "#f3f3f3"


        Text {
            id: textGoToFront
            x: 34
            y: 24
            width: 178
            height: 86
            text: qsTr("뒤로가기")
            font.family: fontBold.name
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 40
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    swipeView.currentIndex = 0
                }
            }
        }

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
            x: 83
            y: 368
            width: 914
            height: 77
            color: "#201547"
            Text {
                anchors.fill: parent
                color: "#ffffff"
                text: "티 & 커피"
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 40
            }
        }
        Rectangle {
            x: 83
            y: 941
            width: 914
            height: 77
            color: "#201547"

            Text {
                id: textMenuTea
                anchors.fill: parent
                color: "#ffffff"
                text: "보바 밀크티 & 밀크커피"
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 40
            }
        }



        Rectangle{
            id: rectCart
            x: 0
            y: 1686
            width: parent.width
            height: 234
            color: "#2b214e"



            Text {
                anchors.fill: parent
                color: "#ffffff"
                text: "장바구니"
                font.pixelSize: 80
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }


            MouseArea {
                anchors.fill: parent
                onReleased: {
                    if(!mCartClicked){
                        rectCart.opacity = 1.0
                        mCartClicked = true;
                        if(orderManage.hasAnyOrder() === true){
                            swipeView.currentIndex = 3  // cart page
                        }else{
                            warningPopup.closeTimeout = 6
                            warningPopup.setType(1)
                            warningPopup.open()
                        }


                        clickSound.play()
                    }
                }
                onPressed:{
                    if(mCartClicked){
                        rectCart.opacity = 0.7
                        mCartClicked = false;
                    }
                }

                Image {
                    id: image
                    x: 281
                    y: 75
                    width: 77
                    height: 85
                    source: "image/common/check.png"
                    fillMode: Image.PreserveAspectFit
                }
            }

            Rectangle {
                id: circleCart
                x: 721
                y: 86
                width: 70
                height: 70
                color: "#ffffff"
                radius: 35

                Rectangle {
                    x: 2
                    y: 2
                    width: 66
                    height: 66
                    color: "#9672db"
                    radius: 33
                    border.color: "#9672db"

                    Text {
                        id: textCartItemNum
                        width: 66
                        height: 66
                        anchors.fill: parent
                        color: "#ffffff"
                        text: "0"
                        font.pixelSize: 40
                        font.family: fontBold.name
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                }
            }

        }
    }
    // ------------------------------------------------




    //---------------------------------------------------------------

    SwipeView {
        id: menuSwipeViewMilkTea
        x: 83
        y: 472
        width: 914
        height: 344
        clip: true
        currentIndex: 0
        interactive: true

        MenuPage_Tea{
            id: pageMilkTea
        }
    }

    SwipeView {
        id: menuSwipeViewTea
        x: 83
        y: 1045
        width: 914
        height: 344
        clip: true
        currentIndex: 0
        interactive: true

        MenuPage_MilkTea{
            id: pageTea
        }
    }





    Image {
        id: imageRecommend
        x: 535
        y: 1045
        source: "image/option_page/ok.png"
    }

    Image {
        id: imageRecommend2
        x: 877
        y: 472
        source: "image/option_page/ok.png"
    }

    Image {
        id: imageRecommend3
        x: 227
        y: 1045
        source: "image/option_page/ok.png"
    }

    Image {
        id: imageRecommend4
        x: 191
        y: 472
        source: "image/option_page/ok.png"
    }

    //---------------------------------------------------------------



    WarningPopup{
        id: warningPopup
    }








}
