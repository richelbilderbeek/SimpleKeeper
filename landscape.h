#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <vector>
#include "texture_type.h"

struct textures;
namespace sf { struct RenderWindow; }

///The arena
class landscape
{
public:
  landscape(const int n_cols, const int n_rows);
  void draw(sf::RenderWindow& w, const textures& ts);
  texture_type get_bottom(const int x, const int y) const;
  texture_type get_top(const int x, const int y) const;
  int get_n_cols() const noexcept;
  int get_n_rows() const noexcept;


private:
  ///Tile at the bottom, that what will be left after mining or destruction of what is on it
  std::vector<std::vector<texture_type>> m_bottom;

  ///Tile at the top, that what is on the bottom tile, that what can be mined or destroyed
  std::vector<std::vector<texture_type>> m_top;
};


#endif // LANDSCAPE_H
