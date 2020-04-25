#include "resources.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

resources::resources(
  const n_wood woods,
  const n_brick bricks,
  const n_wheat wheats,
  const n_wool wools,
  const n_ore ores
) : m_woods{woods},
    m_bricks{bricks},
    m_wheats{wheats},
    m_wools{wools},
    m_ores{ores}
{

}

int calc_n_turns(
  const resources& goal,
  const resources& income
)
{
  for (int i = 1; i != 100; ++i) {
    const resources difference = (i * income) - goal;
    const int n_negative = sum_negatives(difference);
    const int n_tradable = trade_positives(difference, 4);
    if (n_tradable >= n_negative) return i;
  }
  assert(!"Should never get here");
  return 0;
}

int dice_to_value(const int dice_value)
{
  assert(dice_value >= 2);
  assert(dice_value <= 12);
  assert(dice_value != 7);
  return 6 - std::abs(7 - dice_value);
}

resources get_card_cost() noexcept
{
  return resources(
    n_wood(0),
    n_brick(0),
    n_wheat(1),
    n_wool(1),
    n_ore(1)
  );
}

/// The cost to build a city
resources get_city_cost() noexcept
{
  return resources(
    n_wood(0),
    n_brick(0),
    n_wheat(2),
    n_wool(0),
    n_ore(3)
  );
}

resources get_extra_income(const int n)
{
  switch (n)
  {
    case 0:
      return resources(
        n_wood(dice_to_value(5) + dice_to_value(6)),
        n_brick(0),
        n_wheat(dice_to_value(4)),
        n_wool(0),
        n_ore(0)
      );
    case 1:
      return resources(
        n_wood(0),
        n_brick(dice_to_value(10)),
        n_wheat(dice_to_value(6)),
        n_wool(0),
        n_ore(dice_to_value(5))
      );
    case 2:
      return resources(
        n_wood(dice_to_value(3)),
        n_brick(dice_to_value(8)),
        n_wheat(0),
        n_wool(0),
        n_ore(dice_to_value(5))
      );
    case 3:
      return resources(
        n_wood(0),
        n_brick(0),
        n_wheat(0),
        n_wool(0),
        n_ore(0)
      );
    case 4:
      return resources(
        n_wood(dice_to_value(11)),
        n_brick(dice_to_value(10)),
        n_wheat(0),
        n_wool(0),
        n_ore(dice_to_value(8))
      );
    case 5:
      return resources(
        n_wood(dice_to_value(5)),
        n_brick(dice_to_value(8) + dice_to_value(2)),
        n_wheat(0),
        n_wool(0),
        n_ore(0)
      );
    case 6:
      return resources(
        n_wood(0),
        n_brick(0),
        n_wheat(0),
        n_wool(dice_to_value(4) + dice_to_value(12)),
        n_ore(dice_to_value(8))
      );
    case 7:
      return resources(
        n_wood(dice_to_value(3)),
        n_brick(dice_to_value(8)),
        n_wheat(0),
        n_wool(dice_to_value(9)),
        n_ore(0)
      );
    case 8:
      return resources(
        n_wood(0),
        n_brick(0),
        n_wheat(dice_to_value(9)),
        n_wool(dice_to_value(4) + dice_to_value(12)),
        n_ore(0)
      );
    case 9:
      return resources(
        n_wood(dice_to_value(6)),
        n_brick(0),
        n_wheat(dice_to_value(9)),
        n_wool(0),
        n_ore(0)
      );
  }
  assert(13275 == 7362377);
  return resources();
}

/// The cost to build a road
resources get_road_cost() noexcept
{
  return resources(
    n_wood(1),
    n_brick(1),
    n_wheat(0),
    n_wool(0),
    n_ore(0)
  );
}

/// The cost to build a village
resources get_village_cost() noexcept
{
  return resources(
    n_wood(1),
    n_brick(1),
    n_wheat(1),
    n_wool(1),
    n_ore(0)
  );

}

int sum_negatives(const resources& r)
{
  int sum = 0;
  if (r.get_ores().get() < 0) sum -= r.get_ores().get();
  if (r.get_woods().get() < 0) sum -= r.get_woods().get();
  if (r.get_wools().get() < 0) sum -= r.get_wools().get();
  if (r.get_bricks().get() < 0) sum -= r.get_bricks().get();
  if (r.get_wheats().get() < 0) sum -= r.get_wheats().get();
  assert(sum >= 0);
  return sum;
}

int sum_positives(const resources& r)
{
  int sum = 0;
  if (r.get_ores().get() > 0) sum += r.get_ores().get();
  if (r.get_woods().get() > 0) sum += r.get_woods().get();
  if (r.get_wools().get() > 0) sum += r.get_wools().get();
  if (r.get_bricks().get() > 0) sum += r.get_bricks().get();
  if (r.get_wheats().get() > 0) sum += r.get_wheats().get();
  assert(sum >= 0);
  return sum;
}

