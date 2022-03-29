import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls 1.4 as Old
import io.qt.Backend 1.0

Page {
    id: adminDayReportInfo
    property bool mQuitClicked: true
    property date cd: new Date();
    property string currentdate : cd.toLocaleDateString();
    property bool isadmin: false
    property string user: ""

    width: 1080
    height: 1800
    x: 0
    y: 0
    background: Rectangle{color:"#201547"}
    clip:true


    function reload(user, curdate){

        isadmin=user
        if(isadmin==true) user="관리자"
        else user="대보유통"

        cd = curdate
        updateContent(curdate)
    }

    function updateContent(date){
        backend.reloadContent(date)
        backend.setReport(date)


        element8.text = date.toLocaleDateString();
        tot_amt.text = backend.getReportTotalAmt()+backend.getReportRefundAmt();
        tot_num.text = backend.getReportTotalNum()+backend.getReportRefundNum();

        refund_amt.text = backend.getReportRefundAmt();
        refund_num.text = backend.getReportRefundNum();

        sale_amt.text = backend.getReportTotalAmt();
        sale_num.text = backend.getReportTotalNum();

        per_amt.text = backend.getReportPerAmount();//backend.getReportTotalAmt()/backend.getReportTotalNum();
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

    Column {
        id: column
        x: 468
        y: 700
        width: 200
        height: 400
        spacing: 15

        Rectangle {
            id: rectangle
            width: 290
            height: 53
            color: "#ffffff"
            radius: 20

            Text {
                id: tot_amt
                text: qsTr("0")
                rightPadding: 60
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
                anchors.fill: parent
                font.pixelSize: 30
            }

            Rectangle {
                id: rectangle1
                x: -136
                y: 0
                width: 163
                height: 53
                color: "#8b6fec"
                radius: 20

                Rectangle {
                    id: rectangle2
                    x: 69
                    y: 0
                    width: 113
                    height: 53
                    color: "#8b6fec"
                }

                Text {
                    id: element
                    color: "#ffffff"
                    text: qsTr("총 판매액")
                    anchors.rightMargin: -19
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    font.pixelSize: 30
                }
            }
        }

        Rectangle {
            id: rectangle3
            width: 290
            height: 53
            color: "#ffffff"
            radius: 20
            anchors.top: rectangle.bottom
            anchors.topMargin: 20
            Text {
                id: refund_amt
                text: qsTr("0")
                rightPadding: 60
                font.pixelSize: 30
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }

            Rectangle {
                id: rectangle5
                x: -136
                y: 0
                width: 181
                height: 53
                color: "#8b6fec"
                radius: 20
                Rectangle {
                    id: rectangle4
                    x: 69
                    y: 0
                    width: 113
                    height: 53
                    color: "#8b6fec"
                }

                Text {
                    id: element1
                    color: "#ffffff"
                    text: qsTr("반품 금액")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.fill: parent
                    font.bold: true
                    font.pixelSize: 30
                }
            }
        }

        Rectangle {
            id: rectangle6
            width: 290
            height: 53
            color: "#ffffff"
            radius: 20
            anchors.top: rectangle3.bottom
            anchors.topMargin: 20
            Text {
                id: sale_amt
                text: qsTr("0")
                rightPadding: 60
                font.pixelSize: 30
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }

            Rectangle {
                id: rectangle8
                x: -136
                y: 0
                width: 182
                height: 53
                color: "#8b6fec"
                radius: 20
                Rectangle {
                    id: rectangle7
                    x: 69
                    y: 0
                    width: 113
                    height: 53
                    color: "#8b6fec"
                }

                Text {
                    id: element2
                    color: "#ffffff"
                    text: qsTr("실 매출액")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.fill: parent
                    font.bold: true
                    font.pixelSize: 30
                }
            }
        }

        Rectangle {
            id: rectangle9
            width: 290
            height: 53
            color: "#ffffff"
            radius: 20
            anchors.top: rectangle6.bottom
            anchors.topMargin: 70
            Text {
                id: tot_num
                text: qsTr("0")
                rightPadding: 60
                font.pixelSize: 30
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }

            Rectangle {
                id: rectangle11
                x: -136
                y: 0
                width: 181
                height: 53
                color: "#8b6fec"
                radius: 20
                Rectangle {
                    id: rectangle10
                    x: 69
                    y: 0
                    width: 113
                    height: 53
                    color: "#8b6fec"
                }

                Text {
                    id: element3
                    color: "#ffffff"
                    text: qsTr("판매 건수")
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    font.pixelSize: 30
                }
            }
        }

        Rectangle {
            id: rectangle12
            width: 290
            height: 53
            color: "#ffffff"
            radius: 20
            anchors.top: rectangle9.bottom
            anchors.topMargin: 20
            Text {
                id: refund_num
                text: qsTr("0")
                rightPadding: 60
                font.pixelSize: 30
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }

            Rectangle {
                id: rectangle14
                x: -136
                y: 0
                width: 181
                height: 53
                color: "#8b6fec"
                radius: 20
                Rectangle {
                    id: rectangle13
                    x: 69
                    y: 0
                    width: 113
                    height: 53
                    color: "#8b6fec"
                }

                Text {
                    id: element4
                    color: "#ffffff"
                    text: qsTr("반품 건수")
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    font.pixelSize: 30
                }
            }
        }

        Rectangle {
            id: rectangle15
            width: 290
            height: 53
            color: "#ffffff"
            radius: 20
            anchors.top: rectangle12.bottom
            anchors.topMargin: 20
            Text {
                id: sale_num
                text: qsTr("0")
                rightPadding: 60
                font.pixelSize: 30
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }

            Rectangle {
                id: rectangle17
                x: -136
                y: 0
                width: 182
                height: 53
                color: "#8b6fec"
                radius: 20
                Rectangle {
                    id: rectangle16
                    x: 69
                    y: 0
                    width: 113
                    height: 53
                    color: "#8b6fec"
                }

                Text {
                    id: element5
                    color: "#ffffff"
                    text: qsTr("매출 건수")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.fill: parent
                    font.bold: true
                    font.pixelSize: 30
                }
            }
        }

        Rectangle {
            id: rectangle18
            width: 290
            height: 53
            color: "#ffffff"
            radius: 20
            anchors.top: rectangle15.bottom
            anchors.topMargin: 50
            Text {
                id: per_amt
                text: qsTr("0")
                rightPadding: 60
                font.pixelSize: 30
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }

            Rectangle {
                id: rectangle20
                x: -136
                y: 0
                width: 181
                height: 53
                color: "#8b6fec"
                radius: 20
                Rectangle {
                    id: rectangle19
                    x: 69
                    y: 0
                    width: 113
                    height: 53
                    color: "#8b6fec"
                }

                Text {
                    id: element6
                    color: "#ffffff"
                    text: qsTr("객 단 가")
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    font.pixelSize: 30
                }
            }
        }
    }

    Rectangle {
        id: btnreport
        x: 233
        y: 1317
        width: 275
        height: 70
        color: "#ffffff"
        radius: 5
        border.width: 0
        border.color: "#6e57d1"

        Text {
            anchors.fill: parent
            color: "#201547"
            font.family: fontBold.name
            font.pixelSize: 20
            text: qsTr("영업일보 인쇄")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                backend.dayCheckOut(cd);
                if(isadmin == true)
                    backend.addLogin("관리자","PRINT 영업일보")
                else
                    backend.addLogin("대보유통","PRINT 영업일보")
            }
        }
    }
    Rectangle {
        id: rectangle21
        x: 415
        y: 930
        width: 250
        height: 6
        color: "#ffffff"
    }

    Rectangle {
        id: rectangle22
        x: 415
        y: 1187
        width: 250
        height: 6
        color: "#ffffff"
    }

    Text {
        id: element7
        y: 554
        color: "#ffffff"
        text: qsTr("영업일자 : ")
        anchors.left: parent.left
        anchors.leftMargin: 300
        font.bold: true
        font.pixelSize: 40
    }

    Text {
        id: element8
        y: 554
        height: 40
        color: "#ffffff"
        text: qsTr("date")
        anchors.right: parent.right
        anchors.rightMargin: 200
        anchors.left: element7.right
        anchors.leftMargin: 30
        font.pixelSize: 40
        font.bold: true
    }

    Rectangle {
        id: btnreport1
        x: 562
        y: 1317
        width: 275
        height: 70
        color: "#ffffff"
        radius: 5
        border.color: "#6e57d1"
        Text {
            color: "#201547"
            text: qsTr("매출현황 인쇄")
            font.family: fontBold.name
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                backend.dayCheckOutCard(cd);
                if(isadmin == true)
                    backend.addLogin("관리자","PRINT 매출현황")
                else
                    backend.addLogin("대보유통","PRINT 매출현황")
            }
        }
        border.width: 0
    }


}

/*##^## Designer {
    D{i:8;anchors_x:29;anchors_y:12}D{i:4;anchors_height:53;anchors_width:290}D{i:13;anchors_x:29;anchors_y:12}
D{i:18;anchors_x:29;anchors_y:12}D{i:44;anchors_x:324}
}
 ##^##*/
