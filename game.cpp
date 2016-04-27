#include "game.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

game::game(const int window_width, const int window_height)
  : m_commands{},
    m_cursor1{create_cursor1()},
    m_cursor2{create_cursor2()},
    m_landscape(window_width / 32, window_height / 32),
    m_monsters{},
    m_textures{},
    m_tick{}
{
  //Add initial sprites
  {
    m_monsters.push_back(monster(monster_type::imp, player::red, 224, 352));
    m_monsters.push_back(monster(monster_type::imp, player::blue, 672, 352));
  }
}

void game::add_command(const command& c) noexcept
{
  m_commands.insert(c);
}

void game::draw(sf::RenderWindow& w)
{
  m_landscape.draw(w, m_textures);

  //Draw monsters
  for (const auto& monster: m_monsters) { monster.draw(w, m_textures); }
  //Draw cursors
  draw_cursor(w, get_cursor1());
  draw_cursor(w, get_cursor2());

}

void game::move_monster(monster& m) noexcept
{
  if (has_direction(m) && m_landscape.can_move(
      m.x() + m.dx(),
      m.y() + m.dy(),
      m.w(),
      m.h()
    )
  )
  {
    m.set_pos(m.x() + m.dx(), m.y() + m.dy());
  }
  else
  {
    m.pick_new_direction();
  }
}


void game::move_monsters() noexcept
{
  for (auto& m: m_monsters) { move_monster(m); }
}

void game::process_commands() noexcept
{
  const int n_cols{m_landscape.get_n_cols()};
  const int n_rows{m_landscape.get_n_rows()};

  //Select/unselect before move
  if (m_commands.count(command::select1)) m_landscape.set_selectedness(m_cursor1.m_pos.x, m_cursor1.m_pos.y, 1);
  if (m_commands.count(command::select2)) m_landscape.set_selectedness(m_cursor2.m_pos.x, m_cursor2.m_pos.y, 2);
  if (m_commands.count(command::unselect1)) m_landscape.set_selectedness(m_cursor1.m_pos.x, m_cursor1.m_pos.y, 0);
  if (m_commands.count(command::unselect2)) m_landscape.set_selectedness(m_cursor2.m_pos.x, m_cursor2.m_pos.y, 0);

  if (m_commands.count(command::left1 )) m_cursor1.m_pos.x = (m_cursor1.m_pos.x + n_cols - 1) % n_cols;
  if (m_commands.count(command::right1)) m_cursor1.m_pos.x = (m_cursor1.m_pos.x + n_cols + 1) % n_cols;
  if (m_commands.count(command::up1   )) m_cursor1.m_pos.y = (m_cursor1.m_pos.y + n_rows - 1) % n_rows;
  if (m_commands.count(command::down1 )) m_cursor1.m_pos.y = (m_cursor1.m_pos.y + n_rows + 1) % n_rows;
  if (m_commands.count(command::left2 )) m_cursor2.m_pos.x = (m_cursor2.m_pos.x + n_cols - 1) % n_cols;
  if (m_commands.count(command::right2)) m_cursor2.m_pos.x = (m_cursor2.m_pos.x + n_cols + 1) % n_cols;
  if (m_commands.count(command::up2   )) m_cursor2.m_pos.y = (m_cursor2.m_pos.y + n_rows - 1) % n_rows;
  if (m_commands.count(command::down2 )) m_cursor2.m_pos.y = (m_cursor2.m_pos.y + n_rows + 1) % n_rows;

  //Select/unselect after move
  if (m_commands.count(command::select1)) m_landscape.set_selectedness(m_cursor1.m_pos.x, m_cursor1.m_pos.y, 1);
  if (m_commands.count(command::select2)) m_landscape.set_selectedness(m_cursor2.m_pos.x, m_cursor2.m_pos.y, 2);
  if (m_commands.count(command::unselect1)) m_landscape.set_selectedness(m_cursor1.m_pos.x, m_cursor1.m_pos.y, 0);
  if (m_commands.count(command::unselect2)) m_landscape.set_selectedness(m_cursor2.m_pos.x, m_cursor2.m_pos.y, 0);



  m_commands.clear();
}

void game::tick() noexcept
{
  ++m_tick;
  move_monsters();
  if (m_tick % 4 == 0)
  {
    process_commands();
  }
}
