#include "n_ore.h"

bool operator==(const n_ore& lhs, const n_ore& rhs) noexcept
{
  return lhs.get() == rhs.get();
}

n_ore operator*(const n_ore& w, const int n) noexcept
{
  return n_ore(w.get() * n);
}

n_ore operator+(const n_ore& lhs, const n_ore& rhs) noexcept
{
  return n_ore(lhs.get() + rhs.get());
}

n_ore operator-(const n_ore& lhs, const n_ore& rhs) noexcept
{
  return n_ore(lhs.get() - rhs.get());
}
