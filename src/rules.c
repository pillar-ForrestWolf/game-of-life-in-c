#include "rules.h"

bool live_cell_stays_alive(int neighbors) {
    return neighbors > 1 && neighbors < 4;
}

bool cell_alive(bool alive_now, int neighbors)
{
    return live_cell_stays_alive(neighbors) && alive_now;
}