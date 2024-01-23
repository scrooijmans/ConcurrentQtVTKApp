#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "thread.h"
#include "customqthread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_runButton_clicked();
    void on_message1Button_clicked();
    void on_message2Button_clicked();

    void stateChanged();
    void stateFinished();
    void on_killButton_clicked();

signals:
    void startOperation(int n);


private:
    Ui::MainWindow *ui;
    Thread m_thread;
    QThread m_qThread;
    CustomQThread m_customQThread;


};
#endif // MAINWINDOW_H
