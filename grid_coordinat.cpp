#include "grid_coordinat.h"

#include <cassert>
#include <sstream>
#include <stdexcept>

grid_coordinat create_grid_coordinat(const int x, const int y)
{
  if (x < 0)
  {
    std::stringstream msg;
    msg << __func__ << ": cannot create grid coordinat with x < 0";
    throw std::invalid_argument(msg.str());
  }
  if (y < 0)
  {
    std::stringstream msg;
    msg << __func__ << ": cannot create grid coordinat with y < 0";
    throw std::invalid_argument(msg.str());
  }
  return std::make_pair(x, y);
}

///Obtain the coordinat above the current
grid_coordinat get_above(grid_coordinat c, const int n_rows)
{
  c.second = (c.second - 1 + n_rows) % n_rows;
  return c;
}

///Obtain the coordinat below the current
grid_coordinat get_below(grid_coordinat c, const int n_rows)
{
  c.second = (c.second + 1) % n_rows;
  return c;
}

///Obtain the coordinat left of the current
grid_coordinat get_left(grid_coordinat c, const int n_cols)
{
  c.first = (c.first - 1 + n_cols) % n_cols;
  return c;
}

///Obtain the coordinat right of the current
grid_coordinat get_right(grid_coordinat c, const int n_cols)
{
  c.first = (c.first + 1) % n_cols;
  return c;
}


int get_x(const grid_coordinat g)
{
  assert(g.first >= 0);
  return g.first;
}

int get_y(const grid_coordinat g)
{
  assert(g.second >= 0);
  return g.second;
}
