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
  game(const int window_width, const int window_height);
  void add_command(const command& c) noexcept;
  void draw(sf::RenderWindow& w);
  const cursor& get_cursor1() const noexcept { return m_cursor1; }
  const cursor& get_cursor2() const noexcept { return m_cursor2; }
  const landscape& get_landscape() const noexcept { return m_landscape; }
  void tick() noexcept;

private:
  std::set<command> m_commands;
  cursor m_cursor1;
  cursor m_cursor2;
  landscape m_landscape;
  std::vector<monster> m_monsters;
  textures m_textures;

  void move_monster(monster& m) noexcept;
  void move_monsters() noexcept;
  void process_commands() noexcept;
};

#endif // GAME_H
