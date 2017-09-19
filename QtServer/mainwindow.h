#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include "qtserver.h"


namespace Ui {
class MainWindow;
}
class QtServer;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void addMessage(QString Msg);
public:

     QtServer *m_pBoxserver;

private slots:
    void on_pushButtonConnect_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
