//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Главный рендер                                                               |
//|  Инициализирует SDL, открывает окно,                                          |
//|  запускает цикл и выводит карту на экран.                                     |
//|                                                                               |
//=================================================================================
#include "Engine/Math/Isometric.h"
#include "Engine/Modules/TileMap/MapObject.h"
#include "Engine/Modules/TileMap/Tile.h"
#include "Engine/Render/SDLRender.h"
#include "Engine/Render/ViewCulling.h"
#include "SDL3_image/SDL_image.h"
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

    TextureManager textures;

    if (!LoadTextures(renderer, textures)) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

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
        RenderMap(renderer, map, camera, visibleArea, textures);
        SDL_RenderPresent(renderer);
    }

    DestroyTextures(textures);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void DrawTexture(SDL_Renderer *renderer, const Texture &texture, float x, float y) {
    SDL_FRect dst;

    dst.x = x - texture.width / 2.0f;
    dst.y = y;

    dst.w = texture.width;
    dst.h = texture.height;

    SDL_RenderTexture(renderer, texture.texture, nullptr, &dst);
}

const Texture &GetGroundTexture(GroundType ground, const TextureManager &textures) {
    switch (ground) {
    case GroundType::Grass:
        return textures.grass;

    case GroundType::Water:
        return textures.water;

    case GroundType::Mountain:
        return textures.mountain;

    default:
        return textures.grass;
    }
}

void RenderMap(SDL_Renderer *renderer, const Map &map, const Camera &camera, const VisibleArea &visibleArea, const TextureManager &textures) {
    for (int row = visibleArea.firstRow; row <= visibleArea.lastRow; row++) {
        for (int column = visibleArea.firstColumn; column <= visibleArea.lastColumn; column++) {
            ScreenPoint pos = WorldToScreen(column, row, camera);

            int index = map.map_width * row + column;

            GroundType ground = map.tiles[index].ground;

            const Texture &texture = GetGroundTexture(ground, textures);

            DrawTexture(renderer, texture, pos.x, pos.y);
        }
    }
}
