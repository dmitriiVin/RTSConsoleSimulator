#include "Camera.h"
#include "WorldMath.h"

ScreenPoint WorldToScreen(int column, int row, const Camera &camera) {
    ScreenPoint point;

    point.x = column * TILE_SIZE - camera.x;
    point.y = row * TILE_SIZE - camera.y;

    return point;
}
