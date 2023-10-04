#include "../include/player.h"

Player CreatePlayer() {
    Player player = {0};
    player.speed = (Vector2){200.0f, 200.0f};
    player.size = (Vector2){100.0f, 24.0f};
    player.position = (Vector2){
        GetScreenWidth()/2.0f - player.size.x/2.0f,
        GetScreenHeight()*7.0f/8.0f
    };
    player.lives = STARTING_LIVES;

    return player;
}

static void GetPlayerInput(Player* player) {
    float dt = GetFrameTime();
    float movement = player->speed.x * dt;
    if (IsKeyDown(KEY_LEFT)) {
        player->position.x -= movement;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        player->position.x += movement;
    }
}

static void CheckPlayerBounds(Player* player) {
    if (player->position.x <= 0.0f) {
        player->position.x = 0.0f;
    }
    if (player->position.x + player->size.x >= GetScreenWidth()) {
        player->position.x = GetScreenWidth() - player->size.x;
    }
}

void UpdatePlayer(Player* player) {
    GetPlayerInput(player);
    CheckPlayerBounds(player);
}

static void DrawLives(Player player) {
    for (int i = 0; i < player.lives; i++) {
        DrawRectangle(i*40 + 20, GetScreenHeight() - 30, 35, 10, LIGHTGRAY);
    }
}

void DrawPlayer(Player player, Texture2D texture) {
    DrawTextureV(texture, player.position, WHITE);
    DrawLives(player);
}
