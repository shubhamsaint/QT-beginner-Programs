#-------------------------------------------------
#
# Project created by QtCreator 2017-09-14T15:30:20
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = QtLocalServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    form.cpp \
    localserver.cpp

FORMS += \
    form.ui

HEADERS += \
    form.h \
    localserver.h
