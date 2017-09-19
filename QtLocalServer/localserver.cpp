#include "localserver.h"
#include <QLocalServer>

Localserver::Localserver(QObject *parent) : QLocalServer(parent)
{
    mSocket = nullptr;

    connect(this, &LocalServer::newConnection,[&](){
        mSocket = nextPendingConnection();
    });
}

Localserver::~Localserver()
{

}

