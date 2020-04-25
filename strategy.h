#ifndef STRATEGY_H
#define STRATEGY_H

class actions;

#include "action.h"
#include "state.h"

#include <iosfwd>
#include <vector>

/// The series of actions to strive for
class strategy
{
public:
  strategy(
    const state& begin = state(),
    const std::vector<action>& actions = {}
  );
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

/// Get all strategies to go from begin to a win condition
std::vector<strategy> get_all_strategies(
  const state& begin
);

/// Convert each vector of actions to a unique integer
int to_int(const strategy& strategy);

/// Play the actions until a win condition is reached
/// Return the strategy with the (shorter) set of actions
strategy play_actions(const state& begin, const actions& a);

/// Test the strategy class and free functions
void test_strategy();

std::ostream& operator<<(std::ostream& os, const strategy& s);
bool operator<(const strategy& lhs, const strategy& rhs);

#endif // STRATEGY_H
