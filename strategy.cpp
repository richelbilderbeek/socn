#include "strategy.h"

#include "actions.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>

strategy::strategy(
  const state& begin,
  const std::vector<action>& actions)
  : m_begin{begin},
    m_actions{actions}
{

}

int calc_n_turns(const strategy& s)
{
  auto cur_state = s.get_begin();
  int sum_n_turns = 0;
  for (const auto& action: s.get_actions())
  {
    sum_n_turns += calc_n_turns(cur_state, action);
    cur_state = to_next_state(cur_state, action);
  }
  return sum_n_turns;
}

std::vector<strategy> get_all_strategies(
  const state& begin
)
{
  std::set<strategy> strategies;
  for (const actions& as: get_all_actionses())
  {
    strategies.insert(play_actions(begin, as));
  }

  std::vector<strategy> results;
  results.resize(strategies.size());
  std::copy(
    std::begin(strategies), std::end(strategies),
    std::back_inserter(results)
  );
  return results;
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
    //Already won the game
    assert(23748 == 7357615);
    return {};
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

strategy play_actions(const state& begin, const actions& raw_actions)
{
  state cur_state = begin;
  std::vector<action> actions_played;

  for (const action& a: raw_actions.get())
  {
    if (has_won(cur_state)) return strategy(begin, actions_played);

    // Play next acion
    actions_played.push_back(a);
    cur_state = to_next_state(cur_state, a);
  }
  assert(has_won(cur_state));
  return strategy(begin, actions_played);
}

void test_strategy()
{

  //strategy play_actions(const state& begin, const actions& raw_actions)

}

std::ostream& operator<<(std::ostream& os, const strategy& s)
{ 
  const auto actions = s.get_actions();
  const auto n_actions = actions.size();
  for (auto i = 0u; i != n_actions; ++i)
  {
    os << i << ": " << actions[i] << '\n';
  }
  return os;
}

bool operator<(const strategy& lhs, const strategy& rhs)
{
  return calc_n_turns(lhs) < calc_n_turns(rhs);
}
