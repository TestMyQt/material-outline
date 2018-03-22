import QtQuick 2.9
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.0

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

        MouseArea {
            anchors.fill: parent

            onClicked: {
                cookieText.text = clickedType + "s clicked: " + click;
                click++;
            }
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
}
