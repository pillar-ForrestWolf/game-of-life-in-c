#include <stdbool.h>
#include <unity_fixture.h>
#include "grid.h"

TEST_GROUP(Grid);

TEST_SETUP(Grid) {}

TEST_TEAR_DOWN(Grid) {}

void fill_with(bool val, bool grid[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            grid[i][j] = val;
        }
    }
}

TEST(Grid, count_neighbors_returns_0_on_empty_grid)
{
    bool grid[10][10];
    fill_with(false, grid);

    TEST_ASSERT_EQUAL_INT(0, count_neighbors(grid, 1, 1));
}

TEST(Grid, count_neighbors_returns_1_if_the_cell_has_a_neighbor_to_the_left)
{
    bool grid[10][10];
    fill_with(false, grid);

    grid[0][0] = true;

    TEST_ASSERT_EQUAL_INT(1, count_neighbors(grid, 1, 0));
}

TEST(Grid, count_neighbors_returns_1_if_the_cell_has_a_neighbor_to_the_right)
{
    bool grid[10][10];
    fill_with(false, grid);

    grid[2][0] = true;

    TEST_ASSERT_EQUAL_INT(1, count_neighbors(grid, 1, 0));
}

TEST(Grid, count_neighbors_returns_2_if_the_cell_has_neighbors_to_the_left_and_right)
{
    bool grid[10][10];
    fill_with(false, grid);

    grid[0][0] = true;
    grid[2][0] = true;

    TEST_ASSERT_EQUAL_INT(2, count_neighbors(grid, 1, 0));
}

TEST(Grid, count_neighbors_returns_1_if_the_cell_has_a_neighbor_above)
{
    bool grid[10][10];
    fill_with(false, grid);

    grid[0][0] = true;

    TEST_ASSERT_EQUAL_INT(1, count_neighbors(grid, 0, 1));
}

TEST(Grid, count_neighbors_returns_1_if_the_cell_has_a_diagonal_neighbor)
{
    bool grid[10][10];
    fill_with(false, grid);

    grid[0][0] = true;

    TEST_ASSERT_EQUAL_INT(1, count_neighbors(grid, 1, 1));
}

bool fake_is_alive_returning_false(bool current, int neighbors)
{
    return false;
}

TEST(Grid, update_grid_leaves_an_empty_grid_empty_when_passed_a_function_that_always_returns_false)
{
    bool expected[10][10];
    bool actual[10][10];

    fill_with(false, expected);
    fill_with(false, actual);

    update_grid(actual, fake_is_alive_returning_false);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 10);
}

bool fake_is_alive_returning_true(bool current, int neighbors)
{
    return true;
}

TEST(Grid, update_grid_fills_an_empty_grid_with_true_when_passed_a_function_that_always_returns_true)
{
    bool expected[10][10];
    bool actual[10][10];

    fill_with(true, expected);
    fill_with(false, actual);

    update_grid(actual, fake_is_alive_returning_true);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 10);
}

bool fake_is_alive_returning_opposite(bool current, int neighbors)
{
    return !current;
}

TEST(Grid, update_grid_flips_values_when_passed_a_function_that_returns_the_opposite_of_its_input)
{
    bool expected[10][10];
    bool actual[10][10];

    fill_with(true, expected);
    expected[2][2] = false;

    fill_with(false, actual);
    actual[2][2] = true;

    update_grid(actual, fake_is_alive_returning_opposite);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 10);
}

bool fake_is_alive_returning_true_if_true_and_has_neighbor(bool current, int neighbors)
{
    return current && neighbors > 0;
}

TEST(Grid, update_grid_calls_passed_function_with_number_of_true_neighbors)
{
    bool expected[10][10];
    bool actual[10][10];

    fill_with(false, expected);
    expected[2][2] = true;
    expected[2][3] = true;

    fill_with(false, actual);
    actual[2][2] = true;
    actual[2][3] = true;
    actual[7][7] = true;

    update_grid(actual, fake_is_alive_returning_true_if_true_and_has_neighbor);

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
    RUN_TEST_CASE(Grid, update_grid_fills_an_empty_grid_with_true_when_passed_a_function_that_always_returns_true);
    RUN_TEST_CASE(Grid, update_grid_flips_values_when_passed_a_function_that_returns_the_opposite_of_its_input);
    RUN_TEST_CASE(Grid, update_grid_calls_passed_function_with_number_of_true_neighbors);
}