import QtQuick 2.10
import QtQuick.Controls 2.3
import io.qt.Backend 1.0
import io.qt.OrderManage 1.0
import QtQuick.Layouts 1.0
//import QtMultimedia 5.0


Page {

    id: page5
    width: 1080
    height: 1920

    property bool mBackToCartClicked : true
    property bool mCancelCreditClicked : true

    property int  _time: 0

    property bool mBlockButton : false



    // 새로운 결제를 위해 --> 버튼 활성화
    function newCreditReady(){
        mBlockButton = false;
        updateButtonBlock();
    }

    // 카드 인식이 시작되면 발생 --> 버튼 비활성화
    function creditNotiApproving(){
        backend.addLog("[QML]     creditNotiApproving");
        console.log("CreditPage --------------> creditNotiApproving")
        mBlockButton = true;
        updateButtonBlock();
        //globalCreditApproving = 1
    }

    function updateButtonBlock(){
        if(mBlockButton == true){
            rectBackToCart.color = "#686767";
            rectCancelCredit.color = "#aba9ab";
        }else{
            rectBackToCart.color = "#3b3a51";
            rectCancelCredit.color = "#7647c0";
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
                text: "결제하기"
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 65
            }
        }

        Text {
            x: 191
            y: 620
            width: 699
            height: 76
            color: "#4c4e54"
            text: "카드를 투입구에 넣어주세요."
            lineHeight: 1.2
            font.family: fontBold.name
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 54
        }

        Text {
            x: 164
            y: 700
            width: 752
            height: 76
            color: "#5b5e66"
            text: "기기 하단에 있는 카드리더기에 카드를 넣어주세요.\n결제가 완료될 때까지 카드를 빼지 마세요!"
            font.family: fontLight.name
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            lineHeight: 1.2
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
        }

        Image{
            id: imageCard
            x: 343
            y: 872
            width: 389
            height: 241
            fillMode: Image.PreserveAspectFit
            source: "image/credit_page/card_insert.png"
        }

        Text {
            x: 204
            y: 1176
            width: 673
            height: 76
            color: "#5b5e66"
            text: "※ 주문현황판의 주문량이 많을 경우 대기 시간이\n길어질 수 있습니다."
            font.family: fontLight.name
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 1.2
            font.pixelSize: 30
        }



        Rectangle{
            id: rectBackToCart
            x: 0
            y: 1686
            width: parent.width/2
            height: 234
            color: "#3b3a51"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                text: "    뒤로가기"
                font.pixelSize: 60
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                anchors.fill: parent
                onReleased: {
                    if(mBlockButton == true){
                        // 카드 승인중이라 버튼이 막혀있을경우에
                        rectBackToCart.opacity = 1.0;
                        mBackToCartClicked = true;
                    }else{
                        if(!mBackToCartClicked){
                            var card_state = backend.getCardState();
                            backend.addLog("[QML]       CreditBack : "+card_state);
                            if(card_state === "POS_TRANS"){
                                ;
                            }else{
                                backend.cancelCredit();
                                swipeView.currentIndex = 3;  // cart page
                                clickSound.play()
                            }
                            rectBackToCart.opacity = 1.0
                            mBackToCartClicked = true;
                        }
                    }
                }
                onPressed:{
                    if(mBlockButton == true){
                        // 카드 승인중이라 버튼이 막혀있을경우에
                        rectBackToCart.opacity = 1.0;
                        mBackToCartClicked = true;
                    }else{
                        if(mBackToCartClicked){
                            rectBackToCart.opacity = 0.7
                            mBackToCartClicked = false;
                        }
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
            id: rectCancelCredit
            x: parent.width/2
            y: 1686
            width: parent.width/2
            height: 234
            color: "#7647c0"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                text: "    결제취소"
                font.pixelSize: 60
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                anchors.fill: parent
                onReleased: {
                    if(mBlockButton == true){
                        // 카드 승인중이라 버튼이 막혀있을경우에
                        rectCancelCredit.opacity = 1.0;
                        mCancelCreditClicked = true;
                    }else{
                        if(!mCancelCreditClicked){
                            var card_state = backend.getCardState()
                            backend.addLog("[QML]       CreditCancel : " + card_state);
                            if(card_state === "POS_TRANS"){
                                ;
                            }else{
                                backend.cancelCredit();
                                swipeView.currentIndex = -1 // dummy
                                swipeView.currentIndex = 0  // main page
                                clickSound.play()
                            }
                            rectCancelCredit.opacity = 1.0
                            mCancelCreditClicked = true;
                        }
                    }
                }
                onPressed:{
                    if(mBlockButton == true){
                        // 카드 승인중이라 버튼이 막혀있을경우에
                        rectCancelCredit.opacity = 1.0;
                        mCancelCreditClicked = true;
                    }else{
                        if(mCancelCreditClicked){
                            rectCancelCredit.opacity = 0.7
                            mCancelCreditClicked = false;
                        }
                    }
                }
            }

            Image {
                id: image1
                x: 104
                y: 91
                width: 54
                height: 53
                source: "image/common/pause.png"
                fillMode: Image.PreserveAspectFit
            }
        }

        Text {
            id: element
            x: 304
            y: 1276
            text: qsTr("카드리더기의 불이 빠르게 깜빡이면 \nIC인식이 아닌 카드를 긁어주세요")
            font.family: fontLight.name
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            lineHeight: 1.2
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
        }

        Text {
            id: element1
            x: 508
            y: 1385
            color: "#202020"
            text: _time
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            lineHeight: 1.2
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 40
        }


    }
    // ------------------------------------------------




}
