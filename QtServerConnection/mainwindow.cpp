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

void MainWindow::on_pushButtonConnect_clicked()
{
    MainWindow *server = new MainWindow();
    bool success = server->listen(QHostAddress::Any, 4200);
     if(!success)
     {
         addMessage("Server Failed");
     }
     else
         {
             addMessage("Server Started...");
         }

}

void MainWindow::addMessage(QString Msg)
{
 ui->textEditStatus->setText(Msg);
}
