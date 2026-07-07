#pragma once

#include <SDL3/SDL.h>

struct Texture {
    SDL_Texture *texture = nullptr;

    int width = 0;
    int height = 0;
};
