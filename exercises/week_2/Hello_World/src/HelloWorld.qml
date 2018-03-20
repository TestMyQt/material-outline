import QtQuick 2.0
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.0

Item {
    id: world
    width: 400
    height: 200

    property string textThing
    property alias rectThing : loader.sourceComponent

    Text {
        id: text1
        x: 38
        y: 41
        width: 325
        height: 99
        color: "blue"
        font.pixelSize: 55
    }

    Loader { id: loader }

    MouseArea {
        anchors.fill: parent
        onClicked: pew()
    }

    Rectangle {

    }
    property string sc: 'import QtQuick 2.0; Rectangle {width: 20; height: 20; color: "red"; Component.onCompleted: {x = Math.random() * parent.width; y = Math.random() * parent.height;}}'

    function pew() {
        Qt.createQmlObject(sc, world, 'obj');
    }

}
