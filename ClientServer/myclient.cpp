#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{

}
void MyClient::setSocket(qintptr descriptor)
{
    socket = new QTcpSocket(this);

    qDebug() << "new socket";

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    socket->setSocketDescriptor(descriptor);

    qDebug() << " Client connected at " << descriptor;
}


void MyClient::connected()
{
    qDebug() << "Client connected event";
}


void MyClient::disconnected()
{
    qDebug() << "Client disconnected";
}


void MyClient::readyRead()
{
    while(socket->canReadLine()){

        qDebug() <<"Port=" << socket->peerPort();
        qDebug() << socket->readLine();
}
}
