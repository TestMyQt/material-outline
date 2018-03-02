#include "useful.h"
#include <QDebug>

useful::useful() {

}

// Write "Hello world" as qDebug message and
// "Don't panic!" as a qWarning message.
void useful::hello() {
    qDebug() << "Hello world";
    qWarning() << "Don't panic!";
}
