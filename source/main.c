#include "raylib.h"
#include "../include/game.h"
#if defined(__EMSCRIPTEN__)
	#include <emscripten/emscripten.h>
#endif

// game vars
GameData game_data;
GameObjects game_objects;
TextureManager textures;
AudioManager audio;
Fonts fonts;
// TODO: make a struct for music?
Music music;

void Setup() {
	game_data = InitGame();
	game_objects = InitGameObjects();
	textures = InitTextures();
	audio = InitAudioManager();
	fonts = InitFonts();
	music = LoadMusicStream("resources/blockshock.mod");
}

void MainLoop() {
	UpdateGame(&game_data, &game_objects, &audio);
	UpdateMusicStream(music);
	BeginDrawing();
	ClearBackground(WHITE);
	DrawGame(game_data, textures, game_objects, fonts);
	DrawFPS(0, 0);
	EndDrawing();
}

int main() {
	const int fps = 60;
	SetTraceLogLevel(LOG_WARNING);
	InitWindow(800, 500, "Arkanoid");
	InitAudioDevice();
	// setup game
	Setup();

	PlayMusicStream(music);

	#ifdef __EMSCRIPTEN__
	emscripten_set_main_loop(MainLoop, fps, 1);

	#else
	SetTargetFPS(fps);
	while (!WindowShouldClose()) {
		MainLoop();
	}
	#endif

	UnloadGameTextures(&textures);
	UnloadGameAudio(&audio);
	UnloadGameFonts(&fonts);
	UnloadMusicStream(music);
	CloseAudioDevice();
	CloseWindow();
	return 0;
}
