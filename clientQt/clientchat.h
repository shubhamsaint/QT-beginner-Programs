#ifndef CLIENTCHAT_H
#define CLIENTCHAT_H

#include <QDialog>

namespace Ui {
class ClientChat;
}

class ClientChat : public QDialog
{
    Q_OBJECT

public:
    explicit ClientChat(QWidget *parent = 0);
    ~ClientChat();

private slots:
    void on_connectIP_clicked();

private:
    Ui::ClientChat *ui;
};

#endif // CLIENTCHAT_H
