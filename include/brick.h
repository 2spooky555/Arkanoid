#pragma once
#include "raylib.h"
#define ROWS 6
#define COLS 20
#define BRICK_Y 100

typedef struct Brick {
    Vector2 position;
    Vector2 size;
    Rectangle bounds;
    int resistance;
    bool active;
} Brick;

void CreateBricks(Brick bricks[ROWS][COLS]);
void DrawBricks(Brick bricks[ROWS][COLS], Texture2D texture);
