#include "game_window.h"

#include <sstream>
#include <stdexcept>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio/Music.hpp>
#include "game.h"

game_window::game_window(
  const int window_width,
  const int window_height,
  const int poll_time_msecs,
  const std::function<bool(const game_window&)> stop_condition,
  const std::string& window_title
) : m_game{create_default_game(window_width / 32, window_height / 32)},
    m_poll_time_msecs{poll_time_msecs},
    m_stop_condition{stop_condition},
    m_window_height{window_height},
    m_window_title{window_title},
    m_window_width{window_width}
{
  if (m_window_width < 3 * 32 || m_window_height < 3 * 32)
  {
    std::stringstream msg;
    msg << __func__ << ": cannot create a window of "
      << m_window_width << " x " << m_window_height
      << ", must be at least" << (3 * 32)
    ;
    throw std::invalid_argument(msg.str());
  }
  if (m_window_width % 32 || m_window_height % 32)
  {
    std::stringstream msg;
    msg << __func__ << ": cannot create a window of "
      << m_window_width << " x " << m_window_height
      << ", must both be multiples of 32"
    ;
    throw std::invalid_argument(msg.str());
  }

  static sf::Music music;
  music.openFromFile("../SimpleKeeper/Sound/Underworld.wav");
  music.setLoop(true);
  music.play();
}

void game_window::execute()
{
  const int n_cols{m_game.get_n_cols()};
  const int n_rows{m_game.get_n_rows()};

  sf::RenderWindow window(
    sf::VideoMode(n_cols * 32, n_rows * 32),
    m_window_title,
    sf::Style::Titlebar | sf::Style::Close
  );
  sf::Clock clock;
  while(1)
  {
    if (m_stop_condition(*this)) return;
    if (!window.isOpen()) return;
    sf::Event event;
    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
          window.close();
          return;
        default:
          break;
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) m_game.add_command(command::up1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) m_game.add_command(command::right1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) m_game.add_command(command::down1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) m_game.add_command(command::left1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) m_game.add_command(command::select1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) m_game.add_command(command::unselect1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) m_game.add_command(command::up2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon )) m_game.add_command(command::right2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) m_game.add_command(command::down2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) m_game.add_command(command::left2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) m_game.add_command(command::select2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) m_game.add_command(command::unselect2);
    if (clock.getElapsedTime().asMilliseconds() < 10) continue;
    clock.restart();
    m_game.tick();
    m_game.draw(window);
    window.display();
  }
}
