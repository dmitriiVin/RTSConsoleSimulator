//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Модель карты                                                                 |
//|  Хранит размеры, линейный массив клеток                                       |
//|  и интерфейс для создания/печати мира.                                        |
//|                                                                               |
//=================================================================================
#pragma once

#include "Engine/Modules/TileMap/Tile.h"
#include "Game/Units/Unit.h"
#include <vector>

struct Map {
    int map_width;
    int map_height;
    std::vector<char> cells_map;
};

void PaintInConsole(const Map &map, const std::vector<Unit> &units);
Map CreateMap();
