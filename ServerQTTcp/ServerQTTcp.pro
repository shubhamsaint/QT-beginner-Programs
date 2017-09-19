#-------------------------------------------------
#
# Project created by QtCreator 2017-09-14T17:01:42
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ServerQTTcp
TEMPLATE = app


SOURCES += main.cpp\
        myserver.cpp \
    serverlistener.cpp

HEADERS  += myserver.h \
    serverlistener.h

FORMS    += myserver.ui
