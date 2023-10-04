#include "../include/ball.h"
#include "raymath.h"

Ball CreateBall(Player player) {
    Ball ball = {0};
    ball.radius = 10.0f;
    ball.active = false;
    ball.position = (Vector2){
        player.position.x + player.size.x/2.0f,
        player.position.y - ball.radius*2.0f,
    };
    ball.speed = (Vector2){0.0f, BALL_SPEED};

    return ball;
}

static void MoveBall(Ball* ball) {
    float dt = GetFrameTime();
    ball->position.x += ball->speed.x * dt;
    ball->position.y += ball->speed.y * dt;
}

static void CheckBallBounds(Ball* ball) {
    if (ball->position.x + ball->radius >= GetScreenWidth()) {
        ball->speed.x *= -1.0f;
        ball->position.x = GetScreenWidth() - ball->radius;
    }
    if (ball->position.x - ball->radius <= 0.0f) {
        ball->speed.x *= -1.0f;
        ball->position.x = 0.0f + ball->radius;
    }
    if (ball->position.y - ball->radius <= 0.0f) {
        ball->speed.y *= -1.0f;
        ball->position.y = 0.0f + ball->radius;
    }
}

static void CollideWithPlayer(Ball* ball, Player player) {
    Rectangle player_rect = (Rectangle){
        player.position.x,
        player.position.y,
        player.size.x,
        player.size.y
    };

    if (CheckCollisionCircleRec(ball->position, ball->radius, player_rect)) {
        ball->speed.x = (ball->position.x
                        - (player.position.x + player.size.x/2.0f))
                        /player.size.x*BALL_SPEED;
        ball->position.y = player.position.y - ball->radius;
        ball->speed.y *= -1.0f;
    }
}

static bool CollideWithBrick(Ball* ball, Brick* brick) {
    // TODO: make this a general function
    if (!(brick->active
        && CheckCollisionCircleRec(ball->position, ball->radius, brick->bounds)))
        return false;
    const float half_width = brick->size.x/2.0f;
    const float half_height = brick->size.y/2.0f;
    // Vector that points to wall from player position
    Vector2 delta_position = (Vector2){
        brick->position.x + half_width - ball->position.x,
        brick->position.y + half_height - ball->position.y
    };
    // Vector that points to the closest point on the wall from the center of the wall
    Vector2 from_closest = (Vector2){
        Clamp(delta_position.x, -half_width, half_width),
        Clamp(delta_position.y, -half_height, half_height)
    };
    // check if player is inside the wall
    if (Vector2Equals(delta_position, from_closest)) {
        if (fabs(delta_position.x) < fabsf(delta_position.y)) {
            from_closest.x = (from_closest.x >= 0.0f) ? half_width : -half_width;
        } else {
            from_closest.y = (from_closest.y >= 0.0f) ? half_height : -half_height;
        }
    }

    Vector2 direction = Vector2Subtract(delta_position, from_closest);

    if (direction.x < 0.0f) {
        ball->speed.x *= -1.0f;
        ball->position.x = brick->position.x + brick->size.x + ball->radius;
    } else if (direction.x > 0.0f) {
        ball->speed.x *= -1.0f;
        ball->position.x = brick->position.x - ball->radius;
    }

    if (direction.y < 0.0f) {
        ball->speed.y *= -1.0f;
        ball->position.y = brick->position.y + brick->size.y + ball->radius;
    } else if (direction.y > 0.0f) {
        ball->speed.y *= -1.0f;
        ball->position.y = brick->position.y - ball->radius;
    }

    brick->active = false;

    return true;
}

static void CollideWithBricks(Ball* ball, Brick bricks[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            Brick* brick = &bricks[row][col];
            if (CollideWithBrick(ball, brick)) {
                // only collide with one brick
                break;
            }
        }
    }
}

static void CheckLifeLost(Ball* ball, Player* player) {
    if (ball->position.y + ball->radius >= GetScreenHeight()) {
        ball->position.x = player->position.x + player->size.x/2.0f;
        ball->position.y = player->position.y - ball->radius - 1.0f;
        ball->speed = (Vector2){0.0f, 0.0f};
        ball->active = false;

        player->lives--;
    }
}

void UpdateBall(Ball* ball, Player* player, Brick bricks[ROWS][COLS]) {
    if (ball->active) {
        CheckBallBounds(ball);
        CollideWithPlayer(ball, *player);
        CollideWithBricks(ball, bricks);
        MoveBall(ball);
        CheckLifeLost(ball, player);
    } else {
        ball->position.x = player->position.x + player->size.x/2.0f;
    }
    if (IsKeyPressed(KEY_SPACE) && !ball->active) {
        ball->active = true;
        ball->speed = (Vector2){0.0f, BALL_SPEED};
    }
}

void DrawBall(Ball ball, Texture2D texture) {
    const Vector2 center = (Vector2){
        ball.position.x - texture.width/2.0f,
        ball.position.y - texture.height/2.0f,
    };
    DrawTextureV(texture, center, MAROON);
}
