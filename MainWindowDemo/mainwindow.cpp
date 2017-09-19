
#include <QtGui>
#include "mainwindow.h"

MainWindow ::MainWindow()
{
    /*QWidget *widget = new QWidget;

    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;

    topFiller->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QWidget *bottomFiller = new QWidget;

    bottomFiller->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QVBoxLayout*layout = new QVBoxLayout;
    layout->addWidget(topFiller);
    layout->addWidget(bottomFiller);

    widget->setLayout(layout);

    setWindowTitle(tr("Main Window"));
    resize(512,480);
    */

    centralWidget = new QMdiArea;

    setCentralWidget(centralWidget);
    File = menuBar()->addMenu("&File");
    Edit = menuBar()->addMenu("&Edit");
    New = new QAction("New",this);
    Exit = new QAction("Exit",this);
    File->addAction(New);
    File->addAction(Exit);
    connect(Exit,SIGNAL(triggered()),qApp,SLOT(quit()));
    recentFile = File->addMenu("&recent file");
    recentFile->addAction("File1.txt");
    tools = addToolBar("File");

    New->setIcon(QIcon("C:/Users/Shubham/Documents/MainWindowDemo/new_icon.png"));
    Exit->setIcon(QIcon("C:/Users/Shubham/Documents/MainWindowDemo/exit_icon.jpg"));

    tools->addAction(New);
    tools->addAction(Exit);

    font = new QFontComboBox;

    tools->addWidget(font);
    tools->addSeparator();


}
