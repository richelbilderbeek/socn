#include "map_pos.h"

#include <cassert>

map_pos::map_pos(
  const int x,
  const int y,
  const int orientation
) : m_x{x}, m_y{y}, m_orientation{orientation}
{
  assert(m_x >= 0);
  assert(m_y >= 0);
  assert(m_orientation >= 0 && m_orientation <= 12);
}
