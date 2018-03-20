#include <QTest>
#include <QDebug>
#include <iostream>
#include "test_runner.h"

#define POINT(test_name, point) qInfo("TMC:"#test_name"."#point)

test_runner::test_runner(QObject *parent) : QObject(parent)
{

}

void test_runner::hello_test()
{

}
