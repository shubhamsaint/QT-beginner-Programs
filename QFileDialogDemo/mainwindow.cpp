#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

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
    QString file_name = QFileDialog::getOpenFileName(this,"open a file",QDir::homePath(),"All files (*.*);;Text File (*.txt);;Music File(*.mp3)");

    //QMessageBox::information(this,tr("File Name"),file_name);

    QDesktopServices::openUrl(QUrl("file:///"+file_name,QUrl::TolerantMode));

}
