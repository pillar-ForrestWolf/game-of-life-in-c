#ifndef _GRID_H_
#define _GRID_H_

#include <stdbool.h>

int count_neighbors(bool grid[10][10], int x, int y);

void update_grid(bool grid[10][10] );

void fill_with_false(bool grid[10][10] );

#endif