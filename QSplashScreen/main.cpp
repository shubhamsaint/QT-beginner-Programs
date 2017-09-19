#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("C:/Users/Shubham/Downloads/Nature.jpg"));
    splash->show();


    MainWindow w;

    QTimer::singleShot(5000,splash,SLOT(close()));
    QTimer::singleShot(2500,&w,SLOT(show()));


    return a.exec();
}
