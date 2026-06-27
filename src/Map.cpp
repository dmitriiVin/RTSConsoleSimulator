#include "Map.h"
#include "Unit.h"

#include <iostream>
#include <vector>

Map CreateMap() {
    Map map;
    map.map_width = 50;
    map.map_height = 25;

    int points = map.map_width * map.map_height;

    map.cells_map = std::vector<char>(points, '.');

    return map;
}

void PaintInConsole(const Map &map, const std::vector<Unit> &units) {
    int row, column;

    for (row = 0; row < map.map_height; row++) {
        for (column = 0; column < map.map_width; column++) {

            int index = map.map_width * row + column;
            bool unitFound = false;

            for (const auto &element : units) {
                if (element.x == column && element.y == row) {
                    unitFound = true;
                }
            }
            if (unitFound == true) {
                std::cout << 'U';
            }
            else {
                std::cout << '.';
            }
        }
        std::cout << "\n";
    }
}
