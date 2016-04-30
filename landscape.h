#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <vector>
#include <map>
#include "texture_type.h"
#include <SFML/Graphics/Color.hpp>
#include "attractiveness_grid.h"

struct textures;
namespace sf { struct RenderWindow; }

///The arena, also helps the monsters to navigate
class landscape
{
public:
  landscape(const int n_cols, const int n_rows);

  ///Can the sprite move here?
  bool can_move(const int x, const int y, const int w, const int h) const;

  void draw(sf::RenderWindow& w, const textures& ts) const;
  double get_attractiveness(const monster_type m, const player master, const int x, const int y) const noexcept;
  texture_type get_bottom(const int x, const int y) const;
  int get_selectedness(const int x, const int y) const;
  texture_type get_top(const int x, const int y) const;
  int get_n_cols() const noexcept;
  int get_n_rows() const noexcept;
  void set_selectedness(const int x, const int y, const int selectedness);
  void set_top(const int x, const int y, const texture_type t);
  void update_attractivenesses() noexcept;

private:
  std::map<monster_type, attractiveness_grid> m_attract_blue;
  std::map<monster_type, attractiveness_grid> m_attract_red;

  ///Tile at the bottom, that what will be left after mining or destruction of what is on it
  std::vector<std::vector<texture_type>> m_bottom;

  ///The selected tiles: 0: not, 1: by player 1, 2: by player 2
  std::vector<std::vector<int>> m_selected;

  ///Tile at the top, that what is on the bottom tile, that what can be mined or destroyed
  std::vector<std::vector<texture_type>> m_top;

};

///Convert the attractiveness (the tendency a monster is attracted to that square)
///to a nice color.
sf::Color attractiveness_to_color(const double a, const player master) noexcept;

#endif // LANDSCAPE_H
