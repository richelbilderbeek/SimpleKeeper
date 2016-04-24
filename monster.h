#ifndef MONSTER_H
#define MONSTER_H

#include "player.h"
#include "monster_type.h"

struct monster
{
  monster_type m_type;
  player m_player; //player it is loyal to
};

#endif // MONSTER_H
