#ifndef USEFUL_H
#define USEFUL_H
#include <QList>
#include <QMap>
#include <QString>

class useful {

	public:

        useful();

        QList<int> listPractise(QList<int> list);
        QList<float> heights(QMap<QString, float> heights);
        QList<QString> names(QMap<QString, float> heights);
};

#endif //USEFUL_H
