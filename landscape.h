#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <vector>
#include "tile.h"

struct textures;
namespace sf { struct RenderWindow; }

///The arena
class landscape
{
public:
  landscape(const int n_cols, const int n_rows);
  tile get(const int x, const int y) const;
  int get_n_cols() const noexcept;
  int get_n_rows() const noexcept;


private:
  std::vector<std::vector<tile>> m_tiles;
};

void draw_landscape(sf::RenderWindow& w, const textures& ts, const landscape& s);

#endif // LANDSCAPE_H
