#include "landscape.h"

#include <cassert>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "textures.h"

landscape::landscape(const int n_cols, const int n_rows)
  : m_attract_blue{},
    m_attract_red{},
    m_bottom(n_rows, std::vector<texture_type>(n_cols)),
    m_selected(n_rows, std::vector<int>(n_cols, 0)),
    m_top(n_rows, std::vector<texture_type>(n_cols))
{
  //Initialize bottom and top grid
  for (int y{0}; y!=n_rows; ++y)
  {
    for (int x{0}; x!=n_cols; ++x)
    {
      m_top[y][x] = texture_type::wall1;
      m_bottom[y][x] = texture_type::floor1;
    }
  }
  /*
  //Create room for dungeon hearts
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
  */

  //Initialize attractiveness grids
  {
    attractiveness_grid g = create_attractiveness_grid(n_cols, n_rows, 0);
    m_attract_blue.insert(std::make_pair(monster_type::imp, g));
    m_attract_red.insert(std::make_pair(monster_type::imp, g));
  }
}

sf::Color attractiveness_to_color(const double a, const player master) noexcept
{
  if (master == player::blue)
  {
    //Blue: attracted
    if (a > 0.01) {
      const int blue = std::min(static_cast<int>(a * 255.0), 255);
      return sf::Color(0,0,blue,128);
    }
    //Blue + green: repulsed
    if (a < -0.01) {
      const int blue = std::min(static_cast<int>(-a * 255.0), 255);
      return sf::Color(0,blue,blue,128);
    }
  }
  else
  {
    assert(master == player::red);
    //Red: attracted
    if (a > 0.01) {
      const int red = std::min(static_cast<int>(a * 255.0), 255);
      return sf::Color(red,0,0,128);
    }
    //Red + green: repulsed
    if (a < -0.01) {
      const int red = std::min(static_cast<int>(-a * 255.0), 255);
      return sf::Color(red,red,0,128);
    }
  }
  return sf::Color(128,128,128,128);
}

bool landscape::can_move(const int x, const int y, const int w, const int h) const
{
  const int block_left = (x + w - 31) / 32;
  const int block_right = (x + w - 1) / 32;
  const int block_top = (y + h - 16) / 32; // -16: only feet (at lower half) are important
  const int block_bottom = (y + h - 1) / 32;
  return
       get_top(block_left , block_top   ) == texture_type::empty
    && get_top(block_left , block_bottom) == texture_type::empty
    && get_top(block_right, block_top   ) == texture_type::empty
    && get_top(block_right, block_bottom) == texture_type::empty
  ;
}

std::vector<grid_coordinat> landscape::collect_selected(const player p) const noexcept
{
  const int n_rows = get_n_rows();
  const int n_cols = get_n_cols();
  std::vector<grid_coordinat> v;

  //Draw bottom
  for (int y{0}; y!=n_rows; ++y)
  {
    for (int x{0}; x!=n_cols; ++x)
    {
      if (is_selected(x, y, p))
      {
        v.push_back(create_grid_coordinat(x,y));
      }
    }
  }
  return v;
}


void landscape::draw(sf::RenderWindow& w, const textures& ts) const
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
      sprite.setPosition(x * block_width, y * block_height);
      w.draw(sprite);
    }
  }
  //Draw fairy dust (the tendency monsters are attracted to a square)
  if ("draw imp attractivenss grids")
  {
    for (const auto master: { player::blue, player::red })
    {
      for (int y{0}; y!=n_rows; ++y)
      {
        for (int x{0}; x!=n_cols; ++x)
        {
          const double a = get_attractiveness(monster_type::imp, master, x, y);
          sf::RectangleShape s(sf::Vector2f(32,32));
          s.setPosition(x * block_width, y * block_height);
          const sf::Color c = attractiveness_to_color(a, master);
          s.setFillColor(c);
          w.draw(s);
        }
      }
    }
  }
  //Draw selected
  sf::RectangleShape red(sf::Vector2f(32,32));
  red.setFillColor(sf::Color(255,0,0,128));
  sf::RectangleShape blue(sf::Vector2f(32,32));
  blue.setFillColor(sf::Color(0,0,255,128));
  for (int y{0}; y!=n_rows; ++y)
  {
    for (int x{0}; x!=n_cols; ++x)
    {
      const auto top = get_top(x,y);
      if (top != texture_type::wall1) continue;

      const auto t = get_selectedness(x,y);
      if (t == 0) continue;
      if (t & 1)
      {
        red.setPosition(x * block_width, y * block_height);
        w.draw(red);
      }
      if (t & 2)
      {
        blue.setPosition(x * block_width, y * block_height);
        w.draw(blue);
      }
    }
  }
}

