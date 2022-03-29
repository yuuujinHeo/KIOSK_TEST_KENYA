import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls 1.4 as Old
import io.qt.Backend 1.0

Item {
    id: adminSaleInfo2

    property bool mQuitClicked: true
    property date cd: new Date();
    property string currentdate : cd.toLocaleDateString();

    width: 1080
    height: 1800
    x: 0
    y: 0

    function dbReload(){
//        updateContent(listViewSaleDate.currentIndex)
    }

    function reload(){
//        swipeViewAdmin.currentIndex = 0

        backend.reloadSaleData()
        var year = backend.getYear();
        var month = backend.getMonth();
        var day = backend.getDay();

//        var year_month = comboBoxTargetYear.currentText + "-" + comboBoxTargetMonth.currentText
//        backend.updateSaleMonth(year_month)

        for(var i = 0; i < backend.getSaleDateSize(); i++){//리스트의 개수만큼 for문을 돌린다.
            listViewSaleDate.model.append({"list_text": backend.getSaleDateAt(i)})
//            console.log(backend.getSaleDateAt(i))
        }
    }

    function updateContent(){
        listViewContent.model.clear()
        backend.reloadContentLast()
        for(var i = 0; i < backend.getContentSize(); i++){
            console.log(i)
            listViewContent.model.append({"pin_text": backend.getContentPin(i),
                                             "time_text": backend.getContentTime(i),
                                             "menu_text": backend.getContentMenu(i),
                                             "price_text": backend.getContentPrice(i),
                                             "card_comp_text": backend.getContentCardComp(i),
                                             "card_num_text": backend.getContentCardNum(i),
                                             "app_num_text": backend.getContentAppNum(i),
                                             "tran_date_text": backend.getContentTrandate(i),
                                             "is_cancel_text": backend.getContentIsCancel(i)})
        }
    }



    Rectangle{
        id: rectQuit
        x: 140
        y: 15
        width:800
        height:71
        color: "#39374d"

        Text {
            anchors.fill: parent
            color: "#ffffff"
            text: "키오스크 종료"
            font.pixelSize: 40
            font.family: fontBold.name
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        MouseArea {
            anchors.fill: parent
            onReleased: {
                if(!mQuitClicked){
                    rectQuit.opacity = 1.0
                    mQuitClicked = true;
                    backend.addLogin("대보유통","QUIT");
                    Qt.quit()
                }
            }
            onPressed:{
                if(mQuitClicked){
                    rectQuit.opacity = 0.7
                    mQuitClicked = false;
                }
            }
        }
    }


    Component {//리스트 뷰의 틀을 만든다.
        id: contactDelegateContent
        Item {
            width: 940
            height: 40
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_Pin
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                text:pin_text
                font.pixelSize: 12
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_Time
                anchors.left: parent.left
                anchors.leftMargin: 50
                anchors.verticalCenter: parent.verticalCenter
                text:time_text
                font.pixelSize: 12
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_Menu
                anchors.left: parent.left
                anchors.leftMargin: 130
                anchors.verticalCenter: parent.verticalCenter
                text:menu_text
                font.pixelSize: 12
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_Price
                anchors.left: parent.left
                anchors.leftMargin: 270
                anchors.verticalCenter: parent.verticalCenter
                text:price_text
                font.pixelSize: 12
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_CardComp
                anchors.left: parent.left
                anchors.leftMargin: 340
                anchors.verticalCenter: parent.verticalCenter
                text:card_comp_text
                font.pixelSize: 12
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_CardNum
                anchors.left: parent.left
                anchors.leftMargin: 470
                anchors.verticalCenter: parent.verticalCenter
                text:card_num_text
                font.pixelSize: 12
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_AppNum
                anchors.left: parent.left
                anchors.leftMargin: 600
                anchors.verticalCenter: parent.verticalCenter
                text:app_num_text
                font.pixelSize: 12
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_TranDate
                anchors.left: parent.left
                anchors.leftMargin: 700
                anchors.verticalCenter: parent.verticalCenter
                text:tran_date_text
                font.pixelSize: 12
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_IsCancel
                anchors.left: parent.left
                anchors.leftMargin: 800
                anchors.verticalCenter: parent.verticalCenter
                text:is_cancel_text
                font.pixelSize: 12
            }
//            Button//리스트에 버튼을 넣어주기 위해 버튼 객체를 만들어준다.
//            {
//                id:listView_Cancel
//                anchors.right: parent.right
//                anchors.rightMargin: 30
//                anchors.verticalCenter: parent.verticalCenter
//                text: "결제취소"
//                onClicked:{
//                    console.log("cancel"+index)
//                    backend.doCancel(index)
//                }
//            }
            Rectangle//리스트의 구분선
            {
                id:line
                width:parent.width
                anchors.bottom:parent.bottom//현재 객체의 아래 기준점을 부모객체의 아래로 잡아주어서 위치가 아래로가게 설정
                height:1
                color:"black"
            }

            MouseArea{
                anchors.fill: parent
                onClicked:{
                    listViewContent.currentIndex = index
                }
            }
        }
    }

    ListView {
        id:listViewContent
        x: 40
        y: 352
        //        anchors.rightMargin: 172
//        anchors.bottomMargin: 320
//        anchors.leftMargin: -172
//        anchors.topMargin: -320
//        anchors.fill: parent
        width: 1000
        height: 1312
        anchors.horizontalCenter: parent.horizontalCenter
        model: ListModel{}//임으로 만들 모델을 넣어준다.
        delegate: contactDelegateContent
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        highlightMoveDuration: 1
        focus: true
        boundsBehavior: Flickable.StopAtBounds
        clip: true
        orientation: ListView.Vertical
    }


    //-----------------------------------------------------------
    Button {
        id: buttonListUpdate
        x: 559
        y: 156
        width: 140
        height: 48
        text: "업데이트"
        font.pixelSize: 20
        onClicked: {
//            reload()
            updateContent()
        }
    }
    //-----------------------------------------------------------


    Button {
        id: buttonCreditCancel
        x: 918
        y: 156
        width: 140
        height: 48
        text: "결제취소"
        font.pixelSize: 20
        onClicked: {
            backend.setOrderOnSalesLog(-1, listViewContent.currentIndex)
            backend.doCancel(-1, listViewContent.currentIndex)
            backend.addLogin("대보유통","CANCEL");
        }
    }

    Rectangle {
        id: rectangle
        x: 504
        y: 150
        width: 5
        height: 159
        color: "#b58f8f"
    }

    Button {
        id: buttonCreditPrint
        x: 735
        y: 156
        width: 140
        height: 48
        text: "재발행"
        font.pixelSize: 20
        onClicked: {
//            updateContent(index)
//            backend.reloadContent(idx)
            backend.setOrderOnSalesLog(-1, listViewContent.currentIndex)
            backend.doPrintagain(-1, listViewContent.currentIndex)
            backend.addLogin("대보유통","PRINT AGAIN");
        }
    }

    Text {
        id: element
        x: 64
        y: 190
        width: 108
        height: 0
        text: qsTr("영업 일자 : ")
        font.pixelSize: 20
    }

    Text {
        id: element1
        x: 91
        y: 258
        text: qsTr("로그인 : ")
        font.pixelSize: 20
    }

    Text {
        id: text_date
        x: 188
        y: 190
        text: currentdate
        font.pixelSize: 20
    }

    Text {
        id: text_login
        x: 188
        y: 258
        text: qsTr("대보유통")
        font.pixelSize: 20
    }

}
