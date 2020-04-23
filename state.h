#ifndef STATE_H
#define STATE_H


class state
{
public:
  state(
    const int n_villages = 2,
    const int n_cities = 0,
    const bool has_longest_road = false,
    const bool has_biggest_knight_force = false,
    const int n_development_points = 0
  );

  bool get_has_biggest_knight_force() const noexcept { return m_has_biggest_knight_force; }
  bool get_has_longest_road() const noexcept { return m_has_longest_road; }
  int get_n_cities() const noexcept { return m_n_cities; }
  int get_n_development_points() const noexcept { return m_n_development_points; }
  int get_n_villages() const noexcept { return m_n_villages; }

private:

  /// Does the player have the biggest knight force?
  bool m_has_biggest_knight_force;

  /// Does the player have the longest road?
  bool m_has_longest_road;

  /// Number of cities
  int m_n_cities;

  /// Number of development points, from cards
  int m_n_development_points;

  /// Number of villages
  int m_n_villages;
};

/// Count the number of points
int count_points(const state& s) noexcept;

/// Is the state winning?
bool has_won(const state& s) noexcept;

/// Test the state
void test_state();


#endif // STATE_H
