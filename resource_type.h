#ifndef RESOURCE_TYPE_H
#define RESOURCE_TYPE_H

#include <string>

// The 5 resource types
enum class tile_type
{
  wood,
  bricks,
  wheat,
  wool,
  ore,
  three_is_one_harbor,
  wood_harbor,
  bricks_harbor,
  wheat_harbor,
  wool_harbor,
  ore_harbor,
  desert,
  sea
};

std::string to_str(const tile_type t) noexcept;

#endif // RESOURCE_TYPE_H
