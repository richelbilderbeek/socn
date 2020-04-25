#include "n_wool.h"

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

std::string to_str(const n_wool& r) noexcept
{
  std::stringstream s;
  s << r.get() << " wool";
  return s.str();
}

bool operator==(const n_wool& lhs, const n_wool& rhs) noexcept
{
  return lhs.get() == rhs.get();
}

n_wool operator*(const n_wool& w, const double n) noexcept
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
  os << to_str(r);
  return os;
}

void test_n_wool()
{
  {
    std::stringstream s;
    s << n_wool(1);
    assert(s.str() == std::string("1 wool"));
  }
  assert(to_str(n_wool(1)) == std::string("1 wool"));
}
