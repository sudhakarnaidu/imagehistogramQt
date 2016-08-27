#-------------------------------------------------
#
# Project created by QtCreator 2012-09-03T20:39:27
#
#-------------------------------------------------

QT       += core

TARGET = HistogramTool

CONFIG   += console core
CONFIG   -= app_bundle

SOURCES += main.cpp \
    ImageHistogram.cpp \
    UnitTest.cpp

HEADERS +=  ImageHistogram.h \
    UnitTest.h

#The below line is to be uncommented and provide Qtconcurrent lib file path
#if necessary include header path
#LIBS        += -L"H:/Qt/Qt5.6.0/5.6/msvc2015/lib" -lQt5Concurrent

TEMPLATE = app

# The below line is to be uncommented if unit testing is not required.
DEFINES += UNIT_TESTING

