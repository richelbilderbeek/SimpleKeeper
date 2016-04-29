#include "texture_type.h"
#include <cassert>
#include <set>

texture_type get_other_texture_type(
  const texture_type t
)
{
  switch (t)
  {
     case texture_type::empty: assert(!"Should not get here"); return t;
     case texture_type::floor: assert(!"Should not get here"); return t;
     case texture_type::heart_blue: assert(!"Should not get here"); return t;
     case texture_type::heart_red: assert(!"Should not get here"); return t;
     case texture_type::hole: assert(!"Should not get here"); return t;
     case texture_type::imp_blue_back_1: return texture_type::imp_blue_back_2;
     case texture_type::imp_blue_back_2: return texture_type::imp_blue_back_1;
     case texture_type::imp_blue_front_1: return texture_type::imp_blue_front_2;
     case texture_type::imp_blue_front_2: return texture_type::imp_blue_front_1;
     case texture_type::imp_blue_left_1: return texture_type::imp_blue_left_2;
     case texture_type::imp_blue_left_2: return texture_type::imp_blue_left_1;
     case texture_type::imp_blue_right_1: return texture_type::imp_blue_right_2;
     case texture_type::imp_blue_right_2: return texture_type::imp_blue_right_1;
     case texture_type::imp_red_back_1: return texture_type::imp_red_back_2;
     case texture_type::imp_red_back_2: return texture_type::imp_red_back_1;
     case texture_type::imp_red_front_1: return texture_type::imp_red_front_2;
     case texture_type::imp_red_front_2: return texture_type::imp_red_front_1;
     case texture_type::imp_red_left_1: return texture_type::imp_red_left_2;
     case texture_type::imp_red_left_2: return texture_type::imp_red_left_1;
     case texture_type::imp_red_right_1: return texture_type::imp_red_right_2;
     case texture_type::imp_red_right_2: return texture_type::imp_red_right_1;
     case texture_type::question_mark: assert(!"Should not get here"); return t;
     case texture_type::wall: assert(!"Should not get here"); return t;
     case texture_type::water: assert(!"Should not get here"); return t;
  }
  assert(!"Should not get here");
  return t;
}

texture_type get_texture_type(
  const monster_type m,
  const player master,
  const int dx,
  const int dy
)
{
  switch (master)
  {
    case player::blue: return get_texture_type_blue(m, dx, dy);
    case player::red : return get_texture_type_red( m, dx, dy);
  }
  assert(!"Should not get here");
  return texture_type::question_mark;
}

texture_type get_texture_type_blue(
  const monster_type m,
  const int dx,
  const int dy
)
{
  switch (m)
  {
    case monster_type::imp:
    {
      if (dx < 0.0) return texture_type::imp_blue_left_1;
      if (dx > 0.0) return texture_type::imp_blue_right_1;
      if (dy < 0.0) return texture_type::imp_blue_back_1;
      return texture_type::imp_blue_front_1;
    }
  }
  assert(!"Should not get here");
  return texture_type::question_mark;
}

texture_type get_texture_type_red(
  const monster_type m,
  const int dx,
  const int dy
)
{
  switch (m)
  {
    case monster_type::imp:
    {
      if (dx < 0.0) return texture_type::imp_red_left_1;
      if (dx > 0.0) return texture_type::imp_red_right_1;
      if (dy < 0.0) return texture_type::imp_red_back_1;
      return texture_type::imp_red_front_1;
    }
  }
  assert(!"Should not get here");
  return texture_type::question_mark;
}

bool is_small(const texture_type t) noexcept
{
  const std::set<texture_type> small = {
    texture_type::empty,
    texture_type::floor,
    texture_type::hole,
    texture_type::wall,
    texture_type::water
  };
  return small.count(t);
}
