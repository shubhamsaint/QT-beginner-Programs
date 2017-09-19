#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlqueryexecute.h"
#include <QMessageBox>
#include "informationshow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(1,"LOGIN");

    ui->tabWidget->setTabText(0,"SIGN UP");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_signup_clicked()
{
    SqlQueryExecute sql;

    QString eid = ui->lineEdit_eid->text();
    QString name = ui->lineEdit_name->text();
    QString surname = ui->lineEdit_surname->text();
    QString age = ui->lineEdit_age->text();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();


    QString query;
    query = "insert into employeeinfo (eid,name,surname,age,username,password) values ('"+eid+"','"+name+"','"+surname+"','"+age+"','"+username+"','"+password+"')";

    if(sql.insertExecute(query))
    {
      QMessageBox::information(this,"Signup","Data is stored");
    }
    else
    {
       QMessageBox::information(this,"Signup","Data cannot be stored");
    }
}

void MainWindow::on_pushButton_login_clicked()
{
    SqlQueryExecute sql;

    QString username = ui->lineEdit_login_username->text();
    QString password = ui->lineEdit_login_password->text();

    QString query;
    QString sendUsername;
    showInformation = new InformationShow();
    query = "select * from employeeinfo where username ='"+username+"'and password='"+password+"'";

    if(sql.validateExecute(query))
    {
        sendUsername = username;

        showInformation->setModal(true);

        connect(this,SIGNAL(sendData(QString)),showInformation,SLOT(receiveData(QString)));

        emit sendData(sendUsername);

        this->hide();
        showInformation->exec();

    }
    else
    {
        QMessageBox::warning(this,"Login","username/password is incorrect");
    }

}
