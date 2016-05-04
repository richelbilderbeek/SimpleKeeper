
#include "SFML/Graphics.hpp"
#include "tmx/MapLoader.h"


int main()
{
  sf::RenderWindow window(sf::VideoMode(360, 280), "STP Example");
  tmx::MapLoader map("~/GitHubs/SimpleKeeper/Maps");
  map.Load("simple.tmx");
  //tmx::MapLoader map("~/GitHubs/tiled/examples/orthogonal-outside.tmx");

  // Start the game loop
  while (window.isOpen()) {
      // Process events
      sf::Event event;
      while (window.pollEvent(event)) {
          // Close window : exit
          if (event.type == sf::Event::Closed)
              window.close();
      }
      // Clear screen
      window.clear();
      // Draw the map
      window.draw(map);
      // Update the window
      window.display();
  }

  return EXIT_SUCCESS;
}
