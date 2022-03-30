import QtQuick 2.10
import QtQuick.Controls 2.3
import io.qt.Backend 1.0
import io.qt.Menu 1.0
import io.qt.OrderManage 1.0
import QtMultimedia 5.0


ApplicationWindow {

    property int globalCreditResult: 0;
    property string globalCreditErrorCode: "";
    property int globalCreditSwipe: 0;
    property int globalCreditApproving: 0;

    property var globalSoundVolume: 0.2;
    property int globalOrderPrice: 0;



    property bool globalIsTestMode: false


    property string globalAppDir: ""


    id: mainwindow
    visible: true
    width: 1080
    height: 1920
    title: qsTr("Rainbow-Robotics::Mixx")
    visibility: "FullScreen"



    Component.onCompleted: {
        globalAppDir = applicationDirPath;
    }

    FontLoader {
        id: fontBold
        source: "font/lotteDreamBold.ttf"
    }
    FontLoader {
        id: fontLight
        source: "font/lotteDreamLight.ttf"
    }


    function clearMenuPage(){
        orderManage.clearCart()
//        menuPage.clearPage()
    }

    function creditNotiApproving(){
        console.log("MainQML --------------> creditNotiApproving")
        creditPage.creditNotiApproving();
        //globalCreditApproving = 1
    }
    function creditNotiIdle(){
//        console.log("--------------creditNotiIdle")
        globalCreditSwipe = 0
        globalCreditApproving = 0
    }
    function creditNotiMSRSwipe(){
        console.log("--------------creditNotiMSRSwipe")
        globalCreditSwipe = 1
    }

    function creditNotiSuccess(){
        console.log("MainQML --------------> creditNotiSuccess")
        //globalCreditResult = 1
        //menuPage.creditChangePopupPage(1)
        //soundReturn.play()
        swipeView.currentIndex = 5;     // complete page
    }
    function creditNotiFail(error_code){
        console.log("MainQML --------------> creditNotiFail")
        //globalCreditResult = -1
        //menuPage.creditChangePopupPage(1)
        globalCreditErrorCode = error_code
        swipeView.currentIndex = 6;
    }

    function maintenance(){
        console.log("maintenance On")
        swipeView.currentIndex = 0
        frontPage.mPlatformStatus = 1
        frontPage.openNotice()
    }

    function cleaningNotice(){
        console.log("cleaningNotice On")
        swipeView.currentIndex = 0
        frontPage.mPlatformStatus = 2
        frontPage.openNotice()
    }

    function waitNotice(){
        console.log("waitNotice On")
        swipeView.currentIndex = 0
        frontPage.mPlatformStatus = 3
        frontPage.openNotice()
    }

    function restart(){
        console.log("restart")
        frontPage.mPlatformStatus = 4
        frontPage.closeNotice()
    }


    function precleaning(){
        console.log("precleaning On")
        swipeView.currentIndex = 0
        frontPage.mPlatformStatus = 5
        frontPage.openNotice()
    }

    function preoperation(){
        console.log("preoperation On")
        swipeView.currentIndex = 0
        frontPage.mPlatformStatus = 6
        frontPage.openNotice()
    }


    function disconnected(){
        console.log("disconnected")
        swipeView.currentIndex = 0
        frontPage.mPlatformStatus = 7
        frontPage.openNotice()
    }


    function dbReload(){
//        console.log("dbReload")
        frontPage.dbReload()
    }

    function creditTimerStart(){
        creditPage._time = 30;
        console.log("creditTimerStart")
        creditTimer.start();
    }

    function creditTimerStop(){
        console.log("creditTimerStop")
        creditTimer.stop();
    }




    function formatToCurrency(amount){
        return amount.toString().replace(/(\d)(?=(\d{3})+(?!\d))/g, '$1,');
    }


    function cartUpdate(){
        menuPage.cartReload()
    }

    Backend {
        id: backend
    }

    OrderManage {
        id: orderManage;
    }

    Menu {
        id: menu;
    }

    SoundEffect {
        id: clickSound
        //source: "sound/button.wav"
//        source: "sound/click.wav"
        source: "sound/buttonclick.wav"
        loops: 1    //SoundEffect.Infinite
    }


    SoundEffect {
        id: soundCredit
        source: "sound/KIOSK_CREDIT.wav"
        loops: 1
    }
    SoundEffect {
        id: soundReturn
        source: "sound/KIOSK_RETURN.wav"
        loops: 1
    }




    MediaPlayer {
        id: bgmPlayer
        source: "sound/bgm.wav"
        volume: 0.5
        autoPlay: false//true
        loops: SoundEffect.Infinite
    }

//    MouseArea{
    //        anchors.fill: parent
    //        enabled: false
    //        cursorShape: Qt.BlankCursor
    //    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        interactive: false

        Page1{
            id: frontPage
        }

        Page2{
            id: menuPage
        }
    }




    property int curPage : 0
    property int timeCount : 0

    Timer {
        id: userActionTimer
        interval: 1000
        repeat: true
        running: true
        triggeredOnStart: true
        onTriggered: {
            menuPage.checkSoldout();

            if(swipeView.currentIndex == curPage){
                timeCount = timeCount+1;
            }else{
                curPage = swipeView.currentIndex;
                timeCount = 0;
            }

//            if((curPage == 1) || (curPage == 2) || (curPage == 3)){// || (curPage ==4)){
//                if(timeCount > 30){
//                    timeCount = 0;
//                    swipeView.currentIndex = 0;
//                }
//            }else if((curPage == 5) || (curPage == 6)){
//                if(timeCount > 5){//15){
//                    timeCount = 0;
//                    swipeView.currentIndex = 0;
//                }
//            }

        }
    }


    Timer {
        id: fadeInOutTimer
        interval: 200
        repeat: true
        running: true
        triggeredOnStart: true
        onTriggered: {
            if(swipeView.currentIndex == 0){
                globalSoundVolume = globalSoundVolume + 0.04;
                if(globalSoundVolume > 1.0){
                    globalSoundVolume = 1.0;
                }
                bgmPlayer.volume = globalSoundVolume;
            }else if(swipeView.currentIndex == 1){
                globalSoundVolume = globalSoundVolume - 0.04;
                if(globalSoundVolume < 0){
                    globalSoundVolume = 0;
                }
                bgmPlayer.volume = globalSoundVolume;
            }

//            globalIsTestMode = backend.getIsTest();
        }
    }


    Timer{
        id: creditTimer
        interval: 1000
        repeat: true
        onTriggered: {
            console.log("%d",creditPage._time);
            if(creditPage._time > 0){
                creditPage._time--;
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

//        TabButton {
//            text: qsTr("Page 1")
//        }
//        TabButton {
//            text: qsTr("Page 2")
//        }
    }


}
