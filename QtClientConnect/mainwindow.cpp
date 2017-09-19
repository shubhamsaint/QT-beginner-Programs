#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(2);
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    socket->connectToHost(ui->serverLineEdit->text(),4200);
}

void MainWindow::on_sayButton_clicked()
{
    QString message = ui->sayLineEdit->text().trimmed();

    if(!message.isEmpty())
    {
        socket->write(QString(message +"\n").toUtf8());
    }

    ui->sayLineEdit->clear();

    ui->sayLineEdit->setFocus();
}

void MainWindow::readyRead()
{
    while(socket->canReadLine())
    {
        QString line = QString::fromUtf8(socket->readLine()).trimmed();

        QRegExp messageRegex("^([^:]+):(.*)$");

        QRegExp usersRegex("^/users:(.*)$");

        if(usersRegex.indexIn(line) != -1)
        {

        QStringList users = usersRegex.cap(1).split(",");
        ui->userListWidget->clear();
        foreach(QString user, users)
             new QListWidgetItem(QPixmap(":/images/user.png"), user, ui->userListWidget);
         }

         else if(messageRegex.indexIn(line) != -1)
         {
                    // If so, append this message to our chat box:
            QString user = messageRegex.cap(1);
            QString message = messageRegex.cap(2);

                    ui->roomTextEdit->append("<b>" + user + "</b>: " + message);
          }
    }

}

// This function gets called when the socket tells us it's connected.
void MainWindow::connected()
{
    ui->stackedWidget->setCurrentIndex(1);

        socket->write(QString("/me:" + ui->userLineEdit->text() + "\n").toUtf8());
}
