#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T13:52:27
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = SocketChat


TEMPLATE = app


SOURCES += main.cpp \
    hockevent.cpp \
    keysinput.cpp \
    curtains.cpp \
    letter.cpp \
    chat.cpp \
    screen.cpp \
    chatclient.cpp \
    mainwnd.cpp

HEADERS += \
    hockevent.h \
    keysinput.h \
    curtains.h \
    letter.h \
    chat.h \
    screen.h \
    chatclient.h \
    mainwnd.h

FORMS += \
    mainwnd.ui
