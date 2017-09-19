#include "memoryclass.h"

MemoryClass::MemoryClass(QObject *parent) : QObject(parent)
{

}

MemoryClass::~MemoryClass()
{

}

void MemoryClass::test()
{
    qDebug()<<"Hello from c++";
}

void MemoryClass::clear()
{
    qDebug()<<"clear";
}

void MemoryClass::save()
{
   qDebug()<<"save the data";
}

void MemoryClass::add(double x, double y)
{
    QPoint p(x,y);
    qDebug()<< "Adding "<<p;
}

void MemoryClass::add(QPoint point)
{
    qDebug()<< "Adding Float "<<point;
}

