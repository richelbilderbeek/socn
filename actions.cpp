#include "actions.h"

#include <algorithm>
#include <cassert>

actions::actions(const std::vector<action>& actions)
  : m_actions{actions}
{

}

bool is_valid(const std::vector<action>& actions)
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
  // is_valid
  {
    assert(is_valid( {} ));
    assert(is_valid( { action::build_city } ));
    assert(
      !is_valid(
        {
          action::build_trade_route,
          action::build_trade_route
        }
      )
    );

  }
}
