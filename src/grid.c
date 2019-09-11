#include "grid.h"

int count_neighbors(bool grid[10][10], int x, int y)
{
    int neighbors = 0;

    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            bool is_same_cell = (i == 0 && j == 0);
            bool outside_array = (x + i < 0 || x + i >= 10 || y + j < 0 || y + j >= 10);

            if (!is_same_cell && !outside_array && grid[x + i][y + j])
            {
                neighbors++;
            }
        }
    }

    return neighbors;
};

void update_grid(bool grid[10][10])
{
}

void fill_with_false(bool grid[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            grid[i][j] = false;
        }
    }
}
