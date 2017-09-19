#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem(QIcon(":/rec/img/Nature.jpg"),"hello");
     ui->comboBox->addItem(QIcon(":/rec/img/new_icon.png"),"hello1");
      ui->comboBox->addItem(QIcon(":/rec/img/open_icon.jpg"),"hello2");

      for(int i=0;i<10;i++)
      {
          ui->comboBox->addItem(QIcon(":/rec/img/Nature.jpg"),QString::number(i)+"name");
      }
      ui->comboBox->insertItem(3,QIcon(":/rec/img/Nature.jpg"),"new");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QMessageBox::information(this,"MEssager",QString::number(ui->comboBox->currentIndex()));
}
