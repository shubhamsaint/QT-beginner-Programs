#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow *w = new QMainWindow();
    QWidget *centralWidget = new QWidget(w);
    QLineEdit *line1 = new QLineEdit(centralWidget);

    QFormLayout *form = new QFormLayout;

    form->addRow("line1",line1);

    centralWidget->setLayout(form);
    w->setCentralWidget(centralWidget);

    w->show();

    return a.exec();
}
