#ifndef MAINWINDOW
#define MAINWINDOW

#include <QApplication>
#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    QMdiArea *centralWidget;
    QMenu *File;
    QMenu *Edit;
    QAction *New;
    QAction *Exit;
    QMenu *recentFile;
    QToolBar * tools;
    QFontComboBox *font;


};


#endif // MAINWINDOW

