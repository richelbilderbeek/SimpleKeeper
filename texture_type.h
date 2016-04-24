#ifndef TEXTURE_TYPE_H
#define TEXTURE_TYPE_H

enum class texture_type
{
  empty, //Transparent
  floor, //A bottom tile, the stuff you stand on, the stuff where a wall is built on
  heart_blue,
  heart_red,
  hole, //A bottom tile, the stuff you cannot stand on (but can fall though), the stuff where a wall cannot be built on
  imp_red_front_1,
  imp_blue_front_1,
  wall,
  water //A bottom tile, the stuff you cannot stand on (but swim through), the stuff where a wall cannot be built on
};

///Is 16x16 pixels
bool is_small(const texture_type t) noexcept;

#endif // TEXTURE_TYPE_H
