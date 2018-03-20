import QtQuick 2.0
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.0

Item {
    id: world
    width: 400
    height: 200

    property string textThing

    Text {
        id: text1
        x: 38
        y: 41
        width: 325
        height: 99
        color: "blue"
        text: textThing
        font.pixelSize: 55
    }
}
