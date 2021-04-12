QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bachelorparty.cpp \
    commercialfair.cpp \
    controller.cpp \
    date.cpp \
    event.cpp \
    eventcreator.cpp \
    eventviewer.cpp \
    inputdialog.cpp \
    main.cpp \
    marathon.cpp \
    marriage.cpp \
    modelevent.cpp \
    organization.cpp \
    ratingerror.cpp \
    sport.cpp \
    tournament.cpp \
    wedding.cpp

HEADERS += \
    TypeChurch.h \
    bachelorparty.h \
    commercialfair.h \
    company.h \
    container.h \
    controller.h \
    date.h \
    deepptr.h \
    event.h \
    eventcreator.h \
    eventviewer.h \
    inputdialog.h \
    marathon.h \
    marriage.h \
    modelevent.h \
    organization.h \
    ratingerror.h \
    sport.h \
    tournament.h \
    typesport.h \
    wedding.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
