#-------------------------------------------------
#
# Project created by QtCreator 2017-09-14T16:43:19
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClientServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myclient.cpp

HEADERS  += mainwindow.h \
    myclient.h

FORMS    += mainwindow.ui
