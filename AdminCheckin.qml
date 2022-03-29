import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Private 1.0
import QtQuick.Controls 1.4 as Old
import io.qt.Backend 1.0

Page {
    id: adminCheckinInfo

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
        backend.reloadCheckinContent(date)
        backend.hasDatas(date)
        console.log("--------------------------------------------");
        console.log(backend.getCheckDBSize());
        for(var i = 0; i < backend.getCheckDBSize(); i++){
            listViewContent.model.append({"date_text": backend.getCheckDBDate(i),
                                             "time_text": backend.getCheckDBTime(i),
                                             "user_text": backend.getCheckDBUser(i),
                                             "log_text": backend.getCheckDBLogin(i)});

        }
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
                id:listView_Date
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.verticalCenter: parent.verticalCenter
                text:date_text
                font.pixelSize: 12
                font.bold: true
                color: "black"

            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_Time
                anchors.left: parent.left
                anchors.leftMargin: 150
                anchors.verticalCenter: parent.verticalCenter
                text:time_text
                font.pixelSize: 12
                color: "black"
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_User
                anchors.left: parent.left
                anchors.leftMargin: 300
                anchors.verticalCenter: parent.verticalCenter
                text:user_text
                font.pixelSize: 12
                color: "black"
            }
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_Log
                anchors.left: parent.left
                anchors.leftMargin: 500
                anchors.verticalCenter: parent.verticalCenter
                text:log_text
                font.pixelSize: 12
                color: "black"
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
        y: 503
        width: 1000
        height: 994
        anchors.horizontalCenterOffset: 0
        keyNavigationWraps: false
        anchors.horizontalCenter: parent.horizontalCenter
        model: ListModel{}//임으로 만들 모델을 넣어준다.
        delegate: contactDelegateContent
        focus: true
        boundsBehavior: Flickable.StopAtBounds
        clip: true
        orientation: ListView.Vertical
    }
    Image {
         id: image
         x: 728
         y: 88
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
                    id: img_check
                    visible: backend.hasDatas(styleData.date) > 0
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
}
