#ifndef N_WOOD_H
#define N_WOOD_H

#include <iosfwd>

struct n_wood
{
  explicit n_wood(const int n) : m_n{n} {}
  int get() const noexcept { return m_n; }
private:
  int m_n;
};

/// Convert to string
std::string to_str(const n_wood& r) noexcept;

bool operator==(const n_wood& lhs, const n_wood& rhs) noexcept;
n_wood operator*(const n_wood& w, const int n) noexcept;
n_wood operator+(const n_wood& lhs, const n_wood& rhs) noexcept;
n_wood operator-(const n_wood& lhs, const n_wood& rhs) noexcept;
std::ostream& operator<<(std::ostream& os, const n_wood& r);
void test_n_wood();

#endif // N_WOOD_H
