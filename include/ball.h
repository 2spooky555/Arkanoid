#pragma once
#include "raylib.h"
#include "player.h"
#include "brick.h"
#include "audio.h"
#define BALL_SPEED 300.0f

typedef struct Ball {
    Vector2 position;
    Vector2 speed;
    float radius;
    bool active;
} Ball;

Ball CreateBall(Player player);
void UpdateBall(Ball* ball, Player* player, Brick bricks[ROWS][COLS], AudioManager* audio);
void DrawBall(Ball ball, Texture2D texture);
