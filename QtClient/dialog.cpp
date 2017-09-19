#include "dialog.h"
#include "ui_dialog.h"

#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    socket = new QTcpSocket(this);
     connect(socket, SIGNAL(readyRead()), this, SLOT(readServer()));
    ui->setupUi(this);
    ui->pushButtonSend->setEnabled(false);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButtonConnect_clicked()
{
    socket->connectToHost(ui->textEditIP->toPlainText(),ui->textEditPort->toPlainText().toInt());

        ui->pushButtonSend->setEnabled(true);

}

void Dialog::on_pushButtonSend_clicked()
{


       QString message = ui->textEditMessage->toPlainText().trimmed();
       if(!message.isEmpty())
       {
           socket->write(QString(message + " ").toUtf8());
       }

        ui->textEditMessage->clear();
}

void Dialog::readServer()
{
    QTcpSocket *socket = (QTcpSocket*)sender();

   // msg.append(ui->textEdit_chat->toPlainText());

    while(socket->canReadLine())
    {
         msg.append(socket->readLine());
    }

    ui->textEdit_chat->setText(msg);
}
