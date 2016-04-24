#include "landscape.h"

#include <cassert>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "textures.h"

landscape::landscape(const int n_cols, const int n_rows)
  : m_tiles(n_rows, std::vector<tile>(n_cols))
{
  for (int y{0}; y!=n_rows; ++y)
  {
    for (int x{0}; x!=n_cols; ++x)
    {
      m_tiles[y][x] = tile::wall;
    }
  }
  for (int y{0}; y!=5; ++y)
  {
    for (int x{0}; x!=5; ++x)
    {
      m_tiles[(n_rows / 2) - 2 + y][ (1 * (n_cols / 4)) - 2 + x] = tile::empty;
      m_tiles[(n_rows / 2) - 2 + y][ (3 * (n_cols / 4)) - 2 + x] = tile::empty;
    }
  }
}

void draw_landscape(sf::RenderWindow& w, const textures& ts, const landscape& s)
{
  const int n_rows = s.get_n_rows();
  const int n_cols = s.get_n_cols();
  const float block_width  = w.getSize().x / n_cols;
  const float block_height = w.getSize().y / n_rows;
  sf::Texture empty_texture = ts.get(texture_type::empty);
  sf::Texture wall_texture = ts.get(texture_type::wall);

  for (int y{0}; y!=n_rows; ++y)
  {
    for (int x{0}; x!=n_cols; ++x)
    {
      sf::Sprite sprite;
      switch (s.get(x,y)) {
        case tile::empty: sprite.setTexture(empty_texture); break;
        case tile::wall: sprite.setTexture(wall_texture); break;
        default: break;
      }
      sprite.setScale(2.0,2.0);
      sprite.setPosition(x * block_width, y * block_height);
      w.draw(sprite);
    }
  }
}

tile landscape::get(const int x, const int y) const
{
  assert(y >= 0);
  assert(y < static_cast<int>(m_tiles.size()));
  assert(x >= 0);
  assert(x < static_cast<int>(m_tiles[y].size()));
  return m_tiles[y][x];
}


int landscape::get_n_cols() const noexcept
{
  assert(get_n_rows() > 0);
  return static_cast<int>(m_tiles[0].size());
}

int landscape::get_n_rows() const noexcept
{
  return static_cast<int>(m_tiles.size());
}
