#pragma once
#include "Config.h"
#include "Map.h"
#include "SDL3/SDL.h"
#include <algorithm>

struct Camera {
    float x;
    float y;

    int viewportWidth;
    int viewportHeight;
};

void UpdateCamera(Camera &camera, SDL_Window *window);
void ClampCamera(Camera &camera, const Map &map);
