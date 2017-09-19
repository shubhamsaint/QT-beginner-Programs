#-------------------------------------------------
#
# Project created by QtCreator 2017-09-05T17:45:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    seconddialog.cpp \
    thirddialog.cpp

HEADERS  += mainwindow.h \
    seconddialog.h \
    thirddialog.h

FORMS    += mainwindow.ui \
    seconddialog.ui \
    thirddialog.ui

RESOURCES += \
    resources.qrc
