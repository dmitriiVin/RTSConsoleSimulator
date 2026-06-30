#include "Map.h"
#include "SDLRender.h"

#include <iostream>
#include <ostream>
#include <vector>

int main() {
    std::vector<Unit> units;

    Map world = CreateMap();

    Render(world, units);
}
