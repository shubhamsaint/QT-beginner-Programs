#include "mainwindow.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainWindow *server = new MainWindow();

    bool success = server->listen(QHostAddress::Any, 4200);

    if(!success)
    {
        qFatal("Could not listen on port 4200.");
    }

    qDebug()<<"Ready";

    return a.exec();
}
