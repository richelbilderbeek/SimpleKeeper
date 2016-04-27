#ifndef TEXTURE_TYPE_H
#define TEXTURE_TYPE_H

#include "monster_type.h"
#include "player.h"

enum class texture_type
{
  empty, //Transparent
  floor, //A bottom tile, the stuff you stand on, the stuff where a wall is built on
  heart_blue,
  heart_red,
  hole, //A bottom tile, the stuff you cannot stand on (but can fall though), the stuff where a wall cannot be built on
  imp_red_front_1,
  imp_blue_front_1,
  question_mark, //To indicate something went wrong
  wall,
  water //A bottom tile, the stuff you cannot stand on (but swim through), the stuff where a wall cannot be built on
};


///Obtain the texture type for a monster, loyal to a certain master, going in a certain direction
texture_type get_texture_type(
  const monster_type m,
  const player master,
  const int dx,
  const int dy
);

///Obtain the texture type for a monster, loyal to blue, going in a certain direction
texture_type get_texture_type_blue(
  const monster_type m,
  const int dx,
  const int dy
);

///Obtain the texture type for a monster, loyal to red, going in a certain direction
texture_type get_texture_type_red(
  const monster_type m,
  const int dx,
  const int dy
);


///For animations, you want walk1 and walk2 to alternate
///This function gives you the same, yet other, texture type
texture_type get_other_texture_type(
  const texture_type t
);

///Is 16x16 pixels
bool is_small(const texture_type t) noexcept;

#endif // TEXTURE_TYPE_H
