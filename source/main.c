#include "raylib.h"
#include "../include/game.h"
#include "../include/audio.h"

int main() {
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(800, 500, "Arkanoid");
    InitAudioDevice();
    SetTargetFPS(144);

    GameData game_data = InitGame();
    GameObjects game_objects = InitGameObjects();
    TextureManager textures = InitTextures();
    AudioManager audio = InitAudioManager();

    while (!WindowShouldClose()) {
        UpdateGame(&game_data, &game_objects, &audio);
        BeginDrawing();
        ClearBackground(WHITE);
        DrawGame(game_data, textures, game_objects);
        DrawFPS(0, 0);
        EndDrawing();
    }

    UnloadGameTextures(&textures);
    UnloadGameAudio(&audio);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
