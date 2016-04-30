#include "game_window.h"

#include <sstream>
#include <stdexcept>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "game.h"

game_window::game_window(
  const int window_width,
  const int window_height,
  const int poll_time_msecs,
  const std::function<bool(const game_window&)> stop_condition,
  const std::string& window_title
) : m_poll_time_msecs{poll_time_msecs},
    m_stop_condition{stop_condition},
    m_window_height{window_height},
    m_window_title{window_title},
    m_window_width{window_width}
{
  if (m_window_width < 960 || m_window_height < 640)
  {
    std::stringstream msg;
    msg << __func__ << ": cannot create a window of "
      << m_window_width << " x " << m_window_height
      << ", must minimally be 960 x 640"
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
}

void game_window::execute()
{
  game g(m_window_width, m_window_height);

  sf::RenderWindow window(
    sf::VideoMode(m_window_width, m_window_height),
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) g.add_command(command::up1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) g.add_command(command::right1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) g.add_command(command::down1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) g.add_command(command::left1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) g.add_command(command::select1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) g.add_command(command::unselect1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) g.add_command(command::up2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon )) g.add_command(command::right2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) g.add_command(command::down2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) g.add_command(command::left2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) g.add_command(command::select2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) g.add_command(command::unselect2);
    if (clock.getElapsedTime().asMilliseconds() < 10) continue;
    clock.restart();
    g.tick();
    g.draw(window);
    window.display();
  }
}
