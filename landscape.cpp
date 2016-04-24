#include "landscape.h"

#include <cassert>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "textures.h"

landscape::landscape(const int n_cols, const int n_rows)
  : m_bottom(n_rows, std::vector<texture_type>(n_cols)),
    m_top(n_rows, std::vector<texture_type>(n_cols))
{
  for (int y{0}; y!=n_rows; ++y)
  {
    for (int x{0}; x!=n_cols; ++x)
    {
      m_top[y][x] = texture_type::wall;
      m_bottom[y][x] = texture_type::floor;
    }
  }
  for (int y{0}; y!=5; ++y)
  {
    for (int x{0}; x!=5; ++x)
    {
      m_top[(n_rows / 2) - 2 + y][ (1 * (n_cols / 4)) - 2 + x] = texture_type::empty;
      m_top[(n_rows / 2) - 2 + y][ (3 * (n_cols / 4)) - 2 + x] = texture_type::empty;
    }
  }
  m_top[(n_rows / 2) ][ (1 * (n_cols / 4))] = texture_type::heart_red;
  m_top[(n_rows / 2) ][ (3 * (n_cols / 4))] = texture_type::heart_blue;

}

bool landscape::can_move(const int x, const int y, const int w, const int h)
{
  const int block_left = x / 32;
  const int block_right = (x + w) / 32;
  const int block_top = y / 32;
  const int block_bottom = (y + h) / 32;
  return
       get_top(block_left , block_top   ) == texture_type::empty
    && get_top(block_left , block_bottom) == texture_type::empty
    && get_top(block_right, block_top   ) == texture_type::empty
    && get_top(block_right, block_bottom) == texture_type::empty
  ;
}


void landscape::draw(sf::RenderWindow& w, const textures& ts)
{
  const int n_rows = get_n_rows();
  const int n_cols = get_n_cols();
  const float block_width  = w.getSize().x / n_cols;
  const float block_height = w.getSize().y / n_rows;

  //Draw bottom
  for (int y{0}; y!=n_rows; ++y)
  {
    for (int x{0}; x!=n_cols; ++x)
    {
      const auto t = get_bottom(x,y);
      sf::Sprite sprite;
      sprite.setTexture(ts.get(t));
      if (is_small(t)) { sprite.setScale(2.0,2.0); }
      sprite.setPosition(x * block_width, y * block_height);
      w.draw(sprite);
    }
  }

  //Draw top
  for (int y{0}; y!=n_rows; ++y)
  {
    for (int x{0}; x!=n_cols; ++x)
    {
      const auto t = get_top(x,y);
      if (t == texture_type::empty) continue;
      sf::Sprite sprite;
      sprite.setTexture(ts.get(t));
      if (is_small(t)) { sprite.setScale(2.0,2.0); }
      sprite.setPosition(x * block_width, y * block_height);
      w.draw(sprite);
    }
  }
}

texture_type landscape::get_bottom(const int x, const int y) const
{
  assert(y >= 0);
  assert(y < static_cast<int>(m_bottom.size()));
  assert(x >= 0);
  assert(x < static_cast<int>(m_bottom[y].size()));
  return m_bottom[y][x];
}

texture_type landscape::get_top(const int x, const int y) const
{
  assert(y >= 0);
  assert(y < static_cast<int>(m_top.size()));
  assert(x >= 0);
  assert(x < static_cast<int>(m_top[y].size()));
  return m_top[y][x];
}


int landscape::get_n_cols() const noexcept
{
  assert(get_n_rows() > 0);
  return static_cast<int>(m_bottom[0].size());
}

int landscape::get_n_rows() const noexcept
{
  return static_cast<int>(m_bottom.size());
}
