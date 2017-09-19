#include "widgets.h"
#include "ui_widgets.h"

Widgets::Widgets(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widgets)
{
    ui->setupUi(this);
}

Widgets::~Widgets()
{
    delete ui;
}
