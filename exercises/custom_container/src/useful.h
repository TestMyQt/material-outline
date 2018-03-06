#ifndef USEFUL_H
#define USEFUL_H
#include <QMap>
#include <QString>
#include "student.h"

class useful {

	public:
        useful();
        void addStudent(QString name, int credits, int studentNumber);
        QStringList findByCredits(int credits);
        QMap<int, Student> removeDivisibleStudents(int divisor);
        int countStudentsStartingWith(char n);

    private:
        QMap<int, Student> studentMap;
};

#endif //USEFUL_H
