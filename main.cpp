#include <cassert>
#include <iostream>
#include <vector>
#include <QFile>
#include <SFML/Graphics.hpp>

enum class tile {
  heart1, heart2,
  wall,
  empty
};

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
  sf::Texture empty_texture;
  if (!empty_texture.loadFromFile("../SimpleKeeper/Sprites/DungeonsAll.png", sf::IntRect(640,697,16,16)))
  {
    assert(!"Should not get here");
  }
  sf::Texture wall_texture;
  if (!wall_texture.loadFromFile("../SimpleKeeper/Sprites/DungeonsAll.png", sf::IntRect(659,678,16,16)))
  {
    assert(!"Should not get here");
  }

  for (int y{0}; y!=n_rows; ++y)
  {
    for (int x{0}; x!=n_cols; ++x)
    {
      sf::Sprite sprite;
      switch (s[y][x]) {
        case tile::empty: sprite.setTexture(empty_texture); break;
        case tile::wall: sprite.setTexture(wall_texture); break;
      }
      sprite.setScale(2.0,2.0);
      sprite.setPosition(x * block_width, y * block_height);
      w.draw(sprite);
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
  sf::RectangleShape r(sf::Vector2f(block_width - 1, block_height - 1));
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

  const int window_height{640};
  const int window_width{960};
  const int block_width{32};
  const int block_height{32};
  const int n_cols{window_width / block_width};
  const int n_rows{window_height / block_height};
  landscape my_landscape = create_landscape(n_cols, n_rows);
  cursor cursor1 = create_cursor1();
  cursor cursor2 = create_cursor2();
  sf::Texture sprite1_texture;
  if (!sprite1_texture.loadFromFile("../SimpleKeeper/Sprites/LinkRedFrontSmallShield1.png"))
  {
    assert(!"Should not get here");
  }
  sf::Texture sprite2_texture;
  if (!sprite2_texture.loadFromFile("../SimpleKeeper/Sprites/LinkBlueFrontSmallShield1.png"))
  {
    assert(!"Should not get here");
  }
  sf::Sprite sprite1;
  sprite1.setTexture(sprite1_texture);
  sprite1.setPosition(224, 320 + 32);
  sf::Sprite sprite2;
  sprite2.setTexture(sprite2_texture);
  sprite2.setPosition(672, 320 + 32);

  sf::Texture heart1_texture;
  if (!heart1_texture.loadFromFile("../SimpleKeeper/Sprites/TriforceGround1.png"))
  {
    assert(!"Should not get here");
  }
  sf::Texture heart2_texture;
  if (!heart2_texture.loadFromFile("../SimpleKeeper/Sprites/TriforceGround2.png"))
  {
    assert(!"Should not get here");
  }
  sf::Sprite heart1;
  heart1.setTexture(heart1_texture);
  heart1.setPosition(224, 320);
  sf::Sprite heart2;
  heart2.setTexture(heart2_texture);
  heart2.setPosition(672, 320);


  sf::RenderWindow window(
    sf::VideoMode(window_width, window_height),
    "SimpleKeeper",
    sf::Style::Titlebar | sf::Style::Close
  );
  while(window.isOpen())
  {
    sf::Clock clock;
    sf::Event event;

    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::MouseMoved:
        {
          //int mouse_x = event.mouseMove.x;
          //int mouse_y = event.mouseMove.y;
          break;
        }
        default:
          break;
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) cursor1.m_pos.x = (cursor1.m_pos.x + n_cols - 1) % n_cols;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) cursor1.m_pos.x = (cursor1.m_pos.x + n_cols + 1) % n_cols;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) cursor1.m_pos.y = (cursor1.m_pos.y + n_rows - 1) % n_rows;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) cursor1.m_pos.y = (cursor1.m_pos.y + n_rows + 1) % n_rows;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) cursor2.m_pos.x = (cursor2.m_pos.x + n_cols - 1) % n_cols;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) cursor2.m_pos.x = (cursor2.m_pos.x + n_cols + 1) % n_cols;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) cursor2.m_pos.y = (cursor2.m_pos.y + n_rows - 1) % n_rows;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) cursor2.m_pos.y = (cursor2.m_pos.y + n_rows + 1) % n_rows;

    window.clear();
    draw_landscape(window, my_landscape);
    draw_cursor(window, my_landscape, cursor1);
    draw_cursor(window, my_landscape, cursor2);
    window.draw(heart1);
    window.draw(heart2);
    window.draw(sprite1);
    window.draw(sprite2);
    window.display();
  }
}
