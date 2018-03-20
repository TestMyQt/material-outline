#include <QTest>
#include <QList>
#include <QDebug>
#include "test_runner.h"
#include "useful.h"

#define POINT(test_name, point) qInfo("TMC:"#test_name"."#point)

test_runner::test_runner(QObject *parent)
    : QObject(parent)
{

}

void test_runner::find_by_credits_test()
{
    Useful test_useful;
    POINT(find_by_credits_test, 1.1);
    test_useful.addStudent("Mark Markdown", 15, 1233);
    test_useful.addStudent("Linus Torvalds", 240, 1454);
    test_useful.addStudent("Richard Stallman", 300, 1888);
    QStringList names = test_useful.findByCredits(100);
    QVERIFY(names.at(0) == "Linus Torvalds");
    QVERIFY(names.at(1) == "Richard Stallman");
}

void test_runner::remove_divisible_students_test()
{
    Useful test_useful;
    POINT(remove_divisible_students, 1.2);
    test_useful.addStudent("Mark Markdown", 15, 1233);
    test_useful.addStudent("Linus Torvalds", 240, 1454);
    test_useful.addStudent("Richard Stallman", 300, 1888);
    QMap<int, Student> map = test_useful.removeDivisibleStudents(4);
    QVERIFY(map.contains(1233) && map.contains(1454) && !map.contains(1888));
}

void test_runner::count_students_starting_with_test()
{
    Useful test_useful;
    POINT(count_students_starting_with, 1.3);
    test_useful.addStudent("Mark Markdown", 15, 1233);
    test_useful.addStudent("Linus Torvalds", 240, 1454);
    test_useful.addStudent("Richard Stallman", 300, 1888);
    test_useful.addStudent("Lauri Markkanen",  20, 2590);
    int n = test_useful.countStudentsStartingWith('L');
    int m = test_useful.countStudentsStartingWith('X');
    QVERIFY(n == 2 && m == 0);
}
