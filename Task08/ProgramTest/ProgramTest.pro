#-------------------------------------------------
#
# Project created by QtCreator 2015-06-06T12:57:42
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = programtest
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

Debug {
  DEFINES += DEBUG
}

SOURCES += \
    main.cpp \
    ../*.cpp \
    ../../common/*.cpp \
    targetmock.cpp \
    test_deathstar.cpp \
    test_spaceship.cpp \
    test_planet.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    programtest.h \
    test_deathstar.h \
    test_planet.h \
    test_spaceship.h \
    targetmock.h \
    ../*.h \
    ../../common/*.h