double landscape::get_attractiveness(
  const monster_type m,
  const player master,
  const int x,
  const int y
) const noexcept
{
  assert(m == monster_type::imp);
  const auto& ags = master == player::blue ? m_attract_blue : m_attract_red;
  assert(ags.find(m) != ags.end());
  const auto& g = (*ags.find(m)).second;
  assert(y >= 0);
  assert(y < static_cast<int>(g.size()));
  assert(x >= 0);
  assert(x < static_cast<int>(g[y].size()));
  return g[y][x];
}

texture_type landscape::get_bottom(const int col, const int row) const
{
  assert(row >= 0);
  assert(row < static_cast<int>(m_bottom.size()));
  assert(col >= 0);
  assert(col < static_cast<int>(m_bottom[row].size()));
  return m_bottom[row][col];
}

int landscape::get_selectedness(const int col, const int row) const
{
  assert(row >= 0);
  assert(row < static_cast<int>(m_selected.size()));
  assert(col >= 0);
  assert(col < static_cast<int>(m_selected[row].size()));
  return m_selected[row][col];
}

texture_type landscape::get_top(const grid_coordinat& c) const
{
  return get_top(get_x(c), get_y(c));
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

bool landscape::is_selected(const grid_coordinat& c, const player p) const
{
  return is_selected(get_x(c), get_y(c), p);
}

bool landscape::is_selected(const int x, const int y, const player p) const
{
  assert(y >= 0);
  assert(y < static_cast<int>(m_selected.size()));
  assert(x >= 0);
  assert(x < static_cast<int>(m_selected[y].size()));
  const auto s = m_selected[y][x];
  return s & (p == player::red ? 1 : 2);
}

void landscape::set_selectedness(const int x, const int y, const int selectedness)
{
  assert(y >= 0);
  assert(y < static_cast<int>(m_selected.size()));
  assert(x >= 0);
  assert(x < static_cast<int>(m_selected[y].size()));
  assert(selectedness >= 0);
  assert(selectedness <= 2);
  if (selectedness == 0) { m_selected[y][x] = 0; }
  else {
    m_selected[y][x] = m_selected[y][x] | selectedness;
  }
}

void landscape::set_top(const int x, const int y, const texture_type t)
{
  assert(y >= 0);
  assert(y < static_cast<int>(m_selected.size()));
  assert(x >= 0);
  assert(x < static_cast<int>(m_selected[y].size()));
  m_top[y][x] = t;
}

void landscape::update_attractivenesses() noexcept
{
  //Imps
  for (const auto p: { player::blue, player::red })
  {
    std::vector<grid_coordinat> todo = collect_selected(p); //Coordinats to check
    const int initial_value{-1 * get_n_cols() * get_n_rows()};
    assert(initial_value < 0);
    const int n_cols{get_n_cols()};
    const int n_rows{get_n_rows()};
    attractiveness_grid g = create_attractiveness_grid(n_cols, n_rows, initial_value);
    int a = 255; //attractiveness
    while (!todo.empty())
    {
      //Find the adjacent squares that are not walls
      std::vector<grid_coordinat> new_todos;
      for (const auto c: todo)
      {
        //Check all neighbors 'd'
        for (const auto d: { get_above(c, n_rows), get_right(c, n_rows), get_below(c, n_rows), get_left(c, n_rows)})
        {
          if (get_top(d) == texture_type::empty && get_grid_cell(g, d) < a) { new_todos.push_back(d); }
        }
      }
      //Replace the old by the new TODO's
      todo = new_todos;
      //Set the attractivenesses of the current todo's
      for (const auto c: todo)
      {

        assert(get_y(c) >= 0 && get_y(c) < static_cast<int>(g.size()));
        assert(get_x(c) >= 0 && get_x(c) < static_cast<int>(g[get_y(c)].size()));
        g[get_y(c)][get_x(c)] = a;
      }
      --a;
    }
    auto& prev_g = (*(p == player::blue ? m_attract_blue : m_attract_red).find(monster_type::imp)).second;
    prev_g = g;
  }
}
