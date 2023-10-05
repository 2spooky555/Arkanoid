#pragma once
#include "raylib.h"

typedef struct AudioManager {
    Sound bounce;
    Sound start;
} AudioManager;

AudioManager InitAudioManager();
void UnloadGameAudio(AudioManager* audio);
