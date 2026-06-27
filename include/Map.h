#pragma once

#include "Unit.h"
#include <vector>

struct Map {
    int map_width;
    int map_height;
    std::vector<char> cells_map;
};

void PaintInConsole(const Map &map, const std::vector<Unit> &units);
Map CreateMap();
