#ifndef USEFUL_H
#define USEFUL_H
#include <QMap>
#include <QString>
#include "student.h"

class Useful
{

	public:
        Useful();
        void addStudent(const QString &name, int credits, int studentNumber);
        QStringList findByCredits(int credits) const;
        QMap<int, Student> removeDivisibleStudents(int divisor);
        int countStudentsStartingWith(QChar n) const const;

    private:
        QMap<int, Student> studentMap;
};

#endif //USEFUL_H
