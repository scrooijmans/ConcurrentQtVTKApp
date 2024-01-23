#ifndef CUSTOMQTHREAD_H
#define CUSTOMQTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

class CustomQThread : public QThread
{
    Q_OBJECT
public:
    explicit CustomQThread(QObject *parent = nullptr);


    void doWork(int n);

protected:
    void run();

};

#endif // CUSTOMQTHREAD_H
