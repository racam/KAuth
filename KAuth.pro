#-------------------------------------------------
#
# Project created by QtCreator 2014-01-25T20:15:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KAuth
TEMPLATE = app

SOURCES += src/main.cpp\
    src/OpenSSL.cpp \
    src/Kauth.cpp

HEADERS  += \
    src/Kauth.h \
    src/OpenSSL.h

FORMS    += \
    src/mainwindow.ui
