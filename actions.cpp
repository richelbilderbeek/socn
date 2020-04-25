#include "actions.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <exception>
#include <iostream>

actions::actions(
  const std::array<action, get_n_actions_to_win_the_game()>& actions
) : m_actions{actions}
{
  if (!is_valid(m_actions)) throw std::logic_error("Invalid set of actions");
}

std::vector<actions> get_all_actionses()
{
  const int n_max{
    static_cast<int>(
      std::pow(
        get_n_actions(),
        get_n_actions_to_win_the_game()
      )
    )
  };
  std::vector<actions> v;
  for (int i = 0; i != n_max; ++i)
  {
    const auto raw_actions = int_to_raw_actions(i);
    try
    {
      v.push_back(actions(raw_actions));
    }
    catch (const std::exception&) {} // Ignore invalid actions
  }
  return v;
}


std::array<action, get_n_actions_to_win_the_game()> int_to_raw_actions(int i)
{
  std::array<action, get_n_actions_to_win_the_game()> actions;
  // 10 actions will win the game for sure
  for (int n = 0; n != get_n_actions_to_win_the_game(); ++n)
  {
    actions[static_cast<size_t>(n)] = static_cast<action>(i % get_n_actions());
    i /= get_n_actions();
  }
  return actions;
}

bool is_valid(
  const std::array<action, get_n_actions_to_win_the_game()>& actions
)
{
  using namespace std;
  if (actions.size() < 2) return true;
  if (count(begin(actions), end(actions), action::build_village) > 5)
  {
    return false;
  }
  if (count(begin(actions), end(actions), action::build_city) > 5)
  {
    return false;
  }
  if (count(begin(actions), end(actions), action::build_trade_route) > 1)
  {
    return false;
  }
  if (count(begin(actions), end(actions), action::buy_knight_force) > 1)
  {
    return false;
  }
  if (count(begin(actions), end(actions), action::buy_dev_point) > 5)
  {
    return false;
  }
  return true;
}

void test_actions()
{
  // int_to_raw_actions
  {
    assert(int_to_raw_actions(0)[0] == action::build_village);
  }
  // get_all_actionses
  {
    const auto actionses = get_all_actionses();
    const auto created_sz = actionses.size();
    if (get_n_actions_to_win_the_game() == 10)
    {
      assert(actionses.size() == 944706);
    }
    assert(actionses.size() == 81102);
  }
}
