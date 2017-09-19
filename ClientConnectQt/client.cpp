#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

}

void Client::start(QString address, quint16 port)
{
  QHostAddress addr(address);
  socket->connectToHost(addr, port);
}


void Client::on_pushButton_clicked()
{
    QString message = ui->messagetoServer->text().trimmed();
    if(!message.isEmpty())
    {
        socket->write(QString(message + "\n").toUtf8());
    }
}

Client::~Client()
{

}
