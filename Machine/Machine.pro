QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adduser.cpp \
    authorization.cpp \
    infouser.cpp \
    machine.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowadmin.cpp \
    repair.cpp \
    repairs.cpp \
    settings.cpp \
    user.cpp

HEADERS += \
    adduser.h \
    authorization.h \
    infouser.h \
    machine.h \
    mainwindow.h \
    mainwindowadmin.h \
    repair.h \
    repairs.h \
    settings.h \
    user.h

FORMS += \
    adduser.ui \
    authorization.ui \
    infouser.ui \
    mainwindow.ui \
    mainwindowadmin.ui \
    registration.ui \
    repair.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
