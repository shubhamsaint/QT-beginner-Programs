#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/rec/img/new_icon.png"),"Mark");
    ui->listWidget->addItem(item);
    QListWidgetItem *item1 = new QListWidgetItem(QIcon(":/rec/img/open_icon.jpg"),"Mark1");
    ui->listWidget->addItem(item1);
    QListWidgetItem *item2 = new QListWidgetItem(QIcon(":/rec/img/exit_icon.jpg"),"Mark2");
    ui->listWidget->addItem(item2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
 //QMessageBox::information(this,"Message",ui->listWidget->currentItem()->text());
    ui->listWidget->currentItem()->setBackgroundColor(Qt::red);
     ui->listWidget->currentItem()->setForeground(Qt::white);
}
