#-------------------------------------------------
#
# Project created by QtCreator 2017-09-07T17:34:44
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignUpPorject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    databaseconnection.cpp \
    sqlqueryexecute.cpp \
    informationshow.cpp

HEADERS  += mainwindow.h \
    databaseconnection.h \
    sqlqueryexecute.h \
    informationshow.h

FORMS    += mainwindow.ui \
    informationshow.ui
