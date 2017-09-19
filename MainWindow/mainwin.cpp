#include "mainwin.h"

MainWin::MainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWin)
{
    ui->setupUi(this);

    centralWidget = new QWidget;

    line1 = new QLineEdit(centralWidget);
    line2 = new QlineEdit(centralWidget);

    QFormLayout *form;
    form->addRow("lien1",line1);
    form->addRow("line2",line2);

    centralWidget->setLayout(form);

    setCentralWidget(centralWidget);

}

MainWin::~MainWin()
{
    delete ui;
}
