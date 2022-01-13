include(../../Common.pri)

TARGET = SimpleShader
SOURCES += \
    asteroiden.cpp \
    asteroidgenerator.cpp \
    myscene.cpp \
    pausemenue.cpp \
    spaceship.cpp

RESOURCES += \
    MyShaders.qrc

HEADERS += \
    asteroiden.h \
    asteroidgenerator.h \
    pausemenue.h \
    spaceship.h

QT += quick

