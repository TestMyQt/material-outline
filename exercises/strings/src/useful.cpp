#include "useful.h"
#include <QDebug>

useful::useful() {

}

// Some basic string manipulation. Currently only tested to have
// correct qDebug output, not sure if possible to test if certain
// function like .append has been used (nor if that's necessary)
void useful::string()
{
    QString string("Qt rules ");
    string.append(QString::number(42));
    qDebug() << string;

    if (string.contains("Qt"))
        string.insert(string.indexOf("Qt") + QByteArray("Qt").length(), " always");
    qDebug() << string;

    QString copyString(" " + string);
    for (auto i = 0; i < 9; ++i)
        string.append(copyString);
    qDebug() << string;

    qDebug() << "Qt appeared" << string.count("Qt") << "times";
}
