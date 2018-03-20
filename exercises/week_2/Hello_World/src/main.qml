import QtQuick 2.0
import QtQuick.Window 2.2

Window {
    id: window
    width: 400
    visible: true
    height: 220
    title: qsTr("Hello World")

    HelloWorld {
        rectThing: Rectangle {
            color: "red"
            y: 40; width: 40; height: 40
        }
        textThing: "wat"
        width: 350
        height: 200
        anchors.centerIn: parent
    }

}
