#-------------------------------------------------
#
# Project created by QtCreator 2014-01-25T20:15:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KAuth
TEMPLATE = app


SOURCES += main.cpp\
    OpenSSL.cpp \
    Kauth.cpp

HEADERS  += \
    OpenSSL.h \
    Kauth.h \
    include/Kauth.h \
    include/OpenSSL.h

FORMS    += \
    mainwindow.ui
