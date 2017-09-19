#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{

}

void SocketTest::connect()
{
    socket = new QTcpSocket(this);

    socket->connectToHost("127.0.0.1",1234);

    if(socket->waitForConnected(3000))
    {
        qDebug()<<"connected";

        socket->write("Hello Server");

        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() <<"reading" <<socket->bytesAvailable();

        qDebug()<<socket->readAll();

        socket->close();
    }
    else

       {
        qDebug()<<" not connected";
        }
}
