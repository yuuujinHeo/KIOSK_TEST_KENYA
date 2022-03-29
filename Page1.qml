import QtQuick 2.10
import QtQuick.Controls 2.3
//import QtMultimedia 5.0


Page {
    property bool mbImageClicked : true
    property bool mIsOnFixxing : false
    property bool mIsInCleaning: false
    property bool mISOnWating : false
    property int mPlatformStatus : 0

    id: page1
    width: 1080
    height: 1920



    function dbReload(){
        adminMain.dbReload()
    }

    function openNotice(){
        switch(mPlatformStatus){
        case 1:
            notice.__image_src = "image/notice_page/maintenance.png"
            notice.__background_src = "image/notice_page/background.png"
            notice.open()
            break;
        case 2:
            notice.__image_src = "image/notice_page/cleaning.png"
            notice.__background_src = "image/notice_page/background.png"
            notice.open()
            break;
        case 3:
            notice.__image_src = "image/notice_page/please_wait.png"
            notice.__background_src = "image/notice_page/background.png"
            notice.open()
            break;
        case 4:
            break;
        case 5:
            notice.__image_src = "image/notice_page/pre_cleaning.png"
            notice.__background_src = "image/notice_page/background.png"
            notice.open()
            break;
        case 6:
            notice.__image_src = "image/notice_page/pre_operation.png"
            notice.__background_src = "image/notice_page/background.png"
            notice.open()
            break;
        case 7:
            notice.__background_src = "image/notice_page/disconnected.png"
            notice.__image_src = ""//"image/notice_page/discon.png"
            notice.open()
            break;
        }



//        if(mIsOnFixxing){
//            notice.stateofboba = 1
//            notice.__image_src = "image/notice_page/maintenance.png"
//            notice.open()
//        }else if(mIsInCleaning){
//            notice.stateofboba = 2
//            notice.__image_src = "image/notice_page/cleaning.png"
//            notice.open()
//        }else if(mISOnWating){
//            notice.stateofboba = 3
//            notice.__image_src = "image/notice_page/please_wait.png"
//            notice.open()
//        }
    }

    function closeNotice(){
        notice.close()
        backend.addLog("[PAGE1]     notice : close");
    }




    // ------------------------------------------------



    Image {
        id: imageBackground
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        source: "image/main_page/main_background.png"
        fillMode: Image.Stretch

        Image {
            id: imageOrderButton
            x: 179
            y: 850
            width: 722
            height: 311
            anchors.top: parent.top
            anchors.topMargin: 617
            anchors.right: parent.right
            anchors.rightMargin: 179
            source: "image/main_page/main_order.png"
            fillMode: Image.PreserveAspectFit

            MouseArea{
                anchors.rightMargin: 0
                anchors.bottomMargin: -5
                anchors.leftMargin: 0
                anchors.topMargin: 3
                anchors.fill: parent
                onReleased: {
                    if(!mbImageClicked){
                        imageOrderButton.opacity = 1.0
                        mbImageClicked = true;
                        clearMenuPage();
                        swipeView.currentIndex = 1
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(mbImageClicked){
                        imageOrderButton.opacity = 0.7
                        mbImageClicked = false;
                    }
                }
            }
        }




        Text {
            id: textIsTest
            x: 251
            y: 1783
            width: 579
            height: 105
            color: "#4a7f6a"
            text: "테스트 모드 입니다."
            verticalAlignment: Text.AlignTop
            font.family: fontBold.name
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 1.2
            font.pixelSize: 80
            visible: globalIsTestMode ? true : false
        }

        MouseArea {
            id: mouseAreaAdmin
            x: 0
            y: 226
            width: 64
            height: 63
            anchors.leftMargin: 216
            anchors.left: parent.left
            onClicked: {
//                adminPopup.reload()
//                adminPopup.open()
                backend.addLog("[QML]       Enter Admin");
                adminMain.reload()
                adminMain.open()
            }
        }

        Image {
            id: imageLogo
            x: 91
            y: 121
            width: 454
            height: 173
            fillMode: Image.PreserveAspectFit
            source: "image/main_page/main_logo.png"
        }
    }

    AdminMain{
        id: adminMain
    }

    Notice{
        id: notice
    }

}

