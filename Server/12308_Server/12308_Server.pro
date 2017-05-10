#-------------------------------------------------
#
# Project created by QtCreator 2017-04-30T11:01:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 12308_Server
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


SOURCES += main.cpp\
        servermainwindow.cpp \
    src_Timer/database_main.cpp \
    src_Timer/database_base.cpp

HEADERS  += servermainwindow.h \
    src_Timer/algorithm0.hpp \
    src_MW/vector.hpp \
    src_MW/smartpoint.hpp \
    src_MW/exceptions.hpp \
    src_Vegewong/DataBase_Log.hpp \
    src_Timer/DataBase.h \
    src_Timer/database_main.h

FORMS    += servermainwindow.ui \
    server.ui
