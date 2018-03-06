#include "useful.h"
#include <QDebug>

useful::useful() {

}

// 1) Make a function that takes a QList<int> as an
// argument and uses a mutabel iterator to multiply
// all numbers divisible by 5 by 3.
// 2) Make a function that takes a QMap<QString, float> as an
// argument and returns a QList<float> of all heights where
// the name start with an 'A'.
// 3) Same as 2) but return QList<QString> of names of people
// who are taller than 1.80m. You can assume that no two people
// are the same height.
QList<int> useful::listPractise(QList<int> list)
{
    QMutableListIterator<int> i(list);
    while (i.hasNext()) {
        int j = i.next();
        if (list[j] % 5 == 0) {
            list[j] = list[j] * 3;
        }
    }
    return list;
}

QList<float> useful::heights(QMap<QString, float> heights)
{
    QList<float> heightList;
    for (QMap<QString, float>::iterator i = heights.begin(); i != heights.end(); i++) {
        if (i.key().startsWith('A'))
            heightList.append(heights.value(i.key()));
    }
    return heightList;
}

QList<QString> useful::names(QMap<QString, float> heights)
{
    QList<QString> nameList;
    for (QMap<QString, float>::iterator i = heights.begin(); i != heights.end(); i++) {
        if (i.value() > 1.80)
            nameList.append(heights.key(i.value()));
    }
    return nameList;
}



