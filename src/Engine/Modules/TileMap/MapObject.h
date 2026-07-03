#pragma once

enum class MapObjectType {
    Tree,
    GoldMine,
    Crystal,
    Stone,
    Bush
};

struct MapObject {
    MapObjectType type;

    int maxHealth = 100;
    int health = 100;

    int maxResources = 0;
    int resourcesLeft = 0;

    bool blocksMovement = true;
};
