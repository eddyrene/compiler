#-------------------------------------------------
#
# Project created by QtCreator 2016-09-22T12:23:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = compiler
TEMPLATE = app
CONFIG += c++11
SOURCES += main.cpp\
        mainwindow.cpp \
    compiler.cpp \
    lexer.cpp \
    symbols_table.cpp \
    automata.cpp

HEADERS  += mainwindow.h \
    compiler.h \
    lexer.h \
    symbols_table.h \
    automata.h

FORMS    += mainwindow.ui

DISTFILES += \
    resources/symbols_table.txt
