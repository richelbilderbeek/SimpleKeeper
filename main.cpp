#include <cassert>
#include <iostream>
#include <vector>
#include <QFile>
#include <SFML/Graphics.hpp>

enum class tile { wall, empty };
using landscape = std::vector<std::vector<tile>>;

struct cursor
{
  sf::Vector2i m_pos;
  sf::Color m_color;
};

cursor create_cursor1()
{
  cursor c;
  c.m_pos = sf::Vector2i(7,10);
  c.m_color = sf::Color::Red;
  return c;
}

cursor create_cursor2()
{
  cursor c;
  c.m_pos = sf::Vector2i(21,10);
  c.m_color = sf::Color::Blue;
  return c;
}

landscape create_landscape(const int n_cols, const int n_rows)
{
  landscape m(
    n_rows,
    std::vector<tile>(n_cols)
  );
  for (int y{0}; y!=n_rows; ++y)
  {
    for (int x{0}; x!=n_cols; ++x)
    {
      m[y][x] = tile::wall;
    }
  }
  for (int y{0}; y!=3; ++y)
  {
    for (int x{0}; x!=3; ++x)
    {
      m[(n_rows / 2) - 1 + y][ (1 * (n_cols / 4)) - 1 + x] = tile::empty;
      m[(n_rows / 2) - 1 + y][ (3 * (n_cols / 4)) - 1 + x] = tile::empty;
    }
  }

  return m;
}

void draw_landscape(sf::RenderWindow& w, const landscape& s)
{
  const int n_rows = static_cast<int>(s.size());
  if (n_rows == 0) return;
  const int n_cols = static_cast<int>(s.front().size());
  if (n_cols == 0) return;
  const float block_width  = w.getSize().x / n_cols;
  const float block_height = w.getSize().y / n_rows;

  for (int y{0}; y!=n_rows; ++y)
  {
    for (int x{0}; x!=n_cols; ++x)
    {
      sf::RectangleShape r(sf::Vector2f(block_width - 1, block_height - 1));
      switch (s[y][x]) {
        case tile::empty: r.setFillColor(sf::Color::Black); break;
        case tile::wall: r.setFillColor(sf::Color::Green); break;
      }
      r.setOutlineColor(sf::Color::Black);
      r.setOutlineThickness(0.5);
      r.setPosition(x * block_width, y * block_height);
      w.draw(r);
    }
  }
}

void draw_cursor(sf::RenderWindow& w, const landscape& s, const cursor& c)
{
  const int n_rows = static_cast<int>(s.size());
  if (n_rows == 0) return;
  const int n_cols = static_cast<int>(s.front().size());
  if (n_cols == 0) return;
  const float block_width  = w.getSize().x / n_cols;
  const float block_height = w.getSize().y / n_rows;
  sf::RectangleShape r(sf::Vector2f(block_width, block_height));
  r.setFillColor(sf::Color::Transparent);
  r.setOutlineColor(c.m_color);
  r.setOutlineThickness(2.0);
  const int x = c.m_pos.x;
  const int y = c.m_pos.y;
  r.setPosition(x * block_width, y * block_height);
  w.draw(r);
}


int main()
{

  const int window_height = 640;
  const int window_width = 960;
  const int block_width{32};
  const int block_height{32};
  landscape my_landscape = create_landscape(
    window_width / block_width,
    window_height / block_height
  );
  cursor cursor1 = create_cursor1();
  cursor cursor2 = create_cursor2();
  sf::Texture sprite1;
  if (!sprite1.loadFromFile("../SimpleKeeper/LinkRedFrontSmallShield1.png"))
  {
    assert(!"Should not get here");
  }
  sf::Texture sprite2;
  if (!sprite2.loadFromFile("../SimpleKeeper/LinkBlueFrontSmallShield1.png"))
  {
    assert(!"Should not get here");
  }



  sf::RenderWindow window(
    sf::VideoMode(window_width, window_height),
    "SimpleKeeper",
    sf::Style::Titlebar | sf::Style::Close
  );
  while(window.isOpen())
  {
    sf::Event event;

    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case::sf::Event::Closed:
          window.close();
          break;
        case::sf::Event::MouseMoved:
        {
          //int mouse_x = event.mouseMove.x;
          //int mouse_y = event.mouseMove.y;
          break;
        }
        default:
          break;
      }
    }
    window.clear();
    draw_landscape(window, my_landscape);
    draw_cursor(window, my_landscape, cursor1);
    draw_cursor(window, my_landscape, cursor2);
    window.display();
  }
}
