#pragma once

enum class MapObjectType {
    Tree,
    GoldMine,
    Crystal,
    Stone,
    Bush,
    Rock,
    Forge
};

struct MapObject {
    MapObjectType type;

    int worldX;
    int worldY;

    int tileWidth = 1;
    int tileHeight = 1;

    int maxHealth = 100;
    int health = 100;

    int maxResources = 0;
    int resourcesLeft = 0;

    int variation;

    bool blocksMovement = true;
};
