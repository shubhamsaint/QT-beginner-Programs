#ifndef MEMORYCLASS_H
#define MEMORYCLASS_H

#include <QObject>
#include <QDebug>
#include <QPoint>

class MemoryClass : public QObject
{
    Q_OBJECT
public:
    explicit MemoryClass(QObject *parent = 0);
    ~MemoryClass();

     Q_INVOKABLE void test();
     Q_INVOKABLE void clear();
        Q_INVOKABLE void save();
        Q_INVOKABLE void add(double x,double y);
        Q_INVOKABLE void add(QPoint point);
signals:

public slots:
};

#endif // MEMORYCLASS_H
