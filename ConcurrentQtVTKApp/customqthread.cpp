#include "customqthread.h"

CustomQThread::CustomQThread(QObject *parent)
    : QThread{parent}
{}

void CustomQThread::doWork(int n)
{
    for (int i = 0; i < n; ++i)
    {
        qDebug() << "Running custom qthread" << i;
        QThread::msleep(100);
    }
}

void CustomQThread::run()
{
    doWork(20);
}

