import QtQuick 2.10
import QtQuick.Controls 2.3
import io.qt.Backend 1.0
import io.qt.OrderManage 1.0
import QtQuick.Layouts 1.0
//import QtMultimedia 5.0


Page {

    id: page6
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
                text: "주문완료"
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
            text: "카드를 리더기에서 뽑아주세요.\n음료가 완료될 때까지 잠시만 기다려주세요."
            lineHeight: 1.2
            font.family: fontLight.name
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 36
        }

        Text {
            x: 164
            y: 807
            width: 752
            height: 132
            color: "#9957f7"
            text: "영수증의 바코드가 있어야\n음료 픽업이 가능합니다."
            font.family: fontBold.name
            verticalAlignment: Text.AlignVCenter
            lineHeight: 1.2
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 46
        }

        Rectangle{
            x: 190
            y: 945
            width: 700
            height: 85
            color: "#9957f7"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                text: "\" 영수증을 꼭 소지해주세요! \""
                font.family: fontBold.name
                verticalAlignment: Text.AlignVCenter
                lineHeight: 1.2
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 50
            }

        }

        Image{
            id: imageComplete
            x: 308
            y: 1134
            width: 463
            height: 289
            fillMode: Image.PreserveAspectFit
            source: "image/complete_page/complete.png"
        }


        Rectangle{
            x: 0
            y: 1686
            width: parent.width
            height: 234
            color: "#3b3a51"         
        }
    }
    // ------------------------------------------------
}
