#include <QTest>
#include <QTextStream>
#include <QtMessageHandler>
#include <QList>
#include <QDebug>
#include <iostream>
#include "test_runner.h"
#include "useful.h"

#define POINT(test_name, point) qInfo("TMC:"#test_name"."#point)

test_runner::test_runner(QObject *parent)
    : QObject(parent)
{

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
        ts << txt <<"\t" << QString(msg) << endl;
    break;
    case QtCriticalMsg:
        txt = QString("Critical: %1 %2 %3:").arg(context.file).arg(context.line).arg(context.function);
        ts << txt << "\t" << QString(msg) << endl;
    break;
    case QtFatalMsg:
        txt = QString("Fatal: %1 %2 %3:").arg(context.file).arg(context.line).arg(context.function);
        ts << txt << "\t" << QString(msg) << endl;
        abort();
    }

    if (context.category == "focus")
    {
        std::cout<< txt.toStdString() << "\t" << QString(msg).toStdString() << std::endl;
    }
}

void test_runner::execute_strings()
{
    Useful test_useful;

    m_oldMessageHandler = qInstallMessageHandler(myMessageOutput);
    test_useful.string();
    qInstallMessageHandler(m_oldMessageHandler);
}

// Would it be necessary to give feedback on each string seperately?
void test_runner::correct_strings()
{
    POINT(correct_strings, 1);

    QList<QString> correctResults;
    correctResults.append("Qt rules 42");
    correctResults.append("Qt always rules 42");
    correctResults.append("Qt always rules 42 Qt always rules 42 Qt always rules 42 Qt always rules 42 Qt always rules 42 Qt always rules 42 Qt always rules 42 Qt always rules 42 Qt always rules 42 Qt always rules 42");
    correctResults.append("Qt appeared 10 times");

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
            int i = correctResults.indexOf(output);
            if (i != -1)
                correctResults.removeAt(i);
        }
    }
    resultsFile.remove();
    QVERIFY(correctResults.isEmpty());
}
