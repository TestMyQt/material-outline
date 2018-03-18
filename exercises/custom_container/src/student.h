#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QMetaType>

class Student
{
public:
    Student();
    Student(const QString &name, int credits);

    QString getName() const;
    void setName(const QString &name);
    int getCredits() const;
    void setCredits(int credits);

private:
    QString m_name;
    int m_credits;
};

Q_DECLARE_METATYPE(Student)


#endif // STUDENT_H
