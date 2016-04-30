#include "attractiveness_grid.h"
#include <boost/test/unit_test.hpp>
#include <sstream>

BOOST_AUTO_TEST_CASE(attractiveness_grid_diffusion)
{
  auto good = create_attractiveness_grid(3,3);
  good[1][1] = 1.0;
  diffuse(good, 0.1);
  BOOST_CHECK_CLOSE(good[0][0], 0.0  , 0.01);
  BOOST_CHECK_CLOSE(good[0][1], 0.025, 0.01);
  BOOST_CHECK_CLOSE(good[0][2], 0.0  , 0.01);
  BOOST_CHECK_CLOSE(good[1][0], 0.025, 0.01);
  BOOST_CHECK_CLOSE(good[1][1], 0.9  , 0.01);
  BOOST_CHECK_CLOSE(good[1][2], 0.025, 0.01);
  BOOST_CHECK_CLOSE(good[2][0], 0.0  , 0.01);
  BOOST_CHECK_CLOSE(good[2][1], 0.025, 0.01);
  BOOST_CHECK_CLOSE(good[2][2], 0.0  , 0.01);
}

BOOST_AUTO_TEST_CASE(attractiveness_grid_diffusion_throw)
{
  auto good = create_attractiveness_grid(3,3);
  BOOST_CHECK_THROW(diffuse(good, 3.14), std::invalid_argument);
  auto empty = attractiveness_grid();
  BOOST_CHECK_THROW(diffuse(empty, 0.5), std::invalid_argument);
  auto one_row = attractiveness_grid(1, std::vector<double>(0));
  BOOST_CHECK_THROW(diffuse(one_row, 0.5), std::invalid_argument);

}

/*
void dilute(attractiveness_grid& g, const double d)
{
  if (d <= 0.0 || d >= 1.0)
  {
    std::stringstream msg;
    msg << __func__ << ": dilution must be in range <0,1>";
    throw std::invalid_argument(msg.str());
  }
  const int n_rows{static_cast<int>(g.size())};
  if (n_rows == 0)
  {
    std::stringstream msg;
    msg << __func__ << ": grid must have rows";
    throw std::invalid_argument(msg.str());
  }
  const int n_cols{static_cast<int>(g.size())};
  if (n_cols == 0)
  {
    std::stringstream msg;
    msg << __func__ << ": grid must have columns";
    throw std::invalid_argument(msg.str());
  }
  for (int y{0}; y!=n_rows; ++y)
  {
    for (int x{0}; x!=n_cols; ++x)
    {
      g[y][x] *= d;
    }
  }
}
*/
