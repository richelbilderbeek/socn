#ifndef TILE_H
#define TILE_H

#include <string>
#include <vector>

class tile
{
public:
  tile();
};

std::vector<std::string> to_text(const tile& t);

void test_tile();

#endif // TILE_H
