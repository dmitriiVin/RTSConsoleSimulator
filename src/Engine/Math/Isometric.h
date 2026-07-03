//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Изометрия координат                                                          |
//|  Переводит координаты мира в экранные                                         |
//|  и обратно, чтобы карта рисовалась корректно.                                 |
//|                                                                               |
//=================================================================================
#pragma once

#include "Engine/Camera/Camera.h"
#include "Engine/Core/EngineConfig.h"
#include "Engine/Math/ScreenPoint.h"

#include <algorithm>

struct MapBounds {
    float left;
    float right;
    float top;
    float bottom;
};

struct Camera;

ScreenPoint WorldToScreen(int column, int row, const Camera &camera);

void ScreenToWorld(float screenX, float screenY, const Camera &camera, int &column, int &row);

float GetMapPixelWidth(int mapWidth, int mapHeight);
float GetMapPixelHeight(int mapWidth, int mapHeight);

MapBounds GetMapBounds(const Map &map, const Camera &camera);
