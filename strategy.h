#ifndef STRATEGY_H
#define STRATEGY_H

#include "action.h"
#include "state.h"

#include <iosfwd>
#include <vector>

/// The series of actions to strive for
class strategy
{
public:
  strategy(const state& begin = state());
  const auto& get_actions() const noexcept { return m_actions; }
  const auto& get_begin() const noexcept { return m_begin; }

private:
  state m_begin;

  std::vector<action> m_actions;
};

/// Calculate the predicted number of turns to go from
/// the first to the second state
int calc_n_turns(const strategy& s);

/// Get the n best strategies of all possible end states
std::vector<strategy> get_best_strategies(
  const state& begin,
  const int n = 1
);

/// Get the n best strategies for a given end state
std::vector<strategy> get_best_strategies(
  const state& begin,
  const state& end,
  const int n
);

/// Get all strategies to go from begin to end
std::vector<strategy> get_all_strategies(
  const state& begin,
  const state& end
);

std::ostream& operator<<(std::ostream& os, const strategy& s);
bool operator<(const strategy& lhs, const strategy& rhs);

#endif // STRATEGY_H
