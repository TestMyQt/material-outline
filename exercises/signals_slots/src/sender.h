#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QString>

class Sender : public QObject
{
    Q_OBJECT
public:
    explicit Sender(QObject *parent = 0);

    void sendText(QString message);
    void sendNumbers(int first, int second);

signals:
    void textSignal(QString message);
    void numberSignal(int first, int second);
};

#endif // SENDER_H
