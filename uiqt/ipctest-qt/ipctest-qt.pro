#-------------------------------------------------
#
# Project created by QtCreator 2013-06-09T14:22:49
#
#-------------------------------------------------

CONFIG += debug

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

XMLLIB = `pkg-config --libs expat jsoncpp`


INCPATH += ../../libipctest
LIBS += -L../../libipctest -lipctest $$XMLLIB \
        -L../../../control-service/sockstr/src -lsockstr \
        -lssl -lcrypto


TARGET = ipctest-qt
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    messagesmodel.cpp

HEADERS  += MainWindow.h \
    messagesmodel.h

FORMS    += MainWindow.ui
