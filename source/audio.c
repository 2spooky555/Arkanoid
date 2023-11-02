#include "../include/audio.h"

AudioManager InitAudioManager() {
	AudioManager manager = { 0 };
	manager.bounce = LoadSound("resources/bounce.wav");
	manager.start = LoadSound("resources/start.wav");
	manager.explosion = LoadSound("resources/explosion.wav");

	return manager;
}

void UnloadGameAudio(AudioManager* audio) {
	UnloadSound(audio->bounce);
	UnloadSound(audio->start);
	UnloadSound(audio->explosion);
}
