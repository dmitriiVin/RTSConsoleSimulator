#pragma once

#include "Map.h"

void GenerateMap(Map &map);
void CreateForest(Map &map, int x, int y, int width, int height);
void CreateLake(Map &map, int x, int y, int width, int height);
void CreateMountains(Map &map, int x, int y, int width, int height);
