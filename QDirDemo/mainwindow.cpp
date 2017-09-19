#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*QDir dir("C:/Users/Shubham/Documents/QDirDemo");

    if(dir.exists())
    {
        QMessageBox::information(this,"title","true");
    }
    else
    {
        QMessageBox::information(this,"title","no");
    }
    */
    QDir dir;
    foreach(QFileInfo var,dir.drives())
    {
        ui->comboBox->addItem(var.absoluteFilePath());
    }
    QDir dir_2("C:/Users/Shubham/Documents/QDirDemo");
    foreach(QFileInfo var,dir_2.entryInfoList())
    {
        if(var.isDir())
        ui->comboBox->addItem("Dir:"+var.absoluteFilePath());
        if(var.isFile())
            ui->comboBox->addItem(("File:" +var.absoluteFilePath()));
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDir dir("C:/Users/Shubham/Documents/QDirDemo/YY");
    if(dir.exists())
    {
        QMessageBox::information(this,"","dir existe");
    }
    else
    {
        dir.mkpath("C:/Users/Shubham/Documents/QDirDemo/YY");
        QMessageBox::information(this,"","Directory created");
    }
}
