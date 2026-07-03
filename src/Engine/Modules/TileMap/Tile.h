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

enum class ObjectType {
    None,
    Tree,
    Stone,
    Bush
};

struct Tile {
    GroundType ground = GroundType::Grass;
    ObjectType object = ObjectType::None;
};
