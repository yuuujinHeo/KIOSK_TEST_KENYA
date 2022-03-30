import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Window 2.1
import io.qt.OrderManage 1.0



Item {
    property string __image_src: ""
    property string __drink_text_kor: ""
    property string __drink_text_eng: ""
    property string __drink_text_description: ""

    id: drinkItemOption
    width: 304
    height: 420

    Image{
        id: baseImage
        width: parent.width
        height: parent.width
        //anchors.fill: parent
        source: __image_src
        visible: true

        Text {
            id: drinkNameKor
            x: 0
            y: 344
            width: parent.width
            height: 35
            color: "#5b5e66"
            font.family: fontBold.name
            text: qsTr(__drink_text_description)
            anchors.horizontalCenterOffset: 0
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            font.pixelSize: 38
            visible: true
        }
//        Text {
//            id: drinkNameEng
//            x: 0
//            y: 366
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
//            font.pixelSize: 33
//            visible: true
//        }
    }
}
