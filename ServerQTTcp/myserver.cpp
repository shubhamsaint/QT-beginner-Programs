#include "myserver.h"
#include "ui_myserver.h"
#include <QTcpSocket>

MyServer::MyServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyServer)
{
    ui->setupUi(this);

}

MyServer::~MyServer()
{
    delete ui;
}

void MyServer::on_pushButtonConnect_clicked()
{
    serverListener = new ServerListener(this);

    bool success = serverListener->listen(QHostAddress::Any,ui->textEditPort->toPlainText().toInt());

    if(!success)
    {
        ui->textEditStatus->setText("Not start");
    }
    else
    {
        ui->textEditStatus->setText("Started...");
    }

}

void MyServer::addMessage(QString Msg)
{
    ui->textEditStatus->setText(Msg);
}
