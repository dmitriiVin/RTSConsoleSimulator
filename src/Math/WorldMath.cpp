#include "WorldMath.h"

ScreenPoint WorldToScreen(int column, int row) {
    ScreenPoint point;
    point.x = column * TILE_SIZE;
    point.y = row * TILE_SIZE;

    return point;
}
