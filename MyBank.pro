#-------------------------------------------------
#
# Project created by QtCreator 2020-06-29T07:40:33
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyBank
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    Core/Account.cpp \
    Core/AccountManager.cpp \
    Core/dbmanager.cpp \
    Core/User.cpp \
    Core/UserManager.cpp \
    Ui/loginscreen.cpp \
    Ui/mainappwindow.cpp \

HEADERS += \
    Core/Account.h \
    Core/AccountManager.h \
    Core/dbmanager.h \
    Core/User.h \
    Core/UserManager.h \
    Ui/loginscreen.h \
    Ui/mainappwindow.h

FORMS += \
    Ui/loginscreen.ui \
    Ui/mainappwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    MyBank.pro

