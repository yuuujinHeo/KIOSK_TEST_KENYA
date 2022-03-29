import QtQuick 2.10
import QtQuick.Controls 2.3
import io.qt.Backend 1.0
import io.qt.OrderManage 1.0
import QtQuick.Layouts 1.0
//import QtMultimedia 5.0


Page {

    id: page3
    width: 1080
    height: 1920

    property bool mBackClicked : true
    property bool mSelectClicked : true

    property int mOptionIce: 0
    property int mOptionBoba: 1
    property int mOptionSyrup: 2

    property int mDrinkType: 0

    property string menuKor: ""
    property int menuPrice: 0

    property int margin: 15

    property bool isBobaSoldout: false
    property bool isSyrupSoldout: false


    function setDrink(name_kor, name_eng, image_src, price, type){
        drinkInfo.__drink_text_kor = name_kor;
        drinkInfo.__drink_text_eng = name_eng;
        drinkInfo.__image_src = image_src;


        menuKor = name_kor;
        menuPrice = price;
        mDrinkType = type;

        updateSoldout();
        mOptionIce = 0;
        if(mDrinkType==0) mOptionBoba = 0;
        else    mOptionBoba = 1;
        //        mOptionBoba = (mDrinkType)?0:1;
        mOptionSyrup = (isSyrupSoldout)?-1:2;

        updateOption();
    }


    function updateSoldout(){
        isSyrupSoldout = backend.getOptionSoldOut("SYRUP");
        //        console.log(isBobaSoldout);
        //        console.log(isSyrupSoldout);
    }

    function updateOption(){



        //            if(mDrinkType == 1){
        //            //Tea
        //                rectBoba.visible = true;
        //                image_select_boba_no.visible = false;
        //                image_select_boba_yes.visible = false;
        //                textboba1.visible = false;
        //                textboba2.visible = false;
        //                textboba3.visible = false;
        //                textboba4.visible = false;
        //                textboba5.visible = false;
        //                image_soldout_boba.visible = false;
        //                mousearea_boba_no.enabled = false;
        //                mousearea_boba_yes.enabled = false;

        //                mOptionBoba = 1;
        //            }else{
        //            rectBoba.visible = false;
        //            textboba1.visible = true;
        //            textboba2.visible = true;
        //            textboba3.visible = true;
        //            textboba4.visible = true;
        //            textboba5.visible = true;
        //            mousearea_boba_no.enabled = true;
        //            mousearea_boba_yes.enabled = true;

        //            if(mOptionBoba == 0){
        //                image_select_boba_no.visible = true;
        //                image_select_boba_yes.visible = false;
        //                image_soldout_boba.visible = false;
        //            }else if(mOptionBoba == 1){
        //                image_select_boba_no.visible = false;
        //                image_select_boba_yes.visible = true;
        //                image_soldout_boba.visible = false;
        //            }else{//soldout
        //                image_select_boba_no.visible = false;
        //                image_select_boba_yes.visible = false;
        //                image_soldout_boba.visible = true;
        //            }
        ////            }

        if(drinkInfo.__drink_text_kor == "옛날커피"){
            mixcoffee_rect.visible = true;
            mixcoffee_text.visible = true;
            mOptionSyrup = 0;
        }else{
            mixcoffee_rect.visible = false;
            mixcoffee_text.visible = false;
        }

        if(mOptionSyrup == 0){
            image_select_syrup_no.visible = true;
            image_select_syrup_normal.visible = false;
            image_select_syrup_many.visible = false;
            image_soldout_syrup.visible = false;
        }else if(mOptionSyrup == 1){
            image_select_syrup_no.visible = false;
            image_select_syrup_normal.visible = false;
            image_select_syrup_many.visible = false;
            image_soldout_syrup.visible = false;
        }else if(mOptionSyrup == 2){
            image_select_syrup_no.visible = false;
            image_select_syrup_normal.visible = true;
            image_select_syrup_many.visible = false;
            image_soldout_syrup.visible = false;
        }else if(mOptionSyrup == 3){
            image_select_syrup_no.visible = false;
            image_select_syrup_normal.visible = false;
            image_select_syrup_many.visible = true;
            image_soldout_syrup.visible = false;
        }else{//soldout
            image_select_syrup_no.visible = false;
            image_select_syrup_normal.visible = false;
            image_select_syrup_many.visible = false;
            image_soldout_syrup.visible = true;
        }
    }

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
                text: "옵션 선택"
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 65
            }
        }

        DrinkItemOption{
            id: drinkInfo
            x: 389
            y: 545
        }

        Text {
            x: 241
            y: 1003
            width: 600
            height: 76
            color: "#5b5e66"
            text: "원하시는 메뉴의 옵션을 골라주세요!"
            lineHeight: 1.2
            font.family: fontLight.name
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 30
        }

        Image{
            id: imageOption
            x: 147
            y: 1085
            width: 788
            height: 440
            source: "image/option_page/option.png"
            fillMode: Image.PreserveAspectFit

            Text {
                x: 0
                y: 182
                width: 204
                height: 76
                color: "#5b5e66"
                font.pixelSize: 30
                text: "시럽\n(Syrup)"
                lineHeight: 1.2
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }


            Text {
                x: 456
                y: 225
                width: 70
                height: 40
                color: "#5b5e66"
                text: "보 통"
                font.family: fontLight.name
                verticalAlignment: Text.AlignVCenter
                lineHeight: 1.2
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }

            Text {
                x: 656
                y: 225
                width: 70
                height: 40
                color: "#5b5e66"
                text: "많 음"
                font.family: fontLight.name
                verticalAlignment: Text.AlignVCenter
                lineHeight: 1.2
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }

            Text {
                x: 263
                y: 225
                width: 70
                height: 40
                color: "#5b5e66"
                text: "없 음"
                font.family: fontLight.name
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                lineHeight: 1.2
                font.pixelSize: 22
            }


            // ice option ----------------------------------------

            // boba option ----------------------------------------
            Image {
                id: image_soldout_syrup
                x: 204
                y: 147
                width: 584
                height: 146
                source: "image/option_page/option_soldout.png"
                fillMode: Image.PreserveAspectFit
            }


            // syrup option ----------------------------------------

            Image {
                id: image_select_syrup_no
                x: 266
                y: 182
                width: 63
                height: 37
                source: "image/option_page/option_select.png"
                fillMode: Image.PreserveAspectFit
            }
            MouseArea{
                x: image_select_syrup_no.x-margin
                y: image_select_syrup_no.y-margin
                width: 63+margin*2
                height: 37+margin*2
                //                anchors.fill: image_select_syrup_no
                onClicked: {
                    updateSoldout();
                    mOptionSyrup = isSyrupSoldout?-1:0;
                    updateOption();
                }
            }
            Image {
                id: image_select_syrup_normal
                x: 456
                y: 185
                width: 70
                height: 34
                source: "image/option_page/option_select.png"
                fillMode: Image.PreserveAspectFit
            }
            MouseArea{
                x: image_select_syrup_normal.x-margin
                y: image_select_syrup_normal.y-margin
                width: 63+margin*2
                height: 37+margin*2
                //                anchors.fill: image_select_syrup_normal
                onClicked: {
                    updateSoldout();
                    mOptionSyrup = isSyrupSoldout?-1:2;
                    updateOption();
                }
            }
            Image {
                id: image_select_syrup_many
                x: 659
                y: 182
                width: 63
                height: 37
                source: "image/option_page/option_select.png"
                fillMode: Image.PreserveAspectFit
            }
            Rectangle {
                id: mixcoffee_rect
                x: 210
                y: 147
                width: 584
                height: 146
                color: "#ffffff"

                Text {
                    id: mixcoffee_text
                    x: 72
                    y: 61
                    text: qsTr("옛날커피는 시럽을 선택할 수 없습니다.")
                    font.pixelSize: 25
                }
            }

            MouseArea{
                x: image_select_syrup_many.x-margin
                y: image_select_syrup_many.y-margin
                width: 63+margin*2
                height: 37+margin*2
                //                anchors.fill: image_select_syrup_many
                onClicked: {
                    updateSoldout();
                    mOptionSyrup = isSyrupSoldout?-1:3;
                    updateOption();
                }
            }

        }





        Rectangle{
            id: rectBack
            x: 0
            y: 1686
            width: parent.width/2
            height: 234
            color: "#3b3a51"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                text: "    뒤로가기"
                font.pixelSize: 60
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                anchors.fill: parent
                onReleased: {
                    if(!mBackClicked){
                        rectBack.opacity = 1.0
                        mBackClicked = true;
                        swipeView.currentIndex = 1  // menu page
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(mBackClicked){
                        rectBack.opacity = 0.7
                        mBackClicked = false;
                    }
                }

                Image {
                    id: image
                    x: 98
                    y: 83
                    width: 62
                    height: 69
                    source: "image/common/back.png"
                    fillMode: Image.PreserveAspectFit
                }
            }
        }


        Rectangle{
            id: rectSelect
            x: parent.width/2
            y: 1686
            width: parent.width/2
            height: 234
            color: "#7647c0"

            Text {
                anchors.fill: parent
                color: "#ffffff"
                text: "    선택 완료"
                font.pixelSize: 60
                font.family: fontBold.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                anchors.fill: parent
                onReleased: {
                    if(!mSelectClicked){
                        console.log(menuKor)
                        orderManage.addOrderToCart(menuKor, mOptionIce, mOptionBoba, mOptionSyrup, menuPrice)
                        rectSelect.opacity = 1.0
                        mSelectClicked = true;
                        swipeView.currentIndex = 3  // cart page
                        clickSound.play()
                    }
                }
                onPressed:{
                    if(mSelectClicked){
                        rectSelect.opacity = 0.7
                        mSelectClicked = false;
                    }
                }

                Image {
                    id: image1
                    x: 84
                    y: 81
                    width: 71
                    height: 73
                    source: "image/common/check.png"
                    fillMode: Image.PreserveAspectFit
                }
            }
        }

    }
    // ------------------------------------------------

}
