#include "n_brick.h"

bool operator==(const n_brick& lhs, const n_brick& rhs) noexcept
{
  return lhs.get() == rhs.get();
}
