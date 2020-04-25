#ifndef ACTIONS_H
#define ACTIONS_H

#include "action.h"

#include <array>

///The number of actions to win the game for sure
constexpr int get_n_actions_to_win_the_game() { return 8; }

/// A valid sequence of actions
class actions
{
public:
  actions(const std::array<action, get_n_actions_to_win_the_game()>& actions);

  const auto& get() const noexcept { return m_actions; }

private:
  std::array<action, get_n_actions_to_win_the_game()> m_actions;
};

///Converts an integer to the number of actions,
///These actions do not need to be valid.
///For example '1111111111' would be to build a city for 10 turns.
///The '1' is in the 5-digit number system, as there are 5 actions.
///The number of digits amounts to the number of actions needed to win the game for sure
std::array<action, get_n_actions_to_win_the_game()> int_to_raw_actions(int i);

/// Get all the valid sets of actions, calculate this at runtime
/// These are 81102 for 8 actions
std::vector<actions> get_all_actionses();

bool is_valid(const std::array<action, get_n_actions_to_win_the_game()>& actions);

void test_actions();

#endif // ACTIONS_H
