#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/img1/Nature.jpg");
    int h=ui->labelPic->height();
    int w=ui->labelPic->width();
    ui->labelPic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username=="test"&&password=="test")
    {

        ui->statusBar->showMessage("Password is correct",5000);
        //QMessageBox ::information(this,"Login","Password is correct");

    }
    else
    {
        ui->statusBar->showMessage("Password is not correct",5000);
        //QMessageBox::warning(this,"Login","Password is incorrect");
    }
}
