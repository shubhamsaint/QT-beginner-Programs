#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "informationshow.h"

#include <QMainWindow>
#include <QtSql>

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

    void on_pushButton_signup_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;

     InformationShow *showInformation;
signals:
    void sendData(QString);


};

#endif // MAINWINDOW_H
