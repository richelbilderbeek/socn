#ifndef MAP_H
#define MAP_H

#include "tile.h"

#include <iosfwd>
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

std::ostream& operator<<(std::ostream& os, const map& m);

#endif // MAP_H
