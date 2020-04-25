#include "tile.h"

#include <cassert>

tile::tile(
  const resource_type resource_type,
  const int dice_value
) : m_resource_type{resource_type},
    m_dice_value{dice_value}
{
  assert(dice_value >= 2);
  assert(dice_value <= 12);
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
    std::string resource_text = to_str(t.get_resource_type());
    const int n_chars = resource_text.size();
    for (int i = 0; i != n_chars; ++i)
    {
      text[4][3 + i] = resource_text[i];
    }
  }
  // Paste dice values
  {
    std::string dice_text = std::to_string(t.get_dice_value());
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
      tile(resource_type::wheat, 12)
    );
    assert(expected == created);
  }
}
