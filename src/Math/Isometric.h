#pragma once

#include "ScreenPoint.h"

struct Camera;

ScreenPoint WorldToScreen(int column, int row, const Camera &camera);

void ScreenToWorld(float screenX, float screenY, const Camera &camera, int &column, int &row);

float GetMapPixelWidth(int mapWidth, int mapHeight);
float GetMapPixelHeight(int mapWidth, int mapHeight);
