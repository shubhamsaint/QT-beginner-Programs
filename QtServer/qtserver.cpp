#include "qtserver.h"
#include <QTcpSocket>

QtServer::QtServer(MainWindow* pQServer,QObject *parent) : QTcpServer(parent)
{
    m_pQWindow = pQServer;
}

void QtServer::incomingConnection(int socketfd)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);
    client = nextPendingConnection();
    clients.insert(client);

    m_pQWindow->addMessage("New client from: "+client->peerAddress().toString());

    connect(client,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(client,SIGNAL(disconnected()),this,SLOT(disconnected()));

}

void QtServer::readyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();
       while(client->canReadLine())
       {
           QString line = QString::fromUtf8(client->readLine()).trimmed();
           m_pQWindow->addMessage(line);
       }
}

void QtServer::disconnected()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    qDebug() << "Client disconnected:" << client->peerAddress().toString();

    clients.remove(client);

}



