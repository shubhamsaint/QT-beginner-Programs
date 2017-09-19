#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSet>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow ,public QTcpServer
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addMessage(QString Msg);
public:


private slots:
    void on_pushButtonConnect_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
