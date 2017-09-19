#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QMainWindow>


#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThreadPool>

namespace Ui {
class Myclient;
}

class Myclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit Myclient(QWidget *parent = 0);
    void setSocket(qintptr Descriptor);

signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();


private:
    QTcpSocket *socket;
private:
    Ui::Myclient *ui;
};

#endif // MYCLIENT_H
