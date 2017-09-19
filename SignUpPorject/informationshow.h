#ifndef INFORMATIONSHOW_H
#define INFORMATIONSHOW_H

#include <QDialog>
#include <QDebug>
#include <QMainWindow>
#include <QtSql>

namespace Ui {
class InformationShow;
}

class InformationShow : public QDialog
{
    Q_OBJECT

public:
    explicit InformationShow(QWidget *parent = 0);
    ~InformationShow();

public slots:
    void receiveData(QString);

private slots:
    void on_pushButton_information_logout_clicked();

private:
    Ui::InformationShow *ui;
};

#endif // INFORMATIONSHOW_H
