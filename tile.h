#ifndef TILE_H
#define TILE_H

#include "resource_type.h"

#include <string>
#include <vector>

class tile
{
public:
  tile(
    const resource_type resource_type = resource_type::wheat,
    const int dice_value = 12
  );

  auto get_resource_type() const noexcept { return m_resource_type; }
  auto get_dice_value() const noexcept { return m_dice_value; }

private:
  resource_type m_resource_type;
  int m_dice_value;
};

/// Create the standard tiles
std::vector<std::vector<tile>> create_std_tiles();

std::vector<std::string> tile_base_as_text();

std::vector<std::string> to_text(const tile& t);

void test_tile();

#endif // TILE_H
