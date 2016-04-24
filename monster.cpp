#include "monster.h"
#include "textures.h"
#include <SFML/Graphics/RenderWindow.hpp>

monster::monster(const monster_type type, const player master, const int x, const int y)
  : m_dx{0},
    m_dy{0},
    m_master{master},
    m_sprite{},
    m_type{type}
{
  m_sprite.setPosition(x, y);
}

void monster::draw(sf::RenderWindow& w, const textures& ts) const
{
  if (m_type == monster_type::imp) {
    if (m_master == player::red) { m_sprite.setTexture(ts.get(texture_type::imp_red_front_1)); }
    if (m_master == player::blue) { m_sprite.setTexture(ts.get(texture_type::imp_blue_front_1)); }
  }

  w.draw(m_sprite);
}

bool has_direction(const monster& m) noexcept
{
  return m.dx() != 0 || m.dy() != 0;
}

void monster::pick_new_direction()
{
  m_dx = (std::rand() % 3) - 1;
  m_dy = (std::rand() % 3) - 1;
}

void monster::set_pos(const int x, const int y)
{
  m_sprite.setPosition(x,y);
}

int monster::x() const noexcept
{
  return m_sprite.getPosition().x;
}

int monster::y() const noexcept
{
  return m_sprite.getPosition().y;
}
