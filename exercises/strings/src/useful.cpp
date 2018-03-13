#include "useful.h"
#include <QDebug>

useful::useful() {

}

// 1) Create a QString with the text "Qt rules " and then
// add the number "42" to it using QStrings appending function.
// Then print it the QDebug output.
// 2) Use the same QString. Use insert to add the word "always"
// after the first word, and then print the string with QDebug.
// 3) Make a copy of the string and use a loop to append it to
// the original (seperated by a space) 10 times. Again print
// the string with QDebug.
// 4) Count the amount of times "Qt" appears in the string
// print out "Qt appeared x times" with QDebug.
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
