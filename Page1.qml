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
    }

    function closeNotice(){
        notice.close()
        backend.addLog("[PAGE1]     notice : close");
    }




    // ------------------------------------------------



    MouseArea{
        x: 330
        y: 858
        width: 409
        height: 209
        onReleased: {
            if(!mbImageClicked){
//                imageOrderButton.opacity = 1.0
                mbImageClicked = true;
                clearMenuPage();
                swipeView.currentIndex = 1
                clickSound.play()
            }
        }
        onPressed:{
            if(mbImageClicked){
//                imageOrderButton.opacity = 0.7
                mbImageClicked = false;
            }
        }
    }

    Image {
        id: imageBackground
        x: 0
        y: 0
        width: parent.width
        height: parent.height
//        source: "image/background_kenya.png"
        source: "file:C:/Users/POS/Desktop/BobaMenuImage/background_kenya.png"
        fillMode: Image.Stretch
    }

}

