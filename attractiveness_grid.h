#ifndef ATTRACTIVENESS_GRID_H
#define ATTRACTIVENESS_GRID_H

#include <vector>

using attractiveness_grid = std::vector<std::vector<double>>;

attractiveness_grid create_attractiveness_grid(const int n_cols, const int n_rows);

///4-way diffusion of values in grid g with coeffection coefficient d
void diffuse(attractiveness_grid& g, const double d);

///Dilution of values in grid g with dilution d (the fraction that will be left)
void dilute(attractiveness_grid& g, const double d);

#endif // ATTRACTIVENESS_GRID_H
