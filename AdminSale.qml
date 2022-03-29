import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls 1.4 as Old
import io.qt.Backend 1.0

Item {
    id: adminSaleInfo

    property bool mQuitClicked: true


    width: 1080
    height: 1800
    x: 0
    y: 0


    function dbReload(){
        updateContent(listViewSaleDate.currentIndex)
    }

    function reload(){
//        swipeViewAdmin.currentIndex = 0
        listViewSaleDate.model.clear()

        //backend.reloadSaleData()
        var year_month = comboBoxTargetYear.currentText + "-" + comboBoxTargetMonth.currentText
        backend.updateSaleMonth(year_month)

        for(var i = 0; i < backend.getSaleDateSize(); i++){//리스트의 개수만큼 for문을 돌린다.
            listViewSaleDate.model.append({"list_text": backend.getSaleDateAt(i)})
//            console.log(backend.getSaleDateAt(i))
        }
    }

    function updateContent(idx){
        listViewContent.model.clear()
        backend.reloadContent(idx)
        for(var i = 0; i < backend.getContentSize(idx); i++){
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


    Component.onCompleted: {
        var year = backend.getYear();
        var month = backend.getMonth();
        var day = backend.getDay();

        comboBoxTargetYear.currentIndex = year;
        comboBoxTargetMonth.currentIndex = month;

        comboBoxStartYear.currentIndex = year;
        comboBoxStartMonth.currentIndex = month;
        comboBoxStartDay.currentIndex = day;

        comboBoxEndYear.currentIndex = year;
        comboBoxEndMonth.currentIndex = month;
        comboBoxEndDay.currentIndex = day;

    }


//    Old.Calendar{
//        id: calendar1
//        x: 533
//        y: 295

//        minimumDate: new Date(2021, 0, 1)
//    }


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
                    backend.addLogin("관리자","QUIT")
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
        id: contactDelegateSaleDate
        Item {
            width: 450
            height: 50
            Text//리스트에 텍스트를 넣어주기 위해 텍스트 객체를 만들어준다.
            {
                id:listView_Text
                anchors.left: parent.left
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter
                text:list_text//모델에 매칭이될 변수 listview에 원하는 값을 넣기위해서 설정하는 값
                font.pixelSize: 20
            }
            Button//리스트에 버튼을 넣어주기 위해 버튼 객체를 만들어준다.
            {
                id:listView_ButtonDetail
                width:80
                height:40
                anchors.rightMargin: 190
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                text: "상세내용"
                onClicked:{
                    listViewSaleDate.currentIndex = index
                    updateContent(index)
                }
            }
            Button//리스트에 버튼을 넣어주기 위해 버튼 객체를 만들어준다.
            {
                id:listView_ButtonCheckOut
                width:80
                height:40
                anchors.rightMargin: 100
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                text: "영업일보"
                onClicked:{
                    listViewSaleDate.currentIndex = index
                    updateContent(index)
                    backend.dayCheckOut(index);
                    backend.addLogin("관리자","PRINT 영업일보")
                }
            }
            Button//리스트에 버튼을 넣어주기 위해 버튼 객체를 만들어준다.
            {
                id:listView_ButtonCheckOutCard
                width:80
                height:40
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                text: "매출현황"
                onClicked:{
                    listViewSaleDate.currentIndex = index
                    updateContent(index)
                    backend.dayCheckOutCard(index);
                    backend.addLogin("관리자","PRINT 매출현황")
                }
            }
            Rectangle//리스트의 구분선
            {
                id:line
                width:parent.width
                anchors.bottom:parent.bottom//현재 객체의 아래 기준점을 부모객체의 아래로 잡아주어서 위치가 아래로가게 설정
                height:1
                color:"black"
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
        id:listViewSaleDate
        x: 40
        y: 163
        //        anchors.rightMargin: 172
//        anchors.bottomMargin: 320
//        anchors.leftMargin: -172
//        anchors.topMargin: -320
//        anchors.fill: parent
        width: 450
        height: 415
        anchors.horizontalCenterOffset: -275
        anchors.horizontalCenter: parent.horizontalCenter
        model: ListModel{}//임으로 만들 모델을 넣어준다.
        delegate: contactDelegateSaleDate
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        highlightMoveDuration: 1
        focus: true
        boundsBehavior: Flickable.StopAtBounds
        clip: true
        orientation: ListView.Vertical
    }

    ListView {
        id:listViewContent
        x: 40
        y: 680
        //        anchors.rightMargin: 172
//        anchors.bottomMargin: 320
//        anchors.leftMargin: -172
//        anchors.topMargin: -320
//        anchors.fill: parent
        width: 1000
        height: 984
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
    ComboBox {
        id: comboBoxTargetYear
        x: 61
        y: 99
        width: 100
        font.pointSize: 11
        model: ["2020","2021","2022","2023","2024","2025"]
    }
    ComboBox {
        id: comboBoxTargetMonth
        x: 173
        y: 99
        width: 80
        height: 48
        font.pointSize: 11
        model: ["1","2","3","4","5","6","7","8","9","10","11","12"]
    }
    Button {
        id: buttonListUpdate
        x: 280
        y: 99
        width: 140
        height: 48
        text: "업데이트"
        font.pixelSize: 20
        onClicked: {
            reload()
        }
    }
    //-----------------------------------------------------------


    Button {
        id: buttonCreditCancel
        x: 900
        y: 618
        width: 140
        height: 48
        text: "결제취소"
        font.pixelSize: 20
        onClicked: {
            backend.setOrderOnSalesLog(listViewSaleDate.currentIndex, listViewContent.currentIndex)
            backend.doCancel(listViewSaleDate.currentIndex, listViewContent.currentIndex)

            backend.addLogin("관리자","CANCEL")
        }
    }

    Button {
        id: buttonTestMode
        x: 53
        y: 618
        width: 140
        height: 48
        text: "테스트모드"
        font.pixelSize: 20
        onClicked: {
            backend.setIsTest(1)
            backend.addLogin("관리자","SET TESTMODE")
        }
    }

    Button {
        id: buttonRunMode
        x: 222
        y: 618
        width: 140
        height: 48
        text: "장사모드"
        font.pixelSize: 20
        onClicked: {
            backend.setIsTest(0)
            backend.addLogin("관리자","SET RUNMODE")
        }
    }

    Rectangle {
        id: rectangle
        x: 507
        y: 156
        width: 5
        height: 430
        color: "#b58f8f"
    }

    ComboBox {
        id: comboBoxStartYear
        x: 649
        y: 163
        width: 100
        font.pointSize: 11
        model:["2020","2021","2022","2023","2024","2025"]
    }

    ComboBox {
        id: comboBoxEndYear
        x: 649
        y: 236
        width: 100
        height: 48
        font.pointSize: 11
        model:["2020","2021","2022","2023","2024","2025"]

    }

    ComboBox {
        id: comboBoxStartMonth
        x: 761
        y: 163
        width: 80
        height: 48
        font.pointSize: 11
        model:["1","2","3","4","5","6","7","8","9","10","11","12"]
    }

    ComboBox {
        id: comboBoxStartDay
        x: 864
        y: 163
        width: 80
        height: 48
        font.pointSize: 11
        model:["1","2","3","4","5","6","7","8","9","10",
            "11","12","13","14","15","16","17","18","19","20",
            "21","22","23","24","25","26","27","28","29","30","31"]
    }

    ComboBox {
        id: comboBoxEndMonth
        x: 761
        y: 235
        width: 80
        height: 48
        font.pointSize: 11
        model: ["1","2","3","4","5","6","7","8","9","10","11","12"]
    }

    ComboBox {
        id: comboBoxEndDay
        x: 864
        y: 235
        width: 80
        height: 48
        font.pointSize: 11
        model: ["1","2","3","4","5","6","7","8","9","10",
                    "11","12","13","14","15","16","17","18","19","20",
            "21","22","23","24","25","26","27","28","29","30","31"]
    }

    Text {
        x: 533
        y: 174
        width: 95
        height: 27
        text: "결산 시작일"
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 18
    }
    Text {
        x: 533
        y: 246
        width: 95
        height: 27
        text: "결산 종료일"
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 18
    }

    Button {
        id: buttonCheckOut
        x: 962
        y: 163
        width: 102
        height: 115
        text: "기간\n결산"
        font.pixelSize: 20
        onClicked: {
            var startDate = comboBoxStartYear.currentText + "-" + comboBoxStartMonth.currentText + "-" + comboBoxStartDay.currentText;
            var endDate = comboBoxEndYear.currentText + "-" + comboBoxEndMonth.currentText + "-" + comboBoxEndDay.currentText;
            backend.checkOut(startDate, endDate);
        }
    }

    Button {
        id: buttonCreditPrint
        x: 747
        y: 618
        width: 140
        height: 48
        text: "재발행"
        font.pixelSize: 20
        onClicked: {
//            updateContent(index)
//            backend.reloadContent(idx)
            backend.setOrderOnSalesLog(listViewSaleDate.currentIndex, listViewContent.currentIndex)
            backend.doPrintagain(listViewSaleDate.currentIndex, listViewContent.currentIndex)

            backend.addLogin("관리자","PRINT AGAIN")
        }
    }

}
