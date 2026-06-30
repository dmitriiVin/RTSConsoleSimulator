#pragma once

#include "Camera.h"
#include "Config.h"
#include "Map.h"
#include "SDL3/SDL.h"
#include "SDL3/SDL_render.h"
#include "Unit.h"
#include "WorldMath.h"
#include <SDL3/SDL_video.h>
#include <stdio.h>

void Render(const Map &map, const std::vector<Unit> &units);
void RenderMap(SDL_Renderer *renderer, const Map &map, const Camera &camera);
