import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Window 2.1
//import QtMultimedia 5.0



Item {
    property string __image_src: "";
    property string __drink_id: "";
    property string __drink_text_kor: "블랙티";
    property string __drink_text_eng: "Black Tea";
    property string __drink_description: "유기농\n블랙티+우유";
    property int __drink_type: 0;
    property string __price_text: "\\ "+formatToCurrency(__drink_price) //"2,500";
    property int    __drink_price: 2000
    property bool mDrinkClicked : true;
    property bool mIsSoldOut : false
    property int animation_duration: 350;


    id: drinkItem
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
            font.pixelSize: 20
            lineHeight: 1.2
            visible: true
        }
//        Text {
//            id: drinkNameEng
//            x: 0
//            y: 285
//            width: parent.width
//            height: 30
//            color: "#5b5e66"
//            font.family: fontBold.name
//            text: qsTr("(" + __drink_text_eng + ")")
//            anchors.horizontalCenterOffset: 0
//            verticalAlignment: Text.AlignVCenter
//            horizontalAlignment: Text.AlignHCenter
//            anchors.horizontalCenter: parent.horizontalCenter
//            font.bold: true
//            font.pixelSize: 30
//            visible: true
//        }

        MouseArea{
            anchors.fill: parent
            onReleased: {
                if(!mDrinkClicked){
                    baseImage.opacity = 1.0
                    mDrinkClicked = true;
                    if(mIsSoldOut){

                    }else{
                        page2.sigItem(__drink_text_kor, __drink_text_eng, __drink_description,  __image_src, __drink_price,__drink_type)
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
//    Image{
//        id: soldoutImage
//        x: 0
//        y: 0
//        width: parent.width
//        height: parent.width
//        //anchors.fill: parent
//        source: "image/order_page/sold_out.png"
//        visible: mIsSoldOut ? true : false
//    }

}

