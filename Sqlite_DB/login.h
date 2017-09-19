#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "employeeinfo.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb;
    void connClose()
    {
        QString connection;
        connection = mydb.connectionName();

        mydb = QSqlDatabase();
        mydb.close();
        mydb.removeDatabase(connection);
        qDebug() << "CLOSING DB";
    }

    bool connOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/sqlite/testDB.db");

        if(!mydb.open())
        {
           qDebug() << "Failed to connect!!";
           return false;
        }
        else

        {
           qDebug()<< "Connected.3." ;
           return true;
        }
    }
public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(const QString &arg1);

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;

};

#endif // LOGIN_H
