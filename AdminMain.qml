import QtQuick 2.10
import QtQuick.Controls 2.3
import io.qt.Backend 1.0

Popup {
    id: adminMain

    property bool mCloseClicked: true
    property date cd: new Date()
    width: 1080
    height: 1920
    dim: true
    closePolicy: Popup.CloseOnPressOutside //팝업 영역이 아닌곳을 클릭하면 팝업이 닫힘
    clip: true

    function reload(){
        cd = backend.getDate()
        swipeViewAdminMain.currentIndex = 0
        adminInfoLogin.reload()
        adminInfoMenu.reload(true,cd)
        userInfoMenu.reload(false,cd)
        adminInfoReceipts.reload(cd)
        userInfoReceipts.reload(cd)
        adminInfoCheckin.reload()
        adminInfoSales.reload(cd)
        adminInfoDayReport.reload(true, cd)
    }

    SwipeView{
        id: swipeViewAdminMain
        anchors.fill: parent
        anchors.leftMargin: -15
        anchors.rightMargin: -15
        anchors.bottomMargin: -15
        anchors.topMargin: -15
        interactive: false
        clip: true

        AdminLogin{
            id:adminInfoLogin
        }
        AdminMenu{
            id:adminInfoMenu
        }
        AdminMenu{
            id:userInfoMenu
        }
        AdminDayReport{
            id:adminInfoDayReport
        }
        AdminReceipts{
            id:adminInfoReceipts
        }
        AdminReceiptsToday{
            id:userInfoReceipts
        }
        AdminSales{
            id:adminInfoSales
        }
        AdminCheckin{
            id:adminInfoCheckin
        }
    }

    Rectangle {
        id: rectangle4
        x: 313
        y: 1672
        width: 455
        height: 148
        color: "#ffffff"
        radius: 30
        border.color: "#ffffff"
        clip: false
        MouseArea {
            id: mouseArea_sales1
            anchors.fill: parent
            Text {
                id: element6
                color: "#311669"
                text: qsTr("페이지 나가기")
                anchors.fill: parent
                fontSizeMode: Text.FixedSize
                style: Text.Outline
                font.family: "Arial"
                font.weight: Font.DemiBold
                font.bold: true
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
                styleColor: "#000000"
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: {
                if(!mCloseClicked){
                    rectangle4.opacity = 1.0
                    mCloseClicked = true;
//                    backend.reloadContent(date)

                    if(adminInfoLogin.isadmin == true){
                        backend.addLogin("관리자","LOGOUT");
                    }else{
                        backend.addLogin("대보유통","LOGOUT");
                    }

                    adminMain.close()
                }
            }
            onPressed:{
                if(mCloseClicked){
                    rectangle4.opacity = 0.7
                    mCloseClicked = false;
                }
            }
        }
        border.width: 1
    }

}
