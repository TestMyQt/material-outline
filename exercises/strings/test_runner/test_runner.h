#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <QObject>

class test_runner : public QObject {

	Q_OBJECT

	public:
		explicit test_runner(QObject *parent = nullptr);

    private:
        QtMessageHandler m_oldMessageHandler;

	signals:

	public slots:

	private slots:
        void execute_strings();
        void correct_strings();

};

#endif
