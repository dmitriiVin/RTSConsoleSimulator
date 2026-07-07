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
#include "Engine/Render/Texture.h"
#include "Engine/Render/TextureManager.h"
#include "Engine/Render/ViewCulling.h"
#include "Game/Units/Unit.h"
#include "SDL3/SDL.h"
#include <stdio.h>

void Render(const Map &map, const std::vector<Unit> &units);
void RenderMap(SDL_Renderer *renderer, const Map &map, const Camera &camera, const VisibleArea &visibleArea, const TextureManager &textures);
void DrawTexture(SDL_Renderer *renderer, const Texture &texture, float x, float y);
