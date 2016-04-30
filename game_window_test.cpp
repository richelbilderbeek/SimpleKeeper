#include "game_window.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(game_window_throw)
{
  //Too small
  BOOST_CHECK_THROW(game_window(32,32,0), std::invalid_argument);
  //No multiples of 32
  BOOST_CHECK_THROW(game_window(961,461,0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(game_window_show_one_second)
{
  const std::function<bool(const game_window&)> stop_function
    = [](const game_window& g) { return g.get_total_time_msec() > 2000; };
  game_window g(960,640,0,stop_function,__func__);
  g.execute();
}
