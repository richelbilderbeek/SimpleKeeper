CONFIG += qt console

#include(SimpleKeeper.pri)

INCLUDEPATH += ../STP/include ../STP/extlibs/headers
SOURCES += ../STP/src/STP/Core/*.*
SOURCES += ../STP/extlibs/pugixml/*.*

SOURCES += main_stp.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -Werror
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

LIBS += -lboost_unit_test_framework

# zlib
LIBS += -lz

LIBS += -lpugixml
