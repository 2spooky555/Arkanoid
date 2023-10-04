#include "../include/brick.h"

static Brick CreateBrick(float row_offset, float col_offset) {
    Brick brick = {0};
    brick.size = (Vector2){
        (float)GetScreenWidth()/COLS,
        20.0f
    };
    brick.position = (Vector2){
        col_offset*brick.size.x,
        row_offset*brick.size.y + BRICK_Y
    };
    brick.bounds = (Rectangle){
        brick.position.x,
        brick.position.y,
        brick.size.x,
        brick.size.y
    };
    brick.active = true;

    return brick;
}

void CreateBricks(Brick bricks[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            bricks[row][col] = CreateBrick((float)row, (float)col);
        }
    }
}

void DrawBricks(Brick bricks[ROWS][COLS], Texture2D texture) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            Brick brick = bricks[row][col];
            if (!brick.active) continue;
            Color color = ((row + col) % 2 == 0) ? GRAY : DARKGRAY;
            DrawTextureV(texture, brick.position, color);
        }
    }
}
