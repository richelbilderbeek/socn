#include "n_wood.h"

#include <iostream>

bool operator==(const n_wood& lhs, const n_wood& rhs) noexcept
{
  return lhs.get() == rhs.get();
}

n_wood operator*(const n_wood& w, const int n) noexcept
{
  return n_wood(w.get() * n);
}

n_wood operator+(const n_wood& lhs, const n_wood& rhs) noexcept
{
  return n_wood(lhs.get() + rhs.get());
}

n_wood operator-(const n_wood& lhs, const n_wood& rhs) noexcept
{
  return n_wood(lhs.get() - rhs.get());
}

std::ostream& operator<<(std::ostream& os, const n_wood& r)
{
  os << r.get() << " wood";
  return os;
}
