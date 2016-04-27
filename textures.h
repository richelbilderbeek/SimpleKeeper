#ifndef TEXTURES_H
#define TEXTURES_H

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include "texture_type.h"

///Contains all textures
class textures
{
public:
  textures();
  const sf::Texture& get(const texture_type t) const;
private:
  std::map<texture_type, sf::Texture> m_textures;
};



#endif // TEXTURES_H
