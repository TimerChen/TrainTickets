#-------------------------------------------------
#
# Project created by QtCreator 2017-05-13T15:52:36
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_mapsavetesttest
CONFIG   += console
CONFIG   -= app_bundle

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


SOURCES += tst_mapsavetesttest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    include/algorithm0.hpp \
    include/database.h \
    include/database_main.h \
    include/datastream.h \
    include/exceptions.hpp \
    include/map.hpp \
    include/smartpoint.hpp \
    include/station.h \
    include/train.h \
    include/utility.hpp \
    include/vector.hpp
