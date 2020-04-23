#ifndef N_BRICK_H
#define N_BRICK_H

struct n_brick
{
  explicit n_brick(const int n) : m_n{n} {}
  int get() const noexcept { return m_n; }
private:
  int m_n;
};

bool operator==(const n_brick& lhs, const n_brick& rhs) noexcept;

#endif // N_BRICK_H
