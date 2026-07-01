#include "Camera.h"
#include "SDLRender.h"

void Render(const Map &map, const std::vector<Unit> &units) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Ошибка инициализации SDL: %s", SDL_GetError());
        return;
    }
    SDL_DisplayID display = SDL_GetPrimaryDisplay();
    const SDL_DisplayMode *mode = SDL_GetCurrentDisplayMode(display);

    SDL_Window *window = SDL_CreateWindow("Моё окно SDL3", 1280, 720, SDL_WINDOW_RESIZABLE);

    if (window == nullptr) {
        SDL_Log("Не удалось создать окно: %s", SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);

    if (renderer == nullptr) {
        SDL_Log("Не удалось создать рендерер: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    bool running = true;

    Camera camera{0.0f, 0.0f};

    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);

        UpdateCamera(camera, window);
        ClampCamera(camera, map);

        SDL_RenderClear(renderer);
        RenderMap(renderer, map, camera);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void RenderMap(SDL_Renderer *renderer, const Map &map, const Camera &camera) {

    int firstColumn = std::max(0, static_cast<int>(camera.x / TILE_SIZE));
    int firstRow = std::max(0, static_cast<int>(camera.y / TILE_SIZE));

    int visibleColumns = camera.viewportWidth / TILE_SIZE + 2;
    int visibleRows = camera.viewportHeight / TILE_SIZE + 2;

    int lastColumn = std::min(map.map_width, firstColumn + visibleColumns);
    int lastRow = std::min(map.map_height, firstRow + visibleRows);

    int row, column;

    for (row = firstRow; row < lastRow; row++) {
        for (column = firstColumn; column < lastColumn; column++) {

            ScreenPoint pos = WorldToScreen(column, row, camera);

            SDL_FRect tileRect = {pos.x, pos.y, TILE_SIZE, TILE_SIZE};
            SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
            int index = map.map_width * row + column;
            char tile = map.cells_map[index];

            if (tile == TILE_GRASS) {
                SDL_SetRenderDrawColor(renderer, 117, 233, 128, 255);
            } else if (tile == TILE_TREE) {
                SDL_SetRenderDrawColor(renderer, 61, 186, 7, 255);
            } else if (tile == TILE_WATER) {
                SDL_SetRenderDrawColor(renderer, 113, 244, 249, 255);
            } else if (tile == TILE_MOUNTAIN) {
                SDL_SetRenderDrawColor(renderer, 155, 150, 150, 255);
            }

            SDL_RenderFillRect(renderer, &tileRect);

            if (DRAW_GRID) {
                SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
                SDL_RenderRect(renderer, &tileRect);
            }
        }
    }
}
