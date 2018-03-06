#include "useful.h"
#include <QDebug>
#include <QList>

useful::useful() {

}

// Create a class Student that has the student's name as QString
// and amound of study credits as integer. Use a student number (int) as
// the key in the container.
// Student should have setName(QString) and setCredits(int) as well as
// the respective getters.
// 1) Function that creates Students and adds them to the container.
//      void addStudent(QString name, int credits, int studentNumber)
// 2) Function that iterates over the container and returns a list
// of all names who have >= credits.
//      QStringList findByCredits(int credits)
// 3) Removes all students with a student numer divisible by N.
//      QMap<int, Student> removeDivisibleStudents(int divisor)
// 4) Counts the amount of students with a name starting with a char.
//      int countStudentsStartingWith(char n)
void useful::addStudent(QString name, int credits, int studentNumber)
{
    studentMap.insert(studentNumber, Student(name, credits));
}

QStringList useful::findByCredits(int credits)
{
    QStringList names;
    for (QMap<int, Student>::iterator i = studentMap.begin();
         i != studentMap.end(); i++) {
        if (i.value().getCredits() >= credits) {
            names.append(i.value().getName());
        }
    }
    return names;
}

QMap<int, Student> useful::removeDivisibleStudents(int divisor)
{
    QMutableMapIterator<int, Student> i(studentMap);
    while (i.hasNext()) {
        int n = i.next().key();
        if (n % divisor == 0) {
            studentMap.remove(n);
        }
    }
    return studentMap;
}

int useful::countStudentsStartingWith(char n)
{
    int count = 0;
    for (QMap<int, Student>::iterator i = studentMap.begin();
         i != studentMap.end(); i++) {
        if (i.value().getName().startsWith(n))
            count++;
    }
    return count;
}
