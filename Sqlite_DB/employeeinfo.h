#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H


#include <QDialog>
#include "login.h"

namespace Ui {
class EmployeeInfo;
}

class EmployeeInfo : public QDialog
{
    Q_OBJECT

public:

    explicit EmployeeInfo(QWidget *parent = 0);

    ~EmployeeInfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_loadTable_clicked();

    void on_pushButton_loadList_clicked();

    void on_pushButton_comboBox_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_listView_activated(const QModelIndex &index);

private:
    Ui::EmployeeInfo *ui;
};

#endif // EMPLOYEEINFO_H
