#pragma once
#include "raylib.h"
#define STARTING_LIVES 3

typedef struct Player {
    Vector2 position;
    Vector2 speed;
    Vector2 size;
    int lives;
} Player;

Player CreatePlayer();
void UpdatePlayer(Player* player);
void DrawPlayer(Player player, Texture2D texture);
