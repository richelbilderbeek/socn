#include "n_wheat.h"

bool operator==(const n_wheat& lhs, const n_wheat& rhs) noexcept
{
  return lhs.get() == rhs.get();
}

n_wheat operator*(const n_wheat& w, const int n) noexcept
{
  return n_wheat(w.get() * n);
}

n_wheat operator+(const n_wheat& lhs, const n_wheat& rhs) noexcept
{
  return n_wheat(lhs.get() + rhs.get());
}

n_wheat operator-(const n_wheat& lhs, const n_wheat& rhs) noexcept
{
  return n_wheat(lhs.get() - rhs.get());
}
