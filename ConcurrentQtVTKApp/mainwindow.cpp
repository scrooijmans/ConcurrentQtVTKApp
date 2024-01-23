#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, &MainWindow::startOperation, &m_thread, &Thread::doWork);

    // Move this operation to a different thread so we can continue with the main thread.
    m_thread.moveToThread(&m_qThread);
    m_qThread.start(); // Start the thread

    connect(&m_customQThread, &CustomQThread::started, this, &MainWindow::stateChanged);
    connect(&m_customQThread, &CustomQThread::finished, this, &MainWindow::stateFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runButton_clicked()
{
    emit startOperation(20);

    // Start will call the run method of the thread.
    m_customQThread.start();

    // m_thread.doWork(50000);
}


void MainWindow::on_message1Button_clicked()
{
    ui->lineEdit->setText("Message1");
}


void MainWindow::on_message2Button_clicked()
{
    ui->lineEdit->setText("Message2");

}

void MainWindow::stateChanged()
{
    ui->lineEdit->setText("CustomQThread started");
}

void MainWindow::stateFinished()
{
    ui->lineEdit->setText("CustomQThread finished");

}

void MainWindow::on_killButton_clicked()
{
    // Check if the thread is running. If it is, terminate it.
    if (m_customQThread.isRunning())
    {
        m_customQThread.terminate();
        ui->lineEdit->setText("Custom QThread terminated");

    }
    // do the same for the other thread.
    if (m_qThread.isRunning())
    {
        m_qThread.terminate();
        ui->lineEdit->setText("Received task from main QThread terminated");
    }
}

