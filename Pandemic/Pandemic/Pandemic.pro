#-------------------------------------------------
#
# Project created by QtCreator 2013-10-29T10:48:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pandemic
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    View.cpp \
    Player.cpp \
    Model.cpp \
    Map.cpp \
    Hand.cpp \
    File.cpp \
    Deck.cpp \
    Controller.cpp \
    City.cpp \
    Card.cpp

HEADERS  += mainwindow.h \
    View.h \
    Player.h \
    Model.h \
    Map.h \
    Hand.h \
    File.h \
    Deck.h \
    Controller.h \
    City.h \
    Card.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    board.jpg

RESOURCES += \
    board.qrc
