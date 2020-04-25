#include "strategy.h"

#include <algorithm>
#include <cassert>
#include <iostream>

strategy::strategy(const std::vector<state>& states)
  : m_states{states}
{

}

int calc_n_turns(const strategy& s)
{
  const auto& states = s.get_states();
  const int n_states = static_cast<int>(states.size());
  const int n_calcs = n_states - 1;
  int sum_n_turns = 0;
  for (int i = 0; i != n_calcs; ++i)
  {
    sum_n_turns += calc_n_turns(states[i], states[i + 1]);
  }
  return sum_n_turns;
}

std::vector<strategy> get_all_strategies(
  const state& begin,
  const state& end
) {
  // Cannot go back
  if (begin.get_n_villages() + begin.get_n_cities()
    > end.get_n_villages() + end.get_n_cities()
    || begin.get_has_longest_road() > end.get_has_longest_road()
    || begin.get_n_development_points() > end.get_n_development_points()
    || begin.get_has_biggest_knight_force() > end.get_has_biggest_knight_force()
  )
  {
    return {};
  }
  if (begin.get_n_villages() + begin.get_n_cities()
    == end.get_n_villages() + end.get_n_cities()
    && begin.get_n_cities() == end.get_n_cities()
    && begin.get_has_longest_road() == end.get_has_longest_road()
    && begin.get_n_development_points() == end.get_n_development_points()
    && begin.get_has_biggest_knight_force() == end.get_has_biggest_knight_force()
  ) {
    return {
      strategy( { begin, end } )
    };
  }
  assert(652361 == 64637582);
  return {};
}

std::vector<strategy> get_best_strategies(
  const state& begin,
  const state& end,
  const int n
)
{
  std::vector<strategy> strategies = get_all_strategies(begin, end);

  // Sort on the number of turns
  std::sort(std::begin(strategies), std::end(strategies));

  // Best strategies have lowest number of turns
  strategies.resize(static_cast<size_t>(n));

  return strategies;
}

std::vector<strategy> get_best_strategies(
  const state& begin,
  const int n
)
{
  const auto win_states = get_win_states();

  std::vector<strategy> strategies;
  strategies.reserve(static_cast<size_t>(n) * win_states.size());
  for (const auto& win_state: win_states) {
     const auto these_strategies = get_best_strategies(
       begin,
       win_state,
       n
     );
     std::copy(
       std::begin(these_strategies),
       std::end(these_strategies),
       std::back_inserter(strategies)
     );
  }
  // Sort on the number of turns
  std::sort(std::begin(strategies), std::end(strategies));

  // Best strategies have lowest number of turn
  strategies.resize(static_cast<size_t>(n));

  return strategies;
}


void test_strategy()
{
}

std::ostream& operator<<(std::ostream& os, const strategy& s)
{ 
  const auto states = s.get_states();
  const auto n_states = states.size();
  for (auto i = 0u; i != n_states; ++i)
  {
    os << i << ": " << states[i] << '\n';
  }
  return os;
}

bool operator<(const strategy& lhs, const strategy& rhs)
{
  return calc_n_turns(lhs) < calc_n_turns(rhs);
}
