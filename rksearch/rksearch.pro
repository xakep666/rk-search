#-------------------------------------------------
#
# Project created by QtCreator 2016-12-11T18:06:42
#
#-------------------------------------------------

QT       -= gui

TARGET = rksearch
TEMPLATE = lib

DEFINES += RKSEARCH_LIBRARY

SOURCES += rksearch.cpp

HEADERS += rksearch.h\
        rksearch_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
