#ifndef GAME_H
#define GAME_H

#include <set>

#include <SFML/Graphics/Sprite.hpp>

#include "command.h"
#include "cursor.h"
#include "landscape.h"
#include "monster.h"
#include "textures.h"

namespace sf { struct RenderWindow; }

///The game engine
class game
{
public:
  void add_command(const command& c) noexcept;
  void add_monster(const monster& m);
  void draw(sf::RenderWindow& w);
  const cursor& get_cursor1() const noexcept { return m_cursor1; }
  const cursor& get_cursor2() const noexcept { return m_cursor2; }
  const landscape& get_landscape() const noexcept { return m_landscape; }
        landscape& get_landscape()       noexcept { return m_landscape; }
  int get_n_cols() const;
  int get_n_rows() const noexcept;
  void tick() noexcept;

private:
  std::set<command> m_commands;
  cursor m_cursor1;
  cursor m_cursor2;
  landscape m_landscape;
  std::vector<monster> m_monsters;
  textures m_textures;
  int m_tick; //Number of ticks

  game(const int n_cols, const int n_rows);
  void move_monster(monster& m) noexcept;
  void move_monsters() noexcept;
  void process_commands() noexcept;
  friend game create_default_game(const int n_cols, const int n_rows);
};

game create_default_game(const int n_cols = 30, const int n_rows = 20);

#endif // GAME_H
