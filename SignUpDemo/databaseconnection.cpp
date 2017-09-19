#include "databaseconnection.h"

DatabaseConnection::DatabaseConnection()
{

}

DatabaseConnection::~DatabaseConnection()
{

}
void DatabaseConnection::connClose()
{
    QString connection;
    connection = mydb.connectionName();

    mydb = QSqlDatabase();
    mydb.close();
    mydb.removeDatabase(connection);
    qDebug() << "CLOSING DB";
}


bool DatabaseConnection::connOpen()
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
