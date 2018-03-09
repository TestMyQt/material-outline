#include "sender.h"

Sender::Sender(QObject *parent) : QObject(parent)
{

}

void Sender::sendText(QString message)
{
    emit textSignal(message);
}

void Sender::sendNumbers(int first, int second)
{
    emit numberSignal(first, second);
}
