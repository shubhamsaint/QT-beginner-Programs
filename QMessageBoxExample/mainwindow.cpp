#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   // QMessageBox::about(this,"Message","This is my custom messgae");
    //QMessageBox::aboutQt(this,"Message");
    //QMessageBox::critical(this,"Message","This is Critical Message.");
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Message","this is a Question",QMessageBox::Yes|QMessageBox::No);
    //QMessageBox::warning(this,"Message","This is Warning");

    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else
    {
        qDebug() << "No is clicked";
    }
}
