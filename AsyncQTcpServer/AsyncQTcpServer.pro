#-------------------------------------------------
#
# Project created by QtCreator 2013-09-19T18:58:06
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = AsyncQTcpServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp \
    myclient.cpp

HEADERS += \
    myserver.h \
    myclient.h
