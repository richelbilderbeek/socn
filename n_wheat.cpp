#include "n_wheat.h"

bool operator==(const n_wheat& lhs, const n_wheat& rhs) noexcept
{
  return lhs.get() == rhs.get();
}
