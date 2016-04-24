#include "cursor.h"
#include "landscape.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

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

void draw_cursor(sf::RenderWindow& w, const cursor& c)
{
  const float block_width  = 32;
  const float block_height = 32;
  sf::RectangleShape r(sf::Vector2f(block_width - 1, block_height - 1));
  r.setFillColor(sf::Color::Transparent);
  r.setOutlineColor(c.m_color);
  r.setOutlineThickness(2.0);
  const int x = c.m_pos.x;
  const int y = c.m_pos.y;
  r.setPosition(x * block_width, y * block_height);
  w.draw(r);
}
