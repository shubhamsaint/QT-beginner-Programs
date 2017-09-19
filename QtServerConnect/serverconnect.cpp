#include "serverconnect.h"

#include <QTcpSocket>
#include <QRegExp>

ServerConnect::ServerConnect(QObject *parent) : QTcpServer(parent)
{
    tcpServer = new QTcpServer(this);

    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(newConnection()));

    if(!tcpServer->listen(QHostAddress::Any,80))
    {
        qDebug()<<"Server could not start";
    }
    else
    {
        qDebug()<<"Server  started";
    }
}

void ServerConnect::newConnection()
{
  QTcpSocket *socket = tcpServer->nextPendingConnection();

  socket->write("HELOO CLIENT");
  socket->flush();

  socket->waitForBytesWritten(3000);

  socket->close();
}
