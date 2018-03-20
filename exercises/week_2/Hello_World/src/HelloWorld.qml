import QtQuick 2.0
import QtTest 1.0

Item {
    id: world
    width: 400
    height: 200
    Text {
        id: text1
        x: 38
        y: 41
        width: 325
        height: 99
        text: "Hello World!"
        font.pixelSize: 55
        TestCase {
            function test_hello() {
                compare(text1.text, "Hello World!")
            }
        }
    }

}
