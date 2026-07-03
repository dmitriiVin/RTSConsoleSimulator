//=================================================================================
//|                                                                             | |
//|  RTSEngine                                                                    |
//|  Камера и границы обзора                                                      |
//|  Хранит позицию экрана, размер окна                                           |
//|  и используется для ограничения движения.                                     |
//|                                            |                                  |
//=================================================================================
#pragma once
#include "Engine/Core/EngineConfig.h"
#include "Engine/Core/Time/EngineTime.h"
#include "Engine/Modules/TileMap/Map.h"
#include "Engine/Math/Isometric.h"
#include "SDL3/SDL.h"
#include <algorithm>

struct Camera {
    float x;
    float y;

    int viewportWidth;
    int viewportHeight;
};

void UpdateCamera(Camera &camera, SDL_Window *window, float deltaTime);
void ClampCamera(Camera &camera, const Map &map);
void UpdateViewport(Camera &camera, SDL_Window *window);
