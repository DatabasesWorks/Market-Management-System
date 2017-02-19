#-------------------------------------------------
#
# Project created by QtCreator 2017-02-09T12:57:49
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iMarket
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbhandler.cpp \
    authentication.cpp \
    managerform.cpp \
    itemregister.cpp \
    search.cpp \
    stockfrom.cpp \
    customerform.cpp \
    ikarketmap.cpp \
    customersearch.cpp \
    paying.cpp \
    custeval.cpp

HEADERS  += mainwindow.h \
    dbhandler.h \
    authentication.h \
    managerform.h \
    itemregister.h \
    search.h \
    stockfrom.h \
    customerform.h \
    ikarketmap.h \
    customersearch.h \
    paying.h \
    custeval.h

FORMS    += mainwindow.ui \
    authentication.ui \
    managerform.ui \
    itemregister.ui \
    search.ui \
    stockfrom.ui \
    customerform.ui \
    ikarketmap.ui \
    customersearch.ui \
    paying.ui \
    custeval.ui

RESOURCES += \
    resources.qrc

INCLUDEPATH += rapidjson
