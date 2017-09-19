#include <QCoreApplication>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

      Client client;
      client.start("127.0.0.1", 80);

      return app.exec();
}
