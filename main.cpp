#include <vector>
#include <iostream>
#include "actions.h"
#include "action.h"
#include "resources.h"
#include "state.h"
#include "strategy.h"

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
}

int main()
{
  test();

  std::cout << get_all_actionses().size() << '\n';

  if (1 == 2)
  {
    const state begin;
    const std::vector<strategy> best_strategies{
      get_best_strategies(begin, 1)
    };
    std::cout << best_strategies[0] << '\n';
  }
  std::cout << "Done\n";
}
