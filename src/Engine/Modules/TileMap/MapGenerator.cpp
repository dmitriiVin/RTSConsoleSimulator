//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Процедурная генерация                                                        |
//|  Заполняет карту лесом, водой и горами,                                       |
//|  создавая простой игровой ландшафт.                                           |
//|                                                                               |
//=================================================================================
#include "Engine/Modules/TileMap/MapGenerator.h"
#include "Engine/Modules/TileMap/MapObject.h"
#include <random>

void CreateForest(Map &map, int x, int y, int width, int height) {
    int row, column;

    int leftBorder = x;
    int rightBorder = x + width - 1;

    int topBorder = y;
    int bottomBorder = y + height - 1;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 99);

    for (row = y; row < y + height; row++) {
        for (column = x; column < x + width; column++) {
            int index = row * map.map_width + column;

            int leftDistance = column - leftBorder;
            int rightDistance = rightBorder - column;

            int topDistance = row - topBorder;
            int bottomDistance = bottomBorder - row;

            int random_num = distrib(gen);

            bool isEdge = leftDistance < TREE_EDGE_SIZE || rightDistance < TREE_EDGE_SIZE || topDistance < TREE_EDGE_SIZE || bottomDistance < TREE_EDGE_SIZE;

            if (isEdge) {
                if (random_num < TREE_EDGE_MISSING_PROBABILITY) {
                    map.tiles[index].ground = GroundType::Grass;

                    map.tiles[index].object = nullptr;
                }
                else {
                    map.tiles[index].ground = GroundType::Grass;
                    map.tiles[index].object = new MapObject;
                    map.tiles[index].object->type = MapObjectType::Tree;
                }
            }
            else {
                map.tiles[index].ground = GroundType::Grass;
                map.tiles[index].object = new MapObject;
                map.tiles[index].object->type = MapObjectType::Tree;
            }
        }
    }
}

void CreateLake(Map &map, int x, int y, int width, int height) {
    int row, column;
    for (row = y; row < y + height; row++) {
        for (column = x; column < x + width; column++) {
            int index = row * map.map_width + column;
            map.tiles[index].ground = GroundType::Water;
            map.tiles[index].object = nullptr;
        }
    }
}

void CreateMountains(Map &map, int x, int y, int width, int height) {
    int row, column;
    for (row = y; row < y + height; row++) {
        for (column = x; column < x + width; column++) {
            int index = row * map.map_width + column;
            map.tiles[index].ground = GroundType::Mountain;
            map.tiles[index].object = nullptr;
        }
    }
}

void GenerateMap(Map &map) {
    CreateForest(map, 40, 15, 10, 10);
    CreateLake(map, 13, 1, 12, 3);
    CreateMountains(map, 10, 13, 2, 12);
}
