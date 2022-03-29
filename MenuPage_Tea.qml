import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
import io.qt.Backend 1.0
import QtQuick.Shapes 1.0


Page {
    id: menuPage_Tea
    width: 914
    height: 344
    background: Rectangle{
        color:"transparent"
    }

    Component.onCompleted: {
        item1.__drink_text_kor = backend.getMenuInfoKor("티", 4);
        item1.__drink_text_eng = backend.getMenuInfoEng("티", 4);
        item1.__drink_price = backend.getMenuInfoPrice("티", 4);
        item1.__drink_description = backend.getMenuInfoDescription("티", 4);
        item1.__image_src = "file:" + backend.getMenuInfoImage("티", 4);
        item1.__drink_type = 0;

        item2.__drink_text_kor = backend.getMenuInfoKor("티", 0);
        item2.__drink_text_eng = backend.getMenuInfoEng("티", 0);
        item2.__drink_price = backend.getMenuInfoPrice("티", 0);
        item2.__drink_description = backend.getMenuInfoDescription("티", 0);
        item2.__image_src = "file:" + backend.getMenuInfoImage("티", 0);
        item2.__drink_type = 0;

        item3.__drink_text_kor = backend.getMenuInfoKor("티", 1);
        item3.__drink_text_eng = backend.getMenuInfoEng("티", 1);
        item3.__drink_price = backend.getMenuInfoPrice("티", 1);
        item3.__drink_description = backend.getMenuInfoDescription("티", 1);
        item3.__image_src = "file:" + backend.getMenuInfoImage("티", 1);
        item3.__drink_type = 0;

        item4.__drink_text_kor = backend.getMenuInfoKor("티", 3);
        item4.__drink_text_eng = backend.getMenuInfoEng("티", 3);
        item4.__drink_price = backend.getMenuInfoPrice("티", 3);
        item4.__drink_description = backend.getMenuInfoDescription("티", 3);
        item4.__image_src = "file:" + backend.getMenuInfoImage("티", 3);
        item4.__drink_type = 0;
    }

    function checkSoldout(){
        item1.checkSoldout();
        item2.checkSoldout();
        item3.checkSoldout();
        item4.checkSoldout();
    }

    Item{
        x: 0
        y: 0

        GridLayout {
            x: 0
            y: 0
            width: 914
            height: 344
            clip: true
            rows: 1
            columns: 4

            DrinkItem{
                id: item1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            DrinkItem{
                id: item2
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            DrinkItem{
                id: item3
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            DrinkItem{
                id: item4
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }
        }
    }

}
