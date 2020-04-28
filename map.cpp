#include "map.h"

#include <cassert>
#include <iostream>
#include <iterator>

map::map(
  const std::vector<std::vector<tile>>& tiles
) : m_tiles{tiles}
{

}

std::vector<std::string> to_text(const map& m)
{
  std::vector<std::string> canvas(57, std::string(61, ' '));
  const int n_rows = static_cast<int>(m.get_tiles().size());
  for (int row_index = 0; row_index != n_rows; ++row_index)
  {
    const auto& row = m.get_tiles()[static_cast<size_t>(row_index)];
    const int n_cols = static_cast<int>(row.size());
    for (int col_index = 0; col_index != n_cols; ++col_index)
    {
      const tile& t = row[static_cast<size_t>(col_index)];
      if (row_index <= 3)
      {
        // Go at 8 o'clock angle
        const int x = 24 + (col_index * 8) - (row_index * 8);
        const int y = (row_index * 4) + (col_index * 4);
        draw(canvas, x, y, to_text(t));
      }
      else
      {
        // Go down
        assert(row_index > 3);
        const int delta = row_index - 3;
        const int x = 24 + ((col_index + delta) * 8) - (row_index * 8);
        const int y = (row_index * 4) + ((col_index + delta) * 4);
        draw(canvas, x, y, to_text(t));
      }
    }
  }
  return canvas;
}


std::vector<std::vector<tile>> create_std_tiles()
{
  return
  {
    std::vector<tile>(
      {
        tile(tile_type::sea),
        tile(tile_type::three_is_one_harbor),
        tile(tile_type::sea),
        tile(tile_type::three_is_one_harbor)
      }
    ),
    std::vector<tile>(
      {
        tile(tile_type::wool_harbor),
        tile(tile_type::wheat, 9),
        tile(tile_type::wool, 4),
        tile(tile_type::wool, 10),
        tile(tile_type::sea)
      }
    ),
    std::vector<tile>(
      {
        tile(tile_type::sea),
        tile(tile_type::wood, 6),
        tile(tile_type::wool, 12),
        tile(tile_type::ore, 8),
        tile(tile_type::wood, 11),
        tile(tile_type::wheat_harbor)
      }
    ),
    std::vector<tile>(
      {
        tile(tile_type::ore_harbor),
        tile(tile_type::wheat, 4),
        tile(tile_type::wood, 5),
        tile(tile_type::desert),
        tile(tile_type::bricks, 10),
        tile(tile_type::ore, 11),
        tile(tile_type::sea)
      }
    ),
    std::vector<tile>(
      {
        tile(tile_type::sea),
        tile(tile_type::bricks, 2),
        tile(tile_type::bricks, 8),
        tile(tile_type::ore, 5),
        tile(tile_type::wheat, 6),
        tile(tile_type::three_is_one_harbor)
      }
    ),
    std::vector<tile>(
      {
        tile(tile_type::wood_harbor),
        tile(tile_type::wool, 9),
        tile(tile_type::wood, 3),
        tile(tile_type::wheat, 3),
        tile(tile_type::sea)
      }
    ),
    std::vector<tile>(
      {
        tile(tile_type::sea),
        tile(tile_type::three_is_one_harbor),
        tile(tile_type::sea),
        tile(tile_type::bricks_harbor)
      }
    )
  };
}

std::ostream& operator<<(std::ostream& os, const map& m)
{
  const auto text = to_text(m);
  std::copy(
    std::begin(text),
    std::end(text),
    std::ostream_iterator<std::string>(os, "\n")
  );
  return os;
}

void test_map()
{
  {
    const map m;
    assert(!m.get_tiles().empty());
  }
}
