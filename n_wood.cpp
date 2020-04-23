#include "n_wood.h"

bool operator==(const n_wood& lhs, const n_wood& rhs) noexcept
{
  return lhs.get() == rhs.get();
}
