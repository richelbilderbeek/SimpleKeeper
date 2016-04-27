#include "monster.h"
#include "landscape.h"
#include "textures.h"
#include <SFML/Graphics/RenderWindow.hpp>

monster::monster(
  const monster_type type,
  const player master,
  const int x,
  const int y
) : m_dx{0},
    m_dy{0},
    m_master{master},
    m_sprite{},
    m_texture{texture_type::question_mark},
    m_type{type}
{
  m_sprite.setPosition(x, y);
  pick_new_direction();
}

void monster::draw(sf::RenderWindow& w, const textures& ts) const
{
  m_sprite.setTexture(ts.get(m_texture));
  w.draw(m_sprite);
}

bool has_direction(const monster& m) noexcept
{
  return m.dx() != 0 || m.dy() != 0;
}

void move(monster& m, const landscape& s)
{
  if (has_direction(m) && s.can_move(
      m.x() + m.dx(),
      m.y() + m.dy(),
      m.w(),
      m.h()
    )
  )
  {
    m.set_pos(m.x() + m.dx(), m.y() + m.dy());
    m.set_texture(
      get_other_texture_type(m.texture())
    );
  }
  else
  {
    m.pick_new_direction();
  }
}

void monster::pick_new_direction()
{
  m_dx = (std::rand() % 3) - 1;
  m_dy = (std::rand() % 3) - 1;
  m_texture = get_texture_type(m_type, m_master, m_dx, m_dy);
}

void monster::set_pos(const int x, const int y)
{
  m_sprite.setPosition(x,y);
}

void monster::set_texture(const texture_type t)
{
  m_texture = t;
}

int monster::x() const noexcept
{
  return m_sprite.getPosition().x;
}

int monster::y() const noexcept
{
  return m_sprite.getPosition().y;
}
