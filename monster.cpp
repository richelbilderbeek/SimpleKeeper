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
  set_direction(0,0);
  //pick_new_direction();
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
  const int block_x{m.x() / 32};
  const int block_y{m.y() / 32};
  const int block_x_left {(block_x - 1 + s.get_n_cols()) % s.get_n_cols()};
  const int block_x_right{(block_x + 1 + s.get_n_cols()) % s.get_n_cols()};
  const int block_y_above{(block_y - 1 + s.get_n_rows()) % s.get_n_rows()};
  const int block_y_below{(block_y + 1 + s.get_n_rows()) % s.get_n_rows()};
  const double a_here{s.get_attractiveness(m.type(), m.master(), block_x, block_y)};
  const double a_left{s.get_attractiveness(m.type(), m.master(), block_x_left, block_y)};
  const double a_right{s.get_attractiveness(m.type(), m.master(), block_x_right, block_y)};
  const double a_above{s.get_attractiveness(m.type(), m.master(), block_x, block_y_above)};
  const double a_below{s.get_attractiveness(m.type(), m.master(), block_x, block_y_below)};
  const int new_dx = a_right > a_here ? 1 : (a_left  > a_here ? -1 : 0);
  const int new_dy = a_below > a_here ? 1 : (a_above > a_here ? -1 : 0);
  if (m.dx() != new_dx || m.dy() != new_dy)
  {
    m.set_direction(new_dx, new_dy);
    return; //No movement
  }
  //Horizontal movement
  if (s.can_move(m.x() + m.dx(),
      m.y() + 0,
      m.w(),
      m.h()
    )
  )
  {
    m.set_pos(m.x() + m.dx(), m.y() + 0);
  }
  //Verical movement
  if (s.can_move(m.x() + 0,
      m.y() + m.dy(),
      m.w(),
      m.h()
    )
  )
  {
    m.set_pos(m.x() + 0, m.y() + m.dy());
  }
  m.set_texture(
    get_other_texture_type(m.texture())
  );
}

void monster::set_direction(const int dx, const int dy) noexcept
{
  m_dx = dx;
  m_dy = dy;
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
