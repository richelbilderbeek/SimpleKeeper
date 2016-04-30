#include "game.h"

#include <cassert>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

game::game(const int n_cols, const int n_rows)
  : m_commands{},
    m_cursor1{create_cursor1()},
    m_cursor2{create_cursor2()},
    m_landscape(n_cols, n_rows),
    m_monsters{},
    m_textures{},
    m_tick{}
{

}

void game::add_command(const command& c) noexcept
{
  m_commands.insert(c);
}

void game::add_monster(const monster& m)
{
  m_monsters.push_back(m);
}

game create_default_game(const int n_cols, const int n_rows)
{
  game g(n_cols, n_rows);
  g.add_monster(monster(monster_type::imp, player::red, ((1 * n_cols / 4) * 32) + 32, ((n_rows / 2) * 32) + 32));
  g.add_monster(monster(monster_type::imp, player::blue,((3 * n_cols / 4) * 32) + 32, ((n_rows / 2) * 32) + 32));
  auto& s = g.get_landscape();
  auto& top = s.get_top_texture_grid();
  //Create room for dungeon hearts
  if (n_cols >= 11 && n_rows >= 5)
  {
    for (int y{0}; y!=5; ++y)
    {
      const int row{(n_rows / 2) - 2 + y};
      assert(row >= 0 && row < static_cast<int>(top.size()));
      for (int x{0}; x!=5; ++x)
      {
        const int col_left {(1 * (n_cols / 4)) - 2 + x};
        const int col_right{(3 * (n_cols / 4)) - 2 + x};
        assert(col_left  >= 0 && col_left  < static_cast<int>(top[row].size()));
        assert(col_right >= 0 && col_right < static_cast<int>(top[row].size()));
        top[row][col_left ] = texture_type::empty;
        top[row][col_right] = texture_type::empty;
      }
    }
    const int row{(n_rows / 2)};
    const int col_left {(1 * (n_cols / 4))};
    const int col_right{(3 * (n_cols / 4))};
    assert(row >= 0 && row < static_cast<int>(top.size()));
    assert(col_left  >= 0 && col_left  < static_cast<int>(top[row].size()));
    assert(col_right >= 0 && col_right < static_cast<int>(top[row].size()));
    top[row][col_left] = texture_type::heart_red;
    top[row][col_right] = texture_type::heart_blue;
  }
  return g;
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

int game::get_n_cols() const
{
  return m_landscape.get_n_cols();
}

int game::get_n_rows() const noexcept
{
  return m_landscape.get_n_rows();
}

void game::move_monster(monster& m) noexcept
{
  move(m, m_landscape);
  behave(m, m_landscape);
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
    m_landscape.update_attractivenesses();
  }
}
