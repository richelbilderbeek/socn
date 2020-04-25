#include "n_wood.h"

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

std::string to_str(const n_wood& r) noexcept
{
  std::stringstream s;
  s << r.get() << " wood";
  return s.str();
}

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
  os << to_str(r);
  return os;
}

void test_n_wood()
{
  assert(to_str(n_wood(1)) == std::string("1 wood"));
}
