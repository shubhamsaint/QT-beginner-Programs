#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QLocalServer>

class QLocalSocket;

class Localserver : public QLocalServer
{
    Q_OBJECT
public:
    explicit Localserver(QObject *parent = 0);
    ~Localserver();
private:
    QLocalSocket *mSocket;

};

#endif // LOCALSERVER_H
