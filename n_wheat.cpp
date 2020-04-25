#include "n_wheat.h"

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

std::string to_str(const n_wheat& r) noexcept
{
  std::stringstream s;
  s << r.get() << " wheat";
  return s.str();
}

bool operator==(const n_wheat& lhs, const n_wheat& rhs) noexcept
{
  return lhs.get() == rhs.get();
}

n_wheat operator*(const n_wheat& w, const double n) noexcept
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

std::ostream& operator<<(std::ostream& os, const n_wheat& r)
{
  os << to_str(r);
  return os;
}

void test_n_wheat()
{
  {
    std::stringstream s;
    s << n_wheat(1);
    assert(s.str() == std::string("1 wheat"));
  }
  assert(to_str(n_wheat(1)) == std::string("1 wheat"));
}
