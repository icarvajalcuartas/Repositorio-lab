TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Archivo.cpp \
        Integracion.cpp \
        LZ78.cpp \
        OperacionB.cpp \
        RLE.cpp \
        main.cpp

HEADERS += \
    Archivo.h \
    Integracion.h \
    LZ78.h \
    OperacionB.h \
    RLE.h

DISTFILES += \
    compresionlz78.txt \
    compresionrle.txt \
    integrar.txt \
    resultado.txt
