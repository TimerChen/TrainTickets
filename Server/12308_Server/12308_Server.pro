#-------------------------------------------------
#
# Project created by QtCreator 2017-04-30T11:01:52
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = 12308_Server
TEMPLATE = app

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        servermainwindow.cpp \
    src/database_base.cpp \
    src/database_main.cpp \
    clientthread.cpp \
    src/datastream.cpp \
    src/DataBase_User.cpp \
    src/DataBase_Account.cpp \
    toserverstructs.cpp \
    src/DataBase_Log.cpp \
    src/DataBase_Train.cpp

HEADERS  += servermainwindow.h \
    include/vector.hpp \
    include/utility.hpp \
    include/smartpoint.hpp \
    include/exceptions.hpp \
    include/database_main.h \
    include/algorithm0.hpp \
    clientthread.h \
    include/database.h \
    include/map.hpp \
    include/DataBase_Account.h \
    include/DataBase_User.h \
    include/datastream.h \
    toserverstructs.h \
    include/DataBase_Log.h \
    include/DataBase_Train.h

FORMS    += servermainwindow.ui

RESOURCES +=
