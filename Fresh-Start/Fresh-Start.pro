#-------------------------------------------------
#
# Project created by QtCreator 2018-12-03T23:54:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fresh-Start
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    shape.cpp \
    line.cpp \
    polyline.cpp \
    polygon.cpp \
    ellipse.cpp \
    circle.cpp \
    rectangle.cpp \
    square.cpp \
    text.cpp \
    utilities.cpp \
    renderarea.cpp

HEADERS += \
        mainwindow.h \
    shape.h \
    line.h \
    polyline.h \
    polygon.h \
    ellipse.h \
    circle.h \
    rectangle.h \
    square.h \
    text.h \
    vector.h \
    renderarea.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    shapes.txt \
    originalShapes.txt

RESOURCES += \
    resource.qrc
