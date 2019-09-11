#include <stdbool.h>
#include <unity_fixture.h>
#include "grid.h"

TEST_GROUP(Grid);

TEST_SETUP(Grid) {}

TEST_TEAR_DOWN(Grid) {}

TEST(Grid, count_neighbors_returns_0_on_empty_grid)
{
    bool grid[10][10];
    fill_with_false(grid);

    TEST_ASSERT_EQUAL_INT(0, count_neighbors(grid, 1, 1));
}

TEST(Grid, count_neighbors_returns_1_if_the_cell_has_a_neighbor_to_the_left)
{
    bool grid[10][10];
    fill_with_false(grid);

    grid[0][0] = true;

    TEST_ASSERT_EQUAL_INT(1, count_neighbors(grid, 1, 0));
}

TEST(Grid, count_neighbors_returns_1_if_the_cell_has_a_neighbor_to_the_right)
{
    bool grid[10][10];
    fill_with_false(grid);

    grid[2][0] = true;

    TEST_ASSERT_EQUAL_INT(1, count_neighbors(grid, 1, 0));
}

TEST(Grid, count_neighbors_returns_2_if_the_cell_has_neighbors_to_the_left_and_right)
{
    bool grid[10][10];
    fill_with_false(grid);

    grid[0][0] = true;
    grid[2][0] = true;

    TEST_ASSERT_EQUAL_INT(2, count_neighbors(grid, 1, 0));
}

TEST(Grid, count_neighbors_returns_1_if_the_cell_has_a_neighbor_above)
{
    bool grid[10][10];
    fill_with_false(grid);

    grid[0][0] = true;

    TEST_ASSERT_EQUAL_INT(1, count_neighbors(grid, 0, 1));
}

TEST(Grid, count_neighbors_returns_1_if_the_cell_has_a_diagonal_neighbor)
{
    bool grid[10][10];
    fill_with_false(grid);

    grid[0][0] = true;

    TEST_ASSERT_EQUAL_INT(1, count_neighbors(grid, 1, 1));
}

bool fake_is_alive_returning_false(bool current, int neighbors)
{
    return false;
}

TEST(Grid, v)
{
    bool expected[10][10];
    bool actual[10][10];

    fill_with_false(expected);
    fill_with_false(actual);

    update_grid(actual, fake_is_alive_returning_false);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 10);
}

TEST_GROUP_RUNNER(Grid)
{
    RUN_TEST_CASE(Grid, count_neighbors_returns_0_on_empty_grid);
    RUN_TEST_CASE(Grid, count_neighbors_returns_1_if_the_cell_has_a_neighbor_to_the_left);
    RUN_TEST_CASE(Grid, count_neighbors_returns_1_if_the_cell_has_a_neighbor_to_the_right);
    RUN_TEST_CASE(Grid, count_neighbors_returns_2_if_the_cell_has_neighbors_to_the_left_and_right);
    RUN_TEST_CASE(Grid, count_neighbors_returns_1_if_the_cell_has_a_neighbor_above);
    RUN_TEST_CASE(Grid, count_neighbors_returns_1_if_the_cell_has_a_diagonal_neighbor);
    RUN_TEST_CASE(Grid, update_grid_leaves_an_empty_grid_empty_when_passed_a_function_that_always_returns_false);
}