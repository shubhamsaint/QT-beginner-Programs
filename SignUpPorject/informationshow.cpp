#include "informationshow.h"
#include "ui_informationshow.h"
#include "sqlqueryexecute.h"
#include "mainwindow.h"

InformationShow::InformationShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformationShow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("Employee Information"));
}

InformationShow::~InformationShow()
{
    delete ui;
}
void InformationShow::receiveData(QString empInfo)
{



    SqlQueryExecute sql;

    QString query = "select * from employeeinfo where username ='"+empInfo+"'";

    QStringList sl = sql.selectExecute(query);

    ui->lineEdit_information_eid->setText(sl.value(0));
    ui->lineEdit_information_name->setText(sl.value(1));
    ui->lineEdit_information_surname->setText(sl.value(2));
    ui->lineEdit_information_age->setText(sl.value(3));

}

void InformationShow::on_pushButton_information_logout_clicked()
{

    this->hide();
}
