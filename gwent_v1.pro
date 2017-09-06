#-------------------------------------------------
#
# Project created by QtCreator 2017-08-30T17:00:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gwent_v1
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    player.cpp \
    card.cpp \
    process.cpp \
    camp.cpp \
    rule.cpp \
    unseen_elder.cpp \
    angry_wolf.cpp \
    bekker_twisted_mirror.cpp \
    impenetrable_fog.cpp \
    sub_earth_elemental.cpp \
    biting_frost.cpp \
    dagon.cpp

HEADERS += \
        mainwindow.h \
    player.h \
    card.h \
    process.h \
    camp.h \
    rule.h \
    unseen_elder.h \
    angry_wolf.h \
    bekker_twisted_mirror.h \
    impenetrable_fog.h \
    sub_earth_elemental.h \
    biting_frost.h \
    dagon.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    img.qrc
