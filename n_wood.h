#ifndef N_WOOD_H
#define N_WOOD_H

struct n_wood
{
  explicit n_wood(const int n) : m_n{n} {}
  int get() const noexcept { return m_n; }
private:
  int m_n;
};

bool operator==(const n_wood& lhs, const n_wood& rhs) noexcept;

#endif // N_WOOD_H
