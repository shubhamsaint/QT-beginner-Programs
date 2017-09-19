#include "widgets.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widgets w;
    w.show();

    return a.exec();
}
