#ifndef MAP_POS_H
#define MAP_POS_H

/// Position on the map.
/// There are two map_pos values possible per road,
/// as a road is adjacent to two tiles.
/// There are three map_pos values possible per settlement.
/// as a settlement is adjacent to three tiles.
class map_pos
{
public:
  /// @param x column index of the tile in the map tiles
  /// @param y row index of the tile in the map tiles
  /// @param orientation corner of the tile where a road, village
  ///   or city is. Follows the same orientation as the
  ///   clock:
  ///     0 = top flat part, for a road),
  ///     1 = top-right corner, for a settlement
  ///     2 = top-right flat part, for a road
  ///     3 = right corner, for a settlement
  ///   This value is 12 for the robber
  map_pos(
    const int x,
    const int y,
    const int orientation = 12
  );
  constexpr int get_x() const noexcept { return m_x; }
  constexpr int get_y() const noexcept { return m_y; }
  constexpr int get_orientation() const noexcept { return m_orientation; }

  private:
  const int m_x;
  const int m_y;
  const int m_orientation;
};

#endif // MAP_POS_H
