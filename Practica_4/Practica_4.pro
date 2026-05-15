TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Enrutador.cpp \
        Gestor.cpp \
        Red.cpp \
        main.cpp

HEADERS += \
    Enrutador.h \
    Gestor.h \
    Red.h

DISTFILES += \
    redes.txt
