#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/rec/img/exit_icon.jpg");
    ui->label->setPixmap(pix.scaled(ui->label->height(),ui->label->width(),Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}
