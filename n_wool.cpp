#include "n_wool.h"

bool operator==(const n_wool& lhs, const n_wool& rhs) noexcept
{
  return lhs.get() == rhs.get();
}
