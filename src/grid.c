#include "grid.h"

int count_neighbors(bool grid[10][10], int x, int y)
{
    int neighbors = 0;

    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            bool is_same_cell = (i == 0 && j == 0);

            if (!is_same_cell && grid[x + i][y + j])
            {
                neighbors++;
            }
        }
    }

    return neighbors;
};
