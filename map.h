#ifndef MAP_H
#define MAP_H

#include "tile.h"

#include <iosfwd>
#include <vector>

// The island map, including everything on the board
class map
{
public:
  map(const std::vector<std::vector<tile>>& tiles = create_std_tiles());

  const auto& get_tiles() const noexcept { return m_tiles; }

  constexpr int get_robber_x() const noexcept { return m_robber_x; }
  constexpr int get_robber_y() const noexcept { return m_robber_y; }

private:
  // Row-column ordered
  std::vector<std::vector<tile>> m_tiles;

  /// Coordinat of the robber
  int m_robber_x;
  int m_robber_y;
};

void test_map();

/// Return the X coordinat on the grid, from a grid column index
/// @param col the Y index of a grid tile
constexpr std::pair<int, int> tile_pos_to_canvas_pos(
  const int col,
  const int row
) noexcept;

std::vector<std::string> to_text(const map& m);

/// Get the robber tile as text
std::vector<std::string> robber_as_text() noexcept;

std::ostream& operator<<(std::ostream& os, const map& m);

#endif // MAP_H
