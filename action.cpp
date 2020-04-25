#include "action.h"

#include "actions.h"
#include "resources.h"
#include "state.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

int calc_n_turns(const state& s, const action& a)
{
  resources needed;
  switch(a)
  {
    case action::build_village:
      // Assumed that two road are needed as well
      // Ignores that these roads are already present,
      // which is especially likely when having the longest trade route
      needed = get_village_cost() + (2 * get_road_cost());
      break;
    case action::build_city: needed = get_city_cost();
      needed = get_city_cost();
    break;
    case action::build_trade_route:
      needed = 5 * get_road_cost();
    break;
    case action::buy_knight_force:
      // Assume 3 knight cards are needed, ignoring the opponent
      // 14 out of 25 dev card are knight
      // Buying 6 is expected to result in 3 knight cards
      // (ignores that a development point is also likely to be gained)
      needed = 6 * get_card_cost();
    break;
    case action::buy_dev_point:
      // 5 out of 25 dev card are development card
      // Buying 5 is expected to result in 1 development point
      // (ignores that obtaining the largest knight force is also likely to be gained)
      needed = 5 * get_card_cost();
    break;
  }
  const resources& income = s.get_income();
  return calc_n_turns(needed, income);
}

std::vector<action> get_actions(const state& s)
{
  std::vector<action> actions;
  if (s.get_n_villages() < 5)
  {
    actions.push_back(action::build_village);
  }
  if (s.get_n_villages() > 0 && s.get_n_cities() < 5)
  {
    actions.push_back(action::build_city);
  }
  if (!s.get_has_longest_road())
  {
    actions.push_back(action::build_trade_route);
  }
  if (!s.get_has_biggest_knight_force())
  {
    actions.push_back(action::buy_knight_force);
  }
  if (s.get_n_development_points() < 5)
  {
    actions.push_back(action::buy_dev_point);
  }
  return actions;
}

int to_int(const std::vector<action>& actions)
{
  // These must be the actions values
  static_assert(static_cast<int>(action::build_village) == 0);
  static_assert(static_cast<int>(action::build_city) == 1);
  static_assert(static_cast<int>(action::build_trade_route) == 2);
  static_assert(static_cast<int>(action::buy_knight_force) == 3);
  static_assert(static_cast<int>(action::buy_dev_point) == 4);

  // Use the reverse of the actions, to make the last actions
  // be the lower digits
  std::vector<action> rev_actions;
  std::reverse_copy(std::begin(actions), std::end(actions),
    std::back_inserter(rev_actions)
  );
  int sum = 0;
  const int number_system = get_n_actions();
  const int n_actions = static_cast<int>(rev_actions.size());

  for (int i = 0; i != n_actions; ++i)
  {
    const int digit_multiplier{
      static_cast<int>(
        std::pow(number_system, i)
      )
    };
    const int this_digit{
      1 + static_cast<int>(rev_actions[static_cast<size_t>(i)])
    };
    assert(this_digit >= 0);
    assert(this_digit <= 5);
    sum += (digit_multiplier * this_digit);
  }
  return sum;
}

std::string to_str(const action& a) noexcept
{
  switch (a)
  {
    case action::build_village: return "build_village";
    case action::build_city: return "build_city";
    case action::build_trade_route: return "build_trade_route";
    case action::buy_knight_force: return "buy_knight_force";
    case action::buy_dev_point: return "buy_dev_point";
  }
  assert(7383 == 52895181);
  return "";
}

std::ostream& operator<<(std::ostream& os, const action& a)
{
  os << to_str(a);
  return os;
}

void test_action()
{
  // to_str
  {
    assert(to_str(action::build_village) == "build_village");
    assert(to_str(action::build_city) == "build_city");
    assert(to_str(action::build_trade_route) == "build_trade_route");
    assert(to_str(action::buy_knight_force) == "buy_knight_force");
    assert(to_str(action::buy_dev_point) == "buy_dev_point");
  }
  // Calculate the number of turns to build a
  // village. This includes building two roads
  {
    // 1st road: 1 wood, 1 brick
    // 2nd road: 1 wood, 1 brick
    // village: 1 wood, 1 brick, 1 sheep, 1 wheat
    // In total: 8 resources
    // Only have one income, which needs to be traded 1 to 4.
    // Therefore, it will take 8 * 4 turns
    const resources income(
      n_wood(0),
      n_brick(0),
      n_wheat(0),
      n_wool(0),
      n_ore(1)
    );
    const state begin(1, 0, false, false, 0, income);
    const int n = calc_n_turns(begin, action::build_village);
    assert(n == 36 * 8 * 4);
  }
  // Calculate the number of turns to build a
  // city.
  {
    // City: 2 wheat, 3 ore
    // In total: 5 resources
    // Only have one income, which needs to be traded 1 to 4.
    // Therefore, 3 + (2 * 4) == 11
    const resources income(
      n_wood(0),
      n_brick(0),
      n_wheat(0),
      n_wool(0),
      n_ore(1)
    );
    const state a(1, 1, false, false, 0, income);
    const int n = calc_n_turns(a, action::build_city);
    assert(n == 11 * 36);
  }
  // Calculate the number of turns to build a
  // the largest trade route
  {
    // Trade route: 5x road (as a proxy)
    // In total: 5x wood, 5x brick
    const resources income(
      n_wood(2),
      n_brick(2),
      n_wheat(0),
      n_wool(0),
      n_ore(1)
    );
    const state a(1, 1, false, false, 0, income);
    const int n = calc_n_turns(a, action::build_trade_route);
    // Less than 3 * 36, due to averaging out
    assert(n == 90);
  }
  // Calculate the number of turns to build a
  // the largest knight force
  {
    // Knight force: 3x knights,
    // 14 our of 25 card are knights, so need approx 6 card
    const resources income(
      n_wood(0),
      n_brick(0),
      n_wheat(1),
      n_wool(1),
      n_ore(1)
    );
    const state a(1, 1, true, false, 0, income);
    const int n = calc_n_turns(a, action::buy_knight_force);
    assert(n == 6 * 36);
  }
  {
    static_assert(static_cast<int>(action::build_village) == 0);
    static_assert(static_cast<int>(action::build_city) == 1);
    static_assert(static_cast<int>(action::build_trade_route) == 2);
    static_assert(static_cast<int>(action::buy_knight_force) == 3);
    static_assert(static_cast<int>(action::buy_dev_point) == 4);
    assert(to_int( { action::build_village} ) == 1);
    assert(to_int( { action::build_city} ) == 2);
    assert(to_int( { action::build_trade_route} ) == 3);
    assert(to_int( { action::buy_knight_force} ) == 4);
    assert(to_int( { action::buy_dev_point} ) == 5);
    assert(to_int( { action::build_village, action::build_village} ) == 6);
    assert(to_int( { action::build_village, action::build_city} ) == 7);
    assert(to_int( { action::build_village, action::build_village, action::build_village} ) == 31);
  }
}
