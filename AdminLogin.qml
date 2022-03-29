import QtQuick 2.10
import QtQuick.Controls 2.3
import io.qt.Backend 1.0


Page {
    id: adminLoginInfo

    width: 1080
    height: 1800
    x: 0
    y: 0
    background: Rectangle{color:"#201547"}
    clip:true


    property bool m1Clicked : true
    property bool m2Clicked : true
    property bool m3Clicked : true
    property bool m4Clicked : true
    property bool m5Clicked : true
    property bool m6Clicked : true
    property bool m7Clicked : true
    property bool m8Clicked : true
    property bool m9Clicked : true

    property int mPass1 : 0
    property int mPass2 : 0
    property int mPass3 : 0
    property int mPass4 : 0
    property int mCursor : 1

    property bool isadmin: false


    function reload(){
        mCursor = 1

        mPass1 = 0
        mPass2 = 0
        mPass3 = 0
        mPass4 = 0
    }

    function password(key){
        if(mCursor === 1){
            mPass1 = key
        }else if(mCursor === 2){
            mPass2 = key
        }else if(mCursor === 3){
            mPass3 = key
        }else if(mCursor === 4){
            mPass4 = key
        }

        mCursor = mCursor+1
        if(mCursor > 4){
            mCursor = 1
            if(mPass1 === 9 && mPass2 === 9 && mPass3 === 9 && mPass4 === 9){
//                swipeViewAdmin.currentIndex = 1
                swipeViewAdminMain.currentIndex = 1
                backend.addLogin("관리자","LOGIN");
                isadmin=true

            }
            if(mPass1 === 1 && mPass2 === 1 && mPass3 === 1 && mPass4 === 1){
//                adminInfo3.updateContent()
                swipeViewAdminMain.currentIndex = 2
                backend.addLogin("대보유통","LOGIN");
                isadmin=false
            }


            mPass1 = 0
            mPass2 = 0
            mPass3 = 0
            mPass4 = 0
        }
    }
   Image {
        id: image
        x: 413
        y: 188
        width: 256
        height: 284
        source: "image/order_page/logo_boba.png"
        fillMode: Image.PreserveAspectFit
    }

    Grid {
        id: grid
        x: 200
        y: 750
        width: 664
        height: 674
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 30
        rows: 3
        columns: 3


        Rectangle {
            id: rect1
            width: 200
            height: 200
            color: "#201547"
            radius: 80
            border.width: 15
            border.color: "#848484"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                font.family: fontBold.name
                font.pixelSize: 60
                text: "1"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea{
                anchors.fill: parent
                onReleased: {
                    if(!m1Clicked){
                        rect1.opacity = 1.0
                        m1Clicked = true;
                        password(1)
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(m1Clicked){
                        rect1.opacity = 0.7
                        m1Clicked = false;
                    }
                }
            }
        }

        Rectangle {
            id: rect2
            width: 200
            height: 200
            color: "#201547"
            radius: 80
            border.color: "#848484"
            border.width: 15

            Text {
                anchors.fill: parent
                color: "#ffffff"
                font.family: fontBold.name
                font.pixelSize: 60
                text: "2"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea{
                anchors.fill: parent
                onReleased: {
                    if(!m2Clicked){
                        rect2.opacity = 1.0
                        m2Clicked = true;
                        password(2)
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(m2Clicked){
                        rect2.opacity = 0.7
                        m2Clicked = false;
                    }
                }
            }
        }

        Rectangle {
            id: rect3
            width: 200
            height: 200
            color: "#201547"
            radius: 80
            border.width: 15
            border.color: "#848484"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                font.family: fontBold.name
                font.pixelSize: 60
                text: "3"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea{
                anchors.fill: parent
                onReleased: {
                    if(!m3Clicked){
                        rect3.opacity = 1.0
                        m3Clicked = true;
                        password(3)
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(m3Clicked){
                        rect3.opacity = 0.7
                        m3Clicked = false;
                    }
                }
            }
        }

        Rectangle {
            id: rect4
            width: 200
            height: 200
            color: "#201547"
            radius: 80
            border.color: "#848484"
            border.width: 15

            Text {
                anchors.fill: parent
                color: "#ffffff"
                font.family: fontBold.name
                font.pixelSize: 60
                text: "4"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea{
                anchors.fill: parent
                onReleased: {
                    if(!m4Clicked){
                        rect4.opacity = 1.0
                        m4Clicked = true;
                        password(4)
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(m4Clicked){
                        rect4.opacity = 0.7
                        m4Clicked = false;
                    }
                }
            }
        }

        Rectangle {
            id: rect5
            width: 200
            height: 200
            color: "#201547"
            radius: 80
            border.width: 15
            border.color: "#848484"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                font.family: fontBold.name
                font.pixelSize: 60
                text: "5"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea{
                anchors.fill: parent
                onReleased: {
                    if(!m5Clicked){
                        rect5.opacity = 1.0
                        m5Clicked = true;
                        password(5)
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(m5Clicked){
                        rect5.opacity = 0.7
                        m5Clicked = false;
                    }
                }
            }
        }

        Rectangle {
            id: rect6
            width: 200
            height: 200
            color: "#201547"
            radius: 80
            border.width: 15
            border.color: "#848484"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                font.family: fontBold.name
                font.pixelSize: 60
                text: "6"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea{
                anchors.fill: parent
                onReleased: {
                    if(!m6Clicked){
                        rect6.opacity = 1.0
                        m6Clicked = true;
                        password(6)
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(m6Clicked){
                        rect6.opacity = 0.7
                        m6Clicked = false;
                    }
                }
            }
        }

        Rectangle {
            id: rect7
            width: 200
            height: 200
            color: "#201547"
            radius: 80
            border.width: 15
            border.color: "#848484"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                font.family: fontBold.name
                font.pixelSize: 60
                text: "7"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea{
                anchors.fill: parent
                onReleased: {
                    if(!m7Clicked){
                        rect7.opacity = 1.0
                        m7Clicked = true;
                        password(7)
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(m7Clicked){
                        rect7.opacity = 0.7
                        m7Clicked = false;
                    }
                }
            }
        }

        Rectangle {
            id: rect8
            width: 200
            height: 200
            color: "#201547"
            radius: 80
            border.width: 15
            border.color: "#848484"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                font.family: fontBold.name
                font.pixelSize: 60
                text: "8"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea{
                anchors.fill: parent
                onReleased: {
                    if(!m8Clicked){
                        rect8.opacity = 1.0
                        m8Clicked = true;
                        password(8)
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(m8Clicked){
                        rect8.opacity = 0.7
                        m8Clicked = false;
                    }
                }
            }
        }

        Rectangle {
            id: rect9
            width: 200
            height: 200
            color: "#201547"
            radius: 80
            border.width: 15
            border.color: "#848484"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                font.family: fontBold.name
                font.pixelSize: 60
                text: "9"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea{
                anchors.fill: parent
                onReleased: {
                    if(!m9Clicked){
                        rect9.opacity = 1.0
                        m9Clicked = true;
                        password(9)
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(m9Clicked){
                        rect9.opacity = 0.7
                        m9Clicked = false;
                    }
                }
            }
        }

    }


    Rectangle {
        id: rectangle
        x: 209
        y: 624
        width: 150
        height: 20
        color: "#848484"
        radius: 10
    }

    Rectangle {
        x: 727
        y: 624
        width: 150
        height: 20
        color: "#848484"
        radius: 10
    }

    Rectangle {
        x: 545
        y: 624
        width: 150
        height: 20
        color: "#898989"
        radius: 10
    }

    Rectangle {
        x: 378
        y: 624
        width: 150
        height: 20
        color: "#848484"
        radius: 10
    }


    Text {
        id: textPass1
        x: 264
        y: 506
        color: "#ffffff"
        font.family: fontBold.name
        font.pixelSize: 120
        text: (mPass1 == 0) ? " " : "*"
        anchors.verticalCenterOffset: 0
        anchors.topMargin: 0
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: textPass2
        x: 433
        y: 506
        color: "#ffffff"
        font.family: fontBold.name
        font.pixelSize: 120
        text: (mPass2 == 0) ? " " : "*"
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: textPass3
        x: 600
        y: 506
        color: "#ffffff"
        font.family: fontBold.name
        font.pixelSize: 120
        text: (mPass3 == 0) ? " " : "*"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: textPass4
        x: 782
        y: 506
        color: "#ffffff"
        font.family: fontBold.name
        font.pixelSize: 120
        text: (mPass4 == 0) ? " " : "*"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
