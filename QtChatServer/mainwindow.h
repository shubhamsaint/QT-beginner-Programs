#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSet>

class MainWindow : public QTcpServer
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void incomingConnection(int socketfd);
private slots:
    void readyRead();
    void disconnected();
    void sendUserList();

private:
    QSet <QTcpSocket*> clients;
    QMap<QTcpSocket*,QString> users;

};

#endif // MAINWINDOW_H
