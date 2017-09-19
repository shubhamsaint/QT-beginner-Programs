#include "login.h"
#include "ui_login.h"
#include <QPixmap>
#include <QMessageBox>

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    ui->tabWidget->setTabText(0,"LOGIN");

    ui->tabWidget->setTabText(1,"SIGN UP");


    QPixmap pix("C:/Users/Shubham/Downloads/Nature.jpg");

    ui->label_pic->setPixmap(pix.scaled(ui->label_pic->height(),ui->label_pic->width(),Qt::KeepAspectRatio));

    if(!connOpen())
    {
        ui->label->setText("Failed to connect!!");
        ui->label_4->setText("Failed");
    }
    else
    {
        ui->label->setText("Connected..");
        mydb.close();
        ui->label_4->setText("Connected");
    }


}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString username,password;

    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(!connOpen())
    {
        qDebug()<<"Failed to connect to database";
        return;

    }

    QSqlQuery qry;
    qry.prepare("select * from employeeinfo where username ='"+username+"'and password='"+password+"'");

    if(qry.exec())
    {
      int count=0;
      while(qry.next())
      {
          count++;
      }
      if(count==1)
      {
          ui->label->setText("username and password is correct");
          connClose();
          this->hide();
          qDebug()<<"NEW SIDE";
          mydb.close();
          EmployeeInfo employeeinfo;
          employeeinfo.setModal(true);
          employeeinfo.exec();
      }
      if(count>1)
          ui->label->setText("username and password is Duplicate");
      if(count>1)
          ui->label->setText("username and password is incorrect");

    }
    connClose();
}

void login::on_spinBox_valueChanged(const QString &arg1)
{
    ui->lineEdit_username->setText(arg1);
}

void login::on_tabWidget_tabBarClicked(int index)
{


}

void login::on_pushButton_2_clicked()
{

    QString username,password;

   QString eid=ui->lineEdit_eid->text();
    QString name=ui->lineEdit_name->text();

    if(!connOpen())
    {
        qDebug()<<"Failed to connect to database";
        return;

    }

    QSqlQuery qry;

    qry.prepare("insert into employeeinfo (eid,name) values('"+eid+"','"+name+"'");
    if(qry.exec())
    {
        qDebug()<<("SAVING NEW DATA");
    }

    connClose();

    /*
    QString username,password,eid,name,surname,age;


    username=ui->lineEdit_username_2->text();
    password=ui->lineEdit_password_2->text();
    eid=ui->lineEdit_eid->text();
    name=ui->lineEdit_name->text();
    age=ui->lineEdit_age->text();
    surname=ui->lineEdit_surname->text();
    mydb.open();
    if(!connOpen())
    {
        qDebug()<<"Failed to connect to database";
        return;

    }

    QSqlQuery qry;

    qry.prepare("insert into employeeinfo (eid,name,surname,age,username,password) values('"+eid+"','"+name+"','"+surname+"','"+age+"','"+username+"','"+password+"')");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
    }
    else
    {
         qry.finish();
         QMessageBox::critical(this,tr("error:"),qry.lastError().text());
    }
    connClose();

*/
}
