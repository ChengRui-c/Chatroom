#-------------------------------------------------
#
# Project created by QtCreator 2016-06-29T20:51:57
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT+=widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = my_char
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

RESOURCES += \
    pic.qrc
