#include "serverlistener.h"

ServerListener::ServerListener(QObject *parent) : QTcpServer(parent)
{
 qDebug() <<"listening";

}

void ServerListener::incomingConnection(qintptr socketfd)
{
    QTcpSocket *socket = new QTcpSocket();

    socket->setSocketDescriptor(socketfd);
    qDebug() <<"helllolooo";

    connect(socket,SIGNAL(readyRead()),this,SLOT(readClient));

    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
}

void ServerListener::readClient()
{
    QTcpSocket *socket = (QTcpSocket*)sender();

    QString line = socket->readAll();
    qDebug()<<line;
}

