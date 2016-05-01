#ifndef MONSTER_H
#define MONSTER_H

#include <SFML/Graphics/Sprite.hpp>
#include "player.h"
#include "monster_type.h"
#include "texture_type.h"

struct textures;
struct landscape;
namespace sf { struct RenderWindow; }

/*!
   \brief The monster class
   Its
 */
class monster
{
public:
  monster(const monster_type type, const player master, const int x, const int y);
  void draw(sf::RenderWindow& w, const textures& ts) const;
  int dx() const noexcept { return m_dx; }
  int dy() const noexcept { return m_dy; }
  int h() const noexcept { return 32; }
  player master() const noexcept { return m_master; } //player it is loyal to
  //void pick_new_direction();
  void set_direction(const int dx, const int dy) noexcept;
  void set_pos(const int x, const int y);
  void set_texture(const texture_type t);
  texture_type texture() const noexcept { return m_texture; }
  monster_type type() const noexcept { return m_type; }
  int w() const noexcept { return 32; }
  int x() const noexcept;
  int y() const noexcept;
private:
  int m_dx;
  int m_dy;
  player m_master; //player it is loyal to
  mutable sf::Sprite m_sprite; //Will be updated at draw
  texture_type m_texture;
  monster_type m_type;
};

///Let monsters have their behaviors, e.g. mining
void behave(monster& m, landscape& s);
bool has_direction(const monster& m) noexcept;
void move(monster& m, const landscape& s);

#endif // MONSTER_H
