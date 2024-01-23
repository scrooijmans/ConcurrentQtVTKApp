#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QtConcurrent>


class Thread : public QObject
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = nullptr);

public slots:
    void doWork(int i);
private:
    void printNums(int n);



signals:
};

#endif // THREAD_H
