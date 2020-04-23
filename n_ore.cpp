#include "n_ore.h"

bool operator==(const n_ore& lhs, const n_ore& rhs) noexcept
{
  return lhs.get() == rhs.get();
}
