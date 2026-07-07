#include "Engine/Render/TextureManager.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

bool LoadTexture(SDL_Renderer *renderer, Texture &texture, const char *path) {
    texture.texture = IMG_LoadTexture(renderer, path);

    if (texture.texture == nullptr) {
        SDL_Log("Ошибка загрузки %s: %s", path, SDL_GetError());
        return false;
    }

    float width;
    float height;

    SDL_GetTextureSize(texture.texture, &width, &height);

    texture.width = static_cast<int>(width);
    texture.height = static_cast<int>(height);

    return true;
}

bool LoadTextures(SDL_Renderer *renderer, TextureManager &textures) {

    if (!LoadTexture(renderer, textures.grass, "/Users/dmitriivinogradov/RTSEngine/src/Game/Assets/Textures/Tiles/ts_grass0/straight/45/0.png"))
        return false;

    if (!LoadTexture(renderer, textures.mountain, "/Users/dmitriivinogradov/RTSEngine/src/Game/Assets/Textures/Tiles/ts_beach-shallow0/straight/45/0.png"))
        return false;

    if (!LoadTexture(renderer, textures.water, "/Users/dmitriivinogradov/RTSEngine/src/Game/Assets/Textures/Tiles/ts_shallow0/straight/45/0.png"))
        return false;

    if (!LoadTexture(renderer, textures.tree, "/Users/dmitriivinogradov/RTSEngine/src/Game/Assets/Textures/Objects/tree_sheet.png"))
        return false;

    return true;
}

void DestroyTextures(TextureManager &textures) {

    if (textures.grass.texture)
        SDL_DestroyTexture(textures.grass.texture);

    if (textures.water.texture)
        SDL_DestroyTexture(textures.water.texture);

    if (textures.mountain.texture)
        SDL_DestroyTexture(textures.mountain.texture);

    if (textures.tree.texture)
        SDL_DestroyTexture(textures.tree.texture);
}
