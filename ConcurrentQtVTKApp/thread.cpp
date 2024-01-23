#include "thread.h"


Thread::Thread(QObject *parent)
    : QObject{parent}
{}

void Thread::doWork(int n)
{
    // QtConcurrent::run(&Thread::printNums, this, 10);
    // exectue using QtConcurrent but usign a lambda
    QtConcurrent::run([this]{return printNums(10);});
}

void Thread::printNums(int n)
{
    // count multiples of 5 from 0 to n
    for (int i = 0; i < n; ++i)
    {
        qDebug() << i*5;
        QThread::msleep(200);
    }

}
