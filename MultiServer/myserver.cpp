#include "myserver.h"

MyServer::MyServer(QObject *parent) : QTcpServer(parent)
{

}

void MyServer::startServer()
{
    if(!this->listen(QHostAddress::Any,1234))
    {
        qDebug()<<"Server is not started";
    }
    else
    {
        qDebug() <<"Listening..";
    }
}

void MyServer::incomingConnection(int socketDescriptor)
{
    qDebug()<<socketDescriptor <<"Connecting...";

    MyThread *thread = new MyThread(socketDescriptor,this);

    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));

    thread->start();

 }
