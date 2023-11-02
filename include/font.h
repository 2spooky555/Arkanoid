#pragma once
#include "raylib.h"
#define PROMPT_TEXT_FONT 40

typedef struct Fonts {
    Font game_font;
} Fonts;

Fonts InitFonts();
void UnloadGameFonts(Fonts* fonts);
