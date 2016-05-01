#ifndef GRID_COORDINAT_H
#define GRID_COORDINAT_H

#include <utility>

using grid_coordinat = std::pair<int,int>;

grid_coordinat create_grid_coordinat(const int x, const int y);

int get_x(const grid_coordinat g);
int get_y(const grid_coordinat g);


///Obtain the coordinat above the current
grid_coordinat get_above(grid_coordinat c, const int n_rows);

///Obtain the coordinat below the current
grid_coordinat get_below(grid_coordinat c, const int n_rows);

///Obtain the coordinat left of the current
grid_coordinat get_left(grid_coordinat c, const int n_cols);

///Obtain the coordinat right of the current
grid_coordinat get_right(grid_coordinat c, const int n_cols);

#endif // GRID_COORDINAT_H
