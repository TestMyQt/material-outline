#include <QTest>
#include <QDebug>
#include <QSignalSpy>
#include <iostream>
#include "test_runner.h"

#define POINT(test_name, point) qInfo("TMC:"#test_name"."#point)

test_runner::test_runner(QObject *parent)
    : QObject(parent)
{
    QObject::connect(&sender, &Sender::textSignal, &receiver, &Receiver::textSlot);
    QObject::connect(&sender, &Sender::numberSignal, &receiver, &Receiver::numberSlot);
}

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QFile outFile("./log.txt");
    {
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    }

    QTextStream ts(&outFile);
    QString txt;
    switch (type) {
    case QtInfoMsg:
        txt = QString("Info: %1 %2 %3:").arg(context.file).arg(context.line).arg(context.function);
        ts << txt << "\t" << QString(msg) << endl;
        break;
    case QtDebugMsg:
        txt = QString("Debug: %1 %2 %3:").arg(context.file).arg(context.line).arg(context.function);
        ts << txt << "\t" << QString(msg) << endl;
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1 %2 %3:").arg(context.file).arg(context.line).arg(context.function);
        ts << txt << "\t" << QString(msg) << endl;
        break;
    case QtCriticalMsg:
        txt = QString("Critical: %1 %2 %3:").arg(context.file).arg(context.line).arg(context.function);
        ts << txt << "\t" << QString(msg) << endl;
        break;
    case QtFatalMsg:
        txt = QString("Fatal: %1 %2 %3:").arg(context.file).arg(context.line).arg(context.function);
        ts << txt <<"\t" << QString(msg) << endl;
        abort();
    }

    if (context.category == "focus")
    {
        std::cout<< txt.toStdString() << "\t" << QString(msg).toStdString() << std::endl;
    }
}

void test_runner::text_signal_test()
{
    POINT(text_signal_fires, 1.1);
    m_oldMessageHandler = qInstallMessageHandler(myMessageOutput);
    QSignalSpy spy(&sender, &Sender::textSignal);
    sender.sendText("Let's test text sending signal");
    QCOMPARE(spy.count(), 1);
    qInstallMessageHandler(m_oldMessageHandler);
}

void test_runner::text_signal_test_read()
{
    POINT(text_output_correct, 1.2);
    bool correct = 0;
    QFile resultsFile("./log.txt");
    if (!resultsFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream results(&resultsFile);
    while (!results.atEnd()) {
        QString line = results.readLine();
        if (line.startsWith("Debug")) {
            QString output = line.section("\t", 1);
            if (output.startsWith('\"')) {
                output.remove(0, 1);
                output.chop(1);
            }
            if (output == "Let's test text sending signal")
                correct = 1;
        }
    }
    resultsFile.remove();
    QVERIFY2(correct, "Correct text printed to debug");
}

void test_runner::numbers_signal_test()
{
    POINT(numbers_signal_fires, 1.3);
    m_oldMessageHandler = qInstallMessageHandler(myMessageOutput);
    QSignalSpy spy(&sender, &Sender::numberSignal);
    sender.sendNumbers(5, 13);
    QCOMPARE(spy.count(), 1);
    qInstallMessageHandler(m_oldMessageHandler);
}

void test_runner::numbers_signal_test_read()
{
    POINT(numbers_output_correct, 1.4);
    bool correct = 0;
    QFile resultsFile("./log.txt");
    if (!resultsFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream results(&resultsFile);
    while (!results.atEnd()) {
        QString line = results.readLine();
        if (line.startsWith("Debug")) {
            QString output = line.section("\t", 1);
            if (output.startsWith('\"')) {
                output.remove(0, 1);
                output.chop(1);
            }
            if (output == "18")
                correct = 1;
        }
    }
    resultsFile.remove();
    QVERIFY2(correct, "Correct sum printed to debug");
}
