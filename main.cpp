#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include "game_window.h"


int main()
{
  try
  {
    game_window g(960,640,10);
    g.execute();
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }
}
