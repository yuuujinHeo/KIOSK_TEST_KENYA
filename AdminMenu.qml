import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls 1.4 as Old
import io.qt.Backend 1.0

Page {
    id: adminMenuInfo
    property bool mQuitClicked: true
    property bool isadmin: false
    property date cd: new Date()
    width: 1080
    height: 1800
    x: 0
    y: 0
    background: Rectangle{color:"#201547"}
    clip:true

    function reload(mode,curdate){
        isadmin = mode

        cd = curdate
        if(isadmin == true){
            element5.text = "관리자"
        }else{
            element5.text = "대보유통"
            rectangleCheckin.visible = false;
            rectangleSales.visible = false;
            rectangleTestMode.visible = false;
            rectangleSaleMode.visible = false;
            rectangleQuit.visible = false;
        }
        adminInfoDayReport.reload(isadmin,cd)

    }

    Image {
        id: image
        x: 412
        y: 153
        width: 256
        height: 284
        source: "image/order_page/logo_boba.png";
        fillMode: Image.PreserveAspectFit
    }


    Rectangle {
        id: rectangleDayReport
        x: 372
        width: 320
        height: 148
        color: "#201547"
        radius: 30
        anchors.horizontalCenterOffset: -218
        anchors.top: parent.top
        anchors.topMargin: 674
        anchors.horizontalCenter: parent.horizontalCenter
        clip: false
        border.color: "#ffffff"
        border.width: 10

        MouseArea {
            id: mouseArea_dayreport
            anchors.fill: parent

            Text {
                id: element1
                color: "#ffffff"
                text: qsTr("영업 일보")
                fontSizeMode: Text.FixedSize
                styleColor: "#000000"
                style: Text.Outline
                font.weight: Font.DemiBold
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.family: "Arial"
                font.bold: true
                font.pixelSize: 50
            }
            onClicked: {
                swipeViewAdminMain.currentIndex = 3;
                adminInfoDayReport.reload(isadmin)

            }
        }
    }

    Text {
        id: element
        x: 335
        y: 517
        color: "#ffffff"
        text: qsTr("login : ")
        font.pixelSize: 60
    }

    Rectangle {
        id: rectangleReceipts
        width: 320
        height: 148
        color: "#201547"
        radius: 30
        anchors.horizontalCenterOffset: -218
        anchors.left: rectangleDayReport.right
        anchors.leftMargin: -320
        anchors.top: rectangleDayReport.bottom
        anchors.topMargin: 102
        anchors.horizontalCenter: parent.horizontalCenter
        border.color: "#ffffff"
        clip: false
        MouseArea {
            id: mouseArea_receipts
            anchors.fill: parent
            Text {
                id: element2
                color: "#ffffff"
                text: qsTr("영수증 관리")
                font.family: "Arial"
                style: Text.Outline
                fontSizeMode: Text.FixedSize
                font.weight: Font.DemiBold
                font.pixelSize: 50
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                styleColor: "#000000"
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }
            onClicked: {
                if(isadmin){
                    swipeViewAdminMain.currentIndex = 4;
                    adminInfoReceipts.reload()
                }else{
                    swipeViewAdminMain.currentIndex = 5;
                    userInfoReceipts.reload()
                }
            }
        }
        border.width: 10
    }

    Rectangle {
        id: rectangleSales
        x: 372
        width: 320
        height: 148
        color: "#201547"
        radius: 30
        anchors.horizontalCenterOffset: -218
        anchors.top: rectangleReceipts.bottom
        anchors.topMargin: 105
        anchors.horizontalCenter: parent.horizontalCenter
        border.color: "#ffffff"
        clip: false
        MouseArea {
            id: mouseArea_sales
            anchors.fill: parent
            Text {
                id: element3
                color: "#ffffff"
                text: qsTr("매출 관리")
                font.family: "Arial"
                style: Text.Outline
                fontSizeMode: Text.FixedSize
                font.weight: Font.DemiBold
                font.pixelSize: 50
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                styleColor: "#000000"
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }
            onClicked: {
                swipeViewAdminMain.currentIndex = 6;
                adminInfoSales.reload()

            }
        }
        border.width: 10
    }

    Rectangle {
        id: rectangleCheckin
        x: 372
        width: 320
        height: 148
        color: "#201547"
        radius: 30
        anchors.horizontalCenterOffset: -218
        anchors.top: rectangleSales.bottom
        anchors.topMargin: 105
        anchors.horizontalCenter: parent.horizontalCenter
        border.color: "#ffffff"
        clip: false
        MouseArea {
            id: mouseArea_checkin
            anchors.fill: parent
            Text {
                id: element4
                color: "#ffffff"
                text: qsTr("이력 조회")
                font.family: "Arial"
                style: Text.Outline
                fontSizeMode: Text.FixedSize
                font.weight: Font.DemiBold
                font.pixelSize: 50
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                styleColor: "#000000"
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }
            onClicked: {
                swipeViewAdminMain.currentIndex = 7;
                adminInfoCheckin.reload()

            }
        }
        border.width: 10
    }

    Text {
        id: element5
        y: 481
        color: "#ffffff"

        text: qsTr("system")
        anchors.verticalCenter: element.verticalCenter
        anchors.left: element.right
        anchors.leftMargin: 30
        font.pixelSize: 50
    }

    Rectangle {
        id: rectangleTestMode
        x: 373
        y: 4
        width: 320
        height: 148
        color: "#201547"
        radius: 30
        border.color: "#ffffff"
        clip: false
        MouseArea {
            id: mouseArea_dayreport1
            anchors.fill: parent
            onClicked: {
                backend.setIsTest(1)
                backend.addLogin("관리자","SET TESTMODE")
            }
            Text {
                id: element6
                color: "#ffffff"
                text: qsTr("테스트 모드")
                fontSizeMode: Text.FixedSize
                style: Text.Outline
                font.family: "Arial"
                font.weight: Font.DemiBold
                font.bold: true
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
                styleColor: "#000000"
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }
        }
        anchors.top: parent.top
        anchors.topMargin: 674
        anchors.horizontalCenterOffset: 224
        anchors.horizontalCenter: parent.horizontalCenter
        border.width: 10
    }

    Rectangle {
        id: rectangleSaleMode
        x: 371
        y: -4
        width: 320
        height: 148
        color: "#201547"
        radius: 30
        border.color: "#ffffff"
        clip: false
        MouseArea {
            id: mouseArea_dayreport2
            anchors.fill: parent
            onClicked: {
                backend.setIsTest(0)
                backend.addLogin("관리자","SET RUNMODE")
            }
            Text {
                id: element7
                color: "#ffffff"
                text: qsTr("장사 모드")
                fontSizeMode: Text.FixedSize
                style: Text.Outline
                font.family: "Arial"
                font.weight: Font.DemiBold
                font.bold: true
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
                styleColor: "#000000"
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }
        }
        anchors.top: parent.top
        anchors.topMargin: 924
        anchors.horizontalCenterOffset: 224
        anchors.horizontalCenter: parent.horizontalCenter
        border.width: 10
    }

    Rectangle {
        id: rectangleQuit
        x: 364
        y: 1
        width: 320
        height: 148
        color: "#201547"
        radius: 30
        border.color: "#ffffff"
        clip: false
        MouseArea {
            id: mouseArea_dayreport3
            anchors.fill: parent
            onReleased: {
                if(!mQuitClicked){
                    rectangleQuit.opacity = 1.0
                    mQuitClicked = true;
                    backend.addLogin("관리자","QUIT")
                    Qt.quit()
                }
            }
            onPressed:{
                if(mQuitClicked){
                    rectangleQuit.opacity = 0.7
                    mQuitClicked = false;
                }
            }
            Text {
                id: element8
                color: "#ffffff"
                text: qsTr("키오스크 종료")
                fontSizeMode: Text.FixedSize
                style: Text.Outline
                font.family: "Arial"
                font.weight: Font.DemiBold
                font.bold: true
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
                styleColor: "#000000"
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }
        }
        anchors.top: parent.top
        anchors.topMargin: 1177
        anchors.horizontalCenterOffset: 224
        anchors.horizontalCenter: parent.horizontalCenter
        border.width: 10
    }

    Rectangle {
        id: rectangleReceipts1
        x: -4
        y: 1430
        width: 320
        height: 148
        color: "#201547"
        radius: 30
        anchors.horizontalCenter: parent.horizontalCenter
        clip: false
        MouseArea {
            id: mouseArea_receipts1
            anchors.fill: parent
            onClicked: {
                lower()
            }

            Text {
                id: element9
                color: "#ffffff"
                text: qsTr("최소화")
                anchors.fill: parent
                font.pixelSize: 50
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                style: Text.Outline
                font.weight: Font.DemiBold
                verticalAlignment: Text.AlignVCenter
                fontSizeMode: Text.FixedSize
                font.family: "Arial"
                styleColor: "#000000"
            }
        }
        border.width: 10
        border.color: "#ffffff"
        anchors.horizontalCenterOffset: 224
    }




}
