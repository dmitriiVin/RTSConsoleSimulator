//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  SDL-рендерер                                                                 |
//|  Окно, кадр отрисовки и функции                                               |
//|  для рисования изометрической карты.                                          |
//|                                                                               |
//=================================================================================
#pragma once

#include "Engine/Camera/Camera.h"
#include "Engine/Core/EngineConfig.h"
#include "Engine/Core/Time/EngineTime.h"
#include "Engine/Math/Isometric.h"
#include "Engine/Modules/TileMap/Map.h"
#include "Engine/Render/ViewCulling.h"
#include "Game/Units/Unit.h"
#include "SDL3/SDL.h"
#include <stdio.h>

void Render(const Map &map, const std::vector<Unit> &units);
void RenderMap(SDL_Renderer *renderer, const Map &map, const Camera &camera, const VisibleArea &visibleArea);
void DrawIsometricTile(SDL_Renderer *renderer, float x, float y);
