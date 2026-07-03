//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Типы тайлов                                                                  |
//|  Описывает тип поверхности и объект,                                          |
//|  которые вместе образуют клетку карты.                                        |
//|                                                                               |
//=================================================================================
#pragma once

enum class GroundType {
    Grass,
    Sand,
    Water,
    Mountain
};

struct MapObject;

struct Tile {
    GroundType ground = GroundType::Grass;
    MapObject *object = nullptr;
};
