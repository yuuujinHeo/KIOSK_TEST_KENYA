import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Private 1.0
import QtQuick.Controls 1.4 as Old
import io.qt.Backend 1.0

Page {
    id: adminDayReportInfo
    property bool mQuitClicked: true
    property date cd: new Date();
    property string currentdate : cd.toLocaleDateString();

    width: 1060
    height: 1600
    x: 0
    y: 0
    background: Rectangle{color:"#201547"}
    clip:true


    function reload(curdate){
        cd = curdate
        updateContent(cd);
    }

    function updateContent(date){
        backend.reloadContent(date);
        backend.setReport(date);

        total1.text = backend.getReportMenuTotalNum();
        total2.text = backend.getReportTotalAmt();
        total3.text = backend.getReportRefundNum();
        total4.text = backend.getReportRefundAmt();

        amt1.text = backend.getReportMenuAmt(name1.text);
        amt2.text = backend.getReportMenuAmt(name2.text);
        amt3.text = backend.getReportMenuAmt(name3.text);
        amt4.text = backend.getReportMenuAmt("콜드브루 커피");
        amt5.text = backend.getReportMenuAmt(name5.text);
        amt6.text = backend.getReportMenuAmt(name6.text);
        amt7.text = backend.getReportMenuAmt(name7.text);
        amt8.text = backend.getReportMenuAmt("콜드브루 밀크커피");
        amt9.text = backend.getReportMenuAmt(name9.text);

        num1.text = backend.getReportMenuNum(name1.text);
        num2.text = backend.getReportMenuNum(name2.text);
        num3.text = backend.getReportMenuNum(name3.text);
        num4.text = backend.getReportMenuNum("콜드브루 커피");
        num5.text = backend.getReportMenuNum(name5.text);
        num6.text = backend.getReportMenuNum(name6.text);
        num7.text = backend.getReportMenuNum(name7.text);
        num8.text = backend.getReportMenuNum("콜드브루 밀크커피");
        num9.text = backend.getReportMenuNum(name9.text);
    }

    Image {
        id: image
        x: 776
        y: 47
        width: 256
        height: 284
        source: "image/order_page/logo_boba.png"
        fillMode: Image.PreserveAspectFit
    }

    Old.Calendar{
        id: calendar1
        width: 375
        height: 368
        anchors.left: parent.left
        anchors.leftMargin: 353
        anchors.top: parent.top
        anchors.topMargin: 122
        visibleMonth: 5
        dayOfWeekFormat: 1

        minimumDate: new Date(2021, 0, 1)

        style: CalendarStyle{
            dayDelegate: Item{
                readonly property color sameMonthDateTextColor: "#ffffff"
                readonly property color selectedDateColor:  "#3778d0"
                readonly property color selectedDateTextColor: "white"
                readonly property color differentMonthDateTextColor: "#444"
                readonly property color hasSalescolor: "#201547"
                readonly property color invalidDatecolor: "#dddddd"

                Rectangle {
                    anchors.fill: parent
                    border.color: "transparent"
                    color: styleData.date !== undefined && styleData.selected ? selectedDateColor : "#201547"
                    anchors.margins: styleData.selected ? -1 : 0
                }
                Image {
                    visible: backend.hasSales(styleData.date) > 0
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.margins: -1
                    width: 12
                    height: width
                    source: "qrc:/image/credit/check_blue.png"
                }
                Label {
                    id: dayDelegateText
                    text: styleData.date.getDate()
                    anchors.centerIn: parent
                    color: {
                        var color = invalidDatecolor;
                        if (styleData.valid) {
                            // Date is within the valid range.
                            color = styleData.visibleMonth ? sameMonthDateTextColor : differentMonthDateTextColor;
                            if (styleData.selected) {
                                color = selectedDateTextColor;
                            }
                        }
                        color;
                    }
                }
            }
        }
        onClicked: {
            updateContent(selectedDate);
        }
    }


    Rectangle {
        id: btnreport
        x: 403
        y: 1302
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
            text: qsTr("매출현황 인쇄")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                backend.dayCheckOut(calendar1.selectedDate);
                backend.addLogin("관리자","PRINT 영업일보")
            }
        }
    }


    Row {
        x: 308
        y: 832
        spacing: 300

        Column {
            spacing: 30

            Rectangle {
                id: rectangle
                width: 197
                height: 60
                color: "#ffffff"
                radius: 30

                Text {
                    id: amt1
                    text: qsTr("0")
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 20
                }

                Rectangle {
                    id: rectangle1
                    x: -224
                    y: 0
                    width: 187
                    height: 60
                    color: "#8b6fec"
                    radius: 30

                    Rectangle {
                        id: rectangle2
                        x: 161
                        y: 0
                        width: 90
                        height: 60
                        color: "#d1c2ff"

                        Text {
                            id: num1
                            text: qsTr("0")
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            anchors.fill: parent
                            font.pixelSize: 20
                        }
                    }

                    Text {
                        id: name1
                        x: 279
                        y: 0
                        color: "#ffffff"
                        text: "블랙티"
                        anchors.rightMargin: 10
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pixelSize: 20
                    }
                }
            }

            Rectangle {
                id: rectangle3
                width: 197
                height: 60
                color: "#ffffff"
                radius: 30
                Text {
                    id: amt2
                    text: qsTr("0")
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }

                Rectangle {
                    id: rectangle5
                    x: -224
                    y: 0
                    width: 187
                    height: 60
                    color: "#8b6fec"
                    radius: 30
                    Rectangle {
                        id: rectangle4
                        x: 161
                        y: 0
                        width: 90
                        height: 60
                        color: "#d1c2ff"
                        Text {
                            id: num2
                            text: qsTr("0")
                            font.pixelSize: 20
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.fill: parent
                        }
                    }

                    Text {
                        id: name2
                        x: 279
                        y: 0
                        color: "#ffffff"
                        text: "베리티"
                        anchors.rightMargin: 10
                        font.bold: true
                        font.pixelSize: 20
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        anchors.fill: parent
                    }
                }
            }

            Rectangle {
                id: rectangle6
                width: 197
                height: 60
                color: "#ffffff"
                radius: 30
                Text {
                    id: amt3
                    text: qsTr("0")
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }

                Rectangle {
                    id: rectangle8
                    x: -224
                    y: 0
                    width: 187
                    height: 60
                    color: "#8b6fec"
                    radius: 30
                    Rectangle {
                        id: rectangle7
                        x: 161
                        y: 0
                        width: 90
                        height: 60
                        color: "#d1c2ff"
                        Text {
                            id: num3
                            text: qsTr("0")
                            font.pixelSize: 20
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.fill: parent
                        }
                    }

                    Text {
                        id: name3
                        x: 279
                        y: 0
                        color: "#ffffff"
                        text: "말차티"
                        anchors.rightMargin: 10
                        font.bold: true
                        font.pixelSize: 20
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        anchors.fill: parent
                    }
                }
            }

            Rectangle {
                id: rectangle9
                width: 197
                height: 60
                color: "#ffffff"
                radius: 30
                Text {
                    id: amt4
                    text: qsTr("0")
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }

                Rectangle {
                    id: rectangle11
                    x: -224
                    y: 0
                    width: 187
                    height: 60
                    color: "#8b6fec"
                    radius: 30
                    Rectangle {
                        id: rectangle10
                        x: 161
                        y: 0
                        width: 90
                        height: 60
                        color: "#d1c2ff"
                        Text {
                            id: num4
                            text: qsTr("0")
                            font.pixelSize: 20
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.fill: parent
                        }
                    }

                    Text {
                        id: name4
                        x: 279
                        y: 0
                        color: "#ffffff"
                        text: "콜드브루\n커피"
                        anchors.rightMargin: 10
                        font.bold: true
                        font.pixelSize: 20
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        anchors.fill: parent
                    }
                }
            }
        }

        Column {
            spacing: 30

            Rectangle {
                id: rectangle21
                width: 197
                height: 60
                color: "#ffffff"
                radius: 30
                Text {
                    id: amt5
                    text: qsTr("0")
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }

                Rectangle {
                    id: rectangle23
                    x: -224
                    y: 0
                    width: 187
                    height: 60
                    color: "#8b6fec"
                    radius: 30
                    Rectangle {
                        id: rectangle22
                        x: 161
                        y: 0
                        width: 90
                        height: 60
                        color: "#d1c2ff"
                        Text {
                            id: num5
                            text: qsTr("0")
                            font.pixelSize: 20
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.fill: parent
                        }
                    }

                    Text {
                        id: name5
                        x: 279
                        y: 0
                        color: "#ffffff"
                        text: "블랙 밀크티"
                        anchors.rightMargin: 10
                        font.bold: true
                        font.pixelSize: 20
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        anchors.fill: parent
                    }
                }
            }

            Rectangle {
                id: rectangle12
                width: 197
                height: 60
                color: "#ffffff"
                radius: 30
                Text {
                    id: amt6
                    text: qsTr("0")
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }

                Rectangle {
                    id: rectangle14
                    x: -224
                    y: 0
                    width: 187
                    height: 60
                    color: "#8b6fec"
                    radius: 30
                    Rectangle {
                        id: rectangle13
                        x: 161
                        y: 0
                        width: 90
                        height: 60
                        color: "#d1c2ff"
                        Text {
                            id: num6
                            text: qsTr("0")
                            font.pixelSize: 20
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.fill: parent
                        }
                    }

                    Text {
                        id: name6
                        x: 279
                        y: 0
                        color: "#ffffff"
                        text: "베리 밀크티"
                        anchors.rightMargin: 10
                        font.bold: true
                        font.pixelSize: 20
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        anchors.fill: parent
                    }
                }
            }

            Rectangle {
                id: rectangle15
                width: 197
                height: 60
                color: "#ffffff"
                radius: 30
                Text {
                    id: amt7
                    text: qsTr("0")
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }

                Rectangle {
                    id: rectangle17
                    x: -224
                    y: 0
                    width: 187
                    height: 60
                    color: "#8b6fec"
                    radius: 30
                    Rectangle {
                        id: rectangle16
                        x: 161
                        y: 0
                        width: 90
                        height: 60
                        color: "#d1c2ff"
                        Text {
                            id: num7
                            text: qsTr("0")
                            font.pixelSize: 20
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.fill: parent
                        }
                    }

                    Text {
                        id: name7
                        x: 279
                        y: 0
                        color: "#ffffff"
                        text: "말차 밀크티"
                        anchors.rightMargin: 10
                        font.bold: true
                        font.pixelSize: 20
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        anchors.fill: parent
                    }
                }
            }

            Rectangle {
                id: rectangle18
                width: 197
                height: 60
                color: "#ffffff"
                radius: 30
                Text {
                    id: amt8
                    text: qsTr("0")
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }

                Rectangle {
                    id: rectangle20
                    x: -224
                    y: 0
                    width: 187
                    height: 60
                    color: "#8b6fec"
                    radius: 30
                    Rectangle {
                        id: rectangle19
                        x: 161
                        y: 0
                        width: 90
                        height: 60
                        color: "#d1c2ff"
                        Text {
                            id: num8
                            text: qsTr("0")
                            font.pixelSize: 20
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.fill: parent
                        }
                    }

                    Text {
                        id: name8
                        x: 279
                        y: 0
                        color: "#ffffff"
                        text: "콜드브루\n밀크커피"
                        anchors.rightMargin: 10
                        font.bold: true
                        font.pixelSize: 20
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        anchors.fill: parent
                    }
                }
            }
        }
    }

    Rectangle {
        id: rectangle24
        x: 308
        y: 779
        width: 197
        height: 47
        color: "#ffffff"
        radius: 20
        Text {
            id: amt92
            text: qsTr("금액")
            style: Text.Raised
            font.weight: Font.Black
            font.bold: true
            anchors.fill: parent
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Rectangle {
            id: rectangle26
            x: -224
            y: 0
            width: 187
            height: 47
            color: "#8b6fec"
            radius: 20
            Rectangle {
                id: rectangle25
                x: 161
                y: 0
                width: 90
                height: 47
                color: "#d1c2ff"
                Text {
                    id: element16
                    text: qsTr("수량")
                    style: Text.Raised
                    font.bold: false
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }
            }

            Text {
                id: element17
                x: 279
                y: 0
                color: "#000000"
                text: "음료"
                style: Text.Raised
                anchors.rightMargin: 10
                font.bold: true
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }
        }
    }

    Rectangle {
        id: rectangle27
        x: 805
        y: 779
        width: 197
        height: 47
        color: "#ffffff"
        radius: 20
        Text {
            id: amt10
            text: qsTr("금액")
            style: Text.Raised
            font.weight: Font.Black
            font.pixelSize: 20
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
        }

        Rectangle {
            id: rectangle29
            x: -224
            y: 0
            width: 187
            height: 47
            color: "#8b6fec"
            radius: 20
            Rectangle {
                id: rectangle28
                x: 161
                y: 0
                width: 90
                height: 47
                color: "#d1c2ff"
                Text {
                    id: element18
                    text: qsTr("수량")
                    style: Text.Raised
                    font.pixelSize: 20
                    font.bold: false
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }
            }

            Text {
                id: element19
                x: 279
                y: 0
                color: "#000000"
                text: "음료"
                style: Text.Raised
                anchors.rightMargin: 10
                font.pixelSize: 20
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }
        }
    }

    Rectangle {
        id: rectangle30
        x: 539
        y: 779
        width: 5
        height: 383
        color: "#d1c2ff"
    }

    Rectangle {
        id: rectangle31
        x: 278
        y: 562
        width: 528
        height: 168
        color: "#ffffff"
        radius: 30

        Text {
            id: element1
            x: 8
            y: 0
            width: 247
            height: 53
            text: qsTr("매출 수량")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            style: Text.Raised
            font.pixelSize: 20
        }

        Text {
            id: element2
            x: 8
            y: 85
            width: 247
            height: 34
            text: qsTr("매출 금액")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            style: Text.Raised
            font.pixelSize: 20
        }

        Text {
            id: element4
            x: 268
            y: 0
            width: 252
            height: 53
            text: qsTr("반품 수량")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            style: Text.Raised
            font.pixelSize: 20
        }

        Text {
            id: element6
            x: 268
            y: 85
            width: 252
            height: 34
            text: qsTr("반품 금액")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            style: Text.Raised
            font.pixelSize: 20
        }

        Text {
            id: total1
            x: 0
            y: 59
            width: 255
            height: 20
            text: qsTr("0")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
        }

        Text {
            id: total4
            x: 268
            y: 125
            width: 255
            height: 35
            text: qsTr("0")
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: total2
            x: 0
            y: 125
            width: 255
            height: 35
            text: qsTr("0")
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: total3
            x: 268
            y: 59
            width: 255
            height: 20
            text: qsTr("0")
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: rectangle32
        x: 536
        y: 559
        width: 9
        height: 175
        color: "#201547"
    }

    Rectangle {
        id: rectangle33
        x: 805
        y: 1191
        width: 197
        height: 60
        color: "#ffffff"
        radius: 30
        Text {
            id: amt9
            text: qsTr("0")
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
        }

        Rectangle {
            id: rectangle35
            x: -224
            y: 0
            width: 187
            height: 60
            color: "#8b6fec"
            radius: 30
            Rectangle {
                id: rectangle34
                x: 161
                y: 0
                width: 90
                height: 60
                color: "#d1c2ff"
                Text {
                    id: num9
                    text: qsTr("0")
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }
            }

            Text {
                id: name9
                x: 279
                y: 0
                color: "#ffffff"
                text: "보바"
                anchors.rightMargin: 10
                font.bold: true
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }
        }
    }



}

/*##^## Designer {
    D{i:9;anchors_height:53;anchors_width:200}D{i:24;anchors_x:"-1";anchors_y:"-94"}D{i:20;anchors_height:53;anchors_width:200}
D{i:30;anchors_x:"-1";anchors_y:"-94"}D{i:26;anchors_height:53;anchors_width:200}
D{i:36;anchors_x:"-1";anchors_y:"-94"}D{i:32;anchors_height:53;anchors_width:200}
}
 ##^##*/
