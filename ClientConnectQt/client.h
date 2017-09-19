#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QtNetwork>

#include <QString>
#include <QTcpSocket>

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);

    ~Client();

    void start(QString address, quint16 port);

public slots:

private slots:
     void on_pushButton_clicked();


private:
     QTcpSocket *socket;
     Ui::Client *ui;
};

#endif
