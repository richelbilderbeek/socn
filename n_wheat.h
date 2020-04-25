#ifndef N_WHEAT_H
#define N_WHEAT_H

#include <iosfwd>

struct n_wheat
{
  explicit n_wheat(const int n) : m_n{n} {}
  int get() const noexcept { return m_n; }
private:
  int m_n;
};

bool operator==(const n_wheat& lhs, const n_wheat& rhs) noexcept;
n_wheat operator*(const n_wheat& w, const int n) noexcept;
n_wheat operator+(const n_wheat& lhs, const n_wheat& rhs) noexcept;
n_wheat operator-(const n_wheat& lhs, const n_wheat& rhs) noexcept;
std::ostream& operator<<(std::ostream& os, const n_wheat& r);

#endif // N_WHEAT_H
