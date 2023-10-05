#pragma once
#include "player.h"
#include "ball.h"
#include "brick.h"

typedef struct GameObjects {
    Player player;
    Ball ball;
    Brick bricks[ROWS][COLS];
} GameObjects;

GameObjects InitGameObjects();
