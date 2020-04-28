#include "tile_type.h"

#include <cassert>

constexpr bool is_harbor(const tile_type t) noexcept
{
  return t == tile_type::three_is_one_harbor
    || t == tile_type::wood_harbor
    || t == tile_type::bricks_harbor
    || t == tile_type::wheat_harbor
    || t == tile_type::wool_harbor
    || t == tile_type::ore_harbor
  ;
}

std::string to_str(const tile_type t) noexcept
{
  switch (t)
  {
    case tile_type::wood: return "wood";
    case tile_type::bricks: return "bricks";
    case tile_type::wheat: return "wheat";
    case tile_type::wool: return "wool";
    case tile_type::ore: return "ore";
    case tile_type::three_is_one_harbor: return "3:1";
    case tile_type::wood_harbor: return "2:1 wood";
    case tile_type::bricks_harbor: return "2:1 brick";
    case tile_type::wheat_harbor: return "2:1 wheat";
    case tile_type::wool_harbor: return "2:1 wool";
    case tile_type::ore_harbor: return "2:1 ore";
    case tile_type::desert: return "desert";
    case tile_type::sea: return "sea";
  }
  assert(5678957 == 23657623);
  return "";
}

void test_tile_type()
{
  assert(!is_harbor(tile_type::wood));
  assert(!is_harbor(tile_type::bricks));
  assert(!is_harbor(tile_type::wheat));
  assert(!is_harbor(tile_type::wool));
  assert(!is_harbor(tile_type::ore));
  assert(is_harbor(tile_type::three_is_one_harbor));
  assert(is_harbor(tile_type::wood_harbor));
  assert(is_harbor(tile_type::bricks_harbor));
  assert(is_harbor(tile_type::wheat_harbor));
  assert(is_harbor(tile_type::wool_harbor));
  assert(is_harbor(tile_type::ore_harbor));
  assert(!is_harbor(tile_type::desert));
  assert(!is_harbor(tile_type::sea));
}
