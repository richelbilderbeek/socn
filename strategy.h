#ifndef STRATEGY_H
#define STRATEGY_H

#include "state.h"

#include <iosfwd>
#include <vector>

/// The series of states to strive for
class strategy
{
public:
  strategy(const std::vector<state>& states = {});
  const std::vector<state>& get_states() const noexcept { return m_states; }

private:
  std::vector<state> m_states;
};

/// Calculate the predicted number of turns to go from
/// the first to the second state
int calc_n_turns(const strategy& s);

/// Get the n best strategies
std::vector<strategy> get_best_strategies(
  const state& begin,
  const int n = 1
);

std::ostream& operator<<(std::ostream& os, const strategy& s);
bool operator<(const strategy& lhs, const strategy& rhs);

#endif // STRATEGY_H
