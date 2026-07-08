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

MapObject *CreateObject(MapObjectType type, int x, int y) {
    MapObject *object = new MapObject;

    object->type = type;
    object->worldX = x;
    object->worldY = y;

    return object;
}

void PlaceObject(Map &map, MapObjectType type, int x, int y, int width, int height) {
    MapObject *object = CreateObject(type, x, y);

    object->tileWidth = width;
    object->tileHeight = height;

    for (int row = y; row < y + height; row++) {
        for (int column = x; column < x + width; column++) {

            if (row < 0 || row >= map.map_height)
                continue;

            if (column < 0 || column >= map.map_width)
                continue;

            int index = row * map.map_width + column;

            map.tiles[index].object = object;
        }
    }
}

void CreateForest(Map &map, int x, int y, int width, int height) {
    int leftBorder = x;
    int rightBorder = x + width - 1;

    int topBorder = y;
    int bottomBorder = y + height - 1;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 99);

    for (int row = y; row < y + height; row++) {
        for (int column = x; column < x + width; column++) {

            int index = row * map.map_width + column;

            int leftDistance = column - leftBorder;
            int rightDistance = rightBorder - column;

            int topDistance = row - topBorder;
            int bottomDistance = bottomBorder - row;

            bool isEdge = leftDistance < TREE_EDGE_SIZE || rightDistance < TREE_EDGE_SIZE || topDistance < TREE_EDGE_SIZE || bottomDistance < TREE_EDGE_SIZE;

            if (isEdge && distrib(gen) < TREE_EDGE_MISSING_PROBABILITY) {

                map.tiles[index].ground = GroundType::Grass;
                map.tiles[index].object = nullptr;

                continue;
            }

            map.tiles[index].ground = GroundType::Grass;
            map.tiles[index].object = CreateObject(MapObjectType::Tree, column, row);
        }
    }
}

void CreateLake(Map &map, int x, int y, int width, int height) {
    for (int row = y; row < y + height; row++) {
        for (int column = x; column < x + width; column++) {

            int index = row * map.map_width + column;

            map.tiles[index].ground = GroundType::Water;
            map.tiles[index].object = nullptr;
        }
    }
}

void CreateMountains(Map &map, int x, int y, int width, int height) {
    for (int row = y; row < y + height; row++) {
        for (int column = x; column < x + width; column++) {

            int index = row * map.map_width + column;

            map.tiles[index].ground = GroundType::Grass;

            map.tiles[index].object = CreateObject(MapObjectType::Stone, column, row);
        }
    }
}

void GenerateMap(Map &map) {
    CreateForest(map, 40, 15, 10, 10);

    CreateLake(map, 13, 1, 12, 3);

    CreateMountains(map, 10, 13, 2, 12);

    PlaceObject(map, MapObjectType::Forge, 20, 20, 3, 3);
}
