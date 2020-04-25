#ifndef N_WOOL_H
#define N_WOOL_H

#include <iosfwd>

struct n_wool
{
  explicit n_wool(const int n) : m_n{n} {}
  int get() const noexcept { return m_n; }
private:
  int m_n;
};

/// Convert to string
std::string to_str(const n_wool& r) noexcept;

bool operator==(const n_wool& lhs, const n_wool& rhs) noexcept;
n_wool operator*(const n_wool& w, const int n) noexcept;
n_wool operator+(const n_wool& lhs, const n_wool& rhs) noexcept;
n_wool operator-(const n_wool& lhs, const n_wool& rhs) noexcept;
std::ostream& operator<<(std::ostream& os, const n_wool& r);
void test_n_wool();

#endif // N_WOOL_H
