#pragma once

#include "Camera.h"
#include "Config.h"
#include "ScreenPoint.h"

ScreenPoint WorldToScreen(int column, int row, const Camera &camera);
