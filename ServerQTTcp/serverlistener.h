#ifndef SERVERLISTENER_H
#define SERVERLISTENER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class ServerListener : public QTcpServer
{
    Q_OBJECT
public:
    explicit ServerListener(QObject *parent = 0);
private slots:

    void readClient();

signals:
protected:
    void incomingConnection(qintptr socketfd);
public slots:
};

#endif // SERVERLISTENER_H
