#include "n_brick.h"

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

std::string to_str(const n_brick& r) noexcept
{
  std::stringstream s;
  s << r.get() << " brick";
  return s.str();
}

bool operator==(const n_brick& lhs, const n_brick& rhs) noexcept
{
  return lhs.get() == rhs.get();
}

n_brick operator*(const n_brick& w, const double n) noexcept
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

std::ostream& operator<<(std::ostream& os, const n_brick& r)
{
  os << to_str(r);
  return os;
}

void test_n_brick()
{
  {
    std::stringstream s;
    s << n_brick(1);
    assert(s.str() == std::string("1 brick"));
  }
  assert(to_str(n_brick(1)) == std::string("1 brick"));
}
