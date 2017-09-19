#include "myserver.h"

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    server =new QTcpServer();

    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any,5002))
    {
        qDebug()<<"Server could not started..";
    }
    else
    {
        qDebug() <<"Server Started..";
    }
}


void MyServer::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    socket->write("Hello client\n");

    socket->flush();

    socket->waitForBytesWritten(1000);
    socket->close();

}
