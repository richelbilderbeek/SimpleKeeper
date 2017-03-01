#ifndef ATTRACTIVENESS_GRID_H
#define ATTRACTIVENESS_GRID_H

#include <vector>
#include "grid_coordinat.h"
using attractiveness_grid = std::vector<std::vector<double>>;

attractiveness_grid create_attractiveness_grid(
  const int n_cols,
  const int n_rows,
  const double initial_value = 0.0
);

int get_grid_cell(const attractiveness_grid& g, const int x, const int y);
int get_grid_cell(const attractiveness_grid& g, const grid_coordinat c);

///4-way diffusion of values in grid g with coeffection coefficient d
void diffuse(std::vector<std::vector<double>>& g, const double d);

///Dilution of values in grid g with dilution d (the fraction that will be left)
void dilute(std::vector<std::vector<double>>& g, const double d);


#endif // ATTRACTIVENESS_GRID_H
