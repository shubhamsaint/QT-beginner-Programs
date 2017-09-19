#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include <QtWidgets>

namespace Ui {
class MainWin;
}

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = 0);
    ~MainWin();

private:
    Ui::MainWin *ui;
    QWidget *centralWidget;
    QLineEdit *line1;
    QLineEdit *line2;


};

#endif // MAINWIN_H
