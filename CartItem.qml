import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Window 2.1
//import QtMultimedia 5.0



Item {
    property string __image_src: "";
    property string __drink_id: "";
    property string __drink_text_kor: "블랙티";
   property bool mDrinkClicked : true;
    property bool mIsSoldOut : false
    property int animation_duration: 350;


    id: cartItem
    width: 218
    height: 344


    function checkSoldout(){
        mIsSoldOut = backend.getSoldOut(__drink_text_kor);
    }

    Image{
        id: baseImage
        width: parent.width
        height: parent.width
        fillMode: Image.Stretch
        //anchors.fill: parent
        source: __image_src
//        visible: (__image_src == "") ? false : true

        Rectangle{
            id: rectSoldout
            width: parent.width
            height: parent.height
            color: "#ffffff"
            opacity: mIsSoldOut ? 0.7 : 0.0
        }

        Text {
            id: drinkNameKor
            x: 0
            y: 242
            width: parent.width
            height: 60
            color: "#5b5e66"
            font.family: fontBold.name
            text: qsTr(__drink_text_kor)
            anchors.horizontalCenterOffset: 0
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
//            font.bold: true
            font.pixelSize: 28
            lineHeight: 1.2
            visible: true
        }
        MouseArea{
            anchors.fill: parent
            onReleased: {
                if(!mDrinkClicked){
                    baseImage.opacity = 1.0
                    mDrinkClicked = true;
                    if(mIsSoldOut){

                    }else{
                        orderManage.removeOrderFromCart(index)
//                        page2.deleteItem(__drink_text_kor)
                    }
                    clickSound.play()
                }
            }
            onPressed:{
                if(mDrinkClicked){
                    if(mIsSoldOut){

                    }else{
                        baseImage.opacity = 0.7
                    }
                    mDrinkClicked = false;
                }
            }

        }
    }

}

