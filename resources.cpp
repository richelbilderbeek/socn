#include "resources.h"
#include <cassert>

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

/// The cost to draw a card
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
}
