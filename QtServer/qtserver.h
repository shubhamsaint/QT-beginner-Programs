#ifndef QTSERVER_H
#define QTSERVER_H

#include <QTcpServer>

#include "MainWindow.h"
class MainWindow;

class QtServer : public QTcpServer
{
    Q_OBJECT
public:
    QtServer(MainWindow* pQServer,QObject *parent=0);

    MainWindow* m_pQWindow;
private slots:

    void readyRead();
    void disconnected();

    protected:
    void incomingConnection(int socketfd);

    public:
    QSet<QTcpSocket*> clients;
};

#endif // QTSERVER_H
