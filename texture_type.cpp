#include "texture_type.h"
#include <set>
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
