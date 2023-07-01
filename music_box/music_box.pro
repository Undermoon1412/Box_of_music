QT       += core gui multimedia network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    downloadmusic.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    serchmusic.cpp \
    serchresult.cpp

HEADERS += \
    MusicBeans.h \
    downloadmusic.h \
    mainwindow.h \
    player.h \
    serchmusic.h \
    serchresult.h

FORMS += \
    downloadmusic.ui \
    mainwindow.ui \
    player.ui \
    serchmusic.ui \
    serchresult.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    res/iTunes.ico
