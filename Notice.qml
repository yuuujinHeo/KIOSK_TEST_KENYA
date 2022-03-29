import QtQuick 2.10
import QtQuick.Controls 2.3
import io.qt.Backend 1.0


Popup {
    property string __image_src: ""
    property string __background_src: ""
    id: noticePopup

    width: 1080
    height: 1920
    x: 0
    y: 0
    dim:true
    background: Rectangle{
        color:"black"
    }
    closePolicy: Popup.CloseOnPressOutside //팝업 영역이 아닌곳을 클릭하면 팝업이 닫힘


//    SwipeView{
//        id: swipeViewAdmin
//        anchors.fill: parent
    //        interactive: false
    //    }


    Image {
        id: image
        x: -74
        y: 0
        width: 1232
        height: 1920
        source: __background_src
        fillMode: Image.PreserveAspectFit

        Image {
            id: image1
            x: 302
            y: 611
            width: 628
            height: 698
            fillMode: Image.PreserveAspectFit
            source: __image_src
        }
    }
}
