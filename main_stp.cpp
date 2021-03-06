#include <cassert>
#include <fstream>
#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

///Determines if a filename is a regular file
///From http://www.richelbilderbeek.nl/CppIsRegularFile.htm
bool is_regular_file(const std::string& filename) noexcept
{
  std::fstream f;
  f.open(filename.c_str(),std::ios::in);
  return f.is_open();
}

#include "STP/Core/Image.hpp"

int main()
{
  {
    const std::string filename{"/home/richel/GitHubs/SimpleKeeper/Sprites/Floor1.png"};
    assert(is_regular_file(filename));
    tmx::Image image(filename);
    assert(image.GetWidth() < 100);
  }

  sf::RenderWindow window(sf::VideoMode(360, 280), "STP Example");
<<<<<<< HEAD
  //const std::string filename{"/home/richel/GitHubs/SimpleKeeper/Maps/simple.tmx"};
  //const std::string filename{"orthogonal-outside.tmx"};
  const std::string filename{"simple.tmx"};
  assert(is_regular_file(filename));

  tmx::TileMap map(filename);
  //tmx::TileMap map("~/GitHubs/tiled/examples/orthogonal-outside.tmx");
=======
  //tmx::TileMap map("~/GitHubs/SimpleKeeper/Maps/simple.tmx");
  tmx::TileMap map("orthogonal-outside.tmx");
>>>>>>> 357ed28da927a46218411316a1dd4356721d6009

  map.ShowObjects(); // Display all the layer objects.

  //map.GetLayer("World").visible = false; // Hide a Layer named World

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
