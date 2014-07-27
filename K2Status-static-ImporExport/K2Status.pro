#-------------------------------------------------
#
# Project created by QtCreator 2014-07-16T03:54:44
#
#-------------------------------------------------

QT       += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG  += static libstatic


TARGET = K2Status
TEMPLATE = app
QMAKE_CXXFLAGS += -Dlinux -D__i386 -D_LINUX -D_INTEL -D_USE_SCHED  -D_USE_PTHREADS -D_USE_TERMIOS
QMAKE_CFLAGS   += -g -D_REENTRANT -Dlinux -D__i386 -D_LINUX -D_INTEL -D_USE_SCHED  -D_USE_PTHREADS -D_USE_TERMIOS

SOURCES += main.cpp\
        k2status.cpp \
    config.cpp \
    defineandconnect.cpp \
    messagercv.cpp

HEADERS  += \
    config.h \
    defineandconnect.h \
    k2pktdef.h \
    k2info.h \
    ew_packet.h \
    byteswap.h \
    include/byteswap.h \
    include/ew_packet.h \
    include/k2info.h \
    include/k2pktdef.h \
    include/nkwhdrs.h \
    k2status.h \
    include/TableDef.h \
    messagercv.h

FORMS    += k2status.ui \
    defineandconnect.ui
