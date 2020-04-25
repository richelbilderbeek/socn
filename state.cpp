#include "state.h"

#include <algorithm>
#include <cassert>
#include <iostream>

state::state(
  const int n_villages,
  const int n_cities,
  const bool has_longest_road,
  const bool has_biggest_knight_force,
  const int n_development_points,
  const resources& income
)
  : m_has_biggest_knight_force{has_biggest_knight_force},
    m_has_longest_road{has_longest_road},
    m_income{income},
    m_n_cities{n_cities},
    m_n_development_points{n_development_points},
    m_n_villages{n_villages}
{
  if (!is_valid(*this)) {
    throw std::logic_error("Invalid state");
  }
}

int calc_n_turns(const state& a, const state& b)
{
  resources needed;
  const int n_villages = b.get_n_villages() - a.get_n_villages();
  if (n_villages > 0)
  {
    // Building a city removed a village
    needed = needed
      + (n_villages * get_village_cost())
      + (n_villages * 2 * get_road_cost())
    ;
  }
  const int n_cities = b.get_n_cities() - a.get_n_cities();
  needed = needed + (n_cities * get_city_cost());

  const bool build_trade_route = b.get_has_longest_road()
    && !a.get_has_longest_road();
  if (build_trade_route)
  {
    needed = needed + (5 * get_road_cost());
  }

  const bool obtain_knight_force = b.get_has_biggest_knight_force()
    && !a.get_has_biggest_knight_force();
  if (obtain_knight_force)
  {
    needed = needed + (6 * get_card_cost());
  }

  const resources& income = a.get_income();
  return calc_n_turns(needed, income);
}

std::vector<int> calc_n_turns(const state& from, const std::vector<state>& to)
{
  std::vector<int> v;
  v.reserve(to.size());
  for (const state& s: to)
  {
    v.push_back(calc_n_turns(from, s));
  }
  return v;
}

int count_points(const state& s) noexcept
{
  return s.get_n_villages()
    + (2 * s.get_n_cities())
    + (2 * s.get_has_longest_road())
    + (2 * s.get_has_biggest_knight_force())
    + s.get_n_development_points()
  ;
}

state get_richels_favorite_begin_state()
{
  const resources income = get_extra_income(0) + get_extra_income(1);
  return state(
    2,
    0,
    false,
    false,
    0,
    income
  );
}

std::vector<state> get_win_states() noexcept
{
  std::vector<state> all_states;
  for (int n_villages = 0; n_villages != 5; ++n_villages)
  {
    for (int n_cities = 0; n_cities != 5; ++n_cities)
    {
      for (int n_development_points = 0; n_development_points != 8; ++n_development_points)
      {
        for (int has_longest_road = 0; has_longest_road != 2; ++has_longest_road)
        {
          for (int has_biggest_knight_force = 0; has_biggest_knight_force != 2; ++has_biggest_knight_force)
          {
            try
            {
              all_states.push_back(
                state(
                  n_villages,
                  n_cities,
                  has_longest_road,
                  has_biggest_knight_force,
                  n_development_points
                )
              );
            }
            catch (const std::logic_error&) {} // OK
          }
        }
      }
    }
  }
  std::vector<state> states;
  std::copy_if(
    std::begin(all_states),
    std::end(all_states),
    std::back_inserter(states),
    [](const state& s) { return count_points(s) == 10 || count_points(s) == 11; }
  );
  return states;
}

bool has_won(const state& s) noexcept
{
  return count_points(s) >= 10;
}

bool is_valid(const state& s) noexcept
{
  return
       s.get_n_villages() >= 0
    && s.get_n_villages() <= 5
    && s.get_n_cities() >= 0
    && s.get_n_cities() <= 5
    && s.get_n_villages() + s.get_n_cities() <= 10
    && s.get_n_development_points() >= 0
    && s.get_n_development_points() <= 5
    && sum_negatives(s.get_income()) == 0
  ;
}

state to_next_state(const state& s, const action& a)
{
  switch(a)
  {
    case action::build_village:
      return state(
        s.get_n_villages() + 1,
        s.get_n_cities(),
        s.get_has_longest_road(),
        s.get_has_biggest_knight_force(),
        s.get_n_development_points(),
        s.get_income()
          + get_extra_income(
            s.get_n_villages() + s.get_n_cities()
          )
      );
    case action::build_city:
      return state(
        s.get_n_villages() - 1,
        s.get_n_cities() + 1,
        s.get_has_longest_road(),
        s.get_has_biggest_knight_force(),
        s.get_n_development_points(),
        s.get_income()
          + get_extra_income(
            s.get_n_cities()
          )
      );
    case action::build_trade_route:
      return state(
        s.get_n_villages(),
        s.get_n_cities(),
        true,
        s.get_has_biggest_knight_force(),
        s.get_n_development_points(),
        s.get_income()
      );
    case action::buy_knight_force:
      return state(
        s.get_n_villages(),
        s.get_n_cities(),
        s.get_has_longest_road(),
        true,
        s.get_n_development_points(),
        s.get_income()
      );
    case action::buy_dev_point:
      return state(
        s.get_n_villages(),
        s.get_n_cities(),
        s.get_has_longest_road(),
        s.get_has_biggest_knight_force(),
        s.get_n_development_points() + 1,
        s.get_income()
      );
  }
  assert(37462374628 == 237366);
  return state();
}

