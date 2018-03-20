import QtQuick 2.0
import QtTest 1.0
import QtQuick.Window 2.2
import "../src/" 1.00 as App

TestCase {
    name: "tst_quick"

    App.HelloWorld {
        id: helloWorld
        textThing: "Don't Panic!"
    }

    function test_world() {
        compare(helloWorld.textThing, "Don't Panic!")
    }
}
