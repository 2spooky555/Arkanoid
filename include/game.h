#pragma once
#include "textures.h"
#include "game_objs.h"
#include "audio.h"
#include "font.h"

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
void UpdateGame(GameData* game_data, GameObjects* game_objects, AudioManager* audio);
void DrawGame(GameData game_date, TextureManager textures, GameObjects game, Fonts fonts);
