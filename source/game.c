#include "../include/game.h"
#include "raylib.h"

GameData InitGame() {
    GameData game = {0};
    game.state = LOGO;
    game.frame_counter = 0;
    game.paused = false;

    return game;
}

void UpdateGame(GameData* game_data, GameObjects* game_objects, AudioManager* audio) {
    switch (game_data->state) {
    case LOGO:
        game_data->frame_counter++;
        if (game_data->frame_counter > 180) {
            game_data->state = TITLE;
            game_data->frame_counter = 0;
        }
        break;
    case TITLE:
        game_data->frame_counter++;
        if (IsKeyPressed(KEY_ENTER)) {
            PlaySound(audio->start);
            game_data->state = GAMEPLAY;
        }
        break;
    case GAMEPLAY:
        if (IsKeyPressed(KEY_P)) {
            game_data->paused = !game_data->paused;
        }
        if (!game_data->paused) {
            UpdatePlayer(&game_objects->player);
            UpdateBall(
                &game_objects->ball,
                &game_objects->player,
                game_objects->bricks,
                audio
            );
        }
        if (game_objects->player.lives <= 0) {
            game_data->state = ENDING;
            game_objects->player.lives = STARTING_LIVES;
            game_data->frame_counter = 0;
        }
        break;
    case ENDING:
        game_data->frame_counter++;
        if (IsKeyPressed(KEY_ENTER)) {
            // reset game
            game_objects->player = CreatePlayer();
            game_objects->ball = CreateBall(game_objects->player);
            CreateBricks(game_objects->bricks);
            game_data->state = TITLE;
        }
        break;
    }
}

void DrawGame(GameData game_data, TextureManager textures, GameObjects game, Fonts fonts) {
    switch (game_data.state) {
    case LOGO:
        const Vector2 center = {
            (GetScreenWidth() - textures.raylib_logo.width)/2.0f,
            (GetScreenHeight() - textures.raylib_logo.height)/2.0f
        };
        DrawTextureV(textures.raylib_logo, center, WHITE);
        break;
    case TITLE:
        DrawTextEx(
            fonts.game_font,
            "Title",
            (Vector2){20, 20},
            PROMPT_TEXT_FONT*2.0f,
            4.0f,
            GRAY
        );
        if ((game_data.frame_counter/30) % 2 == 0) {
            DrawTextEx(
                fonts.game_font,
                "PRESS [ENTER] to START",
                (Vector2){
                    (float)GetScreenWidth()/2 - MeasureText("PRESS [ENTER] to START", PROMPT_TEXT_FONT)/2,
                    (float)GetScreenHeight()/2 + 60,
                },
                PROMPT_TEXT_FONT,
                2.0f,
                GRAY
            );
        }
        break;
    case GAMEPLAY:
        DrawBall(game.ball, textures.ball_texture);
        DrawPlayer(game.player, textures.paddle_texture);
        DrawBricks(game.bricks, textures.brick_texture);
        if (game_data.paused) {
            DrawTextEx(
                fonts.game_font,
                "GAME PAUSED",
                (Vector2){
                    (float)GetScreenWidth()/2 - MeasureText("GAME PAUSED", PROMPT_TEXT_FONT)/2,
                    (float)GetScreenHeight()/2 + 60,
                },
                PROMPT_TEXT_FONT,
                2.0f,
                GRAY
            );
        }
        break;
    case ENDING:
        DrawTextEx(
            fonts.game_font,
            "ENDING",
            (Vector2){20, 20},
            PROMPT_TEXT_FONT*2.0f,
            4.0f,
            GRAY
        );
        if ((game_data.frame_counter/30) % 2 == 0) {
            DrawTextEx(
                fonts.game_font,
                "PRESS [ENTER] TO PLAY AGAIN",
                (Vector2){
                    (float)GetScreenWidth()/2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", PROMPT_TEXT_FONT)/2,
                    (float)GetScreenHeight()/2 + 60,
                },
                PROMPT_TEXT_FONT,
                2.0f,
                GRAY
            );
        }
        break;
    }
}
