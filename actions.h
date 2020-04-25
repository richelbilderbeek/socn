#ifndef ACTIONS_H
#define ACTIONS_H

#include "action.h"

/// A valid sequence of actions
class actions
{
public:
  actions(const std::vector<action>& actions);

private:

  std::vector<action> m_actions;
};

///Converts an integer to the number of actions,
///These actions do not need to be valid.
///For example '11111111' would be to build a city for 8 turns.
///The '1' is in the 5-digit number system, as there are 5 actions
std::vector<action> int_to_raw_actions();

bool is_valid(const std::vector<action>& actions);

void test_actions();

#endif // ACTIONS_H
