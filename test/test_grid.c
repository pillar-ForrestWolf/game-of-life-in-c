#include <stdbool.h>
#include <unity_fixture.h>
#include "grid.h"

TEST_GROUP(Grid);

TEST_SETUP(Grid) {}

TEST_TEAR_DOWN(Grid) {}

TEST(Grid, count_neighbors_returns_0_on_empty_grid)
{
    bool grid[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = false;
        }
    }

    TEST_ASSERT_EQUAL_INT(count_neighbors(grid, 1, 1), 0);
}

TEST_GROUP_RUNNER(Grid)
{
    RUN_TEST_CASE(Grid, count_neighbors_returns_0_on_empty_grid);
}