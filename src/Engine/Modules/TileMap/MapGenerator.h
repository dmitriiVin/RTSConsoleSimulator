//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Генератор карты                                                              |
//|  Содержит отдельные процедуры для леса,                                       |
//|  озера и гор как строительных блоков мира.                                    |
//|                                                                               |
//=================================================================================
#pragma once

#include "Engine/Core/EngineConfig.h"
#include "Engine/Modules/TileMap/Map.h"

void GenerateMap(Map &map);
void CreateForest(Map &map, int x, int y, int width, int height);
void CreateLake(Map &map, int x, int y, int width, int height);
void CreateMountains(Map &map, int x, int y, int width, int height);
