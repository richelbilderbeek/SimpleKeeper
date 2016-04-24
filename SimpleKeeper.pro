TEMPLATE = app
CONFIG += qt console
CONFIG -= app_bundle

SOURCES += main.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

RESOURCES += \
    SimpleKeeper.qrc
