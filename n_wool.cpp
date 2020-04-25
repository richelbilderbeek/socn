#include "n_wool.h"

#include <iostream>

bool operator==(const n_wool& lhs, const n_wool& rhs) noexcept
{
  return lhs.get() == rhs.get();
}

n_wool operator*(const n_wool& w, const int n) noexcept
{
  return n_wool(w.get() * n);
}

n_wool operator+(const n_wool& lhs, const n_wool& rhs) noexcept
{
  return n_wool(lhs.get() + rhs.get());
}

n_wool operator-(const n_wool& lhs, const n_wool& rhs) noexcept
{
  return n_wool(lhs.get() - rhs.get());
}

std::ostream& operator<<(std::ostream& os, const n_wool& r)
{
  os << r.get() << " wool";
  return os;
}
