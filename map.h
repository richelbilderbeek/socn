#ifndef MAP_H
#define MAP_H

#include "tile.h"

#include <vector>

// The island map
class map
{
public:
  map(const std::vector<std::vector<tile>>& tiles = create_std_tiles());

  const auto& get_tiles() const noexcept { return m_tiles; }

private:
  // Row-column ordered
  std::vector<std::vector<tile>> m_tiles;
};

void test_map();

std::vector<std::string> to_text(const map& m);

/*
 7 layers high
 7 wide
 24 rows

so a tile may be 10 wide and high...



 01234567890123456789
 +---------+---------
0|  *****  |    **
1| *     * |   *  *
2|*       *|  *    *
3| *     * | *      *
4|  *****  | *      *
5|           *      *
6|            *    *
7|             *  *
8|              **
9|


*/
#endif // MAP_H
