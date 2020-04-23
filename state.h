#ifndef STATE_H
#define STATE_H


class state
{
public:
  state();
};


/// Is the state winning?
bool has_won(const state& s) noexcept;

/// Test the state
void test_state();


#endif // STATE_H
