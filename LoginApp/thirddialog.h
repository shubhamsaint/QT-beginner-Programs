#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>

namespace Ui {
class ThirdDialog;
}

class ThirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdDialog(QWidget *parent = 0);
    ~ThirdDialog();

private:
    Ui::ThirdDialog *ui;
};

#endif // THIRDDIALOG_H
