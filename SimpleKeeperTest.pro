CONFIG += qt console

include(SimpleKeeper.pri)
include(SimpleKeeperTest.pri)

SOURCES += main_test.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -Werror
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

LIBS += -lboost_unit_test_framework

# Windows
#LIBS += -LC:/SFML/lib -LC:\SFML\bin
#INCLUDEPATH += C:/SFML/include
#DEPENDPATH += C:/SFML/include
#INCLUDEPATH += C:/Boost/include
#DEPENDPATH += C:/Boost/include
#INCLUDEPATH += C:/Boost
#LIBS += C:/Boost/stage/lib/libboost_filesystem-mgw49-mt-1_59.a
#LIBS += C:/Boost/stage/lib/libboost_system-mgw49-mt-d-1_59.a
