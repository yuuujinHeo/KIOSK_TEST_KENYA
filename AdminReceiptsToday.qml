import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls 1.4 as Old
import io.qt.Backend 1.0

Page {
    id: adminReceiptsTodayInfo

    property bool mQuitClicked: true
    property date cd: new Date();
    property string currentdate : cd.toLocaleDateString();

    width: 1080
    height: 1800
    x: 0
    y: 0
    background: Rectangle{color:"#201547"}
    clip:true

    function reload(curdate){
        cd = curdate
        currentdate = cd.toLocaleDateString();
        console.log("yuu")
        console.log(cd)
        updateContent(cd)
    }

    function updateContent(date){
        text_date.text = date.toLocaleDateString();
        listViewContent.model.clear()
        backend.reloadContent(date)
        for(var i = 0; i < backend.getContentSize(); i++){
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

    Image {
        id: image
        x: 412
        y: 153
        width: 256
        height: 284
        source: "image/order_page/logo_boba.png"
        fillMode: Image.PreserveAspectFit
    }

    Component {//리스트 뷰의 틀을 만든다.
        id: contactDelegateContent
        Rectangle {
            id: wrapper
            width: 940
            height: 40
            color: ListView.isCurrentItem ? "lightsteelblue" : "white"
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_Pin
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                text:pin_text
                font.pixelSize: 12
                font.bold: true
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
        y: 540
        width: 1000
        height: 1124
        anchors.horizontalCenter: parent.horizontalCenter
        model: ListModel{}//임으로 만들 모델을 넣어준다.
        delegate: contactDelegateContent
        focus: true
        boundsBehavior: Flickable.StopAtBounds
        clip: true
        orientation: ListView.Vertical
    }

    Rectangle {
        id: btncancel
        x: 876
        y: 277
        width: 120
        height: 160
        color: "#ffffff"
        radius: 5
        border.width: 0
        border.color: "#6e57d1"

        Text {
            anchors.fill: parent
            color: "#201547"
            font.family: fontBold.name
            font.pixelSize: 20
            text: "결제취소"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                backend.setOrderOnSalesLog(cd, listViewContent.currentIndex)
                backend.doCancel(cd, listViewContent.currentIndex)

                backend.addLogin("대보유통","CANCEL")
            }
        }
    }

    Rectangle {
        id: rectangle
        x: 46
        y: 153
        width: 345
        height: 214
        color: "#201547"
        radius: 20
        border.color: "#ffffff"
        border.width: 8
    }

    Rectangle {
        id: btnprint
        x: 709
        y: 277
        width: 120
        height: 160
        color: "#ffffff"
        radius: 5
        border.width: 0
        border.color: "#6e57d1"

        Text {
            anchors.fill: parent
            color: "#201547"
            font.family: fontBold.name
            font.pixelSize: 20
            text: "재발행"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                backend.setOrderOnSalesLog(cd.getDate(), listViewContent.currentIndex)
                backend.doPrintagain(listViewContent.currentIndex)

                backend.addLogin("대보유통","PRINT AGAIN");
            }
        }
    }

    Text {
        id: element
        x: 78
        y: 207
        width: 108
        height: 0
        color: "#ffffff"
        text: qsTr("영업 일자 : ")
        font.bold: false
        font.pixelSize: 20
    }

    Text {
        id: element1
        x: 105
        y: 297
        color: "#ffffff"
        text: qsTr("로그인 : ")
        font.bold: true
        font.pixelSize: 20
    }

    Text {
        id: text_date
        x: 158
        y: 251
        color: "#ffffff"
        text: currentdate
        font.bold: true
        font.pixelSize: 18
    }

    Text {
        id: text_login
        x: 205
        y: 297
        color: "#ffffff"
        text: qsTr("대보유통")
        font.bold: true
        font.pixelSize: 20
    }


}
