#-------------------------------------------------
#
# Project created by QtCreator 2017-09-13T18:27:14
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qtserver.cpp

HEADERS  += mainwindow.h \
    qtserver.h

FORMS    += mainwindow.ui
