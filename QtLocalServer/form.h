#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_pushButtonInitialise_clicked();

    void on_pushButtonEnter_clicked();

    void on_pushButtonQuit_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
