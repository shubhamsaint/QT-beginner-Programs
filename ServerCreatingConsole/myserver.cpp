// myserver.cpp

#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}

void MyServer::startServer()
{
    if(listen(QHostAddress("192.168.0.60"), 1234))
    {
        qDebug() << "Server: started";
    }
    else
    {
        qDebug() << "Server: not started!";
    }
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug()<<socketDescriptor;
    QTcpSocket *socket = new QTcpSocket();

    socket->setSocketDescriptor(socketDescriptor);

    sockets.insert(socket);

    QString msg = "Client Connected:";
    msg.append(socket->peerAddress().toString());

    foreach(QTcpSocket *otherSocket, sockets)
    {
     otherSocket->write(msg.toUtf8());
     otherSocket->write("\n\r");
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

void MyServer::readClient()
{
     QTcpSocket *socket = (QTcpSocket*)sender();
     //qDebug()<<socket->socketDescriptor()<<" :"<<socket->readAll();
     QString msg = socket->peerAddress().toString();
     msg.append(" : ");
     msg.append(socket->readAll());
     foreach(QTcpSocket *otherSocket, sockets)
     {
      otherSocket->write(msg.toUtf8());
      otherSocket->write("\n\r");
      }
}

void MyServer::disconnected()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    sockets.remove(socket);
    QString msg = "Client disconnected:" ;
    msg.append(socket->peerAddress().toString());
    foreach(QTcpSocket *otherSocket, sockets)
    {
     otherSocket->write(msg.toUtf8());
     otherSocket->write("\n\r");
     }

    //sockets.remove(socket);   `

}
