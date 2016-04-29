# TEMPLATE = app
CONFIG += qt console
# CONFIG -= app_bundle

SOURCES += main.cpp \
    player.cpp \
    command.cpp \
    monster.cpp \
    monster_type.cpp \
    tile.cpp \
    landscape.cpp \
    cursor.cpp \
    game.cpp \
    textures.cpp \
    texture_type.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -Werror
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

RESOURCES += \
    SimpleKeeper.qrc

HEADERS += \
    player.h \
    command.h \
    monster.h \
    monster_type.h \
    tile.h \
    landscape.h \
    cursor.h \
    game.h \
    textures.h \
    texture_type.h


# Windows
#LIBS += -LC:/SFML/lib -LC:\SFML\bin
#INCLUDEPATH += C:/SFML/include
#DEPENDPATH += C:/SFML/include
#INCLUDEPATH += C:/Boost/include
#DEPENDPATH += C:/Boost/include
#INCLUDEPATH += C:/Boost
#LIBS += C:/Boost/stage/lib/libboost_filesystem-mgw49-mt-1_59.a
#LIBS += C:/Boost/stage/lib/libboost_system-mgw49-mt-d-1_59.a
