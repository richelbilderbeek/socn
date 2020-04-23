#include "state.h"
#include <cassert>

state::state()
{

}

bool has_won(const state& ) noexcept
{
  return false;
}

void test_state()
{
  //A default state is not a win
  {
    assert(!has_won(state()));
  }
}
