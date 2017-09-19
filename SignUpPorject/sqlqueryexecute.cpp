#include "sqlqueryexecute.h"
#include "databaseconnection.h"

SqlQueryExecute::SqlQueryExecute()
{

}

SqlQueryExecute::~SqlQueryExecute()
{

}

bool SqlQueryExecute::insertExecute(QString query)
{
    DatabaseConnection db;

    db.connOpen();


    QSqlQuery qry;
    qry.prepare(query);

    if(qry.exec())
    {
        db.connClose();
        return true;
    }
    else
    {
        qDebug()<<"Insert:"<<qry.lastError().text();
        db.connClose();
        return false;
    }
}

bool SqlQueryExecute::validateExecute(QString query)
{
    DatabaseConnection db;

    db.connOpen();


    QSqlQuery qry;

    qry.prepare(query);

    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            return true;
        }
        if(count!=1)
        {
            return false;
        }
    }

    else
    {
        qDebug()<<"Validate:"<<qry.lastError().text();
        db.connClose();
        return false;
    }
    return false;
}

QStringList SqlQueryExecute::selectExecute(QString query)
{
    DatabaseConnection db;

    db.connOpen();

    QStringList sl;

    QSqlQuery qry,qry_ex;

    qry.prepare(query);
    qry_ex.prepare(query);
    if(qry.exec())
    {
        while(qry.next())
        {

           sl.append(qry.value(0).toString());
           sl.append(qry.value(1).toString());
           sl.append(qry.value(2).toString());
           sl.append(qry.value(3).toString());
           db.connClose();
        }
           return sl;

    }

    else
    {
        qDebug()<<"Select::"<<qry.lastError().text();

        return sl;
    }
}
