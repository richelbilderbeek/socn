#include "actions.h"
#include "action.h"
#include "resources.h"
#include "state.h"
#include "strategy.h"

#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>

void test()
{
  test_n_brick();
  test_n_ore();
  test_n_wheat();
  test_n_wood();
  test_n_wool();
  test_resources();

  test_action();
  test_actions();
  test_state();
  test_strategy();
}

int main()
{
  test();

  const state begin = get_richels_favorite_begin_state();
  const auto all_strategies = get_all_strategies(begin);
  const int top_n = 10;

  std::cout << "=====================================================\n";
  std::cout << "= ALL STRATEGIES                                    =\n";
  std::cout << "=====================================================\n";  
  for (auto i = 0u; i != top_n; ++i)
  {
    std::cout << "[" << i << "] "
      << calc_n_turns(all_strategies[i])
      << " turn when playing: \n" << all_strategies[i] << '\n'
      << '\n'
    ;
  }

  std::cout << "=====================================================\n";
  std::cout << "= WORST STRATEGIES                                  =\n";
  std::cout << "=====================================================\n";
  auto worst_strategies = all_strategies;
  std::partial_sort(
    std::begin(worst_strategies), std::end(worst_strategies),
    std::begin(worst_strategies) + top_n,
    [](const strategy& lhs, const strategy& rhs)
    {
      return calc_n_turns(lhs) > calc_n_turns(rhs);
    }
  );
  for (auto i = 0u; i != top_n; ++i)
  {
    std::cout << "[" << i << "] "
      << calc_n_turns(worst_strategies[i])
      << " turn when playing: \n" << worst_strategies[i] << '\n'
      << '\n'
    ;
  }

  std::cout << "=====================================================\n";
  std::cout << "= BEST STRATEGIES                                   =\n";
  std::cout << "=====================================================\n";
  auto best_strategies = all_strategies;
  std::partial_sort(
    std::begin(best_strategies), std::end(best_strategies),
    std::begin(best_strategies) + top_n,
    [](const strategy& lhs, const strategy& rhs)
    {
      assert(calc_n_turns(lhs) > 0);
      assert(calc_n_turns(rhs) > 0);
      return calc_n_turns(lhs) < calc_n_turns(rhs);
    }
  );
  for (auto i = 0u; i != top_n; ++i)
  {
    std::cout << "[" << i << "] "
      << calc_n_turns(all_strategies[i])
      << " turn when playing: \n" << best_strategies[i] << '\n'
      << '\n'
    ;
  }
  std::cout << "Done\n";
}
