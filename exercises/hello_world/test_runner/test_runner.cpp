#include <QTest>
#include "test_runner.h"
#include "useful.h"

#define POINT(test_name, point) qInfo("TMC:"#test_name"."#point)

test_runner::test_runner(QObject *parent) : QObject(parent)
{

}

void test_runner::hello_worlds() {
    QTest::ignoreMessage(QtDebugMsg, "Hello world");
    QTest::ignoreMessage(QtWarningMsg, "Don't panic!");

    useful test_useful;

    POINT(hello_worlds, 1);
    test_useful.hello();
}
