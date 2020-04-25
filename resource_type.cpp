#include "resource_type.h"

#include <cassert>

std::string to_str(const resource_type t) noexcept
{
  switch (t)
  {
    case resource_type::wood: return "wood";
    case resource_type::bricks: return "bricks";
    case resource_type::wheat: return "wheat";
    case resource_type::wool: return "wool";
    case resource_type::ore: return "ore";
  }
  assert(5678957 == 23657623);
  return "";
}
