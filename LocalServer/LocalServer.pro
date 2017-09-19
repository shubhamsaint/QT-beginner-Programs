#-------------------------------------------------
#
# Project created by QtCreator 2017-09-14T15:19:51
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LocalServer
TEMPLATE = app


SOURCES += main.cpp\
        widgets.cpp \
    localserver.cpp

HEADERS  += widgets.h \
    localserver.h

FORMS    += widgets.ui
