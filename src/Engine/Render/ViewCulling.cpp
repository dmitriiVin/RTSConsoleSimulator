#include "Engine/Camera/Camera.h"
#include "Engine/Modules/TileMap/Map.h"
#include "Engine/Render/ViewCulling.h"

VisibleArea CalculateVisibleArea(Camera &camera, const Map &map) {
    
    VisibleArea visibleArea;

    int tlColumn, tlRow;
    int trColumn, trRow;
    int blColumn, blRow;
    int brColumn, brRow;

    ScreenToWorld(0.0f, 0.0f, camera, tlColumn, tlRow);
    ScreenToWorld(static_cast<float>(camera.viewportWidth), 0.0f, camera, trColumn, trRow);
    ScreenToWorld(0.0f, static_cast<float>(camera.viewportHeight), camera, blColumn, blRow);
    ScreenToWorld(static_cast<float>(camera.viewportWidth), static_cast<float>(camera.viewportHeight), camera, brColumn, brRow);

    int firstColumn = std::min({tlColumn, trColumn, blColumn, brColumn});
    int lastColumn = std::max({tlColumn, trColumn, blColumn, brColumn});

    int firstRow = std::min({tlRow, trRow, blRow, brRow});
    int lastRow = std::max({tlRow, trRow, blRow, brRow});

    firstColumn -= 2;
    lastColumn += 2;

    firstRow -= 2;
    lastRow += 2;

    firstColumn = std::max(0, firstColumn);
    firstRow = std::max(0, firstRow);

    lastColumn = std::min(map.map_width - 1, lastColumn);
    lastRow = std::min(map.map_height - 1, lastRow);

    visibleArea.firstColumn = firstColumn;
    visibleArea.lastColumn = lastColumn;
    visibleArea.firstRow = firstRow;
    visibleArea.lastRow = lastRow;

    return visibleArea;
}
