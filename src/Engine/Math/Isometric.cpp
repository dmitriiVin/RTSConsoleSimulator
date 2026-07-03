//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Формулы изометрии                                                            |
//|  Пересчитывает клетки карты в ромбы                                           |
//|  и оценивает размеры мира в пикселях.                                         |
//|                                                                               |
//=================================================================================
#include "Engine/Math/Isometric.h"

ScreenPoint WorldToScreen(int column, int row, const Camera &camera) {
    ScreenPoint point;

    point.x = (column - row) * HALF_TILE_WIDTH + camera.viewportWidth / 2.0f - camera.x;
    point.y = (column + row) * HALF_TILE_HEIGHT - camera.y;

    return point;
}

void ScreenToWorld(float screenX, float screenY, const Camera &camera, int &column, int &row) {
    // Возвращаем экранные координаты в систему мира
    screenX = screenX + camera.x - camera.viewportWidth / 2.0f;
    screenY = screenY + camera.y;

    // Нормализуем относительно размеров тайла
    float a = screenX / HALF_TILE_WIDTH;
    float b = screenY / HALF_TILE_HEIGHT;

    // Обратное преобразование
    float worldColumn = (a + b) * 0.5f;
    float worldRow = (b - a) * 0.5f;

    column = static_cast<int>(worldColumn);
    row = static_cast<int>(worldRow);
}

float GetMapPixelWidth(int mapWidth, int mapHeight) {
    return (mapWidth + mapHeight) * HALF_TILE_WIDTH;
}

float GetMapPixelHeight(int mapWidth, int mapHeight) {
    return (mapWidth + mapHeight) * HALF_TILE_HEIGHT;
}

MapBounds GetMapBounds(const Map &map, const Camera &camera) {
    ScreenPoint top = WorldToScreen(0, 0, camera);
    ScreenPoint left = WorldToScreen(0, map.map_height - 1, camera);
    ScreenPoint right = WorldToScreen(map.map_width - 1, 0, camera);
    ScreenPoint bottom = WorldToScreen(map.map_width - 1, map.map_height - 1, camera);

    MapBounds bounds;

    bounds.left = std::min({top.x, left.x, right.x, bottom.x});
    bounds.right = std::max({top.x, left.x, right.x, bottom.x});

    bounds.top = std::min({top.y, left.y, right.y, bottom.y});
    bounds.bottom = std::max({top.y, left.y, right.y, bottom.y});

    return bounds;
}
