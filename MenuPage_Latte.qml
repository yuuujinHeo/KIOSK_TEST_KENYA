import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
import io.qt.Backend 1.0
import QtQuick.Shapes 1.0


Page {
    id: menuPage_Latte
    width: 960
    height: 1200
    background: Rectangle{
        color:"transparent"
    }

    property int height_gap: 280;
    property int line_start_y: 160;
    property int item_start_y: 220;


    Component.onCompleted: {
        item1.__drink_text1 = backend.getMenuInfoKor("콜드브루 라떼", 0);
        item1.__drink_price = backend.getMenuInfoPrice("콜드브루 라떼", 0);
        item1.__image_src = "file:/" + globalAppDir + "/../" + backend.getMenuInfoImage("콜드브루 라떼", 0);

        item2.__drink_text1 = backend.getMenuInfoKor("콜드브루 라떼", 1);
        item2.__drink_price = backend.getMenuInfoPrice("콜드브루 라떼", 1);
        item2.__image_src = "file:/" + globalAppDir + "/../" + backend.getMenuInfoImage("콜드브루 라떼", 1);

        item3.__drink_text1 = backend.getMenuInfoKor("콜드브루 라떼", 2);
        item3.__drink_price = backend.getMenuInfoPrice("콜드브루 라떼", 2);
        item3.__image_src = "file:/" + globalAppDir + "/../" + backend.getMenuInfoImage("콜드브루 라떼", 2);
    }

    function checkSoldout(){
        item1.checkSoldout();
        item2.checkSoldout();
        item3.checkSoldout();
    }


    Item {
        x: 0
        y: 50
        width: 960
        height: 120
        Text {
            x: 0
            y: 0
            width: 960
            height: 40
            color: "#603129"
            font.pixelSize: 40
            text: "콜드브루 라떼는 Ice만 가능합니다."
            font.family: fontBold.name
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Shape {
        width: 20
        ShapePath {
            strokeColor: "#6d6d6d"
            strokeWidth: 1
            strokeStyle: ShapePath.DashLine
            dashPattern: [2,3]
            startX: 0
            startY: line_start_y
            PathLine { x: parent.width; y: line_start_y }
        }
    }
    Shape {
        width: 20
        ShapePath {
            strokeColor: "#6d6d6d"
            strokeWidth: 1
            strokeStyle: ShapePath.DashLine
            dashPattern: [2,3]
            startX: 0
            startY: line_start_y+height_gap*1
            PathLine { x: parent.width; y: line_start_y+height_gap*1 }
        }
    }
    Shape {
        width: 20
        ShapePath {
            strokeColor: "#6d6d6d"
            strokeWidth: 1
            strokeStyle: ShapePath.DashLine
            dashPattern: [2,3]
            startX: 0
            startY: line_start_y+height_gap*2
            PathLine { x: parent.width; y: line_start_y+height_gap*2 }
        }
    }
    Shape {
        width: 20
        ShapePath {
            strokeColor: "#6d6d6d"
            strokeWidth: 1
            strokeStyle: ShapePath.DashLine
            dashPattern: [2,3]
            startX: 0
            startY: line_start_y+height_gap*3
            PathLine { x: parent.width; y: line_start_y+height_gap*3 }
        }
    }


    Item{
        x: 20
        y: item_start_y

        Text {
            x: 0
            y: 0
            width: 500
            height: 40
            color: "#603129"
            font.pixelSize: 40
            text: "에티오피아 예가체프"
            font.family: fontBold.name
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
        Text {
            x: 0
            y: 50
            width: 500
            height: 18
            color: "#603129"
            font.pixelSize: 18
            text: "과즙에 비유되는 상큼한 신맛과 꽃 향기로 유명합니다."
            font.family: fontBold.name
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
        Image {
            x: 0
            y: 80
            width: 480
            height: 80
            source: "image/order_page/menu_taste1.png"
            fillMode: Image.PreserveAspectFit
        }

        GridLayout {
            x: 520
            y: -20
            width: 400
            height: 240
            clip: true
            rows: 1
            columns: 1

            DrinkItem{
                id: item1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }
        }
    }


    Item{
        x: 20
        y: item_start_y+height_gap*1

        Text {
            x: 0
            y: 0
            width: 500
            height: 40
            color: "#603129"
            font.pixelSize: 40
            text: "콜롬비아 수프리모"
            font.family: fontBold.name
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
        Text {
            x: 0
            y: 50
            width: 500
            height: 18
            color: "#603129"
            font.pixelSize: 18
            text: "견과류의 구수한 맛과 깔끔한 산미로 마일드커피의 대명사입니다."
            font.family: fontBold.name
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
        Image {
            x: 0
            y: 80
            width: 480
            height: 80
            source: "image/order_page/menu_taste2.png"
            fillMode: Image.PreserveAspectFit
        }

        GridLayout {
            x: 520
            y: -20
            width: 400
            height: 240
            clip: true
            rows: 1
            columns: 1

            DrinkItem{
                id: item2
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }
        }
    }


    Item{
        x: 20
        y: item_start_y+height_gap*2

        Text {
            x: 0
            y: 0
            width: 500
            height: 40
            color: "#603129"
            font.pixelSize: 40
            text: "케냐 AA"
            font.family: fontBold.name
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
        Text {
            x: 0
            y: 50
            width: 500
            height: 18
            color: "#603129"
            font.pixelSize: 18
            text: "묵직한 바디감과 열대과일의 달콤. 신맛으로 뛰어난 밸런스를 갖습니다."
            font.family: fontBold.name
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
        Image {
            x: 0
            y: 80
            width: 480
            height: 80
            source: "image/order_page/menu_taste3.png"
            fillMode: Image.PreserveAspectFit
        }

        GridLayout {
            x: 520
            y: -20
            width: 400
            height: 240
            clip: true
            rows: 1
            columns: 1

            DrinkItem{
                id: item3
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }
        }
    }
}
