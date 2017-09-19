#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QRegExp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

    void on_sayButton_clicked();

    void readyRead();

    // This function gets called when the socket tells us it's connected.
    void connected();


private:
    Ui::MainWindow *ui;
    QTcpSocket* socket;
};

#endif // MAINWINDOW_H
