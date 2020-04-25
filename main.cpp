#include <vector>
#include <iostream>
#include "resources.h"
#include "state.h"
#include "strategy.h"

void test()
{
  test_resources();
  test_state();
}

int main()
{
  test();

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
