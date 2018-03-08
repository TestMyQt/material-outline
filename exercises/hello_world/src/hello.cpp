#include "hello.h"
#include <QDebug>

hello::hello() {

}

// Write "Hello world" as qDebug message and
// "Don't panic!" as a qWarning message.
void hello::world() {
    qDebug() << "Hello world";
    qWarning() << "Don't panic!";
}
