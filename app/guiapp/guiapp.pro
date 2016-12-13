#-------------------------------------------------
#
# Project created by QtCreator 2016-12-11T19:52:49
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT+= widgets

TARGET = guiapp
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    AnswerComparator.cpp \
    TestFileParser.cpp \
    TestSetWithAnswer.cpp \
    Timer.cpp \
    searchform.cpp

HEADERS  += mainwindow.h \
    AnswerComparator.h \
    TestFileParser.h \
    TestSetWithAnswer.h \
    Timer.h \
    searchform.h

FORMS    += mainwindow.ui \
    searchform.ui

unix:!macx: LIBS += -L$$OUT_PWD/RkSearchLibrary/ -lRkSearchLibrary

INCLUDEPATH += $$PWD/RkSearchLibrary
DEPENDPATH += $$PWD/RkSearchLibrary

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/qcustomplot/release/ -lqcustomplotd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/qcustomplot/debug/ -lqcustomplotd
else:unix: LIBS += -L$$OUT_PWD/qcustomplot/ -lqcustomplotd

INCLUDEPATH += $$PWD/qcustomplot
DEPENDPATH += $$PWD/qcustomplot
