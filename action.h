#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <iostream>
#include <vector>

class state;

/// The (simplified) actions a player can do
enum class action
{
  build_village,
  build_city,
  build_trade_route,
  buy_knight_force,
  buy_dev_point
};

constexpr int get_n_actions() { return 5; }

/// Calculate the expected number of turns to do an action
int calc_n_turns(const state& s, const action& a);

/// Get all the valid actions for a state
std::vector<action> get_actions(const state& s);

void test_action();

/// Convert to string
std::string to_str(const action& a) noexcept;

std::ostream& operator<<(std::ostream& os, const action& a);


#endif // ACTION_H
