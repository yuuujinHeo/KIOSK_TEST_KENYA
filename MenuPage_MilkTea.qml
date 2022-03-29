import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
import io.qt.Backend 1.0
import QtQuick.Shapes 1.0


Page {
    id: menuPage_MilkTea
    width: 914
    height: 344
    background: Rectangle{
        color:"transparent"
    }

    Component.onCompleted: {
        item1.__drink_text_kor = backend.getMenuInfoKor("밀크티", 0);
        item1.__drink_text_eng = backend.getMenuInfoEng("밀크티", 0);
        item1.__drink_price = backend.getMenuInfoPrice("밀크티", 0);
        item1.__drink_description = backend.getMenuInfoDescription("밀크티", 0);
        item1.__image_src = "file:" + backend.getMenuInfoImage("밀크티", 0);
        item1.__drink_type = 1;

        item2.__drink_text_kor = backend.getMenuInfoKor("밀크티", 1);
        item2.__drink_text_eng = backend.getMenuInfoEng("밀크티", 1);
        item2.__drink_price = backend.getMenuInfoPrice("밀크티", 1);
        item2.__drink_description = backend.getMenuInfoDescription("밀크티", 1);
        item2.__image_src = "file:" + backend.getMenuInfoImage("밀크티", 1);
        item2.__drink_type = 1;

        item3.__drink_text_kor = backend.getMenuInfoKor("밀크티", 3);
        item3.__drink_text_eng = backend.getMenuInfoEng("밀크티", 3);
        item3.__drink_price = backend.getMenuInfoPrice("밀크티", 3);
        item3.__drink_description = backend.getMenuInfoDescription("밀크티", 3);
        item3.__image_src = "file:" + backend.getMenuInfoImage("밀크티", 3);
        item3.__drink_type = 1;
    }

    function checkSoldout(){
        item1.checkSoldout();
        item2.checkSoldout();
        item3.checkSoldout();
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
        }
    }

}
