#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databaseconnection.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_signUp_clicked()
{
    DatabaseConnection db;

    QString eid,name,surname;

    eid = ui->lineEdit_eid->text();
    surname = ui->lineEdit_surname->text();
    name = ui->lineEdit_name->text();

    QSqlQuery query;

    query.prepare("insert into employeeinfo (eid,name,surname) values('"+eid+"','"+name+"'+'"+surname+"'");

    db.connOpen();

    query.exec();

    db.connClose();

}
