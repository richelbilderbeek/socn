#include "map.h"

#include <cassert>

map::map(
  const std::vector<std::vector<tile>>& tiles
) : m_tiles{tiles}
{

}


std::vector<std::vector<tile>> create_std_tiles()
{
  return
  {
    std::vector<tile>(4),
    std::vector<tile>(5),
    std::vector<tile>(6),
    std::vector<tile>(7),
    std::vector<tile>(6),
    std::vector<tile>(5),
    std::vector<tile>(4)
  };
}

void test_map()
{
  {
    const map m;
    assert(!m.get_tiles().empty());
  }
}
