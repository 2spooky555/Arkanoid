#pragma once
#include <stdbool.h>
#include "textures.h"
#include "game_objs.h"

#define PROMPT_TEXT_FONT 20

typedef enum GameState {
    LOGO,
    TITLE,
    GAMEPLAY,
    ENDING,
} GameState;

typedef struct GameData {
    GameState state;
    int frame_counter;
    bool paused;
} GameData;

GameData InitGame();
void UpdateGame(GameData* game_data, GameObjects* game_objects);
void DrawGame(GameData game_date, TextureManager textures, GameObjects game);