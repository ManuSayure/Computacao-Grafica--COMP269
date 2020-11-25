#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T18:53:20
#
#-------------------------------------------------

QT       += core gui
QT       +=opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opengl02
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    widgetopengl.cpp

HEADERS  += mainwindow.h \
    widgetopengl.h

FORMS    += mainwindow.ui
LIBS += -lOpengl32
