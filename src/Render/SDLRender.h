#pragma once
#include "Config.h"
#include "Map.h"
#include "SDL3/SDL.h"
#include "Unit.h"
#include <SDL3/SDL_video.h>

void Render(const Map &map, const std::vector<Unit> &units);
void RenderMap(SDL_Renderer *renderer, const Map &map);
