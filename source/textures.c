#include "../include/textures.h"

TextureManager InitTextures() {
    TextureManager manager = {0};
    manager.ball_texture = LoadTexture("resources/ball.png");
    manager.brick_texture = LoadTexture("resources/brick.png");
    manager.paddle_texture = LoadTexture("resources/paddle.png");
    manager.raylib_logo = LoadTexture("resources/raylib_logo.png");

    return manager;
}

void UnloadGameTextures(TextureManager* textures) {
    UnloadTexture(textures->ball_texture);
    UnloadTexture(textures->brick_texture);
    UnloadTexture(textures->paddle_texture);
    UnloadTexture(textures->raylib_logo);
}
