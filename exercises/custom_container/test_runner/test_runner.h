#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <QObject>

class test_runner : public QObject
{

	Q_OBJECT

	public:
		explicit test_runner(QObject *parent = nullptr);

	signals:

	public slots:

	private slots:
        void find_by_credits_test();
        void remove_divisible_students_test();
        void count_students_starting_with_test();

};

#endif
