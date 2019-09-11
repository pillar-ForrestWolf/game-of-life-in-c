#include "grid.h"

bool is_valid_neighbor(int x, int y, int x_offset, int y_offset)
{
    bool is_same_cell = (x_offset == 0 && y_offset == 0);
    bool x_outside_array = (x + x_offset < 0 || x + x_offset >= 10);
    bool y_outside_array = (y + y_offset < 0 || y + y_offset >= 10);

    return !(is_same_cell || x_outside_array || y_outside_array);
}

int count_neighbors(bool grid[10][10], int x, int y)
{
    int neighbors = 0;

    for (int x_offset = -1; x_offset < 2; x_offset++)
    {
        for (int y_offset = -1; y_offset < 2; y_offset++)
        {
            if (is_valid_neighbor(x, y, x_offset, y_offset) && grid[x + x_offset][y + y_offset])
            {
                neighbors++;
            }
        }
    }

    return neighbors;
};

void update_grid(bool grid[10][10], bool (*rule)(bool, int))
{
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            grid[x][y] = rule(grid[x][y], count_neighbors(grid, x, y));
        }
    }
}
