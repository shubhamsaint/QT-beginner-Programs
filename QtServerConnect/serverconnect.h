#ifndef SERVERCONNECT_H
#define SERVERCONNECT_H

#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>

class ServerConnect : public QTcpServer
{
public:
    ServerConnect(QObject *parent = 0);

public slots:
    void newConnection();


private:

    QTcpServer *tcpServer;

};

#endif // SERVERCONNECT_H
