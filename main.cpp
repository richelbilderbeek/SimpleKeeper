#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "textures.h"


int main()
{

  const int window_width{960};
  const int window_height{640};

  game g(window_width, window_height);
  textures ts;

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


  sf::RenderWindow window(
    sf::VideoMode(window_width, window_height),
    "SimpleKeeper",
    sf::Style::Titlebar | sf::Style::Close
  );
  sf::Clock clock;
  while(window.isOpen())
  {
    sf::Event event;

    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;
        default:
          break;
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) g.add_command(command::left1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) g.add_command(command::right1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) g.add_command(command::up1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) g.add_command(command::down1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) g.add_command(command::left2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) g.add_command(command::right2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) g.add_command(command::up2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) g.add_command(command::down2);
    if (clock.getElapsedTime().asMilliseconds() < 40) continue;
    clock.restart();
    g.process_commands();

    window.clear();
    draw_landscape(window, ts, g.get_landscape());
    draw_cursor(window, g.get_cursor1());
    draw_cursor(window, g.get_cursor2());
    window.draw(heart1);
    window.draw(heart2);
    window.draw(sprite1);
    window.draw(sprite2);
    window.display();
  }
}
