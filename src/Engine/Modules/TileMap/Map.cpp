//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Создание карты мира                                                          |
//|  Подготавливает базовую сетку и передаёт                                      |
//|  её в генератор биомов.                                                       |
//|                                                                               |
//=================================================================================
#include "Engine/Modules/TileMap/Map.h"
#include "Engine/Modules/TileMap/MapGenerator.h"

#include <iostream>
#include <vector>

Map CreateMap() {
    Map map;
    map.map_width = 500;
    map.map_height = 500;

    int points = map.map_width * map.map_height;

    map.tiles.resize(points);

    GenerateMap(map);

    return map;
}
