#ifndef MYSERVER_H
#define MYSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include "serverlistener.h"

namespace Ui {
class MyServer;
}

class MyServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyServer(QWidget *parent = 0);
    ~MyServer();
     QTcpServer *server;
     ServerListener *serverListener;
     void addMessage(QString Msg);
private slots:
    void on_pushButtonConnect_clicked();

private:
    Ui::MyServer *ui;

};

#endif // MYSERVER_H
