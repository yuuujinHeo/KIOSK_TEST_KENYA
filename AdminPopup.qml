import QtQuick 2.10
import QtQuick.Controls 2.3
import io.qt.Backend 1.0


Popup {
    id: adminPopup

    property bool mCloseClicked: true

    width: 1080
    height: 1920
    x: 0
    y: 0
    dim:true
    background: Rectangle{
        color:"white"
    }
    closePolicy: Popup.CloseOnPressOutside //팝업 영역이 아닌곳을 클릭하면 팝업이 닫힘


    function reload(){
        swipeViewAdmin.currentIndex = 0
        adminInfo1.reload()
        adminInfo2.reload()
        adminInfo2.reload()
    }

    function dbReload(){
        adminInfo2.dbReload()
    }


    SwipeView{
        id: swipeViewAdmin
        anchors.fill: parent
        interactive: false

        AdminLogin{
            id:adminInfo1
        }
        AdminSale{
            id:adminInfo2
        }
        AdminSaleToday{
            id:adminInfo3
        }
    }


    Rectangle{
        id: rectClose
        x: 140
        y: 1772
        width:800
        height:100
        color: "#39374d"

        Text {
            anchors.fill: parent
            color: "#ffffff"
            text: "관리자 창 닫기"
            font.pixelSize: 40
            font.family: fontBold.name
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

        }

        MouseArea {
            anchors.fill: parent
            onReleased: {
                if(!mCloseClicked){
                    rectClose.opacity = 1.0
                    mCloseClicked = true;
                    backend.reloadContentLast()

                    if(swipeViewAdmin.currentIndex == 1)
                        backend.addLogin("관리자","LOGOUT");
                    else if(swipeViewAdmin.currentIndex == 2)
                        backend.addLogin("대보유통","LOGOUT");

                    adminPopup.close()
                }
            }
            onPressed:{
                if(mCloseClicked){
                    rectClose.opacity = 0.7
                    mCloseClicked = false;
                }
            }
        }
    }

//    Button
//    {
//        id:closeButton
//        x: 140
//        y: 1772
//        anchors.bottom:parent.bottom
//        anchors.bottomMargin: 48
//        width:800
//        height:100
//        background: Rectangle{
//            color: "#39374d"
//        }
//        text: "닫기"

//        font.pixelSize: 40

//        onClicked: {//버튼을 누르면 파법이 닫히도록 구현
//            adminPopup.close()
//        }
//    }
}
