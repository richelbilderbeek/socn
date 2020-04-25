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

bool operator==(const n_brick& lhs, const n_brick& rhs) noexcept;
n_brick operator*(const n_brick& w, const int n) noexcept;
n_brick operator+(const n_brick& lhs, const n_brick& rhs) noexcept;
n_brick operator-(const n_brick& lhs, const n_brick& rhs) noexcept;
std::ostream& operator<<(std::ostream& os, const n_brick& r);

#endif // N_BRICK_H
