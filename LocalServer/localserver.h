#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QLocalServer>

class Localserver : public QLocalServer
{
public:
    Localserver();
    ~Localserver();
};

#endif // LOCALSERVER_H
