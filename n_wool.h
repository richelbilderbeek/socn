#ifndef N_WOOL_H
#define N_WOOL_H

struct n_wool
{
  explicit n_wool(const int n) : m_n{n} {}
  int get() const noexcept { return m_n; }
private:
  int m_n;
};

bool operator==(const n_wool& lhs, const n_wool& rhs) noexcept;
n_wool operator*(const n_wool& w, const int n) noexcept;
n_wool operator+(const n_wool& lhs, const n_wool& rhs) noexcept;
n_wool operator-(const n_wool& lhs, const n_wool& rhs) noexcept;


#endif // N_WOOL_H
