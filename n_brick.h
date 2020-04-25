#ifndef N_BRICK_H
#define N_BRICK_H

#include <iosfwd>

struct n_brick
{
  explicit n_brick(const int n) : m_n{n} {}
  int get() const noexcept { return m_n; }
private:
  int m_n;
};

/// Convert to string
std::string to_str(const n_brick& r) noexcept;

bool operator==(const n_brick& lhs, const n_brick& rhs) noexcept;
n_brick operator*(const n_brick& w, const double n) noexcept;
n_brick operator+(const n_brick& lhs, const n_brick& rhs) noexcept;
n_brick operator-(const n_brick& lhs, const n_brick& rhs) noexcept;
std::ostream& operator<<(std::ostream& os, const n_brick& r);
void test_n_brick();

#endif // N_BRICK_H
