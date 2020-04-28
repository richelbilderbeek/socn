#ifndef TILE_H
#define TILE_H

#include "tile_type.h"

#include <string>
#include <vector>

class tile
{
public:
  /// @param dice_value value to acquire the resource,
  ///   if the type is a resource. Use 0 otherwise
  /// @param orientation orientation of the tile, to
  ///   be used for harbors, usin the same orientation as a clock.
  ///   Use 12 for up, 2 for top-right, etc.
  ///   Use 0 if the orientation is unused.
  tile(
    const tile_type tile_type = tile_type::wheat,
    const int dice_value = 0,
    const int orientation = 0
  );

  constexpr auto get_tile_type() const noexcept { return m_tile_type; }
  constexpr auto get_dice_value() const noexcept { return m_dice_value; }
  constexpr auto get_orientation() const noexcept { return m_orientation; }

private:
  tile_type m_tile_type;
  int m_dice_value;
  int m_orientation;
};

/// Add spaces up until the string is of the final size.
/// The spacies will make the text be centered
std::string add_spaces(std::string s, const int n_final_size);

/// Is the tile a harbor?
constexpr bool is_harbor(const tile& t) noexcept;

/// Create the standard tiles
std::vector<std::vector<tile>> create_std_tiles();

/// Draw a figure on the canvas
void draw(
  std::vector<std::string>& canvas,
  const int x,
  const int y,
  const std::vector<std::string>& figure
);

std::vector<std::string> tile_base_as_text();

std::vector<std::string> to_text(const tile& t);

void test_tile();

#endif // TILE_H
