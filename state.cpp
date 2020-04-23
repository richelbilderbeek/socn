#include "state.h"
#include <cassert>

state::state(
  const int n_villages,
  const int n_cities,
  const bool has_longest_road,
  const bool has_biggest_knight_force,
  const int n_development_points
)
  : m_has_biggest_knight_force{has_biggest_knight_force},
    m_has_longest_road{has_longest_road},
    m_n_cities{n_cities},
    m_n_development_points{n_development_points},
    m_n_villages{n_villages}
{

}

int count_points(const state& s) noexcept
{
  return
      1 * s.get_n_villages()
    + (2 * s.get_n_cities())
    + (2 * s.get_has_longest_road())
    + (2 * s.get_has_biggest_knight_force())
    + s.get_n_development_points()
  ;
}

bool has_won(const state& s) noexcept
{
  return count_points(s) >= 10;
}

void test_state()
{
  //A default state is not a win
  {
    assert(!has_won(state()));
  }
  //5 cities wins the game
  {
    state s(0, 5);
    assert(s.get_n_villages() == 0);
    assert(s.get_n_cities() == 5);
    assert(!s.get_has_longest_road());
    assert(!s.get_has_biggest_knight_force());
    assert(has_won(s));
  }
  //2 villages and 4 cities wins the game
  {
    state s(2, 4);
    assert(s.get_n_villages() == 2);
    assert(s.get_n_cities() == 4);
    assert(!s.get_has_longest_road());
    assert(!s.get_has_biggest_knight_force());
    assert(has_won(s));
  }
  //2 villages, 3 cities and longest road wins the game
  {
    state s(2, 3, true);
    assert(s.get_n_villages() == 2);
    assert(s.get_n_cities() == 3);
    assert(s.get_has_longest_road());
    assert(!s.get_has_biggest_knight_force());
    assert(has_won(s));
  }
  //2 villages, 2 cities, longest road and biggest knight force wins the game
  {
    state s(2, 2, true, true);
    assert(s.get_n_villages() == 2);
    assert(s.get_n_cities() == 2);
    assert(s.get_has_longest_road());
    assert(s.get_has_biggest_knight_force());
    assert(has_won(s));
  }
  //4 villages, 2 cities, 2 development points wins the game
  {
    state s(4, 2, false, false, 2);
    assert(s.get_n_villages() == 4);
    assert(s.get_n_cities() == 2);
    assert(!s.get_has_longest_road());
    assert(!s.get_has_biggest_knight_force());
    assert(s.get_n_development_points() == 2);
    assert(has_won(s));
  }
}
