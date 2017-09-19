#include "employeeinfo.h"
#include "ui_employeeinfo.h"
#include "login.h"
#include <QMessageBox>

EmployeeInfo::EmployeeInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeInfo)
{
    ui->setupUi(this);
    login conn;
    if(!conn.connOpen())
    {
        ui->label_sec_status->setText("Failed to connect!!");
    }
    else
    {
        ui->label_sec_status->setText("Connected...");
    }
}

EmployeeInfo::~EmployeeInfo()
{
    delete ui;
}

void EmployeeInfo::on_pushButton_clicked()
{
    QString eid,name,surname,age;

    login conn;

    conn.connOpen();
    eid=ui->lineEdit_eid->text();
    name=ui->lineEdit_name->text();
    surname=ui->lineEdit_surname->text();
    age=ui->lineEdit_age->text();

    QSqlQuery *qry=new QSqlQuery(conn.mydb);

    qry->prepare("insert into employeeinfo (eid,name,surname,age) values('"+eid+"','"+name+"','"+surname+"','"+age+"')");
    if(qry->exec())
    {
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),tr("can not be saved"));
    }
    conn.connClose();
}

void EmployeeInfo::on_pushButton_loadTable_clicked()
{
    login conn;
    QSqlQueryModel *modal = new QSqlQueryModel();


    conn.connOpen();

    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from employeeinfo");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}

void EmployeeInfo::on_pushButton_loadList_clicked()
{
    login conn;
    QSqlQueryModel *modal = new QSqlQueryModel();


    conn.connOpen();

    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select name from employeeinfo");

    qry->exec();
    modal->setQuery(*qry);

   ui->listView->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}

void EmployeeInfo::on_pushButton_comboBox_clicked()
{
    login conn;
    QSqlQueryModel *modal = new QSqlQueryModel();


    conn.connOpen();

    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select name from employeeinfo");

    qry->exec();
    modal->setQuery(*qry);

   ui->comboBox->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());

}

void EmployeeInfo::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString name = ui->comboBox->currentText();

    login conn;
    if(!conn.connOpen())
    {
        qDebug()<<"Failed to connect to database";
        return;

    }

    conn.connOpen();

    QSqlQuery qry;

    qry.prepare("select * from employeeinfo where name='"+name+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_eid->setText(qry.value(0).toString());
            ui->lineEdit_name->setText(qry.value(1).toString());
            ui->lineEdit_surname->setText(qry.value(2).toString());
            ui->lineEdit_age->setText(qry.value(3).toString());
        }
        conn.connClose();
    }
    else
    {
         QMessageBox::critical(this,tr("error:"),qry.lastError().text());
    }
    conn.connClose();
}

void EmployeeInfo::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();

    login conn;
    if(!conn.connOpen())
    {
        qDebug()<<"Failed to connect to database";
        return;

    }

    conn.connOpen();

    QSqlQuery qry;

    qry.prepare("select * from employeeinfo where name='"+val+"' or eid='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_eid->setText(qry.value(0).toString());
            ui->lineEdit_name->setText(qry.value(1).toString());
            ui->lineEdit_surname->setText(qry.value(2).toString());
            ui->lineEdit_age->setText(qry.value(3).toString());
        }
        conn.connClose();
    }
    else
    {
         QMessageBox::critical(this,tr("error:"),qry.lastError().text());
    }
}

void EmployeeInfo::on_listView_activated(const QModelIndex &index)
{
    QString val = ui->listView->model()->data(index).toString();

    login conn;
    if(!conn.connOpen())
    {
        qDebug()<<"Failed to connect to database";
        return;

    }

    conn.connOpen();

    QSqlQuery qry;

    qry.prepare("select * from employeeinfo where name='"+val+"' or eid='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_eid->setText(qry.value(0).toString());
            ui->lineEdit_name->setText(qry.value(1).toString());
            ui->lineEdit_surname->setText(qry.value(2).toString());
            ui->lineEdit_age->setText(qry.value(3).toString());
        }
        conn.connClose();
    }
    else
    {
         QMessageBox::critical(this,tr("error:"),qry.lastError().text());
    }
}
