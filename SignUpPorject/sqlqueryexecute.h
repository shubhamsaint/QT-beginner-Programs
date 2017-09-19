#ifndef SQLQUERYEXECUTE_H
#define SQLQUERYEXECUTE_H
#include <QMainWindow>

class SqlQueryExecute
{
public:
    SqlQueryExecute();
    ~SqlQueryExecute();

    bool insertExecute(QString query);
    bool validateExecute(QString query);
    QStringList selectExecute(QString query);
};



#endif // SQLQUERYEXECUTE_H
