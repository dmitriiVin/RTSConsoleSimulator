#include "Isometric.h"

#include "Camera.h"
#include "Config.h"

ScreenPoint WorldToScreen(int column, int row, const Camera &camera) {
    ScreenPoint point;

    point.x = (column - row) * HALF_TILE_WIDTH + camera.viewportWidth / 2.0f - camera.x;
    point.y = (column + row) * HALF_TILE_HEIGHT - camera.y;

    return point;
}

void ScreenToWorld(float screenX, float screenY, const Camera &camera, int &column, int &row) {
    screenX += camera.x;
    screenY += camera.y;

    float worldX = (screenX / HALF_TILE_WIDTH + screenY / HALF_TILE_HEIGHT) * 0.5f;

    float worldY = (screenY / HALF_TILE_HEIGHT - screenX / HALF_TILE_WIDTH) * 0.5f;

    column = static_cast<int>(worldX);
    row = static_cast<int>(worldY);
}

float GetMapPixelWidth(int mapWidth, int mapHeight) {
    return (mapWidth + mapHeight) * HALF_TILE_WIDTH;
}

float GetMapPixelHeight(int mapWidth, int mapHeight) {
    return (mapWidth + mapHeight) * HALF_TILE_HEIGHT;
}
