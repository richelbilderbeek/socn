#include "tile.h"

#include <cassert>

tile::tile(
  const tile_type tile_type,
  const int dice_value
) : m_tile_type{tile_type},
    m_dice_value{dice_value}
{
  assert(dice_value == 0 || dice_value >= 2);
  assert(dice_value <= 12);
}


std::string add_spaces(std::string s, const int n_final_size)
{
  if (n_final_size <= static_cast<int>(s.size())) return s;
  s = s + " ";
  if (n_final_size == static_cast<int>(s.size())) return s;
  s = " " + s;
  if (n_final_size == static_cast<int>(s.size())) return s;
  return add_spaces(s, n_final_size);
}

void draw(
  std::vector<std::string>& canvas,
  const int x,
  const int y,
  const std::vector<std::string>& figure
)
{
  const int n_rows = static_cast<int>(figure.size());
  for (int row_index = 0; row_index != n_rows; ++row_index)
  {
    const auto& row = figure[static_cast<size_t>(row_index)];
    const int n_cols = static_cast<int>(row.size());
    for (int col_index = 0; col_index != n_cols; ++col_index)
    {
      const char c = row[static_cast<size_t>(col_index)];
      if (c != ' ')
      {
        if (y + row_index >= static_cast<int>(canvas.size())) continue;
        assert(y + row_index < static_cast<int>(canvas.size()));
        auto& canvas_row = canvas[static_cast<size_t>(y + row_index)];
        if (x + col_index >= static_cast<int>(canvas_row.size())) continue;
        assert(x + col_index < static_cast<int>(canvas_row.size()));
        canvas_row[static_cast<size_t>(x + col_index)] = c;
      }
    }
  }
}

std::vector<std::string> tile_base_as_text()
{
  return {
    R"|(    *-*    )|",
    R"|(   /   \   )|",
    R"|(           )|",
    R"|( /       \ )|",
    R"|(*         *)|",
    R"|( \       / )|",
    R"|(           )|",
    R"|(   \   /   )|",
    R"|(    *-*    )|"
  };
}

std::vector<std::string> to_text(const tile& t)
{
  std::vector<std::string> text = tile_base_as_text();
  // Paste resource text
  {
    std::string resource_text = to_str(t.get_tile_type());
    resource_text = add_spaces(resource_text, 9);
    const int n_chars = resource_text.size();
    for (int i = 0; i != n_chars; ++i)
    {
      text[4][1 + i] = resource_text[i];
    }
  }
  // Paste dice values
  if (t.get_dice_value())
  {
    std::string dice_text = std::to_string(t.get_dice_value());
    //dice_text = add_spaces(dice_text, 9);
    const int n_chars = dice_text.size();
    for (int i = 0; i != n_chars; ++i)
    {
      text[3][5 + i] = dice_text[i];
      text[5][5 + i] = dice_text[i];
    }
  }
  return text;
}

void test_tile()
{
  // add_spaces
  {
    assert(add_spaces("X", 2) == "X ");
  }
  {
    const std::vector<std::string> expected =
    {
      R"|(    *-*    )|",
      R"|(   /   \   )|",
      R"|(           )|",
      R"|( /       \ )|",
      R"|(*         *)|",
      R"|( \       / )|",
      R"|(           )|",
      R"|(   \   /   )|",
      R"|(    *-*    )|"
    };
    const auto created = tile_base_as_text();
    assert(expected == created);
  }
  {
    const std::vector<std::string> expected =
    {
      R"|(    *-*    )|",
      R"|(   /   \   )|",
      R"|(           )|",
      R"|( /   12  \ )|",
      R"|(*  wheat  *)|",
      R"|( \   12  / )|",
      R"|(           )|",
      R"|(   \   /   )|",
      R"|(    *-*    )|"
    };
    const auto created = to_text(
      tile(tile_type::wheat, 12)
    );
    assert(expected == created);
  }
}
