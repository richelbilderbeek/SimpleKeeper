CONFIG += qt console

#include(SimpleKeeper.pri)

INCLUDEPATH += $$PWD/../tmxparser/src
INCLUDEPATH += $$PWD/../tmxparser/build
HEADERS += $$PWD/../tmxparser/src/*.h
HEADERS += $$PWD/../tmxparser/build/*.h
SOURCES += $$PWD/../tmxparser/src/*.cpp
SOURCES += $$PWD/../tmxparser/src/base64/*.cpp
#LIBS += $$PWD/../tmxparser/build/libtmxparser
SOURCES += main_tmxparser.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -Werror
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

LIBS += -lboost_unit_test_framework

# zlib
LIBS += -lz

LIBS += -ltinyxml2

#INCLUDEPATH += /usr/local/include/tmxparser
#LIBS += -ltmxparser
