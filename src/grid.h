#ifndef _GRID_H_
#define _GRID_H_

#include <stdbool.h>

int count_neighbors(bool grid[10][10], int x, int y);

void update_grid(bool grid[10][10], bool (*rule)(bool, int));

bool is_valid_neighbor(int x, int y, int x_offset, int y_offset);

#endif