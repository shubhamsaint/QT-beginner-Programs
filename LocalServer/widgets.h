#ifndef WIDGETS_H
#define WIDGETS_H

#include <QMainWindow>

namespace Ui {
class Widgets;
}

class Widgets : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widgets(QWidget *parent = 0);
    ~Widgets();

private:
    Ui::Widgets *ui;
};

#endif // WIDGETS_H
