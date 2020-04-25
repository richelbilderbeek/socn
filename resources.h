#ifndef RESOURCES_H
#define RESOURCES_H

#include "n_wood.h"
#include "n_brick.h"
#include "n_wheat.h"
#include "n_wool.h"
#include "n_ore.h"

#include <iostream>

class resources
{
public:
  explicit resources(
    const n_wood woods = n_wood(0),
    const n_brick bricks = n_brick(0),
    const n_wheat wheats = n_wheat(0),
    const n_wool wools = n_wool(0),
    const n_ore ores = n_ore(0)
  );

  const n_wood& get_woods() const noexcept { return m_woods; }
  const n_brick& get_bricks() const noexcept { return m_bricks; }
  const n_wheat& get_wheats() const noexcept { return m_wheats; }
  const n_wool& get_wools() const noexcept { return m_wools; }
  const n_ore& get_ores() const noexcept { return m_ores; }

private:
  n_wood m_woods;
  n_brick m_bricks;
  n_wheat m_wheats;
  n_wool m_wools;
  n_ore m_ores;

};

/// Calculate the number of turn it takes to reach the goal
int calc_n_turns(const resources& goal, const resources& income);

/// The cost to draw a card
resources get_card_cost() noexcept;

/// The cost to build a city
resources get_city_cost() noexcept;

/// The cost to build a road
resources get_road_cost() noexcept;

/// The cost to build a village
resources get_village_cost() noexcept;

/// Sum the negatives and take the absolute value of that
/// (that is -2 and -1 is 3)
int sum_negatives(const resources& r);

/// Sum the positives
int sum_positives(const resources& r);

void test_resources();

resources operator*(const int n, const resources& r) noexcept;

resources operator+(const resources& lhs, const resources& rhs) noexcept;
resources operator-(const resources& lhs, const resources& rhs) noexcept;
std::ostream& operator<<(std::ostream& os, const resources& r);

#endif // RESOURCES_H
