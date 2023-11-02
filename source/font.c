#include "../include/font.h"

Fonts InitFonts() {
	Fonts fonts = { 0 };
	fonts.game_font = LoadFont("resources/setback.png");

	return fonts;
}

void UnloadGameFonts(Fonts* font) {
	UnloadFont(font->game_font);
}
