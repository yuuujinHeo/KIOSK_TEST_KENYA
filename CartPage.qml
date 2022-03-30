import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
import io.qt.Backend 1.0
import QtQuick.Shapes 1.0


Page {
    id: cartPage
    width: 1033
    height: 400
    background: Rectangle{
        color:"transparent"
    }

    function reloadCart(){
        listCart.model.clear()

        for(var i = 0; i < orderManage.getCartItemSize(); i++){//리스트의 개수만큼 for문을 돌린다.
            listCart.model.append({"menu_name": orderManage.getCartItemName(i),"menu_image": menu.getMenuImagename(orderManage.getCartItemName(i))});
            console.log(orderManage.getCartItemName(i));
            console.log(menu.getMenuImagename(orderManage.getCartItemName(i)));
        }
    }
    Component {//리스트 뷰의 틀을 만든다.
        id: contactDelegateCart
        CartItem{
            __drink_text_kor: menu_name
            __image_src: "file:" + menu_image
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }

    Item{
        x: 0
        y: 0
        width:parent.width
        height:400


        ListView {
            id: listCart
            spacing: 20
            anchors.fill: parent
            clip: true

            orientation: ListView.Horizontal// listView.horizontalCenter

            model: ListModel {}
            delegate: contactDelegateCart
        }
    }


}
