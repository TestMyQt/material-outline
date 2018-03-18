#include "student.h"

Student::Student()
    : Student("Douglas Adams", 42)
{

}

Student::Student(const QString &name, int credits)
{
    m_name = name;
    m_credits = credits;
}

QString Student::getName() const
{
    return m_name;
}

void Student::setName(const QString &name)
{
    m_name = name;
}

int Student::getCredits() const
{
    return m_credits;
}

void Student::setCredits(int credits)
{
    m_credits = credits;
}