int trade_positives(
  const resources& r,
  const int ratio
)
{
  std::vector<int> values  = {
    r.get_woods().get(),
    r.get_bricks().get(),
    r.get_wheats().get(),
    r.get_wools().get(),
    r.get_ores().get()
  };
  int sum = 0;
  for (int& i: values)
  {
    if (i > 0) sum += (i / ratio);
  }
  return sum;
}

std::string to_str(const resources& r)
{
  std::stringstream s;
  s
    << r.get_woods()
    << ", " << r.get_bricks()
    << ", " << r.get_wheats()
    << ", " << r.get_wools()
    << ", " << r.get_ores()
  ;
  return s.str();
}

resources operator+(const resources& lhs, const resources& rhs) noexcept
{
  return resources(
    lhs.get_woods() + rhs.get_woods(),
    lhs.get_bricks() + rhs.get_bricks(),
    lhs.get_wheats() + rhs.get_wheats(),
    lhs.get_wools() + rhs.get_wools(),
    lhs.get_ores() + rhs.get_ores()
  );
}

resources operator-(const resources& lhs, const resources& rhs) noexcept
{
  return resources(
    lhs.get_woods() - rhs.get_woods(),
    lhs.get_bricks() - rhs.get_bricks(),
    lhs.get_wheats() - rhs.get_wheats(),
    lhs.get_wools() - rhs.get_wools(),
    lhs.get_ores() - rhs.get_ores()
  );
}

std::ostream& operator<<(std::ostream& os, const resources& r)
{
  os << to_str(r);
  return os;
}

void test_resources()
{
  //Road: 1 wood, 1 brick
  {
    const auto cost = get_road_cost();
    assert(cost.get_ores() == n_ore(0));
    assert(cost.get_woods() == n_wood(1));
    assert(cost.get_wools() == n_wool(0));
    assert(cost.get_bricks() == n_brick(1));
    assert(cost.get_wheats() == n_wheat(0));
  }
  // Count negatives
  {
    const resources r(
      n_wood(-2),
      n_brick(11111),
      n_wheat(11111),
      n_wool(-3),
      n_ore(11111)
    );
    assert(sum_negatives(r) == 5);
  }
  {
    const resources r(
      n_wood(0),
      n_brick(1),
      n_wheat(2),
      n_wool(-3),
      n_ore(5)
    );
    assert(sum_positives(r) == 8);
  }
  // Pay a road from ore only
  {
    const resources goal = get_road_cost();
    const resources income(
      n_wood(0),
      n_brick(0),
      n_wheat(0),
      n_wool(0),
      n_ore(1)
    );
    const int n_turns = calc_n_turns(goal, income);
    assert(8 == n_turns);
  }
  // Pay a road from wood
  {
    const resources goal = get_road_cost();
    const resources income(
      n_wood(1),
      n_brick(0),
      n_wheat(0),
      n_wool(0),
      n_ore(0)
    );
    const int n_turns = calc_n_turns(goal, income);
    assert(5 == n_turns);
  }
  // Must be four of the same resources
  {
    const resources goal(
      n_wood(1),
      n_brick(0),
      n_wheat(0),
      n_wool(0),
      n_ore(0)
    );
    // It will take four turns to get here,
    // as one needs four resources of one kind
    const resources income(
      n_wood(0),
      n_brick(1),
      n_wheat(1),
      n_wool(1),
      n_ore(1)
    );
    const int n_turns = calc_n_turns(goal, income);
    assert(4 == n_turns);

  }
  // to_str
  {
    const resources r(
      n_wood(1),
      n_brick(2),
      n_wheat(3),
      n_wool(4),
      n_ore(5)
    );
    const std::string created = to_str(r);
    const std::string expected = "1 wood, 2 brick, 3 wheat, 4 wool, 5 ore";
    assert(created == expected);
  }
  {
    assert(dice_to_value( 2) == 1);
    assert(dice_to_value( 3) == 2);
    assert(dice_to_value( 4) == 3);
    assert(dice_to_value( 5) == 4);
    assert(dice_to_value( 6) == 5);
    assert(dice_to_value( 8) == 5);
    assert(dice_to_value( 9) == 4);
    assert(dice_to_value(10) == 3);
    assert(dice_to_value(11) == 2);
    assert(dice_to_value(12) == 1);
  }
}

bool operator>(const resources& lhs, const resources& rhs) noexcept
{
  return sum_positives(lhs) > sum_positives(rhs);
}

resources operator*(const int n, const resources& r) noexcept
{
  return resources(
    r.get_woods() * n,
    r.get_bricks() * n,
    r.get_wheats() * n,
    r.get_wools() * n,
    r.get_ores() * n
  );
}
