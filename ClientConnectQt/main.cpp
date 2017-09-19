#include "client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Client client;


    client.show();
    client.start("127.0.0.1", 5002);
    return a.exec();
}
