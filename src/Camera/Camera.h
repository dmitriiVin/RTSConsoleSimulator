#pragma once
#include "Config.h"
#include "EngineTime.h"
#include "Map.h"
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
