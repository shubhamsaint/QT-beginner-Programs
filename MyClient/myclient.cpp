#include "myclient.h"
#include "ui_myclient.h"

Myclient::Myclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Myclient)
{
    ui->setupUi(this);
}


void Myclient::setSocket(qintptr descriptor)
{
    socket = new QTcpSocket(this);


    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    socket->setSocketDescriptor(descriptor);

    qDebug() << " Client connected at " << descriptor;
}



void Myclient::connected()
{
    qDebug() << "Client connected event";
}


void Myclient::disconnected()
{
    qDebug() << "Client disconnected";
}


void Myclient::readyRead()
{
    while(socket->canReadLine()){

        qDebug() <<"Port=" << socket->peerPort();
        qDebug() << socket->readLine();
}
}
