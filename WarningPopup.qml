import QtQuick 2.10
import QtQuick.Controls 2.3
import io.qt.Backend 1.0
import QtQuick.Layouts 1.0

//Rectangle {
Popup{
    id: warningPopupDialog

    property int closeTimeout : 4;

    property string warningRobotConnection : "로봇이 연결되지 않았습니다.\n관리자에게 문의하세요."
    property string warningCartEmpty : "장바구니가 비어있습니다."
    property string warningCartFull : "장바구니가 가득 찼습니다."

    width: 1080     //parent.width
    height: 1920    //parent.height
    x: 0    //(parent.width - width) / 2
    y: 0    //(parent.height - height) / 2

    // popup 만들시 기본적으로 설정되는 각 영역들을 모두 없앰
    leftPadding: 0
    rightPadding: 0
    topPadding: 0
    bottomPadding: 0

    //dim:true
    background: Rectangle{
        color:"#000000"
        opacity: 0.5
    }
    closePolicy: Popup.CloseOnPressOutside //팝업 영역이 아닌곳을 클릭하면 팝업이 닫힘



    function setType(msgtype){
        if(msgtype === 0){
            textWarning.text = warningRobotConnection
        }else if(msgtype === 1){
            textWarning.text = warningCartEmpty
        }else if(msgtype === 2){
            textWarning.text = warningCartFull
        }
    }




    Timer {
        id: closeTimer
        interval: 200
        repeat: true
        running: true
        triggeredOnStart: true
        onTriggered: {
//            console.log(backend.getRobotActionState())
            if(closeTimeout-- < 0){
                warningPopupDialog.close()
            }
        }
    }

    Rectangle {
        id: rectangle
        x: 190
        y: 860
        width: 700
        height: 200
        color: "#ffffff"
        radius: 40

        Text {
            id: textWarning
            x: 50
            y: 62
            width: 600
            height: 76
            color: "#5b5e66"
            font.pixelSize: 40
            text: "장바구니가 비어있습니다."
            lineHeight: 1.2
            font.family: fontBold.name
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

}
