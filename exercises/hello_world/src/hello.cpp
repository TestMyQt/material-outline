#include "hello.h"
#include <QDebug>

Hello::Hello()
{

}

// Write "Hello world" as qDebug message and
// "Don't panic!" as a qWarning message.
void Hello::world()
{
    qDebug() << "Hello world";
    qWarning() << "Don't panic!";
}
