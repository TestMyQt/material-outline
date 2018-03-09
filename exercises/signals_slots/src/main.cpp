#include <QCoreApplication>
#include <iostream>
#include "sender.h"
#include "receiver.h"

#include <QObject>

using namespace std;


// Create classes Sender and Receiver.
// On Sender create functions
// sendText(QString) and sendNumbers(int one, int two)
// and define signals textSignal(QString) and numberSignal(int f, int s)
// On Receiver create the corresponding slots
// textSlot() that uses QDebug to print out the message
// numberSlot() that uses QDebug to print out the sum
int main(int argc, char *argv[]) {
    Sender sender;
    Receiver receiver;
    QObject::connect(&sender, &Sender::textSignal, &receiver, &Receiver::textSlot);
    QObject::connect(&sender, &Sender::numberSignal, &receiver, &Receiver::numberSlot);
    sender.sendText("testi");
    sender.sendNumbers(15, -4);

    QCoreApplication a(argc, argv);
    return a.exec();
}
