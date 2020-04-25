#include "n_ore.h"

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

std::string to_str(const n_ore& r) noexcept
{
  std::stringstream s;
  s << r.get() << " ore";
  return s.str();
}

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
  os << to_str(r);
  return os;
}

void test_n_ore()
{
  {
    std::stringstream s;
    s << n_ore(1);
    assert(s.str() == std::string("1 ore"));
  }
  assert(to_str(n_ore(1)) == std::string("1 ore"));
}
