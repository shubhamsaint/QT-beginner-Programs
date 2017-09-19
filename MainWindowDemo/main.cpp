
#include <QApplication>
#include "mainwindow.h"
#include "mainwin.h"

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    MainWin w;
    w.show();
    app.exec();
}
