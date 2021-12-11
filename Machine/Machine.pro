QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adduser.cpp \
    authorization.cpp \
    checkinfo.cpp \
    infouser.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowadmin.cpp \
    registration.cpp \
    repair.cpp \
    setrole.cpp \
    settings.cpp

HEADERS += \
    adduser.h \
    authorization.h \
    checkinfo.h \
    infouser.h \
    mainwindow.h \
    mainwindowadmin.h \
    registration.h \
    repair.h \
    setrole.h \
    settings.h

FORMS += \
    adduser.ui \
    authorization.ui \
    checkinfo.ui \
    infouser.ui \
    mainwindow.ui \
    mainwindowadmin.ui \
    registration.ui \
    repair.ui \
    setrole.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
