import QtQuick 2.10
import QtQuick.Controls 2.3
import io.qt.Backend 1.0
import io.qt.OrderManage 1.0
import QtQuick.Layouts 1.0
//import QtMultimedia 5.0


Page {

    id: page7
    width: 1080
    height: 1920


    // Background -------------------------------------
    Rectangle{
        id: rectBackground
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        color: "#f3f3f3"

        Image {
            id: imageLogo
            x: 446
            y: 92
            width: 188
            height: 221
            source: "image/order_page/logo_boba.png"
            fillMode: Image.PreserveAspectFit
        }



        Rectangle {
            x: 104
            y: 358
            width: 874
            height: 129
            color: "#201547"
            Text {
                anchors.fill: parent
                color: "#ffffff"
                text: "결제 오류"
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 65
            }
        }

        Text {
            x: 200
            y: 623
            width: 699
            height: 76
            color: "#5b5e66"
            text: "카드의 승인이 완료되지 않았습니다.\n다른 카드로 다시 시도해 주시기 바랍니다."
            lineHeight: 1.2
            font.family: fontLight.name
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 36
        }

        Image{
            id: imageCard
            x: 343
            y: 872
            width: 389
            height: 241
            fillMode: Image.PreserveAspectFit
            source: "image/credit_page/card_insert.png"
        }
        Image {
            id: image1
            x: 679
            y: 809
            width: 103
            height: 103
            source: "image/cart_page/menu_remove.png"
            fillMode: Image.PreserveAspectFit
        }
        Image {
            id: image2
            x: 679
            y: 809
            width: 103
            height: 103
            source: "image/cart_page/menu_remove.png"
            fillMode: Image.PreserveAspectFit
        }


        Rectangle{
            x: 0
            y: 1686
            width: parent.width
            height: 234
            color: "#3b3a51"
        }

        Text {
            x: 200
            y: 1230
            width: 699
            height: 76
            color: "#5b5e66"
            text: globalCreditErrorCode
            font.family: fontLight.name
            verticalAlignment: Text.AlignVCenter
            lineHeight: 1.2
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 36
        }


    }
    // ------------------------------------------------
}
