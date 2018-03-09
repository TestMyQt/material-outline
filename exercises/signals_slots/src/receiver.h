#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QString>

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = 0);

public slots:
    void textSlot(QString message);
    void numberSlot(int first, int second);
};

#endif // RECEIVER_H
