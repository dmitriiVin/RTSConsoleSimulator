//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Точка входа приложения                                                       |
//|  Создаёт карту мира, формирует список                                         |
//|  юнитов и передаёт управление в рендер.                                       |
//|                                                                               |
//=================================================================================
#include "Engine/Camera/Camera.h"
#include "Engine/Math/Isometric.h"
#include "Engine/Modules/TileMap/Map.h"
#include "Engine/Render/SDLRender.h"

#include <iostream>
#include <ostream>
#include <vector>

int main() {
    std::vector<Unit> units;

    Map world = CreateMap();

    Render(world, units);

}
