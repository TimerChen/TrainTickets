#-------------------------------------------------
#
# Project created by QtCreator 2017-04-30T10:11:03
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrainUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += C++11

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    regist.cpp \
    myticket.cpp \
    myinform.cpp \
    stationtostationsearch.cpp \
    trainsearch.cpp \
    stationsearch.cpp \
    searchticket.cpp \
    adminwindow.cpp \
    toserverstructs.cpp \
    uistructs.cpp \
    modifyplanofatrain.cpp \
    addplan.cpp \
    addplansimple.cpp \
    searchusr.cpp \
    editsearchusr.cpp \
    syslog.cpp

HEADERS  += mainwindow.h \
    login.h \
    regist.h \
    myticket.h \
    myinform.h \
    stationtostationsearch.h \
    trainsearch.h \
    stationsearch.h \
    searchticket.h \
    adminwindow.h \
    toserverstructs.h \
    uistructs.h \
    modifyplanofatrain.h \
    addplan.h \
    addplansimple.h \
    searchusr.h \
    editsearchusr.h \
    syslog.h

FORMS    += mainwindow.ui \
    login.ui \
    regist.ui \
    myticket.ui \
    myinform.ui \
    stationtostationsearch.ui \
    trainsearch.ui \
    stationsearch.ui \
    searchticket.ui \
    adminwindow.ui \
    modifyplanofatrain.ui \
    addplan.ui \
    addplansimple.ui \
    searchusr.ui \
    editsearchusr.ui \
    syslog.ui

RESOURCES += \
    pic.qrc \
    completer.qrc

DISTFILES +=
