#pragma once
#include "raylib.h"

typedef struct TextureManager {
    Texture2D ball_texture;
    Texture2D brick_texture;
    Texture2D paddle_texture;
    Texture2D raylib_logo;
} TextureManager;

TextureManager InitTextures();
void UnloadGameTextures(TextureManager* textures);
