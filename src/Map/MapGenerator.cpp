#include "Config.h"
#include "MapGenerator.h"
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
                    map.cells_map[index] = TILE_GRASS;
                }
                else {
                    map.cells_map[index] = TILE_TREE;
                }
            }
            else {
                map.cells_map[index] = TILE_TREE;
            }
        }
    }
}

void CreateLake(Map &map, int x, int y, int width, int height) {
    int row, column;
    for (row = y; row < y + height; row++) {
        for (column = x; column < x + width; column++) {
            int index = row * map.map_width + column;
            map.cells_map[index] = '~';
        }
    }
}

void CreateMountains(Map &map, int x, int y, int width, int height) {
    int row, column;
    for (row = y; row < y + height; row++) {
        for (column = x; column < x + width; column++) {
            int index = row * map.map_width + column;
            map.cells_map[index] = '^';
        }
    }
}

void GenerateMap(Map &map) {
    CreateForest(map, 40, 15, 10, 10);
    CreateLake(map, 13, 1, 12, 3);
    CreateMountains(map, 10, 13, 2, 12);
}
