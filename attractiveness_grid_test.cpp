#include "attractiveness_grid.h"
#include <sstream>
#include <boost/test/unit_test.hpp>

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

BOOST_AUTO_TEST_CASE(attractiveness_grid_dilute)
{
  auto good = create_attractiveness_grid(3,3);
  good[1][1] = 1.0;
  dilute(good, 0.9);
  BOOST_CHECK_CLOSE(good[0][0], 0.0, 0.01);
  BOOST_CHECK_CLOSE(good[0][1], 0.0, 0.01);
  BOOST_CHECK_CLOSE(good[0][2], 0.0, 0.01);
  BOOST_CHECK_CLOSE(good[1][0], 0.0, 0.01);
  BOOST_CHECK_CLOSE(good[1][1], 0.9, 0.01);
  BOOST_CHECK_CLOSE(good[1][2], 0.0, 0.01);
  BOOST_CHECK_CLOSE(good[2][0], 0.0, 0.01);
  BOOST_CHECK_CLOSE(good[2][1], 0.0, 0.01);
  BOOST_CHECK_CLOSE(good[2][2], 0.0, 0.01);
}

BOOST_AUTO_TEST_CASE(attractiveness_grid_dilute_throw)
{
  auto good = create_attractiveness_grid(3,3);
  BOOST_CHECK_THROW(dilute(good, 3.14), std::invalid_argument);
  auto empty = attractiveness_grid();
  BOOST_CHECK_THROW(dilute(empty, 0.5), std::invalid_argument);
  auto one_row = attractiveness_grid(1, std::vector<double>(0));
  BOOST_CHECK_THROW(dilute(one_row, 0.5), std::invalid_argument);
}
