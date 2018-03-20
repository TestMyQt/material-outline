import QtQuick 2.0
import QtTest 1.0
import QtQuick.Window 2.2
import "../src/" 1.00 as App

TestCase {
    name: "tst_quick"

    App.HelloWorld {
        id: helloWorld
    }

    function test_world() {
        compare(helloWorld.textThing.text, "Hello World!")
    }
}

//Item {
//    id: root
//    width: 400
//    height: 300

////    HelloWorld {
////        id: testObject
////    }

//    TestCase {
//        name: "Hello tests"
//        id: testCase

//        function initTestCase() {

//        }

//        function test_hello() {
//            var item = createTemporaryQmlObject("import QtQuick 2.0; import \"" + Qt.resolvedUrl("../src") + "\"; HelloWorld {}", testCase)
//            console.log(item.text1)
//            compare(item, "Hello World!")
//        }
//    }
//}
