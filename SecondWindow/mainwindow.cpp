#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    /*//dont allow us to use previos window
    SecDialog secDialog;
    secDialog.setModal(true);
    secDialog.exec();
       */
    /*
    secDialog = new SecDialog(this);
    secDialog->show();
    */
    hide();
    secDialog = new SecDialog(this);
    secDialog->show();

}