std::ostream& operator<<(std::ostream& os, const state& s)
{
  os
    << "income: " << s.get_income()
    << ", n_villages: " << s.get_n_villages()
    << ", n_cities: " << s.get_n_cities()
    << ", trade_route: " << s.get_has_longest_road()
    << ", knight force: " << s.get_has_biggest_knight_force()
    << ", n_dev_points: " << s.get_n_development_points()
  ;
  return os;
}

void test_state()
{
  //A default state is not a win
  {
    assert(!has_won(state()));
  }
  //5 cities wins the game
  {
    const state s(0, 5);
    assert(s.get_n_villages() == 0);
    assert(s.get_n_cities() == 5);
    assert(!s.get_has_longest_road());
    assert(!s.get_has_biggest_knight_force());
    assert(has_won(s));
  }
  //2 villages and 4 cities wins the game
  {
    const state s(2, 4);
    assert(s.get_n_villages() == 2);
    assert(s.get_n_cities() == 4);
    assert(!s.get_has_longest_road());
    assert(!s.get_has_biggest_knight_force());
    assert(has_won(s));
  }
  //2 villages, 3 cities and longest road wins the game
  {
    const state s(2, 3, true);
    assert(s.get_n_villages() == 2);
    assert(s.get_n_cities() == 3);
    assert(s.get_has_longest_road());
    assert(!s.get_has_biggest_knight_force());
    assert(has_won(s));
  }
  //2 villages, 2 cities, longest road and biggest knight force wins the game
  {
    const state s(2, 2, true, true);
    assert(s.get_n_villages() == 2);
    assert(s.get_n_cities() == 2);
    assert(s.get_has_longest_road());
    assert(s.get_has_biggest_knight_force());
    assert(has_won(s));
  }
  //4 villages, 2 cities, 2 development points wins the game
  {
    const state s(4, 2, false, false, 2);
    assert(s.get_n_villages() == 4);
    assert(s.get_n_cities() == 2);
    assert(!s.get_has_longest_road());
    assert(!s.get_has_biggest_knight_force());
    assert(s.get_n_development_points() == 2);
    assert(has_won(s));
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
    const state a(1, 0, false, false, 0, income);
    const state b(2, 0, false, false, 0, income);
    const int n = calc_n_turns(a, b);
    assert(n == 8 * 4);
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
    const state b(0, 2, false, false, 0, income);
    const int n = calc_n_turns(a, b);
    assert(n == 11);
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
    const state b(1, 1, true, false, 0, income);
    const int n = calc_n_turns(a, b);
    assert(n == 3);
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
    const state b(1, 1, true, true, 0, income);
    const int n = calc_n_turns(a, b);
    assert(n == 6);
  }
  {
    const resources income(
      n_wood(9),
      n_brick(3),
      n_wheat(3 + 5),
      n_wool(0),
      n_ore(4)
    );
    const state start(2, 0, false, false, 0, income);
    const state end_1(5, 5, false, false, 0, income);
    const state end_2(5, 3, false, true, 0, income);
    assert(has_won(end_1));
    assert(has_won(end_2));
    const std::vector<int> ns = calc_n_turns(start, { end_1, end_2 } );
    assert(ns[0] < ns[1]);
  }
  {
    const resources income(
      n_wood(9),
      n_brick(3),
      n_wheat(3 + 5),
      n_wool(0),
      n_ore(4)
    );
    const state start(2, 0, false, false, 0, income);
    const auto win_states = get_win_states();
    const std::vector<int> ns = calc_n_turns(start, win_states);
    const auto n_win_states = win_states.size();
    const auto n_turnses = ns.size();

    assert(n_win_states == n_turnses);
    assert(n_win_states == 114);
  }
  // Acquiring a village generates extra income
  {
    const resources income(
      n_wood(9),
      n_brick(3),
      n_wheat(3 + 5),
      n_wool(0),
      n_ore(4)
    );
    const state begin(2, 0, false, false, 0, income);
    const state next{to_next_state(begin, action::build_village)};
    assert(next.get_income() > begin.get_income());
  }
  // Acquiring a city generates extra income
  {
    const resources income(
      n_wood(9),
      n_brick(3),
      n_wheat(3 + 5),
      n_wool(0),
      n_ore(4)
    );
    const state begin(2, 0, false, false, 0, income);
    const state next{to_next_state(begin, action::build_city)};
    assert(next.get_income() > begin.get_income());
  }
  //
}
