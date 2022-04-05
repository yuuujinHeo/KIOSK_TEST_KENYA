import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
import io.qt.Backend 1.0
import QtQuick.Shapes 1.0


Page {
    id: menuPage_Tea
    width: 914
    height: 1200

    background: Rectangle{
        color:"transparent"
    }

    Component.onCompleted: {
        var max_col = 3;
        for(var i=0; i<menu.getMenuNum("아이스커피"); i++){
            listTea.model.append({"menu_name":menu.getMenuName("아이스커피",i),"menu_image":menu.getMenuImage("아이스커피",i)})
        }
    }

    Component{
        id: contactDelegateTea
        DrinkItem{
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            __drink_text_kor: menu_name
            __image_src: "file:" + menu_image
        }
    }

    Item{
        x: 40
        y: 40

        GridView {
            id: listTea
            x: 0
            y: 0
            width: 914
            height: 1200

            cellWidth: 300
            cellHeight: 400
            clip: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter


            model: ListModel{}
            delegate: contactDelegateTea

        }
    }

}
