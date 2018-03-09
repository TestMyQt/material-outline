#include "receiver.h"
#include <QDebug>

Receiver::Receiver(QObject *parent) : QObject(parent)
{

}

void Receiver::textSlot(QString message)
{
    qDebug() << message;
}

void Receiver::numberSlot(int first, int second)
{
    qDebug() << first + second;
}
