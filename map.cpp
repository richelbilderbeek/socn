#include "map.h"

#include <cassert>
#include <iostream>
#include <iterator>

map::map(
  const std::vector<std::vector<tile>>& tiles
) : m_tiles{tiles},
    m_robber{3,3}
{

}

std::vector<std::string> robber_as_text() noexcept
{
  return {
    R"|(    *---*    )|",
    R"|(   /     \   )|",
    R"|(             )|",
    R"|( /XXXXXXXXX\ )|",
    R"|(*X.ROBBER.XX*)|",
    R"|( \XXXXXXXXX/ )|",
    R"|(             )|",
    R"|(   \     /   )|",
    R"|(    *---*    )|"
  };
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
      const int x = tile_pos_to_canvas_pos(col_index, row_index).first;
      const int y = tile_pos_to_canvas_pos(col_index, row_index).second;
      draw(canvas, x, y, to_text(t));
    }
  }
  // Draw robber
  {
    const int col_index = m.get_robber().get_x();
    const int row_index = m.get_robber().get_y();
    const int x = tile_pos_to_canvas_pos(col_index, row_index).first;
    const int y = tile_pos_to_canvas_pos(col_index, row_index).second;
    draw(canvas, x, y, robber_as_text());
  }
  return canvas;
}


std::vector<std::vector<tile>> create_std_tiles()
{
  return
  {
    // 0
    std::vector<tile>(
      {
        tile(tile_type::sea),
        tile(tile_type::three_is_one_harbor, 0, 8),
        tile(tile_type::sea),
        tile(tile_type::three_is_one_harbor, 0, 8)
      }
    ),
    // 1
    std::vector<tile>(
      {
        tile(tile_type::wool_harbor, 0, 6),
        tile(tile_type::wheat, 9),
        tile(tile_type::wool, 4),
        tile(tile_type::wool, 10),
        tile(tile_type::sea)
      }
    ),
    // 2
    std::vector<tile>(
      {
        tile(tile_type::sea),
        tile(tile_type::wood, 6),
        tile(tile_type::wool, 12),
        tile(tile_type::ore, 8),
        tile(tile_type::wood, 11),
        tile(tile_type::wheat_harbor, 0, 8)
      }
    ),
    // 3
    std::vector<tile>(
      {
        tile(tile_type::ore_harbor, 0, 4),
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
        tile(tile_type::three_is_one_harbor, 0, 12)
      }
    ),
    std::vector<tile>(
      {
        tile(tile_type::wood_harbor, 0, 2),
        tile(tile_type::wool, 9),
        tile(tile_type::wood, 3),
        tile(tile_type::wheat, 3),
        tile(tile_type::sea)
      }
    ),
    std::vector<tile>(
      {
        tile(tile_type::sea),
        tile(tile_type::three_is_one_harbor, 0, 12),
        tile(tile_type::sea),
        tile(tile_type::bricks_harbor, 0, 12)
      }
    )
  };
}

constexpr std::pair<int, int> tile_pos_to_canvas_pos(
  const int col_index,
  const int row_index
) noexcept
{
  const int minx{24};
  const int dx{8};
  const int dy{4};
  if (row_index <= 3)
  {
    // Go at 8 o'clock angle
    const int x = minx + (col_index * dx) - (row_index * dx);
    const int y = (row_index * dy) + (col_index * dy);
    return { x, y };
  }
  else
  {
    // Go down
    assert(row_index > 3);
    const int delta_row = row_index - 3;
    const int x = minx + ((col_index + delta_row) * dx) - (row_index * dx);
    const int y = (row_index * dy) + ((col_index + delta_row) * dy);
    return { x, y };
  }
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
