#-------------------------------------------------
#
# Project created by QtCreator 2019-07-17T19:38:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = widgets-app
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
        mainwindow.cpp \
    mybutton.cpp \
    qswitchbutton.cpp \
    mybutton2.cpp \
    littlebutton.cpp \
    mycombobox.cpp \
    myvirtualkeyboard.cpp \
    formvirtualkeyboard.cpp \
    formbutton.cpp \
    formbutton2.cpp \
    formfrequencyspectrum.cpp

HEADERS  += mainwindow.h \
    mybutton.h \
    qswitchbutton.h \
    mybutton2.h \
    littlebutton.h \
    mycombobox.h \
    myvirtualkeyboard.h \
    formvirtualkeyboard.h \
    formbutton.h \
    formbutton2.h \
    formfrequencyspectrum.h

FORMS    += mainwindow.ui \
    formvirtualkeyboard.ui \
    formbutton.ui \
    formbutton2.ui \
    formfrequencyspectrum.ui

RESOURCES += \
    image/image.qrc
