#-------------------------------------------------
#
# Project created by QtCreator 2019-11-24T11:53:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PERCEPTRON
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    charger.cpp \
    donnees.cpp \
    perceptron.cpp \
    verifie.cpp

HEADERS  += mainwindow.h \
    charger.h \
    donnees.h \
    perceptron.h \
    verifie.h

FORMS    += mainwindow.ui \
    charger.ui \
    donnees.ui \
    perceptron.ui \
    verifie.ui

DISTFILES +=

RESOURCES +=
