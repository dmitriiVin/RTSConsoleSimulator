#pragma once
#include "Config.h"
#include "SDL3/SDL.h"

struct Camera {
    float x;
    float y;
};

void UpdateCamera(Camera &camera);
