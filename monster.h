#ifndef MONSTER_H
#define MONSTER_H

#include <SFML/Graphics/Sprite.hpp>
#include "player.h"
#include "monster_type.h"
#include "texture_type.h"

struct textures;
namespace sf { struct RenderWindow; }

class monster
{
public:
  monster(const monster_type type, const player master, const int x, const int y);
  void draw(sf::RenderWindow& w, const textures& ts) const;
private:
  player m_master; //player it is loyal to
  mutable sf::Sprite m_sprite; //Will be updated at draw
  monster_type m_type;
};

#endif // MONSTER_H
