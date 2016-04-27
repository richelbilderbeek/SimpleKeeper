#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "textures.h"


int main()
{
  try
  {
    const int window_width{960};
    const int window_height{640};

    game g(window_width, window_height);

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
      //window.clear();
      g.draw(window);
      window.display();
    }
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }
}
