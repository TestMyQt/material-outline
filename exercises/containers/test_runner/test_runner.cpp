#include <QTest>
#include <QList>
#include <QDebug>
#include "test_runner.h"
#include "useful.h"

#define POINT(test_name, point) qInfo("TMC:"#test_name"."#point)

test_runner::test_runner(QObject *parent) : QObject(parent)
{

}

void test_runner::list_modified_correctly() {
    useful test_useful;
    POINT(list_modified_correctly, 1.1);

    QList<int> list;
    QList<int> correctList;
    for (int i = 0; i < 1000; i++) {
        list.append(i);
        if (i % 5 == 0) {
            correctList.append(i*3);
        } else {
            correctList.append(i);
        }
    }
    list = test_useful.listPractise(list);
    for (int i = 0; i < 1000; i++) {
        QVERIFY(list[i] == correctList[i]);
    }
}

void test_runner::correct_heights_returned() {
    useful test_useful;
    POINT(correct_heights_returned, 1.2);
    QMap<QString, float> map;
    map.insert("Mark", 1.82);
    map.insert("Anton", 1.90);
    map.insert("Liisa", 1.59);
    map.insert("Anna", 1.64);
    QList<float> correctHeights;
    correctHeights.append(1.64);
    correctHeights.append(1.90);
    QList<float> returned = test_useful.heights(map);
    QVERIFY(correctHeights.size() == returned.size());
    for (int i = 0; i < returned.size(); i++)
        QVERIFY(returned[i] == correctHeights[i]);
}

void test_runner::correct_names_returned() {
    useful test_useful;
    POINT(correct_names_returned, 1.3);
    QMap<QString, float> map;
    map.insert("Mark", 1.82);
    map.insert("Anton", 1.90);
    map.insert("Liisa", 1.59);
    map.insert("Anna", 1.64);
    QList<QString> correctNames;
    correctNames.append("Anton");
    correctNames.append("Mark");
    QList<QString> returned = test_useful.names(map);
    QVERIFY(correctNames.size() == returned.size());
    for (int i = 0; i < returned.size(); i++) {
        QVERIFY(returned[i] == correctNames[i]);
    }
}
