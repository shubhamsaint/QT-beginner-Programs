#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

class DatabaseConnection
{
public:

    DatabaseConnection();
    ~DatabaseConnection();


    QSqlDatabase mydb;

    void connClose();
    bool connOpen();
};

#endif // DATABASECONNECTION_H
