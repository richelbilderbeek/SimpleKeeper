#ifndef CURSOR_H
#define CURSOR_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

struct landscape;
namespace sf { struct RenderWindow; }

struct cursor
{
  cursor() {}
  sf::Vector2i m_pos;
  sf::Color m_color;
};

cursor create_cursor1();
cursor create_cursor2();

void draw_cursor(sf::RenderWindow& w, const cursor& c);

#endif // CURSOR_H
