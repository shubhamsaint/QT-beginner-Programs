#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QListWidgetItem *item = new QListWidgetItem(QIcon(":/rec/img/Nature.jpg"),"Mark");
    ui->listWidget->addItem(item);

     /*QListWidgetItem item1 = new QListWidgetItem(QIcon(":/rec/img/Nature.jpg"),"Hell");
      ui->listWidget->addItem(item1);
      QListWidgetItem item2 = new QListWidgetItem(QIcon(":/rec/img/Nature.jpg"),"Galileo");
       ui->listWidget->addItem(item2);*/

}

MainWindow::~MainWindow()
{
    delete ui;
}
