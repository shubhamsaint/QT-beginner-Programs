#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QDebug>
#include "mythread.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);


    void startServer();
signals:
protected:
    void incomingConnection(int socketDescriptor);
public slots:
};

#endif // MYSERVER_H
