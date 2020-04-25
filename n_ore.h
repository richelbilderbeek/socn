#ifndef N_ORE_H
#define N_ORE_H

#include <iosfwd>

struct n_ore
{
  explicit n_ore(const int n) : m_n{n} {}
  int get() const noexcept { return m_n; }
private:
  int m_n;
};

/// Convert to string
std::string to_str(const n_ore& r) noexcept;

bool operator==(const n_ore& lhs, const n_ore& rhs) noexcept;
n_ore operator*(const n_ore& w, const int n) noexcept;
n_ore operator+(const n_ore& lhs, const n_ore& rhs) noexcept;
n_ore operator-(const n_ore& lhs, const n_ore& rhs) noexcept;
std::ostream& operator<<(std::ostream& os, const n_ore& r);
void test_n_ore();

#endif // N_ORE_H
