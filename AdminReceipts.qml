import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Private 1.0
import QtQuick.Controls 1.4 as Old
import io.qt.Backend 1.0

Page {
    id: adminReceiptsInfo

    property bool mQuitClicked: true
    width: 1080
    height: 1800
    x: 0
    y: 0
    background: Rectangle{color:"#201547"}
    clip:true

    function reload(){
        updateContent(calendar1.selectedDate)
    }

    function updateContent(date){
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


    Row {
        id: row2
        x: 684
        width: 400
        height: 66
        anchors.top: row.bottom
        anchors.topMargin: 5
        anchors.horizontalCenter: row.horizontalCenter
        transformOrigin: Item.Center
        spacing: 10

        Text {
            width: 95
            height: 27
            color: "#ffffff"
            text: "결산 종료일"
            anchors.verticalCenter: parent.verticalCenter
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 18
        }

        ComboBox {
            id: comboBoxEndYear
            width: 100
            height: 48
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 11
            model:["2020","2021","2022","2023","2024","2025"];

        }

        ComboBox {
            id: comboBoxEndMonth
            width: 80
            height: 48
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 11
            model: ["1","2","3","4","5","6","7","8","9","10","11","12"];
        }

        ComboBox {
            id: comboBoxEndDay
            width: 80
            height: 48
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 11
            model: ["1","2","3","4","5","6","7","8","9","10",
                "11","12","13","14","15","16","17","18","19","20",
                "21","22","23","24","25","26","27","28","29","30","31"];
        }
    }

    Row {
        id: row
        x: 506
        y: 134
        width: 400
        height: 56
        spacing: 10

        Text {
            width: 95
            height: 27
            color: "#ffffff"
            text: "결산 시작일"
            anchors.verticalCenter: parent.verticalCenter
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 18
        }

        ComboBox {
            id: comboBoxStartYear
            width: 100
            flat: false
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 11
            model:["2020","2021","2022","2023","2024","2025"]
        }

        ComboBox {
            id: comboBoxStartMonth
            width: 80
            height: 48
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 11
            model:["1","2","3","4","5","6","7","8","9","10","11","12"]
        }

        ComboBox {
            id: comboBoxStartDay
            width: 80
            height: 48
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 11
            model:["1","2","3","4","5","6","7","8","9","10",
                "11","12","13","14","15","16","17","18","19","20",
                "21","22","23","24","25","26","27","28","29","30","31"]
        }
    }

    Component.onCompleted: {
        var year = backend.getYear();
        var month = backend.getMonth();
        var day = backend.getDay();

        comboBoxStartYear.currentIndex = year;
        comboBoxStartMonth.currentIndex = month;
        comboBoxStartDay.currentIndex = day;

        comboBoxEndYear.currentIndex = year;
        comboBoxEndMonth.currentIndex = month;
        comboBoxEndDay.currentIndex = day;

    }

    Component {//리스트 뷰의 틀을 만든다.
        id: contactDelegateContent
        Rectangle {
            id: wrapper
            width: 1000
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
                color: ListView.isCurrentItem ? "white" : "black"

            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_Time
                anchors.left: parent.left
                anchors.leftMargin: 50
                anchors.verticalCenter: parent.verticalCenter
                text:time_text
                font.pixelSize: 12
                color: ListView.isCurrentItem ? "white" : "black"
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_Menu
                anchors.left: parent.left
                anchors.leftMargin: 130
                anchors.verticalCenter: parent.verticalCenter
                text:menu_text
                font.pixelSize: 12
                color: ListView.isCurrentItem ? "white" : "black"
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_Price
                anchors.left: parent.left
                anchors.leftMargin: 270
                anchors.verticalCenter: parent.verticalCenter
                text:price_text
                font.pixelSize: 12
                color: ListView.isCurrentItem ? "white" : "black"
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_CardComp
                anchors.left: parent.left
                anchors.leftMargin: 340
                anchors.verticalCenter: parent.verticalCenter
                text:card_comp_text
                font.pixelSize: 12
                color: ListView.isCurrentItem ? "white" : "black"
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_CardNum
                anchors.left: parent.left
                anchors.leftMargin: 470
                anchors.verticalCenter: parent.verticalCenter
                text:card_num_text
                font.pixelSize: 12
                color: ListView.isCurrentItem ? "white" : "black"
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_AppNum
                anchors.left: parent.left
                anchors.leftMargin: 600
                anchors.verticalCenter: parent.verticalCenter
                text:app_num_text
                font.pixelSize: 12
                color: ListView.isCurrentItem ? "white" : "black"
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_TranDate
                anchors.left: parent.left
                anchors.leftMargin: 700
                anchors.verticalCenter: parent.verticalCenter
                text:tran_date_text
                font.pixelSize: 12
                color: ListView.isCurrentItem ? "white" : "black"
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_IsCancel
                anchors.left: parent.left
                anchors.leftMargin: 800
                anchors.verticalCenter: parent.verticalCenter
                text:is_cancel_text
                font.pixelSize: 12
                color: ListView.isCurrentItem ? "white" : "black"
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
                    console.log("clicked %d",index)
                }
            }
        }
    }

    ListView {
        id:listViewContent
        x: 40
        y: 524
        width: 1000
        height: 1140
        keyNavigationWraps: false
        anchors.horizontalCenter: parent.horizontalCenter
        model: ListModel{}//임으로 만들 모델을 넣어준다.
        delegate: contactDelegateContent
//        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
//        highlightMoveDuration: 1
        focus: true
        boundsBehavior: Flickable.StopAtBounds
        clip: true
        orientation: ListView.Vertical
    }


    Old.Calendar{
        id: calendar1
        width: 375
        height: 368
        anchors.left: parent.left
        anchors.leftMargin: 100
        anchors.top: parent.top
        anchors.topMargin: 100
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



    //-----------------------------------------------------------
    //-----------------------------------------------------------

    Rectangle {
        id: btncancel
        x: 706
        y: 308
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
                backend.setOrderOnSalesLog(calendar1.selectedDate, listViewContent.currentIndex)
                backend.doCancel(calendar1.selectedDate, listViewContent.currentIndex)

                backend.addLogin("관리자","CANCEL")
            }
        }
    }

    Rectangle {
        id: btnreportdays
        x: 930
        y: 140
        width: 102
        height: 115
        color: "#ffffff"
        radius: 5
        border.width: 0
        border.color: "#6e57d1"

        Text {
            anchors.fill: parent
            color: "#201547"
            font.family: fontBold.name
            font.pixelSize: 20
            text: "기간\n결산"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                var startDate = comboBoxStartYear.currentText + "-" + comboBoxStartMonth.currentText + "-" + comboBoxStartDay.currentText;
                var endDate = comboBoxEndYear.currentText + "-" + comboBoxEndMonth.currentText + "-" + comboBoxEndDay.currentText;
                backend.checkOut(startDate, endDate);
            }
        }
    }

    Rectangle {
        id: btnprint
        x: 524
        y: 305
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
                backend.setOrderOnSalesLog(calendar1.selectedDate, listViewContent.currentIndex)
                backend.doPrintagain(listViewContent.currentIndex)

                backend.addLogin("관리자","PRINT AGAIN")
            }
        }
    }
    Rectangle {
        id: btnreport
        x: 882
        y: 308
        width: 150
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
            text: qsTr("영업일보")
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

    Rectangle {
        id: buttonSales
        x: 882
        y: 398
        width: 150
        height: 70
        color: "#ffffff"
        radius: 5
        border.width: 0
        border.color: "#6e57d1"

        Text {
            anchors.fill: parent
            color: "#000000"
            font.family: fontBold.name
            font.pixelSize: 20
            text: qsTr("매출전표")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                backend.dayCheckOutCard(calendar1.selectedDate);
                backend.addLogin("관리자","PRINT 매출현황")
            }
        }
    }
}
