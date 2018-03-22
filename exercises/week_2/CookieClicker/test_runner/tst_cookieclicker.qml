import QtQuick 2.6
import QtTest 1.0
import QtQuick.Window 2.2

Item {
    id: container
    width: 400
    height: 400

    TestCase {
        id: cookieTest
        name: "tst_cookieClicker"
        when: windowShown

        SignalSpy {
            id: spy
        }

        function test_cookie_click() {
            var component = Qt.createComponent("CookieClickerTest.qml")
            compare(component.status, Component.Ready)
            var cookie = component.createObject(container);

            verify(cookie !== null, "cookie created is null")
            waitForRendering(cookie)

            cookie.forceActiveFocus()

            spy.target = cookie
            spy.signalName = "clickChanged"

            for (var prop in cookie)
                console.log(prop)

            compare(spy.count, 0)
            mouseClick(cookie, 100, 100, Qt.LeftButton)
            compare(spy.count, 1)
            compare(cookie.click, 2)

            cookie.destroy()
        }

        function test_cookie_text() {
            var component = Qt.createComponent("../src/CookieClicker.qml")
            compare(component.status, Component.Ready)
            var cookie = component.createObject(container);

            verify(cookie !== null, "cookie created is null")
            waitForRendering(cookie)

            cookie.forceActiveFocus()

            mouseClick(cookie, 100, 100, Qt.LeftButton)
            compare(cookie.click, 2)
            compare(cookie.statusText.text, "Cookies clicked: 2")

            cookie.destroy()
        }
    }

}
