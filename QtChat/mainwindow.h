#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostAddress>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void peerSocket();
private:
    Ui::MainWindow *ui;
    QUdpSocket *udpsocket;
    QHostAddress destination;
    quint16 p;
};

#endif // MAINWINDOW_H
