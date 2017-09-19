// myserver.h

#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMap>
#include <QSet>

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    void startServer();
private:
    QSet<QTcpSocket*> sockets;
     QMap<QTcpSocket*,QString> users;

protected:
    void incomingConnection(qintptr socketDescriptor);
private slots:
    void readClient();

    void disconnected();
signals:

public slots:


};

#endif // MYSERVER_H
