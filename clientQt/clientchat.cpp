#include "clientchat.h"
#include "ui_clientchat.h"

ClientChat::ClientChat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientChat)
{
    ui->setupUi(this);
}

ClientChat::~ClientChat()
{
    delete ui;
}

void ClientChat::on_connectIP_clicked()
{

}
