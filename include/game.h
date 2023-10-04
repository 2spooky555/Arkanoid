#pragma once
#include <stdbool.h>
#include "player.h"
#include "ball.h"
#include "brick.h"

#define PROMPT_TEXT_FONT 20

typedef enum GameState {
    LOGO,
    TITLE,
    GAMEPLAY,
    ENDING,
} GameState;

typedef struct TextureManager {
    Texture2D ball_texture;
    Texture2D brick_texture;
    Texture2D paddle_texture;
    Texture2D raylib_logo;
} TextureManager;

typedef struct GameObjects {
    Player player;
    Ball ball;
    Brick bricks[ROWS][COLS];
} GameObjects;

typedef struct GameData {
    GameState state;
    int frame_counter;
    bool paused;
} GameData;

GameData InitGame();
GameObjects InitGameObjects();
TextureManager InitTextures();
void UpdateGame(GameData* game_data, GameObjects* game_objects);
void DrawGame(GameData game_date, TextureManager textures, GameObjects game);
void UnloadGameTextures(TextureManager* textures);
