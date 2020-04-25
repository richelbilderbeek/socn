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

/// Convert to string
std::string to_str(const n_wheat& r) noexcept;

bool operator==(const n_wheat& lhs, const n_wheat& rhs) noexcept;
n_wheat operator*(const n_wheat& w, const double n) noexcept;
n_wheat operator+(const n_wheat& lhs, const n_wheat& rhs) noexcept;
n_wheat operator-(const n_wheat& lhs, const n_wheat& rhs) noexcept;
std::ostream& operator<<(std::ostream& os, const n_wheat& r);
void test_n_wheat();

#endif // N_WHEAT_H
