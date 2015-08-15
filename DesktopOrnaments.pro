#-------------------------------------------------
#
# Project created by QtCreator 2015-08-12T17:31:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DesktopOrnaments
TEMPLATE = app


SOURCES += main.cpp\
        ornaments.cpp \
    clock.cpp \
    calendar.cpp

HEADERS  += ornaments.h \
    clock.h \
    calendar.h

RESOURCES += \
    pictures.qrc

RC_ICONS = icon.ico

