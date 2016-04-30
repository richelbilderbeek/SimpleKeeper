#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode(360, 280), "STP Example");
  tmx::TileMap map("~/GitHubs/SimpleKeeper/Maps/simple.tmx");

  map.ShowObjects(); // Display all the layer objects.

  map.GetLayer("World").visible = false; // Hide a Layer named World

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
