#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QByteArray stuff;

    stuff.append("hahi");

    qInfo()<<stuff;



    w.show();
    return a.exec();
}
