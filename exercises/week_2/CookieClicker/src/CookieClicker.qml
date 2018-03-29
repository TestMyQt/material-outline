import QtQuick 2.9
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.0
import QtGraphicalEffects 1.0

Item {
    id: cookieClicker
    anchors.fill: parent

    property int click: 1
    property string welcome : "Generic welcome!"
    property alias status: cookieText
    property string clickedType : "Cookie"

    Image {
        id: image
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "qrc:/cookie.jpg"

        state: mouse.pressedButtons & Qt.LeftButton ? 0.9 : 1.0

        MouseArea {
            id: mouse
            anchors.fill: parent
            onClicked: {
                animateScale.start();
                cookieText.text = clickedType + "s clicked: " + click;
                click++;
                if (click > 10 && cookieClicker.state != "tastycookie") {
                    cookieClicker.state = "tastycookie";
                    clickedType = "Tasty " + clickedType;
                }
            }
        }
    }

    NumberAnimation {
        id: animateScale
        target: image
        duration: 200
        properties: "scale"
        from: 0.6
        to: 0.99
        easing {
            type: Easing.OutInBounce
            overshoot: 50;
        }
   }

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        id: cookieText
        x: 0
        y: 0
        text: welcome
        color: "brown"
        font.pixelSize: 30
    }

    states: [
        State {
            name: "tastycookie"

            PropertyChanges {
                target: animateScale
                duration: 50
                alwaysRunToEnd: true
            }

        }
    ]
}
