#pragma once
#include "raylib.h"

typedef struct Fonts {
    Font game_font;
} Fonts;

Fonts InitFonts();
void UnloadGameFonts(Fonts* fonts);
