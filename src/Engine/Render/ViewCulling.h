

#pragma once

#include "Engine/Math/Isometric.h"

struct VisibleArea {
    int firstColumn;
    int lastColumn;
    int firstRow;
    int lastRow;
};

VisibleArea CalculateVisibleArea(Camera &camera, const Map &map);
