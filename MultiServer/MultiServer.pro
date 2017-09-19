#-------------------------------------------------
#
# Project created by QtCreator 2017-09-14T13:23:36
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = MultiServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp \
    mythread.cpp

HEADERS += \
    myserver.h \
    mythread.h
