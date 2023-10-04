#include "raylib.h"
#include "../include/game.h"

int main() {
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(800, 500, "Arkanoid");
    SetTargetFPS(144);

    GameData game_data = InitGame();
    GameObjects game_objects = InitGameObjects();
    TextureManager textures = InitTextures();

    while (!WindowShouldClose()) {
        UpdateGame(&game_data, &game_objects);
        BeginDrawing();
        ClearBackground(WHITE);
        DrawGame(game_data, textures, game_objects);
        DrawFPS(0, 0);
        EndDrawing();
    }
    UnloadGameTextures(&textures);
    CloseWindow();
    return 0;
}
