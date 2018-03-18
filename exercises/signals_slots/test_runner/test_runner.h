#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <QObject>
#include <sender.h>
#include <receiver.h>

class test_runner : public QObject
{

    Q_OBJECT

public:
    explicit test_runner(QObject *parent = nullptr);

signals:

public slots:

private slots:
    void text_signal_test();
    void text_signal_test_read();
    void numbers_signal_test();
    void numbers_signal_test_read();

private:
    QtMessageHandler m_oldMessageHandler;
    Sender sender;
    Receiver receiver;
};

#endif
