#include <cassert>
#include <iostream>
#include <vector>
#include <QFile>
#include <SFML/Graphics.hpp>

enum class tile { wall, empty };
using landscape = std::vector<std::vector<tile>>;

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
      sf::RectangleShape r(sf::Vector2f(block_width, block_height));
      switch (s[y][x]) {
        case tile::empty: r.setFillColor(sf::Color::Black); break;
        case tile::wall: r.setFillColor(sf::Color::Red); break;
      }
      r.setPosition(x * block_width, y * block_height);
      w.draw(r);
    }
  }
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
    //window.draw(level_sprite);
    window.display();
  }
}
