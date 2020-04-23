#include <iostream>
#include "resources.h"
#include "state.h"

void test()
{
  test_resources();
  test_state();
}

int main()
{
  test();

  std::cout << "Done\n";
}
