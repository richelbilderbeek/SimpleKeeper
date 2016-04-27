#include "texture_type.h"
#include <set>

texture_type get_other_texture_type(
  const texture_type t
)
{
  switch (t)
  {
     case texture_type::imp_blue_front_1:
     // return texture_type::imp_blue_front_2;
     //case texture_type::imp_blue_front_2:
      return texture_type::imp_blue_front_1;
     case texture_type::imp_red_front_1:
     // return texture_type::imp_red_front_2;
     //case texture_type::imp_red_front_2:
      return texture_type::imp_red_front_1;

  }
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
      if (dx > -100 && dy > -100)
      {
        return texture_type::imp_blue_front_1;
      }
    }
  }
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
      if (dx > -100 && dy > -100)
      {
        return texture_type::imp_red_front_1;
      }
    }
  }
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
