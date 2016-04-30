#include "attractiveness_grid.h"

#include <sstream>

attractiveness_grid create_attractiveness_grid(const int n_cols, const int n_rows)
{
  if (n_rows == 0)
  {
    std::stringstream msg;
    msg << __func__ << ": grid must have rows";
    throw std::invalid_argument(msg.str());
  }
  if (n_cols == 0)
  {
    std::stringstream msg;
    msg << __func__ << ": grid must have columns";
    throw std::invalid_argument(msg.str());
  }
  return attractiveness_grid(n_rows, std::vector<double>(n_cols, 0.0));
}

void diffuse(attractiveness_grid& g, const double d)
{
  if (d <= 0.0 || d >= 1.0)
  {
    std::stringstream msg;
    msg << __func__ << ": diffusion must be in range <0,1>";
    throw std::invalid_argument(msg.str());
  }
  const attractiveness_grid original(g);
  const int n_rows{static_cast<int>(g.size())};
  if (n_rows == 0)
  {
    std::stringstream msg;
    msg << __func__ << ": grid must have rows";
    throw std::invalid_argument(msg.str());
  }
  const int n_cols{static_cast<int>(g[0].size())};
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
      const int x_left {(x - 1 + n_cols) % n_cols};
      const int x_right{(x + 1 + n_cols) % n_cols};
      const int y_above{(y - 1 + n_rows) % n_rows};
      const int y_below{(y + 1 + n_rows) % n_rows};
      const double z_left  = original[y][x_left ];
      const double z_right = original[y][x_right];
      const double z_above = original[y_above][x];
      const double z_below = original[y_below][x];
      const double z_here = original[y][x];
      const double z = (0.25 * d * z_above) + (0.25 * d * z_right) + (0.25 * d * z_below) + (0.25 * d * z_left) + ((1.0 - d) * z_here);
      g[y][x] = z;
    }
  }
}

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
  const int n_cols{static_cast<int>(g[0].size())};
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
