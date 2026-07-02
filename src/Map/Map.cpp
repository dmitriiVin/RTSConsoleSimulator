#include "Map.h"
#include "MapGenerator.h"
#include "Unit.h"

#include <iostream>
#include <vector>

Map CreateMap() {
    Map map;
    map.map_width = 100;
    map.map_height = 100;

    int points = map.map_width * map.map_height;

    map.cells_map = std::vector<char>(points, '.');

    GenerateMap(map);

    return map;
}
