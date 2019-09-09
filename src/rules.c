#include "rules.h"

bool live_cell_stays_alive(int neighbors) {
    return neighbors > 1 && neighbors < 4;
}

bool dead_cell_becomes_live(int neighbors) {
    return neighbors == 3;
}

bool cell_alive(bool alive_now, int neighbors)
{
    return alive_now ? live_cell_stays_alive(neighbors) : dead_cell_becomes_live(neighbors);
}