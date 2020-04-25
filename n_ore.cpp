#include "n_ore.h"

#include <iostream>

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

std::ostream& operator<<(std::ostream& os, const n_ore& r)
{
  os << r.get() << " ore";
  return os;
}
