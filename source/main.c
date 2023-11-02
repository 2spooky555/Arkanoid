#include "raylib.h"
#include "../include/game.h"

// FIX: web build
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

int main() {
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(800, 500, "Arkanoid");
    InitAudioDevice();
    SetTargetFPS(144);

    GameData game_data = InitGame();
    GameObjects game_objects = InitGameObjects();
    TextureManager textures = InitTextures();
    AudioManager audio = InitAudioManager();
    Fonts fonts = InitFonts();

    // TODO: make a struct for music?
    Music music = LoadMusicStream("resources/blockshock.mod");

    PlayMusicStream(music);

    while (!WindowShouldClose()) {
        UpdateGame(&game_data, &game_objects, &audio);
        UpdateMusicStream(music);
        BeginDrawing();
        ClearBackground(WHITE);
        DrawGame(game_data, textures, game_objects, fonts);
        DrawFPS(0, 0);
        EndDrawing();
    }

    UnloadGameTextures(&textures);
    UnloadGameAudio(&audio);
    UnloadGameFonts(&fonts);
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
