#include "tile.h"

#include <cassert>

tile::tile()
{

}

std::vector<std::string> to_text(const tile& t)
{
  return {
    R"|(    *-*    )|",
    R"|(   /   \   )|",
    R"|(           )|",
    R"|( /       \ )|",
    R"|(*         *)|",
    R"|( \       / )|",
    R"|(           )|",
    R"|(   \   /   )|",
    R"|(    *-*    )|"
  };
}

void test_tile()
{
  {
    const std::vector<std::string> expected =
    {
      R"|(    *-*    )|",
      R"|(   /   \   )|",
      R"|(           )|",
      R"|( /       \ )|",
      R"|(*         *)|",
      R"|( \       / )|",
      R"|(           )|",
      R"|(   \   /   )|",
      R"|(    *-*    )|"
    };
    const auto created = to_text(tile());
    assert(expected == created);
  }
}
