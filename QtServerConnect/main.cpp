#include <QCoreApplication>
#include "serverconnect.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerConnect *server = new ServerConnect();

    bool success = server->listen(QHostAddress::Any, 4200);

    if(!success)
    {
        qFatal("Could not listen on port 4200.");
    }

    qDebug()<<"Ready";

    return a.exec();
}
