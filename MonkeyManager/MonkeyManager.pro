#-------------------------------------------------
#
# Project created by QtCreator 2016-10-14T13:55:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MonkeyManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    project.cpp \
    task.cpp \
    date.cpp \
    projectutils.cpp \
    taskwidget.cpp \
    taskdialog.cpp \
    projectlistmodel.cpp

HEADERS  += mainwindow.h \
    project.h \
    task.h \
    constants.h \
    date.h \
    projectutils.h \
    taskwidget.h \
    taskdialog.h \
    projectlistmodel.h

FORMS    += mainwindow.ui \
    taskwidget.ui \
    taskdialog.ui
