#-------------------------------------------------
#
# Project created by QtCreator 2015-11-29T12:09:58
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = proto
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    nvm.cpp \
    observer.cpp \
    observable.cpp \
    nvmbit.cpp \
    propertydata.cpp \
    onebitpropertydata.cpp \
    twobitpropertydata.cpp \
    nvmdata.cpp \
    range.cpp \
    nvmrange.cpp \
    rangemanager.cpp \
    properties/property.cpp \
    properties/boolproperty.cpp

HEADERS += \
    nvm.h \
    observer.h \
    observable.h \
    nvmbit.h \
    propertydata.h \
    onebitpropertydata.h \
    twobitpropertydata.h \
    nvmdata.h \
    range.h \
    nvmrange.h \
    rangemanager.h \
    properties/property.h \
    properties/boolproperty.h
