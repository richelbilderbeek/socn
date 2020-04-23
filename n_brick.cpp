#include "n_brick.h"

bool operator==(const n_brick& lhs, const n_brick& rhs) noexcept
{
  return lhs.get() == rhs.get();
}

n_brick operator*(const n_brick& w, const int n) noexcept
{
  return n_brick(w.get() * n);
}

n_brick operator+(const n_brick& lhs, const n_brick& rhs) noexcept
{
  return n_brick(lhs.get() + rhs.get());
}

n_brick operator-(const n_brick& lhs, const n_brick& rhs) noexcept
{
  return n_brick(lhs.get() - rhs.get());
}