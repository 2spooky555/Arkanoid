#pragma once
#include "raylib.h"

typedef struct AudioManager {
    Sound bounce;
    Sound start;
    Sound explosion;
} AudioManager;

AudioManager InitAudioManager();
void UnloadGameAudio(AudioManager* audio);
