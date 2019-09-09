#include "rules.h"

bool cell_alive(bool alive_now, int neighbors)
{
    return neighbors > 1 && neighbors < 4;
}