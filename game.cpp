#include "game.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

game::game(const int window_width, const int window_height)
  : m_commands{},
    m_cursor1{create_cursor1()},
    m_cursor2{create_cursor2()},
    m_landscape(window_width / 32, window_height / 32),
    m_textures{}
{

}

void game::add_command(const command& c) noexcept
{
  m_commands.insert(c);
}

void game::draw(sf::RenderWindow& w)
{
  const auto &ts = m_textures;
  sf::Sprite sprite1;
  sprite1.setTexture(ts.get(texture_type::imp_red_front_1));
  sprite1.setPosition(224, 320 + 32);
  sf::Sprite sprite2;
  sprite2.setTexture(ts.get(texture_type::imp_blue_front_1));
  sprite2.setPosition(672, 320 + 32);

  sf::Sprite heart1;
  heart1.setTexture(ts.get(texture_type::heart_red));
  heart1.setPosition(224, 320);
  sf::Sprite heart2;
  heart2.setTexture(ts.get(texture_type::heart_blue));
  heart2.setPosition(672, 320);


  draw_landscape(w, ts, get_landscape());
  draw_cursor(w, get_cursor1());
  draw_cursor(w, get_cursor2());
  w.draw(heart1);
  w.draw(heart2);
  w.draw(sprite1);
  w.draw(sprite2);

}

void game::process_commands() noexcept
{
  const int n_cols{m_landscape.get_n_cols()};
  const int n_rows{m_landscape.get_n_rows()};
  if (m_commands.count(command::left1)) m_cursor1.m_pos.x = (m_cursor1.m_pos.x + n_cols - 1) % n_cols;
  if (m_commands.count(command::right1)) m_cursor1.m_pos.x = (m_cursor1.m_pos.x + n_cols + 1) % n_cols;
  if (m_commands.count(command::up1)) m_cursor1.m_pos.y = (m_cursor1.m_pos.y + n_rows - 1) % n_rows;
  if (m_commands.count(command::down1)) m_cursor1.m_pos.y = (m_cursor1.m_pos.y + n_rows + 1) % n_rows;
  if (m_commands.count(command::left2)) m_cursor2.m_pos.x = (m_cursor2.m_pos.x + n_cols - 1) % n_cols;
  if (m_commands.count(command::right2)) m_cursor2.m_pos.x = (m_cursor2.m_pos.x + n_cols + 1) % n_cols;
  if (m_commands.count(command::up2)) m_cursor2.m_pos.y = (m_cursor2.m_pos.y + n_rows - 1) % n_rows;
  if (m_commands.count(command::down2)) m_cursor2.m_pos.y = (m_cursor2.m_pos.y + n_rows + 1) % n_rows;
  m_commands.clear();
}
