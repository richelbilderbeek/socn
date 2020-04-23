#ifndef RESOURCES_H
#define RESOURCES_H

#include "n_wood.h"
#include "n_brick.h"
#include "n_wheat.h"
#include "n_wool.h"
#include "n_ore.h"

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

  auto get_woods() const noexcept { return m_woods; }
  auto get_bricks() const noexcept { return m_bricks; }
  auto get_wheats() const noexcept { return m_wheats; }
  auto get_wools() const noexcept { return m_wools; }
  auto get_ores() const noexcept { return m_ores; }

private:
  n_wood m_woods;
  n_brick m_bricks;
  n_wheat m_wheats;
  n_wool m_wools;
  n_ore m_ores;

};

/// The cost to draw a card
resources get_card_cost() noexcept;

/// The cost to build a city
resources get_city_cost() noexcept;

/// The cost to build a road
resources get_road_cost() noexcept;

/// The cost to build a village
resources get_village_cost() noexcept;

void test_resources();

#endif // RESOURCES_H
