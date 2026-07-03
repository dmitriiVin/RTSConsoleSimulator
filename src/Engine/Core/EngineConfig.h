//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Конфигурация движка                                                          |
//|  Центральное место для общих констант:                                        |
//|  размеры тайлов, камера и рендер.                                             |
//|                                                                               |
//=================================================================================
#pragma once

constexpr float TILE_SIZE = 32.0f;

constexpr float TILE_WIDTH = 64;
constexpr float TILE_HEIGHT = 32;

constexpr float HALF_TILE_WIDTH = TILE_WIDTH / 2.0f;
constexpr float HALF_TILE_HEIGHT = TILE_HEIGHT / 2.0f;

constexpr char TILE_GRASS = '.';
constexpr char TILE_TREE = 'T';
constexpr char TILE_WATER = '~';
constexpr char TILE_MOUNTAIN = '^';

enum MapSize {
    Small,
    Medium,
    Large,
    Huge
};

constexpr int TREE_EDGE_SIZE = 2;
constexpr int TREE_EDGE_MISSING_PROBABILITY = 25;

constexpr float CAMERA_SPEED = 1200.0f;
constexpr int CAMERA_EDGE_SIZE = 20;

constexpr bool DRAW_GRID = true;
