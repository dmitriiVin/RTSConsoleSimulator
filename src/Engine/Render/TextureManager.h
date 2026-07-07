#pragma once

#include "Engine/Render/Texture.h"

struct TextureManager {
    Texture grass;
    Texture water;
    Texture mountain;
    Texture tree;
};

bool LoadTexture(SDL_Renderer *renderer, Texture &texture, const char *path);
bool LoadTextures(SDL_Renderer *renderer, TextureManager &textures);
void DestroyTextures(TextureManager &textures);
