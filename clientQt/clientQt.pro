#-------------------------------------------------
#
# Project created by QtCreator 2017-09-13T15:09:16
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = clientQt
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    client.cpp \
    clientchat.cpp

HEADERS += \
    client.h \
    clientchat.h

FORMS += \
    clientchat.ui
