//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Главный рендер                                                               |
//|  Инициализирует SDL, открывает окно,                                          |
//|  запускает цикл и выводит карту на экран.                                     |
//|                                                                               |
//=================================================================================
#include "Engine/Math/Isometric.h"
#include "Engine/Render/SDLRender.h"
#include "Engine/Render/ViewCulling.h"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>

void Render(const Map &map, const std::vector<Unit> &units) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Ошибка инициализации SDL: %s", SDL_GetError());
        return;
    }
    SDL_DisplayID display = SDL_GetPrimaryDisplay();
    const SDL_DisplayMode *mode = SDL_GetCurrentDisplayMode(display);

    SDL_Window *window = SDL_CreateWindow("RTS ENGINE", 1280, 720, SDL_WINDOW_RESIZABLE);

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

    Time time;

    while (running) {
        time.Update();

        if (time.IsFPSUpdated()) {
            std::string title = "RTS ENGINE | FPS: " + std::to_string(static_cast<int>(time.GetFPS()));
            SDL_SetWindowTitle(window, title.c_str());
        }

        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);

        UpdateCamera(camera, window, time.GetDeltaTime());
        VisibleArea visibleArea = CalculateVisibleArea(camera, map);
        // ClampCamera(camera, map);

        SDL_RenderClear(renderer);
        RenderMap(renderer, map, camera, visibleArea);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void DrawIsometricTile(SDL_Renderer *renderer, float x, float y, SDL_FColor color) {
    SDL_Vertex vertices[4];

    // Верхняя вершина
    vertices[0].position = {x, y};
    vertices[0].color = color;
    vertices[0].tex_coord = {0.0f, 0.0f};

    // Правая вершина
    vertices[1].position = {x + HALF_TILE_WIDTH, y + HALF_TILE_HEIGHT};
    vertices[1].color = color;
    vertices[1].tex_coord = {0.0f, 0.0f};

    // Нижняя вершина
    vertices[2].position = {x, y + TILE_HEIGHT};
    vertices[2].color = color;
    vertices[2].tex_coord = {0.0f, 0.0f};

    // Левая вершина
    vertices[3].position = {x - HALF_TILE_WIDTH, y + HALF_TILE_HEIGHT};
    vertices[3].color = color;
    vertices[3].tex_coord = {0.0f, 0.0f};

    const int indices[] = {
        0, 1, 3, // первый треугольник
        3, 1, 2  // второй треугольник
    };

    SDL_RenderGeometry(renderer, nullptr, vertices, 4, indices, 6);

    // Если нужна сетка поверх ромба
    if (DRAW_GRID) {
        SDL_FPoint outline[5] = {{x, y}, {x + HALF_TILE_WIDTH, y + HALF_TILE_HEIGHT}, {x, y + TILE_HEIGHT}, {x - HALF_TILE_WIDTH, y + HALF_TILE_HEIGHT}, {x, y}};

        SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
        SDL_RenderLines(renderer, outline, 5);
    }
}

SDL_FColor GetTileColor(char tile) {
    SDL_FColor color;

    if (tile == TILE_GRASS) {
        color = {255.0f / 255.0f, 153.0f / 255.0f, 204.0f / 255.0f, 1.0f};
    }
    else if (tile == TILE_TREE) {
        color = {61.0f / 255.0f, 186.0f / 255.0f, 7.0f / 255.0f, 1.0f};
    }
    else if (tile == TILE_WATER) {
        color = {113.0f / 255.0f, 244.0f / 255.0f, 249.0f / 255.0f, 1.0f};
    }
    else if (tile == TILE_MOUNTAIN) {
        color = {155.0f / 255.0f, 150.0f / 255.0f, 150.0f / 255.0f, 1.0f};
    }
    else {
        color = {1.0f, 1.0f, 1.0f, 1.0f};
    }

    return color;
}

void RenderMap(SDL_Renderer *renderer, const Map &map, const Camera &camera, const VisibleArea &visibleArea) {

    for (int row = visibleArea.firstRow; row <= visibleArea.lastRow; row++) {
        for (int column = visibleArea.firstColumn; column <= visibleArea.lastColumn; column++) {
            ScreenPoint pos = WorldToScreen(column, row, camera);

            int index = map.map_width * row + column;
            char tile = map.cells_map[index];

            SDL_FColor color = GetTileColor(tile);

            DrawIsometricTile(renderer, pos.x, pos.y, color);
        }
    }
}
